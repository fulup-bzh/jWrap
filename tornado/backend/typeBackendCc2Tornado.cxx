/*
 *
 *  Copyright(c) 1997-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   typeBackendCc2jTcl.cc manage type in C++ 2 jTcl backend wrapper
 * Projet    :   jWrap
 * Module    :   WTX VxWorks Troando C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/backend/typeBackendCc2Tornado.cxx,v $
 *
 * Modification History
 * --------------------
 * 01b,16feb99,Fulup,remanced modulefrom TORNADO to Tornado
 * 01a,02jun98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2Tornado.h"


/****************************************************************************
 ** Create a type wrapper that will pass tornado_id as supplemental argument
 ** To all standard Tornado type that needs TornadoId in order reaching target
 ****************************************************************************/
void BackendCc2Tornado::tornadoTypeStdMap (void) {

  fprintf (outFile,"\n// Build string convertion routine\n"); 
  fprintf (outFile,"LOCAL int Put_String (Tcl_Interp *interp, Tcl_Obj *tclObj) {\n");
  fprintf (outFile,"  return (tornadoStringTcl2Cc (&tornadoInfo, interp, tclObj));\n");
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL void Get_String (Tcl_Obj *tclObj) {\n");
  fprintf (outFile,"  tornadoStringCc2Tcl (&tornadoInfo, tclObj);\n");
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL void Free_String (Tcl_Obj *tclObj) {\n");
  fprintf (outFile,"  tornadoStringFree (&tornadoInfo, tclObj);\n");
  fprintf (outFile,"}\n");

  fprintf (outFile,"// make Manual Alloc/Free Tornado string a Tcl type\n");
  fprintf (outFile,"static Tcl_ObjType stringType = {\n"); 
  fprintf (outFile,"  \"%s_string\",\n", (char*)modName);
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)NULL,\n"); 
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n"); 
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_String,\n");
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Put_String\n");
  fprintf (outFile,"  };\n\n");

  fprintf (outFile,"// make Automatic Alloc/free Tornado string a Tcl type\n");
  fprintf (outFile,"static Tcl_ObjType stringPtrType = {\n"); 
  fprintf (outFile,"  \"%s_string_Ptr\",\n", (char*)modName);
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)Free_String,\n"); 
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n"); 
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_String,\n");
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Put_String\n");
  fprintf (outFile,"  };\n\n");

  fprintf (outFile,"\n// Build a free wrapper in order Tcl to find Tornado->wtx handle\n"); 
  fprintf (outFile,"LOCAL void freeTornadoLocal (Tcl_Obj *objPtr) {\n");
  fprintf (outFile,"  tornadoTypeFree (&tornadoInfo, objPtr);\n");
  fprintf (outFile,"}\n");

  fprintf (outFile,"\n// Build a create wrapper in order Tcl to find Tornado->wtx handle\n"); 
  fprintf (outFile,"LOCAL void createTornadoLocal (Tcl_Interp *interp\n");
  fprintf (outFile,"           ,JWRAP_structs *structure,Tcl_Obj *srcObj, Tcl_Obj *destObj) {\n");
  fprintf (outFile,"  tornadoTypeTcl2Cc (&tornadoInfo, interp,structure,srcObj,destObj);\n");
  fprintf (outFile,"}\n");

  fprintf (outFile,"\n// Build a cget wrapper in order Tcl to find Tornado->wtx handle\n"); 
  fprintf (outFile,"LOCAL void cGetTornadoLocal (Tcl_Interp *interp\n");
  fprintf (outFile,"  ,JWRAP_structs *structure,Tcl_Obj *tclObj,Tcl_Obj *slot) {\n");
  fprintf (outFile,"  tornadoTypeCget (&tornadoInfo, interp,structure,tclObj,slot);\n");
  fprintf (outFile,"}\n");

}
