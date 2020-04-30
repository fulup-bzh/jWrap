/* wtxrpc.h - wtx rpc header file */

/* Copyright 1984-1995 Wind River Systems, Inc. */

/*
modification history
--------------------
01g,30sep96,elp  put in share/src/wtx (SPR# 6775).
01f,30may95,c_s  added ipAddr to WTX_RPC_SPLIT_KEY.
01e,17may95,s_w  update functions to form RPC implementation of exchange
		 protocol. Key management functions unchanged.
01d,05may95,p_m  changed WTX_RPC_PROG to differentiate Beta from SDK release.
01c,04may95,s_w  changes to make this the central include file for RPC based
		 implementation files. Moved in defines of WTX_SVC_BASE,
                 WTX_FIRST_ADDL_PROC_NUM, typedef of WTX_ID. Added include of
		 <rpc/rpc.h>.
01b,26jan95,p_m  added UNIX style authentication.
01a,15jan95,p_m  written.
*/

#ifndef __INCwtxrpch
#define __INCwtxrpch	1

#ifdef __cplusplus
extern "C" {
#endif

#include "wtxexch.h"
// Fulup avoid a WARNING from rpc.h FALSE refenition
#undef FALSE
#undef TRUE
#include <rpc/rpc.h>

/* defines */

#define	WTX_RPC_PROG	0x55555551	/* WTX RPC program number */
#define	WTX_RPC_VERSION	1		/* WTX RPC version number */

#define WTX_SVC_BASE		0x22000000	/* base service number */

/*
 * Valid service numbers range between 0 and 500. Standard service have numbers
 * 0 to 300. Additionnal services have numbers 301 to 500.
 */
#define WTX_FIRST_ADDL_PROC_NUM	301

/* typedefs */

typedef struct		/* WTX_RPC_SPLIT_KEY */
    {
    int		progNum;			/* rpc program number */
    int		version;			/* rpc version number */
    int		protocol;			/* rpc protocol type */
    char	host [32];			/* host where service resides */
    char	ipAddr [32];			/* IP addr in a.b.c.d form */
    } WTX_RPC_SPLIT_KEY;

/* function declarations */

#if defined(__STDC__) || defined(__cplusplus)

/* Basic exchange functions */
extern STATUS	wtxRpcExchangeCreate (WTX_XID xid, const char * key);
extern STATUS	wtxRpcExchangeDelete (WTX_XID xid);
extern STATUS	wtxRpcExchange (WTX_XID xid, WTX_REQUEST reqId, 
				void * pIn, void * pOut);
extern STATUS	wtxRpcExchangeFree (WTX_XID xid, WTX_REQUEST reqId, 
				    void * pMsg);
extern STATUS	wtxRpcExchangeControl (WTX_XID xid, UINT32 request, void * arg);

/* RPC key utilities exported for convenience */
extern STATUS 	wtxRpcKeySplit (const char * rpcKey, 
				WTX_RPC_SPLIT_KEY *pSplitKey);
extern STATUS	wtxRpcSvcUnregister (const char *rpcKey);
extern char *	wtxRpcKey (UINT32 progNum, UINT32 version, UINT32 protocol,
		           void (*dispatch) (struct svc_req *, SVCXPRT *),
		           SVCXPRT ** ppNewXprt);

#else	/* __STDC__ */

extern STATUS	wtxRpcExchangeCreate ();
extern STATUS	wtxRpcExchangeDelete ();
extern STATUS	wtxRpcExchange ();
extern STATUS	wtxRpcExchangeFree ();
extern STATUS	wtxRpcExchangeControl ();

extern STATUS 	wtxRpcKeySplit ();
extern STATUS	wtxRpcSvcUnregister ();
extern char *	wtxRpcKey ();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* __INCwtxrpch */
