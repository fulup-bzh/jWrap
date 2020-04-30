# sh-simsp.tcl - simsparc-specific constants for host shell Tcl implementation
#
# Copyright 1995-1996 Wind River Systems, Inc.
#
# modification history
# -----------------------
# 01q,01jul98,c_s  WindView 2 -> Tornado 2 Merge
# 01p,06may98,nps  added support for rBuff and triggering.
# 01r,05jun98,f_l  added offsets for taskWait routines
# 01q,17apr98,rlp  removed numMaxMsgsSent for backward compatibility.
# 01p,05nov97,rlp  added numMaxMsgsSent for tracking messages sent.
# 01o,29oct96,pad  Added routine underscoreStrip (SPR #7159).
# 01n,30sep96,pad  Added mangledSymListGet procedure
# 01m,29apr96,p_m  added pcGetGopher and spGetGopher to fix SPR#6409.
# 01l,06mar96,elp  changed trcSimspLib.tcl to dbgSimspLib.tcl.
# 01k,29jan96,elp  came back to version 01i,
#		   added availRegPuts{}, regOffsetFromIndexGet{},
#		   some proc headers, source trcSimspLib.tcl.
# 01j,17nov95,elp  changed regSetGopher for mRegs{} and changed regSetPrint{}
#		   and taskRegSetVec{} to take care of new regSetGopher.
# 01i,15nov95,c_s  added regSetOfContext.
# 01h,09nov95,s_w  added offset(WIND_TCB,safeCnt) to fix SPR 5090
# 01g,08nov95,elp  added regNList (register Name List) for mRegs
# 01f,19sep95,pad  added offset information for Shared Memory Objects.
# 01e,12sep95,pad  added offset information for POSIX semaphores and msg queues.
# 01d,31may95,c_s  removed stackCheck gopher.
# 01c,18may95,c_s  added excInfoShow.
# 01b,14mar95,c_s  added pcOfRegSet.
# 01a,18jan95,c_s  written; derived from sh-sparc.tcl
#

# DESCRIPTION
#
# This modules holds architecture dependant routines and globals
#
# RESOURCE FILES
# wpwr/host/resource/tcl/dbgSimspLib.tcl
#

source "[wtxPath host resource tcl]dbgSimspLib.tcl"

# globals

set offset(WIND_TCB,timeout)            0x018
set offset(WIND_TCB,activeNode)         0x020
set offset(WIND_TCB,objCore)            0x030
set offset(WIND_TCB,name)               0x034
set offset(WIND_TCB,options)            0x038
set offset(WIND_TCB,status)             0x03c
set offset(WIND_TCB,priority)           0x040
set offset(WIND_TCB,priNormal)          0x044
set offset(WIND_TCB,pPendQ)		0x05c
set offset(WIND_TCB,safeCnt)		0x060
set offset(WIND_TCB,entry)              0x074
set offset(WIND_TCB,pStackBase)         0x078
set offset(WIND_TCB,pStackLimit)        0x07c
set offset(WIND_TCB,pStackEnd)          0x080
set offset(WIND_TCB,errorStatus)        0x084
set offset(WIND_TCB,regs)               0x138
set offset(WIND_TCB,pc)                 0x138
set offset(WIND_TCB,sp)                 0x190

set offset(OBJ_CLASS,objPartId)		0x004

set offset(SEMAPHORE,semType)		0x004
set offset(SEMAPHORE,options)		0x005
set offset(SEMAPHORE,qHead)		0x008
set offset(SEMAPHORE,count)		0x018

set offset(POSIX_SEM,semId)		0x004
set offset(POSIX_SEM,refCnt)		0x008
set offset(POSIX_SEM,sem_name)		0x00c

set offset(MSG_Q,msgQ)			0x004
set offset(MSG_Q,freeQ)			0x024
set offset(MSG_Q,options)		0x044
set offset(MSG_Q,maxMsgs)		0x048
set offset(MSG_Q,maxMsgLength)		0x04c
set offset(MSG_Q,sendTimeouts)		0x050
set offset(MSG_Q,recvTimeouts)		0x054

set offset(POSIX_MSG_Q_DES,f_flags)	0x004
set offset(POSIX_MSG_Q_DES,f_data)	0x008

set offset(POSIX_MSG_Q,msgq_cond_read)  0x000
set offset(POSIX_MSG_Q,msgq_cond_data)  0x010
set offset(POSIX_MSG_Q,msgq_sym)	0x020
set offset(POSIX_MSG_Q,msgq_attr)	0x0e4

set offset(POSIX_MSG_Q_ATTR,mq_maxmsg)	0x000
set offset(POSIX_MSG_Q_ATTR,mq_msgsize)	0x004
set offset(POSIX_MSG_Q_ATTR,mq_flags)	0x008
set offset(POSIX_MSG_Q_ATTR,mq_curmsgs)	0x00c

set offset(SM_OBJ,objType)              0x004

set offset(SM_OBJ_TCB,localTcb)         0x008
set offset(SM_OBJ_TCB,ownerCpu)         0x00c

set offset(SM_OBJ_MEM_HDR,smTcbPart)    0x00c
set offset(SM_OBJ_MEM_HDR,smSemPart)    0x030
set offset(SM_OBJ_MEM_HDR,smNamePart)   0x074
set offset(SM_OBJ_MEM_HDR,smMsgQPart)   0x0b8
set offset(SM_OBJ_MEM_HDR,smPartPart)   0x0fc
set offset(SM_OBJ_MEM_HDR,smSysPart)    0x140
set offset(SM_OBJ_MEM_HDR,nameDtb)      0x184
set offset(SM_OBJ_MEM_HDR,objCpuTbl)    0x1b0
set offset(SM_OBJ_MEM_HDR,maxSems)      0x1b4
set offset(SM_OBJ_MEM_HDR,maxMsgQueues) 0x1b8
set offset(SM_OBJ_MEM_HDR,maxTasks)     0x1bc
set offset(SM_OBJ_MEM_HDR,maxMemParts)  0x1c0
set offset(SM_OBJ_MEM_HDR,maxNames)     0x1c4
set offset(SM_OBJ_MEM_HDR,curNumSemB)   0x1c8
set offset(SM_OBJ_MEM_HDR,curNumSemC)   0x1cc
set offset(SM_OBJ_MEM_HDR,curNumMsgQ)   0x1d0
set offset(SM_OBJ_MEM_HDR,curNumTask)   0x1d4
set offset(SM_OBJ_MEM_HDR,curNumPart)   0x1d8
set offset(SM_OBJ_MEM_HDR,curNumName)   0x1dc

set offset(SM_SEM,objType)              0x004
set offset(SM_SEM,smPendQ)              0x00c
set offset(SM_SEM,count)                0x014

set offset(SM_MSG_Q,msgQSem)            0x008
set offset(SM_MSG_Q,msgQ)               0x024
set offset(SM_MSG_Q,freeQSem)           0x02c
set offset(SM_MSG_Q,freeQ)              0x048
set offset(SM_MSG_Q,options)            0x050
set offset(SM_MSG_Q,maxMsgs)            0x054
set offset(SM_MSG_Q,maxMsgLength)       0x058
set offset(SM_MSG_Q,sendTimeouts)       0x05c
set offset(SM_MSG_Q,recvTimeouts)       0x060

set offset(SM_MSG_NODE,msgLength)       0x008
set offset(SM_MSG_NODE,message)         0x00c

set offset(SM_PARTITION,freeList)               0x008
set offset(SM_PARTITION,totalWords)             0x028
set offset(SM_PARTITION,curBlocksAllocated)     0x034
set offset(SM_PARTITION,curWordsAllocated)      0x038
set offset(SM_PARTITION,cumBlocksAllocated)     0x03c
set offset(SM_PARTITION,cumWordsAllocated)      0x040

set offset(SM_FREE_BLOCK,node)          0x010

set offset(SM_BLOCK_HDR,nWords)         0x004

set offset(SYMBOL,name)			0x004

set offset(WDOG,timeout)                0x00c
set offset(WDOG,status)                 0x014
set offset(WDOG,routine)                0x018
set offset(WDOG,parameter)              0x01c

set offset(MSG_NODE,msgLength)		0x004
set offset(MSG_NODE,message)		0x008

set offset(Q_JOB_HEAD,pendQ)		0x010
set offset(Q_FIFO_G_HEAD,pFifoQ)	0x008

set offset(DEV_HDR,drvNum)		0x008
set offset(DEV_HDR,name)		0x00c

set offset(DL_NODE,next)		0x000
set offset(DL_LIST,head)		0x000

set offset(DEV_HDR,drvNum)		0x008

set offset(FD_ENTRY,pDevHdr)		0x000
set offset(FD_ENTRY,name)		0x008
set offset(FD_ENTRY,inuse)		0x00c
set sizeof(FD_ENTRY)			0x010

set offset(PARTITION,totalWords)	0x028
set offset(PARTITION,curBlocksAllocated) 0x034
set offset(PARTITION,curWordsAllocated) 0x038
set offset(PARTITION,cumBlocksAllocated) 0x03c
set offset(PARTITION,cumWordsAllocated) 0x040
set offset(PARTITION,freeList)          0x004
set offset(FREE_BLOCK,node)		0x008
set offset(FREE_BLOCK,hdr.nWords)	0x004


set offset(RBUFF_TYPE,objCore)          0x000
set offset(RBUFF_TYPE,buffRead)         0x038
set offset(RBUFF_TYPE,buffWrite)        0x03c
set offset(RBUFF_TYPE,dataRead)         0x040
set offset(RBUFF_TYPE,dataWrite)        0x044

set offset(RBUFF_TYPE,srcPart)          0x08c
set offset(RBUFF_TYPE,options)          0x090
set offset(RBUFF_TYPE,buffSize)         0x094
set offset(RBUFF_TYPE,currBuffs)        0x098
set offset(RBUFF_TYPE,threshold)        0x09c
set offset(RBUFF_TYPE,minBuffs)         0x0a0
set offset(RBUFF_TYPE,maxBuffs)         0x0a4
set offset(RBUFF_TYPE,maxBuffsActual)   0x0a8
set offset(RBUFF_TYPE,emptyBuffs)       0x0ac
set offset(RBUFF_TYPE,dataContent)      0x0b0
set offset(RBUFF_TYPE,writesSinceReset) 0x0b4
set offset(RBUFF_TYPE,readsSinceReset)  0x0b8
set offset(RBUFF_TYPE,timesExtended)    0x0bc
set offset(RBUFF_TYPE,timesXThreshold)  0x0c0
set offset(RBUFF_TYPE,bytesWritten)     0x0c4
set offset(RBUFF_TYPE,bytesRead)        0x0c8
set offset(RBUFF_TYPE,bytesPeak)        0x0cc

set offset(TRIGGER,objCore)          0x000 
set offset(TRIGGER,eventId)          0x004 
set offset(TRIGGER,status)           0x006 
set offset(TRIGGER,disable)          0x008 
set offset(TRIGGER,contexType)       0x00c 
set offset(TRIGGER,contextId)        0x010 
set offset(TRIGGER,objId)            0x014 
set offset(TRIGGER,chain)            0x018 
set offset(TRIGGER,next)             0x01c 
set offset(TRIGGER,conditional)      0x020 
set offset(TRIGGER,condType)         0x024 
set offset(TRIGGER,condEx1)          0x028 
set offset(TRIGGER,condOp)           0x02c 
set offset(TRIGGER,condEx2)          0x030 
set offset(TRIGGER,actionType)       0x034 
set offset(TRIGGER,actionFunc)       0x038 
set offset(TRIGGER,actionArg)        0x03c 
set offset(TRIGGER,actionDef)        0x040 
set offset(TRIGGER,hitCnt)           0x044 


#
# Define a gopher that will fetch the CPU registers from the TCB of a 
# given task.  The gopher pointer should point to the TCB upon evaluation
# of this string.
#

set regSetGopher "
    <+$offset(WIND_TCB,regs) @@@@@@ +8 @@@@@@@@ @@@@@@@@ @@@@@@@@ @@@@@@@@>"
#                            pc..y      g0..g7   o0..o7   l0..l7   i0..i7

# gophers that will get the PC value and the SP value

set pcGetGopher "<+$offset(WIND_TCB,pc) @>"
set spGetGopher "<+$offset(WIND_TCB,sp) @>"

#
# register names list. Registers are considered as consecutive if not then we
# add register names called "_" that are skipped by mRegs
#

set regNList {%pc %npc %psr %mask %tbr %y %g0 %g1 %g2 %g3 %g4 %g5 %g6 \
              %g7 %o0 %o1 %o2 %o3 %o4 %o5 %o6 %o7 %l0 %l1 %l2 %l3 %l4 %l5 \
              %l6 %l7 %i0 %i1 %i2 %i3 %i4 %i5 %i6 %i7}

#############################################################################
#
# regSetOfContext - get the system context registers
#
# A procedure to get the system context registers, in the same format
# as regSetGopher would return.
#
# SYNOPSIS: regSetOfContext [ctype cid]
#
# PARAMETERS:
#       ctype: context type
#       cid: context id
#
# RETURNS: N/A
#

proc regSetOfContext {ctype cid} {
    set regBlk [wtxRegsGet $ctype $cid REG_SET_IU 0 [expr 40*4]]
    set rset [memBlockGet -l $regBlk 0 6]
    append rset [memBlockGet -l $regBlk 32 32]
    memBlockDelete $regBlk
    return $rset
}

##############################################################################
# regOffsetFromIndexGet - return register offset from its index in the regset
#
# To write the register we need to know its offset in the regset. Indeed in
# some cases the offset is not always (index * 4) because of padding.
#
# SYNOPSIS:
#       regAddrGet index
#
# PARAMETERS:
#       index: index in the register set of the concerned register
#
# RETURN: the offset of the register 
#
proc regOffsetFromIndexGet {regInd} {
   
    return [expr $regInd * 4 + (($regInd > 5) ? 8 : 0)]
}

##############################################################################
#
# availRegPuts - puts available registers
#
# SYNOPSIS: availRegPuts
#
# RETURNS: N/A
#

proc availRegPuts {} {
    puts stdout "available registers are:"
    puts stdout "  %pc %npc %psr %mask %tbr %y"
    puts stdout "  %g0 %g1 %g2 %g3 %g4 %g5 %g6 %g7"
    puts stdout "  %o0 %o1 %o2 %o3 %o4 %o5 %o6 %o7"
    puts stdout "  %l0 %l1 %l2 %l3 %l4 %l5 %l6 %l7"
    puts stdout "  %i0 %i1 %i2 %i3 %i4 %i5 %i6 %i7"
}

##############################################################################
#
# pcOfRegSet - get pc register
#
# SYNOPSIS: pcOfRegSet [regSet]
#
# PARAMETERS:
#       regSet: set of register values
#
# RETURNS: content of pc
#

proc pcOfRegSet {regSet} {
    return [lindex $regSet 0]
}

##############################################################################
#
# regSetPrint - prints a register set
#
# SYNOPSIS: regSetPrint [regSet]
#
# PARAMETERS:
#       regSet: set of register values
#
# RETURNS: N/A
#

proc regSetPrint {regSet} {
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%pc"   [lindex $regSet 0]  "%npc"  [lindex $regSet 1] \
	"%psr"  [lindex $regSet 2]  "%mask" [lindex $regSet 3]]
    puts stdout [format "%-6s = %8x   %-6s = %8x" \
	"%tbr"  [lindex $regSet 4]  "%y"    [lindex $regSet 5]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%g0"   [lindex $regSet 6]  "%g1"   [lindex $regSet 7] \
	"%g2"   [lindex $regSet 8]  "%g3"   [lindex $regSet 9]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%g4"   [lindex $regSet 10] "%g5"   [lindex $regSet 11] \
	"%g6"   [lindex $regSet 12] "%g7"   [lindex $regSet 13]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%i0"   [lindex $regSet 30] "%i1"   [lindex $regSet 31] \
	"%i2"   [lindex $regSet 32] "%i3"   [lindex $regSet 33]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%i4"   [lindex $regSet 34] "%i5"   [lindex $regSet 35] \
	"%i6"   [lindex $regSet 36] "%i7"   [lindex $regSet 37]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%l0"   [lindex $regSet 22] "%l1"   [lindex $regSet 23] \
	"%l2"   [lindex $regSet 24] "%l3"   [lindex $regSet 25]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%l4"   [lindex $regSet 26] "%l5"   [lindex $regSet 27] \
	"%l6"   [lindex $regSet 28] "%l7"   [lindex $regSet 29]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%o0"   [lindex $regSet 14] "%o1"   [lindex $regSet 15] \
	"%o2"   [lindex $regSet 16] "%o3"   [lindex $regSet 17]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"%o4"   [lindex $regSet 18] "%o5"   [lindex $regSet 19] \
	"%o6"   [lindex $regSet 20] "%o7"   [lindex $regSet 21]]
}

##############################################################################
#
# taskRegSetStruct -
#
# SYNOPSIS: taskRegSetStruct
#
# RETURNS:
#

proc taskRegSetStruct {} {
    return "{\"SPARC Registers\" {{Global {g0 g1 g2 g3 g4 g5 g6 g7}} 
	{In {i0 i1 i2 i3 i4 i5 i6 i7}}
	{Local {l0 l1 l2 l3 l4 l5 l6 l7}}
	{Out {o0 o1 o2 o3 o4 o5 o6 o7}}
	{Other {pc npc psr mask tbr y}}}}"
}

##############################################################################
#
# taskRegSetVec -
#
# SYNOPSIS: taskRegSetVec [taskInfoList]
#
# PARAMETERS:
#       taskInfoList:
#
# RETURNS:
#

proc taskRegSetVec {taskInfoList} {
    set tiLen [llength $taskInfoList]
    set regRawVec [lrange $taskInfoList [expr $tiLen - 38] end]
    return "{ \
                [list [lrange $regRawVec 6 13]] \
                [list [lrange $regRawVec 30 37]] \
                [list [lrange $regRawVec 22 29]] \
                [list [lrange $regRawVec 14 21]] \
                [list [lrange $regRawVec 0 5]] }"
}

#
# Define a gopher that will check the stack for the end of the 0xee sentinel
# area.  This is dependent on the stack sense of the architecture.
#

set stackGrows down

#
# Define the endianness flag that should be used when memory blocks are
# created.  XXX this should be based on data reported from the target 
# server; some architectures are ambi-endian.
#

set endianFlag "-B"

#
# Add a routine that will print exception stack frames.
#

proc excInfoShow {vector esf} {
    set esfInfo [wtxGopherEval "$esf @@@@@@@@"]
    bindNamesToList {valid pc npc ps sig code addr ptcb} $esfInfo

    if {!$valid} return

    case [expr $sig] {
	# IV_BUS
	10		{set excMsg "Bus Error"}
	# IV_SEGV
	11		{set excMsg "Segmentation Violation"}
	# IV_FPE
	8 {		
	    # TRAP_0_DIVIDE
	    if {$code == 2} {
		set excMsg "Divide by zero"
	    } {
		set excMsg "Floating point exception"
	    }
	}
	# IV_ILL
	4		{set excMsg "Illegal instruction"}
	*		{set excMsg "Unknown Exception: $sig, code $code"}
    }

    puts stdout "\n$excMsg"
    puts stdout [format "program counter:            0x%08x" $pc]
    puts stdout [format "next program counter:       0x%08x" $npc]
    puts stdout [format "processor status:           0x%08x" $ps]

    # IV_BUS || IV_SEGV
    if {$sig == 10 || $sig == 11} {
	puts stdout [format "access address:             0x%08x" $addr]
    }
}

##############################################################################
#
# mangledSymListGet - get a list of the mangled symbols
#
# This procedure fetches the list of the overloaded function or method names.
#
# SYNOPSIS: mangledSymListGet
#
# PARAMETERS:
#    name: root name of symbol
#
# RETURNS: a list of mangled names or an empty list if none.
#

proc mangledSymListGet {name} {
    return [wtxSymListGet -name "^_${name}__.*"]
}

##############################################################################
#
# underscoreStrip - strip off the symbol's leading underscore
#
# This procedure removes the leading underscore in symbol names. This is
# required by some C++ demangler.
#
# SYNOPSIS: underscoreStrip symbol
#
# PARAMETERS:
#    symbol: name of symbol
#
# RETURNS: the symbol without its leading underscore.
#

proc underscoreStrip {symbol} {

    if {[string index $symbol 0] == "_"} {
	return [string range $symbol 1 end]
    } else {
	return $symbol
    }
}
