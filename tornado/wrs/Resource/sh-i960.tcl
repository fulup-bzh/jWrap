# sh-i960.tcl - i960-specific material for host shell Tcl implementation
#
# Copyright 1995-1996 Wind River Systems, Inc. 
#
# modification history
# -----------------------
# 01q,01jul98,c_s  WindView 2 -> Tornado 2 Merge
# 01p,15may98,cjtc reversed last change. Not required for this architecture
#                  (see comments)
# 01o,06may98,nps  inserted new rBuff field.
# 01n,02apr98,cjtc added rbuf and evt triggering offsets
# 01p,05jun98,f_l  added offsets for taskWait routines
# 01o,17apr98,rlp  removed numMaxMsgsSent for backward compatibility.
# 01n,05nov97,rlp  added numMaxMsgsSent for tracking messages sent.
# 01m,29oct96,pad  Added routine underscoreStrip (SPR #7159).
# 01l,30sep96,pad  Added mangledSymListGet procedure.
# 01k,29apr96,p_m  added pcGetGopher and spGetGopher to fix SPR#6409.
# 01j,26apr96,c_s  changed regSetGopher to seek local registers in task stack.
# 01i,06mar96,elp  changed trcI960Lib.tcl to dbgI960Lib.tcl.
# 01h,29jan96,elp  added availRegPuts{}, regOffsetFromIndexGet{},
#		   some proc headers, source trcI960Lib.tcl. 
# 01g,20dec95,c_s  fixed offset (MSG_Q, options).
# 01f,15nov95,c_s  added regSetOfContext.
# 01e,09nov95,s_w  added offset(WIND_TCB,safeCnt) to fix SPR 5090
# 01d,08nov95,elp  added regNList (register Name List) for mRegs.
# 01c,19sep95,pad  added offset information for Shared Memory Objects.
# 01b,12sep95,pad  added offset information for POSIX semaphores and msg queues.
# 01a,08jun95,c_s  written.
#

# DESCRIPTION
#
# This modules holds architecture dependant routines and globals
#
# RESOURCE FILES
# wpwr/host/resource/tcl/dbgI960Lib.tcl
#

source "[wtxPath host resource tcl]dbgI960Lib.tcl"

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
set offset(WIND_TCB,regs)		0x140
set offset(WIND_TCB,pc)			0x148
set offset(WIND_TCB,sp)			0x144
set offset(WIND_TCB,fp)			0x1bc
set offset(WIND_TCB,g0)			0x180

set offset(OBJ_CLASS,objPartId)		0x004

set offset(SEMAPHORE,semType)		0x004
set offset(SEMAPHORE,options)		0x005
set offset(SEMAPHORE,qHead)		0x008
set offset(SEMAPHORE,count)		0x018

set offset(POSIX_SEM,semId)             0x004
set offset(POSIX_SEM,refCnt)            0x008
set offset(POSIX_SEM,sem_name)          0x00c

set offset(MSG_Q,msgQ)			0x010
set offset(MSG_Q,freeQ)			0x030
set offset(MSG_Q,options)		0x050
set offset(MSG_Q,maxMsgs)		0x054
set offset(MSG_Q,maxMsgLength)		0x058
set offset(MSG_Q,sendTimeouts)		0x05c
set offset(MSG_Q,recvTimeouts)		0x060

set offset(POSIX_MSG_Q_DES,f_flags)     0x004
set offset(POSIX_MSG_Q_DES,f_data)      0x008

set offset(POSIX_MSG_Q,msgq_cond_read)  0x000
set offset(POSIX_MSG_Q,msgq_cond_data)  0x010
set offset(POSIX_MSG_Q,msgq_sym)        0x020
set offset(POSIX_MSG_Q,msgq_attr)       0x100

set offset(POSIX_MSG_Q_ATTR,mq_maxmsg)  0x000
set offset(POSIX_MSG_Q_ATTR,mq_msgsize) 0x004
set offset(POSIX_MSG_Q_ATTR,mq_flags)   0x008
set offset(POSIX_MSG_Q_ATTR,mq_curmsgs) 0x00c

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

set offset(SYMBOL,name)                 0x004

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

set offset(PARTITION,totalWords)        0x02c
set offset(PARTITION,curBlocksAllocated) 0x038
set offset(PARTITION,curWordsAllocated) 0x03c
set offset(PARTITION,cumBlocksAllocated) 0x040
set offset(PARTITION,cumWordsAllocated) 0x044
set offset(PARTITION,freeList)          0x008

set offset(FREE_BLOCK,node)             0x010
set offset(FREE_BLOCK,hdr.nWords)       0x004

#
# Be aware that the i960 inserts lots of padding bytes between sub-structures
# in a nested structure. Each sub-structure will start on a 16-byte boundary.
# If extra words are inserted in any sub-structure, following offsets may not
# be incremented (padding bytes will have been used)
#

set offset(RBUFF_TYPE,objCore)          0x000

# start of sub-structure - will be 16-byte aligned

set offset(RBUFF_TYPE,buffRead)         0x040
set offset(RBUFF_TYPE,buffWrite)        0x044
set offset(RBUFF_TYPE,dataRead)         0x048
set offset(RBUFF_TYPE,dataWrite)        0x04c

# start of sub-structure - will be 16-byte aligned

set offset(RBUFF_TYPE,srcPart)          0x0a0
set offset(RBUFF_TYPE,options)          0x0a4
set offset(RBUFF_TYPE,buffSize)         0x0a8
set offset(RBUFF_TYPE,currBuffs)        0x0ac
set offset(RBUFF_TYPE,threshold)        0x0b0
set offset(RBUFF_TYPE,minBuffs)         0x0b4
set offset(RBUFF_TYPE,maxBuffs)         0x0b8
set offset(RBUFF_TYPE,maxBuffsActual)   0x0bc
set offset(RBUFF_TYPE,emptyBuffs)       0x0c0
set offset(RBUFF_TYPE,dataContent)      0x0c4
set offset(RBUFF_TYPE,writesSinceReset) 0x0c8
set offset(RBUFF_TYPE,readsSinceReset)  0x0cc
set offset(RBUFF_TYPE,timesExtended)    0x0d0
set offset(RBUFF_TYPE,timesXThreshold)  0x0d4
set offset(RBUFF_TYPE,bytesWritten)     0x0d8
set offset(RBUFF_TYPE,bytesRead)        0x0dc
set offset(RBUFF_TYPE,bytesPeak)        0x0e0

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
# Since local variables are stored on the stack, not the TCB, first
# we dereference the fp register and get the 16 local variabls (r0..r15).
# Then we return to the TCB for the global variables (g0..g15) and finally
# pick up the control words (pcw, acw, tcw).
#

set regSetGopher "
     < <+$offset(WIND_TCB,fp) * @@@@@@@@@@@@@@@@>
       <+$offset(WIND_TCB,g0) @@@@@@@@@@@@@@@@ @@@ >
     >"

# register names list

set regNList {r0|pfp r1|sp r2|rip r3 r4 r5 r6 r7 r8 r9 r10 r11 r12 r13 r14 \
	      r15 g0 g1 g2 g3 g4 g5 g6 g7 g8 g9 g10 g11 g12 g13 g14 fp pcw \
	      acw tcw}

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
# RETURNS: the register set as a list
#

proc regSetOfContext {ctype cid} {
    set regBlk [wtxRegsGet $ctype $cid REG_SET_IU 0 [expr 35*4]]
    set rset [memBlockGet -l $regBlk 0 35]
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
    puts stdout "  r0|pfp r1|sp r2|rip r3 r4 r5 r6 r7 r8 r9 r10 r11 r12 r13\
    		   r14 r15"
    puts stdout "  g0 g1 g2 g3 g4 g5 g6 g7 g8 g9 g10 g11 g12 g13 g14"
    puts stdout "  pcw acw tcw"
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
    return [lindex $regSet 2]
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
    set regNames "
	r0/pfp r1/sp r2/rip r3 r4 r5 r6 r7
	r8 r9 r10 r11 r12 r13 r14 r15
	g0 g1 g2 g3 g4 g5 g6 g7 
	g8 g9 g10 g11 g12 g13 g14 g15/fp
	pcw acw tcw"

    set ix 0
    foreach regVal $regSet {
	puts -nonewline stdout \
		[format "%-6s = %8x" [lindex $regNames $ix] $regVal]
	incr ix
	if {$ix % 4} {
	    puts -nonewline stdout "   "
	} {
	    puts stdout ""
	}
    }
    puts stdout ""
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
    return "{\"i960 Registers\" {{Local {pfp sp rip r3 r4 r5 r6 r7 r8 r9 r10 r11 r12 r13 r14 r15}} {Global {g0 g1 g2 g3 g4 g5 g6 g7 g8 g9 g10 g11 g12 g13 g14 fp}} {Control {pcw acw tcw}}}}"
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
    set regRawVec [lrange $taskInfoList [expr $tiLen - 35] end]
    return "{ \
	    [list [lrange $regRawVec 0 15]] \
	    [list [lrange $regRawVec 16 31]] \
	    [list [lrange $regRawVec 32 34]]}"
}

#
# Define a gopher that will check the stack for the end of the 0xee sentinel
# area.  This is dependent on the stack sense of the architecture.
#

set stackGrows up

#
# Define the endianness flag that should be used when memory blocks are
# created.  XXX this should be based on data reported from the target 
# server; some architectures are ambi-endian.
#

set endianFlag "-L"

#
# The table of exception names.  These are indexed by exception number.
#

set i960ExcName {
    "Parallel Fault"
    "Trace Fault"
    "Operation Fault"
    "Arithmetic Fault"
    "Floating-Point Fault"
    "Constraint Fault"
    "NULL 1"
    "Protection Fault"
    "NULL 2"
    "NULL 3"
    "Type Fault"
}

# gophers that will get the PC value and the SP value
# On the i960 the local registers are stored in the stack, not in the TCB

set pcGetGopher "<+$offset(WIND_TCB,fp) * <+8 @>>"
set spGetGopher "<+$offset(WIND_TCB,fp) * <+4 @>>"

proc excInfoShow {vec esf} {
    global i960ExcName

    # A gopher for unpacking an i960 fault record (see excI960Lib.h,
    # structure FAULT_RECORD_80960).
    #
    # Format: pcw acw subtype type ip

    set frecGopher "+32 @@ @b +1 @b +1 @"

    # A gopher for unpacking an i960 interrupt record (see excI960Lib.h,
    # structure IREC).
    #
    # Format: pcw acw vect

    set irecGopher "@@@"

    # Get exception name 

    set excName [lindex $i960ExcName $vec]

    if {$excName == ""} {
	set excName "Trap to vector number $vec"

	set irec [wtxGopherEval "$esf $irecGopher"]
	bindNamesToList {pcw acw vect} $irec

	puts stdout "\n$excName"
	puts stdout [format "pcw       : %#x" $pcw]
	puts stdout [format "acw       : %#x" $acw]
    } {
	set frec [wtxGopherEval "$esf $frecGopher"]

	bindNamesToList {pcw acw subtype type ip} $frec

	puts stdout "\n$excName"
	puts stdout [format "fault type: %#x" $type]
	puts stdout [format "subtype   : %#x" $subtype]
	puts stdout [format "ip        : %#x" $ip]
	puts stdout [format "pcw       : %#x" $pcw]
	puts stdout [format "acw       : %#x" $acw]
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

