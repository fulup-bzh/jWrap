/*
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   programBackendCc2Tornado
 * Projet    :   jWrap
 * Module    :   Tornado Wtx/Tornado VxWorks interface
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/backend/programBackendCc2Tornado.cxx,v $
 *
 * Modification History
 * --------------------
 * 01c,16feb99,Fulup,make tornado a module added protection agin multi init
 * 01b,20sep98,Fulup,reverse union and section order
 * 01a,28may98,Fulup,written
 */

#include <stdio.h>
#include <ctype.h> 

#include "libBackendCc2Tornado.h"

/******************************************************************************
 *** Effectively build C++ jTcl wrapper 
 ******************************************************************************/

void BackendCc2Tornado::output (Programs *program) {
  int ind,jnd,knd;
  McString enumDefine;
  int usedType=0;  // number of different type in module
  char initName [55];
  
  // start printing an information header
  fprintf (outFile,"\n/*  ----------------------------------------------------------");
  fprintf (outFile,"\n *   File: %s %s",(char*)outName,(char*)program->help);
  fprintf (outFile,"\n *   This file was automatically generated with");
  fprintf (outFile,"\n *   jWrap (C)FRIDU a Free Software Company 97-98");
  fprintf (outFile,"\n *   the %s\n",getDate()); 
  fprintf (outFile,"\n *   jWrap --cc2tornado %s\n *", (char*)program->name);
  fprintf (outFile,"\n *   WARNING: Except if you really know what you are doing"); 
  fprintf (outFile,"\n *   you should not edit this file by hand.");
  fprintf (outFile,"\n *");
  fprintf (outFile,"\n *   In order finding jWrap check: http://www.fridu.bzh");   
  fprintf (outFile,"\n + ------------------------------------------------------------ */\n\n");

  // printout assert for jWrap proto extraction
  fprintf (outFile,"#ifndef EASYC_PROTO_ONLY\n");
  fprintf (outFile,"#define EASYC_PROTO_ONLY\n");
  fprintf (outFile,"#endif\n");

  // include mandatory jWrap header 
  fprintf (outFile,"#define JWRAP_CC2TORNADO\n");

  fprintf (outFile, "\n#include \"libRuntimeTornado.h\"\n");

  // program original header c or c++
  if (inName.size() > 1) {
    fprintf (outFile, "#include \"%s\"\n", (char*)inName);
  }

  fprintf (outFile,"\n#define JWRAP_CC2JTCL\n");
  fprintf (outFile,"#ifndef %s_CUSTOM_STAMP\n", (char*)modName);
  fprintf (outFile," #ifdef FRIDU\n");
  fprintf (outFile," #define %s_CUSTOM_STAMP &vStamp_lib%s[12]\n",(char*)modName,(char*)modName);
  fprintf (outFile," #else\n");
  fprintf (outFile," #define %s_CUSTOM_STAMP NULL\n",(char*)modName);
  fprintf (outFile," #endif\n");
  fprintf (outFile,"#endif\n\n");

  fprintf (outFile,"// Special Tornado-Tornado defines for overloading jWrap type translation\n");
  fprintf (outFile," #define jWrapTypeTcl2Cc(P1,P2,P3,P4) tornadoTypeTcl2Cc(&tornadoInfo,P1,P2,P3,P4)\n");
  fprintf (outFile," #define jWrapTypeUpdate(P1,P2,P3,P4)");
  fprintf (outFile,"  tornadoTypeUpdate(&tornadoInfo,P1,P2,P3,P4)\n");
  fprintf (outFile," #define jWrapTypeCc2Tcl(P1,P2)       tornadoTypeCc2Tcl(&tornadoInfo,P1,P2)\n");
  fprintf (outFile," #define jWrapTypeClean               tornadoTypeClean\n");
  fprintf (outFile," #define jWrapTypeFree                freeTornadoLocal\n");
  fprintf (outFile," #define JWRAP_CREATE_FUNC            createTornadoLocal\n");
  fprintf (outFile," #define JWRAP_FREE_FUNC              freeTornadoLocal\n");
  fprintf (outFile," #define JWRAP_CGET_FUNC              cGetTornadoLocal\n");
  fprintf (outFile," #define jWrapVarRegister(P1,P2,P3,P4,P5,P6)");
  fprintf (outFile," tornadoVarRegister(&tornadoInfo,P1,P2,P3,P5,P6)\n");

  fprintf (outFile," // do we use wtx or VxWorks malloc ?\n");
  fprintf (outFile," #ifdef USE_TARGET_MALLOC\n");
  fprintf (outFile," #define tornadoTypeFree     tornadoTargetTypeFree\n");
  fprintf (outFile," #define tornadoStringFree   tornadoTargetStringFree\n");
  fprintf (outFile," #define tornadoTypeTcl2Cc   tornadoTargetTypeTcl2Cc\n");
  fprintf (outFile," #define tornadoStringTcl2Cc tornadoTargetStringTcl2Cc\n");
  fprintf (outFile," #endif\n");
  

  fprintf (outFile,"\n // Build module static informations\n");
  fprintf (outFile," static JWRAP_modules module;\n");
  fprintf (outFile," static int initDone=0;\n");
  fprintf (outFile," static TORNADO_infos tornadoInfo;\n");
  fprintf (outFile," static TORNADO_id    tornadoId;\n");
  fprintf (outFile," static char *errTypeFmt=\"param:%%d type [%%s] not equivalent to [%%s]\\n\";\n");

  // register all stanard special to tornado types as char*
  tornadoTypeStdMap();

  // Currentelly C++ is not supported with Tornado backend
  if ( program->classes.size() > 0) goto errCPlusPlus;

  // If we have define register dummy Define type
  if (program->defines.size() >0 ) {
     enumDefine =  "Define_";
     enumDefine += modName;

     registerType (&enumDefine,-1,TYPE_NATIVE);
  }
  // Scan all command in order building enum command name, command help array, and type enum
  for (ind=0; ind < program->vars.size(); ind ++) {
     registerType (&program->vars[ind]->type,program->vars[ind]->array,TYPE_NATIVE);
  }
  for (ind=0; ind < program->structs.size(); ind ++) {
    registerType (&program->structs[ind]->name,-1,TYPE_STRUCT);
    for (knd =0; knd < program->structs[ind]->elements.size(); knd ++) {
      registerType (&program->structs[ind]->elements[knd]->type
                   ,program->structs[ind]->elements[knd]->array, TYPE_NATIVE);
    } 
  }
  for (ind=0; ind < program->unions.size(); ind ++) {
    registerType (&program->unions[ind]->name,-1,TYPE_UNION);
    for (knd =0; knd < program->unions[ind]->elements.size(); knd ++) {
      registerType (&program->unions[ind]->elements[knd]->type
                   ,-1,TYPE_NATIVE);
    } 
  }
  for (ind=0; ind < program->enums.size(); ind ++) {
    registerType (&program->enums[ind]->name,-1,TYPE_ENUM);
  }

  for (ind=0; ind < program->functions.size(); ind ++) {
    Functions* function;
    function = program->functions[ind];
    usedCmd.append (function);
    registerType (&function->result,-1,TYPE_NATIVE);
   
    for (jnd=0; jnd < function->params.size(); jnd++) {
     registerType (&function->params[jnd]->type,-1,TYPE_NATIVE);
    }
  } // end for ind


 // we now know used type array size
  fprintf (outFile," static JWRAP_types usedType [%d];\n",cTypes.size());  

  // We print an enumeration in order program to used symbolic name for type
  fprintf (outFile,"\n // Build used type enumeration\n");
  fprintf (outFile," enum enumType {\n   ");
  for (ind=0; ind < cTypes.size(); ind++) {
    if (ind != 0) fprintf (outFile, "  ,"); 
    fprintf (outFile,"JTYPE_%-25s = %d\n", jWrapType (cTypes [ind]->name), ind);
  }
  fprintf (outFile," }; // end of usedType enumeration\n");

  // Command help is a static array of string with one line of help for each command
  fprintf (outFile,"\n // Build used commands arrays\n");
  fprintf (outFile," static WTX_CONTEXT_DESC wtxCtx [%d];\n",usedCmd.size()); 
  fprintf (outFile," static char *helpCmd[] = {\n");
  // each module as at least module management command
  for (ind=0; ind < usedCmd.size(); ind++) {
    usedCmd [ind]->number = ind;
    fprintf (outFile,"   \"%s\",\n",(char*)usedCmd[ind]->help);
  }
  fprintf (outFile," NULL\n }; // end of helpCmd array\n");

  fprintf (outFile," static char *nameCmd[] = {\n");
  for (ind=0; ind < usedCmd.size(); ind++) {
    usedCmd [ind]->number = ind;
    fprintf (outFile,"   \"%s\",\n",(char*)usedCmd[ind]->name);
  }
  fprintf (outFile," NULL\n }; // end of nameCmd array\n");

  if (program->defines.size() > 0) {
     fprintf (outFile,"\n\n/* *** Define Section *** */\n\n");
     BackendCc2jTcl::output (&enumDefine, program->defines);
  }
 
  for (ind=0; ind < program->enums.size(); ind ++) {
     if(ind ==0)  fprintf (outFile,"\n\n/* *** Enumeration Section *** */\n\n");
     BackendCc2jTcl::output (program->enums[ind]);
  }

  // prepare an array to old enumeration references for jWrap cmd
  if ((program->defines.size() + program->enums.size())> 0) {
    fprintf (outFile,"\n // Hold Defines & Enum reference for jWrap struct help cmd\n"); 
    fprintf (outFile," static JWRAP_enums *enumerations[]={\n");
    if (program->defines.size() > 0) {
      fprintf (outFile,"  &%s_enum,\n",(char*)enumDefine);
    }
    for (ind=0; ind < program->enums.size (); ind ++) {
      fprintf (outFile,"  &%s_enum,\n", (char*)program->enums [ind]->name);
    }
    fprintf (outFile,"  NULL\n };\n");
  }

  // output structure union and typedef
  for (ind=0; ind < program->unions.size (); ind ++) {
    if (ind == 0) fprintf (outFile," \n/* *** Unions Section *** */\n\n");
    BackendCc2jTcl::output   (program->unions [ind]);
  }

  for (ind=0; ind < program->structs.size (); ind ++) {
    if (ind == 0) fprintf (outFile," \n/* *** Structure Section *** */\n");
    BackendCc2jTcl::output  (program->structs [ind]);
  }

  // prepare an array to hold module structures
  if ((program->structs.size()+program->unions.size())>0) {
    fprintf (outFile,"\n // Hold structure & unions reference for jWrap struct help cmd\n"); 
    fprintf (outFile," static JWRAP_structs *structures[]={\n");
    for (ind=0; ind < program->structs.size (); ind ++) {
      fprintf (outFile,"  &%s_struct,\n", (char*)program->structs [ind]->name);
    }
    for (ind=0; ind < program->unions.size (); ind ++) {
      fprintf (outFile,"  &%s_union,\n", (char*)program->unions [ind]->name);
    }
    fprintf (outFile,"  NULL\n };\n");
  }
  
  for (ind=0; ind < program->functions.size(); ind ++) {
    if (ind == 0)  fprintf (outFile,"\n/* *** Functions Section *** */\n\n");
    output (program->functions[ind]);
  }

  fprintf (outFile,"\n/* ***  Tcl Register Section *** */\n");
  fprintf (outFile,"#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
  // set First char as upper & removed any uppercase in midle of name for windows
  strcpy (initName, modName);
  initName [0] = toupper (  initName [0]);
  for (ind=1; initName[ind] != '\0'; ind++) {
    initName [ind] = tolower (initName [ind]);
  }

  fprintf (outFile,"\n/* ***  Tcl Register Section *** */\n");
  fprintf (outFile,"#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
  fprintf (outFile,"PUBLIC int %s_Init (Tcl_Interp *interp) {\n", (char*)initName);

  fprintf (outFile," // Dont init twice\n");
  fprintf (outFile," if (initDone) return TCL_OK;\n");
  fprintf (outFile," initDone = 1;\n");

  fprintf (outFile,"\n /* --- Build module handle & register it in jWrap --- */\n\n");
  fprintf (outFile," tornadoInfo.magic         = TORNADO_INFO_MAGIC;\n");
  fprintf (outFile," tornadoInfo.wtxCtx        = wtxCtx;\n");
  fprintf (outFile," tornadoInfo.nameCmd       = nameCmd;\n");
  fprintf (outFile," tornadoInfo.tornadoId         = &tornadoId;\n");
  fprintf (outFile," tornadoInfo.stringType    = &stringPtrType;\n");
  fprintf (outFile," tornadoInfo.tornadoFree       = (void*)freeTornadoLocal;\n");

  fprintf (outFile,"\n module.magic        = JWRAP_MODULE;\n");
  fprintf (outFile," module.name           = \"%s\";\n", (char*)modName);
  fprintf (outFile," module.help           = \"%s\";\n", (char*)program->help); 
  fprintf (outFile," module.helpCmd        = helpCmd;\n"); 
  fprintf (outFile," module.nbCmd          = %d;\n", usedCmd.size());
  fprintf (outFile," module.hashTable      = NULL;\n");
  fprintf (outFile," module.version        = %s_CUSTOM_STAMP;\n",(char*)modName);
  if ((program->structs.size() >0) || (program->unions.size()>0)) {
    fprintf (outFile," module.structures   = structures;\n");
  } else {
    fprintf (outFile," module.structures   = NULL;\n");
  }
  if ((program->defines.size() >0) || (program->enums.size()>0)) {
    fprintf (outFile," module.enumerations = enumerations;\n");
  } else {
    fprintf (outFile," module.enumerations = NULL;\n");
  }
  fprintf (outFile," module.info           = (ClientData) &tornadoInfo;\n");

  fprintf (outFile,"\n // prepare emergency panic return\n"); 
  fprintf (outFile," if (setjmp (jWrapCheckPoint)) {\n");
  fprintf (outFile,"   return TCL_ERROR;\n }\n");

  fprintf (outFile," // Register Target string type\n");
  fprintf (outFile," Tcl_RegisterObjType (&stringType);\n");
  fprintf (outFile," Tcl_RegisterObjType (&stringPtrType);\n\n");

  fprintf (outFile,"\n // init routines user or default\n");
  fprintf (outFile,"#ifdef %s_CUSTOM_INIT\n %s_CUSTOM_INIT;\n"
                  ,(char*)modName, (char*)modName);
  fprintf (outFile,"#else\n if (Tornado_Init (interp) != TCL_OK) return TCL_ERROR;\n");
  fprintf (outFile,"#endif\n");

  fprintf (outFile," jWrapModuleRegister (interp,&module);\n\n");

  if (program->defines.size() > 0) {
     fprintf (outFile," jWrapEnumRegister (&module,&%s_enum,&%s_type);\n"
                     ,(char*)enumDefine,(char*)enumDefine);
  }
  for (ind=0; ind < program->enums.size(); ind ++) {
     if (ind == 0)  fprintf (outFile,"\n /* --- Enumeration Section --- */\n\n");
     fprintf (outFile," jWrapEnumRegister (&module, &%s_enum,&%s_type);\n"
       ,(char*)program->enums[ind]->name,(char*)program->enums[ind]->name);
  }


  if ((program->structs.size() >0) && (program->structs.size() >0)) {
      fprintf (outFile," \n /* *** Type Structs/Unions Section *** */\n");
  }

  for (ind=0; ind < program->structs.size (); ind ++) {
     registrate (program->structs [ind]);
  }

  for (ind=0; ind < program->unions.size (); ind ++) {
     registrate (program->unions [ind]);
  }

  for (ind=0; ind < program->typedefs.size (); ind ++) {
    if (ind == 0) {
       fprintf (outFile," \n /* *** Type Alias Section *** */\n");
    }
    registrate (program->typedefs [ind]);
  }

  for (ind=0; ind < cTypes.size(); ind++) {
    if (ind == 0) fprintf (outFile,"\n /* --- Used Type Section --- */\n\n");
    fprintf (outFile," tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [%d],\"%s\",sizeof("
            ,ind, jWrapType(cTypes[ind]->name));

    // In order handling more case we check we dont have a double prefix
    switch (cTypes[ind]->magic) {
      case TYPE_STRUCT:
       if (strncmp ((char*)*cTypes[ind]->name, "struct ",6)) fprintf (outFile,"struct ");
       break;
      case TYPE_UNION:
       if (strncmp ((char*)*cTypes[ind]->name, "union ",6)) fprintf (outFile,"union ");
       break;
      case TYPE_ENUM:
       if (strncmp ((char*)*cTypes[ind]->name, "enum ",5)) fprintf (outFile,"enum "); 
       break;
    }
    fprintf (outFile,"%s));\n", (char*)*cTypes[ind]->name);
  }

  for (ind = 0; ind < program->vars.size(); ind ++) {
    if (ind == 0) fprintf (outFile,"\n /* --- Static Variable registration --- */\n\n");
    // registrate (program->vars[ind]);
    fprintf (outFile," // WARNING: [%s] var not mapped on this version\n"
            ,(char*) program->vars[ind]->name);
  }

  for (ind=0; ind < program->functions.size(); ind ++) {
     if (ind == 0) fprintf (outFile,"\n /* --- Functions sub-section --- */\n");
     registrate (program->functions[ind]);
  }

  fprintf (outFile," return TCL_OK;\n} // end function %s_Init\n", (char*)modName);
  fprintf (outFile,"#ifdef __cplusplus\n}\n#endif\n");
  fprintf (outFile,"\n// ------------------ end %s ----------------------\n"
                  , (char*) outName);

  return;
 // ------------------------------- ERROR ----------------------------
 errCPlusPlus:
   fprintf (stderr,"ERROR:BackendCc2Tornado: C++ not supported yet!!!\n");
   status=ERROR;
   return;
  
} // end output program

