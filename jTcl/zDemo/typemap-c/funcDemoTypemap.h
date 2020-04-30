/*
 *  Copyright(c) 1997-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   Demonstrate custom internal/external type maping 
 * Projet    :   jWrap
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/typemap-c/funcDemoTypemap.h,v $
 *      State       : $State: Exp $
 *
 * Modification History
 * --------------------
 * 01a,06feb98,Fulup,written
 */

/* ------------------------------------------------
 *  Interface: DemoTypemap
 *  Help     : jTcl C wrapping DemoTypemap
 * -----------------------------------------------*/
 


#ifndef __TYPE_MAP_LIB__
#define __TYPE_MAP_LIB__

#ifndef JWRAP_JTCL
#  include <easyc.h>
#  include <stdlib.h>
#endif

// define application init routines
#define DemoTypemap_CUSTOM_INIT customInitType(interp);

// Enumeration Section
typedef enum Some_Options {
   OPT_1           = 1
  ,OPT_2           = 2
  ,OPT_3           = 3
  } SomeOptions;

// Type section
 typedef struct MapAdrs{
   char* firstName;
   char* lastName;
   char* adress;
   int   zip;
   char* town;
 } typeMapAdrs;

// Variables Section
  IMPORT char*        TypeMap_help;
  IMPORT typeMapAdrs* lastAdr;

// Some extra functions not in lib we want in our Wrapper
#ifdef JWRAP_EXTRA
  EXTERN FILE*     fopen   (char*, char*);
  EXTERN char*     fgets   (void*, int, FILE*); // WARNING: take a void* COOKIE as input param
  EXTERN void      fclose  (FILE*);             // WARNING: return a COOKIE(void*)
#endif

// Function defines in lib
  EXTERN int    checkOpt      (SomeOptions);
  EXTERN int    addOneToInt   (int);
  EXTERN char*  stringToUpper (char*);
  EXTERN char** listToUpper   (char**);
  EXTERN int    evalTclInC    (Tcl_Interp*, Tcl_Obj*);
  EXTERN void   printAdr      (typeMapAdrs*);
  EXTERN void   checkVarg     (JWRAP_varg *varg);

#ifndef JWRAP_JTCL
// include application proto
#include "libDemoTypemap.i"
#endif

#endif  // end if implement or defined  funcLibType




 


