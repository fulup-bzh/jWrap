/*
 *	Copyright(c) 1998 FRIDU a free Software Company
 *
 * Projet	:   Jos/jWrap
 * SubModule    :   Test/jWrap
 * Auteur       :   Fulup Ar Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/structure-c/mainDemoStruct.c,v $
 *
 * Modification History
 * ----------------------
 * 01a,20feb98,Fulup written from old basic cTest simple demo
 *
 */


#include "libRuntimeJwrap.h"

// We don't have a valid proto
extern void Demostruct_Init  (Tcl_Interp *interp);

// Hook from TCL init provide a valid Interp
LOCAL int  modulesInit (Tcl_Interp *interp)
{
   Tcl_Init     (interp);
   Demostruct_Init  (interp);
   return TCL_OK;
}

int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
    return OK;
}
