/*
 * Copyright(c) 1998 FRIDU a Free Software Company
 *
 * Projet       : Test
 * SubModule    : Tcl Event Loop
 * Object   	: Small interface to Tcl custom event in main loop
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 *
 * Last:
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:30 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/event-c/funcDemoEvent.c,v $
 *
 * Modification History
 * -------------------
 * 1.1  01sep98, Fulup Written
 *
 */

#include <signal.h>
#include <libRuntimeJwrap.h>

#include <libDemoEvent.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

/** ------------------------------------------------------------------------------
 *   This example shows how adding a new event in TCL default main loop. It has
 *   no other aim that demonstrating this Tcl functionnality and dont provides
 *   any application facilities [For real application use TCL8 socket commands].
 *
 *   We provides three commands
 *      connect: attach to TCP server [use localhost/7 for test]
 *      send   : send a buffer on openned socket
 *      get    : read a buffer on socket
 *      close  : free connection
 *
 *   Warning: this example is not thread compliant and will probably not work
 *            under WIN32 Fridu reference plateform is Linux, secondary is Solaris
 *  -----------------------------------------------------------------------------*/

// used a private date structure for signal event
typedef struct sock_Evt {
 Tcl_Event tclEvt;
 int       num;
} SOCK_evt;


// we use a stativ array to hold all signal related data
typedef struct sock_Id {
  int           sock;
  Tcl_Obj      *callback;
  Tcl_Interp   *interp;
  Tcl_Obj      *host;
} SOCK_id;

// We store all open socket in a fix array, a linked list would complexify example
LOCAL SOCK_id *sockId [4069];

/** ------------------------------------------------------------------------------
 *   This routine is call by  Tcl_ServiceEvent when a signal as been raised
 *   it received and event handler that allows to know which signal we are
 *   processing. As we alway process event we systematically return 1.
 ** ------------------------------------------------------------------------------*/
LOCAL void sockCallback (ClientData clientData, int flag) {
  static int errNum;
  int status;
  int port = (int) clientData;

  // get tcl callback from signal number and call it.
  status = Tcl_GlobalEvalObj(sockId [port]->interp, sockId [port]->callback);
  if (status != TCL_OK) {
    jWrapLog (0,"%d: failed to call Tcp callback: %s for port %s:%d\n"
             , errNum++, TCL_STRING (sockId [port]->callback)
             , TCL_STRING (sockId [port]->host), port);

    Tcl_BackgroundError(sockId [port]->interp);
  }
}

/** ------------------------------------------------------------------------------
 *   Currentelly init dont do any custom job
 ** ------------------------------------------------------------------------------*/
PUBLIC void initModule (Tcl_Interp *interp) {

 // start initializing jWrap core module
 if (Jwrap_Init (interp) != TCL_OK) goto errInitJwrap;

 return; // ----- OK ------

 errInitJwrap:
    jWrapPanic (interp, "tstEvt jWrap core module initialization failled");
}



/** ---------------------------------------------------------------
 *  Connect onto a Tcp client and store everything will need
 *  to call TCL callback from event handler,
 * ----------------------------------------------------------------*/
PUBLIC int start (Tcl_Interp *interp, Tcl_Obj *host, int port, Tcl_Obj *callback) {

  int sock;
  struct sockaddr_in servAddr;	/* socket address */
  struct hostent *hostent;	/* Host database entry */
  struct in_addr addr;		/* For 64/32 bit madness */
  int    status;

  // check socket validity
  if ((port <=1024) || (port > 4096)) goto errSockNum;

  // check socket is not already trapped
  if (sockId [port] != NULL) goto bsySockNum;

  // Create a client socket
  sock= socket (AF_INET, SOCK_STREAM, 0);
  if (sock <= 0) goto errSockCreate;

  // fill up server structure
  memset((void*) &servAddr, '\0', sizeof(struct sockaddr_in));
  servAddr.sin_family = AF_INET;
  servAddr.sin_port   = htons((unsigned short) (port & 0xFFFF));
  addr.s_addr     = inet_addr(TCL_STRING (host));
  if (addr.s_addr == (unsigned) -1) {
     hostent = gethostbyname(TCL_STRING (host));
     if (hostent == NULL) goto errSockHost;
     memcpy((VOID *) &addr,(VOID *) hostent->h_addr_list[0],(size_t) hostent->h_length);
  }
  servAddr.sin_addr.s_addr = addr.s_addr;

  // try to connect onto client
  status = connect (sock, &servAddr, sizeof (struct sockaddr_in));
  if (status != 0) goto errSockConnect;

  // we sucessfully connect on client store socket
  // store everything to be able to call a TCL callback.
  sockId [port] = (SOCK_id*) Tcl_Alloc (sizeof (SOCK_id));
  sockId [port]->interp   = interp;
  sockId [port]->sock = sock;

  // store callbackname and host as force Tcl not to free it
  Tcl_IncrRefCount (callback);
  sockId [port]->callback = callback;
  Tcl_IncrRefCount (host);
  sockId [port]->host     = host;

  // ask Tcl to call our call back when a buufer will be ready
  Tcl_CreateFileHandler (sock, TCL_READABLE, sockCallback, (ClientData) port);

  jWrapLog (1,"Connect Tcl Client %s:%d done\n", host,port);

  return port; // ------- OK --------

errSockHost:
   jWrapPanic (NULL, "Invalid host internet name %s", host);

errSockCreate:
   jWrapPanic (NULL, "Invalid could not create socket %s:%d", host,port);

errSockConnect:
   jWrapPanic (NULL, "Invalid could not connect socket %s:%d", host,port);

errSockNum:
   jWrapPanic (NULL, "Invalid socket number:%d", port);

bsySockNum:
   jWrapPanic (NULL, "Used socket number:%d", port);

return JWRAP_IMPOSSIBLE;
}


/** ------------------------------------------------------------------------------
 *   Close Tcl client socket and free socket handle
 ** ------------------------------------------------------------------------------*/
PUBLIC void stop (int port) {

  // check socket number validity
  if (port <=0 || (port > 1024)) goto errSockNum;

  // check this socket was previouselly trapped
  if (sockId [port] == NULL) goto unkSockNum;

  // Free up client
  close (sockId [port]->sock);

  jWrapLog (1,"close Tcl Client %s:%d done\n",TCL_STRING (sockId [port]->host), port);

  // free Tcl ressources
  Tcl_DecrRefCount (sockId [port]->callback);
  Tcl_DecrRefCount (sockId [port]->host);
  Tcl_Free ((void*)sockId [port]);
  sockId [port] = NULL;

  return; // ------ OK --------

errSockNum:
   jWrapPanic (NULL, "Invalid socket number:%d", port);

unkSockNum:
   jWrapPanic (NULL, "Unregistrated socket handler:%d", port);

}

/** ------------------------------------------------------------------------------
 *   send a message on socket
 ** ------------------------------------------------------------------------------*/
PUBLIC void put (int port, Tcl_Obj *msg) {
  int status;

  // check this socket was previouselly trapped
  if (sockId [port] == NULL) goto unkSockNum;

  status = send (sockId [port]->sock, TCL_STRING (msg), msg->length, 0);
  if (status != msg->length) goto errSend;

  jWrapLog (1,"send %s:%d done\n",TCL_STRING (sockId [port]->host), port);

  return; // ------ OK --------

errSend:
   jWrapPanic (NULL, "Can't send message to %s:%d",TCL_STRING (sockId [port]->host), port);

unkSockNum:
   jWrapPanic (NULL, "Invalid socket number:%d", port);
}

/** ------------------------------------------------------------------------------
 *   get a message from socket
 ** ------------------------------------------------------------------------------*/
PUBLIC Tcl_Obj* get (int port) {

  char msg [1024];
  Tcl_Obj *result;
  int len;

  // check this socket was previouselly trapped
  if (sockId [port] == NULL) goto unkSockNum;

  len = recv (sockId [port]->sock, msg, sizeof (msg), 0);
  if (len  <= 0) goto errRecv;

  result  = Tcl_NewStringObj (msg,len);

  jWrapLog (1,"got %s:%d done\n",TCL_STRING (sockId [port]->host), port);

  return result; // ------ OK --------

errRecv:
   jWrapPanic (NULL, "Can't send message to %s:%d",TCL_STRING (sockId [port]->host), port);

unkSockNum:
   jWrapPanic (NULL, "Invalid socket number:%d", port);

return (Tcl_Obj*) JWRAP_IMPOSSIBLE;
}
