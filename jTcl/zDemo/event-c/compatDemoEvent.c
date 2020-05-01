/*
 * Copyright(c) 1998 FRIDU a Free Software Company
 *
 * Projet       : Test
 * SubModule    : Tcl Event Loop
 * Implement    : TclEvt
 * Object   	: Small interface to Tcl custom event in main loop
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 *
 * Last:
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:30 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/event-c/compatDemoEvent.c,v $
 *
 * Modification History
 * -------------------
 * 1.1  01sep98, Fulup Written
 *
 */

#include <tcl.h>
#include <libRuntimeJwrap.h>

/** ------------------------------------------------------------------------------
 *   Provide a binary compatibility between TCL8 and Tcl8.1
 *  ------------------------------------------------------------------------------*/


PUBLIC Tcl_Obj *Tcl_ObjSetVar2 (Tcl_Interp *interp, Tcl_Obj *part1Ptr, Tcl_Obj *part2Ptr
		               , Tcl_Obj *newValuePtr, int flags) {

  return (Tcl_SetObjVar2 (interp, TCL_STRING (part1Ptr), TCL_STRING (part2Ptr)
          ,newValuePtr, flags));
}

PUBLIC Tcl_Obj *Tcl_ObjGetVar2 (Tcl_Interp *interp, Tcl_Obj *part1Ptr, Tcl_Obj *part2Ptr
		               , int flags) {

  return (Tcl_GetObjVar2 (interp, TCL_STRING (part1Ptr), TCL_STRING (part2Ptr), flags));
}

PUBLIC int Tcl_GlobalEvalObj (Tcl_Interp *interp, Tcl_Obj *objPtr) {
     return (Tcl_EvalObj (interp, objPtr, TCL_EVAL_GLOBAL));
}

