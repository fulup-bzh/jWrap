/*
 *	Copyright(c) 1998 FRIDU a free Software Company
 *
 * Projet    :   Jos/jWrap
 * Module    :   Test/jWrap
 * Auteur    :   Fulup Ar Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/overload++/mainDemoOverload.cxx,v $
 *
 * Modification History
 * ----------------------
 * 01a,20feb98,Fulup written from old basic cTest simple demo
 *
 */


#include "funcDemoOverload.h"

#ifdef __cplusplus
extern "C" {
#endif
EXTERN DemoOverload_Init (Tcl_Interp *interp);
#ifdef __cplusplus
}
#endif

// Hook from TCL init provide a valid Interp
LOCAL void modulesInit (Tcl_Interp *interp)
{
   Demooverload_Init (interp);
   Tcl_Init     (interp);
}

int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
}
