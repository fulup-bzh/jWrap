/*
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   ccProtoWrap.cc C++ prototype generation
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jProto/ccProto/BackendCcProto.cxx,v $
 *
 * Modification History
 * --------------------
 * 01a,06feb98,Fulup,written
 */


#include <stdio.h>
#include <time.h>

#include "libBackendCcProto.h"
/*****************************************************************
 * output doc if any in a java doc compatible presentation
 *****************************************************************/
void BackendCcProto::output (McString* doc) {

 // only try to print doc is there is a doc
 if (doc == NULL) return;

 // output class header
 if (doc->size() > 0) {
   fprintf (outFile,"\n/** ");
   fputs (*doc, outFile);
   fprintf (outFile,"\n");
 }
}

void BackendCcProto::output (Enums* enumeration) {
   int ind;

   fprintf (outFile," enum %s {\n   ",(char*)enumeration->name);
   for (ind=0; ind < enumeration->values.size(); ind++) {
        if (ind != 0) fprintf (outFile,"  ,");
        fprintf (outFile, "%-15s"
           ,(char*)enumeration->values[ind]->name
        );
        if (enumeration->values[ind]->value.size() > 1) {
          fprintf (outFile, " = %s"
            ,(char*)enumeration->values[ind]->value
          );
        }
        fprintf (outFile, ";\n");
    }
    fprintf (outFile,"};\n");

} // end output enumeration

void BackendCcProto::output (Structs* structure) {
   Elements *element;
   int       ind;

   fprintf (outFile,"\n struct %s  {\n",(char*)structure->name);
   for (ind=0; ind < structure->elements.size(); ind++) {
        element = structure->elements [ind];
        fprintf (outFile, "  %s %s"
           ,(char*)element->type
           ,(char*)element->name
        );
        if (element->array >= 0) {
        fprintf (outFile, " []");
        }
        fprintf (outFile, ";\n");
    }
    fprintf (outFile, "};\n");
} // end output structs

void BackendCcProto::output (Typedefs* alias) {
   int   ind;
   char  name[255];

   // Check we are not facing a final type
   strncpy (name,(char*) alias->source,sizeof(name));

   // check first word of type
   for (ind=0; (name [ind] != ' ') && (name[ind] != '\0'); ind++) {};
   name[ind] = '\0';

   if (!strcmp ("unsigned", name)) return;
   if (!strcmp ("bool"    , name)) return;
   if (!strcmp ("int"     , name)) return;
   if (!strcmp ("float"   , name)) return;
   if (!strcmp ("double"  , name)) return;
   if (!strcmp ("long"    , name)) return;
   if (!strcmp ("char"    , name)) return;

   fprintf (outFile,"typedef  %s %s;\n",(char*)alias->source, (char*) alias->name);

} // end output typedef

void BackendCcProto::output (Vars* var) {

      switch (var->location) {
      case LOC_GLOBAL:
          fprintf (outFile,"extern");
          break;
      case LOC_STATIC:
          fprintf (outFile,"    static");
          break;
      case LOC_AUTO:
          fprintf (outFile,"   ");
          break;
      case LOC_VIRTUAL:
          fprintf (outFile,"    virtual");
          break;
       }
      fprintf (outFile," %s %s;\n", (char*)var->type, (char*)var->name);
} // end output var

void BackendCcProto::output (Functions* function) {

  int ind;

      switch (function->location) {
      case LOC_GLOBAL:
          fprintf (outFile,"extern");
          break;
      case LOC_STATIC:
          fprintf (outFile,"    static");
          break;
      case LOC_AUTO:
          fprintf (outFile,"   ");
          break;
      case LOC_VIRTUAL:
          fprintf (outFile,"    virtual");
          break;
       }

      // print result type with method name
      fprintf (outFile, " %s %s (", (char*)function->result, (char*)function->name);

      // print all parameters types (warning last param as no comma
      for (ind=0; ind < function->params.size (); ind ++)
	{
          if (ind != 0) fprintf (outFile, ", ");
	  fprintf (outFile, "%s", (char*) function->params [ind]->type);

        } // end for each param
        fprintf (outFile,");\n");
} // end output function

void BackendCcProto::output (Classes* classe)
{
 int        ind;
 VISIBILITY visibility;

 // output class header
 fprintf (outFile, "\nclass %s\n", (char*) classe->name);

 // output extension super class list
 if (classe->extends.size() >0) {
   fprintf (outFile,"  // Class heritage hierarchie\n  :");
   for (ind=0; ind < classe->extends.size(); ind++) {
     if (ind != 0) fprintf (outFile, "  ,");
     if (classe->extends[ind]->visibility == PROT_PUBLIC) {
       fprintf (outFile,"public ");
     }
     fprintf (outFile, "%s (%s)\n",(char*) classe->extends [ind]->name
                                ,(char*) classe->extends [ind]->extra);
   }
 }

   // output class core header
   fprintf (outFile,"  {");

   // Enum Section
   for (ind=0; ind < classe->enums.size(); ind++) {
        if (ind == 0)  fprintf (outFile, "\n    // Enum sub-section\n");
        output (classe->enums  [ind]);
   }

   for (visibility=(VISIBILITY)0; visibility < PROT_UNKNOW
                    ; visibility= (VISIBILITY) ((int)visibility + 1)) {

     switch (visibility) {

     case PROT_PUBLIC:
        fprintf (outFile, "\n    public:\n");
        break;

     case PROT_PROTECTED:
        fprintf (outFile, "\n    protected:\n");
        break;

     case PROT_PRIVATE:
        fprintf (outFile, "\n    private:\n");
        break;

     default:
        fprintf (stderr,"BackendCcProto.cc ERROR: Fatal internal unknown visibility\n");
        exit;
     } // end switch

     // Var section
     fprintf (outFile, "    // Vars sub-section\n");
     for (ind=0; ind < classe->vars.size(); ind++) {
       if (classe->vars[ind]->visibility == visibility) {
         output (classe->vars  [ind]);
       }
     }

     // methode section
     fprintf (outFile,"\n    // Methods sub-section\n");
     for (ind=0; ind < classe->methods.size(); ind++) {
       if (classe->methods[ind]->visibility == visibility) {
         output (classe->methods [ind]);
       }
     }
   }   // end for each visibility
 fprintf (outFile,"\n  };   // end class %s\n", (char*) classe->name);
} // end output classe

// Effectively build target file
void BackendCcProto::output (Programs *program) {
  int ind;

  // don't include this twice
  fprintf (outFile,"\n#if ! #implement (%s) && ! defined __%s__"
                  , (char*)program->implement , (char*)defName);
  fprintf (outFile,"\n#define __%s__\n", (char*)defName);

  // start printing an information header
  fprintf (outFile,"\n/*  ----------------------------------------------------------");
  fprintf (outFile,"\n *   This file was automatically generated with");
  fprintf (outFile,"\n *   jWrap (C)FRIDU a Free Software Company 97-98");
  fprintf (outFile,"\n *   File: %s %s\n", (char*)outName,(char*)program->help);
  fprintf (outFile,"\n *   Date: %s",getDate());
  fprintf (outFile,"\n *   jWrap --cproto %s\n", (char*)program->name);
  fprintf (outFile,"\n *   Except if you really know what you are doing you should");
  fprintf (outFile,"\n *   not edit this file by hand.");
  fprintf (outFile,"\n *");
  fprintf (outFile,"\n *   In order rebuilding it use jWrap");
  fprintf (outFile,"\n + ------------------------------------------------------------ */\n");


  // prepare to work with both C++ and C
  fprintf (outFile,"\n#ifdef __cplusplus\n extern \"C\" {\n#endif");

   //  print enum global vars then classes
  fprintf (outFile,"\n\n/* Define Section\n\n");
  for (ind=0; ind < program->defines.size(); ind ++)
     fprintf (outFile,"  define %s %s\n"
      , (char*)program->defines[ind]->name
      , (char*)program->defines[ind]->value );
  fprintf (outFile,"\n*/");


  // Print Struct first
  for (ind=0; ind < program->structs.size(); ind ++) {
     if (ind == 0) fprintf (outFile,"\n\n// Struct Section\n");
     output (program->structs[ind]);
  }

  // Print Union
  for (ind=0; ind < program->unions.size(); ind ++) {
     if (ind == 0) fprintf (outFile,"\n\n// Union Section\n");
     output (program->unions[ind]);
  }

  // Print Enum
  for (ind=0; ind < program->enums.size(); ind ++) {
     if (ind == 0) fprintf (outFile,"\n\n// Enumeration Section\n");
     output (program->enums[ind]);
  }

  // Typedef should be basic alias typedef
  for (ind=0; ind < program->typedefs.size(); ind ++) {
     if (ind == 0) fprintf (outFile,"\n\n// typedef Section\n");
     output (program->typedefs [ind]);
  }

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


  fprintf (outFile,"\n#endif  // end if implement or defined  %s\n",(char*)baseName);
  fprintf (outFile,"\n// ------------------ end %s ----------------------\n"
                  ,(char*) outName);

} // end output program

// return current date as an ascii string
char* BackendCcProto::getDate () {
    long            ltime;
    time(&ltime);
    return ctime(&ltime);
}

// Build output name from input one and do some specific to c++ checkup
void BackendCcProto::setOutName (Programs *program) {
  outName += ".i";     // add ansi proto extension

  // check assert implementation was set before first include
  if (program->assertLine < 0) goto errorNoAssert;
  if (program->assertLine >= program->firstInclude) goto errorPlaceAssert;

  // if assert implement and basename differ print a warning
  if (strcmp (program->implement, baseName)) {
     fprintf (stderr, "Note: [%s] implement [%s]\n"
                    , (char*)baseName, (char*)program->implement);
  }
  return;

errorNoAssert:
  fprintf (stderr,"ERROR: #assert implement (%s) not found in input file [use --implement]\n"
                 ,(char*)baseName);
  status=ERROR;
  return;

errorPlaceAssert:
  fprintf (stderr,"ERROR: assert implementation (line:%d) is after first include (line:%d)\n"
                 ,program->assertLine, program->firstInclude);
  status=ERROR;
  return;

} // end setOutName

// Class constructor
void BackendCcProto::init (Programs* program,char *outDir, char* usrName) {
  int   ind;
  char *tmpName;
  char *dirName;
  char *stripName;

    // save full include name
    inName = program->name;

    // base name is program name without leading dirName
    tmpName= (char*)program->name;;
    for (ind=program->name.size()-1; ind >0; ind--) {
       if (tmpName [ind] == '/') {
        ind++;
        break;
       }
    }
    baseName= (char*) &program->name[ind];

    // generate define name from input name without .
    defName =  baseName;
    tmpName = (char*)baseName;
    for (ind=0; ind < defName.size()-1 ; ind++) {
       if (tmpName [ind] == '.') {
          defName[ind] = '_';
       }
    }

    // remove extension from basename
    tmpName = (char*)baseName;
    for (ind=0; ind < baseName.size()-1 ; ind++) {
       if (tmpName [ind] == '.') {
          baseName[ind] = '\0';
       }
    }

    // get directory name from infile name
    dirName = (char*) program->name;
    for (ind=outName.size()-1; ind >0; ind--)
    {
      if (dirName [ind] == '/') {
         dirName [ind] = '\0';
         break;
      }
    }

    // did we found a directory ?
    if (ind == 0) {
      dirName = "";
      stripName = (char*) program->name;
    } else {
      outName = dirName;
      outName += "/";
      stripName=dirName +ind+1;
    }

    // check if user provided a prefix for output dir
    if (outDir != NULL) {
      outName = outDir;
      outName += "/";
    }

    // now we have directory look for file name
    if (usrName != NULL)
    {
      // If output name given just use it
      outName += usrName;
    } else {

      // else try to build it by changing extension
      for (ind=strlen(stripName)-1; ind >0; ind--)
      {
        if (stripName [ind] == '.') {
          stripName [ind] = '\0';
          break;
        }
      }
      outName += stripName;

      // No extension as been founded
      if (ind == 0) goto badExtention;


      // Build outName Name from input fileName
      setOutName (program);
    } // end user provide a name

    // if no output file use ics file minus extension
    if (((usrName != NULL) && (!strcmp (usrName,"-"))) || (!strcmp (outName,"-"))) {
      outFile  = stdout;
      outName  = "stdout";
    } else {
      // Open output file
      outFile    = fopen (outName, "w");
      if (outFile== NULL) goto invalidFileName;
      if (verbose) fprintf (stderr, "output file: [%s]\n", (char*)outName);
    }

    // check user effectively build a different name
    if (!strcmp (program->name,outName)) goto errorSameFile;

    // set comment for c++
    status=OK;
    return;

errorSameFile:
  fprintf (stderr,"ERROR: BackendCcProto input file [%s] is identical to outfile [%s]\n"
                 ,(char*)program->name, (char*)outName);
  status=ERROR;
  return;

badExtention:
  fprintf (stderr,"ERROR: BackendCcProto input file [%s] don't have a valid extension\n"
                 ,stripName);
  status=ERROR;
  return;

invalidFileName:
  fprintf (stderr,"ERROR: BackendCcProto Can't open file:%s\n", (char*)outName);
  status=ERROR;
  return;

} // end Constructor

BackendCcProto::BackendCcProto (void) {};
