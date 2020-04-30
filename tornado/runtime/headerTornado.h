/** ------------------------------------------------------------
 *
 * Copyright(c) 1997-99 FRIDU a Free Software Company
 * 
 * File   	: headerTornado.h hold every include for WPR.h to compile
 * Projet       : jWrap
 * SubModule    : Wtx VxWorks/Tornado WTX interface
 * Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
 * 
 * Last: 
 *  Author      : $Author: Fulup $
 *  Date        : $Date: 1999/03/22 10:11:46 $
 *  Revision    : $Revision: 1.4 $
 *  Source      : $Source: /Master/jWrap/tornado/runtime/headerTornado.h,v $
 * 
 * Modification History
 * -------------------
 * 01b,15feb99, Fulup moved to new tree and removed WTX C API
 * 01a,05may98, Fulup Written
 * 
 * -----------------------------------------------------------------------*/

/* -----------------------------------------------------------------------
 *  Interface : Tornado
 *  Help      : Tornado fast interface to WTX
 * -----------------------------------------------------------------------*/

#ifndef JWRAP
#  include "host.h"
#  include "wtx.h"
#endif

#include "libRuntimeTornado.h"

#ifndef JWRAP
#  include <easyc.h>
#  include <stdio.h>

#  include "libRuntimeWtx.h"
#endif

// define library time stamp
#ifndef Tornado_CUSTOM_STAMP
#define Tornado_CUSTOM_STAMP &vStamp_libRuntimeTornado[15]
#endif
#define Tornado_CUSTOM_INIT  customInit(interp)

// Force init of Internal jWrap submodule
LOCAL int customInit (Tcl_Interp *interp)
{ 
  // Check jWrap as been correctelly inited
  if (Wtx_Init (interp) != TCL_OK) {
     jWrapPanic (interp,"TORNADO jWrap Custom Init failled\n");
  }

  // We dont test return because moduleInit routine use jWrapPanic for errors
  tornadoMiscInit   (interp);
  tornadoVarInit    (interp);
  tornadoStringInit (interp);
  tornadoTypeInit   (interp);
  tornadoTargetInit (interp);

  jWrapTypeAlias (NULL,"int" ,"size_t");    

  return TCL_OK;
} // end localInit
