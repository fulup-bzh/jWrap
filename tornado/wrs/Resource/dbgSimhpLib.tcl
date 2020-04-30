# dbgSimhpLib.tcl - VxSim/hppa-specific debug routines Tcl implementation
#
# Copyright 1996-1998 Wind River Systems, Inc.
#
# modification history
# -----------------------
# 01h,20may98,dbt  load trcALib.o if trcGetUnwindStart symbol can't be found
# 01g,18mar98,jmb  call dbgNextAddrGet{} call to nextAddrGet{}.
# 01f,12nov97,fle  put dbgNextAddrGet{} in shelcore.tcl as nextAddrGet{}
# 01e,20nov96,mem  minor stack trace patch. (jmb merged 18mar98)
# 01d,04nov96,mem  removed use of on-target table of unwind segments. (jmb)
# 01c,17oct96,mem  cleanup, first fully working version. (jmb merged 18mar98)
# 01b,14oct96,kab  Major mods for stack trace facility.
# 01a,26sep96,mem  written.
#

# DESCRIPTION
# /target/src/arch/simhppa/trcLib.c inspired
# /target/src/arch/simhppa/dbgArchLib.c inspired

# globals

set vxTaskEntry		0
set unwind_start	0
set unwind_end		0
set u_get_unwind_entry	0
set SIGRETURN		0
set trcDebug		0
set defArgNb		5	; # default number of argument

set r2Index		8		; # index of r31 register
set MAX_PROLOGUE_SIZE	[expr 20 * 4]	; # prologue size (20 instructions)
set MAX_SCAN_DEPTH	[expr 250 * 4]	; # search for proc start up to 250
					  # instructions
# some PA-RISC instructions
set INST_BV_R2		0xe840c000	; # standard return instruction.
set MASK_BV		0xffe0fffd	; # 'b' field important, x & n not

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
# CAVEAT
# In order to do the trace, a number of assumptions are made.  In general,
# the trace will work for all C language routines and for assembly language
# routines that follow the PA-RISC calling conventions.
# However, routines written in other languages, strange entries into
# routines, or tasks with corrupted stacks can confuse the trace.
#
# The number of arguments displayed defaults to 5. To change this (e.g.,
# to 7), just set the global variable "trcDefaultArgs" to 7.
# The maximum value you can asign "trcDefaultArgs" is 10.
# The first four arguments displayed may be garbage unless the
# code was compiled with the "-g" flag. In particular, the first four
# arguments shown for any VxWorks library routine may be garbage.
#
# SYNOPSIS:
#	trcStack tid
# 
# PARAMETERS:
#	tid: task to trace
#
# ERRORS: N/A
#
# RETURNS: a list of trace lines
#	   each trace line is a list of 4 elements :
#		{addr callFunc argNb {argList}}
#

proc trcStack {tid} {
    global unwind_end
    global unwind_start
    global u_get_unwind_entry
    global trcDebug

    if {$trcDebug > 0} {
	puts stdout "trcStack tid=$tid"
    }

    if {$unwind_start == 0 || $unwind_end == 0 || $u_get_unwind_entry == 0} {
	puts stderr "trc module not initialized properly"
	return {}
    }

    # get the register set of the task
    set regSet [regSetOfContext CONTEXT_TASK $tid]

    set pc [pcOfRegSet $regSet]
    set sp [lindex $regSet 36]

    return [trcStackLvl $sp $pc $regSet]
}

##############################################################################
#
# trcStackLvl - stack trace routine
#
# Loop and get trace information for each level. Maximum of 40 levels.
#
# SYNOPSYS:
#	trcStackLevel sp pc regSet
#
# PARAMETERS:
#	sp:	content of sp register
#	pc:	content of pc register
#	regSet:	the REG_SET
# 
# ERRORS: N/A
#	
# RETURNS: a list of trace lines
#	   each trace line is a list of 4 elements :
#		{addr callFunc argNb {argList}}
#

proc trcStackLvl {sp pc regSet} {
    global defArgNb	; # default arguments number
    global vxTaskEntry
    global SIGRETURN
    global trcDebug

    set trcStack {}

    for {set depth 0} {$depth < 40} \
	    {incr depth; set sp $prev_sp; set pc $prev_pc} {
	if {$trcDebug > 0} {
	    puts stdout "trcStackLvl: pc=$pc sp=$sp"
	}

	if {$sp == 0xeeeeeeee || $pc == 0xeeeeeeee} {
	    puts stderr "trcStackLvl: walked off stack"
	    break;
	}

	set unwind [trcFindUnwindEntry $pc]

	if {$trcDebug > 0} {
	    puts stdout "trcStackLvl: unwind=$unwind"
	}
	if {$unwind == 0} {
	    puts stdout [format "unable to locate unwind entry for 0x%x" $pc]
	    break
	}
	bindNamesToList {word1 word2 word3 word4} $unwind

	# Break out the interesting fields
	set startAddr  [expr $word1 & ~0x03]
	set frameSize  [expr $word4 & 0x07ffffff]
	set saveSP     [expr $word3 & 0x00000010]
	set millicode  [expr $word3 & 0x40000000]
	set cantunwind [expr $word3 & 0x80000000]

	if {$cantunwind != 0} {
	    puts stdout [format "trcStackLvl: region is unwindable (0x%x)" $pc]
	    break;
	}

	if {$trcDebug > 0} {
	    puts stdout [format \
		"trcStackLvl: depth %d startAddr=0x%x frameSize=%d saveSP=%d" \
		$depth $startAddr $frameSize $saveSP]
	    puts stdout [format \
		"trcStackLvl: millicode=0x%x" \
		$millicode]
	}

	# Get the previous sp
	if {($millicode != 0) 
	  || ($depth == 0) && ($pc < [expr $startAddr + 4])} {
	    # inside a millicode routine or prologue of innermost function
	    set prev_sp $sp
	    incr sp $frameSize
	} elseif {$saveSP != 0} {
	    set blk [wtxMemRead [expr $sp - 4] 4]
	    set prev_sp [memBlockGet -l $blk]
	    memBlockDelete $blk
	} else {
	    set prev_sp [expr $sp - 8 * $frameSize]
	}
	if {$trcDebug > 0} {
	    puts stdout "trcStackLvl: prev_sp=[format "0x%x" $prev_sp]"
	}

	# Get the previous pc
	if {$millicode != 0} {
	    # inside a millicode routine, return address in r31.
	    set prev_pc [lindex $regSet 37]
	} elseif {($depth == 0) && ($frameSize == 0 || $pc == $startAddr)} {
	    # Leaf procedure or in the first instruction of any
	    # procedure, prev_pc is in r2
	    set prev_pc [lindex $regSet 8]
	} else {
	    if {$prev_sp == 0 || $prev_sp == 0xeeeeeeee} {
		puts stderr "bad prev_sp value"
		break;
	    }
	    set blk [wtxMemRead [expr $prev_sp - 20] 4]
	    set prev_pc [memBlockGet -l $blk]
	    memBlockDelete $blk
	}
	if {$trcDebug > 0} {
	    puts stdout "trcStackLvl: prev_pc=[format "0x%x" $prev_pc]"
	}

	# Don't trace beyond vxTaskEntry, or past the beginning of
	# the stack
	if {$startAddr == $vxTaskEntry} {
	    break;
	}
	
	if {$startAddr == $SIGRETURN} {
	    if {$trcDebug > 0} {
		puts stdout "\tpc = SIGRETURN; Adjusting prev_pc"
	    }
	    # prev_pc = (*(UINT *)(prev_sp + 0x30)) & ~3
	    set blk [wtxMemRead [expr $prev_sp + 0x30] 4]
	    set prev_pc [expr [memBlockGet -l $blk] & ~0x3]
	    memBlockDelete $blk
	    if {$trcDebug > 0} {
		puts stdout "trcStackLvl: prev_pc=[format "0x%x" $prev_pc]"
	    }
	}

	# Gather arguments
	set nArg $defArgNb
	if {$depth == 0} {
	    set args [list [lindex $regSet 32] [lindex $regSet 31] \
		    [lindex $regSet 30] [lindex $regSet 29]]
	} else {
	    set args {}
	    for {set arg 0} {$arg < $nArg} {incr arg} {
		set blk [wtxMemRead [expr $prev_sp - 36 - 4 * $arg] 4]
		lappend args [memBlockGet -l $blk]
		memBlockDelete $blk
	    }
	}
	if {$trcDebug > 0} {
	    puts stdout "trcStackLvl: args=$args"
	}

	# Assemble trace entry
	set level [list $prev_pc [trcFuncStartName $startAddr] $nArg $args]
	set trcStack [linsert $trcStack 0 $level]
	if {$prev_sp == 0 || [expr $prev_pc] == 0} {
	    if {$trcDebug > 0} {
		puts stdout "trcStackLvl: done"
	    }
	    break
	}
    }

    return $trcStack
}
    
#############################################################################
#
# trcFindUnwindEntryInTable - 
#
# SYNOPSIS:
#	trcFindUnwindEntryInTable pc start end
#
# PARAMETERS:
#	pc: program counter to find the unwind entry for.
#
# DESCRIPTION:
#	Given a program counter and the beginning and end of an
# unwind table, try to find the needed unwind entry.
#
# ERRORS: N/A
#
# RETURNS:
#	{funcStart frameSize saveSP}
#	or 0.
#

proc trcFindUnwindEntryInTable {pc start end} {
    global u_get_unwind_entry
    global trcDebug

    if {$trcDebug > 0} {
	puts stdout "trcFindUnwindEntryInTable pc=$pc start=$start end=$end"
    }

    set pUnwindEntry [wtxDirectCall $u_get_unwind_entry $pc 0 $start $end]

    if {$trcDebug > 0} {
	puts stdout "\tU_get_unwind_entry: returns $pUnwindEntry"
    }
    if {$pUnwindEntry == -1} {
	return 0
    }

    # Seems to return $end sometimes on failure - strange.
    if {$pUnwindEntry == $end} {
	if {$trcDebug > 0} {
	    puts stdout "\tU_get_unwind_entry: returns END"
	}
	return 0
    }

    set blk [wtxMemRead $pUnwindEntry 16]
    bindNamesToList {word1 word2 word3 word4} [memBlockGet -l $blk]
    memBlockDelete $blk

    if {$trcDebug > 0} {
	puts stdout "\traw unwind entry: $word1 $word2 $word3 $word4"
    }

    # test for discontinuous unwind descriptors
    if {[expr $word3 & 0x18000000] == 0x18000000} {
	set newpc [expr $word1 - 4]
	set unwind [trcFindUnwindEntry $newpc]
	if {$unwind == 0} {
	    puts stdout [format "trcFindUnwindEntry: can't find prev desc (0x%x)" $newpc]
	    return 0
	}
	return $unwind
    }

    return [list $word1 $word2 $word3 $word4]
}

#############################################################################
#
# trcFindUnwindEntryInServer - search the target-server tables
#
# SYNOPSIS:
#	trcFindUnwindEntryInServer pc
#
# DESCRIPTION:
#	Use the server maintained list of unwind entries for loaded
# modules.  The unwindTable is an array of unwindEntry[unwindTableSize].
#
# PARAMETERS:
#	pc: program counter to find the unwind entry for.
#
# ERRORS: N/A
#
# RETURNS:
#	{funcStart frameSize saveSP}
#	or 0.
#

proc trcFindUnwindEntryInServer {pc} {
    global trcDebug
    set unwind 0

    if {$trcDebug > 0} {
	puts stdout "trcFindUnwindEntryInServer $pc"
    }

    foreach mod [wtxObjModuleList] {
	set info [wtxObjModuleInfoGet $mod]
	if {$trcDebug > 0} {
	    puts stdout "  $info"
	}
	set segList [lrange $info 5 end]
	foreach segInfo $segList {
	    if {$trcDebug > 0} {
		puts stdout "    $segInfo"
	    }
	    bindNamesToList {flags addr length} $segInfo
	    # Check for the UNWIND segment flags.
	    if {$flags == 0x100} {
		if {$trcDebug > 0} {
		    puts stdout "      bingo"
		}
		set end [expr $addr + $length]
		set unwind [trcFindUnwindEntryInTable $pc $addr $end]
		if {$unwind != 0} {
		    if {$trcDebug > 0} {
			puts stdout "\tFOUND start $start, end $end"
		    }
		    break
		} else {
		    if {$trcDebug > 0} {
			puts stdout "\tmissed"
		    }
		}
	    }
	}
    }
    return $unwind
}


#############################################################################
#
# trcFindUnwindEntry - 
#
# SYNOPSIS:
#	trcFindUnwindEntry pc
#
# PARAMETERS:
#	pc: program counter to find the unwind entry for.
#
# ERRORS: N/A
#
# RETURNS:
#	{word1 word2 word3 word4} from the unwind entry
#	or 0.
#

proc trcFindUnwindEntry {pc} {
    global unwind_end
    global unwind_start

    set unwind [trcFindUnwindEntryInTable $pc $unwind_start $unwind_end]
    if {$unwind != 0} {
	return $unwind
    }
    # walk through target-server managed table
    set unwind [trcFindUnwindEntryInServer $pc]

    # not found
    return $unwind
}

##############################################################################
#
# trcFuncStartName - return the name of the calling function
#
# SYNOPSIS: trcFuncStartName addr
#
# PARAMETER:
#	addr: address of the symbol about which we want the name
#
# ERRORS: N/A
#
# RETURNS:
#	the name of the symbol if <addr> is the address of a symbol
#	the address if a symbol is found but with a different address
#	???? when symbol search fails
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
# trcSimhpLib.tcl initialization code
#
# This code is executed when the file is sourced. So symbol researches needed
# to get stack trace are done only once.
# 


if [catch "wtxSymFind -name trcGetUnwindStart" status] {
    if {[wtxErrorName $status] == "SYMTBL_SYMBOL_NOT_FOUND"} {

	# Symbol "trcGetUnwindStart" does not exist: the module must be loaded.
	# Verify if trcALib.o exists in right directory

	set cpuId [lindex [lindex [wtxTsInfoGet] 2] 0]
	set name [wtxPath target lib obj$cpuType($cpuId)[targetTool]vx]trcALib.o

	if { [file exists $name] == 0 } {
	    puts stdout "WARNING : File $name is missing" 
	} else {
	    # load trcALib.o file to get spy symbols

	    wtxObjModuleLoad LOAD_ALL_SYMBOLS $name
	}
    }
}

if [catch "wtxSymFind -name trcGetUnwindStart" msg] {
    if {[wtxErrorName $msg] == "SYMTBL_SYMBOL_NOT_FOUND"} {
	puts stdout "WARNING : Can not get trcGetUnwindStart"
    } else {
	error $msg
    }
} else {
    set unwind_start [wtxDirectCall [lindex $msg 1]]
}

if [catch "wtxSymFind -name trcGetUnwindEnd" msg] {
    if {[wtxErrorName $msg] == "SYMTBL_SYMBOL_NOT_FOUND"} {
	puts stdout "WARNING : Can not get trcGetUnwindEnd"
    } else {
	error $msg
    }
} else {
    set unwind_end [wtxDirectCall [lindex $msg 1]]
}

if [catch "wtxSymFind -name U_GET_UNWIND_ENTRY" msg] {
    if {[wtxErrorName $msg] == "SYMTBL_SYMBOL_NOT_FOUND"} {
	puts stdout "WARNING : Can not get U_GET_UNWIND_ENTRY"
    } else {
	error $msg
    }
} else {
    set u_get_unwind_entry [lindex $msg 1]
}

if [catch "wtxSymFind -name vxTaskEntry" msg] {
    if {[wtxErrorName $msg] == "SYMTBL_SYMBOL_NOT_FOUND"} {
	puts stdout "WARNING : Can not get vxTaskEntry"
    } else {
	error $msg
    }
} else {
    set vxTaskEntry [lindex $msg 1]
}

if [catch "wtxSymFind -exact -name _SIGRETURN" sym] {
    if {([wtxErrorName $sym] == "SYMTBL_SYMBOL_NOT_FOUND") || 
    ([wtxErrorName $sym] == "SVR_INVALID_FIND_REQUEST")} {
	puts stdout "WARNING : Missing symbol _SIGRETURN"
    } else {
	error $sym
    }
} else {
    set SIGRETURN [lindex $sym 1]
}


##############################################################################
# shell.tcl debugging support.
#
set dbgDebug		0


##############################################################################
#
# dbgRetAdrsGet - get return address for current routine
#
# As it impossible to reliably determine return address from anywhere in a 
# routine, we assume this function is called only by cret{}. Thus, as the goal 
# is to jump over the current routine, we run until the end and the then get
# reliably the return address.
#
# Currently, millicode routines are not handled.
#
# SYNOPSIS:
#	dbgRetAdrsGet ctype cid
#
# PARAMETERS:
#	ctype: context type
#	cid: context id
#
# ERRORS: N/A
#
# RETURNS: return address for current routine or "done" if the "bv" instruction
#	   can not be hit
#

proc dbgRetAdrsGet {ctype cid} {
    global r2Index
    global MAX_SCAN_DEPTH
    global INST_BV_R2
    global MASK_BV
    global dbgDebug

    set regSet [regSetOfContext $ctype $cid]
    set pc [pcOfRegSet $regSet]

    # scan for "bv %r0(%r2)"

    set n 0
    set found 0
    while {($n < 10) && (! $found)} {
	set scanBlk [wtxMemRead [expr $pc + ($n * $MAX_SCAN_DEPTH)] \
		     $MAX_SCAN_DEPTH]
	for {set i 0} {$i < $MAX_SCAN_DEPTH} {incr i 4} {
	    set inst [expr [memBlockGet -l $scanBlk $i 1]]
	    if {($inst & $MASK_BV) == $INST_BV_R2} {
		set addr [expr $pc + ($n * $MAX_SCAN_DEPTH) + $i]
		set found 1
		break
	    }
	}
	memBlockDelete $scanBlk
	incr n
    }
    if {$dbgDebug > 0} {
	puts stdout [format "dbgRetAdrsGet: found=%d addr=0x%x" $found $addr]
    }
    if {! $found} {
	# "bv" not found then single step
	return [nextAddrGet $pc]
    } else {
	# put a breakpoint, wait for that breakpoint to be hit, then return
	# the address in r2 which is the return address

	set action [expr [wtxEnumFromString ACTION_TYPE ACTION_STOP] | \
			 [wtxEnumFromString ACTION_TYPE ACTION_NOTIFY]]
	set epNum [wtxEventpointAdd WTX_EVENT_TEXT_ACCESS $addr \
		   $ctype $cid $action 0 0 0]
	
	wtxContextCont $ctype $cid
	while 1 {
	    set event [wtxEventPoll 300]
	    if {$dbgDebug > 0} {
		puts stdout "dbgRetAdrsGet: event=$event"
	    }
	    if {![string compare [lindex $event 0] "TEXT_ACCESS"]
		&& ([lindex $event 1] == $cid ||
			[lindex $event 1] == 0xffffffff)
		&& [lindex $event 2] == 
			[wtxEnumFromString CONTEXT_TYPE $ctype]} {
		if {([lindex $event 3] == $addr)} {
	 	    set regSet [regSetOfContext $ctype $cid]
		    wtxEventpointDelete $epNum
		    set r2 [expr [lindex $regSet $r2Index] & ~0x03]
		    if {$dbgDebug > 0} {
			puts stdout [format "dbgRetAdrsGet: r2=0x%x" $r2]
		    }
		    return $r2
		} else {
		    if {$dbgDebug > 0} {
			puts stdout "dbgRetAdrsGet: done"
		    }
		    shEventDispatch $event
		    wtxEventpointDelete $epNum
		    return "done"
		}
		break
	    } else {
		shEventDispatch $event
	    }
	}
    }
}

##############################################################################
#
# dbgFuncCallCheck - check next instruction
#
# This routine checks to see if the next instruction is a function call.
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
#	1 if next instruction is a function call, or 0 otherwise.
#

proc dbgFuncCallCheck {addr} {
    set INST_BL		0xe8000000	; # branch & link instruction.
    set INST_BLR	0xe8004000	; # branch & link reg instruction.
    set MASK_INSN	0xfc00e000	; # no fields are important

    set INST_BLE	0xe4000000	; # branch & link external instruction.
    
    set blk [wtxMemRead $addr 4]
    set inst [expr [memBlockGet -l $blk]]
    memBlockDelete $blk
    set inst [expr $inst & $MASK_INSN]
    return [expr ($inst == $INST_BL) || \
	         ($inst == $INST_BLR) || \
		 (($inst & 0xfc000000) == $INST_BLE)]
}
