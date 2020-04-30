/*
 *	Copyright(c) 1998 FRIDU a free Software Company
 *
 * Projet	:   Jos/jWrap
 * SubModule    :   Test/jWrap
 * Auteur       :   Fulup Le Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/event-c/mainDemoEvent.c,v $
 *
 * Modification History
 * ----------------------
 * 01a,20feb98,Fulup written from old basic cTest simple demo
 *
 */


#include "libRuntimeJwrap.h"
#include "libDemoEvent.h"

// Hook from TCL init provide a vliad Interp 
LOCAL int modulesInit (Tcl_Interp *interp)
{
   Tcl_Init       (interp);
   Demoevent_Init (interp);
   return TCL_OK;
}
    
int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
    return TCL_OK;
}
