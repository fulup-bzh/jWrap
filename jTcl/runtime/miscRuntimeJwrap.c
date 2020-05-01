
/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   miscCcWrap.c init routine for runtime jWrap lib
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/miscRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01e,10mar99,Fulup,added convert option
 * 01d,09nov98,Fulup,added FRIDU_LOG for default log level and file
 * 01c,17oct98,Fulup,corrected cast for cget proxy
 * 01b,03jul98,Fulup,cleanup source and jWrap options
 * 01a,18feb98,Fulup,written
 */

/** ----------------------------------------------------------------------------
 * Implement miscelleanous routine for Runtime jWrap, main routine are jWrap
 * commands, error and warning facilities.
 * @note that almost all commands from this module are used in jWrap and tornado
 * module.
 ** ----------------------------------------------------------------------------*/

#include "libRuntimeJwrap.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#ifdef PTHREAD
#include <pthread.h>
#endif
/** Static return point for jWrapPanic routine, this should be thread private in a
    future release */
EXPORT jmp_buf jWrapCheckPoint;
/** Main jWrap hash table, currently hold all system hash key, nevertheless any
    module may can overload it and use a private hash table */
EXPORT Tcl_HashTable jWrapHashTable;
/** In order helping to debug some silly GPF under window jWrapPanic error message
    is static and public*/
EXPORT char jWrapStaticMessage[255];
/* Multi used string are prepared at starting time */
EXPORT Tcl_Obj *jTclMethodInternalCallProc;
EXPORT Tcl_Obj *jWrapFreeMethod;
EXPORT Tcl_Obj *jWrapMyString;
EXPORT Tcl_Obj *jWrapExtendsString;
EXPORT Tcl_Obj *jWrapInsCountString;
/** default debug level should be 0-9 */
EXPORT int jWrapDbgValue = 1;
/** log file default is stdout */
EXPORT FILE *jWrapDbgFile = NULL;
/** Starting point of module handle linked list */
EXPORT JWRAP_modules *moduleHead = NULL;
/** Owner copyright */
EXPORT char *JWRAP_copyright = "(C)97-98 FRIDU a Free Software Company [http:www.fridu.bzh]";

/**-----------------------------------------------------------------
 * printf a debug/log message according to debugLevel and jWrapDbgFile
 * @note error message are printed with level 0
 * @param level debug level in scale [0-9]
 * @param format string format follow be arguments
 * @see   jWrap debug
 * @note  string formating is not bus error protected.
 **-----------------------------------------------------------------*/
PUBLIC void jWrapLog(int level, char *format, ...)
{

  va_list ap;
  int ind;

  va_start(ap, format);

  // if level is not hight enough return
  if (jWrapDbgValue < level)
    return;

#ifdef PTHREAD
  fprintf(jWrapDbgFile, "%6ld", pthread_self());
#endif
  {
    if (!jWrapDbgFile)
      jWrapDbgFile = stdout;

    char prefix[10];
    if (level >= 10)
      level = 9;

    for (ind = 0; ind < level; ind++)
    {
      prefix[ind] = '.';
    }
    prefix[ind] = '\0';

    // print leaving space according to level
    fprintf(jWrapDbgFile, "%-10s ", prefix);
    vfprintf(jWrapDbgFile, format, ap);
    fflush(jWrapDbgFile);
  }
}

/**-----------------------------------------------------------------
 * Format error message and return with a longjmp to calling routine
 * this entry point should only be used when a previous setjmp has been
 * done. This call is not multi-thread compatible.
 * @param interp is NULL only place message in static message else
 * place it Tcl interpretor with Tcl_AddResult
 * @param format a fprintf format followed corresponding arguments.
 * @note any error in format will result in a core dump
 **-----------------------------------------------------------------*/
PUBLIC void jWrapPanic(Tcl_Interp *interp, char *format, ...)
{

  va_list ap;
  int len;

  va_start(ap, format);

  len = vsprintf(jWrapStaticMessage, format, ap);
  // If message is bigger than 255
  if (len < 0)
  {
    strcpy(jWrapStaticMessage, "jWrapPanic message too big for Tcl result check stderr\n");
    vfprintf(stderr, format, ap);
  }

  // log message if in debu mode
  jWrapLog(1, "BREAK: %s\n", jWrapStaticMessage);

  // if interp available fill return message
  if (interp != NULL)
  {
    Tcl_AppendResult(interp, jWrapStaticMessage, NULL);
    jWrapStaticMessage[0] = '\0';
  }
  // long jump to jWrap entry point
  longjmp(jWrapCheckPoint, (int)&jWrapStaticMessage);

  va_end(ap);
}

/** ----------------------------------------------------------------------
 *   Check if user asked a list or a stdout printed listing
 *   and when a module is given check for module name existence in
 *   hash table. This command is internally used by jWrapCmd
 *   command and is private to Runtime libraries.
 ** ---------------------------------------------------------------------*/
PUBLIC JWRAP_modules *jWrapModuleCheck(int *objc, Tcl_Obj *CONST objv[], int *listAsked)
{
  JWRAP_modules *module;
  Tcl_HashEntry *entryPtr;

  // Check is list is asked
  if (!strcmp("list", TCL_STRING(objv[*objc - 1])))
  {
    *listAsked = TRUE;
    *objc = *objc - 1;
  }
  else
  {
    *listAsked = FALSE;
  }

  // no module provided
  if (!TCL_STRING(objv[2]))
    goto errNoModule;

  // Check if a valid module is given as parameter
  entryPtr = Tcl_FindHashEntry(&jWrapHashTable, TCL_STRING(objv[2]));
  if (entryPtr == NULL)
    goto errNoModule;
  module = (JWRAP_modules *)Tcl_GetHashValue(entryPtr);
  return module;

errNoModule:
  return (NULL);
}

/**-------------------------------------------------------------------
 * Build a list with module name and help line for a given module
 * @param module a valid module handle
 * @param listAsked boolean flag to choose between stdout and TCL list result
 * @param line a pointer to a list line for Tcl list return option.
 **-------------------------------------------------------------------*/
LOCAL void moduleInfo(JWRAP_modules *module, int listAsked, char **line)
{
  const char *slot[2];

  // first build a list with name and help
  slot[0] = module->name;
  slot[1] = module->help;
  if (listAsked)
  {
    *line = Tcl_Merge(2, slot);
  }
  else
  {
    fprintf(stdout, "# %-15s %s\n", module->name, module->help);
  }
}
/**-------------------------------------------------------------------
 * Build a list with module & version for a given module, In Fridu
 * environment this is automatically set to current version number
 * from common makefile Etc/project.mk file.
 * @param module a valid module handle
 * @param listAsked boolean flag to choose between stdout and TCL list result
 * @param line a pointer to a list of string for Tcl list return option.
 **-------------------------------------------------------------------*/
LOCAL void moduleVersion(JWRAP_modules *module, int listAsked, char **line)
{
  char *slot[2];

  // first build a list with name and help
  slot[0] = module->name;
  if (module->version != NULL)
  {
    slot[1] = module->version;
  }
  else
  {
    slot[1] = "No Version Stamp registrated";
  }
  if (listAsked)
  {
    *line = Tcl_Merge(2, slot);
  }
  else
  {
    fprintf(stdout, "# %-12s %s\n", module->name, module->version);
  }
}

/** -----------------------------------------------------------------
 * Build a list of a given module commands, gives for each command
 * Ansi C prototype.
 * @param module a valid module handle
 * @param listAsked boolean flag to choose between stdout and TCL list result
 * @param line a pointer to a list of string for Tcl list return option.
 ** -----------------------------------------------------------------*/
LOCAL void moduleCmd(JWRAP_modules *module, int listAsked, char **line)
{
  int ind;

  if (listAsked)
  {
    *line = Tcl_Merge(module->nbCmd, module->helpCmd);
  }
  else
  {
    fprintf(stdout, "#\n## --- Module: %s\n", module->name);
    for (ind = 0; ind < module->nbCmd; ind++)
    {
      fprintf(stdout, "# %-2d: %s\n", ind, module->helpCmd[ind]);
    }
  }
}

/**-----------------------------------------------------------------------
 * jWrap command is the generic entry point for jWrap complex type and
 * structure mapping.
 * @param cld not used
 * @param interp current Tcl interpretor
 * @param objc  number of parameters coming from Tcl
 * @param objv_Ptr_Ptr an array of Tcl object pointer holding affective
 * user given paramters.
 * @see user manual for detailed options.
 **-----------------------------------------------------------------------*/
LOCAL int jWrapCmd(ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])

{
  JWRAP_modules *module;
  int listAsked;
  JWRAP_objs *hashObj;
  JWRAP_structs *structure;
  int status = TCL_OK;
  char name[JWRAP_MAX_NAME];
  int nbModule = 0;
  char *result;
  Tcl_Obj *tclObj;
  Tcl_Obj *refObj;
  long refValue;
  Tcl_ObjType *tclType;
  Tcl_HashEntry *entryPtr;
  int ind;
  Function *callBack;
  char **line = NULL;
  static char *arrayOptions[] = {"help", "info", "struct", "cmd", "enum", "handle", "debug", "type", "sizeof", "new", "cast", "cget", "equal", "version", "copyright", "perror", "convert", "forget", "isnull", (char *)NULL};

  // prepare emergency panic return
  if (setjmp(jWrapCheckPoint))
  {
    if (jWrapStaticMessage[0] != '\0')
    {
      Tcl_SetResult(interp, jWrapStaticMessage, TCL_STATIC);
    }
    return TCL_ERROR;
  }

  // check we have module registrated
  if (moduleHead == NULL)
    goto errNoModule;

  // In all other case we check input parameters
  if (objc < 2)
    goto errSyntax;
  if (Tcl_GetIndexFromObj(interp, objv[1], arrayOptions, "option",
                          0, &ind) != TCL_OK)
  {
    return TCL_ERROR;
  }

  // process commands
  switch (ind)
  {
  case 0: // help
    Tcl_AppendResult(interp, "syntax: jWrap [", NULL);
    for (ind = 0; arrayOptions[ind] != NULL; ind++)
    {
      Tcl_AppendResult(interp, arrayOptions[ind], "|", NULL);
    }
    Tcl_AppendResult(interp, "]", NULL);
    break;

  case 1: // info
    module = jWrapModuleCheck(&objc, objv, &listAsked);
    if ((objc > 2) && (module == NULL))
      goto errModuleName;

    if (!listAsked)
    {
      fprintf(stdout, "\n## --- Loaded jWrap Modules ---\n");
    }

    // Either loop on all module or not
    if (module != NULL)
    {
      moduleInfo(module, listAsked, &result);
    }
    else
    {
      for (module = moduleHead; module != NULL; module = module->next)
        nbModule++;
      {
        line = (char **)Tcl_Realloc((void *)line, sizeof(char *) * nbModule);
        ind = 0;

        // build a Tcl list with module Name and module Info
        for (module = moduleHead; module != NULL; module = module->next)
        {
          moduleInfo(module, listAsked, &line[ind]);
          ind++;
        }
        if (listAsked)
        {
          // build a list with all modules lines
          result = Tcl_Merge(nbModule, line);
          // free an intermediate lines
          for (ind = 0; ind < nbModule; ind++)
            Tcl_Free(line[ind]);
        }
      } // end block

      // free tempry RAM area
      Tcl_Free((void *)line);
    }
    if (listAsked)
    {
      Tcl_SetResult(interp, result, Tcl_Free);
    }
    else
    {
      fprintf(stdout, "## ---\n");
    }

    break;

  case 2: // struct

    module = jWrapModuleCheck(&objc, objv, &listAsked);
    if ((objc > 2) && (module == NULL))
      goto errModuleName;
    if (!listAsked)
    {
      fprintf(stdout, "\n## --- Added jWrap C/C++ Complex Structures ---\n");
    }

    // Either loop on all module or not
    if (module != NULL)
    {
      jWrapTypeHelp(module, listAsked, &result);
    }
    else
    {
      for (module = moduleHead; module != NULL; module = module->next)
        nbModule++;
      line = (char **)Tcl_Realloc((void *)line, sizeof(char *) * nbModule);
      ind = 0;

      // build a Tcl list with moduleName and moduleInfo
      for (module = moduleHead; module != NULL; module = module->next)
      {
        jWrapTypeHelp(module, listAsked, &line[ind]);
        ind++;
      }
      if (listAsked)
      {
        // build a list with all modules lines
        result = Tcl_Merge(nbModule, line);
        // free an intermediate lines
        for (ind = 0; ind < nbModule; ind++)
          Tcl_Free(line[ind]);
      }
      // free tempry RAM area
      Tcl_Free((void *)line);
    }
    if (listAsked)
    {
      Tcl_SetResult(interp, result, Tcl_Free);
    }
    else
    {
      fprintf(stdout, "## ---\n");
    }
    break;

  case 3: // cmd

    module = jWrapModuleCheck(&objc, objv, &listAsked);
    if ((objc > 2) && (module == NULL))
      goto errModuleName;
    if (!listAsked)
    {
      fprintf(stdout, "\n## --- Added jWrap C/C++ Commands ---\n");
    }

    // Either loop on all module or not
    if (module != NULL)
    {
      moduleCmd(module, listAsked, &result);
    }
    else
    {
      for (module = moduleHead; module != NULL; module = module->next)
        nbModule++;
      line = (char **)Tcl_Realloc((void *)line, sizeof(char *) * nbModule);
      ind = 0;

      // build a Tcl list with moduleName and moduleInfo
      for (module = moduleHead; module != NULL; module = module->next)
      {
        moduleCmd(module, listAsked, &line[ind]);
        ind++;
      }
      if (listAsked)
      {
        // build a list with all modules lines
        result = Tcl_Merge(nbModule, line);
        // free an intermediate lines
        for (ind = 0; ind < nbModule; ind++)
          Tcl_Free(line[ind]);
      }
      // free tempry RAM area
      Tcl_Free((void *)line);
    }
    if (listAsked)
    {
      Tcl_SetResult(interp, result, Tcl_Free);
    }
    else
    {
      fprintf(stdout, "## ---\n");
    }
    break;

  case 4: // enum
    module = jWrapModuleCheck(&objc, objv, &listAsked);
    if ((objc > 2) && (module == NULL))
      goto errModuleName;
    if (!listAsked)
    {
      fprintf(stdout, "\n## --- Added jWrap C/C++ Enumerations ---\n");
    }

    // Either loop on all module or not
    if (module != NULL)
    {
      jWrapEnumHelp(module, listAsked, &result);
    }
    else
    {
      for (module = moduleHead; module != NULL; module = module->next)
        nbModule++;
      {
        line = (char **)Tcl_Realloc((void *)line, sizeof(char *) * nbModule);
        ind = 0;

        // build a Tcl list with moduleName and moduleInfo
        for (module = moduleHead; module != NULL; module = module->next)
        {
          jWrapEnumHelp(module, listAsked, &line[ind]);
          ind++;
        }
        if (listAsked)
        {
          // build a list with all modules lines
          result = Tcl_Merge(nbModule, line);
          // free an intermediate lines
          for (ind = 0; ind < nbModule; ind++)
            Tcl_Free(line[ind]);
        }
      } // end block
      // free tempry RAM area
      Tcl_Free((void *)line);
    }
    if (listAsked)
    {
      Tcl_SetResult(interp, result, Tcl_Free);
    }
    else
    {
      fprintf(stdout, "## ---\n");
    }
    break;

  case 5: // handle
    entryPtr = Tcl_FindHashEntry(&jWrapHashTable, TCL_STRING(objv[2]));
    if (entryPtr == NULL)
      goto errUnknowHandle;
    tclObj = Tcl_NewLongObj((long)Tcl_GetHashValue(entryPtr));
    Tcl_SetObjResult(interp, tclObj);
    break;

  case 6: // debug
    // Try to set debug level
    if (Tcl_GetIntFromObj(interp, objv[objc - 1], &jWrapDbgValue) != TCL_OK)
      goto errDbgLvl;
    if (objc == 4)
    {
      // try opening debug file
      jWrapDbgFile = fopen(TCL_STRING(objv[2]), "w+");
      if (jWrapDbgFile == NULL)
      {
        jWrapDbgFile = stderr;
        goto errDbgFile;
      }
    }
    break;

  case 7: // type
    if (objv[2]->typePtr != NULL)
    {
      if (objv[2]->typePtr == &jWrapTypeTclObj)
      {
        // when facing a cget we return both cget type and contained type
        JWRAP_cgets *cget;
        cget = objv[2]->internalRep.twoPtrValue.ptr1;
        Tcl_SetResult(interp, objv[2]->typePtr->name, TCL_STATIC);
        Tcl_AppendElement(interp, cget->type->name);
      }
      else
      {
        // This is a ordinary Tcl type
        Tcl_SetResult(interp, objv[2]->typePtr->name, TCL_STATIC);
      }
    }
    else
    {
      // TclString a not type we provide something acceptable
      Tcl_SetResult(interp, "TclString", TCL_STATIC);
    }
    break;

  case 8: // sizeof
    sprintf(name, "OBJ_%s", objv[2]->bytes);
    entryPtr = Tcl_FindHashEntry(&jWrapHashTable, name);
    if (entryPtr == NULL)
      goto errSizeof;
    structure = (JWRAP_structs *)Tcl_GetHashValue(entryPtr);

    // return structure size
    Tcl_SetObjResult(interp, Tcl_NewIntObj((int)structure->type->size));

    break;

  case 9: // new
    if (objc != 4)
      goto errNew;
    // search for structure of type name in hashtable
    sprintf(name, "OBJ_%s", TCL_STRING(objv[2]));
    entryPtr = Tcl_FindHashEntry(&jWrapHashTable, name);
    if (entryPtr == NULL)
      goto errName;
    hashObj = (JWRAP_objs *)Tcl_GetHashValue(entryPtr);

    switch (hashObj->magic)
    {
    case JWRAP_ENUM:
      // if no external rep build it now
      if ((objv[3]->bytes == NULL) && (objv[3]->typePtr != NULL))
      {
        ((Function *)objv[3]->typePtr->setFromAnyProc)(interp, objv[3], NULL);
      }
      // effectivelly translate or object
      status = jWrapEnumTcl2Cc(interp, (JWRAP_enums *)hashObj, objv[3]);
      Tcl_SetObjResult(interp, objv[3]);
      break;

    case JWRAP_UNION:
    case JWRAP_STRUCT:
      // repare result object placing a copy of original object in
      tclObj = Tcl_GetObjResult(interp);

      // magic is not enought to know with routine as to be used
      callBack = ((JWRAP_structs *)hashObj)->createFunc;
      if (callBack == NULL)
        goto errCallBack;
      status = (*callBack)(interp, (JWRAP_structs *)hashObj, objv[3], tclObj);
      break;
    default:
      goto unknowObject;
    }
    break;

  case 10: // cast
    if (objc != 4)
      goto errCast;

    // Check given Type is a Tcl type
    tclType = Tcl_GetObjType(TCL_STRING(objv[2]));
    if (tclType == NULL)
      goto errUnknowType;

    // When facing a tcl string
    if (objv[3]->typePtr == NULL)
    {
      // Try to convert string to an int if not possible take it as a full string
      if (Tcl_ConvertToType(interp, objv[3], jWrapTypeInt) != TCL_OK)
      {
        // make a proper char* with given buffer
        jWrapStringPtrType.setFromAnyProc(interp, objv[3]);
      }
    }

    // result is alway a new object
    tclObj = Tcl_NewObj();

    // If object to cast is a proxy we retreive original object
    if (objv[3]->typePtr == &jWrapTypeTclObj)
    {
      JWRAP_cgets *cget;
      cget = (JWRAP_cgets *)objv[3]->internalRep.twoPtrValue.ptr1;
      refObj = cget->owner;
      refValue = (long)cget->valueAdr;
    }
    else
    {
      refObj = objv[3];
      refValue = objv[3]->internalRep.longValue;
    }

    // if new type as a free proc build a cget type
    if (tclType->freeIntRepProc != NULL)
    {
      JWRAP_cgets *cget;
      cget = (JWRAP_cgets *)Tcl_Alloc(sizeof(JWRAP_cgets));

      cget->valueAdr = (void *)refValue;
      Tcl_IncrRefCount(refObj);
      cget->owner = refObj;
      cget->type = tclType;

      // Return cget object to user
      tclObj->internalRep.twoPtrValue.ptr1 = (void *)cget;
      tclObj->internalRep.twoPtrValue.ptr2 = NULL;
      tclObj->typePtr = &jWrapTypeTclObj;
      tclObj->bytes = NULL;
    }
    else
    {
      // as object as no free prc internal is a max of double
      tclObj->internalRep.longValue = refValue;
      tclObj->typePtr = tclType;
      tclObj->bytes = NULL;
    }

    // set new object as result
    Tcl_SetObjResult(interp, tclObj);
    break;

  case 11: // cGet return on slot from structure
    if (objc != 4)
      goto errCget;
    if (objv[2]->typePtr == NULL)
    {
      strcpy(name, "TclString");
      goto errName;
    }
    // for Cget object retreive original type
    if (objv[2]->typePtr == &jWrapTypeTclObj)
    {
      JWRAP_cgets *cget;
      cget = objv[2]->internalRep.twoPtrValue.ptr1;
      sprintf(name, "OBJ_%s", cget->type->name);
    }
    else
    {
      sprintf(name, "OBJ_%s", objv[2]->typePtr->name);
    }
    entryPtr = Tcl_FindHashEntry(&jWrapHashTable, name);
    if (entryPtr == NULL)
      goto errName;
    hashObj = (JWRAP_objs *)Tcl_GetHashValue(entryPtr);

    // check call back exist
    callBack = ((JWRAP_structs *)hashObj)->cGetFunc;
    if (callBack == NULL)
      goto errCallBack;

    // Get one slot object from our complex obj
    (*callBack)(interp, (JWRAP_structs *)hashObj, objv[2], objv[3]);

    break;

  case 12: // equal test internal rep
    if (objc != 4)
      goto errEqual;
    // Check both object have an internal type
    if (objv[2]->typePtr == 0)
    {
      strcpy(name, TCL_STRING(objv[2]));
      goto errNotTyped;
    }
    if (objv[3]->typePtr == 0)
    {
      strcpy(name, TCL_STRING(objv[3]));
      goto errNotTyped;
    }

    // for cget object retrieve original type
    if (objv[2]->typePtr == &jWrapTypeTclObj)
    {
      JWRAP_cgets *cget;
      cget = objv[2]->internalRep.twoPtrValue.ptr1;

      // Get Object result and place result of test
      if (cget->valueAdr == objv[3]->internalRep.twoPtrValue.ptr1)
      {
        tclObj = Tcl_NewBooleanObj(TRUE);
      }
      else
      {
        tclObj = Tcl_NewBooleanObj(FALSE);
      }
    }
    else
    {
      // Get Object result and place result of test
      if (objv[2]->internalRep.longValue == objv[3]->internalRep.longValue)
      {
        tclObj = Tcl_NewBooleanObj(TRUE);
      }
      else
      {
        tclObj = Tcl_NewBooleanObj(FALSE);
      }
    }

    Tcl_SetObjResult(interp, tclObj);
    break;

  case 13: // version
    module = jWrapModuleCheck(&objc, objv, &listAsked);
    if ((objc > 2) && (module == NULL))
      goto errModuleName;

    if (!listAsked)
    {
      fprintf(stdout, "\n## --- Version Stamp jWrap Modules ---\n");
    }

    // Either loop on all module or not
    if (module != NULL)
    {
      moduleVersion(module, listAsked, &result);
    }
    else
    {
      for (module = moduleHead; module != NULL; module = module->next)
        nbModule++;
      {
        line = (char **)Tcl_Realloc((void *)line, sizeof(char *) * nbModule);
        ind = 0;

        // build a Tcl list with moduleName and moduleInfo
        for (module = moduleHead; module != NULL; module = module->next)
        {
          moduleVersion(module, listAsked, &line[ind]);
          ind++;
        }
        if (listAsked)
        {
          // build a list with all modules lines
          result = Tcl_Merge(nbModule, line);
          // free an intermediate lines
          for (ind = 0; ind < nbModule; ind++)
            Tcl_Free(line[ind]);
        }
      } // end block
      // free tempry RAM area
      Tcl_Free((void *)line);
    }
    if (listAsked)
    {
      Tcl_SetResult(interp, result, Tcl_Free);
    }
    else
    {
      fprintf(stdout, "## ---\n");
    }

    break;

  case 14: // copyright

    if (!listAsked)
    {
      fprintf(stdout, "%s\n", JWRAP_copyright);
    }
    else
    {
      Tcl_SetResult(interp, JWRAP_copyright, TCL_STATIC);
    }

    break;

  case 15: // perror
    Tcl_SetResult(interp, jWrapStaticMessage, TCL_STATIC);
    break;

  case 16: // convert from the external rep

    if (objc != 4)
      goto errConvert;

    // Check given Type is a Tcl type
    tclType = Tcl_GetObjType(TCL_STRING(objv[2]));
    if (tclType == NULL)
      goto errUnknowType;

    // result is alway a new object
    tclObj = Tcl_NewObj();

    // original external rep is not accurate update it now
    if (TCL_STRING(objv[3]) == NULL)
    {
      jWrapStringPtrType.setFromAnyProc(interp, objv[3]);
    }

    // copy original rep
    tclObj->bytes = (char *)Tcl_Alloc(objv[3]->length + 1);
    memcpy(tclObj->bytes, objv[3]->bytes, objv[3]->length + 1);

    // convert to wanted type now
    status = Tcl_ConvertToType(interp, tclObj, tclType);
    if (status != TCL_OK)
      goto errConvertType;

    // set new object as result
    Tcl_SetObjResult(interp, tclObj);
    break;

  case 17: // forget clear type in order free not to work on internal rep
    if (objc != 3)
      goto errForget;

    // clean type an internal value
    objv[2]->typePtr = NULL;
    objv[2]->internalRep.twoPtrValue.ptr1 = NULL;
    status = TCL_OK;

    break;

  case 18: // isnull check is both external and internal representation equal NULL
    if (objc != 3)
      goto errForget;

    // if we have a type and internal is not zero we're good
    if (objv[2]->typePtr)
    {

      // we have an internal representation
      if (objv[2]->internalRep.twoPtrValue.ptr1)
      {
        tclObj = Tcl_NewBooleanObj(FALSE);
        Tcl_SetObjResult(interp, tclObj);
        status = TCL_OK;
        break;
      }

      // if we have an external represention let's update the object
      if (objv[2]->length >0 && objv[2]->typePtr->setFromAnyProc)
      {
        objv[2]->typePtr->setFromAnyProc(interp, objv[2]);
        if (objv[2]->internalRep.twoPtrValue.ptr1)
        {
          tclObj = Tcl_NewBooleanObj(FALSE);
          Tcl_SetObjResult(interp, tclObj);
          status = TCL_OK;
          break;
        }
      }
      tclObj = Tcl_NewBooleanObj(TRUE);
      Tcl_SetObjResult(interp, tclObj);
      status = TCL_OK;
    }
    else
    {
      if (!objv[2]->length)
      {
        tclObj = Tcl_NewBooleanObj(FALSE);
        Tcl_SetObjResult(interp, tclObj);
        status = TCL_OK;
        break;
      }
    }

    tclObj = Tcl_NewBooleanObj(TRUE);
        Tcl_SetObjResult(interp, tclObj);
    status = TCL_OK;
    break;

  } // end switch

  return status;

errCallBack:
  Tcl_AppendResult(interp, "\nERROR: internal callback NULL rewrap with a new version\n", NULL);
  return (TCL_ERROR);

errModuleName:
  Tcl_AppendResult(interp, "\nERROR: Unknow jWrap Module [", TCL_STRING(objv[objc - 1]), "]", NULL);
  return (TCL_ERROR);

errSyntax:
  Tcl_AppendResult(interp, "\nERROR: Syntax jWrap option [ex: jWrap help]", NULL);
  return (TCL_ERROR);

errNoModule:
  Tcl_AppendResult(interp, "\nERROR: jWrap no module registrated\n", NULL);
  return (TCL_ERROR);

errUnknowHandle:
  Tcl_AppendResult(interp, "\nUnknown C++ Object in HashTable for jTcl handle=", TCL_STRING(objv[2]), NULL);
  return (TCL_ERROR);

errDbgLvl:
  Tcl_AppendResult(interp, "\nsyntaxe:= jWrap debug [file] level should be 0-9 not:", TCL_STRING(objv[2]), NULL);
  return (TCL_ERROR);

errName:
  Tcl_AppendResult(interp, "\nERROR: jWrap new unknow structure:", TCL_STRING(objv[2]), NULL);
  return (TCL_ERROR);

errDbgFile:
  Tcl_AppendResult(interp, "\njWrap Debug could not open debug log file:", TCL_STRING(objv[2]), NULL);
  return (TCL_ERROR);

errNew:
  Tcl_AppendResult(interp, "ERROR: Syntax:= jWrap new Type Value\n", NULL);
  return (TCL_ERROR);

errCast:
  Tcl_AppendResult(interp, "ERROR: Syntaxe:= jWrap cast type $Var\n", NULL);
  return (TCL_ERROR);

errUnknowType:
  Tcl_AppendResult(interp, "ERROR: jWrap cast [", TCL_STRING(objv[2]), "] unknow type\n", NULL);
  return (TCL_ERROR);

errCget:
  Tcl_AppendResult(interp, "ERROR: Syntaxe:= jWrap cget $Var slot\n", NULL);
  return (TCL_ERROR);

unknowObject:
  Tcl_AppendResult(interp, "ERROR: Invalid magic for hashtable object [", hashObj->type->obj->name, "]\n", NULL);
  return (TCL_ERROR);

errEqual:
  Tcl_AppendResult(interp, "ERROR: Syntaxe:= jWrap equal $Var Value\n", NULL);
  return (TCL_ERROR);

errNotTyped:
  Tcl_AppendResult(interp, "ERROR: Tcl Variable is not typed [", name, "]", NULL);
  return (TCL_ERROR);

errSizeof:
  Tcl_AppendResult(interp, "ERROR: jWrap size [", name, "]", " is not a valid jWrap struct", NULL);
  return (TCL_ERROR);

errConvert:
  Tcl_AppendResult(interp, "ERROR: Syntaxe:= jWrap convert type $Var\n", NULL);
  return (TCL_ERROR);

errConvertType:
  Tcl_AppendResult(interp, "Failled to convert [", objv[3]->bytes, "] into [", objv[2]->bytes, "]\n", NULL);
  return (TCL_ERROR);

errForget:
  Tcl_AppendResult(interp, "ERROR: Syntaxe:= jWrap forget $Var\n", NULL);
  return (TCL_ERROR);

} // end jWrapCmd

/**-------------------------------------------------------------------------
 * Registrate a new module in jWrap modules list. This create a new entry
 * in module hashtable and update moduleList linked list.
 **-------------------------------------------------------------------------*/
PUBLIC void jWrapModuleRegister(Tcl_Interp *interp, JWRAP_modules *module)
{

  static JWRAP_modules *moduleTail;
  Tcl_HashEntry *entryPtr;
  int new;

  // Only registrated valid module structure
  if (module->magic != JWRAP_MODULE)
    goto errMagic;

  // Store help message in common hashtable
  entryPtr = Tcl_CreateHashEntry(&jWrapHashTable, module->name, &new);
  if (!new)
    goto alreadyRegister;
  Tcl_SetHashValue(entryPtr, (ClientData)module);

  // Take global hashtable as module default
  module->hashTable = &jWrapHashTable;

  // append new module to linked list
  if (moduleHead == NULL)
  {
    moduleHead = module;
  }
  else
  {
    moduleTail->next = module;
  }
  moduleTail = module;

  return;

alreadyRegister:
  jWrapPanic(NULL, "Try to register same module %s twice", module->name);

errMagic:
  jWrapPanic(NULL, "Try to registrated a non valid module structure magic=%d", module->magic);
} // end jWrapRegistrateModule

/**-------------------------------------------------------------------------
 * When extending a C++ class we check if class is not already present
 * in C++, if then we add all public methods to new jTcl class array.
 * @note this routine should be moved to an other C file.
 * @param interp current TCL interpretor
 * @param extendClass string with target class
 * @param super class string
 **-------------------------------------------------------------------------*/
PUBLIC void jWrapExtendClass(Tcl_Interp *interp, char *extendClass, char *superClass)
{
  TclVarInternal *extendPtr, *superPtr, *slotPtr, *arrayPtr;
  Tcl_HashEntry *extendEntry, *superEntry;
  Tcl_HashSearch search;
  char *slotName;
  int new;

  // Try to get array pointer and return if class is not registrated in jTcl
  superPtr = TclLookupVar(interp, superClass, (char *)NULL, TCL_GLOBAL_ONLY,
                          /*msg*/ 0, /*createPart1*/ 0, /*createPart2*/ 0, &arrayPtr);
  if (superPtr == NULL)
    return;

  // get original class array
  extendPtr = TclLookupVar(interp, extendClass, (char *)NULL, TCL_GLOBAL_ONLY,
                           /*msg*/ 0, /*createPart1*/ 0, /*createPart2*/ 0, &arrayPtr);
  if (extendPtr == NULL)
    goto invalidClass;

  // loop on super class hash and transfer to target class
  for (superEntry = Tcl_FirstHashEntry(superPtr->value.tablePtr, &search); superEntry != NULL; superEntry = Tcl_NextHashEntry(&search))
  {

    // scan array hashtable values
    slotPtr = (TclVarInternal *)Tcl_GetHashValue(superEntry);

    // get slot name from hashtable and ignore if "my"
    slotName = Tcl_GetHashKey(superPtr->value.tablePtr, superEntry);
    if (!strcmp(TCL_STRING(jWrapMyString), slotName))
      continue;
    if (!strcmp(TCL_STRING(jWrapExtendsString), slotName))
      continue;

    // we hardcopy original slot from super class into extended class
    extendEntry = Tcl_CreateHashEntry(extendPtr->value.tablePtr, slotName, &new);
    Tcl_SetHashValue(extendEntry, (ClientData)slotPtr);

  } // end for

  return;

invalidClass:
  jWrapPanic(NULL, "jWrapClassExtend %s is not a valid Tcl global variable", extendClass);

} // end jWrapExtendClass

/**---------------------------------------------------------------
 * Init module create global hashtable, create jWrap command in tcl
 * and build some common string tcl object to boost further
 * operations.
 * @param interp current TCL interpretor.
 **---------------------------------------------------------------*/
PUBLIC void jWrapMiscInit(Tcl_Interp *interp)
{
  char *loginfo;
  int status;

  // Init CC object handle hashtable
  Tcl_InitHashTable(&jWrapHashTable, TCL_STRING_KEYS);

  // register jWrap command in TCL interp
  Tcl_CreateObjCommand(interp, "jWrap", jWrapCmd, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

  // create some common object
  jTclMethodInternalCallProc = jWrapStringNew("lang.object.call", -1);
  jWrapFreeMethod = jWrapStringNew("free", -1);
  jWrapMyString = jWrapStringNew("my", -1);
  jWrapExtendsString = jWrapStringNew("extends", -1);
  jWrapInsCountString = jWrapStringNew("instanceCounter", -1);

  jWrapVarInit(interp);
  jWrapStringInit(interp);
  jWrapInterpInit(interp);
  jWrapTypeInit(interp);

  // check for FRIDU_LOG_LEVEL
  loginfo = getenv("FRIDU_LOG_LEVEL");
  if (loginfo != NULL)
  {
    status = sscanf(loginfo, "%d", &jWrapDbgValue);
    if (status != 1)
      goto errLevel;
  }

  // check log output file
  loginfo = getenv("FRIDU_LOG_FILE");
  if (loginfo != NULL)
  {
    jWrapDbgFile = fopen(loginfo, "w+");
    if (jWrapDbgFile != NULL)
      goto errFile;
  }

  return;

errLevel:
  jWrapPanic(interp, "jWrapMiscInit: FRIDU_LOG_LEVEL invalid numeric value [%s]\n", loginfo);

errFile:
  jWrapPanic(interp, "jWrapMiscInit: FRIDU_LOG_FILE invalid output file [%s]\n", loginfo);
} // end localInit
