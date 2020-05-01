/*
 *	Copyright(c) 1998-99 FRIDU a free Software Company
 *
 * File   	:   Main entry point for default Tornado Shell
 * Projet	:   jWrap
 * SubModule    :   WTX VxWorks Tornado inteface
 * Auteur       :   Fulup Ar Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/shell/mainShellTornado.c,v $
 *
 * Modification History
 * ----------------------
 * 01b,16feb99,Fulup,addapted to new tree
 * 01a,20feb98,Fulup,written from old basic cTest simple demo
 *
 */


#include "libRuntimeTornado.h"
#include "libRuntimeWtx.h"
#include "libRuntimeReadline.h"
#include "libRuntimeVxWorks.h"

#include <stdlib.h>

// Hook from TCL init provide a vliad Interp
LOCAL int modulesInit (Tcl_Interp *interp)
{
   // WARNING: componant init order should be respected
   Tcl_Init      (interp);
   Vxworks_Init  (interp);
   Readline_Init  (interp);

   return TCL_OK;
}

int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
    return TCL_OK;
}
