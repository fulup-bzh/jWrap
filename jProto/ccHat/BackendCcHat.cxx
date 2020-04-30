/*
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   ccHatWrap.cc C++ prototype generation
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jProto/ccHat/BackendCcHat.cxx,v $
 *
 * Modification History
 * --------------------
 * 01a,06feb98,Fulup,written
 */


#include <stdio.h>
#include <time.h>

#include "libBackendCcHat.h"

void BackendCcHat::output (Vars* var) {

   int methode = FALSE;

      switch (var->location) {
      case LOC_GLOBAL:
          fprintf (outFile,"EXPORT");
          break;
      case LOC_STATIC:
          fprintf (outFile,"    static");
          break;
      case LOC_AUTO:
          methode = TRUE;
          fprintf (outFile,"   ");
          break;
      case LOC_VIRTUAL:
          fprintf (outFile,"    virtual");
          break;
       }
      fprintf (outFile," %s ", (char*)var->type);
      if (methode) {
        fprintf (outFile,"%s::", (char*)var->owner->name);
      }
      fprintf (outFile," %s",(char*)var->name);
  
      if (var->array == 0) fprintf (outFile,"[]");
      if (var->array >  0) fprintf (outFile,"[%d]",var->array);
      fprintf (outFile,";\n");
} // end output var

void BackendCcHat::output (Functions* function) {

  int ind;
  int methode = FALSE;

      switch (function->location) {
      case LOC_GLOBAL:
          fprintf (outFile,"PUBLIC");
          break;
      case LOC_STATIC:
          fprintf (outFile,"    static");
          break;
      case LOC_AUTO:
          fprintf (outFile,"   ");
          methode = TRUE;
          break;
      case LOC_VIRTUAL:
          fprintf (outFile,"    virtual");
          break;
       }

      // print result type with method name
      fprintf (outFile, " %s ", (char*)function->result);
      if (methode) {
        fprintf (outFile,"%s::", (char*)function->owner->name);
      }
      fprintf (outFile, "%s (",  (char*)function->name);

      // print all parameters types (warning last param as no comma
      for (ind=0; ind < function->params.size (); ind ++)
	{
          if (ind != 0) fprintf (outFile, ", ");
	  fprintf (outFile, "%s %s"
           , (char*) function->params [ind]->type
           , (char*) function->params [ind]->name);

        } // end for each param
        fprintf (outFile,") {\n");

      // make a dymmu return for warnings
      if (strcmp ((char*)function->result,"void")) {
        fprintf (outFile," %s result;\n", (char*)function->result);
        fprintf (outFile," memset (&result,0,sizeof(result));\n");
      }

      // provide a dummy trace mecanism for debug 
      fprintf (outFile, " jWrapLog (5, \"trace: %s ", (char*)function->result);
      if (methode) {
        fprintf (outFile,"%s::", (char*)function->owner->name);
      }
      fprintf (outFile, "%s (",  (char*)function->name);
 
      // print all parameters types (warning last param as no comma
      for (ind=0; ind < function->params.size (); ind ++)
      {
         if (ind != 0) fprintf (outFile, ", ");
	 fprintf (outFile, "%s", (char*) function->params [ind]->type);

      }   // end for each param

      fprintf (outFile,")\\n\");\n");

      // make a dymmu return for warnings
      if (strcmp ((char*)function->result,"void")) {
        fprintf (outFile," return result;\n");
      }

      fprintf (outFile,"}\n\n");
} // end output function

void BackendCcHat::output (Classes* classe)
{
 int        ind;
   
   // Var section 
   fprintf (outFile, "    // Vars sub-section\n");
   for (ind=0; ind < classe->vars.size(); ind++) {
       output (classe->vars  [ind]);     
   }

   // methode section
   fprintf (outFile,"\n    // Methods sub-section\n");
   for (ind=0; ind < classe->methods.size(); ind++) {
       output (classe->methods [ind]);     
   }

} // end output classe

// Effectively build target file
void BackendCcHat::output (Programs *program) {
  int ind;

  // start printing an information header
  fprintf (outFile,"\n/*  ----------------------------------------------------------");
  fprintf (outFile,"\n *   This file was automatically generated with");
  fprintf (outFile,"\n *   jWrap (C)FRIDU a Free Software Company 97-98");
  fprintf (outFile,"\n *   File: %s %s", (char*)outName,(char*)program->help); 
  fprintf (outFile,"\n *   Date: %s",getDate()); 
  fprintf (outFile,"\n *   jWrap --ccHat %s\n", (char*)program->name);
  fprintf (outFile,"\n *   Except if you really know what you are doing you should"); 
  fprintf (outFile,"\n *   not edit this file by hand.");
  fprintf (outFile,"\n *");
  fprintf (outFile,"\n *   In order rebuilding it use jWrap");   
  fprintf (outFile,"\n + ------------------------------------------------------------ */\n");

 
  fprintf (outFile,"#include <stdio.h>\n");
  fprintf (outFile,"#include <string.h>\n");
  fprintf (outFile,"\n#define JWRAP_HAT\n");
  fprintf (outFile,"#ifndef EASYC_PROTO_ONLY\n");
  fprintf (outFile,"#define EASYC_PROTO_ONLY\n");
  fprintf (outFile,"#endif\n");
  fprintf (outFile,"\n#include <easyc.h>\n");

  // program original header c or c++
  fprintf (outFile, "#include \"%s\"\n", (char*)inName);

  fprintf (outFile,"\n\n// Variables Section\n");
  for (ind=0; ind < program->vars.size(); ind ++) {
    if (program->vars[ind]->visibility == PROT_PUBLIC) {
      output (program->vars[ind]);
    }
  }

  fprintf (outFile,"\n// Functions Section\n");
  for (ind=0; ind < program->functions.size(); ind ++) {
   if (program->functions[ind]->visibility == PROT_PUBLIC) {
     output (program->functions[ind]);
   }
  }

  fprintf (outFile,"#ifdef __cplusplus\n}\n#endif\n");

  fprintf (outFile,"\n// Classes Section\n");
  for (ind=0; ind < program->classes.size(); ind ++)
     output (program->classes [ind]);


  fprintf (outFile,"\n// ------------------ end %s ----------------------\n"
                  ,(char*) outName);

} // end output program


// Build output name from input one
void BackendCcHat::setOutName (Programs *program) {

  // WARNING: this function is not call when output=-
  if (program->classes.size () > 0) {
    outName += "_hat.cxx";     // add jWrap C++ extension
  } else {
    outName += "_hat.c";      // add jWrap Ordinary C extension
  }
} // end setOutName



BackendCcHat::BackendCcHat (void) {};
