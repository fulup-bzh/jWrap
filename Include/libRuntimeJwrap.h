/*
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libRuntimeJwrap.h Entry points for jWrap cc2jTcl backend runtime lib
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libRuntimeJwrap.h,v $
 *
 * Modification History
 * --------------------
 * 01c,06mar99,Fulup,added jWrap_varg
 * 01b,04jul98,Fulup,documented
 * 01a,06feb98,Fulup,written
 */

/** -----------------------------------------------------------------------------
 * Provides runtime support for C/C++ jWrapped module, this library as to be
 * loaded first when adding jWrap component into tclsh. It can safely be a DLL
 * under Unix, nevertheless under Win32 user should be aware that when using DLL
 * there is no way to trap a strcopy error, making union interfacing with embedded
 * char* almost impossible.
 -------------------------------------------------------------------------------- */

/** do not come here twice */
#ifndef _libRuntimeJwrap_
#define _libRuntimeJwrap_

#include <tcl.h>
#include <easyc.h>
#include <setjmp.h>
#include <string.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C"
{
#endif

/*
 * Pointer to a heap-allocated string of length zero that the Tcl core uses as
 * the value of an empty string representation for an object. This value is
 * shared by all new objects allocated by Tcl_NewObj.
 */
#ifndef MODULE_SCOPE
#   ifdef __cplusplus
#   define MODULE_SCOPE extern "C"
#   else
#   define MODULE_SCOPE extern
#   endif
#endif

MODULE_SCOPE char * tclEmptyStringRep;
MODULE_SCOPE char   tclEmptyString;

// Force to to user Tcl_Alloc
#ifdef JWRAP_MALLOC
#  define malloc jWrapMalloc
#  define free jWrapFree
#  define calloc jWrapCalloc
#  define strdup jWrapDup
#endif

PUBLIC void *jWrapMalloc (size_t size);
PUBLIC void *jWrapCalloc (size_t nmemb, size_t size);
PUBLIC void jWrapFree (void *ptr);
PUBLIC char *jWrapDup (const char*source);

#define jWrapStrDup(DEST,SRC) \
{ DEST->length = strlen (SRC); \
  DEST->bytes  = Tcl_Alloc (DEST->length +1); \
  memcpy (DEST->bytes,SRC,DEST->length +1); \
}


/** Define common var struct type symbolic name */
#define JWRAP_MAX_NAME 120
#define JWRAP_MAX_ARGV 10

  /** Magic number for jWrap complex data */
  typedef enum JWRAPmagics {
      JWRAP_COOKIE  = 960510,
      JWRAP_BASIC,
      JWRAP_DELETED,
      JWRAP_MODULE,
      JWRAP_STRUCT,
      JWRAP_UNION,
      JWRAP_POINTER,
      JWRAP_ENUM,
      JWRAP_NEW,

      JWRAP_UNKNOW   = -2
    } JWRAP_magics;


  /** Format a string in an int faster than sprintf */
  EXTERN int TclFormatInt (char *buffer, long n);

  /** Dummy incomplete define internal Tcl variable in order not imposing tclInt.h  */
  typedef struct TclVarInternal
    {
      union tclObjInternal
	{
          /** The variable's object value. Used for  */
	  Tcl_Obj *objPtr;
          /** For array variables, this points to */
	  Tcl_HashTable *tablePtr;
          /** If this is a global variable being  */
	  struct Var *linkPtr;
	}
      value;
      /**  NULL if the variable is in a hashtable */
      char *name;
      /** Points to the namespace that contains */
      void *nsPtr;
      /** If variable is in a hashtable, either the */
      Tcl_HashEntry *hPtr;
      /** Counts number of active uses of this */
      int refCount;
      /**  First in list of all traces set for this */
      void *tracePtr;
      /**  First in list of all searches active */
      Tcl_HashSearch *searchPtr;
      /**  Miscellaneous bits of information about */
      int flags;
    }
  TclVarInternal;

  /** Internal to Tcl fast search routine */
  EXTERN TclVarInternal *TclLookupVar (Tcl_Interp * interp, char *part1, char *part2, int flags
       ,char *msg, int createPart1, int createPart2
       ,TclVarInternal ** arrayPtrPtr);

  /** jWrap Basic States */
  typedef enum JWRAPstates {
      /** use to bypass return and give back hand to Tcl directly */
      JWRAP_PANIC_CALLED = 1,
      /** use for GCC not to complain after jWrapPanic call when gcc wants a return value */
      JWRAP_IMPOSSIBLE   = -2
  } JWRAP_states ;

// some useful macro
#define TCL_STRING(obj) obj->bytes	// this is faster than Tcl_GetStringFromObj(obj,NULL)

  /** jWrapType is a super set of Tcl type */
  typedef struct JWRAPtypes
    {
      /** Tcl type Obj as to be first in order casting to work */
      Tcl_ObjType *obj;
      /** Size of type instance used for all duplication routines */
      unsigned int size;
      /** Magic allows to know if type is a cookie, a complex type, ... */
      JWRAP_magics magic;
    }
  JWRAP_types;

  /** Define a common header for all object in hashtable */
  typedef struct JWRAPobjs
    {
      /** magic is use to know what type of object we retrieve from hashtable */
      JWRAP_magics magic;

      /** object type name */
      JWRAP_types *type;
    }
  JWRAP_objs;

  /** Define enumeration type in order transferring enum as a C array */
  typedef struct JWRAPenums
    {
      /** magic is use to know what type of object we retrieve from hashtable */
      JWRAP_magics magic;
      /** enumeration name */
      JWRAP_types *type;
      /** number of values in enum */
      int count;
      /** Enumeration Symbol a pointer a a C string */
      char **slotNames;
      /** Enumeration value as given in C/C++ interface file */
      long *slotValues;
    }
  JWRAP_enums;

  /** jWrapStructs hold an array of string containing slot name and related TclType prt */
  typedef struct JWRAPstructs
    {
      /** Magic in order finding object in hashtable */
      int         magic;
      /** A pointer to struc size, ... */
      JWRAP_types *type;
      /** Number of slot */
      int  count;
      /** List of structure slot name */
      char **slotNames;
      /** List of Tcl Obj type pointer attached to relative symbolic slot */
      JWRAP_types **slotTypes;
      /** As user can feel structure in any order we need offset to be pre-computed */
      int  *slotOffsets;
      /** Repetition number for array should be one for ordinary type */
      int  *slotArrays;
      /** Create routine can be local or WTX or ... */
      Function *createFunc;
      /** Free routine can be local or WTX or ... */
      Function *freeFunc;
      /** Cget can be local or WTX or ... */
      Function *cGetFunc;
    } JWRAP_structs;


  /** Hold C/C++ variable in a Tcl array */
  typedef struct JWRAPvars
    {
      /** Pointer to Tcl type structure */
      Tcl_Obj *tclObj;
      /** Array name point on module Class or instance name */
      Tcl_Obj *array;
      /** Variable name */
      Tcl_Obj *index;
      /** C/C++ address in Ram */
      long *address;
      /** Previous value is used to avoid useless internal to external translation */
      void *previous;
      /** variable can hole long, double or a pointer */
      JWRAP_types *jwType;
      /** Small data are hold directly in structure */
      union varInternal
	{
	  long longValue;
	  double doubleValue;
	  VOID *otherValuePtr;
	}
      internalRep;
      /** extra data slot for any specific to module supplementary informations */
      ClientData info;
    }
  JWRAP_vars;


  /** we need a union in order gcc not failing when full dynamic cast is mandatory */
  typedef struct JWRAPresults
    {
      union resultInternal
	{
	  double doubleValue;
	  long longValue;
	  void *otherValuePtr;
	}
      internalRep;
    }
  JWRAP_results;

  /**  modules help structure */
  typedef struct JWRAPmodules
    {
      /** Magic number used for jWrap show routine */
      int magic;
      /** Version stamp is set automatically by Fridu build.tcl command
          when using a non Fridu make this field is set to NULL */
      const char *version;
      /** Module Name should unique in interpretor */
      const char *name;
      /** One line help extracted from File: tag in interface file */
      const char *help;
      /** Number of available commands used to build Tcl list */
      int nbCmd;
      /** Pointer on Cmd small help [C ANSI Prototype] */
      const char **helpCmd;
      /** Pointer on Struct address */
      JWRAP_structs **structures;
      /** Pointer on Enum address */
      JWRAP_enums **enumerations;
      /** Each module as a private hashtable */
      Tcl_HashTable *hashTable;
      /** Clientdata hold any extra informations for module */
      ClientData info;
      /** pointer to next module in linked list */
      struct JWRAPmodules *next;
    }
  JWRAP_modules;

  /** Get type provide a proxy mode for subset of structure when
      using jWrap cget to retrieve only one slot from a complex
      C structure */
  typedef struct JWRAPcgets
  {
    /** This old effective internal rep of object slot inside a pointed structure
        this value as to be a pointer */
    void *valueAdr;
    /** Object of address holding this value */
    Tcl_Obj     *owner;
    /** Original type from where this slot is coming */
    Tcl_ObjType *type;
  }
  JWRAP_cgets;

  /** Varg provide a simple way to get all parameter from TCL
      in order handling variable argument an non typed interface
      of command without dealing with command creation manually
  */
  typedef struct JWRAPvarg {
    Tcl_Interp * interp;
    int        argc;
    Tcl_Obj    **argv;
  } JWRAP_varg;


#ifdef __cplusplus
}
#endif


#include "libRuntimeJwrap.i"

#endif
