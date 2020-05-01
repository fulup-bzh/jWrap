/*
 *	Copyright(c) 1998 FRIDU a free Software Company
 *
 * Projet	:   Jos/jWrap
 * SubModule    :   Test/jWrap
 * Auteur       :   Fulup Ar Foll FRIDU a Free Software company
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/Mikhail++/mainDemoMikhail.cxx,v $
 *
 * Modification History
 * ----------------------
 * 01a,20feb98,Fulup written from old basic cTest simple demo
 *
 */


#include "funcDemoMikhail.h"

// Hook from TCL init provide a valid Interp
LOCAL void modulesInit (Tcl_Interp *interp)
{
   Demomikhail_Init (interp);
   Tcl_Init     (interp);
}

int main (int argc, char** argv)
{
    Tcl_Main(argc, argv, (Tcl_AppInitProc *) modulesInit);
}
