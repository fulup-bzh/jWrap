/*
 *
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   typeWrap.c handle complex C/C++ type mapping with external TCL rep
 * Projet    :   jWrap
 * Module    :   WTX VxWorks Tornado interface
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/typeRuntimeTornado.c,v $
 *
 * Modification History
 * --------------------
 * 01c,12feb99,Fulup,externalized WTX module
 * 01b,28may98,Fulup,ported to Windows [removed all stack dynamic allocation]
 * 01a,18feb98,Fulup,written
 */

/** ------------------------------------------------------------------
 *  handle all complex type and C structure handling. All following
 *  routines handle complex C struct in a generic way, from wrapper
 *  statically generated structures. As all
 *  adress offet computation are done at module init time on host
 *  target internal representation should be compatible with target.
 *  -----------------------------------------------------------------*/

#include "libRuntimeTornado.h"

#include <string.h>
#include <stdlib.h>

 
/**-----------------------------------------------------------------
 ** Translate type from internal to external rep, result is a valid
 ** value for jWrapUpdateType fonction. It loops on all structure slot
 ** produce for each slot a valid element from slot name and value.
 ** All elements are store in a list and used for producing final list.
 ** Depending on slot type we can malloc an area for holding internal
 ** rep of slot value. Result is a valid Tcl list Object than can be
 ** browsed with lindex functions. Nevertheless as this function does 
 ** not change internal representation, almost any function using result
 ** will have to reprocess result obj in order producing a valid list
 ** internal representation.
 ** @bug For BASIC type we should check for byte order in order suporting
 ** non compatible integer sex.
 ** @info backward link on tornado module
 ** @structure static handle
 ** @tclObj a tclsh object with internal rep pointing on a valid stucture
 ** adress in VxWorks target. 
 ** @note As tcl lindex routine change tcl object internal representation
 ** it is preferable using <jWtap cget> for scanning result.
 **-----------------------------------------------------------------*/
RESTRICTED char* tornadoTypeCc2Tcl (TORNADO_infos *info, JWRAP_structs *structure, Tcl_Obj *tclObj) {
 int     ind,jnd;
 Tcl_Obj **tmpObj  =NULL;
 char    **tuple   =NULL;
 char    **elements;

 jWrapLog (4,"tornadoTypeCc2Tcl type=%s ptr=0x%x\n"
           ,tclObj->typePtr->name,tclObj->internalRep.twoPtrValue.ptr1);

 // A pointer can be NULL
 if (tclObj->internalRep.twoPtrValue.ptr1 == NULL) goto nullPtr;

 // allocate trempry structure to an acceptable size
 elements = (char**)    Tcl_Alloc (sizeof(char*) * structure->count);

 // loop on all slot we use realloc in order not freeing result at each run
 for (ind=0; ind < structure->count; ind++) {
   // for each array slot we use a private tcl object to hold external rep
   tmpObj = (Tcl_Obj**) Tcl_Realloc ((void*)tmpObj, sizeof(Tcl_Obj*) * structure->slotArrays[ind]);
   // tuple contain slotname + all array values values [usually only one]
   tuple  = (char**)    Tcl_Realloc ((void*)tuple, sizeof(char*) * (structure->slotArrays[ind]+1));

   // Build external rep for slot name
   tuple [0] = structure->slotNames [ind];

   // Loop on all array element for each element value
   for (jnd=0; jnd < structure->slotArrays[ind]; jnd ++) {
     // Build an object for slot value
     tmpObj[jnd] = Tcl_NewObj();
     Tcl_IncrRefCount(tmpObj[jnd]);
     tmpObj[jnd]->internalRep.twoPtrValue.ptr2 = NULL;

     // Nativ type are copy jWrap struct are malloced
     switch (structure->slotTypes[ind]->magic) {
      case JWRAP_STRUCT:
        // Map internal rep to mother structure rep
        tmpObj[jnd]->internalRep.longValue = 
            (TGT_ADDR_T) (tclObj->internalRep.longValue
            + structure->slotOffsets[ind]
            + (jnd * structure->slotTypes[ind]->size));
        break;

      case JWRAP_POINTER:
      case JWRAP_COOKIE: 
      case JWRAP_BASIC: 
        // Place a copy of internal rep directelly inside tmp object
        tmpObj[jnd]->internalRep.twoPtrValue.ptr1=0;
        if (WTX_ERROR == (INT32) wtxMemRead (info->tornadoId->wtxId
            , (TGT_ADDR_T) (tclObj->internalRep.longValue
              + structure->slotOffsets[ind] + (jnd * structure->slotTypes[ind]->size))
            , &tmpObj[jnd]->internalRep
            , structure->slotTypes[ind]->size)) goto errWtxMemRead;

        break;

      default: goto errMagic;
     }

     // now internal rep is OK we produce external rep and copy in element string
     tmpObj[jnd]->typePtr = structure->slotTypes[ind]->obj;
     tmpObj[jnd]->typePtr->updateStringProc (tmpObj[jnd]);
     if (TCL_STRING (tmpObj[jnd]) != tclEmptyStringRep) {
       tuple [jnd+1] = TCL_STRING (tmpObj[jnd]);
     } else {
       tuple [jnd+1] = jWrapStringNull;
     }

     // reset type to empty in order not freeing orignal obj source internal rep
     tmpObj[jnd]->typePtr = NULL;

   } // end for jnd

   // group tuple object in one list {slot value}
   elements[ind] = Tcl_Merge (structure->slotArrays[ind]+1,tuple);   

   // free all tmp object
   for (jnd=0; jnd < structure->slotArrays[ind]; jnd ++) {
       Tcl_DecrRefCount (tmpObj[jnd]);
   }
 } // end for ind

 // group all element in a list
 tclObj->bytes  = Tcl_Merge (structure->count, elements);
 tclObj->length = strlen (tclObj->bytes);

 // free element tempty string
 for (ind = 0; ind <structure->count; ind++) {
   Tcl_Free ((void*)elements [ind]);
 }

 // free all tempry block
 Tcl_Free ((void*)elements);
 Tcl_Free ((void*)tmpObj);
 Tcl_Free ((void*)tuple);

 return NULL; // ----------- OK -----------------

 nullPtr:
   jWrapStrDup (tclObj,jWrapStringNull);
   return NULL;

 errWtxMemRead:
  sprintf (jWrapStaticMessage,"tornadoTypeUpdate can't read target <0x%lx> ram area\nWTX_ErrMsg=[%s]\n"
     , tclObj->internalRep.longValue
     + structure->slotOffsets[ind] + (jnd * structure->slotTypes[ind]->size)
     , wtxErrMsgGet (info->tornadoId->wtxId));
  return jWrapStaticMessage;

 errMagic:
   sprintf (jWrapStaticMessage, "tornadoTypeCc2Tcl slot=[%s] Unknow Magic\n"
           ,structure->slotNames[ind]);
   return  jWrapStaticMessage;
}

/**-----------------------------------------------------------------
 ** Translate type from external to internal rep. First split
 ** input list elements where each element is a tuple {name value}.
 ** After attached Tcl2Cc routine as been founded
 ** System copy back embedded structure to internal representation
 ** from inner most structure to external structure. We don't have
 ** to check for internal representation validity because to as all
 ** elements are comming from a common list they have the same
 ** usage counter and will all have a zero count usage at same time.
 ** @info backward link on tornado module
 ** @structure static handle
 ** @tclObj a tclsh object with a valid external represention or
 ** a list representation.
 ** @note a slot can be define we a pre-typed value, a list or a string
 ** in all other case we raise a jWrapPanic error.
 **-----------------------------------------------------------------*/
RESTRICTED int tornadoTypeUpdate (TORNADO_infos *info, Tcl_Interp *interp
  ,JWRAP_structs *structure,Tcl_Obj *srcObj, Tcl_Obj *destObj) {

  int     status;
  int     len1,len2;
  int     ind,jnd;
  int     idxSlot;
  Tcl_Obj *slot,*element,*value;
  int     completeMode;
  Tcl_Obj result;
  
   jWrapLog (4,"tornadoTypeUpdate: type=%s ptr=0x%x\n%"
           ,structure->type->obj->name,destObj->internalRep.longValue);

   // Check we have a real place for our result
   if (destObj->internalRep.longValue == 0) goto errNoBuffer;

   // Tcl Object should be a list
   status = Tcl_ListObjLength (interp, srcObj, &len1);
   if (status == TCL_ERROR) goto errList;

   // Loop on each parameters and check them
   for (ind = 0; ind < len1; ind ++) {
     // get element from list and check syntaxe
     status = Tcl_ListObjIndex (interp, srcObj, ind, &element);
     if (status != TCL_OK) goto errSlotList;
     status = Tcl_ListObjLength (interp, element, &len2);
     // Check value is a valid tcl list
     if (status != TCL_OK) goto errElement;
     if (len2 < 2) goto errSlotList;

     // Element look fine check slot name validity
     (void) Tcl_ListObjIndex (NULL, element, 0, &slot);
     if (Tcl_GetIndexFromObj (NULL, slot,structure->slotNames,"option"
        ,0, &idxSlot) != TCL_OK)  goto errSlot;

     // we should have exect number of params or that last param is "..." [complete mode]
     completeMode = FALSE;
     if (len2 != (1 + structure->slotArrays[idxSlot])) {
       // check last parameter is ...
       (void) Tcl_ListObjIndex (interp, element, len2-1, &value);
        if (strcmp ("...", value->bytes)) { 
          goto errElement;
        } else {
          completeMode = TRUE;
        }
     }

     // Loop on all array slot or less if in complete mode
     for (jnd=0; jnd < structure->slotArrays[idxSlot]; jnd ++) {

       // In compte mode we repeat last valid value
       if ((!completeMode) || (jnd < len2-2)) {  
         // process input we have a valid slot call attached Tcl2Cc routine
         (void) Tcl_ListObjIndex (interp, element, jnd+1, &value);
       }
        
       // For jWrapStruct place result directelly in struct without malloc
       if  (structure->slotTypes[idxSlot]->magic == JWRAP_STRUCT) {
         result.internalRep.longValue 
            = destObj->internalRep.longValue + structure->slotOffsets[idxSlot]
            + (structure->slotTypes[idxSlot]->size*jnd);
       }
       // Update object internal representation if not present
       if ((value->typePtr == 0) || (value->typePtr == jWrapTypeList)) {
          status = ((Function*)structure->slotTypes[idxSlot]
          ->obj->setFromAnyProc) (interp, value, &result);
       // Last change is to get directelly application wanted type
       } else if (value->typePtr->updateStringProc
          != structure->slotTypes[idxSlot]->obj->updateStringProc) {
             goto errType;
       }
       if (status != TCL_OK) goto errValue;
 
       // For any type other than JWRAP_struct we have to copy result in or result buffer
       if (structure->slotTypes[idxSlot]->magic != JWRAP_STRUCT) {
            // copy external rep onto target
            if (WTX_ERROR == (INT32) wtxMemWrite (info->tornadoId->wtxId
            , &value->internalRep
            , destObj->internalRep.longValue + structure->slotOffsets[idxSlot] 
              + (structure->slotTypes[idxSlot]->size *jnd)
            , structure->slotTypes[idxSlot]->size)) goto errWtxMemWrite;
       }
     }
   } // end for all elements

   return TCL_OK; // -------------- OK ---------------

 errWtxMemWrite:
  jWrapPanic (interp,"tornadoTypeUpdate can't write host <0x%p> to target <0x%x>\nWTX_ErrMsg=[%s]\n"
	      ,&value->internalRep
              , destObj->internalRep.longValue + structure->slotOffsets[idxSlot] 
                 + (structure->slotTypes[idxSlot]->size *jnd)
              , wtxErrMsgGet (info->tornadoId->wtxId));

 errType:
  jWrapPanic (interp,"Slot [%s] type [%s] not equivalent to [%s]"
            ,TCL_STRING (slot),value->typePtr->name,structure->slotTypes[idxSlot]->obj->name);

 errList:
  Tcl_AppendResult (interp,"\ntornadoTypeUpdate [",structure->type->obj->name
                   ,"] input prm should be a list\n",NULL);
  return TCL_ERROR;

 errNoBuffer:
  Tcl_AppendResult (interp,"tornadoTypeUpdate [",structure->type->obj->name
                   ,"] Internal Buffer is NULL\n",NULL);
  return TCL_ERROR;

 errSlot:
  Tcl_AppendResult (interp,"tornadoTypeUpdate [",structure->type->obj->name
                   ,"] Unknow Slot [",TCL_STRING(slot),"]\n",NULL);
  return TCL_ERROR;

 errSlotList:
  Tcl_AppendResult (interp,"tornadoTypeUpdate [",structure->type->obj->name
                   ,"] Slot is not a valid list [",TCL_STRING(element),"]\n",NULL);
  return TCL_ERROR;

 errElement: {
  char name [JWRAP_MAX_NAME];
  Tcl_AppendResult (interp,"tornadoTypeUpdate [",structure->type->obj->name
    ,"] Element [",TCL_STRING(element),"] not a valid Tcl List"
    ,NULL);
  Tcl_AppendResult (interp,structure->slotNames[idxSlot],NULL);
  for (ind = 1; ind <= structure->slotArrays[idxSlot]; ind ++) {
    sprintf (name," value_%d", ind);
    Tcl_AppendResult (interp,name,NULL);
  }
  Tcl_AppendResult (interp,"]\n",NULL);
  } 
  return TCL_ERROR;

 errValue:
  Tcl_AppendResult (interp,"tornadoTypeUpdate [", structure->type->obj->name
                   ,"] Slot [",TCL_STRING(slot),"] Value [",TCL_STRING(value)
                   ,"] is not a valid [",structure->slotTypes[idxSlot]->obj->name
                   ,"] Type\n",NULL);
  return TCL_ERROR;
}


/**-----------------------------------------------------------------
 * Allocate and set to zero a new instance of Structs, this routine
 * is either called from <jWrap new> or from from jWrap input parameter
 * type control for non polymorph routines. 
 * @info backward link on tornado module
 * @structure static handle
 * @note we use ptr2 in order not breaking Tcl internal object type
 * this is important when Tcl provide a valid list, and save
 * time in TornadoUpdateType routine
 * @error raise a jWrapPanic error if not more ram is avaliable in
 * wtx agent memory pool, or when module in not binded. 
 **-----------------------------------------------------------------*/
RESTRICTED int tornadoTypeTcl2Cc (TORNADO_infos *info, Tcl_Interp *interp
       , JWRAP_structs *structure, Tcl_Obj * srcObj, Tcl_Obj *destObj) {
  int status;

  // if we are not comming from a jWrap new source==destination
  if (destObj == NULL) {
    // source and destination are equivalent
    destObj=srcObj;
    // build a dummy source objet to hold list internal rep
    srcObj = Tcl_NewObj();
    memcpy (srcObj, destObj, sizeof (Tcl_Obj));
    // invalidate previous external rep to advoid dual free
    destObj->bytes = NULL;
  }

  // type our resulting objet now
  destObj->typePtr = structure->type->obj;

  // check user does not want a null pointer
  if ((TCL_STRING(srcObj) != NULL) && (!strcmp (TCL_STRING(srcObj), jWrapStringNull))) {
    destObj->internalRep.twoPtrValue.ptr1 = NULL;
    destObj->internalRep.twoPtrValue.ptr2 = NULL;
    return TCL_OK;
  }

  // use dest ptr2 to hold a backward link on source pointer
  destObj->internalRep.twoPtrValue.ptr2 = srcObj;
  Tcl_IncrRefCount (srcObj);

  // protect our self from unbinded module
  if (info->tornadoId->wtxId == NULL) goto errNotBind;

  // allocate destination ram area on target
  destObj->internalRep.longValue = wtxMemAlloc (info->tornadoId->wtxId, structure->type->size);
  if (destObj->internalRep.longValue == 0) goto errWtxMalloc;

  // copy external rep onto target
  if (WTX_ERROR == (INT32) wtxMemSet (info->tornadoId->wtxId
     , destObj->internalRep.longValue, structure->type->size,'\0')) goto errWtxMemWrite;

  jWrapLog (4,"tornadoTypeTcl2Cc: 0x%x = malloc (%d)\n"
     ,destObj->internalRep.longValue
     ,structure->type->size);

  // Start filling our struct
  status = tornadoTypeUpdate (info,interp,structure, srcObj, destObj);

  // Invalidate external rep
  destObj->bytes = NULL;

  return status; // ------ OK ---------  

errWtxMalloc: // ---------------------- ERROR -------------------
  jWrapPanic (interp,"tornadoTypeTcl2Cc can't alloc tornadoMemPool:%s WTX_ErrMsg=[%s]\n"
	     ,info->tornadoId->targetName
	     ,wtxErrMsgGet (info->tornadoId->wtxId));

errWtxMemWrite:
  jWrapPanic (interp,"tornadoTypeTcl2Cc can't copy %s to wtxMemPool <0x%lx> WTX_ErrMsg=[%s]\n"
	      ,srcObj->bytes, destObj->internalRep.longValue, wtxErrMsgGet (info->tornadoId->wtxId));

errNotBind:
  jWrapPanic (interp,"tornadoTypeTcl2Cc module is not bind\n");

return JWRAP_IMPOSSIBLE;

}

/**********************************************************************
 ** Free a structure on VxWorks target, this routine can be called
 ** with Tcl garbage collector or whith <jWrap free>
 ** @note only <_Ptr> typedef free space on target.
 ** info backwared link on tornado module
 ** tclObj a Tcl object with internal rep pointed on a valid allocated
 ** wtx ram block.
 **********************************************************************/
RESTRICTED void tornadoTypeFree (TORNADO_infos *info,Tcl_Obj *tclObj)
{
  // place string address in long value for C
  jWrapLog (5,"tornadoTypeFree:0x%x\n", tclObj->internalRep.twoPtrValue.ptr1);
  if (WTX_OK != wtxMemFree (info->tornadoId->wtxId
     ,(TGT_ADDR_T)tclObj->internalRep.twoPtrValue.ptr1))
    goto errFree;

  // now free source internal list rep
  if (tclObj->internalRep.twoPtrValue.ptr2 != NULL) {
     Tcl_DecrRefCount((Tcl_Obj*)tclObj->internalRep.twoPtrValue.ptr2); 
  }

  return; // ------------- OK -------------

 errFree:
  jWrapLog (0,"tornadoTypeFree: cannot free: <%#x>\nWTX_ErrMsg=%s\n"
          , (int)tclObj->internalRep.twoPtrValue.ptr1,wtxErrMsgGet (info->tornadoId->wtxId));
}

/**-----------------------------------------------------------------
 ** Free a complex type call with garbage callector.
 ** @note: this routine does not free anything on target it is use
 ** as a tag mecanism for non pointer structure in tcl virtual machine
 **-----------------------------------------------------------------*/
RESTRICTED void tornadoTypeClean (Tcl_Obj * tclObj) {

  // Free our attached complex structure
  jWrapLog (5,"tornadoTypeClean:0x%x\n", tclObj->internalRep.twoPtrValue.ptr1);

  // now free source internal list rep
  if (tclObj->internalRep.twoPtrValue.ptr2 != NULL) {
     Tcl_DecrRefCount((Tcl_Obj*)tclObj->internalRep.twoPtrValue.ptr2); 
  }

}


/**-----------------------------------------------------------------
 ** Get one and only one slot from a complex structure
 ** return result in a Tcl_Obj. If taken object as no
 ** free routine, then cget returned a copy of original object
 ** object type and value, but if original type as a free
 ** routine [ex:char*] we give a dummy "jWrap_Cget"
 ** type to object, and attach a structure that hold original
 ** object value and type. When calling a routine, this structure
 ** is automatically replaced with original value with "putCgetIntoC"
 ** @info backward link on tornado module
 ** @structure static handle
 ** @objObj complex object with a valid internal representation
 ** @slot   tcloecjt holding sold name in it external representation
 ** @note original object should not be freed or cget contructed
 ** object will hold a wrong internal representation, which should [will]
 ** make tclsh to core dump  !!!
 **-----------------------------------------------------------------*/
RESTRICTED void tornadoTypeCget (TORNADO_infos *info, Tcl_Interp *interp
            ,JWRAP_structs *structure,Tcl_Obj*tclObj, Tcl_Obj *slot) {

  int         idxSlot;
  Tcl_Obj     *value;
  long        origine;

   // Check slot name in slot struc array
   if (Tcl_GetIndexFromObj(NULL, slot, structure->slotNames, "option"
      ,0, &idxSlot) != TCL_OK)  goto errSlot;

   // If our oject is a cget we need to retreive original object first
   if (tclObj->typePtr == &jWrapTypeTclObj) {
     JWRAP_cgets *cget;
     cget   = tclObj->internalRep.twoPtrValue.ptr1;
     origine= (long)cget->valueAdr;
   } else {
     origine= (long)tclObj->internalRep.twoPtrValue.ptr1; 
   }

   // create a new TclObj that we be returned to user
   value = Tcl_NewObj();

   // check if original type as a free routine
   if (structure->slotTypes[idxSlot]->obj->freeIntRepProc == NULL) {
      // Place a copy of internal rep directelly inside destination object
      value->internalRep.longValue=0;

      if (WTX_ERROR == (INT32) wtxMemRead (info->tornadoId->wtxId
            , (TGT_ADDR_T)origine + structure->slotOffsets[idxSlot]
            , &value->internalRep
            , structure->slotTypes[idxSlot]->size)) goto errWtxMemRead;
      value->typePtr = structure->slotTypes[idxSlot]->obj;

    } else {
       JWRAP_cgets* resultAdr;
       // Place result in a Cget private structure
       resultAdr  = (JWRAP_cgets*) Tcl_Alloc (sizeof (JWRAP_cgets));
       if (resultAdr == NULL) goto errMalloc;
       // Copy Object type & value in Cget struc & increment orig count usage 
       resultAdr->valueAdr 
       = (void*) (origine+structure->slotOffsets[idxSlot]);
       resultAdr->type     = structure->slotTypes[idxSlot]->obj;
       resultAdr->owner    = tclObj;
       Tcl_IncrRefCount(tclObj);
       value->typePtr      = &jWrapTypeTclObj;
       value->internalRep.twoPtrValue.ptr1 = resultAdr;
    }

   // invalidate external rep and set internal type
   value->bytes   =  NULL;

   // place result in interp
   Tcl_SetObjResult (interp, value);

   return; // -------------- OK ---------------

errWtxMemRead:
  jWrapPanic (interp,"tornadoTypeCget cannot read %#x on target"
    , origine + structure->slotOffsets[idxSlot]);

errSlot:
  jWrapPanic (interp, "jWrapTypeCget [%s] Unknow Slot [%s]\n"
             ,structure->type->obj->name,TCL_STRING(slot));
errMalloc:
   jWrapPanic (NULL, "jWrapTypeCc2Tcl struc=[%s] malloc failled\n", structure->type->obj->name);
}

/**-----------------------------------------------------------------
 ** Pointer Tornado type are not compliant with C host. Nevertheless
 ** as tornado produce it own type translation routines we only have to
 ** check for standard non compliant as char* and char**.
 ** @info backward link on tornado module
 ** @param usedtype a pointer in jWrap static type array element
 ** @param typeName type symbolic name, whill be used to update
 ** tclsh type hashtable.
 **-----------------------------------------------------------------*/
RESTRICTED void tornadoTypeCheck (TORNADO_infos *info, JWRAP_types *usedType, char* typeName
       , unsigned int typeSize) {

 // check this is not a standard TCL type
 usedType->obj = Tcl_GetObjType (typeName);
 
 // if unknown we register a new jWrap cookie type
 if (usedType->obj == NULL) {
   jWrapCookieRegisterType (usedType, typeName);

 } else {

   // We use free routine to classify type
   if (usedType->obj->freeIntRepProc == tornadoTypeClean) {
       usedType->magic = JWRAP_STRUCT;
   } else if ((void*)usedType->obj->freeIntRepProc == info->tornadoFree) {
       usedType->magic = JWRAP_POINTER;
   } else if (usedType->obj->updateStringProc == jWrapStringPtrType.updateStringProc) {
       usedType->magic = JWRAP_BASIC;
       usedType->obj   = info->stringType;
   } else if (usedType->obj == &jWrapStringListType) { 
       jWrapPanic (NULL,"tornadoTypeCheck: type unsupported by this version :[%s]",typeName);
   } else {
       usedType->magic = JWRAP_BASIC;
   }
 }
 usedType->size = typeSize;
  
} // end initialiseType

/** -----------------------------------------------------------------
 ** Init module register some Tcl to basic type equivalence
 ** for int and list.
 ** @note this routine is only usefull under WIN32 in order bypassing
 ** dll limitation on static data.
 **-----------------------------------------------------------------*/
RESTRICTED void tornadoTypeInit (Tcl_Interp *interp) {

#ifdef _WINDOWS_
  // Windows duplicate public static area un DLL
  jWrapTypeInt     = Tcl_GetObjType ("int");
  if (jWrapTypeInt == NULL) goto errType;
  jWrapTypeList    = Tcl_GetObjType ("list");
  if (jWrapTypeList == NULL) goto errType;

  return;

errType:
  jWrapPanic (NULL, "tornadoTypeInit: did not find basic [int|list] tcl type [hug!!!]\n");
#endif
}
