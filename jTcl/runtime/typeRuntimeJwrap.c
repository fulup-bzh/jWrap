/*
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   typeWrap.c handle complex C/C++ type mapping with external TCL rep
 * Projet    :   jWrap
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/typeRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01f,09mar99,Fulup,mapped cmdName to char* for unknow command support
 * 01e,18feb99,Fulup,corrected cget on pointer value
 * 01d,17oct98,Fulup,corrected cget return of substructure address
 * 01c,03jul98,Fulup,add source/destination object
 * 01b,28may98,Fulup,ported to Windows [removed all stack dynamic allocation]
 * 01a,18feb98,Fulup,written
 */


#include "libRuntimeJwrap.h"
#include <string.h>

/** Duplication public entry point for windows linker [hug!!!] */
EXPORT Tcl_ObjType *jWrapTypeInt;
/** Duplication public entry point for windows linker [hug!!!] */
EXPORT Tcl_ObjType *jWrapTypeList; 

/**-----------------------------------------------------------
 * When extracting an object from an other one if taken
 * object as a free routine, we replace original type
 * with cget type in order not free original object
 * when cget is free
 **-----------------------------------------------------------*/
LOCAL  void dupCgetInternal (Tcl_Obj *srcPtr, Tcl_Obj *copyPtr);
LOCAL  void getCgetFromC    (Tcl_Obj *tclObj);
LOCAL  void freeCgetInternal(Tcl_Obj *tclObj);
LOCAL  int  putCgetIntoC    (Tcl_Interp *interp,Tcl_Obj *tclObj);

/**------------------------------------------------------------------------
 * Define a global typedef for all proxy objet, those proxy object are
 * used each time user want to make a copy of a part of and object that
 * as a private free routine.
 **------------------------------------------------------------------------*/
EXPORT Tcl_ObjType jWrapTypeTclObj = {
    "jWrap_Proxy",			/* name */
    freeCgetInternal,	                /* freeIntRepProc */
    dupCgetInternal,		        /* dupIntRepProc */
    getCgetFromC,	        	/* updateCgetProc */
    putCgetIntoC			/* setFromAnyProc */
};

/**------------------------------------------------------------------------
 * Update external representation from internal one, in order doing this
 * We subcontract original "setFromAnyProc" routine.
 **------------------------------------------------------------------------*/
LOCAL void getCgetFromC (Tcl_Obj *tclObj)
{
 JWRAP_cgets *cget;

  // Get external rep from our owner object 
  cget = (JWRAP_cgets*)tclObj->internalRep.twoPtrValue.ptr1;
  
  // make or cget object look like father object
  tclObj->internalRep.twoPtrValue.ptr1 = cget->valueAdr;
  cget->type->updateStringProc (tclObj);

  // restore tclObj internal rep a a valid cget obj
  tclObj->internalRep.twoPtrValue.ptr1 = (void*)cget;
  tclObj->typePtr = &jWrapTypeTclObj;
}

/**--------------------------------------------------------------------
 * Update internal rep from external routine, this should be called
 * before any proc call with a cget typed parameter. Note than this
 * routine does not change parameter type, in order not breaking
 * garbage collector. We even restore original cType, because some
 * external presentation can break original type.
 **--------------------------------------------------------------------*/
LOCAL int putCgetIntoC (Tcl_Interp *interp,Tcl_Obj *tclObj)
{
 JWRAP_cgets *cget;
 int         status;
  
  // Call Translation routine with original object   
  cget = (JWRAP_cgets*)tclObj->internalRep.twoPtrValue.ptr1;
  cget->owner->bytes  = tclObj->bytes;
  cget->owner->length = tclObj->length;

  status = cget->type->setFromAnyProc (interp, cget->owner);

  tclObj->typePtr = &jWrapTypeTclObj;

  // owner object external rep obsolete
  cget->owner->bytes = NULL;
    
  return status;
}

/**----------------------------------------------------------------
 * Decrement usage count of owner object, then
 * Free internal cget buffer. This routine does not free original
 * object but only the cget handler, in order allowing garbage
 * collector to free later on the original object, because more
 * then one cget reference can point on owner object. 
 **----------------------------------------------------------------*/
LOCAL void freeCgetInternal(Tcl_Obj *tclObj) {
 JWRAP_cgets *cget;

  cget = (JWRAP_cgets*) tclObj->internalRep.twoPtrValue.ptr1;
  Tcl_DecrRefCount(cget->owner);
  Tcl_Free ((void*) cget);
  tclObj->typePtr = NULL;
}

/**----------------------------------------------------------------
 *   copy cGet internal rep object to a new object
 **----------------------------------------------------------------*/
LOCAL void dupCgetInternal(Tcl_Obj *srcPtr, Tcl_Obj *destPtr)
{
  JWRAP_cgets *cget;

  cget = (JWRAP_cgets*) srcPtr->internalRep.twoPtrValue.ptr1;
    destPtr->internalRep.twoPtrValue.ptr1 = Tcl_Alloc (sizeof (JWRAP_cgets));
    memcpy  (destPtr->internalRep.twoPtrValue.ptr1
            ,srcPtr->internalRep.twoPtrValue.ptr1
            ,sizeof (JWRAP_cgets));
    destPtr->typePtr = &jWrapTypeTclObj;
    Tcl_IncrRefCount(cget->owner);
}

 
/**-----------------------------------------------------------------
 * Translate type from internal to external rep, result is a valid
 * value for jWrapUpdateType function. It loops on all structure slot
 * produce for each slot a valid element from slot name and value.
 * All elements are store in a list and used for producing final list.
 * Depending on slot type we can malloc an area for holding internal
 * rep of slot value. Result is a valid Tcl list Object than can be
 * browsed with lindex functions. Nevertheless as this function does 
 * not change internal representation, almost any function using result
 * will have to re-process result obj in order producing a valid list
 * internal rep.
 **-----------------------------------------------------------------*/
PUBLIC char* jWrapTypeCc2Tcl (JWRAP_structs *structure, Tcl_Obj *tclObj) {
 int     ind,jnd;
 Tcl_Obj **tmpObj  =NULL;
 char    **tuple   =NULL;
 char    **elements;

 // A pointer can be NULL
 if (tclObj->internalRep.twoPtrValue.ptr1 == NULL) goto nullPtr;

 // allocate trempry structure to an acceptable size
 elements = (char**)    Tcl_Alloc (sizeof(char*) * structure->count);

 // loop on all slot we use realloc in order not freeing result at each run
 for (ind=0; ind < structure->count; ind++) {
   // for each array slot we use a private tcl object to hold external rep
   tmpObj = (Tcl_Obj**) Tcl_Realloc ((void*)tmpObj, sizeof(Tcl_Obj*) * structure->slotArrays[ind]);
   // tuple contain slot name + all array values values [usually only one]
   tuple  = (char**) Tcl_Realloc ((void*)tuple, sizeof(char*) * (structure->slotArrays[ind]+1));

   // Build external rep for slot name
   tuple [0] = structure->slotNames [ind];

   // Loop on all array element for each element value
   for (jnd=0; jnd < structure->slotArrays[ind]; jnd ++) {
     // Build an object for slot value
     tmpObj[jnd] = Tcl_NewObj();
     Tcl_IncrRefCount(tmpObj[jnd]);
     // Make sure we wont try to free source object if none attached
     tmpObj[jnd]->internalRep.twoPtrValue.ptr2 = NULL;

     // Nativ type are copy jWrap struct are malloced
     switch (structure->slotTypes[ind]->magic) {
      case JWRAP_STRUCT:
        // Use mother internal rep for producing internal rep
        tmpObj[jnd]->internalRep.longValue = 
	(long)(tclObj->internalRep.twoPtrValue.ptr1)
        + structure->slotOffsets[ind] + (jnd*structure->slotTypes[ind]->size); 
        break;

      case JWRAP_POINTER:
      case JWRAP_COOKIE: 
      case JWRAP_BASIC: 
        // Place a copy of internal rep directelly inside tmp object
        tmpObj[jnd]->internalRep.twoPtrValue.ptr1=0;
        memcpy (&tmpObj[jnd]->internalRep
	 , (char*)(tclObj->internalRep.twoPtrValue.ptr1)
         + structure->slotOffsets[ind] + (jnd * structure->slotTypes[ind]->size)
         , structure->slotTypes[ind]->size); 
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

   } // end for jnd

   // group tuple object in one list {slot value}
   elements[ind] = Tcl_Merge (structure->slotArrays[ind]+1,tuple);   

   // free all tmp object
   for (jnd=0; jnd < structure->slotArrays[ind]; jnd ++) {
       // reset type to empty in order not freeing orignal obj source internal rep
       tmpObj[jnd]->typePtr = NULL;
       Tcl_DecrRefCount (tmpObj[jnd]);
   }
 } // end for ind

 // group all element in a list
 tclObj->bytes  = Tcl_Merge (structure->count, elements);
 tclObj->length = strlen (tclObj->bytes);

 // free element tempty string
 for (ind = 0; ind <structure->count; ind++) {
   Tcl_Free (elements [ind]);
 }

 // free all tempry block
 Tcl_Free ((void*)elements);
 Tcl_Free ((void*)tmpObj);
 Tcl_Free ((void*)tuple);
  

 return NULL; // ----------- OK -----------------

 nullPtr:
   jWrapStrDup (tclObj,jWrapStringNull);
   return NULL;

 errMagic:
   sprintf (jWrapStaticMessage, "jWrapTypeCc2Tcl struc=[%s] Unknown Magic\n"
          , structure->type->obj->name);
   return jWrapStaticMessage;
}

/**-----------------------------------------------------------------
 * Translate type from external to internal rep. First split
 * input list elements where each element is a tuple {name value}.
 * After attached Tcl2Cc routine as been founded
 * System copy back embedded structure to internal representation
 * from inner most structure to external structure. We don't have
 * to check for internal representation validity because to as all
 * elements are coming from a common list they all have the same
 * usage counter and will all have a zero count usage at same time.
 * Note that is a slot can be define we a pre-typed value, in this case
 * we just don't call translation routine.
 **-----------------------------------------------------------------*/
PUBLIC int jWrapTypeUpdate (Tcl_Interp *interp,JWRAP_structs *structure
       , Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  int     status;
  int     len1,len2;
  int     ind,jnd;
  int     idxSlot;
  Tcl_Obj *slot,*element,*value;
  int     completeMode;
  Tcl_Obj result;

   // Check we have a real place for our result
   if (destObj->internalRep.twoPtrValue.ptr1 == NULL) goto errNoBuffer;

   // Tcl Object should be a list
   status = Tcl_ListObjLength (interp, srcObj, &len1);
   if (status == TCL_ERROR) goto errList;

   // Loop on each parameters and check them
   for (ind = 0; ind < len1; ind ++) {
     // get element from list and check syntaxe
     status = Tcl_ListObjIndex (interp, srcObj, ind, &element);
     if (status != TCL_OK) goto errSlotList;
     status = Tcl_ListObjLength (interp, element, &len2);
     if (len2 < 2) goto errSlotList;

     // Element look fine check slot name validity
     (void) Tcl_ListObjIndex (NULL, element, 0, &slot);
     if (Tcl_GetIndexFromObj (NULL, slot,structure->slotNames,"option"
        ,0, &idxSlot) != TCL_OK)  goto errSlot;

     // Check value is a valid tcl list
     if (status != TCL_OK) goto errElement;

     // we should have expect number of params or that last param is "..." [complete mode]
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

       // In complete mode we repeat last valid value
       if ((!completeMode) || (jnd < len2-2)) {  
         // process input we have a valid slot call attached Tcl2Cc routine
         (void) Tcl_ListObjIndex (interp, element, jnd+1, &value);
       }
        
       // Update object internal representation if not present
       if ((value->typePtr == 0) || (value->typePtr == jWrapTypeList)) {
         // For jWrapStruct place result directelly in struct without malloc
         if  (structure->slotTypes[idxSlot]->magic == JWRAP_STRUCT) {
          result.internalRep.twoPtrValue.ptr1
            = (char*)destObj->internalRep.twoPtrValue.ptr1 + structure->slotOffsets[idxSlot]
            + ( structure->slotTypes[idxSlot]->size*jnd);

          status = ((Function*)structure->slotTypes[idxSlot]
          ->obj->setFromAnyProc) (interp, value, &result);
         } else {
          status = ((Function*)structure->slotTypes[idxSlot]
          ->obj->setFromAnyProc) (interp, value, &result,NULL);
         }

       // Last change is to get directelly application wanted type
       // We check updateStringProc in order _Ptr and non _Ptr to be equivalent
       } else if (value->typePtr->updateStringProc
          != structure->slotTypes[idxSlot]->obj->updateStringProc) {
             goto errType;
       }
       if (status != TCL_OK) goto errValue;
 
       // For any type other than JWRAP_struct we have to copy result in or result buffer
       if (structure->slotTypes[idxSlot]->magic != JWRAP_STRUCT) {
          memcpy ((char*)destObj->internalRep.twoPtrValue.ptr1
             + structure->slotOffsets[idxSlot] 
             + (structure->slotTypes[idxSlot]->size *jnd)
             , &value->internalRep
             , structure->slotTypes[idxSlot]->size); 
       }
     }
   } // end for all elements

   return TCL_OK; // -------------- OK ---------------

 errType:
  jWrapPanic (interp,"Slot [%s] type [%s] not equivalent to [%s]"
            ,TCL_STRING (slot),value->typePtr->name,structure->slotTypes[idxSlot]->obj->name);

 errList:
  Tcl_AppendResult (interp,"\njWrapTypeUpdate [",structure->type->obj->name
                   ,"] input prm should be a list\n",NULL);
  return TCL_ERROR;

 errNoBuffer:
  Tcl_AppendResult (interp,"jWrapTypeUpdate [",structure->type->obj->name
                   ,"] Internal Buffer is NULL\n",NULL);
  return TCL_ERROR;

 errSlot:
  Tcl_AppendResult (interp,"jWrapTypeUpdate [",structure->type->obj->name
                   ,"] Unknown Slot [",TCL_STRING(slot),"]\n",NULL);
  return TCL_ERROR;

 errSlotList:
  Tcl_AppendResult (interp,"jWrapTypeUpdate [",structure->type->obj->name
                   ,"] Slot is not a valid list [",TCL_STRING(element),"]\n",NULL);
  return TCL_ERROR;

 errElement: {
  char name [JWRAP_MAX_NAME];
  Tcl_AppendResult (interp,"jWrapTypeUpdate [",structure->type->obj->name
                   ,"] Element [",TCL_STRING(element),"] is not a valid Tcl list"
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
  Tcl_AppendResult (interp,"jWrapTypeUpdate [", structure->type->obj->name
                   ,"] Slot [",TCL_STRING(slot),"] Value [",TCL_STRING(value)
                   ,"] is not a valid [",structure->slotTypes[idxSlot]->obj->name
                   ,"] Type\n",NULL);
  return TCL_ERROR;
}

/**-----------------------------------------------------------------
 * Get only one slot from a complex structure
 * return result in a Tcl_Obj. If taken object as no
 * free routine, then cget returned object take origin
 * object type and value, but if if original type as a free
 * routine [ex:char*] we give a dummy "jWrap_Cget"
 * type to object, and attach a structure that old original
 * object value and type. When calling a routine, this structure
 * is automatically replaced with original value with "putCgetIntoC"
 * WARNING: original object should not be freed or cget constructed
 * object will hold a wrong internal representation, which should [will]
 * make tclsh to core dump  !!!
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeCget (Tcl_Interp *interp,JWRAP_structs *structure
                          ,Tcl_Obj*tclObj, Tcl_Obj *slot) {

  int         idxSlot;
  Tcl_Obj     *value;
  char        *origine;


   // Check slot name in slot struc array
   if (Tcl_GetIndexFromObj(NULL, slot, structure->slotNames, "option"
      ,0, &idxSlot) != TCL_OK)  goto errSlot;

   // If our oject is a cget we need to retreive original objest first
   if (tclObj->typePtr == &jWrapTypeTclObj) {
     JWRAP_cgets *cget;
     cget   = tclObj->internalRep.twoPtrValue.ptr1;
     origine= (char*)cget->valueAdr;
   } else {
     origine= (char*)tclObj->internalRep.twoPtrValue.ptr1; 
   }

   // create a new TclObj that we be returned to user
   value = Tcl_NewObj();

   // check if original type as a free routine
   if (structure->slotTypes[idxSlot]->obj->freeIntRepProc == NULL) {
      // Place a copy of internal rep directly inside destination object
      value->internalRep.longValue=0;
      memcpy (&value->internalRep
        , origine
        + structure->slotOffsets[idxSlot]
        , structure->slotTypes[idxSlot]->size); 
      value->typePtr = structure->slotTypes[idxSlot]->obj;
   } else {
      JWRAP_cgets* resultAdr;
      // Place result in a Cget private structure
      resultAdr  = (JWRAP_cgets*) Tcl_Alloc (sizeof (JWRAP_cgets));
      if (resultAdr == NULL) goto errMalloc;
 
      // Copy Object type and value in Cget structure and increment original count usage
      if (structure->slotTypes[idxSlot]->magic == JWRAP_STRUCT) {
	 // For scructure we take object adresse
         resultAdr->valueAdr = (void*)((long)origine+structure->slotOffsets[idxSlot]);
      } else {
	 // For pointer take pointer value
         resultAdr->valueAdr = *(void**)((long)origine+structure->slotOffsets[idxSlot]);
      }
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

errSlot:
  jWrapPanic (interp, "jWrapTypeCget [%s] Unknown Slot [%s]\n"
             ,structure->type->obj->name,TCL_STRING(slot));
errMalloc:
   jWrapPanic (NULL, "jWrapTypeCc2Tcl struc=[%s] malloc failed\n", structure->type->obj->name);
}

/**-----------------------------------------------------------------
 * Allocate and set to zero a new instance of Structure. Call update
 * routine to effectivelly fill up structure, and use destination ptr2
 * to hold a backward link on source object in oder decrementing usage
 * count at free time.
 * @param interp current tcl interpretor
 * @structure a complex type handle can point a union or a structure
 * @srcObj source objet to use for building destination object
 * @destObj destination object or NULL if srcObj=destObj
 * @see jWrap new
 **-----------------------------------------------------------------*/
PUBLIC int jWrapTypeTcl2Cc(Tcl_Interp *interp,JWRAP_structs *structure
      ,Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  int status;

  // if we are not coming from a jWrap new source==destination
  if (destObj == NULL) {
    // source and destination are equivalent
    destObj=srcObj;
    // build a dummy source objet to hold list internal rep
    srcObj = Tcl_NewObj();
    memcpy (srcObj, destObj, sizeof (Tcl_Obj));
    // invalidate previous external rep to avoid dual free
    destObj->bytes = NULL;
  }

  // type our resulting object now
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

  // Alloc and set to zero our structure in heap
  destObj->internalRep.twoPtrValue.ptr1 = Tcl_Alloc (structure->type->size);
  if (destObj->internalRep.twoPtrValue.ptr1 == NULL) goto errMalloc;

  // propose a zero default value to any new struct
  memset (destObj->internalRep.twoPtrValue.ptr1, 0, structure->type->size);

  // Start filling our struct
  status = jWrapTypeUpdate (interp, structure, srcObj, destObj);

  // Invalidate external rep if any
  destObj->bytes = NULL;

  return status; // ------ OK ---------  

 errMalloc: 
   Tcl_AppendResult (interp, "jWrapTypeNew struct=["
                    ,structure->type->obj->name,"] can't malloc\n"
                    ,NULL);
   return TCL_ERROR;
}

/**-----------------------------------------------------------------
 * Free a complex type call with garbage collector
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeFree (Tcl_Obj * tclObj) {

  jWrapLog (5,"jWrapTypeFree:0x%x\n", tclObj->internalRep.twoPtrValue.ptr1);

  // Free our attached complex structure
  Tcl_Free (tclObj->internalRep.twoPtrValue.ptr1);

  // now free source internal list rep
  if (tclObj->internalRep.twoPtrValue.ptr2 != NULL) {
     Tcl_DecrRefCount((Tcl_Obj*)tclObj->internalRep.twoPtrValue.ptr2); 
  }
}

/**-----------------------------------------------------------------
 * Free a complex type call with garbage collector
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeClean (Tcl_Obj * tclObj) {

  // now free source internal list rep
  if (tclObj->internalRep.twoPtrValue.ptr2 != NULL) {
     Tcl_DecrRefCount((Tcl_Obj*)tclObj->internalRep.twoPtrValue.ptr2); 
  }
}

/**-----------------------------------------------------------------
 * jWrapPrintType print available slot of a given structure
 * on stdout, Do not return any result
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeInfo (JWRAP_structs *structure,int listAsked,char**result,int indStruct) {
  int  ind;
  int  jnd;
  char **elements=NULL;
  char **tuple   =NULL;

  if (!listAsked) {
    // print out structure type and slot name
    fprintf (stdout,"#\n#%3d: Typedef %s struct %s {\n"
                 , indStruct
                 , structure->type->obj->name
                 ,structure->type->obj->name);

    // for each slot print type and var name
    for (ind=0; ind < structure->count; ind ++) {
  
      fprintf (stdout, "#   %s %s"
                   , structure->slotTypes[ind]->obj->name
                   , structure->slotNames[ind]);
      if (structure->slotArrays[ind] > 1) {
        fprintf (stdout,"[%d]", structure->slotArrays[ind]);
      }
      fprintf (stdout,";\n");
    }
    // print a conventional struc trailer
    fprintf (stdout,"# }\n");
  } else {
    // return all structure as a list in slot
    elements = (char**) Tcl_Alloc (sizeof (char*) * (structure->count+1));
    elements [0] = structure->type->obj->name;
  
    for (ind=0; ind < structure->count; ind ++) {
      tuple = (char**) Tcl_Realloc ((void*)tuple,sizeof (char*) * (1+structure->slotArrays[ind]));
      tuple [0] = structure->slotTypes[ind]->obj->name;
      for (jnd=1; jnd <= structure->slotArrays[ind]; jnd++) {
        tuple [jnd] = structure->slotNames[ind];
      }
      elements [ind+1] = Tcl_Merge (jnd, tuple);
    }
    // group all element in result and free tempry element lists
    *result = Tcl_Merge (ind+1, elements);
    for (ind=0;ind < structure->count; ind ++) {
      Tcl_Free (elements[ind+1]);
    }

  // free all tempry structures
  Tcl_Free ((void*)elements);
  Tcl_Free ((void*)tuple);  
  }
}

/**-----------------------------------------------------------------
 *  Print or make a list with structure information
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeHelp (JWRAP_modules *module, int listAsked, char** line) {
 int ind;
 int  nbStruct;
 char **slot=NULL;

 //Check we have structures
 if (module->structures == NULL) {
  *line = strdup (module->name);
  return;
 } 

 if (!listAsked) {
   fprintf (stdout,"#\n## --- Complex Types For Module=%s\n", module->name);
 }
 // First we count structure number
 for (nbStruct=0;module->structures[nbStruct] != NULL; nbStruct++);  
 slot = (char**)Tcl_Realloc ((void*)slot, sizeof (char*) * (nbStruct+1));
 slot [0] = module->name;

 // Add structure in module list
 for (ind=0; module->structures[ind] != NULL; ind ++) {
   jWrapTypeInfo (module->structures[ind], listAsked, &slot[ind+1], ind);
 }

 if (listAsked) {
   // build a list with all modules lines
   *line = Tcl_Merge (nbStruct+1, slot);
   // free an intermediate lines
   for (ind= 0; ind < nbStruct; ind ++) Tcl_Free (slot [ind+1]);
 }

 Tcl_Free ((void*)slot);

}


/**-----------------------------------------------------------------
 * Alias make a link between a structure and a type def
 * We first search is source exist in hashtable and then
 * register new name with same structure address. TypeAlias
 * is done in two step because complex type are a super set
 * of basic Tcl core type. When an alias succeeded we look for
 * PtrType in order aliasing Ptr as Well
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeAlias (JWRAP_modules *module, char *source, char *dest) {
  char name [JWRAP_MAX_NAME];
  int new;
  Tcl_ObjType   *tclType,*tclAliasType;
  Tcl_HashEntry *entryPtr;
  JWRAP_structs *structure;


  // When module is valid we check for complex type aliasing 
  if (module != NULL) {

    // Build label name from structure name
    sprintf (name,"OBJ_%s", source);
 
    // search for source structure if not found check for Tcl Basic Type
    entryPtr = Tcl_FindHashEntry (module->hashTable,name);

    // If we are facing a complex type we register it in module hashtable
    if (entryPtr != NULL) {
      // Get structure address and build destination name
      structure = (JWRAP_structs*) Tcl_GetHashValue (entryPtr);

      // Store in hashtable
      sprintf (name,"OBJ_%s", dest);
      entryPtr = Tcl_CreateHashEntry (module->hashTable, name, &new);
      if (!new) goto alreadyRegister;
      Tcl_SetHashValue (entryPtr, (ClientData) structure);

      // We successfully register basic type try with pointer on same type
      sprintf (name,"OBJ_%s_Ptr", source);
      entryPtr = Tcl_FindHashEntry (module->hashTable,name);
      if (entryPtr != NULL) {
        // Get structure address and build destination name
        structure = (JWRAP_structs*) Tcl_GetHashValue (entryPtr);
        sprintf (name,"OBJ_%s_Ptr", dest);
        entryPtr = Tcl_CreateHashEntry (module->hashTable, name, &new);
        if (!new) goto alreadyRegister;
        Tcl_SetHashValue (entryPtr, (ClientData) structure);
      }
    }
  }

  // In any case try to alias on a basic Tcl type

  // If destination alias is already register return now
  if (Tcl_GetObjType (dest)) {
      jWrapLog (5,"WARNING jWrapTypeAlias: type [%s] already registered\n", dest);    
  } else {

     // In order making alias source should be a valid Tcl type
     tclType = Tcl_GetObjType (source);
     if (tclType == NULL) goto noTclType;

     // Create a new type and register it with same translation routines as source type
     tclAliasType = (Tcl_ObjType*) Tcl_Alloc (sizeof (Tcl_ObjType));
     memcpy (tclAliasType, tclType, sizeof (Tcl_ObjType));
     

     // Register new type in Tcl interp with alias name
     tclAliasType->name = dest;
     Tcl_RegisterObjType (tclAliasType);

     // try to register Ptr equivalent type if any
     sprintf (name,"%s_Ptr", source);
     tclType = Tcl_GetObjType (name);
     if (tclType == NULL) return;   // no ptr declare just return

     tclAliasType = (Tcl_ObjType*) Tcl_Alloc (sizeof (Tcl_ObjType));
     memcpy (tclAliasType, tclType, sizeof (Tcl_ObjType));

     // Register new Ptr type in Tcl interp with alias name
     sprintf (name,"%s_Ptr", dest);
     if (Tcl_GetObjType (name)) {
      jWrapLog (5,"WARNING jWrapTypeAlias: type [%s] already registered\n", name);    
     } else {
      tclAliasType->name = strdup (name);
      Tcl_RegisterObjType (tclAliasType);
     }
  }

  return; // --------------- OK -----------------

alreadyRegister:
  jWrapLog (3, "jWrapTypeAlias: Warning Type [%s] is already register\n", dest); 
  return;

noTclType:
  jWrapLog (2,"jWrapTypeAlias: Warning Type [%s] can't find [%s] source Tcl type\n",dest,source);
  return;
}


/**-----------------------------------------------------------------
 * Register structure in module hashtable
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeRegister(JWRAP_modules *module, JWRAP_structs *structure
                              ,Tcl_ObjType *tclType,Tcl_ObjType *tclPtr) {
  char name [JWRAP_MAX_NAME];
  Tcl_HashEntry *entryPtr;
  int new;

  if ((tclType != NULL) && (Tcl_GetObjType (tclType->name) == NULL)) {
    // Build label name from structure name
    sprintf (name,"OBJ_%s", tclType->name);
 
    // Store in hashtable
    entryPtr = Tcl_CreateHashEntry (module->hashTable, name, &new);
    if (!new) goto alreadyRegister;
    Tcl_SetHashValue (entryPtr, (ClientData) structure);

    // Reference Tcl Type no possible conflic all structure are modname prefixed
    Tcl_RegisterObjType (tclType);
  }

  // For Structure only we registrate a pointer equivalent
  if ((tclPtr != NULL) && (Tcl_GetObjType (tclPtr->name) == NULL)) {
    // register _Ptr equivalent struct pointer
    sprintf (name,"OBJ_%s_Ptr", tclType->name);
 
    // Store in hashtable
    entryPtr = Tcl_CreateHashEntry (module->hashTable, name, &new);
    if (!new) goto alreadyRegister;
    Tcl_SetHashValue (entryPtr, (ClientData) structure);

    Tcl_RegisterObjType (tclPtr);
  }

  return; // --------------- OK -----------------

alreadyRegister:
  jWrapLog (1, "jWrapTypeRegister Structure [%s] already register in module [%s]\n"
                  , name, module->name); 
     
}

/**-----------------------------------------------------------------
 * search in TCL type register an store in jWrap module type array
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeCheck (JWRAP_types *usedType, char* typeName, unsigned int typeSize) {

 // check this is not a standard TCL type
 usedType->obj = Tcl_GetObjType (typeName);
 
 // if unknown we register a new jWrap cookie type
 if (usedType->obj == NULL) {
   jWrapCookieRegisterType (usedType, typeName);

 } else {

   // We use free routine to classify type
   if (usedType->obj->freeIntRepProc == jWrapTypeClean) {
       usedType->magic = JWRAP_STRUCT;

   } else if (usedType->obj->freeIntRepProc == jWrapTypeFree) {
       usedType->magic = JWRAP_POINTER;

   } else {
       usedType->magic = JWRAP_BASIC;
   }
 }
 usedType->size = typeSize;
  
} // end initialiseType

/** -----------------------------------------------------------------
 * Init module register some Tcl to basic type equivalence
 **-----------------------------------------------------------------*/
PUBLIC void jWrapTypeInit (Tcl_Interp *interp) {
 
  char *strInt  = "int";
  char *strBool = "bool";

  // Alias some basic type
  jWrapTypeAlias (NULL, strInt    , "long");
  jWrapTypeAlias (NULL, strInt    , "short");
  jWrapTypeAlias (NULL, "boolean" ,  strBool);
  jWrapTypeAlias (NULL, "double"  , "float");

  jWrapTypeInt      =  Tcl_GetObjType (strInt);
  if (jWrapTypeInt  == NULL) goto errType;
  jWrapTypeList     =  Tcl_GetObjType ("list");
  if (jWrapTypeList == NULL) goto errType;

  return;

errType:
  jWrapPanic (NULL, "jWrapTypeInit: did not find basic [int|list] tcl type [hug!!!]\n");
}
