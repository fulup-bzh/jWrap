# sh-armcore.tcl - ARM and Thumb -specific constants for host shell Tcl implementation 
#
# Copyright 1996-1997 Wind River Systems, Inc. 
#
# modification history
# -----------------------
# 01c,03sep98,cjtc include globals for WV20 Instrumentation
# 01b,05jun98,f_l  added offsets for taskWait routines
# 01a,28aug96,cdp  created from 01c of sh-arm.tcl.
#

# DESCRIPTION
# 
# This modules holds architecture dependant routines and globals
# 

# globals

set offset(WIND_TCB,timeout)		0x018
set offset(WIND_TCB,activeNode) 	0x020
set offset(WIND_TCB,objCore)		0x030
set offset(WIND_TCB,name)		0x034
set offset(WIND_TCB,options)		0x038
set offset(WIND_TCB,status)		0x03c
set offset(WIND_TCB,priority)		0x040
set offset(WIND_TCB,priNormal)		0x044
set offset(WIND_TCB,pPendQ)		0x05c
set offset(WIND_TCB,safeCnt)		0x060
set offset(WIND_TCB,entry)		0x074
set offset(WIND_TCB,pStackBase)		0x078
set offset(WIND_TCB,pStackLimit)	0x07c
set offset(WIND_TCB,pStackEnd)		0x080
set offset(WIND_TCB,errorStatus)	0x084
set offset(WIND_TCB,regs)		0x128
set offset(WIND_TCB,sp)			0x15C
set offset(WIND_TCB,pc)			0x164

set offset(OBJ_CLASS,objPartId)		0x004

set offset(SEMAPHORE,semType)		0x004
set offset(SEMAPHORE,options)		0x005
set offset(SEMAPHORE,qHead)		0x008
set offset(SEMAPHORE,count)		0x018

set offset(MSG_Q,msgQ)			0x004
set offset(MSG_Q,freeQ)			0x024
set offset(MSG_Q,options)		0x044
set offset(MSG_Q,maxMsgs)		0x048
set offset(MSG_Q,maxMsgLength)		0x04c
set offset(MSG_Q,sendTimeouts)		0x050
set offset(MSG_Q,recvTimeouts)		0x054

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

set offset(PARTITION,totalWords)        0x028
set offset(PARTITION,curBlocksAllocated) 0x034
set offset(PARTITION,curWordsAllocated) 0x038
set offset(PARTITION,cumBlocksAllocated) 0x03c
set offset(PARTITION,cumWordsAllocated) 0x040
set offset(PARTITION,freeList)          0x004
set offset(FREE_BLOCK,node)             0x008
set offset(FREE_BLOCK,hdr.nWords)       0x004

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
    <+$offset(WIND_TCB,regs) @@@@@@@@ @@@@@@@ @ @ >"
#                            r0-r7    r8-r14  PC CPSR

# Define the register names list

set regNList {r0 r1 r2 r3 r4 r5 r6 r7 \
	      r8 r9 r10 r11|fp r12|ip r13|sp r14|lr pc cpsr}

# gophers that will get the PC value and the SP value

set pcGetGopher "<+$offset(WIND_TCB,pc) @>"
set spGetGopher "<+$offset(WIND_TCB,sp) @>"

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
#       ctype: context typE
#       cid: context id
#
# RETURNS: N/A
#

proc regSetOfContext {ctype cid} {
    set regBlk [wtxRegsGet $ctype $cid REG_SET_IU 0 [expr 17*4]]
    set rset [memBlockGet -l $regBlk 0 17]
    memBlockDelete $regBlk
    return $rset
}

##############################################################################
#
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

       return [expr $regInd * 4]
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
    puts stdout "  r0 r1 r2 r3 r4 r5 r6 r7"
    puts stdout "  r8 r9 r10 r11|fp r12|ip r13|sp r14|lr pc"
    puts stdout "  cpsr"
}

##############################################################################
# pcOfRegSet - get pc register
#
# SYNOPSIS: pcOfRegSet [regSet]
#
# PARAMETERS:
#       regSet: set of register values
#
# RETURNS: content of pc

proc pcOfRegSet {regSet} {
    return [lindex $regSet 15]
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
	"r0"     [lindex $regSet 0] \
	"r1"     [lindex $regSet 1] \
	"r2"     [lindex $regSet 2] \
	"r3"     [lindex $regSet 3]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"r4"     [lindex $regSet 4] \
	"r5"     [lindex $regSet 5] \
	"r6"     [lindex $regSet 6] \
	"r7"     [lindex $regSet 7]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"r8"     [lindex $regSet 8] \
	"r9"     [lindex $regSet 9] \
	"r10"    [lindex $regSet 10] \
	"r11/fp" [lindex $regSet 11]]
    puts stdout [format "%-6s = %8x   %-6s = %8x   %-6s = %8x   %-6s = %8x" \
	"r12/ip" [lindex $regSet 12] \
	"r13/sp" [lindex $regSet 13] \
	"r14/lr" [lindex $regSet 14] \
	"r15/pc" [lindex $regSet 15]]
    puts stdout [format "%-6s = %8x" \
	"cpsr" [lindex $regSet 16]]
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
    return "{\"ARM Registers\"
	{{General {r0 r1 r2 r3 r4 r5 r6 r7 r8 r9 r10 r11 r12 r13 r14}}
         {Other {pc cpsr}}}}"
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
    set regRawVec [lrange $taskInfoList [expr $tiLen - 17] end]
    return "{ \
	    [list [lrange $regRawVec 0 14]] \
	    [list [lrange $regRawVec 15 16]] \
	    }"
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

set endianFlag "-L"


##############################################################################
#
# excInfoShow - show exception info
#

proc excInfoShow {vec pEsf} {
    global armExcName
    global __wtxCpuType
    global cpuType

    set cpu $cpuType($__wtxCpuType)
    
    # get important parts of ESF info via gopher

    set pcAddr	[expr $pEsf + 0]
    set cpsrAddr [expr $pEsf + 4]
    set vecAddr	[expr $pEsf + 8]

    set excInfo [wtxGopherEval "$pcAddr @ $cpsrAddr @ $vecAddr @"]
    bindNamesToList {pc cpsr vec} $excInfo

    # get the name of the exception

    set vec [format "%#x" $vec]
    switch [expr $vec] {
	# EXC_OFF_RESET
	0		{set excMsg "Branch through zero"}
	# EXC_OFF_UNDEF
	4		{set excMsg "Undefined instruction"}
	# EXC_OFF_SWI
	8		{set excMsg "Software interrupt"}
	# EXC_OFF_PREFETCH
	12		{set excMsg "Instruction prefetch abort"}
	# EXC_OFF_DATA
	16		{set excMsg "Data abort"}
	# ???
	default		{set excMsg "Unknown exception: $vec"}
    }


    # print out exception information

    puts stdout "\n$excMsg"
    puts stdout [format "Program Counter:   %#x" $pc]
    puts stdout [format "Status Register:   %#x" $cpsr]
}

###############################################################################
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
