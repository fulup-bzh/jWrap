/*
 *
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   BackendJavadoc.cc C++ to pseudo Java code generation for JWAVADOC
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jDoc/javadoc/BackendJavadoc.cxx,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup,moved to new tree
 * 01a,06feb98,Fulup,written
 */


#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "libBackendJavadoc.h"


/******************************************************************************
 * Javadoc backend create a file for each class
 ******************************************************************************/
int BackendJavadoc::openOutFile (char  *className, char *postfix, McString *doc) {
 char name [255];

  // If file was output close previous
  if (outFile != stdout) {
   fprintf (outFile,"};\n");
   fclose (outFile);
  }

  // build output file name
  if (postfix != NULL) {
    sprintf (name,"%s_%s.java", className,postfix);
  } else {
    sprintf (name,"%s.java", className);
  }

  if (verbose) fprintf (stderr,"backend javadoc creating file:%s\n", name);
  outFile= fopen (name,"w");
  if (outFile == NULL) goto errOpen;

  // start printing an information header
  fprintf (outFile,"\n/*  ----------------------------------------------------------");
  fprintf (outFile,"\n *   This file was automatically generated with");
  fprintf (outFile,"\n *   jWrap (C)FRIDU a Free Software Company 97-98");
  fprintf (outFile,"\n *   File: %s", (char*)outName);
  fprintf (outFile,"\n *   Date: %s",getDate());
  fprintf (outFile,"\n *   jWrap --javadoc %s\n", name);
  fprintf (outFile,"\n *   Except if you really know what you are doing you should");
  fprintf (outFile,"\n *   not edit this file by hand.");
  fprintf (outFile,"\n *");
  fprintf (outFile,"\n *   In order rebuilding it use jWrap");
  fprintf (outFile,"\n + ------------------------------------------------------------ */\n");

  // attach all module to module
  fprintf (outFile,"package %s;\n", (char*)modName);

  // rebuild class name with no extention and directory prefix
  if (postfix != NULL) {
    sprintf (name,"%s_%s", className,postfix);
  } else {
    sprintf (name,"%s", className);
  }

  // is we have documentation output it before class tag
  if (doc != NULL)  output (doc);

  fprintf (outFile,"\npublic class %s \n", name);
  return OK;

 errOpen:
   fprintf (stderr, "ERROR: BackendJavadoc can't open file |%s|\n", name);
   status = ERROR;
   return ERROR;
} // end outFile

/*****************************************************************
 * output doc if any in a java doc compatible presentation
 *****************************************************************/
void BackendJavadoc::output (McString* doc) {

 // only try to print doc is there is a doc
 if (doc == NULL) return;

 // output class header
 if (doc->size() > 0) {
   fprintf (outFile,"\n/** ");
   fputs (*doc, outFile);
   fprintf (outFile,"/\n");
 }
}

void BackendJavadoc::output (Enums* enumeration) {
   int ind;

   // each enum is define a public java class
   if (openOutFile ( enumeration->name,NULL,enumeration->doc)) return;

   fprintf (outFile," extends global {\n");

   for (ind=0; ind < enumeration->values.size(); ind++) {
        output (enumeration->values[ind]->doc);
        fprintf (outFile, "  public int %-15s"
           ,(char*)enumeration->values[ind]->name
        );
        if (enumeration->values[ind]->value.size() > 1) {
          fprintf (outFile, " = %s"
            ,(char*)enumeration->values[ind]->value
          );
        }
        fprintf (outFile, ";\n");
    }

} // end output enumeration

void BackendJavadoc::output (Structs* structure) {
   Elements *element;
   int       ind;

   // each structure or union is define a public java class
   if (openOutFile ( structure->name,NULL,structure->doc)) return;

   fprintf (outFile," extends global {\n");

   for (ind=0; ind < structure->elements.size(); ind++) {
        element = structure->elements [ind];
        output (element->doc);
        fprintf (outFile, "  public %s %s"
           ,jWrapType (&element->type)
           ,(char*)element->name
        );
        if (element->array >= 0) {
        fprintf (outFile, " []");
        }
        fprintf (outFile, ";\n");
    }
} // end output structs

void BackendJavadoc::output (Typedefs* alias) {
   int   ind;
   char  origin[255];

   // Check we are not facing a final type
   strncpy (origin,(char*) alias->source,sizeof(origin));

   // check first word of type
   for (ind=0; (origin [ind] != ' ') && (origin[ind] != '\0'); ind++) {};
   origin[ind] = '\0';

   if (!strcmp ("unsigned", origin)) return;
   if (!strcmp ("bool"    , origin)) return;
   if (!strcmp ("int"     , origin)) return;
   if (!strcmp ("float"   , origin)) return;
   if (!strcmp ("double"  , origin)) return;
   if (!strcmp ("long"    , origin)) return;
   if (!strcmp ("short"   , origin)) return;
   if (!strcmp ("char"    , origin)) return;
   if (!strcmp ("boolean" , origin)) return;

   // each enum is define a public java class
   if (openOutFile ( alias->name,NULL,alias->doc)) return;

   if (!strcmp ("unsigned", (char*)alias->name)) goto noExtend;
   if (!strcmp ("bool"    , (char*)alias->name)) goto noExtend;
   if (!strcmp ("int"     , (char*)alias->name)) goto noExtend;
   if (!strcmp ("float"   , (char*)alias->name)) goto noExtend;
   if (!strcmp ("double"  , (char*)alias->name)) goto noExtend;
   if (!strcmp ("long"    , (char*)alias->name)) goto noExtend;
   if (!strcmp ("short"   , (char*)alias->name)) goto noExtend;
   if (!strcmp ("char"    , (char*)alias->name)) goto noExtend;
   if (!strcmp ("boolean" , (char*)alias->name)) goto noExtend;


   fprintf (outFile," extends %s {\n",(char*)alias->source);
   return;

// IF C++ is a basic type we dont extend class
noExtend:
   fprintf (outFile," {\n");
   return;

} // end output typedef

void BackendJavadoc::output (Vars* var) {

      output (var->doc);

      switch (var->visibility) {
      case PROT_PRIVATE:
	fprintf (outFile," private ");
	break;

      case PROT_PUBLIC:
	fprintf (outFile," public ");
	break;
      }

      switch (var->location) {
      case LOC_GLOBAL:
      case LOC_STATIC:
          fprintf (outFile," static");
          break;
      case LOC_AUTO:
      case LOC_VIRTUAL:
          break;
       }
      fprintf (outFile," %s %s;\n", jWrapType (&var->type), (char*)var->name);
} // end output var

void BackendJavadoc::output (Functions* function) {

  int ind;

      // for java mapping void function are equivalent to no param functions
      if (!strcmp ("void", (char*)function->result))     function->result.resize(0);
      if (function->params.size() == 1) {
        if (!strcmp ("void", (char*)function->params[0]->type)) function->params.clear();
      }

      output (function->doc);

      switch (function->visibility) {
      case PROT_PRIVATE:
	fprintf (outFile," private ");
	break;

      case PROT_PUBLIC:
	fprintf (outFile," public ");
	break;
      }

      switch (function->location) {
      case LOC_GLOBAL:
      case LOC_STATIC:
          fprintf (outFile," static");
          break;
      case LOC_AUTO:
      case LOC_VIRTUAL:
          break;
       }

      // change destructor to finalize
      if (function->name [0] == '~') {
       fprintf (outFile,"finalize");
       function->name [0] = ' ';
      }

      // print result type with method name
      fprintf (outFile, " %s %s (", jWrapType (&function->result), (char*)function->name);

      // print all parameters types (warning last param as no comma
      for (ind=0; ind < function->params.size (); ind ++)
	{
          if (ind != 0) fprintf (outFile, ", ");
	  fprintf (outFile, "%s %s", jWrapType (&function->params [ind]->type)
                          ,(char*)function->params [ind]->name);

        } // end for each param
      fprintf (outFile,") {};\n");
} // end output function



void BackendJavadoc::output (Classes* classe)
{
 int        ind;
 VISIBILITY visibility;

 // create one output file for each class
 if (openOutFile ( classe->name,NULL,classe->doc)) return;

 // output extension super class list
 for (ind=0; ind < classe->extends.size(); ind++) {
     if (ind == 0) fprintf (outFile, " extends ");
     if (ind == 1) fprintf (outFile, " implements ");
     if (ind >= 2) fprintf (outFile, " , ");
     fprintf (outFile, "%s %s\n",(char*) classe->extends [ind]->name
                                ,(char*) classe->extends [ind]->extra);
 }

   // output class core header
   fprintf (outFile,"  {");

   for (visibility=(VISIBILITY)0; visibility != PROT_UNKNOW
                    ; visibility= (VISIBILITY) ((int)visibility + 1)) {

     // output public element first
     for (ind=0; ind < classe->vars.size(); ind++) {
       if (ind ==0)  fprintf (outFile, "\n  // Vars sub-section\n");
       if (classe->vars[ind]->visibility == visibility) {
         output (classe->vars  [ind]);
       }
     }
     for (ind=0; ind < classe->methods.size(); ind++) {
       if (ind == 0) fprintf (outFile,"\n  // Methods sub-section\n");
       if (classe->methods[ind]->visibility == visibility) {
         output (classe->methods [ind]);
       }
     }
   }   // end for each visibility

} // end output classe

// Effectively build target file
void BackendJavadoc::output (Programs *program) {
  int ind;

  // create outfile for global function
  if (openOutFile ("global",NULL,program->doc)) return;
  fprintf (outFile," {\n");

  for (ind=0; ind < program->vars.size(); ind ++) {
     if (ind == 0)  fprintf (outFile,"\n\n// Variables Section\n");
     // do not output private vars
     if (program->vars[ind]->visibility == PROT_PUBLIC) {
       output (program->vars[ind]);
     }
  }

  for (ind=0; ind < program->functions.size(); ind ++) {
    if (ind == 0) fprintf (outFile,"\n// Interface/Functions Section\n");
     // do not output private functions
     if (program->functions[ind]->visibility == PROT_PUBLIC) {
       output (program->functions[ind]);
     }
  }

  // Start outputing define as a dummy class
  if (program->defines.size() >0 ) {

    if (openOutFile ("define",NULL,NULL)) return;
    fprintf (outFile," extends global {\n");
    for (ind=0; ind < program->defines.size(); ind ++) {
       output  (program->defines[ind]->doc);
       fprintf (outFile,"  int %s;\n",  (char*)program->defines[ind]->name);
    }
  }

  // Each structs is a class
  for (ind=0; ind < program->structs.size(); ind ++) {
     output (program->structs[ind]);
  }

  // Each enum is a class
  for (ind=0; ind < program->unions.size(); ind ++) {
     output ((Structs*)program->unions[ind]);
  }

  // Each enum is a class
  for (ind=0; ind < program->enums.size(); ind ++) {
     output (program->enums[ind]);
  }

  // each typedef is a dymmy empty class
  for (ind=0; ind < program->typedefs.size(); ind ++) {
     output (program->typedefs [ind]);
  }

  // finally map C++ class on java class
  for (ind=0; ind < program->classes.size(); ind ++) {
     output (program->classes [ind]);
  }

  // force last class end brace
  fprintf (outFile,"}");

} // end output program



// Build output name from input one
void BackendJavadoc::setOutName (Programs *program) {

    // Candel default output file
    outName = "-";      // add jWrap Ordinary C extension

} // end setOutName


/****************************************************************************
 ** Constructor just pass parameter to cc proto super class
 *************************************************************************** */
void BackendJavadoc::init (Programs* program, char *outDir, char* usrName) {


  // check user did not force outfile
  if (usrName != NULL) goto errOutFile;

  // As javadoc backend does not postfixe filename we ask for a destination directory
  if (outDir ==  NULL) goto noOutDir;

  // Check destination directoty is valid
  status = chdir (outDir);
  if (status == ERROR) goto notValidDir;

  if (verbose) fprintf (stderr,"Backend javadoc output directory [%s]\n", outDir);

  // out super class build modulename
  BackendCc2jTcl::init (program,outDir,NULL);

  return; // OK

 errOutFile:
  fprintf (stderr, "ERROR: javadoc backend output not supported use outdir [%s]\n",usrName);
  status = ERROR;
  return;

 notValidDir:
  fprintf (stderr, "ERROR: javadoc backend outdir not a valid directory [%s]\n",outDir);
  status = ERROR;
  return;

 noOutDir:
  fprintf (stderr, "ERROR: javadoc backend outdir mandatory [jWrap --outdir=/tmp]\n");
  status = ERROR;
  return;
}

BackendJavadoc::BackendJavadoc (void) {};



