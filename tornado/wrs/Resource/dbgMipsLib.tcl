# dbgMipsLib.tcl - mips-specific Tcl implementation 
#
# Copyright 1996-1998 Wind River Systems, Inc.
#
# modification history
# -----------------------
# 01g,25mar98,dbt  fixed a problem in trcStackLvl.
# 01f,10mar98,dbt  added architecture specific help message and support for
#                  hardware breakpoints.
# 01e,13nov97,fle  moving dbgNextAddrGet{} from every dbgXxxxLib.tcl file to
#                  nextAddrGet{} in shelcore.tcl, since wtxMemDisassemble is
#                  CPU agnostic
# 01d,14jan97,kkk  added little endian, fixed trace debug.
# 01c,19nov96,kkk  added R4650, fixed cret() when encounter lw ra,x(sp).
# 01b,13aug96,elp  changed R4000 index values.
# 01a,25jun96,elp  written.
#

# DESCRIPTION
# /target/src/arch/mips/trcLib.c inspired
# /target/src/arch/mips/dbgArchLib.c inspired

# globals

switch -regexp $cpuType($__wtxCpuType) {
    R3000 {
	set spIndex		35		; # index of sp register
	set raIndex		37		; # index of lr register
    } 
    R4[0-9]*0 {
        switch [targetEndian] {
            BIG_ENDIAN {
                set spIndex             67      ; # index of 32 bit sp value
                set raIndex             71      ; # index of 32 bit ra value
            }
            LITTLE_ENDIAN {
                set spIndex             66      ; # index of 32 bit sp value
                set raIndex             70      ; # index of 32 bit ra value
            }
	}
    }
}

# Set architecture help message
# Hardware breakpoints are only supported by R4650
# processors.

switch -regexp $cpuType($__wtxCpuType) {
    R4650 {
	set archHelpMsg		"bh        addr\[,access\[,task\[,count\]\]\]\
				Set hardware breakpoint\n\
				\t\taccess:\t0 - instruction\t1 - write\n\
				\t\t\t2 - read\t3 - read/write\n";

	set hwBpTypeList {
	    {"0"	"(hard-inst.)"}
	    {"1"	"(hard-write)"}
	    {"2"	"(hard-read)"}
	    {"3"	"(hard-read/write)"}
	};
    }
}

set trcDebug            0               ; # trace debugging on?
set defArgNb		4		; # default argument number
set MAX_SCAN_DEPTH	[expr 4 * 250]	; # search for proc start up to 250
					  # instructions

##############################################################################
#
# trcStack - print a trace of function calls from the stack
#
# This routine provides the low-level stack trace function.  A higher-level
# symbolic stack trace, built on top of trcStack{}, is provided by tt{} in
# shell.tcl
#
# This routine prints a list of the nested routine calls that are on the
# stack, showing each routine with its parameters.
#
# The stack being traced should be quiescent.  The caller should avoid
# tracing its own stack.
#
# SYNOPSYS:
# 	trcStack tid
# 
# PARAMETERS:
# 	tid: task identifier
#
# ERRORS: N/A
#
# RETURNS: a list of trace lines
#	   each trace line is a list of 4 elements :
#		{addr callFunc argNb {argList}}
#

proc trcStack {tid} {
    global offset
    global MAX_SCAN_DEPTH
    global spIndex
    global trcDebug

    set EXC_ACCESS_ADDR 0x0004
    set EXC_EPC		0x0002

    set blk [wtxMemRead [expr $tid + $offset(WIND_TCB,excInfo)] 0x20]
    set valid [expr [memBlockGet -w $blk 0 1]]
    bindNamesToList {epc badVa} [memBlockGet -l $blk 2 2]
    memBlockDelete $blk

    if {($valid & $EXC_ACCESS_ADDR) && 
	($valid & $EXC_EPC) &&
	($badVa == $epc)} {
	puts stdout "cannot trace : i-fetch caused exception"
	return -1
    }
    set blk [wtxMemRead [expr $tid + $offset(WIND_TCB,pStackBase)] 4]
    set stackBottom [expr [memBlockGet -l $blk]]
    memBlockDelete $blk

    #
    # must perform the trace by searching through code to determine stack
    # frames, and unwinding them to determine caller and parameters.
    # We substract 40 from stackBottom for the reserved task params that are 
    # tagged onto every task's main entry point.
    #

    set regSet [regSetOfContext CONTEXT_TASK $tid]
    set pc [pcOfRegSet $regSet]
    set sp [lindex $regSet $spIndex]

    if {$trcDebug > 0} {
        puts stdout [format "0: stackBot 0x%x, sp 0x%x, pc 0x%x" [expr $stackBottom - 40] $sp $pc]
    }

    set trc [trcStackLvl [expr $stackBottom - 40] $sp $pc $regSet]
    
    return $trc
}

#############################################################################
#
# trcInfoGet - get address from which function was called
#
# Determines specific info about the current function, such as the
# address where it was called from, the stack frame size (if any) and
# whether the stack frame has already been allocated.
#
# SYNOPSIS:
#	trcInfoGet pc sp ra
#
# PARAMETERS:
#	pc: current pc
#	sp: stack pointer
#	ra: content of ra register
#
# ERRORS: N/A
#
# RETURNS: 
#

proc trcInfoGet {pc sp ra} {
    global MAX_SCAN_DEPTH

    # set default values

    set retAddr 0
    set frameSize 0

    #
    # scan instructions forward until the end of function or the max
    # scan count is reached. If we find a "sw ra,x(sp)" or a "jr ra"
    # then the return address in already in register "ra".  If we find
    # a "lw ra,x(sp)" then the return address is saved in offset "x"
    # on the stack. If the instruction space is corrupted, could get
    # a bus error eventually or could find a return address for a
    # neighboring subprogram. The calling pc is determined by subtracting
    # 2 instructions from the return address. The stack frame size, if
    # found, and whether it is allocated, are passed out.
    #

    set scanBlk [wtxMemRead $pc $MAX_SCAN_DEPTH]
    set scanDepth $MAX_SCAN_DEPTH

    for {set i 0} {$i < $scanDepth} {incr i 4} {
	set inst [expr [memBlockGet -l $scanBlk $i 1]]


	if {(($inst & 0xffff0000) == 0xafbf0000) ||
	    (($inst & 0xffff0000) == 0xffbf0000)} {
	    
	    # match "sw/sd ra,x(sp)" means return address in ra 

	    set retAddr $ra
	} elseif {(($inst & 0xffe0003f) == 0x03e00008)} {

	    # match "jr ra" means retAddr in ra & end of function reached

	    if {! $retAddr} {
		set retAddr $ra
	    }
	    
	    # check branch delay slot and the stop the scan

	    set scanDepth [expr $i + 8]

	    if {$scanDepth > $MAX_SCAN_DEPTH} {
		memBlockDelete $scanBlk
		set scanBlk [wtxMemRead [expr $pc + $MAX_SCAN_DEPTH] 4]
		set i -4 	; # set to 0 by the loop
		set scanDepth 4
	    }

	} elseif {(($inst & 0xffff0000) == 0x8fbf0000) ||
		  (($inst & 0xffff0000) == 0xdfbf0000)} {
	    
	    #
	    # match "lw ra, x(sp)" or "ld ra, x(sp)"
	    # means return address is on the stack 
	    #

	    if {! $retAddr} {
		set blk [wtxMemRead [expr $sp + $frameSize + \
				     ($inst & 0x0000ffff)] 4]
		set retAddr [expr [memBlockGet -l $blk]]
		memBlockDelete $blk
	    }
	} elseif {(($inst & 0xbfff0000) == 0x27bd0000)} {
	    
	    # match "[d]addiu sp,sp,+-offset" to determine stack frame size.

	    set offset [expr $inst & 0x0000ffff]

	    # offset sign extend 
	    if {$offset & 0x8000} {
		set offset [expr $offset | 0xffff0000]
	    }
	    set frameSize [expr $frameSize + $offset]

	}
    }
    memBlockDelete $scanBlk
    set callAddr [expr ($retAddr) ? $retAddr - 8 : 0]
    return "$callAddr $frameSize"
}

##############################################################################
#
# trcStackLvl - stack trace routine
#
# Loop and get trace information for each level. Maximun number of level is 40
#
# SYNOPSYS:
#	trcStackLevel stackBottom sp pc regSet
#
# PARAMETERS:
#	stackBottom: effective base of task's stack
#	sp: stack pointer
#	pc: content of pc register
#	regSet:	register set
# 
# ERRORS: N/A
#	
# RETURNS: a list of trace lines
#	   each trace line is a list of 4 elements :
#		{addr callFunc argNb {argList}}
#

proc trcStackLvl {stackBottom sp pc regSet} {
    global raIndex
    global defArgNb
    global trcDebug
 
    set trcStack {}
    set frameSize 0

    for {set depth 0} {($depth < 40) && (($sp + $frameSize) <= $stackBottom)} \
	{incr depth; 
	 set sp [expr $sp + $frameSize];
	 set pc $callPc
	 } {
	
	# stop the unwind if it is obvious we can't dereference pc
	
	if {$pc < 0x80000000} {
	    break
	}

        if {$trcDebug > 0} {
            puts stdout [format " stackBot 0x%x, sp 0x%x, pc 0x%x" $stackBottom $sp $pc]
        }

	bindNamesToList {callPc frameSize} \
			[trcInfoGet $pc $sp [lindex $regSet $raIndex]] 

        if {$trcDebug > 0} {
            puts -nonewline stdout [format "callPc 0x%x frameSize %d" $callPc $frameSize]
        }

	# stop the unwind if we can't determine the caller of this function

	if {! $callPc} {
	    break
	}

        # only continue unwinding if this is not the last stack frame 

	if {($sp + $frameSize) < $stackBottom} {
	    set startPc [trcFindFuncStart $callPc]
	    if {! $startPc} {
		
		#
		# Unable to determine entry point from code... Try the symbol
		# table. Note that the symbol table may yield the wrong entry
		# point if the function name is not in it. In this case we
		# get the starting address for the previous function in the 
		# text section and the trace would yield in strange results
		#

		if [catch "wtxSymFind -value $pc" sym] {
		    if {([wtxErrorName $sym] == "SVR_INVALID_FIND_REQUEST") ||
			([wtxErrorName $sym] == "SYMTBL_SYMBOL_NOT_FOUND")} {
			return 
		    } else {
			error $sym
		    }
		} else {
		    set startPc [lindex $sym 1]
		}
	    }
	} else {

	    # Since this is the last frame, we can only determine the entry
	    # point via the symbol table

	    if [catch "wtxSymFind -value $pc" sym] {
		if {([wtxErrorName $sym] == "SVR_INVALID_FIND_REQUEST") ||
		    ([wtxErrorName $sym] == "SYMTBL_SYMBOL_NOT_FOUND")} {
		    return 
		} else {
		    error $sym
		}
	    } else {
		set startPc [lindex $sym 1]
	    }
	    set level [list $callPc [trcFuncStartName $startPc] \
			$defArgNb [trcPrintArgs [expr $sp + $frameSize] -1]]
	    set trcStack [linsert $trcStack 0 $level]
	    break
	}
	set level [list $callPc [trcFuncStartName $startPc] \
			$defArgNb [trcPrintArgs [expr $sp + $frameSize] -1]]
	set trcStack [linsert $trcStack 0 $level]
    }

    return $trcStack
}

##############################################################################
#
# trcFindFuncStart - find the starting address of a function
#
# This routine finds the starting address of a function.
# For MIPS processors, to find the start of a function, we use the instruction
# where the function was called from to compute it. The call was one of
# a "jal", "jalr" or "BxAL[L]" instruction. For "jalr", it will be impossible
# to determine the target address since the contents of the target register
# have been lost along the way.
#
# SYNOPSIS:
#	trcFindFuncStart callPc 
#
# PARAMETERS:
#	callPc:	starting address of the current function
#
# ERRORS: N/A
#
# RETURNS: the starting address of the function
#

proc trcFindFuncStart {callPc} {
    global MAX_SCAN_DEPTH
    global trcDebug

    #
    # Compute the target of the call instruction which will be the
    # entry point (i.e., starting address) of the current function.
    # If the call was by a "jalr" instruction, then there is no way
    # to reconstruct the entry point since the register contents have
    # been lost.
    #

    set blk [wtxMemRead $callPc 4]
    set startInst [expr [memBlockGet -l $blk]]
    memBlockDelete $blk

    if {(($startInst & 0xfc000000) == 0x0c000000)} {
	
	#
	# Jump And Link : target address specified by shifting the offset 
	# left 2 bits and the "or"ing it with the upper 4 bits of the pc.
	#

	return [expr (($startInst & 0x03ffffff) << 2) | \
		     ($callPc & 0xf0000000)]
    }

    if {(($startInst & 0xfc1f0000) == 0x04100000) ||
	(($startInst & 0xfc1f0000) == 0x04110000) ||
	(($startInst & 0xfc1f0000) == 0x04120000) ||
	(($startInst & 0xfc1f0000) == 0x04130000)} {
	
	#
	# Branch And Link : target address specified by shifting the offset
	# left 2 bits with sign extension and the adding it to the address of
	# the instruction in the delay slot.
	#

	set offset [expr $startInst & 0x0000ffff]
	if {$offset & 0x8000} {
	    set offset [expr $offset | 0xffff0000]
	}

        if {$trcDebug > 0} {
            set start [expr $callPc + 1 + $offset]
            puts stdout [format "BAL callPc %x inst %x start %x" $callPc $startInst $start]
        }
	return [expr $callPc + 1 + $offset]
    }
    
    #
    # Either the call was via a "jalr" or ther was a bad instruction where we
    # thought we were called from
    #

    return 0
}

##############################################################################
#
# trcFuncStartName - return the name of the calling function
#
# SYNOPSIS: trcFuncStartName addr
#
# PARAMETER:
# 	addr: address of the symbol about which we want the name
#
# ERRORS: N/A
#
# RETURNS:
#	the name of the symbol if <addr> is the address of a symbol
#       the address if a symbol is found but with a different address
#       ???? when symbol search fails
#

proc trcFuncStartName {addr} {
    
    if [catch "wtxSymFind -value $addr" sym] {
	if {([wtxErrorName $sym] != "SYMTBL_SYMBOL_NOT_FOUND") && 
	    ([wtxErrorName $sym] != "SVR_INVALID_FIND_REQUEST")} {
	    error $sym
	}
    } else {
	set symVal [lindex $sym 1]
	if {$symVal == $addr} {
	    return [lindex $sym 0]
	} else {
	    return [format "%x" $addr]
	}
    }
    return "????"
}

##############################################################################
#
# dbgRetAdrsGet - get return address for current routine
#
# SYNOPSIS:
#	dbgRetAdrsGet ctype cid
#
# PARAMETERS:
#       ctype: context type
#       cid: context id
#
# ERRORS: N/A
#
# RETURNS:
#

proc dbgRetAdrsGet {ctype cid} {
    global spIndex
    global raIndex
    global MAX_SCAN_DEPTH

    set regSet [regSetOfContext $ctype $cid]
    set pc [pcOfRegSet $regSet]

    #
    # scan instructions forward. If we find a "sw ra,x(sp)" or a "jr ra"
    # then the return address in already in register "ra".  If we find
    # a "lw ra,x(sp)" then the return address is saved in offset "x"
    # on the stack. If the instruction space is corrupted, could get
    # a bus error eventually or could find a return address for a
    # neighboring subprogram.
    #

    set n 0
    set found 0
    while {($n < 10) && (! $found)} {
	set scanBlk [wtxMemRead [expr $pc + ($n * $MAX_SCAN_DEPTH)] \
		     $MAX_SCAN_DEPTH]
	for {set i 0} {$i < $MAX_SCAN_DEPTH} {incr i 4} {
	    set inst [expr [memBlockGet -l $scanBlk $i 1]]
	    if {(($inst & 0xffff0000) == 0xafbf0000) ||
		(($inst & 0xffe0003f) == 0x03e00008)} {

		# match "sw ra,x(sp)" or "jr ra" means return address in ra

		set retAddr [lindex $regSet $raIndex]
		set found 1
		break
	    } elseif {($inst & 0xffff0000) == 0x8fbf0000} {
		
		# match "lw ra, x(sp)" means return address is on the stack

		# offset sign extend

		set offset [expr $inst & 0x0000ffff]
		if {$offset & 0x8000} {
		    set offset [expr $offset | 0xffff0000]
		}
		set stackAddr [expr [lindex $regSet $spIndex] + $offset]
		set stackBlk [wtxMemRead $stackAddr 16]
		set retAddr [memBlockGet -l $stackBlk 0 1]

		set found 1
		break
	    }
	}
	memBlockDelete $scanBlk
	incr n
    }
    if {! $found} {
	# return address not found then single step
	return [nextAddrGet $pc]
    } else {
	return $retAddr
    }
}

##############################################################################
#
# dbgFuncCallCheck - check next instruction
# 
# This routine checks to see if the next instruction is a JAL or BAL.
# If it is, it returns TRUE, otherwise, returns FALSE.
# 
# SYNOPSIS:
#	dbgFuncCallCheck addr
# 
# PARAMETERS:
#	addr: where to find instruction
#
# ERRORS: N/A
#
# RETURNS:
#	1 if next instruction is JAL or BAL, or 0 otherwise.
#

proc dbgFuncCallCheck {addr} {

    set blk [wtxMemRead $addr 4]
    set inst [expr [memBlockGet -l $blk]]
    memBlockDelete $blk
    return [expr (($inst & 0xfc000000) == 0x0c000000) || \
		 (($inst & 0xfc00003f) == 0x00000009) || \
		 (($inst & 0xfc1f0000) == 0x04100000) || \
		 (($inst & 0xfc1f0000) == 0x04110000) || \
		 (($inst & 0xfc1f0000) == 0x04120000) || \
		 (($inst & 0xfc1f0000) == 0x04130000)]
}
