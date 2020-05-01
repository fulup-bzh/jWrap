/*
 *      Copyright(c) 1996-1999 Fridu a Free Software Company Fulup Ar Foll
 *
 * Object       : direct call to VxWorks target thru target server
 * Projet       : jWrap
 * SubModule    : VxWorks Wtx Tornado interface
 * Auteur       : Fulup Ar Foll (Fulup@fridu.bzh)
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/directRuntimeTornado.c,v $
 *
 * Modification History
 * --------------------
 * 1.1  06mar99,Fulup written
 *
 */

#include "libRuntimeTornado.h"
#include <string.h>

typedef enum {
   GOPHER_UINT32  = 0,
   GOPHER_STRING  = 1,
   GOPHER_UINT16  = 2,
   GOPHER_UINT8   = 3,
   GOPHER_FLOAT32 = 4,
   GOPHER_FLOAT64 = 5,
   GOPHER_FLOAT80 = 5,

   GOPHER_UNKNOW = -1
} GOPHER_tape_val;

// tornado info will be initialiazed at first
static TORNADO_infos tornadoInfo;
static Tcl_Obj       *zero;


// Build string convertion routine
LOCAL int Put_String (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (tornadoStringTcl2Cc (&tornadoInfo, interp, tclObj));
}
LOCAL void Get_String (Tcl_Obj *tclObj) {
  tornadoStringCc2Tcl (&tornadoInfo, tclObj);
}
LOCAL void Free_String (Tcl_Obj *tclObj) {
  tornadoStringFree (&tornadoInfo, tclObj);
}

// make Automatic Alloc/free Tornado string a Tcl type
static Tcl_ObjType TornadoStringType = {
   "Tornado_String_Ptr",
   (Tcl_FreeInternalRepProc *)Free_String,
   (Tcl_DupInternalRepProc *) NULL,
   (Tcl_UpdateStringProc*)    Get_String,
   (Tcl_SetFromAnyProc*)      Put_String
};

/**------------------------------------------------------------------------------
 * This routine interface wtx gopher command and return a pointer
 * to a coopy of gopher string in order tcl to have an oportunity
 * to free it when needed.
 * @param tornadoId a valid connected handle on target
 * @param result    a valid object name where to store result
 * @param commannd  gopher command
 * @note formating is comming from WRS
 -------------------------------------------------------------------------------*/
PUBLIC void tornadoDirectGopher  (TORNADO_id* tornadoId
                 , JWRAP_varg *result, char *command) {
   WTX_GOPHER_TAPE * tape;
   Tcl_Obj         *liste;
   int	needSwap   = tornadoId->targetEndian != tornadoId->hostEndian;
   int	bufIx;
   int len;

   // request gopher on target
   tape = wtxGopherEval (tornadoId->wtxId, command);
   if (tape == NULL) goto errRead;

   // check result as result object in
   if (result->argc != 1) goto errSyntaxe;

   // allocate liste
   liste = Tcl_NewListObj (0,NULL);

   // process tape
    for (bufIx = 0; bufIx < tape->len;) {
	char valbuf [20];
	UINT8 type = tape->data [bufIx++];
	unsigned char *bufp = (unsigned char *) (tape->data + bufIx);

	switch (type)
	    {
	    case GOPHER_UINT32:
		{
		UINT32 rawVal = UNPACK_32 (bufp);
		len = sprintf (valbuf, "%#x", SWAB_32_IF (needSwap, rawVal));
		Tcl_ListObjAppendElement (NULL, liste, Tcl_NewStringObj (valbuf,len));
		bufIx += sizeof (UINT32);
		break;
		}
	    case GOPHER_UINT16:
		{
		UINT16 rawVal = UNPACK_16 (bufp);
		len = sprintf (valbuf, "%#x", SWAB_16_IF (needSwap, rawVal));
		Tcl_ListObjAppendElement (NULL, liste, Tcl_NewStringObj (valbuf,len));
		bufIx += sizeof (UINT16);
		break;
		}
	    case GOPHER_UINT8:
		{
		UINT8 rawVal = *bufp;
		sprintf (valbuf, "%#x", rawVal);
		Tcl_ListObjAppendElement (NULL, liste, Tcl_NewStringObj (valbuf,len));
		bufIx += sizeof (UINT8);
		break;
		}
	    case GOPHER_STRING:
	    {
		Tcl_ListObjAppendElement (NULL, liste
                        , Tcl_NewStringObj (tape->data + bufIx,-1));
		bufIx += strlen (tape->data + bufIx) + 1;
                break;
	    }

            // If you need float you will have to work sory !!!
            default: goto errFloat;
	}
   }

   wtxResultFree (tornadoId->wtxId, tape);

   // before returning affect list to user object
   if (NULL == Tcl_ObjSetVar2 (result->interp,result->argv[0],NULL
                      ,liste,TCL_LEAVE_ERR_MSG)) goto errSetVar;

   return;

errRead:
   jWrapPanic (NULL,"TornadoDirectGopher wtxGopherEval failled");

errFloat:
  jWrapPanic (NULL,"TornadoDirectGopher does not support float yet!\n");

errSetVar:
    jWrapPanic (NULL,"TornadoDirectGopher Could not set result in [%s]\n"
               , result->argv[0]->bytes);

errSyntaxe:
    jWrapPanic (NULL,"TornadoDirectGopher Return object missing or not valid\n");

}

/**------------------------------------------------------------------------------
 * This function can be used to assign names to list elements.
 * For example, the following call will set the variables a, b, and c in
 * the procedure scope with the values 10, 11, and 12, respectively:
 * Original function is a WRS internal non documented routine.
 *
 * @param  names Variables name we want to set
 * @param  value Value to affect to name
 * @note   If there is more names that value remainding are set to zero
 * @remark I optimized this routine for tcl8.x
 -------------------------------------------------------------------------------*/
PUBLIC void tornadoDirectVarsToValues  (JWRAP_varg *vars, JWRAP_varg *values) {
  int     ind;

    // We should not have more values than variable name
    if (vars->argc < values->argc) goto errSyntaxe;

    // Start to fill up variables with values
    for (ind = 0; ind < values->argc; ind ++) {
       if (NULL == Tcl_ObjSetVar2 (vars->interp,vars->argv[ind],NULL
                      ,values->argv[ind],TCL_LEAVE_ERR_MSG)) goto errSetVar;
    }

    // Remainder should be set with zero
    for (; ind  < vars->argc; ind++) {
         if (NULL == Tcl_ObjSetVar2 (vars->interp,vars->argv[ind],NULL
                      ,zero,TCL_LEAVE_ERR_MSG)) goto errSetVar;
    }

    return; // ------------------- OK --------------------

 errSyntaxe:
    jWrapPanic (vars->interp,"Too many value [%d] for only [%d] variables\n"
               ,values->argc, vars->argc);

 errSetVar:
    jWrapPanic (vars->interp,"Could not set var [%s]\n", vars->argv[ind]->bytes);
}

/**-----------------------------------------------------------
 ** this routine is the one used by jWrap.
 ** @param  tornadoId TORNADO handle
 ** @wtxCtx a valid wtx function handle
 ** @note   in simulation mode alway return string "simu"
 ** @remark we could optimize keeping track of last string
 ** function name in order not querying target server for
 ** symol adress when looping on a unique function name.
 **----------------------------------------------------------*/
PUBLIC void *tornadoDirectFuncCall (TORNADO_id* tornadoId
                , char* funcName, JWRAP_varg* varg) {
  WTX_CONTEXT_ID_T funcId;
  WTX_CONTEXT_DESC wtxCtx;
  Tcl_ObjType *tclType;
  Tcl_Obj     *element,*slot;
  void *result;
  int  len, ind, status;

  if (tornadoId== NULL)         goto errTornadoId;
  if (tornadoId->wtxId == NULL) goto errWtxId;
  if (varg->argc > 10)          goto errTooManyArg;

  // tornadoID can theorically change in one unique session (never tested!!!)
  tornadoInfo.tornadoId     = tornadoId;


  // Start setting function name
  memset (&wtxCtx, 0, sizeof (WTX_CONTEXT_DESC));
  wtxCtx.name  = funcName;

  // loop on each Argument and check
  for (ind=0; ind < varg->argc; ind++) {

    // we save slot type before llength change it
    tclType = varg->argv[ind]->typePtr;
    slot    = varg->argv[ind];

    // if object is a string or a list check for casting value
    if ((tclType == NULL) || (tclType == jWrapTypeList)) {
      status = Tcl_ListObjLength (varg->interp, slot, &len);

      if ((status == TCL_OK) && (len == 2)) {
        // does first element start with a --
        (void)Tcl_ListObjIndex (varg->interp, slot, 0, &element);
        if ((element->bytes != NULL) && (!strncmp (element->bytes,"--",2))) {

          // float are not supported by wtx
          if (!strcmp ("float" , &element->bytes[3])) goto errUnsupportedType;
          if (!strcmp ("double", &element->bytes[3])) goto errUnsupportedType;

	  // impose user not to user char*
          if ((!strncmp ("char", &element->bytes[2],4)) && (element->bytes[6] != '\0')) {
            goto errShouldBeString;
          }

          // process string as target string
          if (!strcmp ("string", &element->bytes[2])) {
	     Tcl_Free (element->bytes);
             jWrapStrDup (element, "--Tornado_String_Ptr");
          }

          // check type exist
          tclType = Tcl_GetObjType (&element->bytes[2]);
          if (tclType == NULL) goto errUnknowType;

          // get object from second element of list
          (void)Tcl_ListObjIndex (varg->interp, varg->argv[ind], 1, &slot);

          // Try to convert string to an int if not possible take it as a full string
          if (Tcl_ConvertToType (varg->interp,slot,tclType) != TCL_OK) goto errCastFailed;
        } else {
          // Try first to map to integer then to a string
          if (Tcl_ConvertToType (varg->interp,slot,jWrapTypeInt) != TCL_OK) {
             (void)Tcl_ConvertToType (varg->interp,slot,&TornadoStringType);
          }
        } // slot had two elements
      } else {
        // Try first to map to integer then to a string
        if (Tcl_ConvertToType (varg->interp,slot,jWrapTypeInt) != TCL_OK) {
           (void)Tcl_ConvertToType (varg->interp,slot,&TornadoStringType);
        }
      } // slot was a list
    } // end argv was passed typed to directcall routine

    // Now we can give internal rep to Tornado function call
    wtxCtx.args[ind] =(long) slot->internalRep.twoPtrValue.ptr1;
  }    // end for argv

  // fill up remainning arguement with zero
  for (; ind < 10; ind++) wtxCtx.args[ind] = 0;

  // spwan task and take exec function wtxCtx id
  result = tornadoExecFuncCall (tornadoId, &wtxCtx);

  return (result); // ------------------ OK ----------------


 errTooManyArg:
   jWrapPanic (NULL,"tornadoDirectFuncCall to many arguments %d>10\n"
              , varg->argc);

 errTornadoId:
   jWrapPanic (NULL,"tornadoDirectFuncCall TornadoId==NULL [Check calling syntaxe]!!!\n");

 errWtxId:
   jWrapPanic (NULL,"tornadoDirectFuncCall TornadoId->wtxId==NULL [not bind|connected]\n");

 errUnknowType:
   jWrapPanic (NULL,"tornadoDirectFuncCall Unknow type [%s]\n",&element->bytes[2]);

 errUnsupportedType:
   jWrapPanic (NULL,"tornadoDirectFuncCall WTX Unsupported type [%s]\n",&element->bytes[2]);

 errShouldBeString:
   jWrapPanic (NULL,"tornadoDirectFuncCall unsupported [%s] thinking [--string] ???\n"
                   ,element->bytes);
 errCastFailed:
   jWrapPanic (NULL,"tornadoDirectFuncCall cannot cast into [%s] into [%s] ???\n"
                   ,tclType->name, slot->bytes);

   return NULL;
}  //end tornadoDirectFuncCall

/** ------------------------------------------------------------
 *   Register Tornado String type and build zero static object
 * -------------------------------------------------------------*/
RESTRICTED void tornadoDirectInit (Tcl_Interp * interp) {

   // Register Tornado String now
   Tcl_RegisterObjType (&TornadoStringType);

   // We dont need a full tornado info because DirectCall is not a real jWrap module
   tornadoInfo.magic         = TORNADO_INFO_MAGIC;
   tornadoInfo.wtxCtx        = NULL;
   tornadoInfo.nameCmd       = NULL;
   tornadoInfo.stringType    = &TornadoStringType;
   tornadoInfo.tornadoFree   = NULL;

   // pre build a zero object for test
   zero = Tcl_NewIntObj (0);

}



