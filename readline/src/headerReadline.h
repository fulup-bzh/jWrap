/** ------------------------------------------------------------
 *
 * Copyright(c) 1999 FRIDU a Free Software Company
 * 
 * Projet       : jWrap
 * SubModule    : Readline
 * Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
 * 
 * Last: 
 *  Author      : $Author: Fulup $
 *  Date        : $Date: 1999/03/22 10:11:46 $
 *  Revision    : $Revision: 1.4 $
 *  Source      : $Source: /Master/jWrap/readline/src/headerReadline.h,v $
 * 
 * Modification History
 * -------------------
 * 01a,03mar99, Fulup written
 * 
 * -----------------------------------------------------------------------*/

/* -----------------------------------------------------------------------
 *  Interface : Readline
 *  Help      : GNU Readline interface to tclsh
 * -----------------------------------------------------------------------*/

#include "libRuntimeReadline.h"

// define library time stamp
#ifndef Readline_CUSTOM_STAMP
#define Readline_CUSTOM_STAMP &vStamp_libRuntimeReadline[15]
#endif
#define Readline_CUSTOM_INIT  customInit(interp)

// Force init of Internal jWrap submodule
LOCAL int customInit (Tcl_Interp *interp)
{ 
  // Check jWrap as been correctelly inited
  if (Jwrap_Init (interp) != TCL_OK) {
     jWrapPanic (interp,"Readline jWrap Custom Init failled\n");
  }

  // We dont test return because moduleInit routine use jWrapPanic for errors
  ReadlineLibInit   (interp);

  return TCL_OK;
} // end localInit
