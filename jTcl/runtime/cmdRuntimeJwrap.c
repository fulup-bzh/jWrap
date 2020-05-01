
/** ----------------------------------------------------------------------------------
 *
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   cmdTargetWrap.c jWrap core module
 * Project   :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/22 10:11:10 $
 *      Revision    : $Revision: 1.5 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/cmdRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01c,19mar99,Fulup,added getenv change getenv name
 * 01b,05mar99,Fulup,added basic jWrap
 * 01a,18feb98,Fulup,written
 -------------------------------------------------------------------------------------*/

/*******************************************************
 *    jWrap Module definition
 *    ----------------------------
 *    Interface: jWrap
 *    Help     : jWrap Core module
 *******************************************************/


#ifndef JWRAP
# include <tcl.h>
# include <stdlib.h>
# include "libRuntimeJwrap.h"
# include <string.h>
#endif

// set a valid time stamp for moule version
#ifndef jWrap_CUSTOM_STAMP
#define jWrap_CUSTOM_STAMP &vStamp_libRuntimeJwrap [15]
#endif
#define jWrap_CUSTOM_INIT  jWrapMiscInit (interp)

// Following are include in wrapping but not define in this lib
#ifdef JWRAP_JTCL
 EXTERN void  Tcl_Free    (void*);
 EXTERN void* Tcl_Alloc   (int);
 EXTERN void* memcpy      (void* dest, void* src, int size);
 EXTERN char* strdup      (const char *string);
 EXTERN int   jWrapDbgValue;
#endif

// small union to retreive pointer from input param in a C routine
typedef union jwrap_basic {
 long   number;
 char   character;
 void   *pointer;
 char   *string;
 double floating;
} JWRAP_basic;


// map malloc and free to make sure everyone use TCL alloc
PUBLIC void *jWrapMalloc (size_t size) {
  return (void*) Tcl_Alloc(size);
}

PUBLIC void *jWrapCalloc (size_t nmemb, size_t size) {
  size_t len= nmemb*size;
  void *ptr = Tcl_Alloc(len);
  memset (ptr, 0, len);
  return ptr;
}

PUBLIC void jWrapFree (void *ptr) {
  Tcl_Free(ptr);
  return;
}

PUBLIC char *jWrapDup (const char*source) {
  int size= 1+ strlen (source);
  char *destination = Tcl_Alloc(size);
  memcpy (destination, source, size);
  return destination;
}

// add a small wrapper in order making a staic copy of string
PUBLIC int jWrapPutEnv (const char *string) {
  return (putenv (strdup (string)));
}

// add a small wrapper in order making a staic copy of string
PUBLIC char* jWrapGetEnv (const char *string) {
  return (strdup (getenv (string)));
}
