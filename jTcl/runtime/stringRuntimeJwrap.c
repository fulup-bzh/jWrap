/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   typeWrap.c provided some default and usefull type mapping
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/stringRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01c,09mar99,Fulup,checked string bytes != NULL before strcmp
 * 01b,04jul98,Fulup,ispell code
 * 01a,18feb98,Fulup,written
 */


#include "libRuntimeJwrap.h"
#include <string.h>
#include <signal.h>
#include <stdlib.h>

// this can be usefull to many modules
EXPORT char *jWrapStringNull  = "NULL";
EXPORT char *jWrapStringEmpty;

EXPORT char *tclEmptyStringRep;
EXPORT char tclEmptyString;

// We need this for init static type
LOCAL void      dupStringInternal(Tcl_Obj *srcPtr, Tcl_Obj *copyPtr);
LOCAL void      getStringFromC   (Tcl_Obj *tclObj);
LOCAL int       putStringIntoC   (Tcl_Interp *interp,Tcl_Obj *tclObj);
LOCAL void      freeStringInternal (Tcl_Obj *tclObj);
LOCAL jmp_buf   checkPoint;

EXPORT Tcl_ObjType jWrapStringPtrType = {
    "char_Ptr",				/* name */
    freeStringInternal,	 /* freeIntRepProc */
    dupStringInternal,	 /* dupIntRepProc */
    jWrapStringCc2Tcl,	 /* updateStringProc */
    putStringIntoC			 /* setFromAnyProc */
};

EXPORT Tcl_ObjType jWrapConstStringPtrType = {
    "const_char_Ptr",				/* name const char* */
    NULL,	                /* never free internal rep */
    dupStringInternal,	  /* dupIntRepProc */
    jWrapStringCc2Tcl,	 	/* updateStringProc */
    NULL			/* No option to update string */
};

// define char** as a list of pointer
LOCAL void dupStringListInternal (Tcl_Obj *srcPtr, Tcl_Obj *copyPtr);
LOCAL void getStringListFromC    (Tcl_Obj *tclObj);
LOCAL int  putStringListIntoC    (Tcl_Interp *interp,Tcl_Obj *tclObj);
LOCAL void freeStringListInternal(Tcl_Obj *tclObj);

EXPORT Tcl_ObjType jWrapStringListType = {
    "char_Ptr_Ptr",			/* name */
    freeStringListInternal,	        /* freeIntRepProc */
    dupStringListInternal,		/* dupIntRepProc */
    getStringListFromC,	        	/* updateStringProc */
    putStringListIntoC			/* setFromAnyProc */
};

// define char as a basic char or a small number
LOCAL void getStringCharFromC    (Tcl_Obj *tclObj);
LOCAL int  putStringCharIntoC    (Tcl_Interp *interp,Tcl_Obj *tclObj);
static Tcl_ObjType jWrapStringCharType = {
    "char",			        /* name */
    (Tcl_FreeInternalRepProc *) NULL,   /* freeIntRepProc */
    (Tcl_DupInternalRepProc *) NULL,	/* dupIntRepProc */
    getStringCharFromC,	        	/* updateStringProc */
    putStringCharIntoC			/* setFromAnyProc */
};

/**-------------------------------------------------------------------------
 * Create a new string and set usage count to one
 * ------------------------------------------------------------------------*/
PUBLIC Tcl_Obj *jWrapStringNew (char* chaine,int len) {
Tcl_Obj *tclObj;

  tclObj = Tcl_NewStringObj (chaine, len);
  Tcl_IncrRefCount (tclObj);

return tclObj;
}

/**************************************************************************
 * Update external string representation from internal values. Make a
 * string copy with Tcl_Alloc of internal string. This routine return a
 * unique character string, no protection is done and resulting character
 * may be unprintable.
 **************************************************************************/
LOCAL void getStringCharFromC (Tcl_Obj *tclObj)
{
    if (tclObj->internalRep.twoPtrValue.ptr1 == NULL) {
        // if C value is NULL
	jWrapStrDup (tclObj, "\\0");
    } else {
        // if C hold a valid string copy it to TCL
        tclObj->length = 1;
        tclObj->bytes  = Tcl_Alloc (2);
        if (tclObj->bytes == NULL) goto errorMalloc;
        tclObj->bytes [0] = (char)tclObj->internalRep.longValue;
        tclObj->bytes [1] = '\0';
    }
    return;

errorMalloc:
 jWrapPanic (NULL,"setStringFromC can't malloc %d byte for string:%x\n"
            ,tclObj->length,tclObj->internalRep.twoPtrValue.ptr1);
}

/**********************************************************************
 * Update Internal string value for a char. Input can be either a
 * one char string or an integer smaller than 256. Priory is given
 * to character also to pass and '1' as a number user should give
 * 01.
 * @note in some architecture Tcl change number to int type
 * before calling this routine. In this case in oder passing a number
 * as a char user should give "1" as parameter to corresponding command.
 **********************************************************************/
LOCAL int putStringCharIntoC (Tcl_Interp *interp,Tcl_Obj *tclObj) {
  // Int type are compatible with char
  if ((tclObj->typePtr != NULL) && (tclObj->typePtr->setFromAnyProc
          == jWrapTypeInt->setFromAnyProc)) {
    if (tclObj->internalRep.longValue > 255) goto errToBig;

  } else {

    switch (tclObj->length) {
    case 0:
      // we are facing an empty object return an empty string
      tclObj->bytes  = jWrapStringEmpty;
      tclObj->length = 0;
      break;
    case 1:
      // place string address in long value for C
      tclObj->internalRep.longValue= (long)tclObj->bytes[0];
      tclObj->typePtr = &jWrapStringCharType;
      break;
    default:
      // try to convert external rep to to an integer
      if (Tcl_ConvertToType (interp,tclObj,jWrapTypeInt) != TCL_OK) goto errNotChar;
      if (tclObj->internalRep.longValue > 255) goto errToBig;
    }
  }
  return TCL_OK;

errNotChar:
  Tcl_AppendResult (interp,"putStringCharIntoC Invalid external string [char] representation ["
                   ,tclObj->bytes,"]\n", NULL);
  return TCL_ERROR;
errToBig:
  {
      char number [50];
        sprintf (number,"%ld",tclObj->internalRep.longValue);
        Tcl_AppendResult (interp,"putStringCharIntoC Integer [",number
                   ,"] to big for a valid representation of type [char]\n", NULL);
  }
  return TCL_ERROR;
}

/******************************************************************
 * Copy string taken from TCL source code, duplicate long value
 * internal representation.
 ******************************************************************/
LOCAL void dupStringInternal(Tcl_Obj *srcPtr, Tcl_Obj *destPtr)
{
 int len;
    /*
     * Tricky point: the string value was copied by generic object
     * management code, so it doesn't contain any extra bytes that
     * might exist in the source object.
     */

    len = strlen ((char*)srcPtr->internalRep.twoPtrValue.ptr1);
    destPtr->internalRep.twoPtrValue.ptr1 = (void*) Tcl_Alloc (len+1);
    memcpy (destPtr->internalRep.twoPtrValue.ptr1,srcPtr->internalRep.twoPtrValue.ptr1,len+1);
    destPtr->typePtr = &jWrapStringPtrType;
}

/**************************************************************************
 ** Protect string conversion routine from bus error
 **************************************************************************/
LOCAL void  busErrorHandler (int sig) {
  longjmp (checkPoint,-1);
}

/**************************************************************************
 * Update external string representation from internal internal values
 * this routine protect itself from bus error because in many occasion
 * a char* pointer is neither null neither a valid value.
 * @note under debugger bus error protection is inefficient as well as
 * for WIN32 DLL where this facility is not available.
 **************************************************************************/
PUBLIC void jWrapStringCc2Tcl (Tcl_Obj *tclObj)
{
  void      *oldSignalhandler;

    // prepare emergency panic return
    if (setjmp (checkPoint)) goto warningMmu;
    oldSignalhandler = signal (SIGSEGV,busErrorHandler);

    if (tclObj->internalRep.twoPtrValue.ptr1 == NULL) {
        // if C value is NULL
        jWrapStrDup (tclObj,jWrapStringNull);
    } else {
        // if C hold a valid string copy it to TCL
        tclObj->length = strlen ((char*)tclObj->internalRep.twoPtrValue.ptr1);
        tclObj->bytes  = Tcl_Alloc ((unsigned int) tclObj->length+1);
        if (tclObj->bytes == NULL) goto errorMalloc;
        memcpy (tclObj->bytes,tclObj->internalRep.twoPtrValue.ptr1,(unsigned int)tclObj->length+1);    }
    signal (SIGSEGV,oldSignalhandler);
    return;

warningMmu:
 // String is no readable return a message to user but no error
 {
   char message [64];
   signal (SIGSEGV,oldSignalhandler);
   sprintf (message,"<%p> not a valid char* pointer",tclObj->internalRep.twoPtrValue.ptr1);
   jWrapStrDup (tclObj,message);
 }
 return;

errorMalloc:
 jWrapPanic (NULL,"setStringFromC can't malloc %d byte for string:%x\n"
            ,tclObj->length,tclObj->internalRep.twoPtrValue.ptr1);
}

/**********************************************************************
 * Free internal buffer attached to string
 **********************************************************************/
LOCAL void freeStringInternal (Tcl_Obj *tclObj)
{
  // String should have been allocated with 'Tcl_Alloc'
  Tcl_Free (tclObj->internalRep.twoPtrValue.ptr1);
}

/**********************************************************************
 * Update Internal string value. Make a copy of external representation
 * and map it onto Tcl object internal rep. This internal rep is kept
 * even when external presentation changes.
 **********************************************************************/
LOCAL int putStringIntoC (Tcl_Interp *interp,Tcl_Obj *tclObj)
{
  int len;

  // if we dont have a valid external rep build it now
  if (TCL_STRING(tclObj) == NULL) {
     if (tclObj->typePtr == NULL) goto internalError;
     tclObj->typePtr->updateStringProc (tclObj);
  }

  // check user does not want a null pointer
  if (!strcmp (TCL_STRING(tclObj), jWrapStringNull)) {
    tclObj->internalRep.twoPtrValue.ptr1 = NULL;
    tclObj->internalRep.twoPtrValue.ptr2 = NULL;
    tclObj->typePtr = &jWrapStringPtrType;
    return TCL_OK;
  }

  // place string address in long value for C
  len = strlen (tclObj->bytes);
  tclObj->internalRep.twoPtrValue.ptr1 = Tcl_Alloc (len+1);
  memcpy (tclObj->internalRep.twoPtrValue.ptr1, (void*) tclObj->bytes,len+1);
  tclObj->typePtr = &jWrapStringPtrType;
  return TCL_OK;

 internalError:
  jWrapPanic (interp,"got an empty object");
  return TCL_ERROR;
}

/******************************************************************
 *   free string List internal buffer
 ******************************************************************/
LOCAL void freeStringListInternal(Tcl_Obj *objList) {
 char **stringList;

  stringList = (char**)objList->internalRep.twoPtrValue.ptr1;
  objList->typePtr = NULL;

  Tcl_Free ((char*)stringList);
}

/******************************************************************
 *   copy string List internal data
 ******************************************************************/
LOCAL void dupStringListInternal(Tcl_Obj *srcPtr, Tcl_Obj *desPtr)
{
 int  objc;
 char **stringListSrc;
 char **stringListDes;

 // As string is only limited with a NULL char we have to check for end
 stringListSrc = (char**)srcPtr->internalRep.twoPtrValue.ptr1;
 for (objc=0; stringListSrc[objc] != NULL; objc++) ;

 // allocate internal destination data space
 stringListDes = (char**) Tcl_Alloc (sizeof(char*) * (objc+1));
 if (stringListDes == NULL) goto errorMalloc;

 // copy source to output and mark and of destination list with null
 for (objc=0; stringListSrc[objc] != NULL; objc++) {
  stringListDes [objc] =  stringListSrc [objc];
 }
 stringListDes [objc] = NULL;

 // Update Tcl destination Object
 desPtr->internalRep.twoPtrValue.ptr1=(void*) stringListDes;
 desPtr->bytes=NULL;
 desPtr->typePtr = &jWrapStringListType;

 return; // OK

errorMalloc:
 jWrapPanic (NULL,"dupStringListInternal can't malloc %d slot for string list",objc);
 return;
}

/****************************************************************************
 * Update external string List representation from internal internal values
 * internal representation is a array of string pointer NULL terminated.
 * @note not bus error protected.
 ****************************************************************************/
LOCAL void getStringListFromC (Tcl_Obj *tclObj)
{
  int  argc;
  char **stringList;

    // get string list internal representation from Tcl object and compute length
    stringList = (char**) tclObj->internalRep.twoPtrValue.ptr1;
    if (stringList == NULL) {
      tclObj->bytes  = Tcl_Merge (0,NULL);
    } else {
      for (argc=0; stringList[argc] != NULL; argc++);
      // create a list from all TclObj in objv
      tclObj->bytes  = Tcl_Merge (argc, stringList);
    }
    tclObj->length = strlen (tclObj->bytes);
    return; // OK
}

/**********************************************************************
 * Update Internal string list value from external string. External rep
 * is a Tcl list and internal list is an array of string pointer NULL
 * terminated. This mechanism is the easiest way for passing a variable
 * list of argument to a C routine from TCL without dealing with
 * Tcl C interface.
 **********************************************************************/
LOCAL int putStringListIntoC (Tcl_Interp *interp,Tcl_Obj *objList)
{
 int status,len,ind;
 char **stringList;
 Tcl_Obj *slot;

  // check user does not want a null pointer
  if ((TCL_STRING(objList) != NULL) && (!strcmp (TCL_STRING(objList), jWrapStringNull))) {
    objList->internalRep.twoPtrValue.ptr1 = NULL;
    objList->internalRep.twoPtrValue.ptr2 = NULL;
    objList->typePtr = &jWrapStringListType;
    return TCL_OK;
  }

   status = Tcl_ListObjLength (interp, objList,&len);
   if (status == TCL_ERROR) goto errList;

   // allocate stringlist
   stringList = (char**) Tcl_Alloc (sizeof(char*)*(len+1));
   if (stringList == NULL) goto errMalloc;

   // set and NULL in last slot
   stringList [len] = NULL;


   // place Tcl object string in list
   for (ind=0; ind <len; ind++) {
     (void) Tcl_ListObjIndex (interp, objList, ind, &slot);
     stringList[ind] = TCL_STRING (slot);
   }

   // make Tcl not to delete our list
   objList->internalRep.twoPtrValue.ptr1 = (void*) stringList;
   objList->typePtr = &jWrapStringListType;

   return TCL_OK;

errList:
  jWrapPanic (interp,"StringList: This is not a valid string list %s", objList->bytes);

errMalloc:
  jWrapPanic (interp,"StringList: Malloc failed for %d elements", len);

// for gcc not to complain
  return JWRAP_IMPOSSIBLE;
}

/*******************************************************************
 * register char char_Ptr and char_Ptr_Ptr as native Tcl type.
 *******************************************************************/
PUBLIC void jWrapStringInit (Tcl_Interp *interp) {

Tcl_Obj *tclObj;

  // getEmptyString from a new object from bypass WinBug limitation on dll
  tclObj = Tcl_NewObj();
  Tcl_IncrRefCount(tclObj);
  jWrapStringEmpty = tclObj->bytes;
  Tcl_DecrRefCount(tclObj);

  // TCL 8.0 compat;
  tclEmptyStringRep= &tclEmptyString;

  // register char * as string
  Tcl_RegisterObjType (&jWrapStringPtrType);
  Tcl_RegisterObjType (&jWrapConstStringPtrType);
  Tcl_RegisterObjType (&jWrapStringListType);
  Tcl_RegisterObjType (&jWrapStringCharType);
}
