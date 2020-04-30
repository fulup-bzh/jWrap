/*
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   interpTclTarWrap.c interface internal to TCL structure
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/interpRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01d,06mar99,Fulup,added jWrapVarg
 * 01c,02sep98,Fulup,chaned TclObj native handling
 * 01b,07jul98,Fulup,ispell code
 * 01a,18feb98,Fulup,written
 */


#include "libRuntimeJwrap.h"

// We need this for init static type
LOCAL void getInterpFromC   (Tcl_Obj *objPtr);
LOCAL int  putInterpIntoC   (Tcl_Interp *interp,Tcl_Obj *objPtr);
static Tcl_ObjType tclInterpType = {
    "Tcl_Interp_Ptr",				   /* name */
    (Tcl_FreeInternalRepProc*) NULL,	           /* freeIntRepProc */
    (Tcl_DupInternalRepProc *) NULL,               /* dupIntRepProc */
    getInterpFromC,	                           /* updateStringProc */
    putInterpIntoC	                           /* setFromAnyProc */
}; 

// define char** as a list of pointer
LOCAL void freeTclObjClone   (Tcl_Obj    *objPtr);
LOCAL void getTclObjFromC    (Tcl_Obj    *objPtr);
LOCAL int  putTclObjIntoC    (Tcl_Interp *interp,Tcl_Obj *objPtr);
static Tcl_ObjType tclTclObjType = {
    "Tcl_Obj_Ptr",			           /* name */
    freeTclObjClone,	                           /* freeIntRepProc */
    (Tcl_DupInternalRepProc *)  NULL,              /* dupIntRepProc */
    getTclObjFromC,	        	           /* updateStringProc */
    putTclObjIntoC			           /* setFromAnyProc */
};

// define char** as a list of pointer
LOCAL void freeVarg   (Tcl_Obj    *objPtr);
LOCAL void getVargFromC  (Tcl_Obj    *objPtr);
LOCAL int  putVargIntoC  (Tcl_Interp *interp,Tcl_Obj *objPtr);
static Tcl_ObjType tclVargType = {
    "JWRAP_varg_Ptr",			           /* name */
    freeVarg,	                           /* freeIntRepProc */
    (Tcl_DupInternalRepProc *)  NULL,              /* dupIntRepProc */
    getVargFromC,	        	           /* updateStringProc */
    putVargIntoC			           /* setFromAnyProc */
};

/**************************************************************************
 * Update external Interp representation from internal value
 **************************************************************************/
LOCAL void getInterpFromC (Tcl_Obj *objPtr)
{
 jWrapPanic (NULL,"getInterpFromC can't send Interp from C to Tcl");
}

/*************************************************************************
 * Update Internal value from a dummy object that is completely ignored
 * this is mandatory because jWrap map parameters one to one.
 *************************************************************************/
LOCAL int putInterpIntoC (Tcl_Interp *interp,Tcl_Obj *objPtr)
{
    // WARNING: in this case TCL object is only used for param position and counting
   
    // place Interp address in long value for C
    objPtr->internalRep.otherValuePtr= (void*)interp;
    return TCL_OK;
}

/****************************************************************************
 * Free clone object
 ****************************************************************************/
LOCAL void freeTclObjClone (Tcl_Obj *objPtr) {
 Tcl_Obj    *clone;

  // If ptr1 dont loop on ourself they is an attached clone
  if (objPtr->internalRep.otherValuePtr != objPtr) {
     // free clone if usage count allow it 
     clone = (Tcl_Obj*) objPtr->internalRep.twoPtrValue.ptr1;
  } else {
     // free internal rep with dummy clone internal rep
     clone = (Tcl_Obj*) objPtr->internalRep.twoPtrValue.ptr2;
     if ((clone->typePtr != NULL) && (clone->typePtr->freeIntRepProc != NULL)) {
       (*clone->typePtr->freeIntRepProc) (clone); 
     }
  }

  // free clone now wherever it comes from
  Tcl_DecrRefCount (clone);
}


/****************************************************************************
 * We only convert Tcl_Obj to external rep when an application routine
 * returned a Tcl_Obj, in This case we subcontract application object 
 * in order getting effective external rep.
 ****************************************************************************/
LOCAL void getTclObjFromC (Tcl_Obj *objPtr)
{
  Tcl_Obj *clone;

   // restore original Tcl Object
   clone = (Tcl_Obj*) objPtr->internalRep.otherValuePtr;
 
   // call presentation routine
   if (clone->bytes == NULL) {
     if (clone->typePtr->updateStringProc == getTclObjFromC) goto looping; 
     objPtr->typePtr->updateStringProc (clone);
   }
   objPtr->bytes  = clone->bytes;
   objPtr->length = clone->length;
   clone->bytes = NULL;

   return;

looping:
   jWrapPanic (NULL,"getTclObjFromC looping in C->tcl conversion [%s]", TCL_STRING(objPtr));
   return;
noType:
   jWrapPanic (NULL,"getTclObjFromC Not type set for TclObj clone [%s]", TCL_STRING(objPtr));
   return;
}

/**********************************************************************
 * Update Internal Interp list value from external Interp, this allows
 * a C routine jWrap interfaced to get a native Tcl objet as parameter.
 **********************************************************************/
LOCAL int putTclObjIntoC (Tcl_Interp *interp,Tcl_Obj *objPtr) 
{
   Tcl_Obj *clone = Tcl_NewObj ();
   
   // store original type and internal rep in a clone
   clone->typePtr  = objPtr->typePtr;
   clone->internalRep.twoPtrValue.ptr1 = objPtr->internalRep.twoPtrValue.ptr1;
   Tcl_IncrRefCount(clone);

   // make our object to loop on itself and store original type in ptr2
   objPtr->internalRep.twoPtrValue.ptr2 = clone;
   objPtr->internalRep.twoPtrValue.ptr1 = objPtr;

   return TCL_OK;
}

/****************************************************************************
 * Free a full cmd clone
 ****************************************************************************/
LOCAL void freeVarg (Tcl_Obj *objPtr) {
 int ind;
 JWRAP_varg *internal;

  // get internal from object 
  internal = (JWRAP_varg*) objPtr->internalRep.twoPtrValue.ptr1;

  // loop on all command parameter
  for (ind=0; ind < internal->argc; ind ++) { 
     Tcl_DecrRefCount (internal->argv[ind]);
  }

  // effectivelly free internal rep
  Tcl_Free ((void*)internal->argv);
  Tcl_Free (objPtr->internalRep.twoPtrValue.ptr1);
  objPtr->internalRep.twoPtrValue.ptr1=NULL;
}

/****************************************************************************
 * Translated from c to an external rep
 ****************************************************************************/
LOCAL void getVargFromC (Tcl_Obj *objPtr)
{
 int ind;
 JWRAP_varg  *internal;
 Tcl_ObjType *tclType;
 Tcl_Obj     *tclObj=NULL; // gcc warning
 char        **listSlot;

  // get internal from object 
  internal = (JWRAP_varg*) objPtr->internalRep.twoPtrValue.ptr1;

  // repare a list for final result
  listSlot = (char**) Tcl_Alloc (internal->argc * sizeof (char*));

  // loop on all slot
  for (ind =0; ind < internal->argc; ind++) {
    tclObj  = internal->argv[ind];
    tclType = internal->argv[ind]->typePtr;

    // if no valid external rep update it now
    if (tclObj->bytes == NULL) {
      if (tclType != NULL) {
        tclType->updateStringProc (tclObj);
      } else {
       jWrapStrDup (tclObj, "No External Rep");
      }
    }

    // save external rep pointer for final rep list making
    listSlot [ind] = tclObj->bytes;
  }

  // produce final external rep
  tclObj->bytes = Tcl_Merge (ind, listSlot);
  tclObj->length = strlen (tclObj->bytes)+1;

  // free tempry listslot array
  Tcl_Free ((void*)listSlot);
}

/**--------------------------------------------------------------------
 * Update internal rep from external routine, this routine will 
 * increment each object usage count in order tcl not to free 
 * internal rep, and then will save a pointer in Varg struct.
 **--------------------------------------------------------------------*/
LOCAL int putVargIntoC (Tcl_Interp *interp,Tcl_Obj *tclObj)
{
 int         ind;
 JWRAP_varg  *internal;
 int         status;
 Tcl_Obj     *element;
  
  // Allocate internal rep struct
  internal = (JWRAP_varg*) Tcl_Alloc (sizeof (JWRAP_varg));
  internal->interp = interp;

  // if external rep in not a list build a list now
  status = Tcl_ListObjLength (interp, tclObj, &internal->argc);
  if (status == TCL_ERROR) goto errList;

  // allocate array to store object reference
  if (internal->argc > 0) {
    internal->argv = (Tcl_Obj**) Tcl_Alloc (sizeof (Tcl_Obj*) * internal->argc);
  } else {
     internal->argv = (Tcl_Obj**)NULL; 
  }

  // loop on all object list 
  for (ind=0; ind < internal->argc; ind ++) {

    // increment internal rep of object in order TCL to keep it
    status = Tcl_ListObjIndex (interp, tclObj, ind, &element);
    if (status == TCL_ERROR) goto errList;
    Tcl_IncrRefCount(element);
   
    // save object in internal rep
    internal->argv[ind] = element;
  }

  // update tcl object internal rep
  tclObj->internalRep.twoPtrValue.ptr1 = (void*) internal;
  tclObj->typePtr = &tclVargType;
    
  return TCL_OK;

errList:
  Tcl_AppendResult (interp,"\nputVargIntoC [",tclObj->bytes
                   ,"] input prm should be a valid TCL list\n",NULL);
  return TCL_ERROR;
}

/*******************************************************************
 * register Interp type and Tcl object as Tcl native type.
 *******************************************************************/
PUBLIC void jWrapInterpInit (Tcl_Interp *interp) {

  // register type in Tcl interp
  Tcl_RegisterObjType (&tclInterpType);
  Tcl_RegisterObjType (&tclTclObjType);
  Tcl_RegisterObjType (&tclVargType);
}


