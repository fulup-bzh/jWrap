# sh-simhp.tcl - simhppa-specific constants for host shell Tcl implementation
#
# Copyright 1996 Wind River Systems, Inc.
#
# modification history
# -----------------------
# 01h,01jul98,c_s  WindView 2 -> Tornado 2 Merge
# 01g,06may98,nps  inserted new rBuff field.
# 01f,02apr98,yh   add RBUFF and TRIG offsets
# 01e,31oct97,jmb  Fix register display in browser (SPR 9452).
# 01d,12jun97,jmb  Removed leading underscore in symbol pattern in
#                  mangledSymListGet and made underscoreStrip simply
#                  return input symbol.
# 01h,17apr98,rlp  removed numMaxMsgsSent for backward compatibility.
# 01g,18mar98,jmb  Fix register display in browser (SPR 9452).
#                  HPSIM merge of jmb patch from 31oct97.
# 01f,18mar98,jmb  Removed leading underscore in symbol pattern in
#                  mangledSymListGet and made underscoreStrip simply return
#                  input symbol.  HPSIM merge of jmb patch from 12jun97.
# 01e,05nov97,rlp  added numMaxMsgsSent for tracking messages sent.
# 01d,29oct96,pad  Added routine underscoreStrip (SPR #7159) and
#                  mangledSymListGet.
# 01f,21nov96,mem  Fixed register offsets for browser.
# 01e,25oct96,mem  added mRegs support, removed sig_regs field.
# 01d,17oct96,mem  cleanup. Removed availRegPuts, mRegs is not supported.
#		   removed now obsolete endianFlag.
# 01c,26sep96,mem  added source of dbgSimhpLib.tcl, fixed copyright.
# 01b,13aug96,jmb  add a patch from Fulup for SPR #6409
# 01a,02jan96,kab  written; derived from sh-simsp.tcl
#

# DESCRIPTION
# 
# This modules holds architecture dependant routines and globals
# 
# RESOURCE FILES
# wpwr/host/resource/tcl/dbgSimhpLib.tcl

source "[wtxPath host resource tcl]dbgSimhpLib.tcl"

# globals

set offset(WIND_TCB,timeout)            0x018
set offset(WIND_TCB,activeNode)         0x020
set offset(WIND_TCB,objCore)            0x030
set offset(WIND_TCB,name)               0x034
set offset(WIND_TCB,options)            0x038
set offset(WIND_TCB,status)             0x03c
set offset(WIND_TCB,priority)           0x040
set offset(WIND_TCB,priNormal)          0x044
set offset(WIND_TCB,safeCnt)		0x060
set offset(WIND_TCB,entry)              0x074
set offset(WIND_TCB,pStackBase)         0x078
set offset(WIND_TCB,pStackLimit)        0x07c
set offset(WIND_TCB,pStackEnd)          0x080
set offset(WIND_TCB,errorStatus)        0x084
set offset(WIND_TCB,regs)               0x278
set offset(WIND_TCB,pc)                 0x280
set offset(WIND_TCB,sp)                 0x308

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

#added for Windview 
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



set offset(SYMBOL,name)			0x004

set offset(WDOG,timeout)                0x00c
set offset(WDOG,status)                 0x014
set offset(WDOG,routine)                0x018
set offset(WDOG,parameter)              0x01c

set offset(MSG_NODE,msgLength)		0x004
set offset(MSG_NODE,message)		0x008

set offset(Q_JOB_HEAD,pendQ)		0x010

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

#
# Define a gopher that will fetch the CPU registers from the TCB of a 
# given task.  The gopher pointer should point to the TCB upon evaluation
# of this string.
set regSetGopher "<+$offset(WIND_TCB,regs) (62 @)>"

# gophers that will get the PC value and the SP value

set pcGetGopher "<+$offset(WIND_TCB,pc) @>"
set spGetGopher "<+$offset(WIND_TCB,sp) @>"

# register names list. Registers are considered as consecutive if not then we
# add register names called "-" that are skipped by mRegs
#
set regNList {
    -		mask	pc	npc	-	-	-
    r1		r2|rp	r3|fp	r4	r5	r6	r7
    r8		r9	r10	r11	r12	r13	r14
    r15		r16	r17	r18	r19	r20	r21
    r22		
    r23|arg3	r24|arg2	r25|arg1	r26|arg0
    r27|dp	r28|ret0	r29|ret1	r30|sp
    r31
    -		-	-	-	-	-	-	-
    cr11|sar	-	-	-	-	-	-	ccr
    cr0		cr8	cr9	cr12	cr13	cr24	cr25	cr26
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
    puts stdout "  mask pc npc pcsqh pcsqt"
    puts stdout "  r1  r2|rp  r3|fp  r4  r5  r6  r7"
    puts stdout "  r8  r9  r10 r11 r12 r13 r14 r15"
    puts stdout "  r16 r17 r18 r19 r20 r21 r22 r23|arg3"
    puts stdout "  r24|arg2 r25|arg1 r26|arg0 r27|dp"
    puts stdout "  r28|ret0 r29|ret1 r30|sp r31"
    puts stdout "  sr0 sr1 sr2 sr3 sr4 sr5 sr6 sr7"
    puts stdout "  cr11|sar eiem iir isr ior psw goto ccr"
    puts stdout "  cr0 cr8 cr9 cr12 cr13 cr24 cr25 cr26"
    puts stdout "  mpsfu_high mpsfu_low mpsfu_ovflo"
}

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
#	ctype: context type
#	cid: context id
#
# RETURNS: N/A
#

proc regSetOfContext {ctype cid} {
    set regBlk [wtxRegsGet $ctype $cid REG_SET_IU 0 [expr 66 * 4]]
    set rset [memBlockGet -l $regBlk 0 65]
    memBlockDelete $regBlk
    return $rset
}

##############################################################################
#
# regOffsetFromIndexGet - return register offset from its index in the regset
#
# SYNOPSIS:
#	regAddrGet index
#
# PARAMETERS:
#	index: index in the register set of the concerned register
#
# RETURN: the offset of the register
#

proc regOffsetFromIndexGet {regInd} {
    return [expr $regInd * 4]
}

##############################################################################
#
# pcOfRegSet - get pc register
#
# SYNOPSIS: pcOfRegSet [regSet]
#
# PARAMETERS:
#	regSet: set of register values
#
# RETURNS: content of pc
#

proc pcOfRegSet {regSet} {
    return [lindex $regSet 2]
}

proc regSetPrint {regSet} {
    puts stdout [format "%-5s = %8x   %-5s = %8x   %-5s = %8x   %-5s = %8x" \
	"%pc"   [lindex $regSet 2]   "%npc"  [lindex $regSet 3] \
	"%sp"   [lindex $regSet 36]  "%fp"   [lindex $regSet 9] ]
    puts stdout [format "%-5s = %8x   %-5s = %8x   %-5s = %8x   %-5s = %8x" \
	"%mask" [lindex $regSet 1]   "%rp"  [lindex $regSet 8] \
	"%dp"	[lindex $regSet 33]  "%sar" [lindex $regSet 46] ]
    puts stdout [format "%-5s = %8x   %-5s = %8x   %-5s = %8x   %-5s = %8x" \
	"%psw"   [lindex $regSet 51 ] "%ccr" [lindex $regSet 53] \
	"%cr0"   [lindex $regSet 54 ] "%cr8" [lindex $regSet 55] ]
    for {set i 0} {$i < 8} {incr i} {
	puts -nonewline stdout \
		[format "%-5s = %8x   " "%sr$i" [lindex $regSet [expr $i + 38]]]
	if {[expr $i % 4] == 3} {
	    puts stdout ""
	}
    }
    for {set i 0} {$i < 32} {incr i} {
	puts -nonewline stdout \
		[format "%-5s = %8x   " "%r$i" [lindex $regSet [expr $i + 6]]]
	if {[expr $i % 4] == 3} {
	    puts stdout ""
	}
    }
}

# See also CrossWind*.tcl, Browser.tcl
proc taskRegSetStruct {} {
    return "{\"PA-RISC Registers\" \
	{{Control { mask pc npc pcsqh pcsqt eiem sar iir isr ior psw \
	_goto ccr cr0 cr8 cr9 cr12 cr13 cr24 cr25 cr26 }} \
	{General { r1 r2|rp r3|fp r4 r5 r6 r7 r8 r9 r10 r11 r12 r13 r14 r15 r16 \
	r17 r18 r19 r20 r21 r22 r23 r24 r25 r26 r27|dp r28 r29 r30|sp r31 }} \
	{Space { sr0 sr1 sr2 sr3 sr4 sr5 sr6 sr7 }}}}"
}

proc taskRegSetVec {taskInfoList} {
    set tiLen [llength $taskInfoList]
    set regRawVec [lrange $taskInfoList [expr $tiLen - 62] end]
    return "{ \
	    [list [concat [lrange $regRawVec  1 5] \
	                  [lrange $regRawVec 45 end]]] \
	    [list [lrange $regRawVec  7 37]] \
	    [list [lrange $regRawVec 38 45]] }"
}

#
# Define a gopher that will check the stack for the end of the 0xee sentinel
# area.  This is dependent on the stack sense of the architecture.
#

set stackGrows up

#
# Add a routine that will print exception stack frames.
#

proc excInfoShow {vector esf} {
    set esfInfo [wtxGopherEval "$esf @@@@@@@@"]
    bindNamesToList {valid pc npc ps sig code addr ptcb} $esfInfo

    set sig [expr $sig]
    case $sig {
	# IV_BUS
	10 {set excMsg "Bus Error"}
	# IV_SEGV
	11 {set excMsg "Segmentation Violation"}
	# IV_FPE
	8 {		
	    # TRAP_0_DIVIDE
	    if {$code == 2} {
		set excMsg "Divide by zero"
	    } else {
		set excMsg "Floating point exception"
	    }
	}
	# IV_ILL
	4 {set excMsg "Illegal instruction"}
	* {set excMsg "Unknown Exception: $sig, code $code"}
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
   return [wtxSymListGet -name "^${name}__.*"]

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
        return $symbol
}
