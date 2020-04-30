/* wtxrpc.c - tornado rpc transport library */

/* Copyright 1984-1996 Wind River Systems, Inc. */
#include "copyright_wrs.h"

/*
modification history
--------------------
01x,25feb97,elp  added valid machname in authunix_create() call (SPR# 7959).
01w,30sep96,elp  put in share, adapted to be compiled on target side SPR# 6775.
01v,28jun96,c_s  tweaks for AIX.
01u,09dec95,wmd  used authunix_create() call to pass uid explicity for WIN32,
                 to fix SPR# 5609.
01t,27oct95,p_m  fixed SPR# 5196 by using the pid to generate the base
		 RPC program number (Unix only).
01s,26oct95,p_m  added WTX_AGENT_MODE_GET and WTX_DIRECT_CALL.
01r,24oct95,wmd  fixed so that processing delays caused by timeout in call
                 to hostbyname() is eliminated, spr #5084, 
01q,14jun95,s_w	 return WTX_ERR_EXCHANGE_NO_SERVER if client create fails.
01p,08jun95,c_s  added WTX_TARGET_ATTACH to rpc function list.
01o,01jun95,p_m  changed WTX_FUNC_CALL to use xdr_WTX_MSG_CONTEXT_DESC.
01n,30may95,p_m  completed WTX_MEM_SCAN and WTX_MEM_MOVE implementation.
01m,30may95,c_s  portablity tweak: use struct in_addr with inet_ntoa().
01l,30may95,c_s  added dotted-decimal IP address to key
01k,23may95,s_w  don't setup or destroy authentication for WIN32
01j,23may95,p_m  made missing name changes.
01i,22may95,s_w  update RPC server table for new WTX_MSG_OBJ_KILL in args
		 and add WTX_MSG_VIO_CHAN_GET/RELEASE messages.
01h,22may95,jcf  name revision.
01g,19may95,jcf	 changed over to WIND_REGISTRY.
01g,18may95,jcf	 changed over to TORNADO_REGISTRY.
01f,14may95,s_w	 add in exchange functions for use by C API (wtx.c). Tidy
		 up rouintes to use types from host.h and make all routines
		 use status and error codes rather than print error messages.
01e,23feb95,p_m  took care of WIN32 platform.
01d,14feb95,p_m  changed S_wtx_ to WTX_ERR_ .
01c,22jan95,c_s  fixed memory leak.
01b,20jan95.jcf  made more portable.
01a,24dec94,c_s  written.
*/

/* includes */

#ifdef HOST
#include "wtxrpc.h"
#include "private/wtxexchp.h"
#include "wtxmsg.h"
#include "wtxxdr.h"
#include "regex.h"

#if defined(RS6000_AIX4) || defined (RS6000_AIX3)
#undef malloc
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/param.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#else
#include "hostLib.h"
#include "arpa/inet.h"
#include "socket.h"

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include "wtx.h"

#include "wtxrpc.h"
#include "private/wtxexchp.h"
#include "wtxmsg.h"
#include "wtxxdr.h"
#include "regex.h"
#endif /* HOST */

/* typedefs */

typedef struct rpc_service
    {
    xdrproc_t	xdrIn;
    xdrproc_t	xdrOut;
    } RPC_SERVICE;

#ifndef HOST
/* globals */

UINT32			syncRegistry;	/* inet registry address */
struct opaque_auth 	authCred;	/* address of the authentication info */
#endif /* HOST */

/* locals */

LOCAL RPC_SERVICE * (*rpcSvcTable)[] = NULL;
LOCAL UINT32	rpcSvcTableSize = 0;

/* This is the UDP retry timeout used when creating a UDP service connection */
LOCAL struct timeval rpcDefaultUdpTimeout = { 5, 0 };

/* forward declarations */

LOCAL WTX_ERROR_T rpcStatToError (enum clnt_stat rpcStat);
LOCAL STATUS rpcSvcTableInstall (void);
LOCAL STATUS rpcSvcAdd (UINT32 svcNum, void *xdrIn, void *xdrOut);

/******************************************************************************
*
* wtxRpcSvcUnregister - perform svc_unregister using RPC key string
*
* This routine will unregister the specified RPC service with svc_unregister.
* This routine will not destroy the service.
*
* RETURNS: WTX_OK, or WTX_ERROR if invalid key.
*/

STATUS wtxRpcSvcUnregister
    (
    const char *	rpcKey	/* service key for service to unregister */
    )
    {
    WTX_RPC_SPLIT_KEY	splitKey;

    if (wtxRpcKeySplit (rpcKey, &splitKey) != WTX_OK)	/* split the key */
	return (WTX_ERROR);

    svc_unregister (splitKey.progNum, splitKey.version);

    return (WTX_OK);
    }

/******************************************************************************
*
* wtxRpcKey - construct an RPC key string given RPC parameters.
*
* An RPC key string is built from the given progNum, version, and protocol
* code.  The format of the string is
* 
*     rpc/<hostname>/<ip-addr>/<progNum>/<version>|<tcp|udp>
*
* The hostname is found from the OS.
*
* RETURNS:
* The constructed RPC key string, or NULL if the input data does not represent
* a valid RPC server address or memory for the string could not be allocated.
* The storage for the string should be freed with free() when it is no longer
* needed.
*/

char *wtxRpcKey
    (
    UINT32	progNum,		/* rpc prog number, or NULL TBA */
    UINT32	version,		/* rpc version number */
    UINT32	protocol,		/* IPPROTO_TCP or IPPROTO_UDP */
    void	(* dispatch) 		/* rpc dispatch routine */
		(struct svc_req *, SVCXPRT *),
    SVCXPRT **	ppNewXprt		/* where to return transport */
    )
    {
    char *		newKey;			/* final key (malloc'd) */
    char 		ipAddrStr [24];		/* string IP addr (a.b.c.d) */
    UINT32 		rpcProgNum;		/* hunted rpc program num */
    SVCXPRT *		newXprt = NULL;		/* transport we make */
    char 		buf [256];		/* accumulates key string */
    char		hostName [MAXHOSTNAMELEN];	/* our host name */
#ifdef HOST
    struct hostent *	pHostEnt;		/* contains our IP addr */
#else
    struct		in_addr ina;
#endif /* HOST */
    
    /* sanity check progNum >= 0, version > 0, and IPPROTO_TCP or IPPROTO_UDP */

    if (((protocol != IPPROTO_TCP) && (protocol != IPPROTO_UDP)) ||
	((progNum == 0) && (dispatch == NULL)))
	return (NULL);

    if (progNum == 0)					/* hunt for prog num */
	{	
	if (protocol == IPPROTO_TCP)
	    newXprt = svctcp_create (RPC_ANYSOCK, 0, 0);
	else

#if defined (WIN32) || defined (RS6000_AIX4) || !defined(HOST) || defined(LINUX)
	    newXprt = svcudp_create (RPC_ANYSOCK);
#else /* WIN32 */
	    newXprt = svcudp_create (RPC_ANYSOCK, 0, 0);
#endif /* WIN32 */

	if (! newXprt)					/* service kaput! */
	    return (NULL);
	
	/* 
	 * In order to limit the number of times a Target Server can
	 * get the RPC program number of a just killed (with kill -9) 
	 * Target Server we introduce a little bit of random here (SPR# 5196).
	 */

#if defined(WIN32) || !defined(HOST)
	rpcProgNum = WTX_SVC_BASE;
#else /* WIN32 */
	rpcProgNum = WTX_SVC_BASE + ((int) getpid () & 0xff);	
#endif /* WIN32 */

	while (!svc_register (newXprt, ++rpcProgNum, version,dispatch,protocol))
	    if (rpcProgNum >= WTX_SVC_BASE + WTX_MAX_SERVICE_CNT)
	        return (NULL);				/* let's give up */
	
	if (ppNewXprt)					/* return transport? */
	    *ppNewXprt = newXprt;
	
	progNum = rpcProgNum;				/* store prog num */
	}

    /* Key format: "rpc/host/ip/prog/version/{tcp,udp}" */

    gethostname (hostName, sizeof (hostName));		/* where are we? */

#ifdef HOST
    if ((pHostEnt = gethostbyname (hostName)))		/* know our IP addr? */
	{
	struct in_addr ina;
	ina.s_addr = * ((u_long *) pHostEnt->h_addr_list [0]);
	strcpy (ipAddrStr, inet_ntoa (ina));
	}
    else
	strcpy (ipAddrStr, "");
#else 
    ina.s_addr = hostGetByName (hostName);
    strcpy (ipAddrStr, inet_ntoa (ina));
#endif /* HOST */

    sprintf (buf, "rpc/%s/%s/%d/%d/%s", hostName, ipAddrStr, progNum, version,
	     (protocol == IPPROTO_TCP) ? "tcp" : "udp");

    if ((newKey = malloc (strlen (buf) + 1)) == NULL)	/* allocate key */
	return (NULL);

    strcpy (newKey, buf);				/* copy string */

    return (newKey);					/* return key */
    }

/******************************************************************************
*
* wtxRpcKeySplit - split an RPC key string into its component parts
*
* The given RPC key string is decoded and the various fields are placed
* into the WTX_RPC_SPLIT_KEY structure provided (by reference).
*
* RETURNS:
* WTX_OK, if the key was split successfully and pSplitKey is filled, or
* WTX_ERROR if the key could not be decoded.
*/

STATUS wtxRpcKeySplit
    (
    const char *	rpcKey,
    WTX_RPC_SPLIT_KEY *	pSplitKey
    )
    {
    int		   len;
    regmatch_t	   keyPart [6];
    static regex_t keyRegex;
    static int	   keyRegInited = 0;
    char	   keyPat [] = 
	"rpc/(.*)/([0-9A-Fa-f.]*)/([0-9A-Fa-f]*)/([0-9A-Fa-f]*)/(tcp|udp)";
    /*  type/host/    ipaddr     /   prognum    /     vers     /protocol   */    
    if (!keyRegInited)
	{
	if (regcomp (&keyRegex, keyPat, REG_EXTENDED))
	    /* bad regular expression management */
	    return (WTX_ERROR);

	++keyRegInited;
	}

    if (regexec (&keyRegex, rpcKey, NELEMENTS (keyPart), keyPart, 0))
	/* bad regular expression management */
	return (WTX_ERROR);

    /*
     * Should have a check here to make sure all parts of the regexp
     * were matched eg. we got a non-rpc key passed to us!
     */
    pSplitKey->progNum	= strtoul (rpcKey + keyPart [3].rm_so, 0, 0);
    pSplitKey->version	= strtoul (rpcKey + keyPart [4].rm_so, 0, 0);
    pSplitKey->protocol	= (rpcKey [keyPart [5].rm_so] == 't') ? IPPROTO_TCP : 
								IPPROTO_UDP;

    /* copy as much of host name, ip address to split key struct as fits */

    len = min((unsigned)keyPart[2].rm_eo-keyPart[2].rm_so, sizeof(pSplitKey->ipAddr)-1);
    pSplitKey->ipAddr [0] = '\0';
    strncpy (pSplitKey->ipAddr, rpcKey + keyPart [2].rm_so, len);
    pSplitKey->ipAddr [len] = '\0';

    len = min((unsigned)keyPart[1].rm_eo - keyPart[1].rm_so, sizeof(pSplitKey->host)-1);
    strncpy (pSplitKey->host, rpcKey + keyPart [1].rm_so, len);
    pSplitKey->host [len] = '\0';

    return (WTX_OK);
    }



/*******************************************************************************
*
* wtxRpcExchangeCreate - create a new exchange client using the RPC transport
*
* This routine takes a wpwr key string and creates a new exchange client
* 
* RETURNS: WTX_OK, or WTX_ERROR
*
* NOMANUAL
*/

STATUS wtxRpcExchangeCreate
    (
    WTX_XID		xid,		/* Exchange handle */
    const char *	key		/* Key for server to connect to */
    )

    {
    WTX_RPC_SPLIT_KEY	split;			/* split key */
    struct sockaddr_in	addr;			/* socket address */
    int			rpcSock;		/* rpc socket */
    CLIENT *		pClient;		/* rpc client handle */
#ifdef HOST
    struct hostent *	pHostEnt;		/* host entry */
    char *              registryHost;           /* registry host name */
#endif	/* HOST */

    if (key != NULL)
	{
	if (wtxRpcKeySplit (key, &split) != WTX_OK)
	    WTX_EXCHANGE_RETURN (xid, 
				 WTX_ERR_EXCHANGE_BAD_KEY, WTX_ERROR);
	}
    else 
	{
	/*
	 * NULL key => contact the registry service so fill in the split key
	 * with the Tornado registry particulars 
	 */
#ifdef HOST
	if ((registryHost = getenv ("WIND_REGISTRY")) == NULL)
	    registryHost = "127.0.0.1";			/* its probably local */

	strncpy (split.host, registryHost, sizeof (split.host));
	split.host [sizeof (split.host) - 1] = '\0';
#endif

	/* set ipAddr to the empty string.  That will cause the address
	 * lookup logic below to use gethostbyname for us.
	 */

	strcpy (split.ipAddr, "");

	split.progNum	= WTX_SVC_BASE;
	split.version	= 1;
	split.protocol	= IPPROTO_TCP;
	}

    /* 
     * Get the internet address for the given host.  Parse hostname
     * as host name or alternatively in the `xx.xx.xx.xx' notation. 
     */

    memset ((void *) &addr, 0, sizeof (addr));

    /*
     * Get the IP address. First use the dotted decimal part of the
     * split key if that is comprehensible.  Otherwise use
     * gethostbyname to look up the address.  If that fails try to
     * parse the hostname itself as a dotted decimal.  Otherwise
     * complain. 
     */

    if (split.ipAddr [0]
	&& (addr.sin_addr.s_addr = inet_addr (split.ipAddr)) != (unsigned)-1)
	;
#ifdef HOST
#ifdef WIN32
    else if ((addr.sin_addr.s_addr = inet_addr (split.host)) != INADDR_NONE)
	;
    else if ((pHostEnt = (struct hostent *)gethostbyname (split.host)) != NULL)
	addr.sin_addr.s_addr = * ((u_long *) pHostEnt->h_addr_list[0]);
    else 
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_NO_SERVER, WTX_ERROR);
#else
    else if ((pHostEnt = (struct hostent *)gethostbyname (split.host)) != NULL)
	addr.sin_addr.s_addr = * ((u_long *) pHostEnt->h_addr_list[0]);
    else if ((addr.sin_addr.s_addr = inet_addr (split.host)) == (unsigned)-1)
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_NO_SERVER, WTX_ERROR);
#endif /* WIN32 */
#else
    else
	addr.sin_addr.s_addr = syncRegistry;
#endif /* HOST */

    addr.sin_family	= AF_INET;
    addr.sin_port	= htons(0);			/* portmapd will pick */
    rpcSock 		= RPC_ANYSOCK;			/* any old socket */
    
    if (split.protocol == IPPROTO_TCP)
	pClient = clnttcp_create (&addr, split.progNum, split.version,
				  &rpcSock, 0, 0);
    else
	pClient = clntudp_create (&addr, split.progNum, split.version, 
				  rpcDefaultUdpTimeout, &rpcSock);

    if (pClient == NULL)				/* transport failed? */
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_NO_SERVER, WTX_ERROR);

    /* Set up the authorization mechanism */
#ifdef HOST
#ifndef WIN32
    pClient->cl_auth = authunix_create_default();
#else
    pClient->cl_auth = authunix_create("WIN32", wpwrGetUid(), NULL, NULL, NULL);
#endif /* WIN32 */
#else
    /* authentication */

    pClient->cl_auth = authunix_create ("", 0, 0, 0, NULL);
    /* set the real value computed on host and stored on target */
    pClient->cl_auth->ah_cred.oa_flavor = authCred.oa_flavor;
    pClient->cl_auth->ah_cred.oa_base = authCred.oa_base;
    pClient->cl_auth->ah_cred.oa_length = authCred.oa_length;
#endif  /* HOST */

    xid->transport = pClient;

    return WTX_OK;
    }

/*******************************************************************************
*
* wtxRpcExchangeControl - perform a miscellaneous exchange control function.
*
* This routine performs a miscellaneous control function on the exchange 
* handle <xid>. 
*
* RETURNS: WTX_OK, or WTX_ERROR.
*
* ERRORS: WTX_ERR_EXCHANGE_INVALID_HANDLE, WTX_ERR_EXCHANGE_INVALID_ARG
*
* NOMANUAL
*/

STATUS wtxRpcExchangeControl
    (
    WTX_XID	xid,		/* Exchange handle */
    UINT32	request,	/* Exchange control request number */
    void *	arg		/* Pointer to request argument */
    )

    {
    CLIENT * pClient;

    pClient = (CLIENT *) xid->transport;

    switch (request) 
	{
	case WTX_EXCHANGE_CTL_TIMEOUT_SET:
	    xid->timeout = *(UINT32 *) arg;
	    break;
	    
	case WTX_EXCHANGE_CTL_TIMEOUT_GET:
	    *(UINT32 *) arg = xid->timeout;
	    break;
	    
	default:
	    WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED, 
				 WTX_ERROR);
	}

    return WTX_OK;
    }


/*******************************************************************************
*
* wxRpcDelete - delete the exchange handle and any transport connection.
*
* This routine deletes the exchange mechanism specified by the exchange 
* handle <xid>. <xid> should not be used again in any further exchange
* calls as the underlying transport mechanism is closed also.
*
* RETURNS: WTX_OK, or WTX_ERROR
*
* NOMANUAL
*/

STATUS wtxRpcExchangeDelete
    (
    WTX_XID xid			/* Exchange handle */
    )
    {
    CLIENT *pClient;

    pClient = (CLIENT *) xid->transport;

    if (pClient == NULL)
	/* Nothing to do */
	return WTX_OK;

#ifndef WIN32
    if (pClient->cl_auth != NULL)
	auth_destroy (pClient->cl_auth);
#endif /* WIN32 */

    clnt_destroy (pClient);

    xid->transport = NULL;

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxRpcExchangeFree - free a exchange call result message
*
* This routine frees the memory allocated internally to the result message
* <pMsg> used in making the exchange service call <svcNum>.
*
* RETURNS: WTX_OK, or WTX_ERROR
*
* NOMANUAL
*/

STATUS wtxRpcExchangeFree
    (
    WTX_XID	xid,		/* exchange handle */
    WTX_REQUEST	svcNum,		/* number of server service result to free */
    void *	pMsg		/* pointer to result message to free */
    )

    {
    CLIENT * pClient;

    pClient = (CLIENT *) xid->transport;

    /* With RPC we cannot free a result after the exchange is disconnected
     * because the clnt_freeres uses the XDR data which is lost on the
     * clnt_destroy(). 
     */
    if (pClient == NULL)
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_NO_TRANSPORT, WTX_ERROR);

    if (svcNum > rpcSvcTableSize || (*rpcSvcTable)[svcNum] == NULL)
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED,
			     WTX_ERROR);

    clnt_freeres (pClient, (*rpcSvcTable)[svcNum]->xdrOut, pMsg);
 
    return (WTX_OK);
    }



/*******************************************************************************
*
* wtxRpcExchange - do a WTX API call via the exchange mechanism
*
* This routine performs the exchange service call <svcNum> with in parameters
* pointed to by <pIn> and result (out) parameters pointed to by <pOut>. The
* status of the call is represented by the error code returned.  The result
* <pOut> may have memory allocated to it internally which can be freed by
* using wtxRpcExchangeFree().
*
* RETURNS: WTX_OK, or WTX_ERROR
*
* NOMANUAL
*/

STATUS wtxRpcExchange
    (
    WTX_XID	xid,		/* exchange handle */
    WTX_REQUEST	svcNum,		/* exchange service number */
    void *	pIn,		/* exchange service in args */
    void *	pOut		/* exchange service out args */
    )

    {
    enum clnt_stat	rpcStat; 
    WTX_ERROR_T		wtxStat;
    WTX_MSG_RESULT *	pMsgOut;
    CLIENT *		pClient;
    RPC_SERVICE	*	pService;
    struct timeval	timeout;


    pClient = (CLIENT *) xid->transport;
    if (pClient == NULL)
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_NO_TRANSPORT, WTX_ERROR);

    /* Make sure the table has been initialized */
    if (rpcSvcTable == NULL)
	rpcSvcTableInstall ();

    if (svcNum > rpcSvcTableSize || (*rpcSvcTable)[svcNum] == NULL)
	WTX_EXCHANGE_RETURN (xid, WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED, 
			     WTX_ERROR);

    pService = (*rpcSvcTable)[svcNum];

    /* Construct a timeout struct on the fly for service request */
    timeout.tv_sec = xid->timeout / 1000;
    timeout.tv_usec = xid->timeout * 1000 - timeout.tv_sec * 1000000;

    rpcStat = clnt_call (pClient,
			 svcNum, 
			 pService->xdrIn, pIn,  
			 pService->xdrOut, pOut,  
			 timeout);

    wtxStat = rpcStatToError (rpcStat);

    if (wtxStat != WTX_ERR_NONE)
	{
	/* An RPC error occured. Free the result and return */
	clnt_freeres (pClient, pService->xdrOut, pOut);

	/* Handle case of RPC failing so badly we must disconnect */
	if (wtxStat == WTX_ERR_EXCHANGE_TRANSPORT_DISCONNECT)
	    wtxRpcExchangeDelete (xid);

	WTX_EXCHANGE_RETURN (xid, wtxStat, WTX_ERROR);
	}

    /*
     * Sort cut for NULLPROC that doesn't return a proper WTX message result.
     */
    if (svcNum == NULLPROC)
	return WTX_OK;

    pMsgOut = (WTX_MSG_RESULT *) pOut;

    if (pMsgOut->wtxCore.errCode != OK)
	{
	UINT32 errCode;

	/* A service specific error occured. Free the result and return */
	errCode = pMsgOut->wtxCore.errCode;
	clnt_freeres (pClient, pService->xdrOut, pOut);
	WTX_EXCHANGE_RETURN (xid, errCode, WTX_ERROR);
	}

    return WTX_ERR_NONE;
    }


/*******************************************************************************
*
* rpcStatToError - convert an RPC status to a WTX error code.
* 
* This routine converts an RPC error status <callStat> to a WTX error code.
*
* RETURNS: the WTX error code or WTX_ERR_NONE if no error occured.
*
* NOMANUAL
*/

LOCAL WTX_ERROR_T rpcStatToError
    (
    enum clnt_stat	rpcStat		/* status from call */
    )

    {
    switch (rpcStat) 
	{
	case RPC_SUCCESS:
	    return WTX_ERR_NONE;	/* call succeeded */

	case RPC_CANTENCODEARGS:	/* can't encode arguments */
	case RPC_CANTDECODERES:		/* can't decode results */
	case RPC_CANTDECODEARGS:	/* decode arguments error */
	case RPC_SYSTEMERROR:		/* generic "other problem" */
	case RPC_UNKNOWNHOST:		/* unknown host name */
	case RPC_UNKNOWNPROTO:		/* unknown protocol -- 4.0 */
	case RPC_PMAPFAILURE:		/* the pmapper failed in its call */
	case RPC_PROGNOTREGISTERED:	/* remote program is not registered */
	case RPC_FAILED:
	    return WTX_ERR_EXCHANGE_TRANSPORT_ERROR;

	case RPC_PROCUNAVAIL:		/* procedure unavailable */
	    return WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED;

	case RPC_CANTSEND:		/* failure in sending call */
	case RPC_CANTRECV:		/* failure in receiving result */
	case RPC_VERSMISMATCH:		/* rpc versions not compatible */
	case RPC_AUTHERROR:		/* authentication error */
	case RPC_PROGUNAVAIL:		/* program not available */
	case RPC_PROGVERSMISMATCH:	/* program version mismatched */
	    return WTX_ERR_EXCHANGE_TRANSPORT_DISCONNECT;

	case RPC_TIMEDOUT:		/* call timed out */
	    return WTX_ERR_EXCHANGE_TIMEOUT;

	default:
	    return WTX_ERR_EXCHANGE;
	}
    
}


/*******************************************************************************
*
* rpcSvcAdd - add a new service into the exchange service table
*
* This routine adds a new service with service number <svcNum> into the
* exchange service table.  The in and out XDR routines <xdrIn> and <xdrOut>
* are recorded in the table.
*
* RETURNS: OK, or ERROR.
*/
LOCAL STATUS rpcSvcAdd
    (
    UINT32	svcNum,
    void	*xdrIn,
    void	*xdrOut
    )

    {
    if (svcNum + 1 > rpcSvcTableSize)
	{
	RPC_SERVICE *(*newTable)[];

	/* Current table not big enough */
	newTable = calloc (svcNum + 1, sizeof (RPC_SERVICE *));
	if (newTable == NULL)
	    return ERROR;

	/* Copy and free the old one */
	if (rpcSvcTable != NULL)
	    {
	    memcpy (newTable, rpcSvcTable, 
		    rpcSvcTableSize * sizeof (RPC_SERVICE *));
	    free (rpcSvcTable);
	    }

	rpcSvcTable = newTable;
	rpcSvcTableSize = svcNum + 1;
	}
    
    (*rpcSvcTable)[svcNum] = malloc (sizeof (RPC_SERVICE));
    if  ((*rpcSvcTable)[svcNum] == NULL)
	/* No space for the new service description */
	return ERROR;

    (*rpcSvcTable)[svcNum]->xdrIn = (xdrproc_t) xdrIn;
    (*rpcSvcTable)[svcNum]->xdrOut =(xdrproc_t) xdrOut;

    return OK;
    }

    
/*******************************************************************************
*
* rpcSvcTableInstall - install initial table of service definitions
*
* This routine sets a the table that defines the XDR conversion functions
* for each available exchange service. No action is taken if this function
* is called more than once.
*
* RETURNS: OK, or ERROR
*/
LOCAL STATUS rpcSvcTableInstall (void)
    {
    if (rpcSvcTable != NULL)
	/* Already initialized */
	return (OK);

    /* Add the services to the table of available services */

    /* Ping or no-op service */
    rpcSvcAdd (NULLPROC, xdr_void, xdr_void);

    /* Registry services */
    rpcSvcAdd (WTX_INFO_Q_GET, 
	       xdr_WTX_MSG_WTXREGD_PATTERN, xdr_WTX_MSG_SVR_DESC_Q); 
    rpcSvcAdd (WTX_INFO_GET, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_SVR_DESC); 
    rpcSvcAdd (WTX_REGISTER, xdr_WTX_MSG_SVR_DESC, xdr_WTX_MSG_SVR_DESC); 
    rpcSvcAdd (WTX_UNREGISTER, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT); 

    /* Target server services */
    rpcSvcAdd (WTX_TOOL_ATTACH, xdr_WTX_MSG_TOOL_DESC, xdr_WTX_MSG_TOOL_DESC);
    rpcSvcAdd (WTX_TOOL_DETACH, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_TS_INFO_GET, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_TS_INFO);
    rpcSvcAdd (WTX_TS_LOCK, xdr_WTX_MSG_TS_LOCK, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_TS_UNLOCK, xdr_WTX_MSG_TS_UNLOCK, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_TARGET_RESET, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_TARGET_ATTACH, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_RESULT);
#if 0 /* ELP */
    rpcSvcAdd (WTX_TARGET_PING, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_RESULT);
#endif

    rpcSvcAdd (WTX_CONTEXT_CREATE,
	       xdr_WTX_MSG_CONTEXT_DESC, xdr_WTX_MSG_CONTEXT);
    rpcSvcAdd (WTX_CONTEXT_KILL, xdr_WTX_MSG_CONTEXT, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_CONTEXT_SUSPEND, xdr_WTX_MSG_CONTEXT, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_CONTEXT_CONT, xdr_WTX_MSG_CONTEXT, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_CONTEXT_RESUME, xdr_WTX_MSG_CONTEXT, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_CONTEXT_STEP,
	       xdr_WTX_MSG_CONTEXT_STEP_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_EVENTPOINT_ADD, xdr_WTX_MSG_EVTPT_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_EVENTPOINT_DELETE, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_EVENTPOINT_LIST, 
	       xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_EVTPT_LIST);
    rpcSvcAdd (WTX_MEM_CHECKSUM, xdr_WTX_MSG_MEM_SET_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_READ, 
	       xdr_WTX_MSG_MEM_READ_DESC, xdr_WTX_MSG_MEM_COPY_DESC);
    rpcSvcAdd (WTX_MEM_WRITE, xdr_WTX_MSG_MEM_COPY_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_SET, xdr_WTX_MSG_MEM_SET_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_SCAN, xdr_WTX_MSG_MEM_SCAN_DESC,	xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_MOVE, xdr_WTX_MSG_MEM_MOVE_DESC,	xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_ALLOC, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_REALLOC,	xdr_WTX_MSG_MEM_BLOCK_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_ALIGN, xdr_WTX_MSG_MEM_BLOCK_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_ADD_TO_POOL,
	       xdr_WTX_MSG_MEM_BLOCK_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_FREE, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_MEM_INFO_GET, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_MEM_INFO);
    rpcSvcAdd (WTX_REGS_GET, xdr_WTX_MSG_REG_READ, xdr_WTX_MSG_MEM_XFER_DESC);
    rpcSvcAdd (WTX_REGS_SET, xdr_WTX_MSG_REG_WRITE, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_OPEN, xdr_WTX_MSG_OPEN_DESC,	xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_VIO_READ, 
	       xdr_WTX_MSG_VIO_COPY_DESC, xdr_WTX_MSG_VIO_COPY_DESC);
    rpcSvcAdd (WTX_VIO_WRITE, xdr_WTX_MSG_VIO_COPY_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_CLOSE, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_VIO_CTL, xdr_WTX_MSG_VIO_CTL_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_VIO_FILE_LIST, 
	       xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_VIO_FILE_LIST);
    rpcSvcAdd (WTX_OBJ_MODULE_LOAD, 
	       xdr_WTX_MSG_LD_M_FILE_DESC, xdr_WTX_MSG_LD_M_FILE_DESC);
    rpcSvcAdd (WTX_OBJ_MODULE_UNLOAD, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_OBJ_MODULE_LIST, 
	       xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_MODULE_LIST);
    rpcSvcAdd (WTX_OBJ_MODULE_INFO_GET, 
	       xdr_WTX_MSG_MOD_NAME_OR_ID, xdr_WTX_MSG_MODULE_INFO);
    rpcSvcAdd (WTX_OBJ_MODULE_FIND, 
	       xdr_WTX_MSG_MOD_NAME_OR_ID, xdr_WTX_MSG_MOD_NAME_OR_ID);
    rpcSvcAdd (WTX_SYM_TBL_INFO_GET, 
	       xdr_WTX_MSG_PARAM, xdr_WTX_MSG_SYM_TBL_INFO);
    rpcSvcAdd (WTX_SYM_LIST_GET, 
	       xdr_WTX_MSG_SYM_MATCH_DESC, xdr_WTX_MSG_SYM_LIST);
    rpcSvcAdd (WTX_SYM_FIND, xdr_WTX_MSG_SYMBOL_DESC, xdr_WTX_MSG_SYMBOL_DESC);
    rpcSvcAdd (WTX_SYM_ADD, xdr_WTX_MSG_SYMBOL_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_SYM_REMOVE, xdr_WTX_MSG_SYMBOL_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_EVENT_GET, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_EVENT_DESC);
    rpcSvcAdd (WTX_REGISTER_FOR_EVENT, 
	       xdr_WTX_MSG_EVENT_REG_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_UN_REGIS_FOR_EVENT, 
	       xdr_WTX_MSG_EVENT_REG_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_EVENT_ADD, xdr_WTX_MSG_EVENT_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_GOPHER_EVAL, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_GOPHER_TAPE);
    rpcSvcAdd (WTX_FUNC_CALL, xdr_WTX_MSG_CONTEXT_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_DIRECT_CALL, xdr_WTX_MSG_CONTEXT_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_SERVICE_ADD, xdr_WTX_MSG_SERVICE_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_AGENT_MODE_SET, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_AGENT_MODE_GET, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_CONSOLE_CREATE, 
	       xdr_WTX_MSG_CONSOLE_DESC, xdr_WTX_MSG_CONSOLE_DESC);
    rpcSvcAdd (WTX_CONSOLE_KILL, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_OBJ_KILL, xdr_WTX_MSG_KILL_DESC, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_VIO_CHAN_GET, xdr_WTX_MSG_TOOL_ID, xdr_WTX_MSG_RESULT);
    rpcSvcAdd (WTX_VIO_CHAN_RELEASE, xdr_WTX_MSG_PARAM, xdr_WTX_MSG_RESULT);

    return (OK);
    }
