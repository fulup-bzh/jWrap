/*
 *
 *  Copyright(c) 1997-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   mainWrap.cc
 * Project   :   jWrap
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/22 10:11:03 $
 *      Revision    : $Revision: 1.4 $
 *      Source      : $Source: /Master/jWrap/cmd/mainWrap.cxx,v $
 *
 * Modification History
 * --------------------
 * 01d,16feb99,Fulup,remanced modulefrom WPR to Tornado
 * 01c,02jun98,Fulup added Tornado option
 * 01b,14may98,Fulup added include option
 * 01a,06feb98,Fulup,written
 */


#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "oalWrap.h"
#include "libFrontendCc.h"
#include "libFrontendTcl.h"
#include "libBackendCc2jTcl.h"
#include "libBackendCcProto.h"
#include "libBackendJavadoc.h"
#include "libBackendCcHat.h"
#ifdef TORNADO_BASE
#include "libBackendCc2Tornado.h"
#endif

#define VERBOSE    1
#define VERSION    2
#define HELP       3
#define DEBUG      4
#define OUTPUT     5

#define IN_JAVA    10
#define IN_CC      11
#define IN_JTCL    6

#define CC_JTCL    20
#define CC_PROTO   21
#define CC_HAT     22
#define JAVA_DOC   23
#define CC_TORNADO     24

#define MOD_NAME   30
#define IGNORE     31
#define OUTDIR     32
#define INCL_NAME  33

// EXAMPLE:long_options starting option for GNU lib getopt
static struct option const long_options[] =
 {
  {"debug"    , (int)"DebugLevel" ,0, DEBUG},
  {"output"   , (int)"Output File Name [stdout == -]" ,0, OUTPUT},
  {"outdir"   , (int)"Output Directory prefix" ,0, OUTDIR},
  {"implement", (int)"ModuleName" ,0, MOD_NAME},
  {"include"  , (int)"#include <patch>" ,0, INCL_NAME},
  {"verbose"  , 0,0, VERBOSE},
  {"ccproto"  , 0,0, CC_PROTO},
  {"cchat"    , 0,0, CC_HAT},
  {"cc2jTcl"  , 0,0, CC_JTCL},
#ifdef TORNADO_BASE
  {"cc2tornado"   , 0,0, CC_TORNADO},
#endif
  {"javadoc"  , 0,0, JAVA_DOC},
  {"cc"       , 0,0, IN_CC},
  {"java"     , 0,0, IN_JTCL},
  {"jTcl"     , 0,0, IN_JAVA},
  {"ignore"   , (int)"Ignore next parameter",0, IGNORE},
  {"version"  , 0,0, VERSION},
  {"help"     , 0,0, HELP},
  {0, 0, 0, 0}
 };


// Compta with tcl8.0
extern "C" {
  IMPORT char* vStampBin_jWrap;
  static char tclEmptyString='\0';
  char * tclEmptyStringRep = &tclEmptyString;
 }


/*----------------------------------------------------------
 | printversion
 |   print all version module remove lib and bin header
 +--------------------------------------------------------- */
 LOCAL void printVersion (void)
 {

   fprintf (stderr,"jWrap Version\n");
   fprintf (stderr,"--------------------------------------\n");
   fprintf (stderr,"Main+oal %s\n", &vStampBin_jWrap[15]);
   fprintf (stderr,"Frontends\n");
   fprintf (stderr," C/C++   %s\n", &vStamp_libFrontendCc[15]);
   fprintf (stderr," jTcl    %s\n", &vStamp_libFrontendTcl[15]);
   fprintf (stderr,"Backends\n");
   fprintf (stderr," ccproto %s\n", &vStamp_libBackendCcProto[15]);
   fprintf (stderr," cc2jTcl %s\n", &vStamp_libBackendCc2jTcl[15]);
   fprintf (stderr," javadoc %s\n", &vStamp_libBackendJavadoc[15]);
   fprintf (stderr," cchat   %s\n", &vStamp_libBackendCcHat[15]);
#ifdef TORNADO_BASE
   fprintf (stderr," ccTornado   %s\n", &vStamp_libBackendCc2Tornado[15]);
#endif
 } // end printVersion

void printHelp(char *name)
{
  int ind;

  fprintf (stderr,"%s:\nallowed options\n", name);
  for (ind=0; long_options [ind].name != NULL;ind++)
  {
    // display options
    if (long_options [ind].has_arg == 0)
    {
       fprintf (stderr,"  --%-10s\n", long_options [ind].name);
    } else {
       fprintf (stderr,"  --%-10s=?? [%s]\n", long_options [ind].name, (char*)long_options [ind].has_arg);
    }
  }

  fprintf (stderr,"Example:\n  %s\\\n  --verbose --implement=MyModule --cc2jTcl *.h \n", name);
} // end printHelp

/* ---------------------------------------------------------
 | docExtract main entry routine
 | Parse parameters in order calling lex/yacc associated
 | routines.
 + -------------------------------------------------------- */
int main
  ( int argc     // Number of argument
   ,char **argv  // Array of  argument LINK:long_options
  )
{
 int            optionIndex = 0;
 int 		optc,ind;
 int            currentArgv =0;
 char*          inclName    = NULL;
 char*          programName;
 char*          outFile     = NULL;
 char*          modName     = NULL;
 char*          outDir      = NULL;
 LANGUAGE       lang        = LANG_UNKNOWN;
 TARGET         target      = TARGET_UKNOWN;
 char           *extention  = NULL;
 FILE           *yyin;



  // get option with GNU lib
  programName = argv[0];

  // get all options from command line
  while ((optc = getopt_long (argc, argv, "vsp?", long_options, &optionIndex))
        != EOF)
  {
    switch (optc)
    {
     case VERBOSE:
       verbose = TRUE;
       break;

     case IN_JAVA:
       lang= LANG_JAVA;

     case IN_CC:
       lang= LANG_CC;
       break;

     case IN_JTCL:
       lang= LANG_JTCL;
       break;

     case CC_PROTO:
       target= TARGET_CCPROTO;
       break;

     case CC_JTCL:
       target= TARGET_CCJTCL;
       break;

     case CC_TORNADO:
       target= TARGET_CCTORNADO;
       break;

     case CC_HAT:
       target= TARGET_CCHAT;
       break;

     case JAVA_DOC:
       target= TARGET_JAVADOC;
       break;

     case DEBUG:
       verbose = TRUE;
       if (optarg == 0) goto invalidValue;
       if (!sscanf (optarg, "%d", &debugLevel)) goto notAnInteger;
       break;

     case VERSION:
       printVersion();
       break;

     case OUTPUT:
       if (optarg == 0) goto invalidValue;
       outFile = optarg;
       break;

     case INCL_NAME:
       if (optarg == 0) goto invalidValue;
       inclName = optarg;
       break;

     case MOD_NAME:
       if (optarg == 0) goto invalidValue;
       modName = optarg;
       break;

     case IGNORE:
       if (optarg == 0) goto invalidValue;
       break;

     case OUTDIR:
       if (optarg == 0) goto invalidValue;
       outDir = optarg;
       break;

     case HELP:
     default:
       printHelp(programName);
       return (ERROR);
    }
    currentArgv ++;
  }

  if (argc < 2) goto errorSyntax;

  for (currentArgv=currentArgv+1; currentArgv<argc; currentArgv++)
  {

   if (lang == LANG_UNKNOWN) {
     // check input language with extention
     extention = argv [currentArgv];
     for (ind=strlen(extention) -1; (ind > 0); ind --) {
       if (extention [ind] == '.') {
         extention = &extention [ind+1];
       }
     }

    // get source langguage from extention
    if (!strcmp (extention, "h")) {
       lang = LANG_CC;
    }

    else if (extention[0] == 'c') {
       lang = LANG_CC;
    }

    else if (!strcmp (extention, "def")) {
       lang = LANG_CC;
    }

    else if (!strcmp (extention, "jTcl")) {
       lang = LANG_JTCL;
    }

    else if (!strcmp (extention, "java")) {
       lang = LANG_JAVA;
    }


    } // end lang ==Unknown

    if (verbose) fprintf (stderr,"Processing file:%s\n", argv [currentArgv]);
    if (strcmp (argv [currentArgv],"-")) {
      yyin    = fopen (argv [currentArgv], "ro");
      yyFileName = argv [currentArgv];
      if (yyin== NULL) goto invalidFileName;
    } else {
      yyin       = stdin;
      yyFileName = "stdin";
    }

    // Create a new program object
    currentProgram  =new Programs (yyFileName,lang);

    switch (lang) {
      case LANG_CC:
        yycc_in = yyin;
        yycc_parse();
        break;

      case LANG_JTCL:
        yytcl_in = yyin;
        yytcl_parse();
        break;

    case LANG_JAVA:
        fprintf (stderr, "NOT done yet [sorry for that]\n");

      default: goto unknowLanguage;
    }

    fclose (yyin);
    if (currentProgram->status == ERROR) goto errorParsing;

    // did our user force module implementation name
    if (modName != NULL) {
       currentProgram->implement = modName;
       currentProgram->assertLine  = 0;
       currentProgram->firstInclude= 1;
    }

    // Create output object
    switch (target) {

      case TARGET_CCPROTO:
        BackendCcProto   *protoProgram;
        protoProgram = new BackendCcProto ();
        protoProgram->init  (currentProgram,outDir,outFile);
        if (protoProgram->status == ERROR) goto errorProto;

        protoProgram->output(currentProgram);
        break;

      case TARGET_CCHAT:
        BackendCcHat   *hatProgram;
        hatProgram = new BackendCcHat ();
        hatProgram->init  (currentProgram,outDir,outFile);
        if (hatProgram->status == ERROR) goto errorProto;
        if (inclName != NULL) {
          hatProgram->inName= inclName;
        }
        hatProgram->output(currentProgram);
        break;

      case TARGET_CCJTCL:
        BackendCc2jTcl   *tclProgram;
        tclProgram = new BackendCc2jTcl ();
        tclProgram->init  (currentProgram,outDir,outFile);
        if (tclProgram->status == ERROR) goto errorProto;
        if (inclName != NULL) {
          tclProgram->inName= inclName;
        }
        tclProgram->output(currentProgram);
        break;

#ifdef TORNADO_BASE
      case TARGET_CCTORNADO:
        BackendCc2Tornado   *tornadoProgram;
        tornadoProgram = new BackendCc2Tornado ();
        tornadoProgram->init  (currentProgram,outDir,outFile);
        if (tornadoProgram->status == ERROR) goto errorProto;
        if (inclName != NULL) {
          tornadoProgram->inName= inclName;
        }
        tornadoProgram->output(currentProgram);
        break;
#endif

      case TARGET_JAVADOC:
        BackendJavadoc   *javaDocFile;
        javaDocFile  = new BackendJavadoc ();
        javaDocFile->init  (currentProgram,outDir,outFile);
        if (javaDocFile->status == ERROR) goto errorProto;

        javaDocFile->output(currentProgram);
        break;

    default: goto unknowTarget;
    }

  }

 if (verbose) fprintf (stderr,"jWrap done\n");
 return OK;

invalidFileName:
  fprintf (stderr,"Can't open file:%s\n",argv [currentArgv]);
  return ERROR;

errorParsing:
  fprintf (stderr,"Error parsing input file:%s\n",yyFileName);
  return ERROR;

errorProto:
  fprintf (stderr,"Error building jWrap target file:%s\n",yyFileName);
  return ERROR;

invalidValue:
  fprintf (stderr,"Value should be set with %s\'=\'\n",optarg);
  return ERROR;

notAnInteger:
  fprintf (stderr,"Value should be a valid integer:%s\n",optarg);
  return ERROR;

errorSyntax:
  fprintf (stderr,"\nERROR: no or invalid parameters parameters\n\n");
  printHelp (programName);
  return (ERROR);

unknowTarget:
  fprintf (stderr,"\njWrap please select output target [javadoc|cc2jTcl|cproto] target\n");
  return (ERROR);

unknowLanguage:
  fprintf (stderr,"\njWrap please select input language [cc|jTcl|java] target\n");
  return (ERROR);
} // end main


