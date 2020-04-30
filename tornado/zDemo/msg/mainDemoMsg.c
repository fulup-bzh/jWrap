/*
 *	Copyright(c) 1998 FRIDU a free Software Company
 *
 * Projet	:   Jos/jWrap
 * SubModule    :   Test/Tornado
 * Auteur       :   Fulup Le Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:31 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/zDemo/msg/mainDemoMsg.c,v $
 *
 * Modification History
 * ----------------------
 * 01a,20feb98,Fulup written from old basic cTest simple demo
 *
 */


#include "libRuntimeTornado.h"
#include "libRuntimeWtx.h"
#include "libRuntimeVxWorks.h"

// We don't have a valid proto
extern Demomsg_Init  (Tcl_Interp *interp); 

// Hook from TCL init provide a vliad Interp 
LOCAL int modulesInit (Tcl_Interp *interp)
{
   // Warning componant init order should be respected
   Tcl_Init      (interp);
   Wtx_Init      (interp);
   Tornado_Init  (interp);
   Vxworks_Init  (interp);
   Demomsg_Init  (interp);
   return TCL_OK;
}
    
int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
    return OK;
}
