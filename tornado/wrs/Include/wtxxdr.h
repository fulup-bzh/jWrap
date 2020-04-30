/* wtxxdr.h - wtx xdr header file */

/* Copyright 1984-1995 Wind River Systems, Inc. */

/*
modification history
--------------------
01r,30sep96,elp  put in share/src/wtx (SPR# 6775).
01q,02feb96,elp  added declaration of xdr_TGT_ADDR_T().
01p,01jun95,p_m  removed xdr_WTX_MSG_CALL_PARAM.
01o,30may95,pad  don't include rpc/rpc.h for PARISC_HPUX9.
01n,30may95,p_m  completed WTX_MEM_SCAN and WTX_MEM_MOVE implementation.
01m,23may95,p_m  made missing name changes.
01l,22may95,jcf  name revision.
01k,16may95,p_m  added xdr_WTX_MSG_KILL_DESC().
01j,09may95,p_m  re-implemented wtxregd related XDR procedures.
		 removed unneeded prototypes.
01i,04may95,s_w  change include of rpc/rpc.h to wtxrpc.h
01h,24mar95,p_m  added xdr_WTX_MSG_MEM_BLOCK_DESC.
01g,16mar95,p_m  added xdr_WTX_MSG_VIO_FILE_LIST.
01f,03mar95,p_m  added xdr_WTX_MSG_GOPHER_TAPE.
01e,27feb95,p_m  added xdr_WTX_MSG_MEM_SCAN_DESC.
01d,25feb95,jcf  added xdr_WTX_MSG_TS_[UN]LOCK.
01c,15feb95,p_m  changed names to xdr_WTX_MSG and added xdr routines
		 to suppress coupling with WDB xdr routines.
		 added #include <rpc/rpc.h>.
01b,31jan95,p_m  added xdr_WTX_MEM_XFER(), xdr_WTX_REG_WRITE() and
		 xdr_WTX_MEM_SET_DESC().
01a,15jan95,p_m  written.
*/

#ifndef __INCwtxxdrh
#define __INCwtxxdrh	1

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PARISC_HPUX9
#include <rpc/rpc.h>
#endif

/* function declarations */

extern bool_t xdr_TGT_ADDR_T ();
extern bool_t xdr_WTX_MSG_TOOL_ID();
extern bool_t xdr_WTX_MSG_TOOL_DESC();
extern bool_t xdr_WTX_MSG_RESULT();
extern bool_t xdr_WTX_MSG_PARAM();

extern bool_t xdr_WTX_MSG_TS_INFO();
extern bool_t xdr_WTX_MSG_TS_LOCK();
extern bool_t xdr_WTX_MSG_TS_UNLOCK();

extern bool_t xdr_WTX_MSG_EVTPT_LIST();

extern bool_t xdr_WTX_MSG_SYM_TBL_INFO();
extern bool_t xdr_WTX_MSG_SYMBOL_DESC();
extern bool_t xdr_WTX_MSG_SYM_LIST();
extern bool_t xdr_WTX_MSG_SYM_MATCH_DESC();

extern bool_t xdr_WTX_MSG_VIO_CTL_DESC();
extern bool_t xdr_WTX_MSG_OPEN_DESC();
extern bool_t xdr_WTX_MSG_VIO_COPY_DESC();
extern bool_t xdr_WTX_MSG_VIO_FILE_LIST();

extern bool_t xdr_WTX_MSG_LD_M_FILE_DESC();
extern bool_t xdr_WTX_MSG_MODULE_LIST();
extern bool_t xdr_WTX_MSG_MODULE_INFO();
extern bool_t xdr_WTX_MSG_MOD_NAME_OR_ID();

extern bool_t xdr_WTX_MSG_CONTEXT_DESC();
extern bool_t xdr_WTX_MSG_CONTEXT();
extern bool_t xdr_WTX_MSG_CONTEXT_STEP_DESC();

extern bool_t xdr_WTX_MSG_EVENT_DESC();
extern bool_t xdr_WTX_MSG_EVENT_REG_DESC();

extern bool_t xdr_WTX_MSG_EVTPT_DESC();

extern bool_t xdr_WTX_MSG_KILL_DESC();

extern bool_t xdr_WTX_MSG_SERVICE_DESC();

extern bool_t xdr_WTX_MSG_CONSOLE_DESC();

extern bool_t xdr_WTX_MSG_MEM_INFO();
extern bool_t xdr_MEM_COPY_ALLOC();
extern bool_t xdr_WTX_MSG_MEM_XFER_DESC();
extern bool_t xdr_WTX_MSG_MEM_SCAN_DESC();
extern bool_t xdr_WTX_MSG_MEM_MOVE_DESC();
extern bool_t xdr_WTX_MSG_MEM_SET_DESC();
extern bool_t xdr_WTX_MSG_MEM_READ_DESC();
extern bool_t xdr_WTX_MSG_MEM_COPY_DESC();
extern bool_t xdr_WTX_MSG_MEM_BLOCK_DESC();

extern bool_t xdr_WTX_MSG_REG_WRITE();
extern bool_t xdr_WTX_MSG_REG_READ();

extern bool_t xdr_WTX_MSG_GOPHER_TAPE();

extern bool_t xdr_WTX_CORE ();

extern bool_t xdr_WTX_MSG_SVR_DESC ();
extern bool_t xdr_WTX_MSG_SVR_DESC_Q ();
extern bool_t xdr_WTX_MSG_WTXREGD_PATTERN ();

#ifdef __cplusplus
}
#endif

#endif /* __INCwtxxdrh */
