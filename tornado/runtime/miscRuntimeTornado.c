/**------------------------------------------------------------------------------
 *      Copyright(c) 1996-99 FRIDU a Free Software Company Philipppe Le Foll
 *
 * File         : miscRuntimeTroando.c misc function for Tornado componant
 * Projet       : jWrap
 * SubModule    : WTX VxWorks Tornado Interface
 * Auteur       : Fulup Le Foll (Fulup@fridu.bzh)
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/miscRuntimeTornado.c,v $
 *
 * Modificatin History
 * -------------------
 * 02c,05mar99,Fulup,added memblock create
 * 02a,16feb99 Fulup,externalized WTX module
 * 01a,02jun98 Fulup,written
 * ----------------------------------------------------------------------------
 */

/** --------------------------------------------------------------
 ** provides control handler and custom Tcl exit function in order
 ** cleanning target resources before killing tclsh 
 **---------------------------------------------------------------*/
#include <wtx.h>
#include <signal.h>

#include "libRuntimeTornado.h"

#include <string.h>

typedef  union {
    char unit[4];
    int  slot[2];
    long number;
} Endian_check;


LOCAL  void *oldIntFunc;
static TORNADO_endian endian = ENDIAN_IS_UNKNOW;

/** --------------------------------------------------------------
 ** this routine check endian type a program startup time
 ** it save endian type in a static value, it wont work
 ** in 64 bit environement
 ** -------------------------------------------------------------*/
PUBLIC TORNADO_endian checkEndian () {
  Endian_check value;

  value.number = 1;

  if (value.slot[0] == 1)   return ENDIAN_IS_LITTLE;
  if (value.slot[1] == 1)   return ENDIAN_IS_BIG;
  return ENDIAN_IS_UNKNOW;
}

/** ---------------------------------------------------------------------
 **  MemBlock build a memory according to a specific patern
 **  It is used by shell proc
 **  @param flag specify how to process value
 **  @value a vlaid string according to flag
 ** ---------------------------------------------------------------------*/
PUBLIC void* tornadoMemBlock (TORNADO_memflag flag, char *value) {
  void         *memBlock;
  Endian_check source,dest; 
  int          status;

  // if endian type unknow check it now
  if (endian == ENDIAN_IS_UNKNOW) {
    endian = checkEndian();
  }
  

  switch (flag) {
   case TORNADO_MEM_HEXA:
       status = sscanf (value, "0x%x", (unsigned int*) &memBlock);
       if (status != 1) goto invalidHexa;
       break;
   case TORNADO_MEM_STRING:
       memBlock = (void*) strdup (value);
       break;
   case TORNADO_MEM_BIG_ENDIAN:
       status = sscanf (value, "%d", (int*) &source);
       if (status != 1) goto invalidNumber;
      
       if (endian == ENDIAN_IS_BIG) {
         memBlock = (void*) source.number;
       } else {
         dest.unit [0] =   source.unit [3];        
         dest.unit [1] =   source.unit [2];        
         dest.unit [2] =   source.unit [3];        
         dest.unit [3] =   source.unit [0];        
         memBlock = (void*) dest.number;
       }

    break;   
   case TORNADO_MEM_LITTLE_ENDIAN:
       status = sscanf (value, "%d", (int*) &source);
       if (status != 1) goto invalidNumber;

       if (endian == ENDIAN_IS_LITTLE) {
         memBlock = (void*) source.number;
       } else {
         dest.unit [0] =   source.unit [3];        
         dest.unit [1] =   source.unit [2];        
         dest.unit [2] =   source.unit [3];        
         dest.unit [3] =   source.unit [0];        
         memBlock = (void*) dest.number;
       }
    break;

   case TORNADO_MEM_UNKNOWN_ENDIAN:
       status = sscanf (value, "%d", (int*) &memBlock);
       if (status != 1) goto invalidNumber;
    break;

  }
  return memBlock; // --------- OK ------------

invalidHexa:
  jWrapPanic (NULL,"Invalid (%s) haxa number\n", value);
invalidNumber:
  jWrapPanic (NULL,"Invalid (%s) integer number\n", value);
  
  return NULL; // for gcc not to complain
}

/** ---------------------------------------------------------------------
 **  Control-C handler trap all sig_int signal and fre all valid
 **  TORNADO handles before kill tclsh.
 ** @note does not work under WIN32
 ** ---------------------------------------------------------------------*/
LOCAL void tornadoCtrlC (int ind) {
  TORNADO_id *tornadoId;
  
   jWrapLog (1,"tornadoCtrlC emergency Shutdown\n");

   for (tornadoId = tornadoIdHead;  tornadoId != NULL; tornadoId = (TORNADO_id*)tornadoId->next) {
      tornadoEnd (tornadoId);       
   }
   exit (1);
}
/**-----------------------------------------------------------------------
 ** We remap TCL exit in order producing a clean exit and free target
 ** resources each time user make a tcl syntaxe error, or type in CTRL-D
 ** in interative mode. 
 ** @note input paramters are ignored
 ** @return function should never return, if a tornadoEnd call fail result
 ** is unpredicable, probabelly a core dump !
 **-----------------------------------------------------------------------*/
LOCAL int tornadoExit (ClientData cld, Tcl_Interp *interp
			    , int objc, Tcl_Obj *CONST objv[])
{
  TORNADO_id *tornadoId;

  jWrapLog (1,"tornadoExit Closing Tgt Connection\n");
  for (tornadoId = tornadoIdHead;  tornadoId != NULL; tornadoId = (TORNADO_id*)tornadoId->next) {
    tornadoEnd (tornadoId);       
  }
  jWrapLog (1,"tornadoExit Tornado Wtx Ended\n");
  exit (0);  

  return JWRAP_IMPOSSIBLE;
}

/** ---------------------------------------------------------------------
 ** Validate Ctrl-C handler, and map tornadoExit function call on tcl exit
 ** command. 
 * ---------------------------------------------------------------------*/
RESTRICTED void tornadoMiscInit (Tcl_Interp *interp) {

#ifndef _WINDOWS_ 
 // Warning: Windows does not handle properly ctrl-C signal check for CV manual
 signal (SIGINT ,tornadoCtrlC);
#endif

 tornadoDirectInit (interp); 
 
 // Overload Tcl exit command
 Tcl_CreateObjCommand (interp,"exit", tornadoExit
        , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
}
