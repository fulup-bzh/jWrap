/*
 * Copyright(c) 1997-99 FRIDU a Free Software Company
 *
 * File   	: libRuntimeTornado.h Interface for VxWorks/Tornado test lib
 * Projet       : jWrap
 * SubModule    : WTX VxWorks Tornado Interface
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 *
 * Last:
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:29 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/Include/libRuntimeTornado.h,v $
 *
 * Modification History
 * -------------------
 * 1.3  16feb99, Fulup externalized WTX module
 * 1.2  06may98, Fulup adapted to jWrap
 * 1.1  13mar96, Fulup Writen
 *
 *
 */

#ifndef _libRuntimeTornado_
#define _libRuntimeTornado_

#ifndef JWRAP
# include <libRuntimeJwrap.h>
# include <host.h>
# include <wtx.h>
#endif

typedef enum tornado_endian {
  ENDIAN_IS_BIG,
  ENDIAN_IS_LITTLE,

  ENDIAN_IS_UNKNOW
} TORNADO_endian;

typedef enum tornado_bindflag {
  BIND_LAZY = 0,
  BIND_NOW  = 1,

  BIND_UNKNOWN = -1
} TORNADO_bindflag;

typedef enum tornado_memflag {
  TORNADO_MEM_HEXA,
  TORNADO_MEM_STRING,
  TORNADO_MEM_BIG_ENDIAN,
  TORNADO_MEM_LITTLE_ENDIAN,

  TORNADO_MEM_UNKNOWN_ENDIAN
} TORNADO_memflag;

typedef enum tornado_magic {
   TORNADO_MAGIC_ID     = 960513,
   TORNADO_MAGIC_CALL   = 960518,
   TORNADO_CTX_T_MAGIC  = 960519,
   TORNADO_CTX_ID_MAGIC = 960523,
   TORNADO_INFO_MAGIC   = 980602,

   TORNADO_MAGIC_UNKNOW = -2
} TORNADO_magics;

/** Function waiting return status is expressed in 100000us tic */
#define TORNADO_DEFAULT_HOP_TIMEOUT 10
#define TORNADO_OK                   0
#define TORNADO_ERROR               -1


/** -----------------------------------------------------
 ** Event return type
 ** -----------------------------------------------------*/
typedef enum TORNADOevt {
  TORNADO_EVT_TYPE        = 0,
  TORNADO_EVT_FUNC_ID     = 1,
  TORNADO_EVT_FUNC_RET    = 2,
  TORNADO_EVT_FUNC_STATUS = 3,

  TORNADO_EVT_UNKNOW      = -2
} TORNADO_evt;

/** -----------------------------------------------------------------
 ** TORNADO_ID hold stdin/out vio redictio and tool to target ID
 ** is a super set of wtx id
 ** -----------------------------------------------------------------*/
typedef struct TORNADOid {
  /** Magic number */
  TORNADO_magics      magic;

  /** WTX Tornado tool ID computed on host */
  HWTX            wtxId;
  /** target Internet name Mandatory */
  char           *targetName;
  /** tool name facultavice */
  char           *toolName;
  /** vio Target device name computed on target */
  INT32          vIoNum;
  /** Target file handle for input vio */
  INT32          vOut;
  /** Target file handle for output vio */
  INT32          vIn;

  /** Host endian type */
  TORNADO_endian hostEndian;

  /** target endian type */
  TORNADO_endian targetEndian;

  /** Next TORNADOID set to void for jWrap */
  void*          next;

} TORNADO_id;

/** -------------------------------------------------------------------------
 ** Event return structur hole WTX event plus a pre-processed view of event
 ** --------------------------------------------------------------------------*/
typedef struct TORNADOevtRet {
  /** Number of slot in event (should be four with function return status) */
  int              argc;
  /** Event is a Tcl List (even in C!) argv hold a splited list of Tcl string */
  char             *argv[4];
  /** Function Context ID allow to fuinf which functin is returning */
  WTX_CONTEXT_ID_T funcId;
  /** Pointer on original WTX ID used for freeing structure */
  WTX_EVENT_DESC   *id;
  /** Event number allows to classified event [return, error, ...] */
  int              evtNum;
  /** Rreverse Link to tool ID */
  TORNADO_id           *tornadoId;
} TORNADO_evtRet;


/** -----------------------------------------------------
 ** Wpr module info will be added to clientData jWrap
 ** module handle.
 ** -----------------------------------------------------*/
typedef struct TORNADOinfos {
  TORNADO_magics       magic;
  TORNADO_id           *tornadoId;
  WTX_CONTEXT_DESC *wtxCtx;
  char             **nameCmd;
  Tcl_ObjType      *stringType;
  void             *tornadoFree;
} TORNADO_infos;


#ifndef JWRAP_DOC
#include "libRuntimeTornado.i"
#endif

#endif




