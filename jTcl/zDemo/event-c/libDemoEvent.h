/*
 * Copyright(c) 1998 FRIDU a Free Software Company
 * 
 * Projet       : Test
 * SubModule    : Tcl Event Loop
 * Implement    : DemoEvent
 * Object   	: Small interface to Tcl custom event in main loop
 * Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
 * 
 * Last: 
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:30 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/event-c/libDemoEvent.h,v $
 * 
 * Modification History
 * -------------------
 * 1.1  01sep98, Fulup Written
 * 
 */

// exclude standard include from wrapping
#ifndef JWRAP_JTCL
#  include <tcl.h>
#endif

/** ------------------------------------------------------------------------------
 *   Overload default jWrap init 
 ** ------------------------------------------------------------------------------*/
#define DemoEvent_CUSTOM_INIT initModule(interp);

/** ---------------------------------------------------------------
 *  Connect onto a Tcp client and store everything will need
 *  to call TCL callback from event handler, 
 * ----------------------------------------------------------------*/
PUBLIC int start (Tcl_Interp *interp, Tcl_Obj *host, int port, Tcl_Obj *callback);

/** ------------------------------------------------------------------------------
 *   Close Tcl client socket and free socket handle
 ** ------------------------------------------------------------------------------*/
PUBLIC void stop (int port);

/** ------------------------------------------------------------------------------
 *   send a message on socket
 ** ------------------------------------------------------------------------------*/
PUBLIC void put (int port, Tcl_Obj *msg);

/** ------------------------------------------------------------------------------
 *   get a message from socket
 ** ------------------------------------------------------------------------------*/
PUBLIC Tcl_Obj* get (int port);

// include all other application proto and timestamp
#include <libDemoEvent.i>
