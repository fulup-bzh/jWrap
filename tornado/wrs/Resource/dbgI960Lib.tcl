# dbgI960Lib.tcl - i960-specific tt Tcl implementation
#
# Copyright 1996-1998 Wind River Systems, Inc.
#
# modification history
# -----------------------
# 01d,10mar98,dbt  added architecture specific help message and support
#		   for hardware breakpoints.
# 01d,17sep97,fle  changing call to disassemble in call to wtxMemDisassemble
# 01c,06jun96,elp  made dbgRetAdrsGet{} work in sytem mode (SPR# 6659).
# 01b,06mar96,elp  added debug routines and renamed,
#                  caught SVR_INVALID_FIND_REQUEST errors,
#		   added expr before each memBlockGet returning one value.
# 01a,22feb96,elp  adapted from trcLib.c and tt-m68k.tcl
#

# DESCRIPTION
# /target/src/arch/i960/trcLib.c inspired
# /target/src/arch/i960/dbgArchLib.c inspired

# globals

set defArgNb		5	; # default number of argument
set regNb		35	; # number of register

# Set architecture help message
# Hardware breakpoints are only supported by I960CA, I960JX and I960HX
# processors.

switch -regexp $cpuType($__wtxCpuType) {
    I960CA -
    I960JX -
    I960HX {
	set archHelpMsg		"bh        addr\[,access\[,task\[,count\]\]\]\
				Set hardware breakpoint\n\
				\t\taccess:\t0 - store only\t\t1 - load/store\n\
				\t\t\t2 - data/inst fetch\t3 - any access\n\
				\t\t\t4 - instruction\n";
	set hwBpTypeList {
	    {"0"	"(hard-store)"}
	    {"1"	"(hard-load/store)"}
	    {"2"	"(hard-fetch)"}
	    {"3"	"(hard-any access)"}
	    {"4"	"(hard-inst.)"}
	};
    }
}

set CALLX_MASK		0x86
set CALLS_MASK		0x660

set regSetSize 	140;	# size of register set

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
#	trcStack tid
# 
# PARAMETERS:
#	tid: task to trace
#
# ERRORS: N/A
#
# RETURNS: a list of trace line
#          each trace line is a list of 4 elements :
#               {addr callFunc argNb {argList}}
#

proc trcStack {tid} {
    global offset
    global defArgNb
    global regNb
    global regSetSize

    #
    # for each level 3 values are necessary:
    #	- pPfp : address of the register set
    #	- rip: rip register value
    #	- pG0: g0 register address
    #

    # lastLevel variable is used to differentiate the last trace level.
    # display <defArgNb> parameters without considering it is the default
    # value (ie without [...]) only at last level 
    
    set lastLevel 1
    set trcStack {}

    set pPfp [expr $tid + $offset(WIND_TCB,regs)]

    # get register set via wtxRegsGet{} because it may be necessary to
    # push registers from the stack and it is done automatically by
    # wtxRegsGet{}

    set blk [wtxRegsGet CONTEXT_TASK $tid REG_SET_IU 0 $regSetSize]
    for {set depth 0} {$depth < 40} \
	{incr depth; set pPfp $nextPPfp; 
	 set blk [wtxMemRead $pPfp [expr 32 * 4]]} {
	set pG0 [expr $pPfp + 64]

	bindNamesToList {nextPPfp dummy rip} [memBlockGet -l $blk]
	set rip [expr $rip & 0xfffffffc]
	memBlockDelete $blk
	if {$lastLevel} {
	    set level [list [trcFindCall $rip] [trcFuncStartName $rip] \
			    $defArgNb [trcPrintArgs $pG0 $defArgNb]]
	    set lastLevel 0
	} else {
	    set funcName [trcFuncStartName \
			  [expr [trcFindFuncStart $rip $pPfp]]]
	    set level [list [trcFindCall $rip] $funcName \
			     -1 [trcPrintArgs $pG0 -1]]
	}
	set trcStack [linsert $trcStack 0 $level]
	if {$nextPPfp == 0} {
	    break	
	}
    }
    
    return $trcStack
}

#############################################################################
#
# trcFindCall - get address from which function was called
#
# SYNOPSIS:
#	trcFindCall rip
#
# PARAMETERS:
#	rip: content of rip register 
#
# ERRORS: N/A
#
# RETURNS: address from which current subroutine was called, or NULL.
#
proc trcFindCall {rip} {
    global CALLX_MASK

    set blk [wtxMemRead [expr $rip - 4] 4]
    set instr [expr [memBlockGet -l $blk]]
    memBlockDelete $blk
    if {(($instr >> 24) & 0xff) == $CALLX_MASK} {
	return [expr $rip - 4]
    } else {
	return $rip
    }
}

##############################################################################
#
# trcFindFuncStart - find the starting address of a function
#
# This routine finds the starting address of a function by one of several ways.
#
# We can find the start of the function we are in by looking at the rip
# of the given REG_SET backing up one instruction and examining the CALL(X)
# instruction. We can find the starting adrs of the function either
# explicitly in the case of a CALLX or by taking the offset of the
# CALL instruction and adding/subracting it from the adrs of the CALL
# instruction.
#
# CAVEATS:
# In the case of a register indirect CALLX instruction that uses a global
# register (ie. callx   (g9)) this function will return an erroneous value
# because global registers are not valid for frames previous to the current
# frame, and may not be valid for the current frame as they may have changed
# since the start of the function.
#
# SYNOPSIS:
#	trcFindFuncStart rip pRegSet
#
# PARAMETERS:
#	rip: content of rip register
#	pRegSet: address of the register set
#
# ERRORS: N/A
#
# RETURNS: the address of the calling function
#

proc trcFindFuncStart {rip pRegSet} {
    global CALLX_MASK
    global CALLS_MASK

    set blk [wtxMemRead [expr $rip - 8] 12]
    bindNamesToList {instr1 instr2 instr3} [memBlockGet -l $blk]
    memBlockDelete $blk

    # if instr1 is callx then next 32bit quantity is abs adrs of func

    if {(($instr1 >> 24) & 0xff) == $CALLX_MASK} {
	return $instr2
    }

    # if instr2 is callx then assume register indirect

    if {(($instr2 >> 24) & 0xff) == $CALLX_MASK} {
	return [memInstrRefAddrGet $rip $instr2 $instr3 $pRegSet]
    }

    # if instr2 is calls instruction, then just return the pInstr

    set op [expr ((($instr2 >> 24) & 0xff) << 4) | (($instr2 >> 7) & 0xf)]
    if {$op == $CALLS_MASK} {
	return [expr $rip - 4]
    }

    # otherwise assume std call instruction

    set displace [expr $instr2 & 0xfffffc]
    if {$displace & 0x800000} {
	
	# sign bit is set, sign extend
	set displace [expr 0xff000000 | $displace]
    }
    return [expr $rip + $displace]

}

##############################################################################
#
# memInstrRefAddrGet - absolute address reference from a MEM instruction 
#
# SYNOPSIS:
#	memInstrRefAddrGet rip instr nextInstr pRegSet
#
# PARAMETERS:
#	rip: rip register content
#	instr: instruction pointed to by rip
#	nextInstr: followinf instruction
#	pRegSet: address of the register set
#
# ERRORS: N/A
#
# RETURNS:
#	absolute address or 0xffffffff if it fails
#

proc memInstrRefAddrGet {rip instr nextInstr pRegSet} {

    set memaModeBits [expr ($instr >> 12) & 0x3]
    set membModeBits [expr ($instr >> 10) & 0xf]
    set offset [expr $instr & 0xfff]
    set reg1 [expr (($instr >> 14) & 0x1f) * 4]	; # register number * 4 bytes
    set reg2 [expr ($offset & 0x1f) * 4]	; # register number * 4 bytes
    set disp $nextInstr				; # displacement
    set scale [expr ($instr >> 7) & 0x7]	; # scale

    switch [format "0x%x" $memaModeBits] {
	0x0 {
	    # exp
	    
	    return $offset
	}
	0x2 {
	    # exp(reg)
	    
	    set blk [wtxMemRead [expr $pRegSet + $reg1] 4]
	    set abase [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    return [expr $abase + $offset]
	}
    }
    switch [format "0x%x" $membModeBits] {
	0x4 {
	    # (reg)

	    set blk [wtxMemRead [expr $pRegSet + $reg1] 4]
	    set abase [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    return $abase
	}
	0x5 {
	    # exp(ip)
	    
	    return [expr $rip + $disp + 0x8]
	}
	0x7 {
	    # (r1) [r2 * scale]

	    set blk [wtxMemRead [expr $pRegSet + $reg1] 4]
	    set abase [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    set blk [wtxMemRead [expr $pRegSet + $reg2] 4]
	    set index [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    return [expr $abase + ($index << $scale)]
	}
	0xc {
	    # exp
	    
	    return $disp
	}
	0xd {
	    # exp(reg)
	    
	    set blk [wtxMemRead [expr $pRegSet + $reg1] 4]
	    set abase [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    return [expr $disp + $abase]
	}
	0xe {
	    # exp [reg * scale]
	    
	    set blk [wtxMemRead [expr $pRegSet + $reg2] 4]
	    set index [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    return [expr $disp + ($index << $scale)]
	}
	0xf {
	    # exp (r1) [r2 * scale]
	    
	    set blk [wtxMemRead [expr $pRegSet + $reg1] 4]
	    set abase [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    set blk [wtxMemRead [expr $pRegSet + $reg2] 4]
	    set index [expr [memBlockGet -l $blk]]	; # register value
	    memBlockDelete $blk
	    return [expr $disp + $abase + ($index << $scale)]
	}
    }
    return 0xffffffff
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
# dbgRetAdrsGet - address of the subroutine in which has hit a breakpoint
#
# SYNOPSIS:
#       dbgRetAdrsGet ctype cid
#
# PARAMETERS:
#       ctype: context type
#       cid: context id
#
# ERRORS: N/A
#
# RETURNS: Address of the next instruction to be executed upon return of
#	   current routine
#

proc dbgRetAdrsGet {ctype cid} {

    set pfpIndex	0		; # pfp index in regSet
    set ripIndex 	2		; # rip index in regSet
    set g14Index 	30		; # g14 index in regSet
    set INST_MOV_G14	0x5c80161e	; # mov g14, gx instruction
    
    # from this address, find the symbol in the symbol table that
    # is closest yet lower than the address. If this symbol is a leaf-proc
    # entry, then get the return address either from gx or g14,
    # depending on whether or not the mov g14, gx instruction has been
    # executed. If the symbol is not a leaf_proc entry point,
    # it is a regular function entry. Get the return address from
    # the rip of the previous frame. Caveat: if an assembly language
    # symbol starts with an `_', this could fool this algo. into
    # thinking it is the start of a function.

    set regSet [regSetOfContext $ctype $cid]
    set pfp [lindex $regSet $pfpIndex]
    set rip [expr [lindex $regSet $ripIndex] & 0xfffffffc]

    if [catch "wtxSymFind -value $rip" sym] {
	if {([wtxErrorName $sym] != "SYMTBL_SYMBOL_NOT_FOUND") && 
	    ([wtxErrorName $sym] != "SVR_INVALID_FIND_REQUEST")} {
	    error $sym
	}
    }
    set symName [lindex $sym 0]
    if {[string range $symName \
		      [expr [string length $symName] - 3] end] == ".lf"} {
	
	# this is a leaf_proc. first we must check to see if we
	# are sitting on the mov g14, gx instruction If we are,
	# return the value in g14, otherwise, disect the instruction
	# and figure out what register is holding the return value

	set blk [wtxMemRead $rip 4]
	set inst [expr [memBlockGet -l $blk]]
	memBlockDelete $blk
	if {($inst & 0xff87ffff) == $INST_MOV_G14} {
	    set retVal [lindex $regSet $g14Index]
	} else {
	    set regNum [expr ($inst & 0x00f80000) >> 0x13]
	    set blk [wtxMemRead [expr $pfp + ($regNum * 4)] 4]
	    set retVal [expr [memBlockGet -l $blk]]
	    memBlockDelete $blk
	}
	
	# we still have to figure out if we got to this point in the 
	# leaf-proc via a 'call' or 'bal' instruction. If we came via a 
	# call instruction, the address 'retVal' will point to the 'ret' 
	# instruction at the end of the function. Otherwise, it will be 
	# the address of the instruction following the 'bal'. If 'retVal'
	# does not point to a 'ret' instruction, we can just return it.
	#
	# NOTE: We could still be fooled if caller's 'bal' or 'balx' is
	# followed by 'ret.' Perhaps we should also check to see if the
	# instruction preceding 'ret' is 'bx gx' and or some similar check.
   
	set blk [wtxMemRead $retVal 4]
	set inst [expr [memBlockGet -l $blk]]
	memBlockDelete $blk
	if {($inst & 0xff000000) != 0x0a000000} {
	    return $retVal
	}
    }

    # non-leaf_proc function or 'called' leaf-proc

    set blk [wtxMemRead [expr $pfp + 8] 4]
    set retVal [expr [memBlockGet -l $blk] & 0xfffffffc]
    memBlockDelete $blk
    return $retVal
}

##############################################################################
#
# dbgFuncCallCheck - check next instruction
#
# This routine checks to see if the next instruction is a JSR or BSR.
# If it is, it returns TRUE, otherwise, returns FALSE.
#
# SYNOPSIS:
#       dbgFuncCallCheck addr
#
# PARAMETERS:
#       addr: where to find instruction
#
# ERRORS: N/A
#
# RETURNS:
#       1 if next instruction is JSR or BSR, or 0 otherwise.
#

proc dbgFuncCallCheck {addr} {
    
    set blk [wtxMemRead $addr 4]
    set opcode [expr ([memBlockGet -l $blk] >> 24) & 0xff]
    memBlockDelete $blk
    switch [format "0x%02x" $opcode] {
	0x09 -
	0x0b -
	0x66 -
	0x85 -
	0x86 {return 1}
	default {return 0}
    }
}
