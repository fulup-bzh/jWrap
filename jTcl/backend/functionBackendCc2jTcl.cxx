/*
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   functionBackendCc2jTcl.cc manage methods output in C++ 2 jTcl backend wrapper
 * Projet    :   Jos/jWrap
 * Module    :   backend/cc2jTcl
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/functionBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01d,20sep98,Fulup,corrected return for short and byte value
 * 01c,15jul98,Fulup,update jTcl handle usage count
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2jTcl.h"



/** ********************************************************************
 ** This Method register C++ method as TCL commands
 ***********************************************************************/
void BackendCc2jTcl::registrate (Functions* function) {
  int   len, prefix;
  char *funcname;

  fprintf (outFile,"\n // register %s C/C++ entry point as  Tcl command\n",(char*)function->name);

  // Function and Method uses different prefix
  switch (function->location) {
    case LOC_GLOBAL:
      funcname = function->name;
      // if module name is equal to start of command we remove prefix
      if (!strncasecmp ((char*)modName, funcname, modName.size()-1)) {
        prefix = modName.size()-1;
      } else {
        prefix = 0;
      }      
      fprintf (outFile
        ," Tcl_CreateObjCommand (interp,\"%s.%s\", jTcl_%s_%d"
        , (char*)modName, &funcname [prefix]
        , funcname,function->number);
      fprintf (outFile,"  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);\n");

      break;

    case LOC_AUTO:
    case LOC_VIRTUAL:
      fprintf (outFile
       ," tclClassIndex= Tcl_NewStringObj (\"%s\",%d);Tcl_IncrRefCount(tclClassIndex);\n"
       , (char*) function->name, function->name.size()-1);
        
      fprintf (outFile
       ," tclClassValue= Tcl_NewStringObj (\"%s.%s\",%d);Tcl_IncrRefCount(tclClassValue);\n"
       , (char*)function->owner->name, (char*) function->name
       , function->owner->name.size()+function->name.size()-1);
        
      fprintf (outFile
       ," Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);\n");

      fprintf (outFile
        ," Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_%s::jTcl_%s_%d"
        , (char*)function->owner->name, (char*)function->name,function->number);
      fprintf (outFile,", (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);\n\n");
      break;
    default: return;
  }
} // end registrate function

/** ********************************************************************
 ** This Method produce a dummy method that will be called from TCL
 ********************************************************************** */
void BackendCc2jTcl::output (Functions* function) {

  int ind;
  int  method;        // Method receive one more parameter
  int  varArgument = FALSE; 
  int  constructor = FALSE;

    // Function are prefixed with jTcl  method are not.
    switch (function->location) {
      case LOC_GLOBAL:
         method = 0;
         break;
      case LOC_AUTO:
      case LOC_VIRTUAL:
         method = 1;
         if (!strcmp ((char*)function->name,(char*)function->owner->name)) {
           constructor=TRUE;
           constructorDone = TRUE;
         }
         break;
      default: return;
    }

   
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
    fprintf (outFile, " static int jTcl_%s_%d (\n     "
                    ,(char*)function->name,function->number);

    // All C function are call with an argc/argv parameters like mechanism
    fprintf (outFile, "ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]");
    fprintf (outFile, ")\n {\n");

    // Where to old TCL type for TCL_OBJ to native representation
    if (function->params.size () >0) {
      fprintf (outFile," Tcl_Obj     tmpCgetObj;\n");
      fprintf (outFile," Tcl_Obj     *currentObj;\n");
      fprintf (outFile," int status;\n");
    }

    // tempry location c++ object native handle value
    if ((method) && (!constructor)) {
      fprintf (outFile," Tcl_HashEntry *entryPtr;\n");
      fprintf (outFile," jWrap_%s *objHandle;\n", (char*)function->owner->name);
    }
    
    // constructor build object and register it in hashtable
    if (constructor) {
     fprintf (outFile," // tempry data for registration of CC obj handle in hashtable\n");
     fprintf (outFile," int isnew; Tcl_HashEntry *entryPtr;\n\n");
    }

    // Allocate return entry value
    if (function->result.size() != 0) {
      fprintf (outFile, " Tcl_Obj *resultPtr;\n");
      fprintf (outFile, " struct { union {\n");
      fprintf (outFile, "   %s   appli;\n", (char*) function->result);
      fprintf (outFile, "   void *ptr;\n");
      fprintf (outFile, " } shared; }result;\n");
    }

   // Allocate each params in stack
   for (ind=0; ind < function->params.size (); ind ++) {
     if (strcmp ("...", (char*) function->params[ind]->type)) {
        fprintf (outFile, " %s param_%d;\n",(char*) function->params[ind]->type, ind);
     } else {
        // variable parameters are limitted to 10 and not typed 
        varArgument = TRUE;
        fprintf (outFile, " va_list param_%d;  // variable arguments\n", ind);
     }
   } // end for each param

   // Prepare ourself a a panic all
   fprintf (outFile,"\n // prepare emergency panic return\n");
   fprintf (outFile," if (setjmp (jWrapCheckPoint)) {\n");
   fprintf (outFile,"   if (jWrapStaticMessage[0] != '\\0') {\n");
   fprintf (outFile,"     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);\n");
   fprintf (outFile,"   }\n   return TCL_ERROR;\n }\n"); 

    // In C++ we have to look for C++ object handle
    if ((method) && (!constructor)) {
      fprintf (outFile,"\n // First check if params number is OK\n");
      fprintf (outFile," if (objc != %d) goto errorNumArg;\n\n"
                      , function->params.size()+method+1);

      // get C++ handle from hashtable
      fprintf (outFile," // get cc object handle from jTcl object name\n");
      fprintf (outFile," entryPtr = Tcl_FindHashEntry (module.hashTable\n");
      fprintf (outFile,"          , TCL_STRING (objv[1]));\n");
      fprintf (outFile," if (entryPtr == NULL) {\n");
      fprintf (outFile,"  Tcl_AppendResult (interp,\"Unknown C++ Object in Hashtable index=\"\n");
      fprintf (outFile,"                   ,TCL_STRING (objv[1]),NULL);\n");
      fprintf (outFile,"  return (TCL_ERROR);\n }\n");
      fprintf (outFile," objHandle= (jWrap_%s*)Tcl_GetHashValue (entryPtr);\n\n"
                      ,(char*)function->owner->name);
    } // end if method

  fprintf (outFile,"\n // Check param number\n");
  fprintf (outFile," if (objc != %d) goto  errorNumArg;\n\n"
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
    fprintf (outFile," if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){\n");
    fprintf (outFile,"   status = ((Function*)usedType[JTYPE_%s].obj->setFromAnyProc)\n"
                    ,jWrapType(&function->params [ind]->type));
    fprintf (outFile,"            (interp, currentObj,NULL);\n");

    fprintf (outFile,"   if (status != TCL_OK) return status;\n");
    fprintf (outFile,"   currentObj->typePtr = usedType[JTYPE_%s].obj;\n"
                    , jWrapType(&function->params [ind]->type));
    fprintf (outFile," } else if (currentObj->typePtr->updateStringProc\n");
    fprintf (outFile,"  != usedType[JTYPE_%s].obj->updateStringProc) {\n"
                     , jWrapType(&function->params [ind]->type)); 
    fprintf (outFile,"  jWrapPanic (interp,errTypeFmt");
    fprintf (outFile,"  ,%d,currentObj->typePtr->name,usedType[JTYPE_%s].obj->name);\n }\n"
	    ,ind,jWrapType(&function->params [ind]->type));

    if (strcmp ("...",(char*)function->params [ind]->type)) {
      fprintf (outFile,"  param_%d = *(%s*)&currentObj->internalRep;\n\n"
                      , ind, (char*)function->params [ind]->type) ;
    } else {
      fprintf (outFile,"  // dynamic argument lenght\n");
      fprintf (outFile,"  param_%d = *(va_list*)&currentObj->internalRep;\n\n", ind) ;
    }
   } // end for each param

   // Class or super class with our parameters
   if (constructor) {
     fprintf (outFile," // Store cc handle in hashtable with jTcl handle as key\n");
     fprintf (outFile," entryPtr = Tcl_CreateHashEntry (module.hashTable\n");
     fprintf (outFile,"          , TCL_STRING (objv[1]), &isnew);\n");
     fprintf (outFile," if (!isnew) goto errorMultiInherit;");

     fprintf (outFile," // Effectively build C++ object and store it in hashtable\n");
     fprintf (outFile," Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_%s ("
                     ,(char*)function->owner->name);
     fprintf (outFile,"interp,objv[1]");
     if (function->params.size() >0) fprintf (outFile,",");
   } else {

     fprintf (outFile," // effectively call C++ function/method\n");
     if (function->result.size() != 0) {
        fprintf (outFile, " result.shared.appli = ");
     } 

     // call super class or C++ global function with a cast to jWrap super class
     if (method) {
       fprintf (outFile," objHandle->%s::%s ("
                       ,(char*)function->owner->name, (char*) function->name);
     } else {
       fprintf (outFile," %s (",(char*)function->name);
     }
   } // end if constructor

   for (ind=0; ind < function->params.size (); ind ++) {
     if (ind != 0) fprintf (outFile, ", ");
     fprintf (outFile, "param_%d",ind);

   } // end for each param
   if (constructor) fprintf (outFile,")");
   fprintf (outFile, ");\n\n");

   // translate return status
   if (function->result.size() != 0) {
     fprintf (outFile," resultPtr = Tcl_GetObjResult (interp);\n");
     fprintf (outFile," // copy result in Tcl internal value without checking it\n");
     fprintf (outFile," resultPtr->internalRep.longValue = 0;\n");
     fprintf (outFile," *(%s*)&resultPtr->internalRep = result.shared.appli;\n"
                     , (char*)function->result);
     fprintf (outFile," resultPtr->bytes = NULL;\n");
     fprintf (outFile," resultPtr->typePtr = usedType[JTYPE_%s].obj;\n"
                       , jWrapType (&function->result)); 
   } // end if result.size != 0
     
   // in any other case our command succeeded
   fprintf (outFile," return TCL_OK;\n");
  
   // Fatal error goto label
   if (constructor) {
     fprintf (outFile,"\n errorMultiInherit:\n");
     fprintf (outFile,"  Tcl_AppendResult (interp,\"jWrap cannot multi-inherit: class %s handle=\"\n", (char*)function->owner->name);
     fprintf (outFile,"                   ,TCL_STRING(objv[1]),NULL);\n");
     fprintf (outFile,"  return TCL_ERROR;\n"); 
   }
   fprintf (outFile,"\n errorNumArg:\n");
   fprintf (outFile,"  Tcl_WrongNumArgs (interp,1,objv, helpCmd[%d]);\n",function->number);
   fprintf (outFile,"  return TCL_ERROR;\n");
   fprintf (outFile, " } // end method jWrap_%s%d\n\n",(char*)function->name,function->number);

  /** -------------------------------------------------------------------
   **   Build CC++ -> jTcl interface with a virtual class
   ** -------------------------------------------------------------------*/

   // When constructor as parameter it as to be provided explicitelly
   if (constructor) {
    fprintf (outFile," // Pass input pattern to our super class\n");
    fprintf (outFile," jWrap_%s::jWrap_%s (Tcl_Interp *interp, Tcl_Obj *jTclObj",(char*)function->name, (char*) function->name);
    // print all parameters types (warning last param as no comma
    for (ind=0; ind < function->params.size (); ind ++)
    {	
      fprintf (outFile, ",%s param_%d", (char*) function->params [ind]->type, ind);
    } // end for each param
    // print super class constructor call
    fprintf (outFile,") : %s::%s (",(char*)function->name, (char*) function->name);
    for (ind=0; ind < function->params.size (); ind ++) {
      if (ind != 0) fprintf (outFile, ", ");
      fprintf (outFile, "param_%d",ind);
    } // end for each param
   fprintf (outFile,") {\n");
   fprintf (outFile,"    jWrap_linkObj (interp, jTclObj);\n");  
   fprintf (outFile," }\n\n"); 
   } // end if constructor

   // if method is virtual then we also need c++->jTcl binding
   if (function->location != LOC_VIRTUAL) return;

   fprintf (outFile," // Interface C++ -> jTcl for %s C++ method\n",
            (char*)function->name);

   // print result type with method name
   fprintf (outFile, " virtual %s %s (", (char*)function->result, (char*)function->name);

   // print all parameters types (warning last param as no comma
   for (ind=0; ind < function->params.size (); ind ++)
   {	
     if (ind != 0) fprintf (outFile, ", ");
     fprintf (outFile, "%s param_%d", (char*) function->params [ind]->type, ind);

   } // end for each param
   fprintf (outFile,")\n {\n");

   // Allocate return entry value
   if (function->result.size() != 0) {
     fprintf (outFile," Tcl_Obj tmpCgetObj;\n");
     fprintf (outFile," Tcl_Obj *currentObj;\n");
     fprintf (outFile, "%s result;\n", (char*) function->result);
   }

   // Allocate an array of Tcl Object for Tcl evaluation
   fprintf (outFile," Tcl_CmdInfo infoCmd;\n");
   fprintf (outFile," Tcl_Obj *objv[%d],*resultObj;\n",  function->params.size ()+2);
   fprintf (outFile," int     status;\n");

   // translate c++ native params to TCL object
   fprintf (outFile," // Build jTcl cmd start with proc_name + jtcl_obj + method_name\n");
   fprintf (outFile," objv[0] = jTclHandle;\n");
   fprintf (outFile," objv[1] = tclStr_%s_%s;\n\n"
                   ,(char*)function->owner->name,(char*)function->name);

   fprintf (outFile," // Translate params from C++ native to Tcl object\n");
   for (ind=0; ind < function->params.size (); ind ++) {
      fprintf (outFile," objv[%d] = Tcl_NewObj();\n", ind+2);
      fprintf (outFile," objv[%d]->bytes = NULL;\n",ind+2);
      fprintf (outFile," objv[%d]->typePtr = usedType [JTYPE_%s].obj;\n"
                      , ind+2, jWrapType (&function->params [ind]->type));
      fprintf (outFile," objv[%d]->internalRep.otherValuePtr = (void*) param_%d;\n"
                      , ind+2,ind);
      fprintf (outFile," Tcl_IncrRefCount(objv[%d]);\n",ind+2);

 } // end for each param

 fprintf (outFile,"  // call jTcl free method\n"); 
 fprintf (outFile,"  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {\n");
 fprintf (outFile,"     jWrapPanic (NULL,\"Unknown jTcl %s object\",TCL_STRING (jTclHandle));\n  }\n","");  
 fprintf (outFile,"  status = (*infoCmd.objProc) (infoCmd.objClientData, interp,%d,objv);\n\n"
                 ,function->params.size()+2);
 fprintf (outFile,"  if (status != TCL_OK) jWrapPanic (NULL,\"jTcl Method %s failed\");\n\n"
                 , (char*)function->name );

 // if C++ wait for a param we pass it back WARNING: ho to free result ???
 if (function->result.size() != 0) {
    fprintf (outFile," resultObj = Tcl_GetObjResult(interp);\n");
    fprintf (outFile," // convert to our wanted application type\n");
    fprintf (outFile," if (resultObj->typePtr == &jWrapTypeTclObj) {\n");
    fprintf (outFile,"   JWRAP_cgets* cget;\n");
    fprintf (outFile,"   cget = (JWRAP_cgets*)resultObj->internalRep.twoPtrValue.ptr1;\n");
    fprintf (outFile,"   // create a tempry object with cget slot\n");
    fprintf (outFile,"   tmpCgetObj.bytes   = resultObj->bytes;\n");
    fprintf (outFile,"   tmpCgetObj.length  = resultObj->length;\n");
    fprintf (outFile,"   tmpCgetObj.typePtr = cget->type;\n");
    fprintf (outFile,"   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;\n");
    fprintf (outFile,"   currentObj    = &tmpCgetObj;\n");
    fprintf (outFile," } else {\n");
    fprintf (outFile,"   currentObj  = resultObj;\n");
    fprintf (outFile," }\n");

    fprintf (outFile," // convert to our wanted application type\n");
    fprintf (outFile," if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){\n");
    fprintf (outFile,"   status = ((Function*)usedType[JTYPE_%s].obj->setFromAnyProc)\n"
                    ,jWrapType(&function->result));
    fprintf (outFile,"            (interp, currentObj,NULL);\n");

    fprintf (outFile,"   if (status != TCL_OK) return status;\n");
    fprintf (outFile,"   currentObj->typePtr = usedType[JTYPE_%s].obj;\n"
                    , jWrapType(&function->result));
    fprintf (outFile," } else if (currentObj->typePtr->updateStringProc\n");
    fprintf (outFile,"  != usedType[JTYPE_%s].obj->updateStringProc) {\n"
                     , jWrapType(&function->result)); 
   fprintf (outFile,"  jWrapPanic (interp,errTypeFmt");
   fprintf (outFile,"  ,%d,currentObj->typePtr->name,usedType[JTYPE_%s].obj->name);\n }\n"
	    ,ind,jWrapType(&function->result));

    fprintf (outFile,"  result = *(%s*)&currentObj->internalRep;\n\n"
                    , (char*)function->result) ;

    // free all tempry input parameter Tcl variables
    for (ind=0; ind < function->params.size (); ind ++) {
      fprintf (outFile," // make sure Tcl GC won't delete internal rep\n"); 
      fprintf (outFile," objv[%d]->typePtr = NULL;\n",ind+2); 
      fprintf (outFile," Tcl_DecrRefCount (objv[%d]);\n",ind+2); 
    }
    fprintf (outFile," return result;\n");

 } else {
    // free all tempry input parameter Tcl variables
    for (ind=0; ind < function->params.size (); ind ++) {
      fprintf (outFile," // make sure Tcl GCwon't delete internal rep\n"); 
      fprintf (outFile," objv[%d]->typePtr = NULL;\n",ind+2); 
      fprintf (outFile," Tcl_DecrRefCount (objv[%d]);\n",ind+2); 
    }

    fprintf (outFile," return;\n");
 } // if result required by c++

 fprintf (outFile," } // end method %s\n\n", (char*)function->name);       

} // end output function

/**********************************************************
 ** Create an extra wrapper for polymorph methods
 **********************************************************/
void BackendCc2jTcl::output (McDArray<Functions*>methods, char *name) {
  const int PRM_MAX=32;
  int ind,jnd,knd;
  Functions *method;
  McDArray<Functions*> polymorph;
  McDArray<Functions*> polymorphs[PRM_MAX]; // A function can have up to 32 params
  
    fprintf (outFile," // Extra wrapper for polymorph function %s\n", name);

    // print result type with method name
    fprintf (outFile, " static int jTcl_%s (\n",name);

    // All C function are call with an argc/argv parameters like mechanism
    fprintf (outFile, "  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]");
    fprintf (outFile, " )\n {\n");

    // In C++ we have to look for C++ object handle
    fprintf (outFile,"\n // First check if params number is OK\n");
    fprintf (outFile," switch (objc) {\n");

    // Search for polypmorph method
    for (ind=0; ind <methods.size(); ind++) {
      method = methods[ind]; 
      if (!strcmp (name, (char*)method->name)) {
        // we are facing polymorph function
        if (method->params.size() >= PRM_MAX) {
         fprintf (stderr, "WARNING: method:%s >= %d prm ignored\n%s\n"
                        , name,PRM_MAX,(char*)method->help); 
        } else {
          // if number > 1 we have to check type in order solving polymorphism
          polymorphs [method->params.size()].append (method);
        }
      }
    } // end for ind

    // loop on polymorph methods
    for (ind=0; ind < PRM_MAX; ind++) {
      // if no polymorh fonction for this prmCount move to next slot  
      if (polymorphs[ind].size () == 0) continue; 

      // We have polyporh methods
      fprintf (outFile,"  case %d: \n",ind+2);

      // If more than one method with current prmSize add a type check
      if  (polymorphs[ind].size() == 1) {       
          fprintf (outFile,"    return ( jWrap_%s::jTcl_%s_%d (cld, interp, objc, objv));\n"
                          ,(char*)method->owner->name, name, polymorphs[ind] [0]->number);
      } else {
        // loop on all polymorh methods with current prm count
	fprintf (outFile,"  // Check internal type before calling methods\n");
        polymorph = polymorphs[ind];
        for (jnd = 0; jnd < polymorph.size() ; jnd ++) {
          method = polymorph [jnd];
	  fprintf (outFile,"  if (\n");
	  for (knd=0; knd <method->params.size(); knd ++) {
              if (knd != 0) fprintf (outFile,"     && ");
              fprintf (outFile," ((objv[%d]->typePtr == usedType[JTYPE_%s].obj)\n"
                      ,knd+2,jWrapType(&method->params [knd]->type));
              fprintf (outFile," ||((objv[%d]->typePtr == &jWrapTypeTclObj)\n",knd+2);
              fprintf (outFile," &&(((JWRAP_cgets*)(objv[%d]->internalRep.otherValuePtr))->owner->typePtr\n",knd+2);
              fprintf (outFile,"            == usedType[JTYPE_%s].obj)))\n"
                      ,jWrapType(&method->params [knd]->type));
	  }
          fprintf (outFile,"   ) return ( jWrap_%s::jTcl_%s_%d (cld, interp, objc, objv));\n"
                          ,(char*)method->owner->name, name, method->number);
        } // end jnd
        fprintf (outFile,"\n // no method fit this prm count\n");
        fprintf (outFile
         ,"  Tcl_AppendResult (interp,\"ERROR: %s polymorph with %d prm method should be:\\n\"\n"
         ,name,ind);

        for (knd=0; knd <polymorph.size(); knd++) {
          method = polymorph [knd];
          fprintf (outFile,"    ,\"- \", helpCmd [%d],\"\\n\"\n",method->number);
        } // end for knd
        fprintf (outFile,"    ,NULL);\n");
        fprintf (outFile,"   return TCL_ERROR; // end case %d\n",ind+2); 
      } // end polymorh.size == 1
    } // end for ind 
    fprintf (outFile,"  }; // end switch\n");

    // any other value is a syntax error
    fprintf (outFile,"\n // Any other case is an error\n"); 
    fprintf (outFile," Tcl_AppendResult (interp,\"ERROR: %s polymorph method available signatures:\\n\"\n",name);
    for (ind=0; ind <methods.size(); ind++) {
      method = methods[ind]; 
      if (!strcmp (name, (char*)method->name)) {
        fprintf (outFile,"  ,\"- \", helpCmd [%d],\"\\n\"\n",method->number);
      }
    }
    fprintf (outFile,"  ,NULL);\n");
    fprintf (outFile," return TCL_ERROR;\n } //end polymorph %s\n\n",name); 
} // end output polymorph extra wrapper


