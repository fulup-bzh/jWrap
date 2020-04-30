/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   translateLibType.c map application type into jWrap
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/typemap-c/translateDemoTypemap.c,v $
 *      State       : $State: Exp $
 *
 * Modification History
 * --------------------
 * 01a,03mar98,Fulup,written
 */

#include "libRuntimeJwrap.h"
#include "funcDemoTypemap.h"

#include <string.h>

// We need this for init static type
LOCAL void freeAdrInt  (Tcl_Obj *objPtr);
LOCAL void dupAdrInt   (Tcl_Obj *srcPtr, Tcl_Obj *copyPtr);
LOCAL void getAdrFromC (Tcl_Obj *objPtr);
LOCAL int  putAdrIntoC (Tcl_Interp *interp,Tcl_Obj *objPtr);


// All jWrap base type are static
static Tcl_ObjType adrCustomType = {
    "typeMapAdrs_Ptr",			/* name * is replace with Ptr */
    freeAdrInt,	                        /* freeIntRepProc */
    dupAdrInt,		                /* dupIntRepProc */
    getAdrFromC,	        	/* updateStringProc */
    putAdrIntoC			        /* setFromAnyProc */
}; 


/******************************************************************
 **   copy string taken from TCL source code
 ******************************************************************/
LOCAL void freeAdrInt(Tcl_Obj *objPtr) {

  if (objPtr->internalRep.otherValuePtr != NULL) {
    Tcl_Free (objPtr->internalRep.otherValuePtr);
  }
}

/******************************************************************
 **   copy string taken from TCL source code
 ******************************************************************/
LOCAL void dupAdrInt(Tcl_Obj *srcPtr, Tcl_Obj *copyPtr)
{
    /*
     * Tricky point: the string value was copied by generic object
     * management code, so it doesn't contain any extra bytes that
     * might exist in the source object.
     */
    copyPtr->internalRep.otherValuePtr = (typeMapAdrs*) Tcl_Alloc (sizeof(typeMapAdrs));
    if (copyPtr->internalRep.otherValuePtr) goto errMalloc;

    memcpy (copyPtr->internalRep.otherValuePtr,copyPtr->internalRep.otherValuePtr
                                              ,sizeof(typeMapAdrs));
    copyPtr->typePtr = &adrCustomType;
    return;

errMalloc:
   jWrapPanic (NULL,"DupAdrInt: can't malloc %s", TCL_STRING (copyPtr));   
}

/**************************************************************************
 ** Update external string representation from internal internal values
 **************************************************************************/
LOCAL void getAdrFromC (Tcl_Obj *objPtr)
{
  char *argv[5];
  char zip  [10];
  unsigned int  len;
  typeMapAdrs *adr;  

    if (objPtr->internalRep.otherValuePtr == NULL) {
      // if C value is NULL 
      objPtr->bytes = tclEmptyStringRep;
      objPtr->length = 0;
    } else {
      // map void structure on application adr type
      adr = (typeMapAdrs*) objPtr->internalRep.otherValuePtr;

      // build external representation in key
      argv[0] = adr->lastName;
      argv[1] = adr->firstName;
      argv[2] = adr->adress;
      sprintf (zip,"%d",adr->zip);
      argv[3] = zip;
      argv[4] = adr->town;
   
      // Allocate room to receive result
      objPtr->bytes  = Tcl_Merge (5,argv);
      objPtr->length = strlen (objPtr->bytes);
    }
}

/**********************************************************************
 ** Update Internal from string value
 **********************************************************************/
LOCAL int putAdrIntoC (Tcl_Interp *interp,Tcl_Obj *objPtr)
{
  typeMapAdrs *adr;
  int status;
  int len;
  Tcl_Obj *slot;

   // check this is a valid list 
   status = Tcl_ListObjLength (interp, objPtr,&len);
   if (status == TCL_ERROR) goto errList;

   // check list as the wanted size
   if (len != 5) goto errSlots;


   // allocate space for the adresse
   adr = (typeMapAdrs*) Tcl_Alloc (sizeof(typeMapAdrs));
   if (adr==NULL) goto errMalloc;

   // fill up adr structure from list
   (void) Tcl_ListObjIndex (interp, objPtr, 0, &slot);
   if (slot->length > 20) goto errTooBig;
   adr->lastName = Tcl_GetStringFromObj (slot,NULL);

   (void) Tcl_ListObjIndex (interp, objPtr, 1, &slot);
   if (slot->length > 20) goto errTooBig;
   adr->firstName = Tcl_GetStringFromObj (slot,NULL);
   
   (void) Tcl_ListObjIndex (interp, objPtr, 2, &slot);
   if (slot->length > 20) goto errTooBig;
   adr->adress = Tcl_GetStringFromObj (slot,NULL);

   (void) Tcl_ListObjIndex (interp, objPtr, 3, &slot);
   status = Tcl_GetIntFromObj (interp, slot, &adr->zip);
   if (status != TCL_OK) return status;
   if ((adr->zip > 99999) || (adr->zip <1000)) goto errZip;

   (void) Tcl_ListObjIndex (interp, objPtr, 4, &slot);
   if (slot->length > 20) goto errTooBig;
   adr->town = Tcl_GetStringFromObj (slot,NULL);

   // store result in Tcl object and move back to jWrap
   objPtr->internalRep.otherValuePtr = adr;
   return TCL_OK;

errZip:
  jWrapPanic (interp,"Zip code should be in between 1000 and 9999 not:%s"
                    ,Tcl_GetStringFromObj (slot,NULL));

errList:
  jWrapPanic (interp,"This is not a valid adresse list %s", objPtr->bytes);

errSlots:
  jWrapPanic (interp,"Adresse list should have 5 element and not: %d", len);

errTooBig:
  jWrapPanic (interp,"list element bigger than 20 characters :%s", TCL_STRING(objPtr));

errMalloc:
  jWrapPanic (interp,"Cannot malloc adress :%s", TCL_STRING(objPtr));
 
// for gcc not to complain
  return JWRAP_IMPOSSIBLE;
}


/*******************************************************************
 ** register default jWrap type
 *******************************************************************/
PUBLIC void customInitType (Tcl_Interp *interp) {

Tcl_ObjType *intType,longType;

  // Check jWrap as been correctelly inited
  if (Jwrap_Init (interp) != TCL_OK) {
     jWrapPanic (interp,"DemoTypemap Custom Init jWrap Init failled\n");
  }

  Tcl_RegisterObjType (&adrCustomType);

  return;
}










