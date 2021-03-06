/** ------------------------------------------------------------
 *
 * Copyright(c) 1997-99 FRIDU a Free Software Company
 *
 * File   	: libWtxHost.h Interface for VxWorks/Tornado test lib
 * Projet       : jWrap
 * SubModule    : jWrap/Wtx WTX interface
 * Author       : Fulup Ar Foll (Fulup@fridu.bzh)
 *
 * Last:
 *  Author      : $Author: Fulup $
 *  Date        : $Date: 1999/03/25 17:20:08 $
 *  Revision    : $Revision: 1.6 $
 *  Source      : $Source: /Master/jWrap/tornado/tWTX/headerWtxTornado.h,v $
 *
 * Modification History
 * -------------------
 * 01c,25mar99, Fulup change for Tornado as father module
 * 01b,15feb99, Fulup addapted to new tree
 * 01a,05may98, Fulup Written
 *
 * -----------------------------------------------------------------------*/

/* -------------------------------------------------------------
 *   Help     : Tornado/VxWorks interface with target server
 *   Interface: Wtx
 *-------------------------------------------------------------*/

/* We use an absolute path in order not including all VxWorks with CPP */

#include <../from-wrs/Include/wtx.h>

#ifndef JWRAP_JTCL
#  include <stdlib.h>
#  include "libRuntimeTornado.h"
#endif

// define library time stamp
#ifndef Wtx_CUSTOM_STAMP
#define Wtx_CUSTOM_STAMP &vStamp_libRuntimeWtx[15]
#endif

#define Wtx_CUSTOM_INIT  customInit(interp)
// Force init of Internal jWrap submodule
LOCAL int customInit (Tcl_Interp *interp)
{
  char* registry;

  // Check jWrap as been correctelly inited
  if (Tornado_Init (interp) != TCL_OK) {
     jWrapPanic (interp,"Wtx jWrap Custom Init failled\n");
  }

  return TCL_OK;
} // end localInit


#ifndef JWRAP
#include "libRuntimeTornado.h"
#include "libRuntimeWtx.i"
#endif
