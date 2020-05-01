/*
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   stringRuntimeTornado.c map string on vxWorks
 * Projet    :   jWrap
 * Module    :   TORNADO VxWorks Tornado interface
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/stringRuntimeWpr.c,v $
 *
 * Modification History
 * --------------------
 * 01b,16feb99,Fulup,externalized WTX module
 * 01a,05jun98,Fulup,written
 */

/** -------------------------------------------------------------------
 ** provides a string transparent facility from tclsh to VxWors target
 ** in jWrap string are mapped on <char_Ptr>. Nevertheless as Tornado
 ** string are not compatible with tclsh hosted string because they have
 ** to be allocated remotely on target, tornado strings are remapped for each
 ** tornadoModule under ModuleName_char_Ptr, when user only use one target
 ** server he can remap them using <typedef char* targetString;> in his
 ** wrapper interface.
 ** -------------------------------------------------------------------*/

#include "libRuntimeTornado.h"
#include <string.h>

/**********************************************************************
 ** Free a String on target
 ** @param info backward link to a Tornado binded module
 ** @param tclObj TclObject with a valid internal rep
 **********************************************************************/
RESTRICTED void tornadoStringFree (TORNADO_infos *info,Tcl_Obj *tclObj)
{
  // place string address in long value for C
  jWrapLog (5,"tornadoStringFree: strAdr=0x%x\n"
  ,tclObj->internalRep.twoPtrValue.ptr1);

  if (WTX_OK != wtxMemFree (info->tornadoId->wtxId
     ,(TGT_ADDR_T)tclObj->internalRep.twoPtrValue.ptr1))
    goto errFree;

 return;

 errFree:
  fprintf (stderr,"tornadoStringFree: cannot free: <0x%p>\nWTX_ErrMsg=%s\n"
          , tclObj->internalRep.twoPtrValue.ptr1,wtxErrMsgGet (info->tornadoId->wtxId));
}


/**************************************************************************
 ** Update external string representation from internal internal values
 ** this routine read ram on target and place a copy as external rep.
 ** @param info backward link on Tornado module
 ** @param tclObj a tcl boject with a valid internal rep
 ** @error never return an error because this would break external reprentation
 ** building in union, when a numeric is map on a string pointer adress.
 **************************************************************************/
RESTRICTED void tornadoStringCc2Tcl (TORNADO_infos *info, Tcl_Obj *tclObj)
{
  char inputString [50];
  WTX_GOPHER_TAPE  *tape;

    jWrapLog (4,"tornadoStringCc2Tcl: strAdr=0x%x\n"
    ,tclObj->internalRep.twoPtrValue.ptr1);

    if (tclObj->internalRep.twoPtrValue.ptr1 == NULL) {
        // if C value is NULL
	jWrapStrDup (tclObj,jWrapStringNull);
    } else {
#ifdef WTX_SIMULATION
	return jWrapStringCc2Tcl  (tclObj);
#else

        // get string from target with gopher
        sprintf (inputString,"0x%lx $",(unsigned long)tclObj->internalRep.twoPtrValue.ptr1);
        tape = wtxGopherEval (info->tornadoId->wtxId,inputString);
        if (tape == NULL) goto warningMmu;

        // if Gopher Tape hold a valid string copy it to TCL
        tclObj->length = tape->len-1;
        if (tclObj->length > 0) {
          jWrapStrDup (tclObj, &tape->data[1]);
        } else {
  	  jWrapStrDup (tclObj, jWrapStringNull);
        }
        // free gopher tape
        wtxResultFree (info->tornadoId->wtxId, tape);
#endif
   }
   return;

warningMmu:
 // String is no readable return a message to user but no error
 sprintf (jWrapStaticMessage,"<%s> not a valid char* pointer",inputString);
 jWrapStrDup (tclObj, jWrapStaticMessage);
 return;
}

/**********************************************************************
 ** Update Internal string value
 ** Malloc equivalent area on target and copy external rep into it
 ** Save remote target string adress as tcl object internal rep
 ** @info backward link in tornado module
 ** tclObbj tcl object with a valid external rep
 ** @note if external rep is <NULL> we set internal rep to zero.
 **********************************************************************/
RESTRICTED int tornadoStringTcl2Cc (TORNADO_infos *info,Tcl_Interp *interp,Tcl_Obj *tclObj)
{
  TGT_ADDR_T strAdr;

  // check user does not want a null pointer
  if (!strcmp (TCL_STRING(tclObj), jWrapStringNull)) {
    tclObj->internalRep.twoPtrValue.ptr1 = NULL;
    tclObj->internalRep.twoPtrValue.ptr2 = NULL;
    tclObj->typePtr = info->stringType;
    return TCL_OK;
  }

  // allocate destination ram area on target
  strAdr = wtxMemAlloc (info->tornadoId->wtxId, (unsigned)tclObj->length+1);
  if (strAdr == (TGT_ADDR_T) NULL) goto errWtxMalloc;

  jWrapLog (4,"tornadoStringTcl2Cc: strAdr=0x%p\n", strAdr);

  // copy external rep onto target
  if (WTX_ERROR == (INT32) wtxMemWrite (info->tornadoId->wtxId
     , tclObj->bytes, strAdr, (unsigned)tclObj->length+1)) goto errWtxMemWrite;

  // place string addr
  tclObj->internalRep.twoPtrValue.ptr1= (void*) strAdr;
  tclObj->typePtr = info->stringType;
  return TCL_OK;

errWtxMalloc: // ---------------------- ERROR -------------------
  jWrapPanic (interp,"tornadoStringTcl2Cc can't alloc tornadoMemPool:%s WTX_ErrMsg=[%s]\n"
	     ,info->tornadoId->targetName
	     ,wtxErrMsgGet (info->tornadoId->wtxId));

errWtxMemWrite:
  jWrapPanic (interp,"tornadoStringTcl2Cc,can't copy %s to wtxMemPool [0x%x] WTX_ErrMsg=[%s]\n"
	      ,tclObj->bytes, strAdr, wtxErrMsgGet (info->tornadoId->wtxId));

  return JWRAP_IMPOSSIBLE;
}

/********************************************************************
 ** String init as to be redone for each Winbug DLL because win32
 ** duplicate static data area for each DLL making jWrapEntyString
 ** to have a different adresse in Tcl.dll jWrap.dll tornado.dll etc.
 ** note: not meaningfull under Unix.
 ********************************************************************/
RESTRICTED void tornadoStringInit (Tcl_Interp *interp) {

#ifdef _WINDOWS_
Tcl_Obj *tclObj;

  // getEmptyString from a ew objet from bypass WinBug limittation on dll
  tclObj = Tcl_NewObj();
  Tcl_IncrRefCount(tclObj);
  jWrapStringEmpty = tclObj->bytes;
  Tcl_DecrRefCount(tclObj);
#endif

}
