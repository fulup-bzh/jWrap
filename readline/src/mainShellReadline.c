/*
 *	Copyright(c) 1998-99 FRIDU a free Software Company
 *
 * File   	:   Main entry point for default Tornado Shell
 * Projet	:   jWrap
 * SubModule    :   Readline
 * Auteur       :   Fulup Ar Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/readline/src/mainShellReadline.c,v $
 *
 * Modification History
 * ----------------------
 * 01a,03mar99,Fulup written
 *
 */


#include "libRuntimeReadline.h"

#include <stdlib.h>

// Hook from TCL init provide a vliad Interp
LOCAL int modulesInit (Tcl_Interp *interp)
{
   // WARNING: componant init order should be respected
   Tcl_Init      (interp);
   Readline_Init  (interp);
   return TCL_OK;
}

int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
    return TCL_OK;
}
