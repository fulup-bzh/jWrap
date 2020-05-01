/*
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   classBackendCc2jTcl.cc C++ 2 jTcl backend class methods
 * Projet    :   Jos/jWrap
 * Module    :   jWrap C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/classBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01c,14jul98,Fulup,adapted to complex structure version
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2jTcl.h"


/**********************************************************
 ** Create a wrapping class for all virtual functions
 **********************************************************/
void BackendCc2jTcl::output (Classes* classe) {
 int   ind,jnd,knd;
 int   firstVirtual = 1;

 // reset user provided constructor flag for each new class
 constructorDone  = FALSE;

 // output one dummy method in oder returning method name directelly [gcc 2.7 bug]
 for (ind=0; ind < classe->methods.size(); ind++) {
    if ((classe->methods[ind]->visibility == PROT_PUBLIC)
        && (classe->methods[ind]->location == LOC_VIRTUAL)) {
         if (firstVirtual == 0) {
            fprintf (outFile," //bypass gcc limitation on static data\n");
            firstVirtual = 1;
         }
         fprintf (outFile,"static Tcl_Obj *tclStr_%s_%s = jWrapStringNew (\"%s\",%d);\n"
                         , (char*)classe->name, (char*)classe->methods[ind]->name
                         , (char*)classe->methods[ind]->name,classe->methods[ind]->name.size()-1);
    }
 }

 // output class header
 fprintf (outFile, "class jWrap_%s : public %s\n{\n", (char*)classe->name, (char*)classe->name);

 fprintf (outFile," private:\n");
 fprintf (outFile," Tcl_Obj    *jTclHandle;  // store jTcl instance object name\n");
 fprintf (outFile," Tcl_Interp *interp;      // Save Interp in order call jTcl from C++\n\n");
 fprintf (outFile," public: // everything else is public\n\n");

 // output class static jTcl<->c++ interface methods
 for (ind=0; ind < classe->methods.size(); ind++) {
    if (classe->methods[ind]->visibility == PROT_PUBLIC) {
         output (classe->methods [ind]);
       }
 }

 // Search for polymorph method in order building extra wrapper
 polymorphs.clear();
 for (ind=0; ind < classe->methods.size(); ind++) {
    if (classe->methods[ind]->visibility != PROT_PUBLIC) continue;

    // for each method name check used function array
    for (jnd = ind+1; jnd < classe->methods.size(); jnd++) {
       if (classe->methods[jnd]->visibility != PROT_PUBLIC) continue;

       if (!strcmp ((char*)classe->methods[ind]->name, (char*)classe->methods[jnd]->name)) {
          // before registrating check is as not already been done
          for (knd = 0; knd < polymorphs.size (); knd ++) {
            if (!strcmp ((char*)classe->methods[ind]->name, (char*) polymorphs[knd]->name)) break;
          }
          if (knd == polymorphs.size ()) {
           // we are facing a new polymorph method
           polymorphs.append (classe->methods[ind]);
         }
       } // end method is polymorph
    }
 } // end polymorph search

 // effectively build wrappers
 for (ind=0; ind < polymorphs.size(); ind++) {
    output (classe->methods, polymorphs [ind]->name);
 }

 // We need an empty constructor if no C++ exists
 if (!constructorDone) {
   fprintf (outFile," // jWrap need a constructor to register jTcl obj reference\n");
   fprintf (outFile," static jTcl_new (ClientData clData, Tcl_Interp *interp\n");
   fprintf (outFile,"           ,int objc,Tcl_Obj *CONST objv[]) {\n");

   fprintf (outFile," // tempry data for registration of CC obj handle in hashtable\n");
   fprintf (outFile," int isnew; Tcl_HashEntry *entryPtr;\n\n");

   fprintf (outFile,"\n // prepare emergency panic return\n");
   fprintf (outFile," if (setjmp (jWrapCheckPoint)) {\n");
   fprintf (outFile,"   return TCL_ERROR;\n }\n");

   fprintf (outFile,"\n // First check if params number is OK\n");
   fprintf (outFile," if (objc != 2) goto errorNumArg;\n\n");

   fprintf (outFile," // Store cc handle in hashtable with jTcl handle as key\n");
   fprintf (outFile," entryPtr = Tcl_CreateHashEntry (&jWrapHashTable");
   fprintf (outFile," ,TCL_STRING (objv[1]), &isnew);\n");
   fprintf (outFile," if (!isnew) goto errorMultiInherit;");

   fprintf (outFile," // Effectively build C++ object and store it in hashtable\n");
   fprintf (outFile," Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_%s (interp,objv[1]));\n"
                   ,(char*)classe->name);

   fprintf (outFile," return TCL_OK;\n\n");

   // Fatal error goto label
   fprintf (outFile,"\n errorNumArg:\n");
   fprintf (outFile,"  Tcl_WrongNumArgs (interp, 1, objv, \"Syntax: new %s\");\n"
                   , (char*)classe->name);
   fprintf (outFile,"  return TCL_ERROR;\n");
   fprintf (outFile,"\n errorMultiInherit:\n");
   fprintf (outFile,"  Tcl_AppendResult (interp,\"jWrap cannot multi-inherit: class %s handle=\"\n"
                   , (char*)classe->name);
   fprintf (outFile,"                   ,TCL_STRING(objv[1]),NULL);\n");
   fprintf (outFile,"  return TCL_ERROR;\n");
   fprintf (outFile, " } // end default jTcl->C++ %s constructor\n\n", (char*)classe->name);
 } // end if constructor not done

 // register C++ destructor
 fprintf (outFile," // Destructor clean up c++ object\n");
 fprintf (outFile," ~jWrap_%s () {\n",(char*)classe->name);
 fprintf (outFile,"   int status;\n");
 fprintf (outFile,"   Tcl_CmdInfo infoCmd;\n");
 fprintf (outFile,"   Tcl_Obj *resultPtr;\n");
 fprintf (outFile,"   Tcl_Obj *objv[2];\n\n");

 fprintf (outFile,"   // if called from jTcl just return\n");
 fprintf (outFile,"   if (jTclHandle == NULL) return;\n\n");

 fprintf (outFile,"   // Build jTcl free cmd\n");
 fprintf (outFile,"   objv[0] = jWrapFreeMethod;\n");
 fprintf (outFile,"   objv[1] = jTclHandle;\n\n");

 fprintf (outFile,"  // call jTcl free method\n");
 fprintf (outFile,"  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {\n");
 fprintf (outFile,"     jWrapPanic (NULL,\"Unknown jTcl %s object\",TCL_STRING (jTclHandle));\n  }\n","");
 fprintf (outFile,"   status    = (*infoCmd.objProc) (infoCmd.objClientData, interp,2,objv);\n\n");
 fprintf (outFile,"   if (status != TCL_OK) {\n");
 fprintf (outFile,"     resultPtr = Tcl_GetObjResult(interp);\n");
 fprintf (outFile,"     jWrapPanic (NULL,TCL_STRING(resultPtr));   }\n\n");

 fprintf (outFile," } // end C++ destructor\n\n");

 // register jTcl destructor
 fprintf (outFile," // jTcl destructor call C++ cleanup\n");
 fprintf (outFile," static int jTcl_free\n");
 fprintf (outFile," (ClientData clData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])\n");
 fprintf (outFile," {\n");

 // tempry location c++ object native handle value
 fprintf (outFile," Tcl_HashEntry *entryPtr;\n");
 fprintf (outFile," jWrap_%s *cxxHandle;\n", (char*)classe->name);

 fprintf (outFile,"  // prepare emergency panic return\n");
 fprintf (outFile,"  if (setjmp (jWrapCheckPoint)) {\n");
 fprintf (outFile,"     return TCL_ERROR;\n  }\n");

 // get C++ handle from hashtable
 fprintf (outFile," // get cc object handle from jTcl object name\n");
 fprintf (outFile," entryPtr = Tcl_FindHashEntry (&jWrapHashTable\n");
 fprintf (outFile,"          , TCL_STRING (objv[1]));\n");
 fprintf (outFile," if (entryPtr == NULL) {\n");
 fprintf (outFile,"  Tcl_AppendResult (interp,\"Unknown C++ Object in Hashtable handle=\"\n");
 fprintf (outFile,"                   ,TCL_STRING (objv[1]),NULL);\n");
 fprintf (outFile,"  return (TCL_ERROR);\n }\n");
 fprintf (outFile," cxxHandle= (jWrap_%s*)Tcl_GetHashValue (entryPtr);\n\n"
                      ,(char*)classe->name);

 fprintf (outFile,"  // Clean up the place and make C++ destructor not to recall jTcl\n");
 fprintf (outFile,"  Tcl_DecrRefCount(cxxHandle->jTclHandle);\n");
 fprintf (outFile,"  cxxHandle->jTclHandle = NULL;\n\n");


 fprintf (outFile,"  //effectively destroy C++ object and jTcl reference\n");
 fprintf (outFile,"  delete (cxxHandle);\n\n");
 fprintf (outFile,"  return TCL_OK;\n");
 fprintf (outFile," } // end jTcl destructor\n\n");

 // register jTcl internal constructor
 fprintf (outFile," // internal constructor register C++ handle in jTcl object\n");
 if (constructorDone) {
   fprintf (outFile," jWrap_linkObj (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)\n");
 } else {
   fprintf (outFile," jWrap_%s (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)\n"
                   ,(char*)classe->name);
 }
 fprintf (outFile," {\n");
 fprintf (outFile,"   // Store jTcl object string in C++ object\n");
 fprintf (outFile,"   Tcl_IncrRefCount (jTclObj);\n");
 fprintf (outFile,"   jTclHandle = jTclObj;\n");
 fprintf (outFile,"   interp     = objInterp;\n");

 // registrate instance variables
 for (ind = 0; ind < classe->vars.size(); ind ++) {
   // ignore any non public instance variables
   if (classe->vars[ind]->visibility != PROT_PUBLIC) continue;

   // in public variable only take instance one
   switch (classe->vars[ind]->location) {
      case LOC_GLOBAL:
      case LOC_STATIC:
	continue;  // not an instance variable
      }
    if (ind == 0) fprintf (outFile,"\n   // register instance variable in Tcl interp\n");
    registrate (classe->vars[ind]);
 }

 fprintf (outFile," } // end internal constructor\n");

 // close classe
 fprintf (outFile,"}; // end class jWrap_%s\n\n",(char*)classe->name);

} // end output classe

/**********************************************************
 ** Create a wrapping class for all virtual functions
 **********************************************************/
void BackendCc2jTcl::registrate (Classes* classe) {
 int        ind;

 // create jTcl class array
 fprintf (outFile, "\n { // registering class %s in Tcl\n", (char*)classe->name);
 fprintf (outFile
  , " Tcl_Obj *tclClassIndex;\n");
 fprintf (outFile
  , " Tcl_Obj *tclClassValue= Tcl_NewStringObj (\"%s\",%d);Tcl_IncrRefCount(tclClassValue);\n"
  , (char*) classe->name, classe->name.size()-1);
 fprintf (outFile
  , " Tcl_Obj *tclCountValue= Tcl_NewIntObj(0); Tcl_IncrRefCount(tclCountValue);\n");

 fprintf (outFile
  , " Tcl_Obj *tclClassArray= Tcl_NewStringObj (\"_C_%s\",%d);Tcl_IncrRefCount(tclClassArray);\n"
  , (char*)classe->name, classe->name.size()+2);

 fprintf (outFile
  ," Tcl_ObjSetVar2(interp,tclClassArray,jWrapMyString,tclClassValue,TCL_GLOBAL_ONLY);\n");
 fprintf (outFile
  ," Tcl_ObjSetVar2(interp,tclClassArray,jWrapExtendsString,tclClassValue,TCL_GLOBAL_ONLY);\n");

 fprintf (outFile," // build a reference Count mandatory for jTcl\n");
 fprintf (outFile
  ," Tcl_ObjSetVar2 (interp,tclClassArray,jWrapInsCountString,tclCountValue,TCL_GLOBAL_ONLY);\n");

 // before filling current class with local data take super class data if any
 if (classe->extends.size() >=1) {
   fprintf (outFile,"\n /* --- Extend Class from suppers --- */\n");

   // copy method from our super class list
   for (ind=0; ind < classe->extends.size(); ind++) {
     if (classe->extends[ind]->visibility == PROT_PUBLIC) {
        fprintf (outFile
          ," jWrapExtendClass (interp,TCL_STRING(tclClassArray), \"_C_%s\");\n"
          , (char*)classe->extends[ind]->name);
     }
   }
 }

 // each public class variable as to be registrate
 for (ind = 0; ind < classe->vars.size(); ind ++) {
    if (ind == 0) fprintf  (outFile,"\n /* --- Static Variable registration --- */\n");
    if ((classe->vars[ind]->visibility == PROT_PUBLIC)
       && (classe->vars[ind]->location == LOC_STATIC)) {
             registrate (classe->vars[ind]);
    }
 }

 // create one command for each method
 for (ind=0; ind < classe->methods.size(); ind++) {
    if (classe->methods[ind]->visibility == PROT_PUBLIC) {
         registrate (classe->methods [ind]);
       }
 }

 // registrate polymorph method
 for (ind=0; ind < polymorphs.size(); ind++) {
  if (ind == 0) fprintf (outFile," // registrate extra polymorph wrapper\n");
  fprintf (outFile
        ," Tcl_CreateObjCommand (interp,\"%s.%s\", jWrap_%s::jTcl_%s"
        , (char*)classe->name, (char*) polymorphs[ind]->name
        , (char*)classe->name,(char*)polymorphs[ind]->name);
  fprintf (outFile,"   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);\n");
 }

 fprintf (outFile,"\n // registrate constructor/destructor\n");
 if (!constructorDone) {
  fprintf (outFile
        ," Tcl_CreateObjCommand (interp,\"%s.new\", jWrap_%s::jTcl_new"
        , (char*)classe->name, (char*) classe->name);
  fprintf (outFile,"   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);\n");
 }
 fprintf (outFile
   ," Tcl_CreateObjCommand (interp,\"%s.free\", jWrap_%s::jTcl_free"
   , (char*)classe->name,(char*)classe->name);
 fprintf (outFile,"   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);\n");

 fprintf (outFile," } // end class %s registration\n", (char*)classe->name);
} // end registrate Classe


