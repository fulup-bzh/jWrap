/*
 *      Copyright(c) 1996-99 FRIDU a Free Software Company Philipppe Le Foll
 *
 * File         : ModuleRuntimeTornado.c load/unload/list of Object module
 * Projet       : jWrap
 * SubModule    : WTX VxWorks Tornado Interface
 * Auteur       : Fulup Le Foll (Fulup@fridu.bzh)
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/22 08:58:02 $
 *      Revision    : $Revision: 1.4 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/moduleRuntimeTornado.c,v $
 *
 * Modificatin History
 * -------------------
 * 1.4  1999/03/22 Fulup,changed ModuleLoad to return moduleId
 * 1.3  1999/02/16 Fulup,externalized WTX module 
 * 1.2  1998/05/06 Fulup,adapted to jWrap 
 * 1.1  1996/05/13 Fulup,written from pad example
 */

/** --------------------------------------------------------------
 ** Provides facilities for modules managment on target from tclsh
 ** --------------------------------------------------------------*/
#include <libRuntimeTornado.h>
#include <string.h>
#include <loadlib.h>

/**-------------------------------------------------
 **  Load and objet module onto target
 **  @param  tornadoId Tornado handle
 **  @param  objPath a valid object filename
 **  @return a wtx object handle or raise an error exception
 **  with jWrapPanic.
 **  @see tornadoModuleUnload
 **------------------------------------------------*/
PUBLIC long tornadoModuleLoad (TORNADO_id * tornadoId, char *objPath)
{
  WTX_LD_M_FILE_DESC *objId;
  WTX_LD_M_FILE_DESC *pFileDescIn;
  long               moduleId;

  /* unspecified value of pFileDescIn must be set to zero */
  pFileDescIn = (WTX_LD_M_FILE_DESC*) Tcl_Alloc (sizeof (WTX_LD_M_FILE_DESC));
  if (pFileDescIn == NULL) goto errMalloc;
  memset (pFileDescIn, 0,sizeof (WTX_LD_M_FILE_DESC));

  /* try to load objet module onto target */
  pFileDescIn->filename = objPath;
  pFileDescIn->loadFlag = LOAD_GLOBAL_SYMBOLS;

  objId = wtxObjModuleLoad (tornadoId->wtxId, pFileDescIn);
  if (objId == (WTX_LD_M_FILE_DESC *) NULL) goto errLoad;

  // only moduleId is needed to unload
  moduleId = objId->moduleId;

  // free input and wtx result
  Tcl_Free ((void*)pFileDescIn);
  wtxResultFree (tornadoId->wtxId, objId);

  return moduleId;

  /* ----------------- ERROR ----------- */
 errLoad:
   jWrapPanic (NULL,"ERROR: tornadoModuleLoad can't load: %s [%s]\n"
	      ,objPath, wtxErrMsgGet (tornadoId->wtxId));
 errMalloc:
   jWrapPanic (NULL,"ERROR: tornadoModuleLoad can't malloc file input struct\n");

   return JWRAP_IMPOSSIBLE; // for gcc not to complain
}				/* end tornadoModuleLoad */

/**--------------------------------------------------------
 **  Unload and objet module from target
 ** @param tornadoId Tornado handle
 ** @objId a valid obect handle from tornadoModuleLoad
 ** @return an OK status or raise an error thru jWrapPanic
 **---------------------------------------------------------*/
PUBLIC UINT32 tornadoModuleUnload (TORNADO_id * tornadoId, WTX_LD_M_FILE_DESC* objId)
{
  STATUS status;

  status = wtxObjModuleUnload (tornadoId->wtxId, objId->moduleId);
  if (status == ERROR) goto errUnload;

  return status;

  /* ----------------- ERROR ----------- */
 errUnload:
   jWrapPanic (NULL,"ERROR: tornadoModuleUnload can't unload: %d [%s]\n"
	       ,objId, wtxErrMsgGet (tornadoId->wtxId));

   return (UINT32)JWRAP_IMPOSSIBLE; // for gcc not to complain
}				/* end tornadoModuleLoad */

/**-------------------------------------------------------
 **  List loaded module [from pad example], print on stdout
 **  a list of currentelly moaded object module in target
 **  @bug does not return a tcl list
 **-------------------------------------------------------*/
PUBLIC STATUS tornadoModuleList (TORNADO_id * tornadoId)
{
  WTX_MODULE_LIST *moduleList;
  UINT32 moduleIdx;
  WTX_MODULE_INFO *moduleInfo;

  if ((moduleList = wtxObjModuleList (tornadoId->wtxId)) == NULL)
    { goto errObjModList;}

  printf ("\nThere is %d module loaded\n", moduleList->numObjMod);
  printf ("----------------------------\n");

  for (moduleIdx = 0; moduleIdx < moduleList->numObjMod; moduleIdx++)
    {
      if ((moduleInfo = wtxObjModuleInfoGet (tornadoId->wtxId,
				 moduleList->modIdList[moduleIdx])) == NULL)
	{ goto errObjInfo;}

      printf ("%x - %s: %s format, group %d\n",
	      moduleInfo->moduleId,
	      moduleInfo->moduleName,
	      moduleInfo->format,
	      moduleInfo->group);
    }

  wtxResultFree (tornadoId->wtxId, moduleList);
  wtxResultFree (tornadoId->wtxId, moduleInfo);
  printf ("----------------------------\n");

  return TORNADO_OK;

  /* ------------------ ERROR -------------------- */
 errObjModList:
  jWrapPanic  (NULL,"ERROR: can't list loaded module [%s]\n"
	      ,wtxErrMsgGet (tornadoId->wtxId));

 errObjInfo:
  jWrapPanic (NULL,"ERROR: can't get info about module %x WTXERR=[%s]\n"
               ,moduleList->modIdList[moduleIdx], wtxErrMsgGet (tornadoId->wtxId));

  return JWRAP_IMPOSSIBLE;
}				/* end tornadoListModules */

/** ----------------------------------------------------------------
 ** Loops on all Tornado module in order geting from target
 ** jWrap componant function adress and prepare wtxCts context
 ** function call, in order not calling tornadoExecSymFind at each call.
 ** @param tornadoId Tornado handle
 ** @moduleName should be a valid jWrap module
 ** @return none or raise an error execption with number of unresoleved
 ** external references.
 ** @see jWrap--implement
 ** @see tornadoModuleErrorGet
 ** ----------------------------------------------------------------*/
PUBLIC void tornadoModuleBind (TORNADO_id *tornadoId, char *moduleName, TORNADO_bindflag lazy) {
 WTX_SYMBOL    *wtxSymId;
 TORNADO_infos *info;
 JWRAP_modules *module;
 Tcl_HashEntry *entryPtr;
 int           unresolved=0;
 int           ind;

 // Check if a valid module is given as parameter
 entryPtr = Tcl_FindHashEntry (&jWrapHashTable,moduleName);
 if (entryPtr == NULL) goto errNotTornadoModule;

 module = (JWRAP_modules*) Tcl_GetHashValue (entryPtr);

 // Check we receveived a valid Tornado module 
 info = (TORNADO_infos*) module->info;
 if (info->magic != TORNADO_INFO_MAGIC) goto errNotTornadoModule;

 // Save user param that TCL garbage collector can free at anytime
 memcpy (info->tornadoId, tornadoId, sizeof (TORNADO_id));

 // Loop on all Tornado module functions name and get target adress
 for (ind=0; info->nameCmd [ind] != NULL; ind++) {
    // using WTX low level in order grouping errors 
    if (lazy == BIND_NOW) {
      wtxSymId  = wtxSymFind (tornadoId->wtxId, info->nameCmd [ind], 0, FALSE, 0, 0);
      if (wtxSymId == NULL) {
        unresolved ++;
        info->wtxCtx[ind].entry = 0;
      } else {
        info->wtxCtx[ind].entry = wtxSymId->value;
      }
    } 
    info->wtxCtx[ind].name      = info->nameCmd [ind];
    info->wtxCtx[ind].redirOut  = tornadoId->vOut;
 }

 if (unresolved >0) goto errUnresolved;

 return; // ---------- OK -----------

errNotTornadoModule:
 jWrapPanic (NULL, "tornadoModuleBind module=%s is not a Tornado/Tornado module\n",moduleName);

errUnresolved:
 jWrapPanic (NULL, "tornadoModuleBind module=%s %d unresolved references\n",moduleName,unresolved);
 
}

/** ----------------------------------------------------------------
 ** scan module entry point in order returning list of unresolved
 ** external references.
 ** @return unresolved references in list of char*
 ** @see tornadoModuleBind
 ** @param moduleName module name string
 ** ----------------------------------------------------------------*/
PUBLIC char** tornadoModuleUnresolved (char *moduleName) {
 TORNADO_infos     *info;
 JWRAP_modules *module;
 Tcl_HashEntry *entryPtr;
 int           ind;
 int           unresolved=0;
 char          **result;

 // Check if a valid module is given as parameter
 entryPtr = Tcl_FindHashEntry (&jWrapHashTable,moduleName);
 if (entryPtr == NULL) goto errNotTornadoModule;

 module = (JWRAP_modules*) Tcl_GetHashValue (entryPtr);

 // Check we receveived a valid Tornado module 
 info = (TORNADO_infos*) module->info;
 if (info->magic != TORNADO_INFO_MAGIC) goto errNotTornadoModule;

 // Count unresolved references
 for (ind=0; info->nameCmd [ind] != NULL; ind++) {
    if (info->wtxCtx[ind].entry == 0) unresolved ++;
 }

 if (unresolved == 0) goto errUnresolved;

 // return result in a jWrap char** list 
 result = (char**) Tcl_Alloc ((1+unresolved)*sizeof (char*));
 if (result == NULL) goto errMalloc;

 // fill up result stucture and return it to TCL
 unresolved = 0;
 for (ind=0; info->nameCmd [ind] != NULL; ind++) {
    if (info->wtxCtx[ind].entry == 0) {
      result [unresolved] = info->wtxCtx[ind].name;
      unresolved ++;
    }
 }

 // jWrap char** as to be NULL closed 
 result [unresolved] = NULL;


 return result; // ---------- OK -----------

errNotTornadoModule:
 jWrapPanic (NULL, "tornadoModuleUnresolved module=%s is not a Tornado/Tornado module\n",moduleName);

errUnresolved:
 jWrapPanic (NULL, "tornadoModuleUnresolved module=%s as no unresolved references\n",moduleName);

errMalloc:
 jWrapPanic (NULL, "tornadoModuleUnresolved module=%s %d unresolved ref cannot malloc\n"
            ,moduleName,unresolved);

return NULL; 
}

/**-------------------------------------------------------------------------
 ** Registrate a new module, currentelly subcontract jWrap
 ** for effective registering with no added processing.
 ** @param interp a valid tclsh interpretor
 ** @module a valid jWrap module handle
 ** @see jWrapModuleRegister
 **-------------------------------------------------------------------------*/
RESTRICTED void tornadoModuleRegister (Tcl_Interp *interp,JWRAP_modules *module) 
{

  // register module in jWrap hashtable
  jWrapModuleRegister (interp, module);

} 
