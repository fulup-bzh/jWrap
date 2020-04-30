/*
 *
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   programBackendCc2jTcl.cc managed program object in C++ 2 jTcl backend wrapper
 * Projet    :   Rubicon/jWrap
 * Module    :   jWrap C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/programBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01e,15feb99,Fulup,removed TCL mapping of local function removed modname from cmd
 * 01d,20sep98,Fulup,revers structure and union order
 * 01c,02jun98,Fulup,minor modification to support a second runtimelib
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>
#include <ctype.h> 
#include "libBackendCc2jTcl.h"

/**----------------------------------------------------------------------------
 *** Effectively build C++ jTcl wrapper 
 **----------------------------------------------------------------------------*/

void BackendCc2jTcl::output (Programs *program) {
  int ind,jnd,knd;
  McString enumDefine;
  int usedType=0;  // number of different type in module
  char initName [55];
  

  // start printing an information header
  fprintf (outFile,"\n/*  ----------------------------------------------------------");
  fprintf (outFile,"\n *   This file was automatically generated with");
  fprintf (outFile,"\n *   jWrap (C)FRIDU a Free Software Company 97-98");
  fprintf (outFile,"\n *   File: %s %s",(char*)outName,(char*)program->help);
  fprintf (outFile,"\n *   Date: %s\n",getDate()); 
  fprintf (outFile,"\n *   jWrap --cc2jTcl %s\n *", (char*)program->name);
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
  fprintf (outFile,"#define JWRAP_CC2JTCL\n\n");
  fprintf (outFile, "#include \"libRuntimeJwrap.h\"\n");
  // program original header c or c++
  if (inName.size() > 1) {
    fprintf (outFile, "#include \"%s\"\n", (char*)inName);
  }

  fprintf (outFile,"\n#ifndef %s_CUSTOM_STAMP\n", (char*)modName);
  fprintf (outFile," #ifdef FRIDU\n");
  fprintf (outFile," #define %s_CUSTOM_STAMP &vStamp_lib%s[12]\n",(char*)modName,(char*)modName);
  fprintf (outFile," #else\n");
  fprintf (outFile," #define %s_CUSTOM_STAMP NULL\n",(char*)modName);
  fprintf (outFile," #endif\n");
  fprintf (outFile,"#endif\n\n");
  fprintf (outFile,"#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc\n");
  fprintf (outFile,"#define JWRAP_FREE_FUNC   jWrapTypeFree\n");
  fprintf (outFile,"#define JWRAP_CGET_FUNC   jWrapTypeCget\n\n");

  fprintf (outFile," // Build module static informations\n");
  fprintf (outFile," static JWRAP_modules module;\n");
  fprintf (outFile," static int initDone=0;\n");
  fprintf (outFile," static char *errTypeFmt=\"param:%%d type [%%s] not equivalent to [%%s]\\n\";\n");

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
    // don't wrap local function
    if (function->visibility != PROT_PUBLIC) continue;
    usedCmd.append (function);
    registerType (&function->result,-1,TYPE_NATIVE);
   
    for (jnd=0; jnd < function->params.size(); jnd++) {
     registerType (&function->params[jnd]->type,-1,TYPE_NATIVE);
    }
  } // end for ind
  for (ind=0; ind < program->classes.size(); ind ++) {
    Classes *classe;
    classe = program->classes [ind];
    for (jnd=0; jnd < classe->vars.size(); jnd++) {
      registerType (&classe->vars[jnd]->type,classe->vars[jnd]->array,TYPE_NATIVE);
    }
    for (jnd=0; jnd < classe->methods.size(); jnd++) {
      Functions* method;
      method = classe->methods[jnd]; 
      // only take public methods
      if (method->visibility != PROT_PUBLIC) continue;
      if (method->name [0] == '~')  {
        // we are facing a destructor remove it from list
        classe->methods.remove (jnd);
        continue;
      }
      usedCmd.append (method);
      registerType (&method->result,-1,TYPE_NATIVE);
      for (knd=0; knd < method->params.size(); knd++) {
        registerType (&method->params[knd]->type,-1,TYPE_NATIVE);
      } // end for knd 
    } // end for jnd
  } // end for ind


  // we now know used type array size
  fprintf (outFile," static JWRAP_types usedType [%d];\n",cTypes.size());  

  // We print an enumeration in order program to used symbolic name for type
  fprintf (outFile,"\n // Build used type enumeration\n");
  fprintf (outFile," enum enumType {\n");
  for (ind=0; ind < cTypes.size(); ind++) {
    if (ind != 0) fprintf (outFile,",\n"); 
    fprintf (outFile,"   JTYPE_%-25s = %d", jWrapType (cTypes [ind]->name), ind);
  }

  fprintf (outFile,"\n }; // end of usedType enumeration\n");

  // Command help is a static array of string with one line of help for each command
  fprintf (outFile,"\n // Build used commands help array\n");
  fprintf (outFile," static char *helpCmd[] = {\n");
  // each module as at least module management command
  for (ind=0; ind < usedCmd.size(); ind++) {
    usedCmd [ind]->number = ind;
    fprintf (outFile,"   \"%s\",\n",(char*)usedCmd[ind]->help);
  }
  fprintf (outFile," NULL\n }; // end of helpCmd array\n");

  if (program->defines.size() > 0) {
     fprintf (outFile,"\n\n/* *** Define Section *** */\n\n");
     output (&enumDefine, program->defines);
  }
 
  for (ind=0; ind < program->enums.size(); ind ++) {
     if(ind ==0)  fprintf (outFile,"\n\n/* *** Enumeration Section *** */\n\n");
     output (program->enums[ind]);
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

  for (ind=0; ind < program->unions.size (); ind ++) {
    if (ind == 0) fprintf (outFile," \n/* *** Unions Section *** */\n\n");
    output   (program->unions [ind]);
  }

  // output structure union and typedef
  for (ind=0; ind < program->structs.size (); ind ++) {
    if (ind == 0) fprintf (outFile," \n/* *** Structure Section *** */\n");
    output  (program->structs [ind]);
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
    // don't wrap local function
    if (program->functions[ind]->visibility != PROT_PUBLIC) continue;
    output (program->functions[ind]);
  }

  for (ind=0; ind < program->classes.size(); ind ++) {
    if (ind == 0) fprintf (outFile,"\n/* *** Classes Section *** */\n");
    output (program->classes [ind]);
  }

  fprintf (outFile,"\n/* ***  Tcl Register Section *** */\n");
  fprintf (outFile,"#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
  // set First char as upper & removed any uppercase in midle of name for windows
  strcpy (initName, modName);
  initName [0] = toupper (  initName [0]);
  for (ind=1; initName[ind] != '\0'; ind++) {
    initName [ind] = tolower (initName [ind]);
  }
  fprintf (outFile,"RESTRICTED int %s_Init (Tcl_Interp *interp) {\n", initName);

  fprintf (outFile," // Dont init twice\n");
  fprintf (outFile," if (initDone) return TCL_OK;\n");
  fprintf (outFile," initDone = 1;\n");

  fprintf (outFile,"\n /* --- Build module handle & register it in jWrap --- */\n\n");
  fprintf (outFile," module.magic       =JWRAP_MODULE;\n");
  fprintf (outFile," module.name        =\"%s\";\n", (char*)modName);
  fprintf (outFile," module.help        =\"%s\";\n", (char*)program->help); 
  fprintf (outFile," module.helpCmd     = helpCmd;\n"); 
  fprintf (outFile," module.nbCmd       = %d;\n", usedCmd.size());
  fprintf (outFile," module.hashTable   = NULL;\n");
  fprintf (outFile," module.version     = %s_CUSTOM_STAMP;\n",(char*)modName);
  if ((program->structs.size() >0) || (program->unions.size()>0)) {
    fprintf (outFile," module.structures  = structures;\n");
  } else {
    fprintf (outFile," module.structures  = NULL;\n");
  }
  if ((program->defines.size() >0) || (program->enums.size()>0)) {
    fprintf (outFile," module.enumerations= enumerations;\n");
  } else {
    fprintf (outFile," module.enumerations= NULL;\n");
  }
  fprintf (outFile," module.info        = NULL;\n");

  fprintf (outFile,"\n // prepare emergency panic return\n"); 
  fprintf (outFile," if (setjmp (jWrapCheckPoint)) {\n");
  fprintf (outFile,"   return TCL_ERROR;\n }\n");

  fprintf (outFile,"\n // init routines user or default\n");
  fprintf (outFile,"#ifdef %s_CUSTOM_INIT\n %s_CUSTOM_INIT;\n"
                  ,(char*)modName, (char*)modName);
  fprintf (outFile,"#else\n if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;\n");
  fprintf (outFile,"#endif\n");

  fprintf (outFile," jWrapModuleRegister (interp,&module);\n");

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
    fprintf (outFile," jWrapTypeCheck (&usedType [%d],\"%s\",sizeof("
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
    if (strcmp ("...",(char*)*cTypes[ind]->name)) { 
      fprintf (outFile,"%s));\n", (char*)*cTypes[ind]->name);
    } else {
      fprintf (outFile,"va_list));\n");
    }
  }

  for (ind = 0; ind < program->vars.size(); ind ++) {
    if (ind == 0) fprintf (outFile,"\n /* --- Static Variable registration --- */\n\n");
    registrate (program->vars[ind]);
  }

  for (ind=0; ind < program->functions.size(); ind ++) {
     if (ind == 0) fprintf (outFile,"\n /* --- Functions sub-section --- */\n");
     // don't wrap local function
     if (program->functions[ind]->visibility != PROT_PUBLIC) continue;
     registrate (program->functions[ind]);
  }

  for (ind=0; ind < program->classes.size(); ind ++) {
     if (ind == 0)   fprintf (outFile,"\n /* --- Class sub-section --- */\n");
     registrate (program->classes [ind]);
  }
  
  fprintf (outFile," return TCL_OK;\n} // end function %s_Init\n", (char*)modName);
  fprintf (outFile,"#ifdef __cplusplus\n}\n#endif\n");
  fprintf (outFile,"\n// ------------------ end %s ----------------------\n"
                  , (char*) outName);

} // end output program

