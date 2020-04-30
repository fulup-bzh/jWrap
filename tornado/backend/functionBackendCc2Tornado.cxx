/**
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   functionBackendCc2Tornado.cc manage methods output in C++ 2 jTcl backend wrapper
 * Projet    :   jWrap
 * Module    :   WTX VxWorks Troando C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/backend/functionBackendCc2Tornado.cxx,v $
 *
 * Modification History
 * --------------------
 * 01c,16feb99,Fulup,remanced modulefrom TORNADO to Tornado
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2Tornado.h"


/** ********************************************************************
 ** This Method produce a dummy method that will be called from TCL
 ********************************************************************** */
void BackendCc2Tornado::output (Functions* function) {

  int ind;
  int  method=0;      // Method receive one more parameter

   
   /** -----------------------------------------------------------------------
    **  We first build jTcl->c++ binding this is done for any public methods
    ** -----------------------------------------------------------------------*/

    // for TCL mapping void function are equivalent to no param functions
    if ((function->result[0]== '\0') || (!strcmp ("void", (char*)function->result))) {
         function->result.resize(0);
    }

    fprintf (outFile," // Interface jTcl to C++ for public %s C/C++ function/method\n",
            (char*)function->name);
    // print result type with method name
    fprintf (outFile, " static int jTcl_%s_%d (\n"
                    ,(char*)function->name,function->number);

    // All C function are call with an argc/argv parameters like mechanism
    fprintf (outFile, "  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]");
    fprintf (outFile, ")\n {\n");

    // Where to old TCL type for TCL_OBJ to native representation
    if (function->params.size ()  > 0) {
      fprintf (outFile," int status;\n");
      fprintf (outFile," Tcl_Obj *currentObj;\n");
      fprintf (outFile," Tcl_Obj tmpCgetObj;\n");
    }
    if (function->result.size ()  != 0) {
      fprintf (outFile," Tcl_Obj *resultPtr;\n");
    }
    // Allocate return entry value
    fprintf (outFile, " void  *result;\n");

   // Prepare ourself a a panic all
   fprintf (outFile,"\n // prepare emergency panic return\n");
   fprintf (outFile," if (setjmp (jWrapCheckPoint)) {\n");
   fprintf (outFile,"   if (jWrapStaticMessage[0] != '\\0') {\n");
   fprintf (outFile,"     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);\n");
   fprintf (outFile,"   }\n   return TCL_ERROR;\n }\n"); 

   // Check param number
   fprintf (outFile,"\n // First check if params number is OK\n");
   fprintf (outFile," if (objc != %d) goto errorNumArg;\n\n"
                      , function->params.size()+method+1);
 
  // translate each time in corresponding type value
  for (ind=0; ind < function->params.size (); ind ++) {
    fprintf (outFile," // Check for user application object\n");
    fprintf (outFile," if (objv[%d]->typePtr == &jWrapTypeTclObj) {\n",ind+method+1);
    fprintf (outFile,"   JWRAP_cgets* cget;\n");
    fprintf (outFile,"   cget = (JWRAP_cgets*)objv[%d]->internalRep.twoPtrValue.ptr1;\n"
                    ,ind+method+1);
    fprintf (outFile,"   // create a tempry object with cget slot\n");
    fprintf (outFile,"   tmpCgetObj.bytes   = objv[%d]->bytes;\n",ind+method+1);
    fprintf (outFile,"   tmpCgetObj.length  = objv[%d]->length;\n",ind+method+1);
    fprintf (outFile,"   tmpCgetObj.typePtr = cget->type;\n");
    fprintf (outFile,"   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;\n");
    fprintf (outFile,"   currentObj    = &tmpCgetObj;\n");
    fprintf (outFile," } else {\n");
    fprintf (outFile,"   currentObj  = objv[%d];\n",ind+method+1);
    fprintf (outFile," }\n");

    fprintf (outFile," // convert to our wanted application type\n");
    fprintf (outFile," if (currentObj->typePtr == NULL) {\n");
    fprintf (outFile,"   status = ((Function*)usedType[JTYPE_%s].obj->setFromAnyProc)\n"
                    ,jWrapType(&function->params [ind]->type));
    fprintf (outFile,"            (interp, currentObj, NULL);\n");

    fprintf (outFile,"   if (status != TCL_OK) return status;\n");
    fprintf (outFile,"   currentObj->typePtr = usedType[JTYPE_%s].obj;\n"
                    , jWrapType(&function->params [ind]->type));
    fprintf (outFile," } else if (currentObj->typePtr->updateStringProc\n");
    fprintf (outFile,"     != usedType[JTYPE_%s].obj->updateStringProc) {\n"
                     , jWrapType(&function->params [ind]->type)); 
   fprintf (outFile,"  jWrapPanic (interp,errTypeFmt");
   fprintf (outFile,"  ,%d,currentObj->typePtr->name,usedType[JTYPE_%s].obj->name);\n }\n"
	    ,ind,jWrapType(&function->params [ind]->type));

   fprintf (outFile,"  wtxCtx[%d].args[%d] = (TGT_ARG_T)currentObj->internalRep.longValue;\n  "
                    ,function->number, ind) ;

   } // end for each param


   fprintf (outFile," // effectivelly call routine on target\n");
   fprintf (outFile," result = tornadoExecFuncCall (&tornadoId, &wtxCtx[%d]);\n\n",function->number);

   // translate return status
   if (function->result.size() != 0) {
     fprintf (outFile," resultPtr = Tcl_GetObjResult (interp);\n");
     fprintf (outFile," // copy result in Tcl internal value without checking it\n");
     fprintf (outFile," resultPtr->internalRep.twoPtrValue.ptr1 = result;\n");
     fprintf (outFile," resultPtr->bytes = NULL;\n");
     fprintf (outFile," resultPtr->typePtr = usedType[JTYPE_%s].obj;\n"
                       , jWrapType (&function->result)); 
   } // end if result.size != 0
          
   // in any other case our command succeeded
   fprintf (outFile," return TCL_OK;\n");
  
   fprintf (outFile,"\n errorNumArg:\n");
   fprintf (outFile,"  Tcl_WrongNumArgs (interp,1,objv, helpCmd[%d]);\n",function->number);
   fprintf (outFile,"  return TCL_ERROR;\n");

   fprintf (outFile, " } // end jWrap_%s%d\n\n",(char*)function->name,function->number);
} // end output function


