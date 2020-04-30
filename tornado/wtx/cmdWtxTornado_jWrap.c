
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: cmdWtxTornado_jWrap.c Tornado VxWorks WTX interface with target server
 *   Date: Mon Mar 22 10:31:50 1999


 *   jWrap --cc2jTcl cmdWtxTornado
 *
 *   WARNING: Except if you really know what you are doing
 *   you should not edit this file by hand.
 *
 *   In order finding jWrap check: http://www.fridu.bzh
 + ------------------------------------------------------------ */

#ifndef EASYC_PROTO_ONLY
#define EASYC_PROTO_ONLY
#endif
#define JWRAP_CC2JTCL

#include "libRuntimeJwrap.h"
#include "./headerWtxTornado.h"

#ifndef Wtx_CUSTOM_STAMP
 #ifdef FRIDU
 #define Wtx_CUSTOM_STAMP &vStamp_libWtx[12]
 #else
 #define Wtx_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [174];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_Wtx                = 0,
   JTYPE_wtx_core                  = 1,
   JTYPE_UINT32                    = 2,
   JTYPE_WTX_ERROR_T               = 3,
   JTYPE_wtx_desc                  = 4,
   JTYPE_char_Ptr                  = 5,
   JTYPE_wtx_desc_q                = 6,
   JTYPE_wtx_desc_q_Ptr            = 7,
   JTYPE_wtx_value                 = 8,
   JTYPE_WTX_VALUE_T               = 9,
   JTYPE_Union_Wtx_0               = 10,
   JTYPE_wtx_msg_result            = 11,
   JTYPE_WTX_CORE                  = 12,
   JTYPE_WTX_VALUE                 = 13,
   JTYPE_wtx_msg_param             = 14,
   JTYPE_wtx_mem_region            = 15,
   JTYPE_TGT_ADDR_T                = 16,
   JTYPE_wtx_rt_info               = 17,
   JTYPE_BOOL32                    = 18,
   JTYPE_WTX_MEM_REGION_Ptr        = 19,
   JTYPE_wtx_agent_info            = 20,
   JTYPE_wtx_tgt_info              = 21,
   JTYPE_WTX_AGENT_INFO            = 22,
   JTYPE_WTX_RT_INFO               = 23,
   JTYPE_wtx_tgt_link_desc         = 24,
   JTYPE_wtx_tool_desc             = 25,
   JTYPE_void_Ptr                  = 26,
   JTYPE_wtx_tool_desc_Ptr         = 27,
   JTYPE_wtx_msg_ts_info           = 28,
   JTYPE_WTX_TGT_LINK_DESC         = 29,
   JTYPE_WTX_TGT_INFO              = 30,
   JTYPE_WTX_TOOL_DESC_Ptr         = 31,
   JTYPE_wtx_msg_ts_lock           = 32,
   JTYPE_wtx_msg_ts_unlock         = 33,
   JTYPE_wtx_msg_tool_desc         = 34,
   JTYPE_WTX_TOOL_DESC             = 35,
   JTYPE_wtx_msg_tool_id           = 36,
   JTYPE_wtx_msg_kill_desc         = 37,
   JTYPE_wtx_symbol                = 38,
   JTYPE_UINT8                     = 39,
   JTYPE_UINT16                    = 40,
   JTYPE_wtx_symbol_Ptr            = 41,
   JTYPE_wtx_msg_symbol_desc       = 42,
   JTYPE_WTX_SYMBOL                = 43,
   JTYPE_wtx_sym_list              = 44,
   JTYPE_WTX_SYMBOL_Ptr            = 45,
   JTYPE_wtx_msg_sym_list          = 46,
   JTYPE_WTX_SYM_LIST              = 47,
   JTYPE_wtx_msg_open_desc         = 48,
   JTYPE_WTX_OPEN_FLAG             = 49,
   JTYPE_INT32                     = 50,
   JTYPE_wtx_msg_vio_ctl_desc      = 51,
   JTYPE_wtx_msg_vio_copy_desc     = 52,
   JTYPE_wtx_vio_file_desc         = 53,
   JTYPE_wtx_vio_file_desc_Ptr     = 54,
   JTYPE_wtx_msg_vio_file_list     = 55,
   JTYPE_WTX_VIO_FILE_DESC_Ptr     = 56,
   JTYPE_ld_m_section              = 57,
   JTYPE_wtx_msg_ld_m_file_desc    = 58,
   JTYPE_LD_M_SECTION_Ptr          = 59,
   JTYPE_wtx_msg_module_list       = 60,
   JTYPE_UINT32_Ptr                = 61,
   JTYPE_obj_segment               = 62,
   JTYPE_wtx_msg_module_info       = 63,
   JTYPE_int                       = 64,
   JTYPE_OBJ_SEGMENT_Ptr           = 65,
   JTYPE_wtx_msg_mod_name_or_id    = 66,
   JTYPE_wtx_sym_tbl_info          = 67,
   JTYPE_wtx_msg_sym_tbl_info      = 68,
   JTYPE_wtx_msg_sym_match_desc    = 69,
   JTYPE_Union_Wtx_1               = 70,
   JTYPE_wtx_event_desc            = 71,
   JTYPE_wtx_msg_event_desc        = 72,
   JTYPE_WTX_EVENT_DESC            = 73,
   JTYPE_wtx_msg_event_reg_desc    = 74,
   JTYPE_wtx_wdb_service_desc      = 75,
   JTYPE_wtx_wtx_service_desc      = 76,
   JTYPE_wtx_msg_service_desc      = 77,
   JTYPE_WTX_WTX_SERVICE_DESC_Ptr  = 78,
   JTYPE_WTX_WDB_SERVICE_DESC_Ptr  = 79,
   JTYPE_wtx_msg_service_list      = 80,
   JTYPE_wtx_console_desc          = 81,
   JTYPE_wtx_msg_console_desc      = 82,
   JTYPE_WTX_CONSOLE_DESC          = 83,
   JTYPE_wtx_msg_mem_info          = 84,
   JTYPE_wtx_mem_xfer              = 85,
   JTYPE_wtx_msg_mem_xfer_desc     = 86,
   JTYPE_WTX_MEM_XFER              = 87,
   JTYPE_wtx_event                 = 88,
   JTYPE_WTX_EVENT_TYPE            = 89,
   JTYPE_TGT_ARG_T                 = 90,
   JTYPE_wtx_context               = 91,
   JTYPE_WTX_CONTEXT_TYPE          = 92,
   JTYPE_WTX_CONTEXT_ID_T          = 93,
   JTYPE_wtx_action                = 94,
   JTYPE_WTX_ACTION_TYPE           = 95,
   JTYPE_wtx_msg_context           = 96,
   JTYPE_wtx_evtpt                 = 97,
   JTYPE_WTX_EVENT                 = 98,
   JTYPE_WTX_CONTEXT               = 99,
   JTYPE_WTX_ACTION                = 100,
   JTYPE_wtx_msg_evtpt_desc        = 101,
   JTYPE_WTX_EVTPT                 = 102,
   JTYPE_wtx_msg_evtpt_list        = 103,
   JTYPE_WTX_EVTPT_Ptr             = 104,
   JTYPE_wtx_msg_reg_write         = 105,
   JTYPE_WTX_REG_SET_TYPE          = 106,
   JTYPE_WTX_MSG_REG_READ          = 107,
   JTYPE_WTX_MEM_REGION            = 108,
   JTYPE_wtx_msg_mem_block_desc    = 109,
   JTYPE_wtx_msg_mem_read_desc     = 110,
   JTYPE_wtx_msg_mem_copy_desc     = 111,
   JTYPE_wtx_msg_mem_scan_desc     = 112,
   JTYPE_wtx_msg_mem_move_desc     = 113,
   JTYPE_wtx_msg_mem_set_desc      = 114,
   JTYPE_wtx_msg_context_desc      = 115,
   JTYPE_WTX_RETURN_TYPE           = 116,
   JTYPE_wtx_msg_context_step_desc = 117,
   JTYPE_wtx_gopher_tape           = 118,
   JTYPE_WTX_MSG_GOPHER_TAPE       = 119,
   JTYPE_WTX_GOPHER_TAPE           = 120,
   JTYPE_wtx_msg_wtxregd_pattern   = 121,
   JTYPE_wtx_svr_desc              = 122,
   JTYPE_wtx_msg_svr_desc          = 123,
   JTYPE_WTX_SVR_DESC              = 124,
   JTYPE_wtx_svr_desc_q            = 125,
   JTYPE_wtx_svr_desc_q_Ptr        = 126,
   JTYPE_wtx_msg_svr_desc_q        = 127,
   JTYPE_WTX_SVR_DESC_Q            = 128,
   JTYPE_wtx_context_desc          = 129,
   JTYPE_wtx_evtpt_list            = 130,
   JTYPE_wtx_ld_m_file_desc        = 131,
   JTYPE_wtx_mem_info              = 132,
   JTYPE_wtx_module_info           = 133,
   JTYPE_wtx_module_list           = 134,
   JTYPE_wtx_ts_info               = 135,
   JTYPE_INT8                      = 136,
   JTYPE_INT16                     = 137,
   JTYPE_double                    = 138,
   JTYPE_wtx_error_t               = 139,
   JTYPE_wtx_event_type            = 140,
   JTYPE_wtx_context_type          = 141,
   JTYPE_wtx_action_type           = 142,
   JTYPE_wtx_return_type           = 143,
   JTYPE_wtx_reg_set_type          = 144,
   JTYPE_wtx_agent_mode_type       = 145,
   JTYPE_wtx_open_flag             = 146,
   JTYPE_wtx_value_t               = 147,
   JTYPE_wtx_endian_t              = 148,
   JTYPE_STATUS                    = 149,
   JTYPE_HWTX                      = 150,
   JTYPE_FUNCPTR                   = 151,
   JTYPE_WTX_DESC_Ptr              = 152,
   JTYPE_WTX_DESC_Q_Ptr            = 153,
   JTYPE_HWTX_Ptr                  = 154,
   JTYPE_WTX_AGENT_MODE_TYPE       = 155,
   JTYPE_void_Ptr_Ptr              = 156,
   JTYPE_INT32_Ptr                 = 157,
   JTYPE_WTX_CONTEXT_DESC_Ptr      = 158,
   JTYPE_WTX_HANDLER_T             = 159,
   JTYPE_WTX_HANDLER_FUNC          = 160,
   JTYPE_WTX_EVENT_DESC_Ptr        = 161,
   JTYPE_WTX_EVTPT_LIST_Ptr        = 162,
   JTYPE_WTX_GOPHER_TAPE_Ptr       = 163,
   JTYPE_WTX_MEM_INFO_Ptr          = 164,
   JTYPE_TGT_ADDR_T_Ptr            = 165,
   JTYPE_WTX_MODULE_INFO_Ptr       = 166,
   JTYPE_WTX_MODULE_LIST_Ptr       = 167,
   JTYPE_WTX_LD_M_FILE_DESC_Ptr    = 168,
   JTYPE_WTX_SYM_LIST_Ptr          = 169,
   JTYPE_WTX_SYM_TBL_INFO_Ptr      = 170,
   JTYPE_WTX_ENDIAN_T              = 171,
   JTYPE_WTX_TS_INFO_Ptr           = 172,
   JTYPE_WTX_VIO_FILE_DESC_Ptr_Ptr = 173
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "STATUS = wtxEach (HWTX hWtx, const char * namePat, const char * typePat, const char * keyPat, FUNCPTR routine, void * arg);",
   "WTX_DESC* = wtxInfo (HWTX hWtx, const char * name);",
   "WTX_DESC_Q* = wtxInfoQ (HWTX hWtx, const char * namePat, const char * typePat, const char * keyPat);",
   "STATUS = wtxInitialize (HWTX * phWtx);",
   "STATUS = wtxProbe (HWTX hWtx);",
   "WTX_DESC* = wtxRegister (HWTX hWtx, const char * name, const char * type, const char * key);",
   "STATUS = wtxTerminate (HWTX hWtx);",
   "STATUS = wtxTimeoutSet (HWTX hWtx, UINT32 msec);",
   "STATUS = wtxTimeoutGet (HWTX hWtx, UINT32 * pMsec);",
   "STATUS = wtxUnregister (HWTX hWtx, const char * name);",
   "STATUS = wtxAgentModeSet (HWTX hWtx, WTX_AGENT_MODE_TYPE agentMode);",
   "WTX_AGENT_MODE_TYPE = wtxAgentModeGet (HWTX hWtx);",
   "UINT32 = wtxBreakpointAdd (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId, TGT_ADDR_T tgtAddr);",
   "STATUS = wtxClientDataGet (HWTX hWtx, void ** ppClientData);",
   "STATUS = wtxClientDataSet (HWTX hWtx, void * pClientData);",
   "INT32 = wtxConsoleCreate (HWTX hWtx, const char * name, const char * display, INT32 * fdIn, INT32 * fdOut);",
   "STATUS = wtxConsoleKill (HWTX hWtx, INT32 consoleId);",
   "STATUS = wtxContextCont (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId);",
   "WTX_CONTEXT_ID_T = wtxContextCreate (HWTX hWtx, WTX_CONTEXT_DESC * pContextDesc);",
   "UINT32 = wtxContextExitNotifyAdd (HWTX hWTx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T NoName);",
   "STATUS = wtxContextKill (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId);",
   "STATUS = wtxContextResume (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId);",
   "STATUS = wtxContextStep (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId, TGT_ADDR_T stepStart, TGT_ADDR_T stepEnd);",
   "STATUS = wtxContextSuspend (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId);",
   "STATUS = wtxErrClear (HWTX hWtx);",
   "WTX_ERROR_T = wtxErrGet (HWTX hWtx);",
   "STATUS = wtxErrSet (HWTX hWtx, UINT32 errCode);",
   "const char* = wtxErrMsgGet (HWTX hWtx);",
   "const char* = wtxErrToMsg (HWTX hWtx, WTX_ERROR_T errCode);",
   "STATUS = wtxErrDispatch (HWTX hWtx, WTX_ERROR_T errCode);",
   "BOOL32 = wtxErrExceptionFunc (HWTX hWtx, void * pClientData, void * pCallData);",
   "WTX_HANDLER_T = wtxErrHandlerAdd (HWTX hWtx, WTX_HANDLER_FUNC pFunc, void * pClientData);",
   "STATUS = wtxErrHandlerRemove (HWTX hWtx, WTX_HANDLER_T pHandler);",
   "STATUS = wtxEventAdd (HWTX hWtx, const char * event, UINT32 addlDataLen, const void * pAddlData);",
   "WTX_EVENT_DESC* = wtxEventGet (HWTX hWtx);",
   "STATUS = wtxEventpointDelete (HWTX hWtx, UINT32 evtptId);",
   "WTX_EVTPT_LIST* = wtxEventpointList (HWTX hWTx);",
   "STATUS = wtxFileClose (HWTX hWtx, INT32 fileDescriptor);",
   "INT32 = wtxFileOpen (HWTX hWtx, const char * fileName, WTX_OPEN_FLAG flags, INT32 mode, INT32 channel);",
   "WTX_CONTEXT_ID_T = wtxFuncCall (HWTX hWtx, WTX_CONTEXT_DESC * pContextDesc);",
   "STATUS = wtxDirectCall (HWTX hWtx, TGT_ADDR_T entry, void * pRetVal, TGT_ARG_T arg0, TGT_ARG_T arg1, TGT_ARG_T arg2, TGT_ARG_T arg3, TGT_ARG_T arg4, TGT_ARG_T arg5, TGT_ARG_T arg6, TGT_ARG_T arg7, TGT_ARG_T arg8, TGT_ARG_T arg9);",
   "WTX_GOPHER_TAPE* = wtxGopherEval (HWTX hWtx, const char * inputString);",
   "WTX_MEM_INFO* = wtxMemInfoGet (HWTX hWtx);",
   "STATUS = wtxMemAddToPool (HWTX hWtx, TGT_ADDR_T address, UINT32 size);",
   "TGT_ADDR_T = wtxMemAlign (HWTX hWtx, TGT_ADDR_T alignment, UINT32 numBytes);",
   "TGT_ADDR_T = wtxMemAlloc (HWTX hWtx, UINT32 numBytes);",
   "UINT32 = wtxMemChecksum (HWTX hWtx, TGT_ADDR_T startAddr, UINT32 numBytes);",
   "STATUS = wtxMemFree (HWTX hWtx, TGT_ADDR_T address);",
   "STATUS = wtxMemMove (HWTX hWtx, TGT_ADDR_T srcAddr, TGT_ADDR_T destAddr, UINT32 numBytes);",
   "UINT32 = wtxMemRead (HWTX hWtx, TGT_ADDR_T fromAddr, void * toAddr, UINT32 numBytes);",
   "TGT_ADDR_T = wtxMemRealloc (HWTX hWtx, TGT_ADDR_T address, UINT32 numBytes);",
   "UINT32 = wtxMemSet (HWTX hWtx, TGT_ADDR_T addr, UINT32 numBytes, UINT32 val);",
   "STATUS = wtxMemScan (HWTX hWTx, BOOL32 match, TGT_ADDR_T startAddr, TGT_ADDR_T endAddr, UINT32 numBytes, void * pattern, TGT_ADDR_T * pResult);",
   "UINT32 = wtxMemWrite (HWTX hWtx, void * fromAddr, TGT_ADDR_T toAddr, UINT32 numBytes);",
   "char* = wtxObjModuleFindName (HWTX hWtx, UINT32 modId);",
   "UINT32 = wtxObjModuleFindId (HWTX hWtx, const char * name);",
   "WTX_MODULE_INFO* = wtxObjModuleInfoGet (HWTX hWtx, UINT32 modId);",
   "WTX_MODULE_LIST* = wtxObjModuleList (HWTX hWtx);",
   "WTX_LD_M_FILE_DESC* = wtxObjModuleLoad (HWTX hWtx, WTX_LD_M_FILE_DESC * pFileDesc);",
   "STATUS = wtxObjModuleUnload (HWTX hWtx, UINT32 modId);",
   "STATUS = wtxRegisterForEvent (HWTX hWtx, const char * regExp);",
   "STATUS = wtxRegsGet (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId, WTX_REG_SET_TYPE regSet, UINT32 firstByte, UINT32 numBytes, void * regMemory);",
   "STATUS = wtxRegsSet (HWTX hWtx, WTX_CONTEXT_TYPE contextType, WTX_CONTEXT_ID_T contextId, WTX_REG_SET_TYPE regSet, UINT32 firstByte, UINT32 numBytes, void * regMemory);",
   "STATUS = wtxResultFree (HWTX hWtx, void * pResult);",
   "STATUS = wtxServiceAdd (HWTX hWtx, UINT32 * wtxSvcNum, UINT32 wdbSvcNum, char * wdbName, char * wdbObjFile, char * wdbInitRtn, char * wtxObjFile, char * wtxName, char * wtxInProcName, char * wtxOutProcName);",
   "TGT_ADDR_T = wtxStrToTgtAddr (HWTX hWtx, const char * NoName);",
   "INT32 = wtxStrToInt32 (HWTX hWtx, const char * NoName);",
   "WTX_CONTEXT_ID_T = wtxStrToContextId (HWTX hWtx, const char * NoName);",
   "WTX_CONTEXT_TYPE = wtxStrToContextType (HWTX hWtx, const char * NoName);",
   "WTX_EVENT_TYPE = wtxStrToEventType (HWTX hWtx, const char * NoName);",
   "STATUS = wtxSymAdd (HWTX hWtx, const char * wtxsymName, TGT_ADDR_T symValue, UINT8 symType);",
   "WTX_SYMBOL* = wtxSymFind (HWTX hWtx, const char * wtxsymName, TGT_ADDR_T symValue, BOOL32 exactName, UINT8 symType, UINT8 typeMask);",
   "WTX_SYM_LIST* = wtxSymListGet (HWTX hWtx, const char * string, const char * moduleNameOrId, TGT_ADDR_T value, BOOL32 listUnknown);",
   "STATUS = wtxSymRemove (HWTX hWtx, const char * wtxsymName, UINT8 symType);",
   "WTX_SYM_TBL_INFO* = wtxSymTblInfoGet (HWTX hWtx);",
   "UINT32 = wtxTargetRtTypeGet (HWTX hWtx);",
   "const char* = wtxTargetRtVersionGet (HWTX hWtx);",
   "UINT32 = wtxTargetCpuTypeGet (HWTX hWtx);",
   "BOOL32 = wtxTargetHasFppGet (HWTX hWtx);",
   "WTX_ENDIAN_T = wtxTargetEndianGet (HWTX hWtx);",
   "const char* = wtxTargetBootlineGet (HWTX hWtx);",
   "const char* = wtxTargetBspNameGet (HWTX hWtx);",
   "STATUS = wtxTargetReset (HWTX hWtx);",
   "STATUS = wtxTargetAttach (HWTX hWtx);",
   "STATUS = wtxToolAttach (HWTX hWtx, const char * targetName, const char * toolName);",
   "char* = wtxToolNameGet (HWTX hWtx);",
   "BOOL32 = wtxToolConnected (HWTX hWtx);",
   "STATUS = wtxToolDetach (HWTX hWtx);",
   "WTX_TS_INFO* = wtxTsInfoGet (HWTX hWtx);",
   "STATUS = wtxTsKill (HWTX hWtx);",
   "STATUS = wtxTsLock (HWTX hWtx);",
   "const char* = wtxTsNameGet (HWTX hWtx);",
   "STATUS = wtxTsRestart (HWTX hWtx);",
   "STATUS = wtxTsUnlock (HWTX hWtx);",
   "BOOL32 = wtxVerify (HWTX hWtx);",
   "INT32 = wtxVioChanGet (HWTX hWtx);",
   "STATUS = wtxVioChanRelease (HWTX hWtx, INT32 channel);",
   "STATUS = wtxVioCtl (HWTX hWtx, INT32 channel, UINT32 request, UINT32 arg);",
   "WTX_VIO_FILE_DESC** = wtxVioFileList (HWTX hWtx);",
   "UINT32 = wtxVioWrite (HWTX hWtx, INT32 channel, void * pData, UINT32 numBytes);",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_Wtx;
 static char *Define_Wtx_slotNames [] = {
   "__INCwtxh",
   "MC68000",
   "MC68010",
   "MC68020",
   "MC68030",
   "MC68040",
   "MC68LC040",
   "MC68060",
   "CPU32",
   "MC680X0",
   "SPARC",
   "SPARClite",
   "I960",
   "I960CA",
   "I960KA",
   "I960KB",
   "I960JX",
   "I960HX",
   "TRON",
   "G100",
   "G200",
   "MIPS",
   "R3000",
   "R33000",
   "R33020",
   "R4000",
   "CW4000",
   "R4650",
   "AM29XXX",
   "AM29030",
   "AM29200",
   "AM29035",
   "SIMSPARCSUNOS",
   "SIMHPPA",
   "I80X86",
   "I80386",
   "I80486",
   "PPC",
   "PPC601",
   "PPC602",
   "PPC603",
   "PPC604",
   "PPC403",
   "PPC505",
   "PPC860",
   "SIMSPARCSOLARIS",
   "BIG_ENDIAN",
   "LITTLE_ENDIAN",
   "_ALLOC_ALIGN_SIZE",
   "NULL",
   "FALSE",
   "TRUE",
   "STD_IN",
   "STD_OUT",
   "STD_ERR",
   "OK",
   "WTX_OK",
   "__INCwtxerrh",
   "WTX_ERR_NONE",
   "WTXERR_BASE_NUM",
   "WTX_MAX_SYM_CNT",
   "WTX_MAX_EVTPT_CNT",
   "WTX_MAX_MODULE_CNT",
   "WTX_MAX_SERVICE_CNT",
   "WTX_MAX_ARG_CNT",
   "WTX_MAX_SYM_TBL_CNT",
   "WTX_MAX_VIO_DATA",
   "WTX_MAX_PATTERN_LEN",
   "WTX_MAX_FILENAME_LEN",
   "WTX_MAX_OBJ_SEG_CNT",
   "WTX_MAX_SECTION_CNT",
   "WTX_MAX_WDB_SVC_CNT",
   "WTX_CTL_VIO_REDIRECT",
   "WTX_OBJ_KILL_DESTROY",
   "WTX_OBJ_KILL_RESTART",
   "WTX_TOOL_ATTACH",
   "WTX_TOOL_DETACH",
   "WTX_TS_INFO_GET",
   "WTX_TARGET_RESET",
   "WTX_TS_LOCK",
   "WTX_TS_UNLOCK",
   "WTX_TARGET_ATTACH",
   "WTX_CONTEXT_CREATE",
   "WTX_CONTEXT_KILL",
   "WTX_CONTEXT_SUSPEND",
   "WTX_CONTEXT_CONT",
   "WTX_CONTEXT_RESUME",
   "WTX_CONTEXT_STEP",
   "WTX_EVENTPOINT_ADD",
   "WTX_EVENTPOINT_DELETE",
   "WTX_EVENTPOINT_LIST",
   "WTX_MEM_CHECKSUM",
   "WTX_MEM_READ",
   "WTX_MEM_WRITE",
   "WTX_MEM_SET",
   "WTX_MEM_SCAN",
   "WTX_MEM_MOVE",
   "WTX_MEM_ALLOC",
   "WTX_MEM_FREE",
   "WTX_MEM_INFO_GET",
   "WTX_MEM_ALIGN",
   "WTX_MEM_REALLOC",
   "WTX_MEM_ADD_TO_POOL",
   "WTX_REGS_GET",
   "WTX_REGS_SET",
   "WTX_OPEN",
   "WTX_VIO_READ",
   "WTX_VIO_WRITE",
   "WTX_CLOSE",
   "WTX_VIO_CTL",
   "WTX_VIO_FILE_LIST",
   "WTX_VIO_CHAN_GET",
   "WTX_VIO_CHAN_RELEASE",
   "WTX_OBJ_MODULE_LOAD",
   "WTX_OBJ_MODULE_UNLOAD",
   "WTX_OBJ_MODULE_LIST",
   "WTX_OBJ_MODULE_INFO_GET",
   "WTX_OBJ_MODULE_FIND",
   "WTX_OBJ_MODULE_UNDEF_SYM_ADD",
   "WTX_SYM_TBL_CREATE",
   "WTX_SYM_TBL_DELETE",
   "WTX_SYM_TBL_LIST_GET",
   "WTX_SYM_LIST_GET",
   "WTX_SYM_TBL_INFO_GET",
   "WTX_SYM_FIND",
   "WTX_SYM_ADD",
   "WTX_SYM_REMOVE",
   "WTX_EVENT_GET",
   "WTX_REGISTER_FOR_EVENT",
   "WTX_UN_REGIS_FOR_EVENT",
   "WTX_EVENT_ADD",
   "WTX_GOPHER_EVAL",
   "WTX_FUNC_CALL",
   "WTX_SERVICE_ADD",
   "WTX_WTX_SERVICE_LIST",
   "WTX_WDB_SERVICE_LIST",
   "WTX_CONSOLE_CREATE",
   "WTX_CONSOLE_KILL",
   "WTX_AGENT_MODE_SET",
   "WTX_AGENT_MODE_GET",
   "WTX_DIRECT_CALL",
   "WTX_OBJ_KILL",
   "WTX_OBJ_RESTART",
   "WTX_REGISTER",
   "WTX_UNREGISTER",
   "WTX_INFO_GET",
   "WTX_INFO_Q_GET",
   NULL
 };
 static long Define_Wtx_slotValues [] = {
   (long)__INCwtxh,
   (long)MC68000,
   (long)MC68010,
   (long)MC68020,
   (long)MC68030,
   (long)MC68040,
   (long)MC68LC040,
   (long)MC68060,
   (long)CPU32,
   (long)MC680X0,
   (long)SPARC,
   (long)SPARClite,
   (long)I960,
   (long)I960CA,
   (long)I960KA,
   (long)I960KB,
   (long)I960JX,
   (long)I960HX,
   (long)TRON,
   (long)G100,
   (long)G200,
   (long)MIPS,
   (long)R3000,
   (long)R33000,
   (long)R33020,
   (long)R4000,
   (long)CW4000,
   (long)R4650,
   (long)AM29XXX,
   (long)AM29030,
   (long)AM29200,
   (long)AM29035,
   (long)SIMSPARCSUNOS,
   (long)SIMHPPA,
   (long)I80X86,
   (long)I80386,
   (long)I80486,
   (long)PPC,
   (long)PPC601,
   (long)PPC602,
   (long)PPC603,
   (long)PPC604,
   (long)PPC403,
   (long)PPC505,
   (long)PPC860,
   (long)SIMSPARCSOLARIS,
   (long)BIG_ENDIAN,
   (long)LITTLE_ENDIAN,
   (long)_ALLOC_ALIGN_SIZE,
   (long)NULL,
   (long)FALSE,
   (long)TRUE,
   (long)STD_IN,
   (long)STD_OUT,
   (long)STD_ERR,
   (long)OK,
   (long)WTX_OK,
   (long)__INCwtxerrh,
   (long)WTX_ERR_NONE,
   (long)WTXERR_BASE_NUM,
   (long)WTX_MAX_SYM_CNT,
   (long)WTX_MAX_EVTPT_CNT,
   (long)WTX_MAX_MODULE_CNT,
   (long)WTX_MAX_SERVICE_CNT,
   (long)WTX_MAX_ARG_CNT,
   (long)WTX_MAX_SYM_TBL_CNT,
   (long)WTX_MAX_VIO_DATA,
   (long)WTX_MAX_PATTERN_LEN,
   (long)WTX_MAX_FILENAME_LEN,
   (long)WTX_MAX_OBJ_SEG_CNT,
   (long)WTX_MAX_SECTION_CNT,
   (long)WTX_MAX_WDB_SVC_CNT,
   (long)WTX_CTL_VIO_REDIRECT,
   (long)WTX_OBJ_KILL_DESTROY,
   (long)WTX_OBJ_KILL_RESTART,
   (long)WTX_TOOL_ATTACH,
   (long)WTX_TOOL_DETACH,
   (long)WTX_TS_INFO_GET,
   (long)WTX_TARGET_RESET,
   (long)WTX_TS_LOCK,
   (long)WTX_TS_UNLOCK,
   (long)WTX_TARGET_ATTACH,
   (long)WTX_CONTEXT_CREATE,
   (long)WTX_CONTEXT_KILL,
   (long)WTX_CONTEXT_SUSPEND,
   (long)WTX_CONTEXT_CONT,
   (long)WTX_CONTEXT_RESUME,
   (long)WTX_CONTEXT_STEP,
   (long)WTX_EVENTPOINT_ADD,
   (long)WTX_EVENTPOINT_DELETE,
   (long)WTX_EVENTPOINT_LIST,
   (long)WTX_MEM_CHECKSUM,
   (long)WTX_MEM_READ,
   (long)WTX_MEM_WRITE,
   (long)WTX_MEM_SET,
   (long)WTX_MEM_SCAN,
   (long)WTX_MEM_MOVE,
   (long)WTX_MEM_ALLOC,
   (long)WTX_MEM_FREE,
   (long)WTX_MEM_INFO_GET,
   (long)WTX_MEM_ALIGN,
   (long)WTX_MEM_REALLOC,
   (long)WTX_MEM_ADD_TO_POOL,
   (long)WTX_REGS_GET,
   (long)WTX_REGS_SET,
   (long)WTX_OPEN,
   (long)WTX_VIO_READ,
   (long)WTX_VIO_WRITE,
   (long)WTX_CLOSE,
   (long)WTX_VIO_CTL,
   (long)WTX_VIO_FILE_LIST,
   (long)WTX_VIO_CHAN_GET,
   (long)WTX_VIO_CHAN_RELEASE,
   (long)WTX_OBJ_MODULE_LOAD,
   (long)WTX_OBJ_MODULE_UNLOAD,
   (long)WTX_OBJ_MODULE_LIST,
   (long)WTX_OBJ_MODULE_INFO_GET,
   (long)WTX_OBJ_MODULE_FIND,
   (long)WTX_OBJ_MODULE_UNDEF_SYM_ADD,
   (long)WTX_SYM_TBL_CREATE,
   (long)WTX_SYM_TBL_DELETE,
   (long)WTX_SYM_TBL_LIST_GET,
   (long)WTX_SYM_LIST_GET,
   (long)WTX_SYM_TBL_INFO_GET,
   (long)WTX_SYM_FIND,
   (long)WTX_SYM_ADD,
   (long)WTX_SYM_REMOVE,
   (long)WTX_EVENT_GET,
   (long)WTX_REGISTER_FOR_EVENT,
   (long)WTX_UN_REGIS_FOR_EVENT,
   (long)WTX_EVENT_ADD,
   (long)WTX_GOPHER_EVAL,
   (long)WTX_FUNC_CALL,
   (long)WTX_SERVICE_ADD,
   (long)WTX_WTX_SERVICE_LIST,
   (long)WTX_WDB_SERVICE_LIST,
   (long)WTX_CONSOLE_CREATE,
   (long)WTX_CONSOLE_KILL,
   (long)WTX_AGENT_MODE_SET,
   (long)WTX_AGENT_MODE_GET,
   (long)WTX_DIRECT_CALL,
   (long)WTX_OBJ_KILL,
   (long)WTX_OBJ_RESTART,
   (long)WTX_REGISTER,
   (long)WTX_UNREGISTER,
   (long)WTX_INFO_GET,
   (long)WTX_INFO_Q_GET,
   0
 };
 static JWRAP_enums Define_Wtx_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_Wtx],
  147,
  Define_Wtx_slotNames,
  (long*)Define_Wtx_slotValues
 };
LOCAL int Put_Define_Wtx (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_Wtx_enum, tclObj));
}
LOCAL void Get_Define_Wtx (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_Wtx_enum, tclObj);
}
// Build Define_Wtx jointure as a Tcl type
static Tcl_ObjType Define_Wtx_type = {
  "Define_Wtx",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_Wtx,
  (Tcl_SetFromAnyProc*)      Put_Define_Wtx
  };


/* *** Enumeration Section *** */


  // build enumeration wtx_error_t 
 static char *wtx_error_t_slotNames [] = {
   "WTX_ERR_SVR_TARGET_NOT_ATTACHED",
   "WTX_ERR_SVR_INVALID_EVENTPOINT",
   "WTX_ERR_SVR_FILE_NOT_FOUND",
   "WTX_ERR_SVR_INVALID_FIND_REQUEST",
   "WTX_ERR_SVR_INVALID_FLAGS",
   "WTX_ERR_SVR_INVALID_FILE_DESCRIPTOR",
   "WTX_ERR_SVR_EINVAL",
   "WTX_ERR_SVR_CANT_START_CONSOLE",
   "WTX_ERR_SVR_INVALID_CONSOLE",
   "WTX_ERR_SVR_NO_SCALABLE_AGENT",
   "WTX_ERR_SVR_CANT_ADD_WTX_SERVICE",
   "WTX_ERR_SVR_NO_VIO_CHANNEL",
   "WTX_ERR_SVR_NOT_ENOUGH_MEMORY",
   "WTX_ERR_SVR_ACCESS_DENIED",
   "WTX_ERR_SVR_WIND_BASE_NOT_SET",
   "WTX_ERR_SVR_SERVICE_NOT_AVAILABLE",
   "WTX_ERR_SVR_INVALID_CLIENT_ID",
   "WTX_ERR_SVR_CLIENT_NOT_ATTACHED",
   "WTX_ERR_SVR_TARGET_UNKNOWN",
   "WTX_ERR_SVR_INVALID_DEVICE",
   "WTX_ERR_SVR_CANT_CONNECT_LICENSE_DAEMON",
   "WTX_ERR_SVR_INVALID_LICENSE",
   "WTX_ERR_REGISTRY_NAME_NOT_FOUND",
   "WTX_ERR_REGISTRY_BAD_PATTERN",
   "WTX_ERR_REGISTRY_NAME_CLASH",
   "WTX_ERR_LOADER_TEXT_IN_USE",
   "WTX_ERR_LOADER_ILLEGAL_FLAGS_COMBINATION",
   "WTX_ERR_LOADER_NO_RELOCATION_ROUTINE",
   "WTX_ERR_LOADER_CANT_GET_SEGMENT_ADDRESSES",
   "WTX_ERR_LOADER_UNKNOWN_RELOCATION_ENTRY",
   "WTX_ERR_LOADER_UNKNOWN_COMMAND_FLAG",
   "WTX_ERR_LOADER_UNKNOWN_OBJ_MODULE_FORMAT",
   "WTX_ERR_LOADER_NULL_SIZE_OBJ_MODULE",
   "WTX_ERR_LOADER_OBJ_MODULE_NOT_FOUND",
   "WTX_ERR_LOADER_BAD_CHECKSUM",
   "WTX_ERR_LOADER_CANT_ATTACH_OMF_MANAGER",
   "WTX_ERR_LOADER_OBJ_MODULE_NOT_APPROPRIATE",
   "WTX_ERR_LOADER_RELOCATION_OFFSET_TOO_LARGE",
   "WTX_ERR_LOADER_SYMBOL_NOT_FROM_SDA_SECTION",
   "WTX_ERR_LOADER_MAX_MODULES_LOADED",
   "WTX_ERR_LOADER_RELOCATION_ERROR",
   "WTX_ERR_SYMTBL_INVALID_SYMTBL",
   "WTX_ERR_SYMTBL_SYMBOL_NOT_FOUND",
   "WTX_ERR_SYMTBL_TABLE_NOT_EMPTY",
   "WTX_ERR_SYMTBL_NAME_CLASH",
   "WTX_ERR_SYMTBL_NO_SUCH_MODULE",
   "WTX_ERR_SYMTBL_SYMBOL_NAME_TOO_LONG",
   "WTX_ERR_TGTMEM_NOT_ENOUGH_MEMORY",
   "WTX_ERR_TGTMEM_INVALID_POOL_SIZE",
   "WTX_ERR_TGTMEM_INVALID_BLOCK",
   "WTX_ERR_TGTMEM_PAGE_SIZE_UNAVAILABLE",
   "WTX_ERR_TGTMEM_BLOCK_CONFLICT",
   "WTX_ERR_TGTMEM_CANT_UNMAP_UNKNOWN_BLOCK",
   "WTX_ERR_TGTMEM_UNMAPPED_MEMORY",
   "WTX_ERR_DLL_CANT_OPEN_SHARED_FILE",
   "WTX_ERR_DLL_CANT_BIND_FUNCTION",
   "WTX_ERR_DLL_CANT_CLOSE_SHARED_FILE",
   "WTX_ERR_OBJ_INVALID_OBJECT",
   "WTX_ERR_AGENT_UNSUPPORTED_REQUEST",
   "WTX_ERR_AGENT_INVALID_PARAMS",
   "WTX_ERR_AGENT_MEM_ACCESS_ERROR",
   "WTX_ERR_AGENT_AGENT_MODE_ERROR",
   "WTX_ERR_AGENT_RT_ERROR",
   "WTX_ERR_AGENT_INVALID_CONTEXT",
   "WTX_ERR_AGENT_INVALID_VIO_CHANNEL",
   "WTX_ERR_AGENT_INVALID_EVENT",
   "WTX_ERR_AGENT_INVALID_EVENTPOINT",
   "WTX_ERR_AGENT_GOPHER_FAULT",
   "WTX_ERR_AGENT_GOPHER_TRUNCATED",
   "WTX_ERR_AGENT_EVENTPOINT_TABLE_FULL",
   "WTX_ERR_AGENT_NO_AGENT_PROC",
   "WTX_ERR_AGENT_NO_RT_PROC",
   "WTX_ERR_AGENT_PROC_FAILED",
   "WTX_ERR_AGENT_PATTERN_NOT_FOUND",
   "WTX_ERR_AGENT_NO_CONNECTION",
   "WTX_ERR_AGENT_CONNECTION_BUSY",
   "WTX_ERR_AGENT_COMMUNICATION_ERROR",
   "WTX_ERR_AGENT_GOPHER_SYNTAX",
   "WTX_ERR_API",
   "WTX_ERR_API_MEMALLOC",
   "WTX_ERR_API_HANDLER_NOT_FOUND",
   "WTX_ERR_API_NOT_CONNECTED",
   "WTX_ERR_API_INVALID_ARG",
   "WTX_ERR_API_SERVER_NOT_FOUND",
   "WTX_ERR_API_ALREADY_CONNECTED",
   "WTX_ERR_API_AMBIGUOUS_SERVER_NAME",
   "WTX_ERR_API_REGS_GET_PARTIAL_READ",
   "WTX_ERR_API_INVALID_HANDLE",
   "WTX_ERR_API_REGISTRY_UNREACHABLE",
   "WTX_ERR_API_SERVICE_NOT_REGISTERED",
   "WTX_ERR_API_SERVICE_ALREADY_REGISTERED",
   "WTX_ERR_API_TOOL_DISCONNECTED",
   "WTX_ERR_API_REQUEST_FAILED",
   "WTX_ERR_API_REQUEST_TIMED_OUT",
   "WTX_ERR_EXCHANGE",
   "WTX_ERR_EXCHANGE_INVALID_HANDLE",
   "WTX_ERR_EXCHANGE_DATA",
   "WTX_ERR_EXCHANGE_MEMALLOC",
   "WTX_ERR_EXCHANGE_NO_SERVER",
   "WTX_ERR_EXCHANGE_INVALID_ARG",
   "WTX_ERR_EXCHANGE_MARSHALPTR",
   "WTX_ERR_EXCHANGE_TIMEOUT",
   "WTX_ERR_EXCHANGE_BAD_KEY",
   "WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED",
   "WTX_ERR_EXCHANGE_TRANSPORT_UNSUPPORTED",
   "WTX_ERR_EXCHANGE_TRANSPORT_ERROR",
   "WTX_ERR_EXCHANGE_TRANSPORT_DISCONNECT",
   "WTX_ERR_EXCHANGE_NO_TRANSPORT",
   "WTX_ERR_LAST",
   NULL
 };
 static enum wtx_error_t wtx_error_t_slotValues [] = {
   WTX_ERR_SVR_TARGET_NOT_ATTACHED,
   WTX_ERR_SVR_INVALID_EVENTPOINT,
   WTX_ERR_SVR_FILE_NOT_FOUND,
   WTX_ERR_SVR_INVALID_FIND_REQUEST,
   WTX_ERR_SVR_INVALID_FLAGS,
   WTX_ERR_SVR_INVALID_FILE_DESCRIPTOR,
   WTX_ERR_SVR_EINVAL,
   WTX_ERR_SVR_CANT_START_CONSOLE,
   WTX_ERR_SVR_INVALID_CONSOLE,
   WTX_ERR_SVR_NO_SCALABLE_AGENT,
   WTX_ERR_SVR_CANT_ADD_WTX_SERVICE,
   WTX_ERR_SVR_NO_VIO_CHANNEL,
   WTX_ERR_SVR_NOT_ENOUGH_MEMORY,
   WTX_ERR_SVR_ACCESS_DENIED,
   WTX_ERR_SVR_WIND_BASE_NOT_SET,
   WTX_ERR_SVR_SERVICE_NOT_AVAILABLE,
   WTX_ERR_SVR_INVALID_CLIENT_ID,
   WTX_ERR_SVR_CLIENT_NOT_ATTACHED,
   WTX_ERR_SVR_TARGET_UNKNOWN,
   WTX_ERR_SVR_INVALID_DEVICE,
   WTX_ERR_SVR_CANT_CONNECT_LICENSE_DAEMON,
   WTX_ERR_SVR_INVALID_LICENSE,
   WTX_ERR_REGISTRY_NAME_NOT_FOUND,
   WTX_ERR_REGISTRY_BAD_PATTERN,
   WTX_ERR_REGISTRY_NAME_CLASH,
   WTX_ERR_LOADER_TEXT_IN_USE,
   WTX_ERR_LOADER_ILLEGAL_FLAGS_COMBINATION,
   WTX_ERR_LOADER_NO_RELOCATION_ROUTINE,
   WTX_ERR_LOADER_CANT_GET_SEGMENT_ADDRESSES,
   WTX_ERR_LOADER_UNKNOWN_RELOCATION_ENTRY,
   WTX_ERR_LOADER_UNKNOWN_COMMAND_FLAG,
   WTX_ERR_LOADER_UNKNOWN_OBJ_MODULE_FORMAT,
   WTX_ERR_LOADER_NULL_SIZE_OBJ_MODULE,
   WTX_ERR_LOADER_OBJ_MODULE_NOT_FOUND,
   WTX_ERR_LOADER_BAD_CHECKSUM,
   WTX_ERR_LOADER_CANT_ATTACH_OMF_MANAGER,
   WTX_ERR_LOADER_OBJ_MODULE_NOT_APPROPRIATE,
   WTX_ERR_LOADER_RELOCATION_OFFSET_TOO_LARGE,
   WTX_ERR_LOADER_SYMBOL_NOT_FROM_SDA_SECTION,
   WTX_ERR_LOADER_MAX_MODULES_LOADED,
   WTX_ERR_LOADER_RELOCATION_ERROR,
   WTX_ERR_SYMTBL_INVALID_SYMTBL,
   WTX_ERR_SYMTBL_SYMBOL_NOT_FOUND,
   WTX_ERR_SYMTBL_TABLE_NOT_EMPTY,
   WTX_ERR_SYMTBL_NAME_CLASH,
   WTX_ERR_SYMTBL_NO_SUCH_MODULE,
   WTX_ERR_SYMTBL_SYMBOL_NAME_TOO_LONG,
   WTX_ERR_TGTMEM_NOT_ENOUGH_MEMORY,
   WTX_ERR_TGTMEM_INVALID_POOL_SIZE,
   WTX_ERR_TGTMEM_INVALID_BLOCK,
   WTX_ERR_TGTMEM_PAGE_SIZE_UNAVAILABLE,
   WTX_ERR_TGTMEM_BLOCK_CONFLICT,
   WTX_ERR_TGTMEM_CANT_UNMAP_UNKNOWN_BLOCK,
   WTX_ERR_TGTMEM_UNMAPPED_MEMORY,
   WTX_ERR_DLL_CANT_OPEN_SHARED_FILE,
   WTX_ERR_DLL_CANT_BIND_FUNCTION,
   WTX_ERR_DLL_CANT_CLOSE_SHARED_FILE,
   WTX_ERR_OBJ_INVALID_OBJECT,
   WTX_ERR_AGENT_UNSUPPORTED_REQUEST,
   WTX_ERR_AGENT_INVALID_PARAMS,
   WTX_ERR_AGENT_MEM_ACCESS_ERROR,
   WTX_ERR_AGENT_AGENT_MODE_ERROR,
   WTX_ERR_AGENT_RT_ERROR,
   WTX_ERR_AGENT_INVALID_CONTEXT,
   WTX_ERR_AGENT_INVALID_VIO_CHANNEL,
   WTX_ERR_AGENT_INVALID_EVENT,
   WTX_ERR_AGENT_INVALID_EVENTPOINT,
   WTX_ERR_AGENT_GOPHER_FAULT,
   WTX_ERR_AGENT_GOPHER_TRUNCATED,
   WTX_ERR_AGENT_EVENTPOINT_TABLE_FULL,
   WTX_ERR_AGENT_NO_AGENT_PROC,
   WTX_ERR_AGENT_NO_RT_PROC,
   WTX_ERR_AGENT_PROC_FAILED,
   WTX_ERR_AGENT_PATTERN_NOT_FOUND,
   WTX_ERR_AGENT_NO_CONNECTION,
   WTX_ERR_AGENT_CONNECTION_BUSY,
   WTX_ERR_AGENT_COMMUNICATION_ERROR,
   WTX_ERR_AGENT_GOPHER_SYNTAX,
   WTX_ERR_API,
   WTX_ERR_API_MEMALLOC,
   WTX_ERR_API_HANDLER_NOT_FOUND,
   WTX_ERR_API_NOT_CONNECTED,
   WTX_ERR_API_INVALID_ARG,
   WTX_ERR_API_SERVER_NOT_FOUND,
   WTX_ERR_API_ALREADY_CONNECTED,
   WTX_ERR_API_AMBIGUOUS_SERVER_NAME,
   WTX_ERR_API_REGS_GET_PARTIAL_READ,
   WTX_ERR_API_INVALID_HANDLE,
   WTX_ERR_API_REGISTRY_UNREACHABLE,
   WTX_ERR_API_SERVICE_NOT_REGISTERED,
   WTX_ERR_API_SERVICE_ALREADY_REGISTERED,
   WTX_ERR_API_TOOL_DISCONNECTED,
   WTX_ERR_API_REQUEST_FAILED,
   WTX_ERR_API_REQUEST_TIMED_OUT,
   WTX_ERR_EXCHANGE,
   WTX_ERR_EXCHANGE_INVALID_HANDLE,
   WTX_ERR_EXCHANGE_DATA,
   WTX_ERR_EXCHANGE_MEMALLOC,
   WTX_ERR_EXCHANGE_NO_SERVER,
   WTX_ERR_EXCHANGE_INVALID_ARG,
   WTX_ERR_EXCHANGE_MARSHALPTR,
   WTX_ERR_EXCHANGE_TIMEOUT,
   WTX_ERR_EXCHANGE_BAD_KEY,
   WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED,
   WTX_ERR_EXCHANGE_TRANSPORT_UNSUPPORTED,
   WTX_ERR_EXCHANGE_TRANSPORT_ERROR,
   WTX_ERR_EXCHANGE_TRANSPORT_DISCONNECT,
   WTX_ERR_EXCHANGE_NO_TRANSPORT,
   WTX_ERR_LAST,
   0
 };
 static JWRAP_enums wtx_error_t_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_error_t],
  109,
  wtx_error_t_slotNames,
  (long*)wtx_error_t_slotValues
 };
LOCAL int Put_wtx_error_t (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_error_t_enum, tclObj));
}
LOCAL void Get_wtx_error_t (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_error_t_enum, tclObj);
}
// Build wtx_error_t jointure as a Tcl type
static Tcl_ObjType wtx_error_t_type = {
  "wtx_error_t",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_error_t,
  (Tcl_SetFromAnyProc*)      Put_wtx_error_t
  };

  // build enumeration wtx_event_type 
 static char *wtx_event_type_slotNames [] = {
   "WTX_EVENT_NONE",
   "WTX_EVENT_CTX_START",
   "WTX_EVENT_CTX_EXIT",
   "WTX_EVENT_TEXT_ACCESS",
   "WTX_EVENT_DATA_ACCESS",
   "WTX_EVENT_EXCEPTION",
   "WTX_EVENT_VIO_WRITE",
   "WTX_EVENT_BREAKPOINT",
   "WTX_EVENT_CALL_RETURN",
   "WTX_EVENT_USER",
   "WTX_EVENT_UNKNOWN",
   "WTX_EVENT_TGT_RESET",
   "WTX_EVENT_SYM_ADDED",
   "WTX_EVENT_SYM_REMOVED",
   "WTX_EVENT_OBJ_LOADED",
   "WTX_EVENT_OBJ_UNLOADED",
   "WTX_EVENT_TOOL_ATTACH",
   "WTX_EVENT_TOOL_DETACH",
   "WTX_EVENT_TOOL_MSG",
   "WTX_EVENT_OTHER",
   "WTX_EVENT_INVALID",
   NULL
 };
 static enum wtx_event_type wtx_event_type_slotValues [] = {
   WTX_EVENT_NONE,
   WTX_EVENT_CTX_START,
   WTX_EVENT_CTX_EXIT,
   WTX_EVENT_TEXT_ACCESS,
   WTX_EVENT_DATA_ACCESS,
   WTX_EVENT_EXCEPTION,
   WTX_EVENT_VIO_WRITE,
   WTX_EVENT_BREAKPOINT,
   WTX_EVENT_CALL_RETURN,
   WTX_EVENT_USER,
   WTX_EVENT_UNKNOWN,
   WTX_EVENT_TGT_RESET,
   WTX_EVENT_SYM_ADDED,
   WTX_EVENT_SYM_REMOVED,
   WTX_EVENT_OBJ_LOADED,
   WTX_EVENT_OBJ_UNLOADED,
   WTX_EVENT_TOOL_ATTACH,
   WTX_EVENT_TOOL_DETACH,
   WTX_EVENT_TOOL_MSG,
   WTX_EVENT_OTHER,
   WTX_EVENT_INVALID,
   0
 };
 static JWRAP_enums wtx_event_type_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_event_type],
  21,
  wtx_event_type_slotNames,
  (long*)wtx_event_type_slotValues
 };
LOCAL int Put_wtx_event_type (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_event_type_enum, tclObj));
}
LOCAL void Get_wtx_event_type (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_event_type_enum, tclObj);
}
// Build wtx_event_type jointure as a Tcl type
static Tcl_ObjType wtx_event_type_type = {
  "wtx_event_type",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_event_type,
  (Tcl_SetFromAnyProc*)      Put_wtx_event_type
  };

  // build enumeration wtx_context_type 
 static char *wtx_context_type_slotNames [] = {
   "WTX_CONTEXT_SYSTEM",
   "WTX_CONTEXT_GROUP",
   "WTX_CONTEXT_ANY",
   "WTX_CONTEXT_TASK",
   "WTX_CONTEXT_ANY_TASK",
   "WTX_CONTEXT_ISR",
   "WTX_CONTEXT_ISR_ANY",
   NULL
 };
 static enum wtx_context_type wtx_context_type_slotValues [] = {
   WTX_CONTEXT_SYSTEM,
   WTX_CONTEXT_GROUP,
   WTX_CONTEXT_ANY,
   WTX_CONTEXT_TASK,
   WTX_CONTEXT_ANY_TASK,
   WTX_CONTEXT_ISR,
   WTX_CONTEXT_ISR_ANY,
   0
 };
 static JWRAP_enums wtx_context_type_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_context_type],
  7,
  wtx_context_type_slotNames,
  (long*)wtx_context_type_slotValues
 };
LOCAL int Put_wtx_context_type (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_context_type_enum, tclObj));
}
LOCAL void Get_wtx_context_type (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_context_type_enum, tclObj);
}
// Build wtx_context_type jointure as a Tcl type
static Tcl_ObjType wtx_context_type_type = {
  "wtx_context_type",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_context_type,
  (Tcl_SetFromAnyProc*)      Put_wtx_context_type
  };

  // build enumeration wtx_action_type 
 static char *wtx_action_type_slotNames [] = {
   "WTX_ACTION_CALL",
   "WTX_ACTION_NOTIFY",
   "WTX_ACTION_STOP",
   "WTX_ACTION_STOP_ALL",
   NULL
 };
 static enum wtx_action_type wtx_action_type_slotValues [] = {
   WTX_ACTION_CALL,
   WTX_ACTION_NOTIFY,
   WTX_ACTION_STOP,
   WTX_ACTION_STOP_ALL,
   0
 };
 static JWRAP_enums wtx_action_type_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_action_type],
  4,
  wtx_action_type_slotNames,
  (long*)wtx_action_type_slotValues
 };
LOCAL int Put_wtx_action_type (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_action_type_enum, tclObj));
}
LOCAL void Get_wtx_action_type (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_action_type_enum, tclObj);
}
// Build wtx_action_type jointure as a Tcl type
static Tcl_ObjType wtx_action_type_type = {
  "wtx_action_type",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_action_type,
  (Tcl_SetFromAnyProc*)      Put_wtx_action_type
  };

  // build enumeration wtx_return_type 
 static char *wtx_return_type_slotNames [] = {
   "WTX_RETURN_TYPE_INT",
   "WTX_RETURN_TYPE_DOUBLE",
   NULL
 };
 static enum wtx_return_type wtx_return_type_slotValues [] = {
   WTX_RETURN_TYPE_INT,
   WTX_RETURN_TYPE_DOUBLE,
   0
 };
 static JWRAP_enums wtx_return_type_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_return_type],
  2,
  wtx_return_type_slotNames,
  (long*)wtx_return_type_slotValues
 };
LOCAL int Put_wtx_return_type (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_return_type_enum, tclObj));
}
LOCAL void Get_wtx_return_type (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_return_type_enum, tclObj);
}
// Build wtx_return_type jointure as a Tcl type
static Tcl_ObjType wtx_return_type_type = {
  "wtx_return_type",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_return_type,
  (Tcl_SetFromAnyProc*)      Put_wtx_return_type
  };

  // build enumeration wtx_reg_set_type 
 static char *wtx_reg_set_type_slotNames [] = {
   "WTX_REG_SET_IU",
   "WTX_REG_SET_FPU",
   "WTX_REG_SET_MMU",
   "WTX_REG_SET_CU",
   "WTX_REG_SET_TPU",
   "WTX_REG_SET_SYS",
   NULL
 };
 static enum wtx_reg_set_type wtx_reg_set_type_slotValues [] = {
   WTX_REG_SET_IU,
   WTX_REG_SET_FPU,
   WTX_REG_SET_MMU,
   WTX_REG_SET_CU,
   WTX_REG_SET_TPU,
   WTX_REG_SET_SYS,
   0
 };
 static JWRAP_enums wtx_reg_set_type_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_reg_set_type],
  6,
  wtx_reg_set_type_slotNames,
  (long*)wtx_reg_set_type_slotValues
 };
LOCAL int Put_wtx_reg_set_type (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_reg_set_type_enum, tclObj));
}
LOCAL void Get_wtx_reg_set_type (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_reg_set_type_enum, tclObj);
}
// Build wtx_reg_set_type jointure as a Tcl type
static Tcl_ObjType wtx_reg_set_type_type = {
  "wtx_reg_set_type",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_reg_set_type,
  (Tcl_SetFromAnyProc*)      Put_wtx_reg_set_type
  };

  // build enumeration wtx_agent_mode_type 
 static char *wtx_agent_mode_type_slotNames [] = {
   "WTX_AGENT_MODE_TASK",
   "WTX_AGENT_MODE_EXTERN",
   "WTX_AGENT_MODE_BI",
   NULL
 };
 static enum wtx_agent_mode_type wtx_agent_mode_type_slotValues [] = {
   WTX_AGENT_MODE_TASK,
   WTX_AGENT_MODE_EXTERN,
   WTX_AGENT_MODE_BI,
   0
 };
 static JWRAP_enums wtx_agent_mode_type_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_agent_mode_type],
  3,
  wtx_agent_mode_type_slotNames,
  (long*)wtx_agent_mode_type_slotValues
 };
LOCAL int Put_wtx_agent_mode_type (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_agent_mode_type_enum, tclObj));
}
LOCAL void Get_wtx_agent_mode_type (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_agent_mode_type_enum, tclObj);
}
// Build wtx_agent_mode_type jointure as a Tcl type
static Tcl_ObjType wtx_agent_mode_type_type = {
  "wtx_agent_mode_type",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_agent_mode_type,
  (Tcl_SetFromAnyProc*)      Put_wtx_agent_mode_type
  };

  // build enumeration wtx_open_flag 
 static char *wtx_open_flag_slotNames [] = {
   "WTX_O_RDONLY",
   "WTX_O_WRONLY",
   "WTX_O_CREAT",
   NULL
 };
 static enum wtx_open_flag wtx_open_flag_slotValues [] = {
   WTX_O_RDONLY,
   WTX_O_WRONLY,
   WTX_O_CREAT,
   0
 };
 static JWRAP_enums wtx_open_flag_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_open_flag],
  3,
  wtx_open_flag_slotNames,
  (long*)wtx_open_flag_slotValues
 };
LOCAL int Put_wtx_open_flag (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_open_flag_enum, tclObj));
}
LOCAL void Get_wtx_open_flag (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_open_flag_enum, tclObj);
}
// Build wtx_open_flag jointure as a Tcl type
static Tcl_ObjType wtx_open_flag_type = {
  "wtx_open_flag",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_open_flag,
  (Tcl_SetFromAnyProc*)      Put_wtx_open_flag
  };

  // build enumeration wtx_value_t 
 static char *wtx_value_t_slotNames [] = {
   "V_INT8",
   "V_INT16",
   "V_INT32",
   "V_UINT8",
   "V_UINT16",
   "V_UINT32",
   "V_DOUBLE",
   "V_BOOL32",
   "V_PCHAR",
   "V_PVOID",
   "V_TGT_ADDR",
   "V_TGT_ARG",
   NULL
 };
 static enum wtx_value_t wtx_value_t_slotValues [] = {
   V_INT8,
   V_INT16,
   V_INT32,
   V_UINT8,
   V_UINT16,
   V_UINT32,
   V_DOUBLE,
   V_BOOL32,
   V_PCHAR,
   V_PVOID,
   V_TGT_ADDR,
   V_TGT_ARG,
   0
 };
 static JWRAP_enums wtx_value_t_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_value_t],
  12,
  wtx_value_t_slotNames,
  (long*)wtx_value_t_slotValues
 };
LOCAL int Put_wtx_value_t (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_value_t_enum, tclObj));
}
LOCAL void Get_wtx_value_t (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_value_t_enum, tclObj);
}
// Build wtx_value_t jointure as a Tcl type
static Tcl_ObjType wtx_value_t_type = {
  "wtx_value_t",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_value_t,
  (Tcl_SetFromAnyProc*)      Put_wtx_value_t
  };

  // build enumeration wtx_endian_t 
 static char *wtx_endian_t_slotNames [] = {
   "WTX_ENDIAN_BIG",
   "WTX_ENDIAN_LITTLE",
   "WTX_ENDIAN_UNKNOWN",
   NULL
 };
 static enum wtx_endian_t wtx_endian_t_slotValues [] = {
   WTX_ENDIAN_BIG,
   WTX_ENDIAN_LITTLE,
   WTX_ENDIAN_UNKNOWN,
   0
 };
 static JWRAP_enums wtx_endian_t_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_wtx_endian_t],
  3,
  wtx_endian_t_slotNames,
  (long*)wtx_endian_t_slotValues
 };
LOCAL int Put_wtx_endian_t (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &wtx_endian_t_enum, tclObj));
}
LOCAL void Get_wtx_endian_t (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&wtx_endian_t_enum, tclObj);
}
// Build wtx_endian_t jointure as a Tcl type
static Tcl_ObjType wtx_endian_t_type = {
  "wtx_endian_t",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_endian_t,
  (Tcl_SetFromAnyProc*)      Put_wtx_endian_t
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_Wtx_enum,
  &wtx_error_t_enum,
  &wtx_event_type_enum,
  &wtx_context_type_enum,
  &wtx_action_type_enum,
  &wtx_return_type_enum,
  &wtx_reg_set_type_enum,
  &wtx_agent_mode_type_enum,
  &wtx_open_flag_enum,
  &wtx_value_t_enum,
  &wtx_endian_t_enum,
  NULL
 };
 
/* *** Unions Section *** */

// We need to produce internal union in order computing size
union Union_Wtx_0 {
  INT8 v_int8;
  INT16 v_int16;
  INT32 v_int32;
  UINT8 v_uint8;
  UINT16 v_uint16;
  UINT32 v_uint32;
  double v_double;
  BOOL32 v_bool32;
  char* v_pchar;
  void* v_pvoid;
  TGT_ADDR_T v_tgt_addr;
  TGT_ARG_T v_tgt_arg;
};
typedef union Union_Wtx_0 Union_Wtx_0;

// Alloc Union_Wtx_0 slot jointure for Put/Get functions
static char *Union_Wtx_0_slotNames[] =  {
    "v_int8",
    "v_int16",
    "v_int32",
    "v_uint8",
    "v_uint16",
    "v_uint32",
    "v_double",
    "v_bool32",
    "v_pchar",
    "v_pvoid",
    "v_tgt_addr",
    "v_tgt_arg",
    NULL
};
static JWRAP_types *Union_Wtx_0_slotTypes[] = {
    &usedType [JTYPE_INT8], // v_int8
    &usedType [JTYPE_INT16], // v_int16
    &usedType [JTYPE_INT32], // v_int32
    &usedType [JTYPE_UINT8], // v_uint8
    &usedType [JTYPE_UINT16], // v_uint16
    &usedType [JTYPE_UINT32], // v_uint32
    &usedType [JTYPE_double], // v_double
    &usedType [JTYPE_BOOL32], // v_bool32
    &usedType [JTYPE_char_Ptr], // v_pchar
    &usedType [JTYPE_void_Ptr], // v_pvoid
    &usedType [JTYPE_TGT_ADDR_T], // v_tgt_addr
    &usedType [JTYPE_TGT_ARG_T], // v_tgt_arg
    NULL
};
static int Union_Wtx_0_slotOffsets[12];
static int Union_Wtx_0_slotArrays[] = {
    1, // v_int8
    1, // v_int16
    1, // v_int32
    1, // v_uint8
    1, // v_uint16
    1, // v_uint32
    1, // v_double
    1, // v_bool32
    1, // v_pchar
    1, // v_pvoid
    1, // v_tgt_addr
    1, // v_tgt_arg
    0
};
static JWRAP_structs Union_Wtx_0_union = {
  JWRAP_UNION,
  &usedType [JTYPE_Union_Wtx_0],
  12,
  Union_Wtx_0_slotNames,
  Union_Wtx_0_slotTypes,
  Union_Wtx_0_slotOffsets,
  Union_Wtx_0_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_Union_Wtx_0 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &Union_Wtx_0_union, srcObj, destObj));
}
LOCAL int Put_Union_Wtx_0 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  return (jWrapTypeUpdate (interp, &Union_Wtx_0_union, srcObj, destObj));
}
LOCAL char* Get_Union_Wtx_0 (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&Union_Wtx_0_union, tclObj);
}
// Build Union_Wtx_0 jointure as a Tcl type
static Tcl_ObjType Union_Wtx_0_type = {
  "Union_Wtx_0",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Union_Wtx_0,
  (Tcl_SetFromAnyProc*)      Put_Union_Wtx_0
  };
// Build Union_Wtx_0 jointure as a Tcl type
static Tcl_ObjType Union_Wtx_0_ptr = {
  "Union_Wtx_0_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Union_Wtx_0,
  (Tcl_SetFromAnyProc*)      Create_Union_Wtx_0
  };
// We need to produce internal union in order computing size
union Union_Wtx_1 {
  UINT32 moduleId;
  char* moduleName;
};
typedef union Union_Wtx_1 Union_Wtx_1;

// Alloc Union_Wtx_1 slot jointure for Put/Get functions
static char *Union_Wtx_1_slotNames[] =  {
    "moduleId",
    "moduleName",
    NULL
};
static JWRAP_types *Union_Wtx_1_slotTypes[] = {
    &usedType [JTYPE_UINT32], // moduleId
    &usedType [JTYPE_char_Ptr], // moduleName
    NULL
};
static int Union_Wtx_1_slotOffsets[2];
static int Union_Wtx_1_slotArrays[] = {
    1, // moduleId
    1, // moduleName
    0
};
static JWRAP_structs Union_Wtx_1_union = {
  JWRAP_UNION,
  &usedType [JTYPE_Union_Wtx_1],
  2,
  Union_Wtx_1_slotNames,
  Union_Wtx_1_slotTypes,
  Union_Wtx_1_slotOffsets,
  Union_Wtx_1_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_Union_Wtx_1 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &Union_Wtx_1_union, srcObj, destObj));
}
LOCAL int Put_Union_Wtx_1 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  return (jWrapTypeUpdate (interp, &Union_Wtx_1_union, srcObj, destObj));
}
LOCAL char* Get_Union_Wtx_1 (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&Union_Wtx_1_union, tclObj);
}
// Build Union_Wtx_1 jointure as a Tcl type
static Tcl_ObjType Union_Wtx_1_type = {
  "Union_Wtx_1",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Union_Wtx_1,
  (Tcl_SetFromAnyProc*)      Put_Union_Wtx_1
  };
// Build Union_Wtx_1 jointure as a Tcl type
static Tcl_ObjType Union_Wtx_1_ptr = {
  "Union_Wtx_1_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Union_Wtx_1,
  (Tcl_SetFromAnyProc*)      Create_Union_Wtx_1
  };
 
/* *** Structure Section *** */

// Alloc wtx_core slot structure for Put/Get functions
static char *wtx_core_slotNames[] =  {
    "objId",
    "errCode",
    "protVersion",
    NULL
};
static JWRAP_types *wtx_core_slotTypes[] = {
    &usedType [JTYPE_UINT32], // objId 
    &usedType [JTYPE_WTX_ERROR_T], // errCode 
    &usedType [JTYPE_UINT32], // protVersion 
    NULL
};
static int wtx_core_slotArrays[] = {
    1, // objId
    1, // errCode
    1, // protVersion
    0
};
static int wtx_core_slotOffsets[3];
static JWRAP_structs wtx_core_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_core],
  3,
  wtx_core_slotNames,
  wtx_core_slotTypes,
  wtx_core_slotOffsets,
  wtx_core_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_core (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_core_struct, srcObj, destObj));
}
LOCAL int Put_wtx_core (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_core_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_core (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_core_struct, tclObj);
}
// Build wtx_core structure as a Tcl type
static Tcl_ObjType wtx_core_type = {
  "wtx_core",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_core,
  (Tcl_SetFromAnyProc*)      Put_wtx_core
  };
// Build wtx_core structure as a Tcl type
static Tcl_ObjType wtx_core_ptr = {
  "wtx_core_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_core,
  (Tcl_SetFromAnyProc*)      Create_wtx_core
  };

// Alloc wtx_desc slot structure for Put/Get functions
static char *wtx_desc_slotNames[] =  {
    "wpwrName",
    "wpwrType",
    "wpwrKey",
    NULL
};
static JWRAP_types *wtx_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // wpwrName 
    &usedType [JTYPE_char_Ptr], // wpwrType 
    &usedType [JTYPE_char_Ptr], // wpwrKey 
    NULL
};
static int wtx_desc_slotArrays[] = {
    1, // wpwrName
    1, // wpwrType
    1, // wpwrKey
    0
};
static int wtx_desc_slotOffsets[3];
static JWRAP_structs wtx_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_desc],
  3,
  wtx_desc_slotNames,
  wtx_desc_slotTypes,
  wtx_desc_slotOffsets,
  wtx_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_desc_struct, tclObj);
}
// Build wtx_desc structure as a Tcl type
static Tcl_ObjType wtx_desc_type = {
  "wtx_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_desc
  };
// Build wtx_desc structure as a Tcl type
static Tcl_ObjType wtx_desc_ptr = {
  "wtx_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_desc
  };

// Alloc wtx_desc_q slot structure for Put/Get functions
static char *wtx_desc_q_slotNames[] =  {
    "wpwrName",
    "wpwrType",
    "wpwrKey",
    "pNext",
    NULL
};
static JWRAP_types *wtx_desc_q_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // wpwrName 
    &usedType [JTYPE_char_Ptr], // wpwrType 
    &usedType [JTYPE_char_Ptr], // wpwrKey 
    &usedType [JTYPE_wtx_desc_q_Ptr], // pNext 
    NULL
};
static int wtx_desc_q_slotArrays[] = {
    1, // wpwrName
    1, // wpwrType
    1, // wpwrKey
    1, // pNext
    0
};
static int wtx_desc_q_slotOffsets[4];
static JWRAP_structs wtx_desc_q_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_desc_q],
  4,
  wtx_desc_q_slotNames,
  wtx_desc_q_slotTypes,
  wtx_desc_q_slotOffsets,
  wtx_desc_q_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_desc_q (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_desc_q_struct, srcObj, destObj));
}
LOCAL int Put_wtx_desc_q (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_desc_q_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_desc_q (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_desc_q_struct, tclObj);
}
// Build wtx_desc_q structure as a Tcl type
static Tcl_ObjType wtx_desc_q_type = {
  "wtx_desc_q",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_desc_q,
  (Tcl_SetFromAnyProc*)      Put_wtx_desc_q
  };
// Build wtx_desc_q structure as a Tcl type
static Tcl_ObjType wtx_desc_q_ptr = {
  "wtx_desc_q_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_desc_q,
  (Tcl_SetFromAnyProc*)      Create_wtx_desc_q
  };

// Alloc wtx_value slot structure for Put/Get functions
static char *wtx_value_slotNames[] =  {
    "valueType",
    "value_u",
    NULL
};
static JWRAP_types *wtx_value_slotTypes[] = {
    &usedType [JTYPE_WTX_VALUE_T], // valueType 
    &usedType [JTYPE_Union_Wtx_0], // value_u 
    NULL
};
static int wtx_value_slotArrays[] = {
    1, // valueType
    1, // value_u
    0
};
static int wtx_value_slotOffsets[2];
static JWRAP_structs wtx_value_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_value],
  2,
  wtx_value_slotNames,
  wtx_value_slotTypes,
  wtx_value_slotOffsets,
  wtx_value_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_value (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_value_struct, srcObj, destObj));
}
LOCAL int Put_wtx_value (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_value_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_value (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_value_struct, tclObj);
}
// Build wtx_value structure as a Tcl type
static Tcl_ObjType wtx_value_type = {
  "wtx_value",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_value,
  (Tcl_SetFromAnyProc*)      Put_wtx_value
  };
// Build wtx_value structure as a Tcl type
static Tcl_ObjType wtx_value_ptr = {
  "wtx_value_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_value,
  (Tcl_SetFromAnyProc*)      Create_wtx_value
  };

// Alloc wtx_msg_result slot structure for Put/Get functions
static char *wtx_msg_result_slotNames[] =  {
    "wtxCore",
    "val",
    NULL
};
static JWRAP_types *wtx_msg_result_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_VALUE], // val 
    NULL
};
static int wtx_msg_result_slotArrays[] = {
    1, // wtxCore
    1, // val
    0
};
static int wtx_msg_result_slotOffsets[2];
static JWRAP_structs wtx_msg_result_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_result],
  2,
  wtx_msg_result_slotNames,
  wtx_msg_result_slotTypes,
  wtx_msg_result_slotOffsets,
  wtx_msg_result_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_result (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_result_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_result (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_result_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_result (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_result_struct, tclObj);
}
// Build wtx_msg_result structure as a Tcl type
static Tcl_ObjType wtx_msg_result_type = {
  "wtx_msg_result",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_result,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_result
  };
// Build wtx_msg_result structure as a Tcl type
static Tcl_ObjType wtx_msg_result_ptr = {
  "wtx_msg_result_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_result,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_result
  };

// Alloc wtx_msg_param slot structure for Put/Get functions
static char *wtx_msg_param_slotNames[] =  {
    "wtxCore",
    "param",
    NULL
};
static JWRAP_types *wtx_msg_param_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_VALUE], // param 
    NULL
};
static int wtx_msg_param_slotArrays[] = {
    1, // wtxCore
    1, // param
    0
};
static int wtx_msg_param_slotOffsets[2];
static JWRAP_structs wtx_msg_param_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_param],
  2,
  wtx_msg_param_slotNames,
  wtx_msg_param_slotTypes,
  wtx_msg_param_slotOffsets,
  wtx_msg_param_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_param (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_param_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_param (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_param_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_param (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_param_struct, tclObj);
}
// Build wtx_msg_param structure as a Tcl type
static Tcl_ObjType wtx_msg_param_type = {
  "wtx_msg_param",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_param,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_param
  };
// Build wtx_msg_param structure as a Tcl type
static Tcl_ObjType wtx_msg_param_ptr = {
  "wtx_msg_param_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_param,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_param
  };

// Alloc wtx_mem_region slot structure for Put/Get functions
static char *wtx_mem_region_slotNames[] =  {
    "baseAddr",
    "size",
    "attribute",
    NULL
};
static JWRAP_types *wtx_mem_region_slotTypes[] = {
    &usedType [JTYPE_TGT_ADDR_T], // baseAddr 
    &usedType [JTYPE_UINT32], // size 
    &usedType [JTYPE_UINT32], // attribute 
    NULL
};
static int wtx_mem_region_slotArrays[] = {
    1, // baseAddr
    1, // size
    1, // attribute
    0
};
static int wtx_mem_region_slotOffsets[3];
static JWRAP_structs wtx_mem_region_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_mem_region],
  3,
  wtx_mem_region_slotNames,
  wtx_mem_region_slotTypes,
  wtx_mem_region_slotOffsets,
  wtx_mem_region_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_mem_region (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_mem_region_struct, srcObj, destObj));
}
LOCAL int Put_wtx_mem_region (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_mem_region_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_mem_region (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_mem_region_struct, tclObj);
}
// Build wtx_mem_region structure as a Tcl type
static Tcl_ObjType wtx_mem_region_type = {
  "wtx_mem_region",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_mem_region,
  (Tcl_SetFromAnyProc*)      Put_wtx_mem_region
  };
// Build wtx_mem_region structure as a Tcl type
static Tcl_ObjType wtx_mem_region_ptr = {
  "wtx_mem_region_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_mem_region,
  (Tcl_SetFromAnyProc*)      Create_wtx_mem_region
  };

// Alloc wtx_rt_info slot structure for Put/Get functions
static char *wtx_rt_info_slotNames[] =  {
    "rtType",
    "rtVersion",
    "cpuType",
    "hasFpp",
    "hasWriteProtect",
    "pageSize",
    "endian",
    "bspName",
    "bootline",
    "memBase",
    "memSize",
    "numRegions",
    "memRegion",
    "hostPoolBase",
    "hostPoolSize",
    NULL
};
static JWRAP_types *wtx_rt_info_slotTypes[] = {
    &usedType [JTYPE_UINT32], // rtType 
    &usedType [JTYPE_char_Ptr], // rtVersion 
    &usedType [JTYPE_UINT32], // cpuType 
    &usedType [JTYPE_BOOL32], // hasFpp 
    &usedType [JTYPE_BOOL32], // hasWriteProtect 
    &usedType [JTYPE_UINT32], // pageSize 
    &usedType [JTYPE_UINT32], // endian 
    &usedType [JTYPE_char_Ptr], // bspName 
    &usedType [JTYPE_char_Ptr], // bootline 
    &usedType [JTYPE_TGT_ADDR_T], // memBase 
    &usedType [JTYPE_UINT32], // memSize 
    &usedType [JTYPE_UINT32], // numRegions 
    &usedType [JTYPE_WTX_MEM_REGION_Ptr], // memRegion 
    &usedType [JTYPE_TGT_ADDR_T], // hostPoolBase 
    &usedType [JTYPE_UINT32], // hostPoolSize 
    NULL
};
static int wtx_rt_info_slotArrays[] = {
    1, // rtType
    1, // rtVersion
    1, // cpuType
    1, // hasFpp
    1, // hasWriteProtect
    1, // pageSize
    1, // endian
    1, // bspName
    1, // bootline
    1, // memBase
    1, // memSize
    1, // numRegions
    1, // memRegion
    1, // hostPoolBase
    1, // hostPoolSize
    0
};
static int wtx_rt_info_slotOffsets[15];
static JWRAP_structs wtx_rt_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_rt_info],
  15,
  wtx_rt_info_slotNames,
  wtx_rt_info_slotTypes,
  wtx_rt_info_slotOffsets,
  wtx_rt_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_rt_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_rt_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_rt_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_rt_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_rt_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_rt_info_struct, tclObj);
}
// Build wtx_rt_info structure as a Tcl type
static Tcl_ObjType wtx_rt_info_type = {
  "wtx_rt_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_rt_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_rt_info
  };
// Build wtx_rt_info structure as a Tcl type
static Tcl_ObjType wtx_rt_info_ptr = {
  "wtx_rt_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_rt_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_rt_info
  };

// Alloc wtx_agent_info slot structure for Put/Get functions
static char *wtx_agent_info_slotNames[] =  {
    "agentVersion",
    "mtu",
    "mode",
    NULL
};
static JWRAP_types *wtx_agent_info_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // agentVersion 
    &usedType [JTYPE_UINT32], // mtu 
    &usedType [JTYPE_UINT32], // mode 
    NULL
};
static int wtx_agent_info_slotArrays[] = {
    1, // agentVersion
    1, // mtu
    1, // mode
    0
};
static int wtx_agent_info_slotOffsets[3];
static JWRAP_structs wtx_agent_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_agent_info],
  3,
  wtx_agent_info_slotNames,
  wtx_agent_info_slotTypes,
  wtx_agent_info_slotOffsets,
  wtx_agent_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_agent_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_agent_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_agent_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_agent_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_agent_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_agent_info_struct, tclObj);
}
// Build wtx_agent_info structure as a Tcl type
static Tcl_ObjType wtx_agent_info_type = {
  "wtx_agent_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_agent_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_agent_info
  };
// Build wtx_agent_info structure as a Tcl type
static Tcl_ObjType wtx_agent_info_ptr = {
  "wtx_agent_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_agent_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_agent_info
  };

// Alloc wtx_tgt_info slot structure for Put/Get functions
static char *wtx_tgt_info_slotNames[] =  {
    "agentInfo",
    "rtInfo",
    NULL
};
static JWRAP_types *wtx_tgt_info_slotTypes[] = {
    &usedType [JTYPE_WTX_AGENT_INFO], // agentInfo 
    &usedType [JTYPE_WTX_RT_INFO], // rtInfo 
    NULL
};
static int wtx_tgt_info_slotArrays[] = {
    1, // agentInfo
    1, // rtInfo
    0
};
static int wtx_tgt_info_slotOffsets[2];
static JWRAP_structs wtx_tgt_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_tgt_info],
  2,
  wtx_tgt_info_slotNames,
  wtx_tgt_info_slotTypes,
  wtx_tgt_info_slotOffsets,
  wtx_tgt_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_tgt_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_tgt_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_tgt_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_tgt_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_tgt_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_tgt_info_struct, tclObj);
}
// Build wtx_tgt_info structure as a Tcl type
static Tcl_ObjType wtx_tgt_info_type = {
  "wtx_tgt_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_tgt_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_tgt_info
  };
// Build wtx_tgt_info structure as a Tcl type
static Tcl_ObjType wtx_tgt_info_ptr = {
  "wtx_tgt_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_tgt_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_tgt_info
  };

// Alloc wtx_tgt_link_desc slot structure for Put/Get functions
static char *wtx_tgt_link_desc_slotNames[] =  {
    "name",
    "type",
    "speed",
    NULL
};
static JWRAP_types *wtx_tgt_link_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_UINT32], // type 
    &usedType [JTYPE_UINT32], // speed 
    NULL
};
static int wtx_tgt_link_desc_slotArrays[] = {
    1, // name
    1, // type
    1, // speed
    0
};
static int wtx_tgt_link_desc_slotOffsets[3];
static JWRAP_structs wtx_tgt_link_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_tgt_link_desc],
  3,
  wtx_tgt_link_desc_slotNames,
  wtx_tgt_link_desc_slotTypes,
  wtx_tgt_link_desc_slotOffsets,
  wtx_tgt_link_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_tgt_link_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_tgt_link_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_tgt_link_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_tgt_link_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_tgt_link_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_tgt_link_desc_struct, tclObj);
}
// Build wtx_tgt_link_desc structure as a Tcl type
static Tcl_ObjType wtx_tgt_link_desc_type = {
  "wtx_tgt_link_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_tgt_link_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_tgt_link_desc
  };
// Build wtx_tgt_link_desc structure as a Tcl type
static Tcl_ObjType wtx_tgt_link_desc_ptr = {
  "wtx_tgt_link_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_tgt_link_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_tgt_link_desc
  };

// Alloc wtx_tool_desc slot structure for Put/Get functions
static char *wtx_tool_desc_slotNames[] =  {
    "id",
    "toolName",
    "toolArgv",
    "toolVersion",
    "userName",
    "pReserved",
    "next",
    NULL
};
static JWRAP_types *wtx_tool_desc_slotTypes[] = {
    &usedType [JTYPE_UINT32], // id 
    &usedType [JTYPE_char_Ptr], // toolName 
    &usedType [JTYPE_char_Ptr], // toolArgv 
    &usedType [JTYPE_char_Ptr], // toolVersion 
    &usedType [JTYPE_char_Ptr], // userName 
    &usedType [JTYPE_void_Ptr], // pReserved 
    &usedType [JTYPE_wtx_tool_desc_Ptr], // next 
    NULL
};
static int wtx_tool_desc_slotArrays[] = {
    1, // id
    1, // toolName
    1, // toolArgv
    1, // toolVersion
    1, // userName
    1, // pReserved
    1, // next
    0
};
static int wtx_tool_desc_slotOffsets[7];
static JWRAP_structs wtx_tool_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_tool_desc],
  7,
  wtx_tool_desc_slotNames,
  wtx_tool_desc_slotTypes,
  wtx_tool_desc_slotOffsets,
  wtx_tool_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_tool_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_tool_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_tool_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_tool_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_tool_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_tool_desc_struct, tclObj);
}
// Build wtx_tool_desc structure as a Tcl type
static Tcl_ObjType wtx_tool_desc_type = {
  "wtx_tool_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_tool_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_tool_desc
  };
// Build wtx_tool_desc structure as a Tcl type
static Tcl_ObjType wtx_tool_desc_ptr = {
  "wtx_tool_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_tool_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_tool_desc
  };

// Alloc wtx_msg_ts_info slot structure for Put/Get functions
static char *wtx_msg_ts_info_slotNames[] =  {
    "wtxCore",
    "tgtLinkDesc",
    "tgtInfo",
    "pWtxToolDesc",
    "version",
    "userName",
    "startTime",
    "accessTime",
    "lockMsg",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_msg_ts_info_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_TGT_LINK_DESC], // tgtLinkDesc 
    &usedType [JTYPE_WTX_TGT_INFO], // tgtInfo 
    &usedType [JTYPE_WTX_TOOL_DESC_Ptr], // pWtxToolDesc 
    &usedType [JTYPE_char_Ptr], // version 
    &usedType [JTYPE_char_Ptr], // userName 
    &usedType [JTYPE_char_Ptr], // startTime 
    &usedType [JTYPE_char_Ptr], // accessTime 
    &usedType [JTYPE_char_Ptr], // lockMsg 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_msg_ts_info_slotArrays[] = {
    1, // wtxCore
    1, // tgtLinkDesc
    1, // tgtInfo
    1, // pWtxToolDesc
    1, // version
    1, // userName
    1, // startTime
    1, // accessTime
    1, // lockMsg
    1, // pReserved
    0
};
static int wtx_msg_ts_info_slotOffsets[10];
static JWRAP_structs wtx_msg_ts_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_ts_info],
  10,
  wtx_msg_ts_info_slotNames,
  wtx_msg_ts_info_slotTypes,
  wtx_msg_ts_info_slotOffsets,
  wtx_msg_ts_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_ts_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_ts_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_ts_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_ts_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_ts_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_ts_info_struct, tclObj);
}
// Build wtx_msg_ts_info structure as a Tcl type
static Tcl_ObjType wtx_msg_ts_info_type = {
  "wtx_msg_ts_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ts_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_ts_info
  };
// Build wtx_msg_ts_info structure as a Tcl type
static Tcl_ObjType wtx_msg_ts_info_ptr = {
  "wtx_msg_ts_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ts_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_ts_info
  };

// Alloc wtx_msg_ts_lock slot structure for Put/Get functions
static char *wtx_msg_ts_lock_slotNames[] =  {
    "wtxCore",
    "lockType",
    NULL
};
static JWRAP_types *wtx_msg_ts_lock_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // lockType 
    NULL
};
static int wtx_msg_ts_lock_slotArrays[] = {
    1, // wtxCore
    1, // lockType
    0
};
static int wtx_msg_ts_lock_slotOffsets[2];
static JWRAP_structs wtx_msg_ts_lock_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_ts_lock],
  2,
  wtx_msg_ts_lock_slotNames,
  wtx_msg_ts_lock_slotTypes,
  wtx_msg_ts_lock_slotOffsets,
  wtx_msg_ts_lock_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_ts_lock (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_ts_lock_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_ts_lock (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_ts_lock_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_ts_lock (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_ts_lock_struct, tclObj);
}
// Build wtx_msg_ts_lock structure as a Tcl type
static Tcl_ObjType wtx_msg_ts_lock_type = {
  "wtx_msg_ts_lock",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ts_lock,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_ts_lock
  };
// Build wtx_msg_ts_lock structure as a Tcl type
static Tcl_ObjType wtx_msg_ts_lock_ptr = {
  "wtx_msg_ts_lock_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ts_lock,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_ts_lock
  };

// Alloc wtx_msg_ts_unlock slot structure for Put/Get functions
static char *wtx_msg_ts_unlock_slotNames[] =  {
    "wtxCore",
    "force",
    NULL
};
static JWRAP_types *wtx_msg_ts_unlock_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_BOOL32], // force 
    NULL
};
static int wtx_msg_ts_unlock_slotArrays[] = {
    1, // wtxCore
    1, // force
    0
};
static int wtx_msg_ts_unlock_slotOffsets[2];
static JWRAP_structs wtx_msg_ts_unlock_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_ts_unlock],
  2,
  wtx_msg_ts_unlock_slotNames,
  wtx_msg_ts_unlock_slotTypes,
  wtx_msg_ts_unlock_slotOffsets,
  wtx_msg_ts_unlock_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_ts_unlock (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_ts_unlock_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_ts_unlock (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_ts_unlock_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_ts_unlock (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_ts_unlock_struct, tclObj);
}
// Build wtx_msg_ts_unlock structure as a Tcl type
static Tcl_ObjType wtx_msg_ts_unlock_type = {
  "wtx_msg_ts_unlock",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ts_unlock,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_ts_unlock
  };
// Build wtx_msg_ts_unlock structure as a Tcl type
static Tcl_ObjType wtx_msg_ts_unlock_ptr = {
  "wtx_msg_ts_unlock_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ts_unlock,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_ts_unlock
  };

// Alloc wtx_msg_tool_desc slot structure for Put/Get functions
static char *wtx_msg_tool_desc_slotNames[] =  {
    "wtxCore",
    "wtxToolDesc",
    NULL
};
static JWRAP_types *wtx_msg_tool_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_TOOL_DESC], // wtxToolDesc 
    NULL
};
static int wtx_msg_tool_desc_slotArrays[] = {
    1, // wtxCore
    1, // wtxToolDesc
    0
};
static int wtx_msg_tool_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_tool_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_tool_desc],
  2,
  wtx_msg_tool_desc_slotNames,
  wtx_msg_tool_desc_slotTypes,
  wtx_msg_tool_desc_slotOffsets,
  wtx_msg_tool_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_tool_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_tool_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_tool_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_tool_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_tool_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_tool_desc_struct, tclObj);
}
// Build wtx_msg_tool_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_tool_desc_type = {
  "wtx_msg_tool_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_tool_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_tool_desc
  };
// Build wtx_msg_tool_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_tool_desc_ptr = {
  "wtx_msg_tool_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_tool_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_tool_desc
  };

// Alloc wtx_msg_tool_id slot structure for Put/Get functions
static char *wtx_msg_tool_id_slotNames[] =  {
    "wtxCore",
    NULL
};
static JWRAP_types *wtx_msg_tool_id_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    NULL
};
static int wtx_msg_tool_id_slotArrays[] = {
    1, // wtxCore
    0
};
static int wtx_msg_tool_id_slotOffsets[1];
static JWRAP_structs wtx_msg_tool_id_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_tool_id],
  1,
  wtx_msg_tool_id_slotNames,
  wtx_msg_tool_id_slotTypes,
  wtx_msg_tool_id_slotOffsets,
  wtx_msg_tool_id_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_tool_id (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_tool_id_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_tool_id (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_tool_id_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_tool_id (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_tool_id_struct, tclObj);
}
// Build wtx_msg_tool_id structure as a Tcl type
static Tcl_ObjType wtx_msg_tool_id_type = {
  "wtx_msg_tool_id",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_tool_id,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_tool_id
  };
// Build wtx_msg_tool_id structure as a Tcl type
static Tcl_ObjType wtx_msg_tool_id_ptr = {
  "wtx_msg_tool_id_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_tool_id,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_tool_id
  };

// Alloc wtx_msg_kill_desc slot structure for Put/Get functions
static char *wtx_msg_kill_desc_slotNames[] =  {
    "wtxCore",
    "request",
    "arg",
    NULL
};
static JWRAP_types *wtx_msg_kill_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // request 
    &usedType [JTYPE_WTX_VALUE], // arg 
    NULL
};
static int wtx_msg_kill_desc_slotArrays[] = {
    1, // wtxCore
    1, // request
    1, // arg
    0
};
static int wtx_msg_kill_desc_slotOffsets[3];
static JWRAP_structs wtx_msg_kill_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_kill_desc],
  3,
  wtx_msg_kill_desc_slotNames,
  wtx_msg_kill_desc_slotTypes,
  wtx_msg_kill_desc_slotOffsets,
  wtx_msg_kill_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_kill_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_kill_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_kill_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_kill_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_kill_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_kill_desc_struct, tclObj);
}
// Build wtx_msg_kill_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_kill_desc_type = {
  "wtx_msg_kill_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_kill_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_kill_desc
  };
// Build wtx_msg_kill_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_kill_desc_ptr = {
  "wtx_msg_kill_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_kill_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_kill_desc
  };

// Alloc wtx_symbol slot structure for Put/Get functions
static char *wtx_symbol_slotNames[] =  {
    "status",
    "symTblId",
    "name",
    "exactName",
    "value",
    "type",
    "typeMask",
    "group",
    "moduleName",
    "pReserved",
    "next",
    NULL
};
static JWRAP_types *wtx_symbol_slotTypes[] = {
    &usedType [JTYPE_UINT32], // status 
    &usedType [JTYPE_UINT32], // symTblId 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_BOOL32], // exactName 
    &usedType [JTYPE_TGT_ADDR_T], // value 
    &usedType [JTYPE_UINT8], // type 
    &usedType [JTYPE_UINT8], // typeMask 
    &usedType [JTYPE_UINT16], // group 
    &usedType [JTYPE_char_Ptr], // moduleName 
    &usedType [JTYPE_void_Ptr], // pReserved 
    &usedType [JTYPE_wtx_symbol_Ptr], // next 
    NULL
};
static int wtx_symbol_slotArrays[] = {
    1, // status
    1, // symTblId
    1, // name
    1, // exactName
    1, // value
    1, // type
    1, // typeMask
    1, // group
    1, // moduleName
    1, // pReserved
    1, // next
    0
};
static int wtx_symbol_slotOffsets[11];
static JWRAP_structs wtx_symbol_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_symbol],
  11,
  wtx_symbol_slotNames,
  wtx_symbol_slotTypes,
  wtx_symbol_slotOffsets,
  wtx_symbol_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_symbol (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_symbol_struct, srcObj, destObj));
}
LOCAL int Put_wtx_symbol (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_symbol_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_symbol (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_symbol_struct, tclObj);
}
// Build wtx_symbol structure as a Tcl type
static Tcl_ObjType wtx_symbol_type = {
  "wtx_symbol",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_symbol,
  (Tcl_SetFromAnyProc*)      Put_wtx_symbol
  };
// Build wtx_symbol structure as a Tcl type
static Tcl_ObjType wtx_symbol_ptr = {
  "wtx_symbol_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_symbol,
  (Tcl_SetFromAnyProc*)      Create_wtx_symbol
  };

// Alloc wtx_msg_symbol_desc slot structure for Put/Get functions
static char *wtx_msg_symbol_desc_slotNames[] =  {
    "wtxCore",
    "symbol",
    NULL
};
static JWRAP_types *wtx_msg_symbol_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_SYMBOL], // symbol 
    NULL
};
static int wtx_msg_symbol_desc_slotArrays[] = {
    1, // wtxCore
    1, // symbol
    0
};
static int wtx_msg_symbol_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_symbol_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_symbol_desc],
  2,
  wtx_msg_symbol_desc_slotNames,
  wtx_msg_symbol_desc_slotTypes,
  wtx_msg_symbol_desc_slotOffsets,
  wtx_msg_symbol_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_symbol_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_symbol_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_symbol_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_symbol_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_symbol_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_symbol_desc_struct, tclObj);
}
// Build wtx_msg_symbol_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_symbol_desc_type = {
  "wtx_msg_symbol_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_symbol_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_symbol_desc
  };
// Build wtx_msg_symbol_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_symbol_desc_ptr = {
  "wtx_msg_symbol_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_symbol_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_symbol_desc
  };

// Alloc wtx_sym_list slot structure for Put/Get functions
static char *wtx_sym_list_slotNames[] =  {
    "pSymbol",
    NULL
};
static JWRAP_types *wtx_sym_list_slotTypes[] = {
    &usedType [JTYPE_WTX_SYMBOL_Ptr], // pSymbol 
    NULL
};
static int wtx_sym_list_slotArrays[] = {
    1, // pSymbol
    0
};
static int wtx_sym_list_slotOffsets[1];
static JWRAP_structs wtx_sym_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_sym_list],
  1,
  wtx_sym_list_slotNames,
  wtx_sym_list_slotTypes,
  wtx_sym_list_slotOffsets,
  wtx_sym_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_sym_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_sym_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_sym_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_sym_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_sym_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_sym_list_struct, tclObj);
}
// Build wtx_sym_list structure as a Tcl type
static Tcl_ObjType wtx_sym_list_type = {
  "wtx_sym_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_sym_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_sym_list
  };
// Build wtx_sym_list structure as a Tcl type
static Tcl_ObjType wtx_sym_list_ptr = {
  "wtx_sym_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_sym_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_sym_list
  };

// Alloc wtx_msg_sym_list slot structure for Put/Get functions
static char *wtx_msg_sym_list_slotNames[] =  {
    "wtxCore",
    "symList",
    "moreToCome",
    NULL
};
static JWRAP_types *wtx_msg_sym_list_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_SYM_LIST], // symList 
    &usedType [JTYPE_BOOL32], // moreToCome 
    NULL
};
static int wtx_msg_sym_list_slotArrays[] = {
    1, // wtxCore
    1, // symList
    1, // moreToCome
    0
};
static int wtx_msg_sym_list_slotOffsets[3];
static JWRAP_structs wtx_msg_sym_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_sym_list],
  3,
  wtx_msg_sym_list_slotNames,
  wtx_msg_sym_list_slotTypes,
  wtx_msg_sym_list_slotOffsets,
  wtx_msg_sym_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_sym_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_sym_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_sym_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_sym_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_sym_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_sym_list_struct, tclObj);
}
// Build wtx_msg_sym_list structure as a Tcl type
static Tcl_ObjType wtx_msg_sym_list_type = {
  "wtx_msg_sym_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_sym_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_sym_list
  };
// Build wtx_msg_sym_list structure as a Tcl type
static Tcl_ObjType wtx_msg_sym_list_ptr = {
  "wtx_msg_sym_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_sym_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_sym_list
  };

// Alloc wtx_msg_open_desc slot structure for Put/Get functions
static char *wtx_msg_open_desc_slotNames[] =  {
    "wtxCore",
    "filename",
    "flags",
    "mode",
    "channel",
    NULL
};
static JWRAP_types *wtx_msg_open_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_char_Ptr], // filename 
    &usedType [JTYPE_WTX_OPEN_FLAG], // flags 
    &usedType [JTYPE_INT32], // mode 
    &usedType [JTYPE_INT32], // channel 
    NULL
};
static int wtx_msg_open_desc_slotArrays[] = {
    1, // wtxCore
    1, // filename
    1, // flags
    1, // mode
    1, // channel
    0
};
static int wtx_msg_open_desc_slotOffsets[5];
static JWRAP_structs wtx_msg_open_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_open_desc],
  5,
  wtx_msg_open_desc_slotNames,
  wtx_msg_open_desc_slotTypes,
  wtx_msg_open_desc_slotOffsets,
  wtx_msg_open_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_open_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_open_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_open_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_open_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_open_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_open_desc_struct, tclObj);
}
// Build wtx_msg_open_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_open_desc_type = {
  "wtx_msg_open_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_open_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_open_desc
  };
// Build wtx_msg_open_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_open_desc_ptr = {
  "wtx_msg_open_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_open_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_open_desc
  };

// Alloc wtx_msg_vio_ctl_desc slot structure for Put/Get functions
static char *wtx_msg_vio_ctl_desc_slotNames[] =  {
    "wtxCore",
    "channel",
    "request",
    "arg",
    NULL
};
static JWRAP_types *wtx_msg_vio_ctl_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_INT32], // channel 
    &usedType [JTYPE_UINT32], // request 
    &usedType [JTYPE_UINT32], // arg 
    NULL
};
static int wtx_msg_vio_ctl_desc_slotArrays[] = {
    1, // wtxCore
    1, // channel
    1, // request
    1, // arg
    0
};
static int wtx_msg_vio_ctl_desc_slotOffsets[4];
static JWRAP_structs wtx_msg_vio_ctl_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_vio_ctl_desc],
  4,
  wtx_msg_vio_ctl_desc_slotNames,
  wtx_msg_vio_ctl_desc_slotTypes,
  wtx_msg_vio_ctl_desc_slotOffsets,
  wtx_msg_vio_ctl_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_vio_ctl_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_vio_ctl_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_vio_ctl_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_vio_ctl_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_vio_ctl_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_vio_ctl_desc_struct, tclObj);
}
// Build wtx_msg_vio_ctl_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_vio_ctl_desc_type = {
  "wtx_msg_vio_ctl_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_vio_ctl_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_vio_ctl_desc
  };
// Build wtx_msg_vio_ctl_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_vio_ctl_desc_ptr = {
  "wtx_msg_vio_ctl_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_vio_ctl_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_vio_ctl_desc
  };

// Alloc wtx_msg_vio_copy_desc slot structure for Put/Get functions
static char *wtx_msg_vio_copy_desc_slotNames[] =  {
    "wtxCore",
    "channel",
    "maxBytes",
    "baseAddr",
    NULL
};
static JWRAP_types *wtx_msg_vio_copy_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // channel 
    &usedType [JTYPE_UINT32], // maxBytes 
    &usedType [JTYPE_void_Ptr], // baseAddr 
    NULL
};
static int wtx_msg_vio_copy_desc_slotArrays[] = {
    1, // wtxCore
    1, // channel
    1, // maxBytes
    1, // baseAddr
    0
};
static int wtx_msg_vio_copy_desc_slotOffsets[4];
static JWRAP_structs wtx_msg_vio_copy_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_vio_copy_desc],
  4,
  wtx_msg_vio_copy_desc_slotNames,
  wtx_msg_vio_copy_desc_slotTypes,
  wtx_msg_vio_copy_desc_slotOffsets,
  wtx_msg_vio_copy_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_vio_copy_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_vio_copy_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_vio_copy_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_vio_copy_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_vio_copy_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_vio_copy_desc_struct, tclObj);
}
// Build wtx_msg_vio_copy_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_vio_copy_desc_type = {
  "wtx_msg_vio_copy_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_vio_copy_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_vio_copy_desc
  };
// Build wtx_msg_vio_copy_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_vio_copy_desc_ptr = {
  "wtx_msg_vio_copy_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_vio_copy_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_vio_copy_desc
  };

// Alloc wtx_vio_file_desc slot structure for Put/Get functions
static char *wtx_vio_file_desc_slotNames[] =  {
    "name",
    "fd",
    "channel",
    "fp",
    "type",
    "mode",
    "status",
    "addlInfo",
    "next",
    NULL
};
static JWRAP_types *wtx_vio_file_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_INT32], // fd 
    &usedType [JTYPE_INT32], // channel 
    &usedType [JTYPE_INT32], // fp 
    &usedType [JTYPE_INT32], // type 
    &usedType [JTYPE_INT32], // mode 
    &usedType [JTYPE_INT32], // status 
    &usedType [JTYPE_INT32], // addlInfo 
    &usedType [JTYPE_wtx_vio_file_desc_Ptr], // next 
    NULL
};
static int wtx_vio_file_desc_slotArrays[] = {
    1, // name
    1, // fd
    1, // channel
    1, // fp
    1, // type
    1, // mode
    1, // status
    1, // addlInfo
    1, // next
    0
};
static int wtx_vio_file_desc_slotOffsets[9];
static JWRAP_structs wtx_vio_file_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_vio_file_desc],
  9,
  wtx_vio_file_desc_slotNames,
  wtx_vio_file_desc_slotTypes,
  wtx_vio_file_desc_slotOffsets,
  wtx_vio_file_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_vio_file_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_vio_file_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_vio_file_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_vio_file_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_vio_file_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_vio_file_desc_struct, tclObj);
}
// Build wtx_vio_file_desc structure as a Tcl type
static Tcl_ObjType wtx_vio_file_desc_type = {
  "wtx_vio_file_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_vio_file_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_vio_file_desc
  };
// Build wtx_vio_file_desc structure as a Tcl type
static Tcl_ObjType wtx_vio_file_desc_ptr = {
  "wtx_vio_file_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_vio_file_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_vio_file_desc
  };

// Alloc wtx_msg_vio_file_list slot structure for Put/Get functions
static char *wtx_msg_vio_file_list_slotNames[] =  {
    "wtxCore",
    "pVioFileList",
    NULL
};
static JWRAP_types *wtx_msg_vio_file_list_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_VIO_FILE_DESC_Ptr], // pVioFileList 
    NULL
};
static int wtx_msg_vio_file_list_slotArrays[] = {
    1, // wtxCore
    1, // pVioFileList
    0
};
static int wtx_msg_vio_file_list_slotOffsets[2];
static JWRAP_structs wtx_msg_vio_file_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_vio_file_list],
  2,
  wtx_msg_vio_file_list_slotNames,
  wtx_msg_vio_file_list_slotTypes,
  wtx_msg_vio_file_list_slotOffsets,
  wtx_msg_vio_file_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_vio_file_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_vio_file_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_vio_file_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_vio_file_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_vio_file_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_vio_file_list_struct, tclObj);
}
// Build wtx_msg_vio_file_list structure as a Tcl type
static Tcl_ObjType wtx_msg_vio_file_list_type = {
  "wtx_msg_vio_file_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_vio_file_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_vio_file_list
  };
// Build wtx_msg_vio_file_list structure as a Tcl type
static Tcl_ObjType wtx_msg_vio_file_list_ptr = {
  "wtx_msg_vio_file_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_vio_file_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_vio_file_list
  };

// Alloc ld_m_section slot structure for Put/Get functions
static char *ld_m_section_slotNames[] =  {
    "flags",
    "addr",
    "length",
    NULL
};
static JWRAP_types *ld_m_section_slotTypes[] = {
    &usedType [JTYPE_UINT32], // flags 
    &usedType [JTYPE_TGT_ADDR_T], // addr 
    &usedType [JTYPE_UINT32], // length 
    NULL
};
static int ld_m_section_slotArrays[] = {
    1, // flags
    1, // addr
    1, // length
    0
};
static int ld_m_section_slotOffsets[3];
static JWRAP_structs ld_m_section_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_ld_m_section],
  3,
  ld_m_section_slotNames,
  ld_m_section_slotTypes,
  ld_m_section_slotOffsets,
  ld_m_section_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_ld_m_section (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &ld_m_section_struct, srcObj, destObj));
}
LOCAL int Put_ld_m_section (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &ld_m_section_struct, srcObj, destObj));
}
LOCAL char* Get_ld_m_section (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&ld_m_section_struct, tclObj);
}
// Build ld_m_section structure as a Tcl type
static Tcl_ObjType ld_m_section_type = {
  "ld_m_section",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_ld_m_section,
  (Tcl_SetFromAnyProc*)      Put_ld_m_section
  };
// Build ld_m_section structure as a Tcl type
static Tcl_ObjType ld_m_section_ptr = {
  "ld_m_section_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_ld_m_section,
  (Tcl_SetFromAnyProc*)      Create_ld_m_section
  };

// Alloc wtx_msg_ld_m_file_desc slot structure for Put/Get functions
static char *wtx_msg_ld_m_file_desc_slotNames[] =  {
    "wtxCore",
    "filename",
    "loadFlag",
    "moduleId",
    "nSections",
    "section",
    "undefSymList",
    NULL
};
static JWRAP_types *wtx_msg_ld_m_file_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_char_Ptr], // filename 
    &usedType [JTYPE_INT32], // loadFlag 
    &usedType [JTYPE_UINT32], // moduleId 
    &usedType [JTYPE_UINT32], // nSections 
    &usedType [JTYPE_LD_M_SECTION_Ptr], // section 
    &usedType [JTYPE_WTX_SYM_LIST], // undefSymList 
    NULL
};
static int wtx_msg_ld_m_file_desc_slotArrays[] = {
    1, // wtxCore
    1, // filename
    1, // loadFlag
    1, // moduleId
    1, // nSections
    1, // section
    1, // undefSymList
    0
};
static int wtx_msg_ld_m_file_desc_slotOffsets[7];
static JWRAP_structs wtx_msg_ld_m_file_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_ld_m_file_desc],
  7,
  wtx_msg_ld_m_file_desc_slotNames,
  wtx_msg_ld_m_file_desc_slotTypes,
  wtx_msg_ld_m_file_desc_slotOffsets,
  wtx_msg_ld_m_file_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_ld_m_file_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_ld_m_file_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_ld_m_file_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_ld_m_file_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_ld_m_file_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_ld_m_file_desc_struct, tclObj);
}
// Build wtx_msg_ld_m_file_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_ld_m_file_desc_type = {
  "wtx_msg_ld_m_file_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ld_m_file_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_ld_m_file_desc
  };
// Build wtx_msg_ld_m_file_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_ld_m_file_desc_ptr = {
  "wtx_msg_ld_m_file_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_ld_m_file_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_ld_m_file_desc
  };

// Alloc wtx_msg_module_list slot structure for Put/Get functions
static char *wtx_msg_module_list_slotNames[] =  {
    "wtxCore",
    "numObjMod",
    "modIdList",
    NULL
};
static JWRAP_types *wtx_msg_module_list_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // numObjMod 
    &usedType [JTYPE_UINT32_Ptr], // modIdList 
    NULL
};
static int wtx_msg_module_list_slotArrays[] = {
    1, // wtxCore
    1, // numObjMod
    1, // modIdList
    0
};
static int wtx_msg_module_list_slotOffsets[3];
static JWRAP_structs wtx_msg_module_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_module_list],
  3,
  wtx_msg_module_list_slotNames,
  wtx_msg_module_list_slotTypes,
  wtx_msg_module_list_slotOffsets,
  wtx_msg_module_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_module_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_module_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_module_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_module_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_module_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_module_list_struct, tclObj);
}
// Build wtx_msg_module_list structure as a Tcl type
static Tcl_ObjType wtx_msg_module_list_type = {
  "wtx_msg_module_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_module_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_module_list
  };
// Build wtx_msg_module_list structure as a Tcl type
static Tcl_ObjType wtx_msg_module_list_ptr = {
  "wtx_msg_module_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_module_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_module_list
  };

// Alloc obj_segment slot structure for Put/Get functions
static char *obj_segment_slotNames[] =  {
    "flags",
    "addr",
    "length",
    "reserved1",
    "reserved2",
    NULL
};
static JWRAP_types *obj_segment_slotTypes[] = {
    &usedType [JTYPE_UINT32], // flags 
    &usedType [JTYPE_TGT_ADDR_T], // addr 
    &usedType [JTYPE_UINT32], // length 
    &usedType [JTYPE_UINT32], // reserved1 
    &usedType [JTYPE_UINT32], // reserved2 
    NULL
};
static int obj_segment_slotArrays[] = {
    1, // flags
    1, // addr
    1, // length
    1, // reserved1
    1, // reserved2
    0
};
static int obj_segment_slotOffsets[5];
static JWRAP_structs obj_segment_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_obj_segment],
  5,
  obj_segment_slotNames,
  obj_segment_slotTypes,
  obj_segment_slotOffsets,
  obj_segment_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_obj_segment (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &obj_segment_struct, srcObj, destObj));
}
LOCAL int Put_obj_segment (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &obj_segment_struct, srcObj, destObj));
}
LOCAL char* Get_obj_segment (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&obj_segment_struct, tclObj);
}
// Build obj_segment structure as a Tcl type
static Tcl_ObjType obj_segment_type = {
  "obj_segment",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_obj_segment,
  (Tcl_SetFromAnyProc*)      Put_obj_segment
  };
// Build obj_segment structure as a Tcl type
static Tcl_ObjType obj_segment_ptr = {
  "obj_segment_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_obj_segment,
  (Tcl_SetFromAnyProc*)      Create_obj_segment
  };

// Alloc wtx_msg_module_info slot structure for Put/Get functions
static char *wtx_msg_module_info_slotNames[] =  {
    "wtxCore",
    "moduleId",
    "moduleName",
    "format",
    "group",
    "loadFlag",
    "nSegments",
    "segment",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_msg_module_info_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // moduleId 
    &usedType [JTYPE_char_Ptr], // moduleName 
    &usedType [JTYPE_char_Ptr], // format 
    &usedType [JTYPE_UINT32], // group 
    &usedType [JTYPE_int], // loadFlag 
    &usedType [JTYPE_UINT32], // nSegments 
    &usedType [JTYPE_OBJ_SEGMENT_Ptr], // segment 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_msg_module_info_slotArrays[] = {
    1, // wtxCore
    1, // moduleId
    1, // moduleName
    1, // format
    1, // group
    1, // loadFlag
    1, // nSegments
    1, // segment
    1, // pReserved
    0
};
static int wtx_msg_module_info_slotOffsets[9];
static JWRAP_structs wtx_msg_module_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_module_info],
  9,
  wtx_msg_module_info_slotNames,
  wtx_msg_module_info_slotTypes,
  wtx_msg_module_info_slotOffsets,
  wtx_msg_module_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_module_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_module_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_module_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_module_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_module_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_module_info_struct, tclObj);
}
// Build wtx_msg_module_info structure as a Tcl type
static Tcl_ObjType wtx_msg_module_info_type = {
  "wtx_msg_module_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_module_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_module_info
  };
// Build wtx_msg_module_info structure as a Tcl type
static Tcl_ObjType wtx_msg_module_info_ptr = {
  "wtx_msg_module_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_module_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_module_info
  };

// Alloc wtx_msg_mod_name_or_id slot structure for Put/Get functions
static char *wtx_msg_mod_name_or_id_slotNames[] =  {
    "wtxCore",
    "moduleId",
    "filename",
    NULL
};
static JWRAP_types *wtx_msg_mod_name_or_id_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // moduleId 
    &usedType [JTYPE_char_Ptr], // filename 
    NULL
};
static int wtx_msg_mod_name_or_id_slotArrays[] = {
    1, // wtxCore
    1, // moduleId
    1, // filename
    0
};
static int wtx_msg_mod_name_or_id_slotOffsets[3];
static JWRAP_structs wtx_msg_mod_name_or_id_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mod_name_or_id],
  3,
  wtx_msg_mod_name_or_id_slotNames,
  wtx_msg_mod_name_or_id_slotTypes,
  wtx_msg_mod_name_or_id_slotOffsets,
  wtx_msg_mod_name_or_id_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mod_name_or_id (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mod_name_or_id_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mod_name_or_id (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mod_name_or_id_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mod_name_or_id (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mod_name_or_id_struct, tclObj);
}
// Build wtx_msg_mod_name_or_id structure as a Tcl type
static Tcl_ObjType wtx_msg_mod_name_or_id_type = {
  "wtx_msg_mod_name_or_id",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mod_name_or_id,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mod_name_or_id
  };
// Build wtx_msg_mod_name_or_id structure as a Tcl type
static Tcl_ObjType wtx_msg_mod_name_or_id_ptr = {
  "wtx_msg_mod_name_or_id_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mod_name_or_id,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mod_name_or_id
  };

// Alloc wtx_sym_tbl_info slot structure for Put/Get functions
static char *wtx_sym_tbl_info_slotNames[] =  {
    "symTblId",
    "symNum",
    "sameNameOk",
    NULL
};
static JWRAP_types *wtx_sym_tbl_info_slotTypes[] = {
    &usedType [JTYPE_UINT32], // symTblId 
    &usedType [JTYPE_UINT32], // symNum 
    &usedType [JTYPE_BOOL32], // sameNameOk 
    NULL
};
static int wtx_sym_tbl_info_slotArrays[] = {
    1, // symTblId
    1, // symNum
    1, // sameNameOk
    0
};
static int wtx_sym_tbl_info_slotOffsets[3];
static JWRAP_structs wtx_sym_tbl_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_sym_tbl_info],
  3,
  wtx_sym_tbl_info_slotNames,
  wtx_sym_tbl_info_slotTypes,
  wtx_sym_tbl_info_slotOffsets,
  wtx_sym_tbl_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_sym_tbl_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_sym_tbl_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_sym_tbl_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_sym_tbl_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_sym_tbl_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_sym_tbl_info_struct, tclObj);
}
// Build wtx_sym_tbl_info structure as a Tcl type
static Tcl_ObjType wtx_sym_tbl_info_type = {
  "wtx_sym_tbl_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_sym_tbl_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_sym_tbl_info
  };
// Build wtx_sym_tbl_info structure as a Tcl type
static Tcl_ObjType wtx_sym_tbl_info_ptr = {
  "wtx_sym_tbl_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_sym_tbl_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_sym_tbl_info
  };

// Alloc wtx_msg_sym_tbl_info slot structure for Put/Get functions
static char *wtx_msg_sym_tbl_info_slotNames[] =  {
    "wtxCore",
    "symTblId",
    "symNum",
    "sameNameOk",
    NULL
};
static JWRAP_types *wtx_msg_sym_tbl_info_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // symTblId 
    &usedType [JTYPE_UINT32], // symNum 
    &usedType [JTYPE_BOOL32], // sameNameOk 
    NULL
};
static int wtx_msg_sym_tbl_info_slotArrays[] = {
    1, // wtxCore
    1, // symTblId
    1, // symNum
    1, // sameNameOk
    0
};
static int wtx_msg_sym_tbl_info_slotOffsets[4];
static JWRAP_structs wtx_msg_sym_tbl_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_sym_tbl_info],
  4,
  wtx_msg_sym_tbl_info_slotNames,
  wtx_msg_sym_tbl_info_slotTypes,
  wtx_msg_sym_tbl_info_slotOffsets,
  wtx_msg_sym_tbl_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_sym_tbl_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_sym_tbl_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_sym_tbl_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_sym_tbl_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_sym_tbl_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_sym_tbl_info_struct, tclObj);
}
// Build wtx_msg_sym_tbl_info structure as a Tcl type
static Tcl_ObjType wtx_msg_sym_tbl_info_type = {
  "wtx_msg_sym_tbl_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_sym_tbl_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_sym_tbl_info
  };
// Build wtx_msg_sym_tbl_info structure as a Tcl type
static Tcl_ObjType wtx_msg_sym_tbl_info_ptr = {
  "wtx_msg_sym_tbl_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_sym_tbl_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_sym_tbl_info
  };

// Alloc wtx_msg_sym_match_desc slot structure for Put/Get functions
static char *wtx_msg_sym_match_desc_slotNames[] =  {
    "wtxCore",
    "symTblId",
    "matchString",
    "adrs",
    "stringToMatch",
    "byModuleName",
    "module",
    "listUnknownSym",
    "giveMeNext",
    NULL
};
static JWRAP_types *wtx_msg_sym_match_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // symTblId 
    &usedType [JTYPE_BOOL32], // matchString 
    &usedType [JTYPE_TGT_ADDR_T], // adrs 
    &usedType [JTYPE_char_Ptr], // stringToMatch 
    &usedType [JTYPE_BOOL32], // byModuleName 
    &usedType [JTYPE_Union_Wtx_1], // module 
    &usedType [JTYPE_BOOL32], // listUnknownSym 
    &usedType [JTYPE_BOOL32], // giveMeNext 
    NULL
};
static int wtx_msg_sym_match_desc_slotArrays[] = {
    1, // wtxCore
    1, // symTblId
    1, // matchString
    1, // adrs
    1, // stringToMatch
    1, // byModuleName
    1, // module
    1, // listUnknownSym
    1, // giveMeNext
    0
};
static int wtx_msg_sym_match_desc_slotOffsets[9];
static JWRAP_structs wtx_msg_sym_match_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_sym_match_desc],
  9,
  wtx_msg_sym_match_desc_slotNames,
  wtx_msg_sym_match_desc_slotTypes,
  wtx_msg_sym_match_desc_slotOffsets,
  wtx_msg_sym_match_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_sym_match_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_sym_match_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_sym_match_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_sym_match_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_sym_match_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_sym_match_desc_struct, tclObj);
}
// Build wtx_msg_sym_match_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_sym_match_desc_type = {
  "wtx_msg_sym_match_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_sym_match_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_sym_match_desc
  };
// Build wtx_msg_sym_match_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_sym_match_desc_ptr = {
  "wtx_msg_sym_match_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_sym_match_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_sym_match_desc
  };

// Alloc wtx_event_desc slot structure for Put/Get functions
static char *wtx_event_desc_slotNames[] =  {
    "event",
    "addlDataLen",
    "addlData",
    NULL
};
static JWRAP_types *wtx_event_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // event 
    &usedType [JTYPE_INT32], // addlDataLen 
    &usedType [JTYPE_char_Ptr], // addlData 
    NULL
};
static int wtx_event_desc_slotArrays[] = {
    1, // event
    1, // addlDataLen
    1, // addlData
    0
};
static int wtx_event_desc_slotOffsets[3];
static JWRAP_structs wtx_event_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_event_desc],
  3,
  wtx_event_desc_slotNames,
  wtx_event_desc_slotTypes,
  wtx_event_desc_slotOffsets,
  wtx_event_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_event_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_event_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_event_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_event_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_event_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_event_desc_struct, tclObj);
}
// Build wtx_event_desc structure as a Tcl type
static Tcl_ObjType wtx_event_desc_type = {
  "wtx_event_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_event_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_event_desc
  };
// Build wtx_event_desc structure as a Tcl type
static Tcl_ObjType wtx_event_desc_ptr = {
  "wtx_event_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_event_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_event_desc
  };

// Alloc wtx_msg_event_desc slot structure for Put/Get functions
static char *wtx_msg_event_desc_slotNames[] =  {
    "wtxCore",
    "eventDesc",
    NULL
};
static JWRAP_types *wtx_msg_event_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_EVENT_DESC], // eventDesc 
    NULL
};
static int wtx_msg_event_desc_slotArrays[] = {
    1, // wtxCore
    1, // eventDesc
    0
};
static int wtx_msg_event_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_event_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_event_desc],
  2,
  wtx_msg_event_desc_slotNames,
  wtx_msg_event_desc_slotTypes,
  wtx_msg_event_desc_slotOffsets,
  wtx_msg_event_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_event_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_event_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_event_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_event_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_event_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_event_desc_struct, tclObj);
}
// Build wtx_msg_event_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_event_desc_type = {
  "wtx_msg_event_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_event_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_event_desc
  };
// Build wtx_msg_event_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_event_desc_ptr = {
  "wtx_msg_event_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_event_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_event_desc
  };

// Alloc wtx_msg_event_reg_desc slot structure for Put/Get functions
static char *wtx_msg_event_reg_desc_slotNames[] =  {
    "wtxCore",
    "evtRegExp",
    NULL
};
static JWRAP_types *wtx_msg_event_reg_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_char_Ptr], // evtRegExp 
    NULL
};
static int wtx_msg_event_reg_desc_slotArrays[] = {
    1, // wtxCore
    1, // evtRegExp
    0
};
static int wtx_msg_event_reg_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_event_reg_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_event_reg_desc],
  2,
  wtx_msg_event_reg_desc_slotNames,
  wtx_msg_event_reg_desc_slotTypes,
  wtx_msg_event_reg_desc_slotOffsets,
  wtx_msg_event_reg_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_event_reg_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_event_reg_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_event_reg_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_event_reg_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_event_reg_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_event_reg_desc_struct, tclObj);
}
// Build wtx_msg_event_reg_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_event_reg_desc_type = {
  "wtx_msg_event_reg_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_event_reg_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_event_reg_desc
  };
// Build wtx_msg_event_reg_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_event_reg_desc_ptr = {
  "wtx_msg_event_reg_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_event_reg_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_event_reg_desc
  };

// Alloc wtx_wdb_service_desc slot structure for Put/Get functions
static char *wtx_wdb_service_desc_slotNames[] =  {
    "rpcNum",
    "name",
    "svcObjFile",
    "initRtnName",
    NULL
};
static JWRAP_types *wtx_wdb_service_desc_slotTypes[] = {
    &usedType [JTYPE_UINT32], // rpcNum 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_char_Ptr], // svcObjFile 
    &usedType [JTYPE_char_Ptr], // initRtnName 
    NULL
};
static int wtx_wdb_service_desc_slotArrays[] = {
    1, // rpcNum
    1, // name
    1, // svcObjFile
    1, // initRtnName
    0
};
static int wtx_wdb_service_desc_slotOffsets[4];
static JWRAP_structs wtx_wdb_service_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_wdb_service_desc],
  4,
  wtx_wdb_service_desc_slotNames,
  wtx_wdb_service_desc_slotTypes,
  wtx_wdb_service_desc_slotOffsets,
  wtx_wdb_service_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_wdb_service_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_wdb_service_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_wdb_service_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_wdb_service_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_wdb_service_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_wdb_service_desc_struct, tclObj);
}
// Build wtx_wdb_service_desc structure as a Tcl type
static Tcl_ObjType wtx_wdb_service_desc_type = {
  "wtx_wdb_service_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_wdb_service_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_wdb_service_desc
  };
// Build wtx_wdb_service_desc structure as a Tcl type
static Tcl_ObjType wtx_wdb_service_desc_ptr = {
  "wtx_wdb_service_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_wdb_service_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_wdb_service_desc
  };

// Alloc wtx_wtx_service_desc slot structure for Put/Get functions
static char *wtx_wtx_service_desc_slotNames[] =  {
    "svcObjFile",
    "svcProcName",
    "inProcName",
    "outProcName",
    NULL
};
static JWRAP_types *wtx_wtx_service_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // svcObjFile 
    &usedType [JTYPE_char_Ptr], // svcProcName 
    &usedType [JTYPE_char_Ptr], // inProcName 
    &usedType [JTYPE_char_Ptr], // outProcName 
    NULL
};
static int wtx_wtx_service_desc_slotArrays[] = {
    1, // svcObjFile
    1, // svcProcName
    1, // inProcName
    1, // outProcName
    0
};
static int wtx_wtx_service_desc_slotOffsets[4];
static JWRAP_structs wtx_wtx_service_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_wtx_service_desc],
  4,
  wtx_wtx_service_desc_slotNames,
  wtx_wtx_service_desc_slotTypes,
  wtx_wtx_service_desc_slotOffsets,
  wtx_wtx_service_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_wtx_service_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_wtx_service_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_wtx_service_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_wtx_service_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_wtx_service_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_wtx_service_desc_struct, tclObj);
}
// Build wtx_wtx_service_desc structure as a Tcl type
static Tcl_ObjType wtx_wtx_service_desc_type = {
  "wtx_wtx_service_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_wtx_service_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_wtx_service_desc
  };
// Build wtx_wtx_service_desc structure as a Tcl type
static Tcl_ObjType wtx_wtx_service_desc_ptr = {
  "wtx_wtx_service_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_wtx_service_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_wtx_service_desc
  };

// Alloc wtx_msg_service_desc slot structure for Put/Get functions
static char *wtx_msg_service_desc_slotNames[] =  {
    "wtxCore",
    "pWtxServiceDesc",
    "pWdbServiceDesc",
    NULL
};
static JWRAP_types *wtx_msg_service_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_WTX_SERVICE_DESC_Ptr], // pWtxServiceDesc 
    &usedType [JTYPE_WTX_WDB_SERVICE_DESC_Ptr], // pWdbServiceDesc 
    NULL
};
static int wtx_msg_service_desc_slotArrays[] = {
    1, // wtxCore
    1, // pWtxServiceDesc
    1, // pWdbServiceDesc
    0
};
static int wtx_msg_service_desc_slotOffsets[3];
static JWRAP_structs wtx_msg_service_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_service_desc],
  3,
  wtx_msg_service_desc_slotNames,
  wtx_msg_service_desc_slotTypes,
  wtx_msg_service_desc_slotOffsets,
  wtx_msg_service_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_service_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_service_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_service_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_service_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_service_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_service_desc_struct, tclObj);
}
// Build wtx_msg_service_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_service_desc_type = {
  "wtx_msg_service_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_service_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_service_desc
  };
// Build wtx_msg_service_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_service_desc_ptr = {
  "wtx_msg_service_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_service_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_service_desc
  };

// Alloc wtx_msg_service_list slot structure for Put/Get functions
static char *wtx_msg_service_list_slotNames[] =  {
    "wtxCore",
    "nServices",
    "serviceDesc",
    NULL
};
static JWRAP_types *wtx_msg_service_list_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // nServices 
    &usedType [JTYPE_WTX_WDB_SERVICE_DESC_Ptr], // serviceDesc 
    NULL
};
static int wtx_msg_service_list_slotArrays[] = {
    1, // wtxCore
    1, // nServices
    1, // serviceDesc
    0
};
static int wtx_msg_service_list_slotOffsets[3];
static JWRAP_structs wtx_msg_service_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_service_list],
  3,
  wtx_msg_service_list_slotNames,
  wtx_msg_service_list_slotTypes,
  wtx_msg_service_list_slotOffsets,
  wtx_msg_service_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_service_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_service_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_service_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_service_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_service_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_service_list_struct, tclObj);
}
// Build wtx_msg_service_list structure as a Tcl type
static Tcl_ObjType wtx_msg_service_list_type = {
  "wtx_msg_service_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_service_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_service_list
  };
// Build wtx_msg_service_list structure as a Tcl type
static Tcl_ObjType wtx_msg_service_list_ptr = {
  "wtx_msg_service_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_service_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_service_list
  };

// Alloc wtx_console_desc slot structure for Put/Get functions
static char *wtx_console_desc_slotNames[] =  {
    "fdIn",
    "fdOut",
    "pid",
    "name",
    "display",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_console_desc_slotTypes[] = {
    &usedType [JTYPE_INT32], // fdIn 
    &usedType [JTYPE_INT32], // fdOut 
    &usedType [JTYPE_INT32], // pid 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_char_Ptr], // display 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_console_desc_slotArrays[] = {
    1, // fdIn
    1, // fdOut
    1, // pid
    1, // name
    1, // display
    1, // pReserved
    0
};
static int wtx_console_desc_slotOffsets[6];
static JWRAP_structs wtx_console_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_console_desc],
  6,
  wtx_console_desc_slotNames,
  wtx_console_desc_slotTypes,
  wtx_console_desc_slotOffsets,
  wtx_console_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_console_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_console_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_console_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_console_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_console_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_console_desc_struct, tclObj);
}
// Build wtx_console_desc structure as a Tcl type
static Tcl_ObjType wtx_console_desc_type = {
  "wtx_console_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_console_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_console_desc
  };
// Build wtx_console_desc structure as a Tcl type
static Tcl_ObjType wtx_console_desc_ptr = {
  "wtx_console_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_console_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_console_desc
  };

// Alloc wtx_msg_console_desc slot structure for Put/Get functions
static char *wtx_msg_console_desc_slotNames[] =  {
    "wtxCore",
    "wtxConsDesc",
    NULL
};
static JWRAP_types *wtx_msg_console_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_CONSOLE_DESC], // wtxConsDesc 
    NULL
};
static int wtx_msg_console_desc_slotArrays[] = {
    1, // wtxCore
    1, // wtxConsDesc
    0
};
static int wtx_msg_console_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_console_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_console_desc],
  2,
  wtx_msg_console_desc_slotNames,
  wtx_msg_console_desc_slotTypes,
  wtx_msg_console_desc_slotOffsets,
  wtx_msg_console_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_console_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_console_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_console_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_console_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_console_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_console_desc_struct, tclObj);
}
// Build wtx_msg_console_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_console_desc_type = {
  "wtx_msg_console_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_console_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_console_desc
  };
// Build wtx_msg_console_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_console_desc_ptr = {
  "wtx_msg_console_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_console_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_console_desc
  };

// Alloc wtx_msg_mem_info slot structure for Put/Get functions
static char *wtx_msg_mem_info_slotNames[] =  {
    "wtxCore",
    "curBytesFree",
    "curBytesAllocated",
    "cumBytesAllocated",
    "curBlocksFree",
    "curBlocksAlloc",
    "cumBlocksAlloc",
    "avgFreeBlockSize",
    "avgAllocBlockSize",
    "cumAvgAllocBlockSize",
    "biggestBlockSize",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_msg_mem_info_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // curBytesFree 
    &usedType [JTYPE_UINT32], // curBytesAllocated 
    &usedType [JTYPE_UINT32], // cumBytesAllocated 
    &usedType [JTYPE_UINT32], // curBlocksFree 
    &usedType [JTYPE_UINT32], // curBlocksAlloc 
    &usedType [JTYPE_UINT32], // cumBlocksAlloc 
    &usedType [JTYPE_UINT32], // avgFreeBlockSize 
    &usedType [JTYPE_UINT32], // avgAllocBlockSize 
    &usedType [JTYPE_UINT32], // cumAvgAllocBlockSize 
    &usedType [JTYPE_UINT32], // biggestBlockSize 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_msg_mem_info_slotArrays[] = {
    1, // wtxCore
    1, // curBytesFree
    1, // curBytesAllocated
    1, // cumBytesAllocated
    1, // curBlocksFree
    1, // curBlocksAlloc
    1, // cumBlocksAlloc
    1, // avgFreeBlockSize
    1, // avgAllocBlockSize
    1, // cumAvgAllocBlockSize
    1, // biggestBlockSize
    1, // pReserved
    0
};
static int wtx_msg_mem_info_slotOffsets[12];
static JWRAP_structs wtx_msg_mem_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_info],
  12,
  wtx_msg_mem_info_slotNames,
  wtx_msg_mem_info_slotTypes,
  wtx_msg_mem_info_slotOffsets,
  wtx_msg_mem_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_info_struct, tclObj);
}
// Build wtx_msg_mem_info structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_info_type = {
  "wtx_msg_mem_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_info
  };
// Build wtx_msg_mem_info structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_info_ptr = {
  "wtx_msg_mem_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_info
  };

// Alloc wtx_mem_xfer slot structure for Put/Get functions
static char *wtx_mem_xfer_slotNames[] =  {
    "numBytes",
    "destination",
    "source",
    NULL
};
static JWRAP_types *wtx_mem_xfer_slotTypes[] = {
    &usedType [JTYPE_UINT32], // numBytes 
    &usedType [JTYPE_TGT_ADDR_T], // destination 
    &usedType [JTYPE_char_Ptr], // source 
    NULL
};
static int wtx_mem_xfer_slotArrays[] = {
    1, // numBytes
    1, // destination
    1, // source
    0
};
static int wtx_mem_xfer_slotOffsets[3];
static JWRAP_structs wtx_mem_xfer_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_mem_xfer],
  3,
  wtx_mem_xfer_slotNames,
  wtx_mem_xfer_slotTypes,
  wtx_mem_xfer_slotOffsets,
  wtx_mem_xfer_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_mem_xfer (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_mem_xfer_struct, srcObj, destObj));
}
LOCAL int Put_wtx_mem_xfer (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_mem_xfer_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_mem_xfer (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_mem_xfer_struct, tclObj);
}
// Build wtx_mem_xfer structure as a Tcl type
static Tcl_ObjType wtx_mem_xfer_type = {
  "wtx_mem_xfer",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_mem_xfer,
  (Tcl_SetFromAnyProc*)      Put_wtx_mem_xfer
  };
// Build wtx_mem_xfer structure as a Tcl type
static Tcl_ObjType wtx_mem_xfer_ptr = {
  "wtx_mem_xfer_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_mem_xfer,
  (Tcl_SetFromAnyProc*)      Create_wtx_mem_xfer
  };

// Alloc wtx_msg_mem_xfer_desc slot structure for Put/Get functions
static char *wtx_msg_mem_xfer_desc_slotNames[] =  {
    "wtxCore",
    "memXfer",
    NULL
};
static JWRAP_types *wtx_msg_mem_xfer_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_MEM_XFER], // memXfer 
    NULL
};
static int wtx_msg_mem_xfer_desc_slotArrays[] = {
    1, // wtxCore
    1, // memXfer
    0
};
static int wtx_msg_mem_xfer_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_mem_xfer_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_xfer_desc],
  2,
  wtx_msg_mem_xfer_desc_slotNames,
  wtx_msg_mem_xfer_desc_slotTypes,
  wtx_msg_mem_xfer_desc_slotOffsets,
  wtx_msg_mem_xfer_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_xfer_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_xfer_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_xfer_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_xfer_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_xfer_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_xfer_desc_struct, tclObj);
}
// Build wtx_msg_mem_xfer_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_xfer_desc_type = {
  "wtx_msg_mem_xfer_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_xfer_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_xfer_desc
  };
// Build wtx_msg_mem_xfer_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_xfer_desc_ptr = {
  "wtx_msg_mem_xfer_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_xfer_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_xfer_desc
  };

// Alloc wtx_event slot structure for Put/Get functions
static char *wtx_event_slotNames[] =  {
    "eventType",
    "eventArg",
    NULL
};
static JWRAP_types *wtx_event_slotTypes[] = {
    &usedType [JTYPE_WTX_EVENT_TYPE], // eventType 
    &usedType [JTYPE_TGT_ARG_T], // eventArg 
    NULL
};
static int wtx_event_slotArrays[] = {
    1, // eventType
    1, // eventArg
    0
};
static int wtx_event_slotOffsets[2];
static JWRAP_structs wtx_event_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_event],
  2,
  wtx_event_slotNames,
  wtx_event_slotTypes,
  wtx_event_slotOffsets,
  wtx_event_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_event (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_event_struct, srcObj, destObj));
}
LOCAL int Put_wtx_event (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_event_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_event (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_event_struct, tclObj);
}
// Build wtx_event structure as a Tcl type
static Tcl_ObjType wtx_event_type = {
  "wtx_event",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_event,
  (Tcl_SetFromAnyProc*)      Put_wtx_event
  };
// Build wtx_event structure as a Tcl type
static Tcl_ObjType wtx_event_ptr = {
  "wtx_event_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_event,
  (Tcl_SetFromAnyProc*)      Create_wtx_event
  };

// Alloc wtx_context slot structure for Put/Get functions
static char *wtx_context_slotNames[] =  {
    "contextType",
    "contextId",
    NULL
};
static JWRAP_types *wtx_context_slotTypes[] = {
    &usedType [JTYPE_WTX_CONTEXT_TYPE], // contextType 
    &usedType [JTYPE_WTX_CONTEXT_ID_T], // contextId 
    NULL
};
static int wtx_context_slotArrays[] = {
    1, // contextType
    1, // contextId
    0
};
static int wtx_context_slotOffsets[2];
static JWRAP_structs wtx_context_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_context],
  2,
  wtx_context_slotNames,
  wtx_context_slotTypes,
  wtx_context_slotOffsets,
  wtx_context_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_context (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_context_struct, srcObj, destObj));
}
LOCAL int Put_wtx_context (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_context_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_context (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_context_struct, tclObj);
}
// Build wtx_context structure as a Tcl type
static Tcl_ObjType wtx_context_type = {
  "wtx_context",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_context,
  (Tcl_SetFromAnyProc*)      Put_wtx_context
  };
// Build wtx_context structure as a Tcl type
static Tcl_ObjType wtx_context_ptr = {
  "wtx_context_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_context,
  (Tcl_SetFromAnyProc*)      Create_wtx_context
  };

// Alloc wtx_action slot structure for Put/Get functions
static char *wtx_action_slotNames[] =  {
    "actionType",
    "actionArg",
    "callRtn",
    "callArg",
    NULL
};
static JWRAP_types *wtx_action_slotTypes[] = {
    &usedType [JTYPE_WTX_ACTION_TYPE], // actionType 
    &usedType [JTYPE_UINT32], // actionArg 
    &usedType [JTYPE_TGT_ADDR_T], // callRtn 
    &usedType [JTYPE_TGT_ARG_T], // callArg 
    NULL
};
static int wtx_action_slotArrays[] = {
    1, // actionType
    1, // actionArg
    1, // callRtn
    1, // callArg
    0
};
static int wtx_action_slotOffsets[4];
static JWRAP_structs wtx_action_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_action],
  4,
  wtx_action_slotNames,
  wtx_action_slotTypes,
  wtx_action_slotOffsets,
  wtx_action_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_action (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_action_struct, srcObj, destObj));
}
LOCAL int Put_wtx_action (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_action_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_action (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_action_struct, tclObj);
}
// Build wtx_action structure as a Tcl type
static Tcl_ObjType wtx_action_type = {
  "wtx_action",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_action,
  (Tcl_SetFromAnyProc*)      Put_wtx_action
  };
// Build wtx_action structure as a Tcl type
static Tcl_ObjType wtx_action_ptr = {
  "wtx_action_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_action,
  (Tcl_SetFromAnyProc*)      Create_wtx_action
  };

// Alloc wtx_msg_context slot structure for Put/Get functions
static char *wtx_msg_context_slotNames[] =  {
    "wtxCore",
    "contextType",
    "contextId",
    NULL
};
static JWRAP_types *wtx_msg_context_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_CONTEXT_TYPE], // contextType 
    &usedType [JTYPE_WTX_CONTEXT_ID_T], // contextId 
    NULL
};
static int wtx_msg_context_slotArrays[] = {
    1, // wtxCore
    1, // contextType
    1, // contextId
    0
};
static int wtx_msg_context_slotOffsets[3];
static JWRAP_structs wtx_msg_context_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_context],
  3,
  wtx_msg_context_slotNames,
  wtx_msg_context_slotTypes,
  wtx_msg_context_slotOffsets,
  wtx_msg_context_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_context (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_context_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_context (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_context_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_context (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_context_struct, tclObj);
}
// Build wtx_msg_context structure as a Tcl type
static Tcl_ObjType wtx_msg_context_type = {
  "wtx_msg_context",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_context,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_context
  };
// Build wtx_msg_context structure as a Tcl type
static Tcl_ObjType wtx_msg_context_ptr = {
  "wtx_msg_context_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_context,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_context
  };

// Alloc wtx_evtpt slot structure for Put/Get functions
static char *wtx_evtpt_slotNames[] =  {
    "event",
    "context",
    "action",
    NULL
};
static JWRAP_types *wtx_evtpt_slotTypes[] = {
    &usedType [JTYPE_WTX_EVENT], // event 
    &usedType [JTYPE_WTX_CONTEXT], // context 
    &usedType [JTYPE_WTX_ACTION], // action 
    NULL
};
static int wtx_evtpt_slotArrays[] = {
    1, // event
    1, // context
    1, // action
    0
};
static int wtx_evtpt_slotOffsets[3];
static JWRAP_structs wtx_evtpt_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_evtpt],
  3,
  wtx_evtpt_slotNames,
  wtx_evtpt_slotTypes,
  wtx_evtpt_slotOffsets,
  wtx_evtpt_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_evtpt (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_evtpt_struct, srcObj, destObj));
}
LOCAL int Put_wtx_evtpt (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_evtpt_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_evtpt (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_evtpt_struct, tclObj);
}
// Build wtx_evtpt structure as a Tcl type
static Tcl_ObjType wtx_evtpt_type = {
  "wtx_evtpt",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_evtpt,
  (Tcl_SetFromAnyProc*)      Put_wtx_evtpt
  };
// Build wtx_evtpt structure as a Tcl type
static Tcl_ObjType wtx_evtpt_ptr = {
  "wtx_evtpt_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_evtpt,
  (Tcl_SetFromAnyProc*)      Create_wtx_evtpt
  };

// Alloc wtx_msg_evtpt_desc slot structure for Put/Get functions
static char *wtx_msg_evtpt_desc_slotNames[] =  {
    "wtxCore",
    "wtxEvtpt",
    NULL
};
static JWRAP_types *wtx_msg_evtpt_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_EVTPT], // wtxEvtpt 
    NULL
};
static int wtx_msg_evtpt_desc_slotArrays[] = {
    1, // wtxCore
    1, // wtxEvtpt
    0
};
static int wtx_msg_evtpt_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_evtpt_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_evtpt_desc],
  2,
  wtx_msg_evtpt_desc_slotNames,
  wtx_msg_evtpt_desc_slotTypes,
  wtx_msg_evtpt_desc_slotOffsets,
  wtx_msg_evtpt_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_evtpt_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_evtpt_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_evtpt_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_evtpt_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_evtpt_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_evtpt_desc_struct, tclObj);
}
// Build wtx_msg_evtpt_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_evtpt_desc_type = {
  "wtx_msg_evtpt_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_evtpt_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_evtpt_desc
  };
// Build wtx_msg_evtpt_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_evtpt_desc_ptr = {
  "wtx_msg_evtpt_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_evtpt_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_evtpt_desc
  };

// Alloc wtx_msg_evtpt_list slot structure for Put/Get functions
static char *wtx_msg_evtpt_list_slotNames[] =  {
    "wtxCore",
    "nEvtpt",
    "pEvtpt",
    NULL
};
static JWRAP_types *wtx_msg_evtpt_list_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // nEvtpt 
    &usedType [JTYPE_WTX_EVTPT_Ptr], // pEvtpt 
    NULL
};
static int wtx_msg_evtpt_list_slotArrays[] = {
    1, // wtxCore
    1, // nEvtpt
    1, // pEvtpt
    0
};
static int wtx_msg_evtpt_list_slotOffsets[3];
static JWRAP_structs wtx_msg_evtpt_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_evtpt_list],
  3,
  wtx_msg_evtpt_list_slotNames,
  wtx_msg_evtpt_list_slotTypes,
  wtx_msg_evtpt_list_slotOffsets,
  wtx_msg_evtpt_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_evtpt_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_evtpt_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_evtpt_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_evtpt_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_evtpt_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_evtpt_list_struct, tclObj);
}
// Build wtx_msg_evtpt_list structure as a Tcl type
static Tcl_ObjType wtx_msg_evtpt_list_type = {
  "wtx_msg_evtpt_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_evtpt_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_evtpt_list
  };
// Build wtx_msg_evtpt_list structure as a Tcl type
static Tcl_ObjType wtx_msg_evtpt_list_ptr = {
  "wtx_msg_evtpt_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_evtpt_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_evtpt_list
  };

// Alloc wtx_msg_reg_write slot structure for Put/Get functions
static char *wtx_msg_reg_write_slotNames[] =  {
    "wtxCore",
    "regSetType",
    "context",
    "memXfer",
    NULL
};
static JWRAP_types *wtx_msg_reg_write_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_REG_SET_TYPE], // regSetType 
    &usedType [JTYPE_WTX_CONTEXT], // context 
    &usedType [JTYPE_WTX_MEM_XFER], // memXfer 
    NULL
};
static int wtx_msg_reg_write_slotArrays[] = {
    1, // wtxCore
    1, // regSetType
    1, // context
    1, // memXfer
    0
};
static int wtx_msg_reg_write_slotOffsets[4];
static JWRAP_structs wtx_msg_reg_write_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_reg_write],
  4,
  wtx_msg_reg_write_slotNames,
  wtx_msg_reg_write_slotTypes,
  wtx_msg_reg_write_slotOffsets,
  wtx_msg_reg_write_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_reg_write (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_reg_write_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_reg_write (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_reg_write_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_reg_write (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_reg_write_struct, tclObj);
}
// Build wtx_msg_reg_write structure as a Tcl type
static Tcl_ObjType wtx_msg_reg_write_type = {
  "wtx_msg_reg_write",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_reg_write,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_reg_write
  };
// Build wtx_msg_reg_write structure as a Tcl type
static Tcl_ObjType wtx_msg_reg_write_ptr = {
  "wtx_msg_reg_write_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_reg_write,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_reg_write
  };

// Alloc WTX_MSG_REG_READ slot structure for Put/Get functions
static char *WTX_MSG_REG_READ_slotNames[] =  {
    "wtxCore",
    "regSetType",
    "context",
    "memRegion",
    NULL
};
static JWRAP_types *WTX_MSG_REG_READ_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_REG_SET_TYPE], // regSetType 
    &usedType [JTYPE_WTX_CONTEXT], // context 
    &usedType [JTYPE_WTX_MEM_REGION], // memRegion 
    NULL
};
static int WTX_MSG_REG_READ_slotArrays[] = {
    1, // wtxCore
    1, // regSetType
    1, // context
    1, // memRegion
    0
};
static int WTX_MSG_REG_READ_slotOffsets[4];
static JWRAP_structs WTX_MSG_REG_READ_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_WTX_MSG_REG_READ],
  4,
  WTX_MSG_REG_READ_slotNames,
  WTX_MSG_REG_READ_slotTypes,
  WTX_MSG_REG_READ_slotOffsets,
  WTX_MSG_REG_READ_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_WTX_MSG_REG_READ (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &WTX_MSG_REG_READ_struct, srcObj, destObj));
}
LOCAL int Put_WTX_MSG_REG_READ (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &WTX_MSG_REG_READ_struct, srcObj, destObj));
}
LOCAL char* Get_WTX_MSG_REG_READ (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&WTX_MSG_REG_READ_struct, tclObj);
}
// Build WTX_MSG_REG_READ structure as a Tcl type
static Tcl_ObjType WTX_MSG_REG_READ_type = {
  "WTX_MSG_REG_READ",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_WTX_MSG_REG_READ,
  (Tcl_SetFromAnyProc*)      Put_WTX_MSG_REG_READ
  };
// Build WTX_MSG_REG_READ structure as a Tcl type
static Tcl_ObjType WTX_MSG_REG_READ_ptr = {
  "WTX_MSG_REG_READ_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_WTX_MSG_REG_READ,
  (Tcl_SetFromAnyProc*)      Create_WTX_MSG_REG_READ
  };

// Alloc wtx_msg_mem_block_desc slot structure for Put/Get functions
static char *wtx_msg_mem_block_desc_slotNames[] =  {
    "wtxCore",
    "startAddr",
    "numBytes",
    NULL
};
static JWRAP_types *wtx_msg_mem_block_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_TGT_ADDR_T], // startAddr 
    &usedType [JTYPE_UINT32], // numBytes 
    NULL
};
static int wtx_msg_mem_block_desc_slotArrays[] = {
    1, // wtxCore
    1, // startAddr
    1, // numBytes
    0
};
static int wtx_msg_mem_block_desc_slotOffsets[3];
static JWRAP_structs wtx_msg_mem_block_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_block_desc],
  3,
  wtx_msg_mem_block_desc_slotNames,
  wtx_msg_mem_block_desc_slotTypes,
  wtx_msg_mem_block_desc_slotOffsets,
  wtx_msg_mem_block_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_block_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_block_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_block_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_block_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_block_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_block_desc_struct, tclObj);
}
// Build wtx_msg_mem_block_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_block_desc_type = {
  "wtx_msg_mem_block_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_block_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_block_desc
  };
// Build wtx_msg_mem_block_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_block_desc_ptr = {
  "wtx_msg_mem_block_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_block_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_block_desc
  };

// Alloc wtx_msg_mem_read_desc slot structure for Put/Get functions
static char *wtx_msg_mem_read_desc_slotNames[] =  {
    "wtxCore",
    "source",
    "destination",
    "numBytes",
    NULL
};
static JWRAP_types *wtx_msg_mem_read_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_TGT_ADDR_T], // source 
    &usedType [JTYPE_UINT32], // destination 
    &usedType [JTYPE_UINT32], // numBytes 
    NULL
};
static int wtx_msg_mem_read_desc_slotArrays[] = {
    1, // wtxCore
    1, // source
    1, // destination
    1, // numBytes
    0
};
static int wtx_msg_mem_read_desc_slotOffsets[4];
static JWRAP_structs wtx_msg_mem_read_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_read_desc],
  4,
  wtx_msg_mem_read_desc_slotNames,
  wtx_msg_mem_read_desc_slotTypes,
  wtx_msg_mem_read_desc_slotOffsets,
  wtx_msg_mem_read_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_read_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_read_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_read_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_read_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_read_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_read_desc_struct, tclObj);
}
// Build wtx_msg_mem_read_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_read_desc_type = {
  "wtx_msg_mem_read_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_read_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_read_desc
  };
// Build wtx_msg_mem_read_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_read_desc_ptr = {
  "wtx_msg_mem_read_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_read_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_read_desc
  };

// Alloc wtx_msg_mem_copy_desc slot structure for Put/Get functions
static char *wtx_msg_mem_copy_desc_slotNames[] =  {
    "wtxCore",
    "source",
    "destination",
    "numBytes",
    NULL
};
static JWRAP_types *wtx_msg_mem_copy_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // source 
    &usedType [JTYPE_TGT_ADDR_T], // destination 
    &usedType [JTYPE_UINT32], // numBytes 
    NULL
};
static int wtx_msg_mem_copy_desc_slotArrays[] = {
    1, // wtxCore
    1, // source
    1, // destination
    1, // numBytes
    0
};
static int wtx_msg_mem_copy_desc_slotOffsets[4];
static JWRAP_structs wtx_msg_mem_copy_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_copy_desc],
  4,
  wtx_msg_mem_copy_desc_slotNames,
  wtx_msg_mem_copy_desc_slotTypes,
  wtx_msg_mem_copy_desc_slotOffsets,
  wtx_msg_mem_copy_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_copy_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_copy_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_copy_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_copy_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_copy_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_copy_desc_struct, tclObj);
}
// Build wtx_msg_mem_copy_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_copy_desc_type = {
  "wtx_msg_mem_copy_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_copy_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_copy_desc
  };
// Build wtx_msg_mem_copy_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_copy_desc_ptr = {
  "wtx_msg_mem_copy_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_copy_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_copy_desc
  };

// Alloc wtx_msg_mem_scan_desc slot structure for Put/Get functions
static char *wtx_msg_mem_scan_desc_slotNames[] =  {
    "wtxCore",
    "match",
    "startAddr",
    "endAddr",
    "numBytes",
    "pattern",
    NULL
};
static JWRAP_types *wtx_msg_mem_scan_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_BOOL32], // match 
    &usedType [JTYPE_TGT_ADDR_T], // startAddr 
    &usedType [JTYPE_TGT_ADDR_T], // endAddr 
    &usedType [JTYPE_UINT32], // numBytes 
    &usedType [JTYPE_void_Ptr], // pattern 
    NULL
};
static int wtx_msg_mem_scan_desc_slotArrays[] = {
    1, // wtxCore
    1, // match
    1, // startAddr
    1, // endAddr
    1, // numBytes
    1, // pattern
    0
};
static int wtx_msg_mem_scan_desc_slotOffsets[6];
static JWRAP_structs wtx_msg_mem_scan_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_scan_desc],
  6,
  wtx_msg_mem_scan_desc_slotNames,
  wtx_msg_mem_scan_desc_slotTypes,
  wtx_msg_mem_scan_desc_slotOffsets,
  wtx_msg_mem_scan_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_scan_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_scan_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_scan_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_scan_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_scan_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_scan_desc_struct, tclObj);
}
// Build wtx_msg_mem_scan_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_scan_desc_type = {
  "wtx_msg_mem_scan_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_scan_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_scan_desc
  };
// Build wtx_msg_mem_scan_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_scan_desc_ptr = {
  "wtx_msg_mem_scan_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_scan_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_scan_desc
  };

// Alloc wtx_msg_mem_move_desc slot structure for Put/Get functions
static char *wtx_msg_mem_move_desc_slotNames[] =  {
    "wtxCore",
    "source",
    "destination",
    "numBytes",
    NULL
};
static JWRAP_types *wtx_msg_mem_move_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_TGT_ADDR_T], // source 
    &usedType [JTYPE_TGT_ADDR_T], // destination 
    &usedType [JTYPE_UINT32], // numBytes 
    NULL
};
static int wtx_msg_mem_move_desc_slotArrays[] = {
    1, // wtxCore
    1, // source
    1, // destination
    1, // numBytes
    0
};
static int wtx_msg_mem_move_desc_slotOffsets[4];
static JWRAP_structs wtx_msg_mem_move_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_move_desc],
  4,
  wtx_msg_mem_move_desc_slotNames,
  wtx_msg_mem_move_desc_slotTypes,
  wtx_msg_mem_move_desc_slotOffsets,
  wtx_msg_mem_move_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_move_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_move_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_move_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_move_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_move_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_move_desc_struct, tclObj);
}
// Build wtx_msg_mem_move_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_move_desc_type = {
  "wtx_msg_mem_move_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_move_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_move_desc
  };
// Build wtx_msg_mem_move_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_move_desc_ptr = {
  "wtx_msg_mem_move_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_move_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_move_desc
  };

// Alloc wtx_msg_mem_set_desc slot structure for Put/Get functions
static char *wtx_msg_mem_set_desc_slotNames[] =  {
    "wtxCore",
    "value",
    "width",
    "startAddr",
    "numItems",
    NULL
};
static JWRAP_types *wtx_msg_mem_set_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_UINT32], // value 
    &usedType [JTYPE_UINT8], // width 
    &usedType [JTYPE_TGT_ADDR_T], // startAddr 
    &usedType [JTYPE_UINT32], // numItems 
    NULL
};
static int wtx_msg_mem_set_desc_slotArrays[] = {
    1, // wtxCore
    1, // value
    1, // width
    1, // startAddr
    1, // numItems
    0
};
static int wtx_msg_mem_set_desc_slotOffsets[5];
static JWRAP_structs wtx_msg_mem_set_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_mem_set_desc],
  5,
  wtx_msg_mem_set_desc_slotNames,
  wtx_msg_mem_set_desc_slotTypes,
  wtx_msg_mem_set_desc_slotOffsets,
  wtx_msg_mem_set_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_mem_set_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_mem_set_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_mem_set_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_mem_set_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_mem_set_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_mem_set_desc_struct, tclObj);
}
// Build wtx_msg_mem_set_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_set_desc_type = {
  "wtx_msg_mem_set_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_set_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_mem_set_desc
  };
// Build wtx_msg_mem_set_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_mem_set_desc_ptr = {
  "wtx_msg_mem_set_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_mem_set_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_mem_set_desc
  };

// Alloc wtx_msg_context_desc slot structure for Put/Get functions
static char *wtx_msg_context_desc_slotNames[] =  {
    "wtxCore",
    "contextType",
    "returnType",
    "name",
    "priority",
    "options",
    "stackBase",
    "stackSize",
    "entry",
    "redirIn",
    "redirOut",
    "args",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_msg_context_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_CONTEXT_TYPE], // contextType 
    &usedType [JTYPE_WTX_RETURN_TYPE], // returnType 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_UINT32], // priority 
    &usedType [JTYPE_UINT32], // options 
    &usedType [JTYPE_TGT_ADDR_T], // stackBase 
    &usedType [JTYPE_UINT32], // stackSize 
    &usedType [JTYPE_TGT_ADDR_T], // entry 
    &usedType [JTYPE_INT32], // redirIn 
    &usedType [JTYPE_INT32], // redirOut 
    &usedType [JTYPE_TGT_ARG_T], // args 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_msg_context_desc_slotArrays[] = {
    1, // wtxCore
    1, // contextType
    1, // returnType
    1, // name
    1, // priority
    1, // options
    1, // stackBase
    1, // stackSize
    1, // entry
    1, // redirIn
    1, // redirOut
    10, // args
    1, // pReserved
    0
};
static int wtx_msg_context_desc_slotOffsets[13];
static JWRAP_structs wtx_msg_context_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_context_desc],
  13,
  wtx_msg_context_desc_slotNames,
  wtx_msg_context_desc_slotTypes,
  wtx_msg_context_desc_slotOffsets,
  wtx_msg_context_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_context_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_context_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_context_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_context_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_context_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_context_desc_struct, tclObj);
}
// Build wtx_msg_context_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_context_desc_type = {
  "wtx_msg_context_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_context_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_context_desc
  };
// Build wtx_msg_context_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_context_desc_ptr = {
  "wtx_msg_context_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_context_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_context_desc
  };

// Alloc wtx_msg_context_step_desc slot structure for Put/Get functions
static char *wtx_msg_context_step_desc_slotNames[] =  {
    "wtxCore",
    "context",
    "startAddr",
    "endAddr",
    NULL
};
static JWRAP_types *wtx_msg_context_step_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_CONTEXT], // context 
    &usedType [JTYPE_TGT_ADDR_T], // startAddr 
    &usedType [JTYPE_TGT_ADDR_T], // endAddr 
    NULL
};
static int wtx_msg_context_step_desc_slotArrays[] = {
    1, // wtxCore
    1, // context
    1, // startAddr
    1, // endAddr
    0
};
static int wtx_msg_context_step_desc_slotOffsets[4];
static JWRAP_structs wtx_msg_context_step_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_context_step_desc],
  4,
  wtx_msg_context_step_desc_slotNames,
  wtx_msg_context_step_desc_slotTypes,
  wtx_msg_context_step_desc_slotOffsets,
  wtx_msg_context_step_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_context_step_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_context_step_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_context_step_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_context_step_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_context_step_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_context_step_desc_struct, tclObj);
}
// Build wtx_msg_context_step_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_context_step_desc_type = {
  "wtx_msg_context_step_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_context_step_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_context_step_desc
  };
// Build wtx_msg_context_step_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_context_step_desc_ptr = {
  "wtx_msg_context_step_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_context_step_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_context_step_desc
  };

// Alloc wtx_gopher_tape slot structure for Put/Get functions
static char *wtx_gopher_tape_slotNames[] =  {
    "len",
    "data",
    NULL
};
static JWRAP_types *wtx_gopher_tape_slotTypes[] = {
    &usedType [JTYPE_UINT16], // len 
    &usedType [JTYPE_char_Ptr], // data 
    NULL
};
static int wtx_gopher_tape_slotArrays[] = {
    1, // len
    1, // data
    0
};
static int wtx_gopher_tape_slotOffsets[2];
static JWRAP_structs wtx_gopher_tape_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_gopher_tape],
  2,
  wtx_gopher_tape_slotNames,
  wtx_gopher_tape_slotTypes,
  wtx_gopher_tape_slotOffsets,
  wtx_gopher_tape_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_gopher_tape (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_gopher_tape_struct, srcObj, destObj));
}
LOCAL int Put_wtx_gopher_tape (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_gopher_tape_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_gopher_tape (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_gopher_tape_struct, tclObj);
}
// Build wtx_gopher_tape structure as a Tcl type
static Tcl_ObjType wtx_gopher_tape_type = {
  "wtx_gopher_tape",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_gopher_tape,
  (Tcl_SetFromAnyProc*)      Put_wtx_gopher_tape
  };
// Build wtx_gopher_tape structure as a Tcl type
static Tcl_ObjType wtx_gopher_tape_ptr = {
  "wtx_gopher_tape_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_gopher_tape,
  (Tcl_SetFromAnyProc*)      Create_wtx_gopher_tape
  };

// Alloc WTX_MSG_GOPHER_TAPE slot structure for Put/Get functions
static char *WTX_MSG_GOPHER_TAPE_slotNames[] =  {
    "wtxCore",
    "tape",
    NULL
};
static JWRAP_types *WTX_MSG_GOPHER_TAPE_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_GOPHER_TAPE], // tape 
    NULL
};
static int WTX_MSG_GOPHER_TAPE_slotArrays[] = {
    1, // wtxCore
    1, // tape
    0
};
static int WTX_MSG_GOPHER_TAPE_slotOffsets[2];
static JWRAP_structs WTX_MSG_GOPHER_TAPE_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_WTX_MSG_GOPHER_TAPE],
  2,
  WTX_MSG_GOPHER_TAPE_slotNames,
  WTX_MSG_GOPHER_TAPE_slotTypes,
  WTX_MSG_GOPHER_TAPE_slotOffsets,
  WTX_MSG_GOPHER_TAPE_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_WTX_MSG_GOPHER_TAPE (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &WTX_MSG_GOPHER_TAPE_struct, srcObj, destObj));
}
LOCAL int Put_WTX_MSG_GOPHER_TAPE (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &WTX_MSG_GOPHER_TAPE_struct, srcObj, destObj));
}
LOCAL char* Get_WTX_MSG_GOPHER_TAPE (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&WTX_MSG_GOPHER_TAPE_struct, tclObj);
}
// Build WTX_MSG_GOPHER_TAPE structure as a Tcl type
static Tcl_ObjType WTX_MSG_GOPHER_TAPE_type = {
  "WTX_MSG_GOPHER_TAPE",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_WTX_MSG_GOPHER_TAPE,
  (Tcl_SetFromAnyProc*)      Put_WTX_MSG_GOPHER_TAPE
  };
// Build WTX_MSG_GOPHER_TAPE structure as a Tcl type
static Tcl_ObjType WTX_MSG_GOPHER_TAPE_ptr = {
  "WTX_MSG_GOPHER_TAPE_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_WTX_MSG_GOPHER_TAPE,
  (Tcl_SetFromAnyProc*)      Create_WTX_MSG_GOPHER_TAPE
  };

// Alloc wtx_msg_wtxregd_pattern slot structure for Put/Get functions
static char *wtx_msg_wtxregd_pattern_slotNames[] =  {
    "wtxCore",
    "name",
    "type",
    "key",
    NULL
};
static JWRAP_types *wtx_msg_wtxregd_pattern_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_char_Ptr], // type 
    &usedType [JTYPE_char_Ptr], // key 
    NULL
};
static int wtx_msg_wtxregd_pattern_slotArrays[] = {
    1, // wtxCore
    1, // name
    1, // type
    1, // key
    0
};
static int wtx_msg_wtxregd_pattern_slotOffsets[4];
static JWRAP_structs wtx_msg_wtxregd_pattern_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_wtxregd_pattern],
  4,
  wtx_msg_wtxregd_pattern_slotNames,
  wtx_msg_wtxregd_pattern_slotTypes,
  wtx_msg_wtxregd_pattern_slotOffsets,
  wtx_msg_wtxregd_pattern_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_wtxregd_pattern (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_wtxregd_pattern_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_wtxregd_pattern (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_wtxregd_pattern_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_wtxregd_pattern (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_wtxregd_pattern_struct, tclObj);
}
// Build wtx_msg_wtxregd_pattern structure as a Tcl type
static Tcl_ObjType wtx_msg_wtxregd_pattern_type = {
  "wtx_msg_wtxregd_pattern",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_wtxregd_pattern,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_wtxregd_pattern
  };
// Build wtx_msg_wtxregd_pattern structure as a Tcl type
static Tcl_ObjType wtx_msg_wtxregd_pattern_ptr = {
  "wtx_msg_wtxregd_pattern_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_wtxregd_pattern,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_wtxregd_pattern
  };

// Alloc wtx_svr_desc slot structure for Put/Get functions
static char *wtx_svr_desc_slotNames[] =  {
    "wpwrName",
    "wpwrType",
    "wpwrKey",
    NULL
};
static JWRAP_types *wtx_svr_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // wpwrName 
    &usedType [JTYPE_char_Ptr], // wpwrType 
    &usedType [JTYPE_char_Ptr], // wpwrKey 
    NULL
};
static int wtx_svr_desc_slotArrays[] = {
    1, // wpwrName
    1, // wpwrType
    1, // wpwrKey
    0
};
static int wtx_svr_desc_slotOffsets[3];
static JWRAP_structs wtx_svr_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_svr_desc],
  3,
  wtx_svr_desc_slotNames,
  wtx_svr_desc_slotTypes,
  wtx_svr_desc_slotOffsets,
  wtx_svr_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_svr_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_svr_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_svr_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_svr_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_svr_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_svr_desc_struct, tclObj);
}
// Build wtx_svr_desc structure as a Tcl type
static Tcl_ObjType wtx_svr_desc_type = {
  "wtx_svr_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_svr_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_svr_desc
  };
// Build wtx_svr_desc structure as a Tcl type
static Tcl_ObjType wtx_svr_desc_ptr = {
  "wtx_svr_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_svr_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_svr_desc
  };

// Alloc wtx_msg_svr_desc slot structure for Put/Get functions
static char *wtx_msg_svr_desc_slotNames[] =  {
    "wtxCore",
    "wtxSvrDesc",
    NULL
};
static JWRAP_types *wtx_msg_svr_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_SVR_DESC], // wtxSvrDesc 
    NULL
};
static int wtx_msg_svr_desc_slotArrays[] = {
    1, // wtxCore
    1, // wtxSvrDesc
    0
};
static int wtx_msg_svr_desc_slotOffsets[2];
static JWRAP_structs wtx_msg_svr_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_svr_desc],
  2,
  wtx_msg_svr_desc_slotNames,
  wtx_msg_svr_desc_slotTypes,
  wtx_msg_svr_desc_slotOffsets,
  wtx_msg_svr_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_svr_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_svr_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_svr_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_svr_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_svr_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_svr_desc_struct, tclObj);
}
// Build wtx_msg_svr_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_svr_desc_type = {
  "wtx_msg_svr_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_svr_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_svr_desc
  };
// Build wtx_msg_svr_desc structure as a Tcl type
static Tcl_ObjType wtx_msg_svr_desc_ptr = {
  "wtx_msg_svr_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_svr_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_svr_desc
  };

// Alloc wtx_svr_desc_q slot structure for Put/Get functions
static char *wtx_svr_desc_q_slotNames[] =  {
    "wtxSvrDesc",
    "pNext",
    NULL
};
static JWRAP_types *wtx_svr_desc_q_slotTypes[] = {
    &usedType [JTYPE_WTX_SVR_DESC], // wtxSvrDesc 
    &usedType [JTYPE_wtx_svr_desc_q_Ptr], // pNext 
    NULL
};
static int wtx_svr_desc_q_slotArrays[] = {
    1, // wtxSvrDesc
    1, // pNext
    0
};
static int wtx_svr_desc_q_slotOffsets[2];
static JWRAP_structs wtx_svr_desc_q_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_svr_desc_q],
  2,
  wtx_svr_desc_q_slotNames,
  wtx_svr_desc_q_slotTypes,
  wtx_svr_desc_q_slotOffsets,
  wtx_svr_desc_q_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_svr_desc_q (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_svr_desc_q_struct, srcObj, destObj));
}
LOCAL int Put_wtx_svr_desc_q (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_svr_desc_q_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_svr_desc_q (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_svr_desc_q_struct, tclObj);
}
// Build wtx_svr_desc_q structure as a Tcl type
static Tcl_ObjType wtx_svr_desc_q_type = {
  "wtx_svr_desc_q",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_svr_desc_q,
  (Tcl_SetFromAnyProc*)      Put_wtx_svr_desc_q
  };
// Build wtx_svr_desc_q structure as a Tcl type
static Tcl_ObjType wtx_svr_desc_q_ptr = {
  "wtx_svr_desc_q_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_svr_desc_q,
  (Tcl_SetFromAnyProc*)      Create_wtx_svr_desc_q
  };

// Alloc wtx_msg_svr_desc_q slot structure for Put/Get functions
static char *wtx_msg_svr_desc_q_slotNames[] =  {
    "wtxCore",
    "wtxSvrDescQ",
    NULL
};
static JWRAP_types *wtx_msg_svr_desc_q_slotTypes[] = {
    &usedType [JTYPE_WTX_CORE], // wtxCore 
    &usedType [JTYPE_WTX_SVR_DESC_Q], // wtxSvrDescQ 
    NULL
};
static int wtx_msg_svr_desc_q_slotArrays[] = {
    1, // wtxCore
    1, // wtxSvrDescQ
    0
};
static int wtx_msg_svr_desc_q_slotOffsets[2];
static JWRAP_structs wtx_msg_svr_desc_q_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_msg_svr_desc_q],
  2,
  wtx_msg_svr_desc_q_slotNames,
  wtx_msg_svr_desc_q_slotTypes,
  wtx_msg_svr_desc_q_slotOffsets,
  wtx_msg_svr_desc_q_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_msg_svr_desc_q (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_msg_svr_desc_q_struct, srcObj, destObj));
}
LOCAL int Put_wtx_msg_svr_desc_q (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_msg_svr_desc_q_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_msg_svr_desc_q (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_msg_svr_desc_q_struct, tclObj);
}
// Build wtx_msg_svr_desc_q structure as a Tcl type
static Tcl_ObjType wtx_msg_svr_desc_q_type = {
  "wtx_msg_svr_desc_q",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_svr_desc_q,
  (Tcl_SetFromAnyProc*)      Put_wtx_msg_svr_desc_q
  };
// Build wtx_msg_svr_desc_q structure as a Tcl type
static Tcl_ObjType wtx_msg_svr_desc_q_ptr = {
  "wtx_msg_svr_desc_q_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_msg_svr_desc_q,
  (Tcl_SetFromAnyProc*)      Create_wtx_msg_svr_desc_q
  };

// Alloc wtx_context_desc slot structure for Put/Get functions
static char *wtx_context_desc_slotNames[] =  {
    "contextType",
    "returnType",
    "name",
    "priority",
    "options",
    "stackBase",
    "stackSize",
    "entry",
    "redirIn",
    "redirOut",
    "args",
    NULL
};
static JWRAP_types *wtx_context_desc_slotTypes[] = {
    &usedType [JTYPE_WTX_CONTEXT_TYPE], // contextType 
    &usedType [JTYPE_WTX_RETURN_TYPE], // returnType 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_UINT32], // priority 
    &usedType [JTYPE_UINT32], // options 
    &usedType [JTYPE_TGT_ADDR_T], // stackBase 
    &usedType [JTYPE_UINT32], // stackSize 
    &usedType [JTYPE_TGT_ADDR_T], // entry 
    &usedType [JTYPE_INT32], // redirIn 
    &usedType [JTYPE_INT32], // redirOut 
    &usedType [JTYPE_TGT_ARG_T], // args 
    NULL
};
static int wtx_context_desc_slotArrays[] = {
    1, // contextType
    1, // returnType
    1, // name
    1, // priority
    1, // options
    1, // stackBase
    1, // stackSize
    1, // entry
    1, // redirIn
    1, // redirOut
    10, // args
    0
};
static int wtx_context_desc_slotOffsets[11];
static JWRAP_structs wtx_context_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_context_desc],
  11,
  wtx_context_desc_slotNames,
  wtx_context_desc_slotTypes,
  wtx_context_desc_slotOffsets,
  wtx_context_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_context_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_context_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_context_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_context_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_context_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_context_desc_struct, tclObj);
}
// Build wtx_context_desc structure as a Tcl type
static Tcl_ObjType wtx_context_desc_type = {
  "wtx_context_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_context_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_context_desc
  };
// Build wtx_context_desc structure as a Tcl type
static Tcl_ObjType wtx_context_desc_ptr = {
  "wtx_context_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_context_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_context_desc
  };

// Alloc wtx_evtpt_list slot structure for Put/Get functions
static char *wtx_evtpt_list_slotNames[] =  {
    "nEvtpt",
    "pEvtpt",
    NULL
};
static JWRAP_types *wtx_evtpt_list_slotTypes[] = {
    &usedType [JTYPE_UINT32], // nEvtpt 
    &usedType [JTYPE_WTX_EVTPT_Ptr], // pEvtpt 
    NULL
};
static int wtx_evtpt_list_slotArrays[] = {
    1, // nEvtpt
    1, // pEvtpt
    0
};
static int wtx_evtpt_list_slotOffsets[2];
static JWRAP_structs wtx_evtpt_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_evtpt_list],
  2,
  wtx_evtpt_list_slotNames,
  wtx_evtpt_list_slotTypes,
  wtx_evtpt_list_slotOffsets,
  wtx_evtpt_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_evtpt_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_evtpt_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_evtpt_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_evtpt_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_evtpt_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_evtpt_list_struct, tclObj);
}
// Build wtx_evtpt_list structure as a Tcl type
static Tcl_ObjType wtx_evtpt_list_type = {
  "wtx_evtpt_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_evtpt_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_evtpt_list
  };
// Build wtx_evtpt_list structure as a Tcl type
static Tcl_ObjType wtx_evtpt_list_ptr = {
  "wtx_evtpt_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_evtpt_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_evtpt_list
  };

// Alloc wtx_ld_m_file_desc slot structure for Put/Get functions
static char *wtx_ld_m_file_desc_slotNames[] =  {
    "filename",
    "loadFlag",
    "moduleId",
    "nSections",
    "section",
    "undefSymList",
    NULL
};
static JWRAP_types *wtx_ld_m_file_desc_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // filename 
    &usedType [JTYPE_INT32], // loadFlag 
    &usedType [JTYPE_UINT32], // moduleId 
    &usedType [JTYPE_UINT32], // nSections 
    &usedType [JTYPE_LD_M_SECTION_Ptr], // section 
    &usedType [JTYPE_WTX_SYM_LIST], // undefSymList 
    NULL
};
static int wtx_ld_m_file_desc_slotArrays[] = {
    1, // filename
    1, // loadFlag
    1, // moduleId
    1, // nSections
    1, // section
    1, // undefSymList
    0
};
static int wtx_ld_m_file_desc_slotOffsets[6];
static JWRAP_structs wtx_ld_m_file_desc_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_ld_m_file_desc],
  6,
  wtx_ld_m_file_desc_slotNames,
  wtx_ld_m_file_desc_slotTypes,
  wtx_ld_m_file_desc_slotOffsets,
  wtx_ld_m_file_desc_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_ld_m_file_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_ld_m_file_desc_struct, srcObj, destObj));
}
LOCAL int Put_wtx_ld_m_file_desc (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_ld_m_file_desc_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_ld_m_file_desc (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_ld_m_file_desc_struct, tclObj);
}
// Build wtx_ld_m_file_desc structure as a Tcl type
static Tcl_ObjType wtx_ld_m_file_desc_type = {
  "wtx_ld_m_file_desc",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_ld_m_file_desc,
  (Tcl_SetFromAnyProc*)      Put_wtx_ld_m_file_desc
  };
// Build wtx_ld_m_file_desc structure as a Tcl type
static Tcl_ObjType wtx_ld_m_file_desc_ptr = {
  "wtx_ld_m_file_desc_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_ld_m_file_desc,
  (Tcl_SetFromAnyProc*)      Create_wtx_ld_m_file_desc
  };

// Alloc wtx_mem_info slot structure for Put/Get functions
static char *wtx_mem_info_slotNames[] =  {
    "curBytesFree",
    "curBytesAllocated",
    "cumBytesAllocated",
    "curBlocksFree",
    "curBlocksAlloc",
    "cumBlocksAlloc",
    "avgFreeBlockSize",
    "avgAllocBlockSize",
    "cumAvgAllocBlockSize",
    "biggestBlockSize",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_mem_info_slotTypes[] = {
    &usedType [JTYPE_UINT32], // curBytesFree 
    &usedType [JTYPE_UINT32], // curBytesAllocated 
    &usedType [JTYPE_UINT32], // cumBytesAllocated 
    &usedType [JTYPE_UINT32], // curBlocksFree 
    &usedType [JTYPE_UINT32], // curBlocksAlloc 
    &usedType [JTYPE_UINT32], // cumBlocksAlloc 
    &usedType [JTYPE_UINT32], // avgFreeBlockSize 
    &usedType [JTYPE_UINT32], // avgAllocBlockSize 
    &usedType [JTYPE_UINT32], // cumAvgAllocBlockSize 
    &usedType [JTYPE_UINT32], // biggestBlockSize 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_mem_info_slotArrays[] = {
    1, // curBytesFree
    1, // curBytesAllocated
    1, // cumBytesAllocated
    1, // curBlocksFree
    1, // curBlocksAlloc
    1, // cumBlocksAlloc
    1, // avgFreeBlockSize
    1, // avgAllocBlockSize
    1, // cumAvgAllocBlockSize
    1, // biggestBlockSize
    1, // pReserved
    0
};
static int wtx_mem_info_slotOffsets[11];
static JWRAP_structs wtx_mem_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_mem_info],
  11,
  wtx_mem_info_slotNames,
  wtx_mem_info_slotTypes,
  wtx_mem_info_slotOffsets,
  wtx_mem_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_mem_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_mem_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_mem_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_mem_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_mem_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_mem_info_struct, tclObj);
}
// Build wtx_mem_info structure as a Tcl type
static Tcl_ObjType wtx_mem_info_type = {
  "wtx_mem_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_mem_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_mem_info
  };
// Build wtx_mem_info structure as a Tcl type
static Tcl_ObjType wtx_mem_info_ptr = {
  "wtx_mem_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_mem_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_mem_info
  };

// Alloc wtx_module_info slot structure for Put/Get functions
static char *wtx_module_info_slotNames[] =  {
    "moduleId",
    "moduleName",
    "format",
    "group",
    "loadFlag",
    "nSegments",
    "segment",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_module_info_slotTypes[] = {
    &usedType [JTYPE_UINT32], // moduleId 
    &usedType [JTYPE_char_Ptr], // moduleName 
    &usedType [JTYPE_char_Ptr], // format 
    &usedType [JTYPE_UINT32], // group 
    &usedType [JTYPE_int], // loadFlag 
    &usedType [JTYPE_UINT32], // nSegments 
    &usedType [JTYPE_OBJ_SEGMENT_Ptr], // segment 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_module_info_slotArrays[] = {
    1, // moduleId
    1, // moduleName
    1, // format
    1, // group
    1, // loadFlag
    1, // nSegments
    1, // segment
    1, // pReserved
    0
};
static int wtx_module_info_slotOffsets[8];
static JWRAP_structs wtx_module_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_module_info],
  8,
  wtx_module_info_slotNames,
  wtx_module_info_slotTypes,
  wtx_module_info_slotOffsets,
  wtx_module_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_module_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_module_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_module_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_module_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_module_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_module_info_struct, tclObj);
}
// Build wtx_module_info structure as a Tcl type
static Tcl_ObjType wtx_module_info_type = {
  "wtx_module_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_module_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_module_info
  };
// Build wtx_module_info structure as a Tcl type
static Tcl_ObjType wtx_module_info_ptr = {
  "wtx_module_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_module_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_module_info
  };

// Alloc wtx_module_list slot structure for Put/Get functions
static char *wtx_module_list_slotNames[] =  {
    "numObjMod",
    "modIdList",
    NULL
};
static JWRAP_types *wtx_module_list_slotTypes[] = {
    &usedType [JTYPE_UINT32], // numObjMod 
    &usedType [JTYPE_UINT32_Ptr], // modIdList 
    NULL
};
static int wtx_module_list_slotArrays[] = {
    1, // numObjMod
    1, // modIdList
    0
};
static int wtx_module_list_slotOffsets[2];
static JWRAP_structs wtx_module_list_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_module_list],
  2,
  wtx_module_list_slotNames,
  wtx_module_list_slotTypes,
  wtx_module_list_slotOffsets,
  wtx_module_list_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_module_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_module_list_struct, srcObj, destObj));
}
LOCAL int Put_wtx_module_list (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_module_list_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_module_list (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_module_list_struct, tclObj);
}
// Build wtx_module_list structure as a Tcl type
static Tcl_ObjType wtx_module_list_type = {
  "wtx_module_list",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_module_list,
  (Tcl_SetFromAnyProc*)      Put_wtx_module_list
  };
// Build wtx_module_list structure as a Tcl type
static Tcl_ObjType wtx_module_list_ptr = {
  "wtx_module_list_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_module_list,
  (Tcl_SetFromAnyProc*)      Create_wtx_module_list
  };

// Alloc wtx_ts_info slot structure for Put/Get functions
static char *wtx_ts_info_slotNames[] =  {
    "tgtLinkDesc",
    "tgtInfo",
    "pWtxToolDesc",
    "version",
    "userName",
    "startTime",
    "accessTime",
    "lockMsg",
    "pReserved",
    NULL
};
static JWRAP_types *wtx_ts_info_slotTypes[] = {
    &usedType [JTYPE_WTX_TGT_LINK_DESC], // tgtLinkDesc 
    &usedType [JTYPE_WTX_TGT_INFO], // tgtInfo 
    &usedType [JTYPE_WTX_TOOL_DESC_Ptr], // pWtxToolDesc 
    &usedType [JTYPE_char_Ptr], // version 
    &usedType [JTYPE_char_Ptr], // userName 
    &usedType [JTYPE_char_Ptr], // startTime 
    &usedType [JTYPE_char_Ptr], // accessTime 
    &usedType [JTYPE_char_Ptr], // lockMsg 
    &usedType [JTYPE_void_Ptr], // pReserved 
    NULL
};
static int wtx_ts_info_slotArrays[] = {
    1, // tgtLinkDesc
    1, // tgtInfo
    1, // pWtxToolDesc
    1, // version
    1, // userName
    1, // startTime
    1, // accessTime
    1, // lockMsg
    1, // pReserved
    0
};
static int wtx_ts_info_slotOffsets[9];
static JWRAP_structs wtx_ts_info_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wtx_ts_info],
  9,
  wtx_ts_info_slotNames,
  wtx_ts_info_slotTypes,
  wtx_ts_info_slotOffsets,
  wtx_ts_info_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wtx_ts_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wtx_ts_info_struct, srcObj, destObj));
}
LOCAL int Put_wtx_ts_info (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wtx_ts_info_struct, srcObj, destObj));
}
LOCAL char* Get_wtx_ts_info (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wtx_ts_info_struct, tclObj);
}
// Build wtx_ts_info structure as a Tcl type
static Tcl_ObjType wtx_ts_info_type = {
  "wtx_ts_info",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_ts_info,
  (Tcl_SetFromAnyProc*)      Put_wtx_ts_info
  };
// Build wtx_ts_info structure as a Tcl type
static Tcl_ObjType wtx_ts_info_ptr = {
  "wtx_ts_info_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wtx_ts_info,
  (Tcl_SetFromAnyProc*)      Create_wtx_ts_info
  };

 // Hold structure & unions reference for jWrap struct help cmd
 static JWRAP_structs *structures[]={
  &wtx_core_struct,
  &wtx_desc_struct,
  &wtx_desc_q_struct,
  &wtx_value_struct,
  &wtx_msg_result_struct,
  &wtx_msg_param_struct,
  &wtx_mem_region_struct,
  &wtx_rt_info_struct,
  &wtx_agent_info_struct,
  &wtx_tgt_info_struct,
  &wtx_tgt_link_desc_struct,
  &wtx_tool_desc_struct,
  &wtx_msg_ts_info_struct,
  &wtx_msg_ts_lock_struct,
  &wtx_msg_ts_unlock_struct,
  &wtx_msg_tool_desc_struct,
  &wtx_msg_tool_id_struct,
  &wtx_msg_kill_desc_struct,
  &wtx_symbol_struct,
  &wtx_msg_symbol_desc_struct,
  &wtx_sym_list_struct,
  &wtx_msg_sym_list_struct,
  &wtx_msg_open_desc_struct,
  &wtx_msg_vio_ctl_desc_struct,
  &wtx_msg_vio_copy_desc_struct,
  &wtx_vio_file_desc_struct,
  &wtx_msg_vio_file_list_struct,
  &ld_m_section_struct,
  &wtx_msg_ld_m_file_desc_struct,
  &wtx_msg_module_list_struct,
  &obj_segment_struct,
  &wtx_msg_module_info_struct,
  &wtx_msg_mod_name_or_id_struct,
  &wtx_sym_tbl_info_struct,
  &wtx_msg_sym_tbl_info_struct,
  &wtx_msg_sym_match_desc_struct,
  &wtx_event_desc_struct,
  &wtx_msg_event_desc_struct,
  &wtx_msg_event_reg_desc_struct,
  &wtx_wdb_service_desc_struct,
  &wtx_wtx_service_desc_struct,
  &wtx_msg_service_desc_struct,
  &wtx_msg_service_list_struct,
  &wtx_console_desc_struct,
  &wtx_msg_console_desc_struct,
  &wtx_msg_mem_info_struct,
  &wtx_mem_xfer_struct,
  &wtx_msg_mem_xfer_desc_struct,
  &wtx_event_struct,
  &wtx_context_struct,
  &wtx_action_struct,
  &wtx_msg_context_struct,
  &wtx_evtpt_struct,
  &wtx_msg_evtpt_desc_struct,
  &wtx_msg_evtpt_list_struct,
  &wtx_msg_reg_write_struct,
  &WTX_MSG_REG_READ_struct,
  &wtx_msg_mem_block_desc_struct,
  &wtx_msg_mem_read_desc_struct,
  &wtx_msg_mem_copy_desc_struct,
  &wtx_msg_mem_scan_desc_struct,
  &wtx_msg_mem_move_desc_struct,
  &wtx_msg_mem_set_desc_struct,
  &wtx_msg_context_desc_struct,
  &wtx_msg_context_step_desc_struct,
  &wtx_gopher_tape_struct,
  &WTX_MSG_GOPHER_TAPE_struct,
  &wtx_msg_wtxregd_pattern_struct,
  &wtx_svr_desc_struct,
  &wtx_msg_svr_desc_struct,
  &wtx_svr_desc_q_struct,
  &wtx_msg_svr_desc_q_struct,
  &wtx_context_desc_struct,
  &wtx_evtpt_list_struct,
  &wtx_ld_m_file_desc_struct,
  &wtx_mem_info_struct,
  &wtx_module_info_struct,
  &wtx_module_list_struct,
  &wtx_ts_info_struct,
  &Union_Wtx_0_union,
  &Union_Wtx_1_union,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public wtxEach C/C++ function/method
 static int jTcl_wtxEach_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 const char * param_2;
 const char * param_3;
 FUNCPTR param_4;
 void * param_5;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 7) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_3 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_FUNCPTR].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_FUNCPTR].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_FUNCPTR].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_FUNCPTR].obj->name);
 }
  param_4 = *(FUNCPTR*)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_5 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxEach (param_0, param_1, param_2, param_3, param_4, param_5);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_wtxEach0

 // Interface jTcl to C++ for public wtxInfo C/C++ function/method
 static int jTcl_wtxInfo_1 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_DESC*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxInfo (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_DESC**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_DESC_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_wtxInfo1

 // Interface jTcl to C++ for public wtxInfoQ C/C++ function/method
 static int jTcl_wtxInfoQ_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_DESC_Q*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 const char * param_2;
 const char * param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_3 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxInfoQ (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_DESC_Q**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_DESC_Q_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end method jWrap_wtxInfoQ2

 // Interface jTcl to C++ for public wtxInitialize C/C++ function/method
 static int jTcl_wtxInitialize_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX_Ptr].obj->name);
 }
  param_0 = *(HWTX **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxInitialize (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_wtxInitialize3

 // Interface jTcl to C++ for public wtxProbe C/C++ function/method
 static int jTcl_wtxProbe_4 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxProbe (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end method jWrap_wtxProbe4

 // Interface jTcl to C++ for public wtxRegister C/C++ function/method
 static int jTcl_wtxRegister_5 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_DESC*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 const char * param_2;
 const char * param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_3 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxRegister (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_DESC**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_DESC_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[5]);
  return TCL_ERROR;
 } // end method jWrap_wtxRegister5

 // Interface jTcl to C++ for public wtxTerminate C/C++ function/method
 static int jTcl_wtxTerminate_6 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTerminate (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[6]);
  return TCL_ERROR;
 } // end method jWrap_wtxTerminate6

 // Interface jTcl to C++ for public wtxTimeoutSet C/C++ function/method
 static int jTcl_wtxTimeoutSet_7 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTimeoutSet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[7]);
  return TCL_ERROR;
 } // end method jWrap_wtxTimeoutSet7

 // Interface jTcl to C++ for public wtxTimeoutGet C/C++ function/method
 static int jTcl_wtxTimeoutGet_8 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32_Ptr].obj->name);
 }
  param_1 = *(UINT32 **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTimeoutGet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[8]);
  return TCL_ERROR;
 } // end method jWrap_wtxTimeoutGet8

 // Interface jTcl to C++ for public wtxUnregister C/C++ function/method
 static int jTcl_wtxUnregister_9 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxUnregister (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[9]);
  return TCL_ERROR;
 } // end method jWrap_wtxUnregister9

 // Interface jTcl to C++ for public wtxAgentModeSet C/C++ function/method
 static int jTcl_wtxAgentModeSet_10 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_AGENT_MODE_TYPE param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_AGENT_MODE_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_AGENT_MODE_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_AGENT_MODE_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_AGENT_MODE_TYPE].obj->name);
 }
  param_1 = *(WTX_AGENT_MODE_TYPE*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxAgentModeSet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[10]);
  return TCL_ERROR;
 } // end method jWrap_wtxAgentModeSet10

 // Interface jTcl to C++ for public wtxAgentModeGet C/C++ function/method
 static int jTcl_wtxAgentModeGet_11 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_AGENT_MODE_TYPE   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxAgentModeGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_AGENT_MODE_TYPE*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_AGENT_MODE_TYPE].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[11]);
  return TCL_ERROR;
 } // end method jWrap_wtxAgentModeGet11

 // Interface jTcl to C++ for public wtxBreakpointAdd C/C++ function/method
 static int jTcl_wtxBreakpointAdd_12 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;
 TGT_ADDR_T param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_3 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxBreakpointAdd (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[12]);
  return TCL_ERROR;
 } // end method jWrap_wtxBreakpointAdd12

 // Interface jTcl to C++ for public wtxClientDataGet C/C++ function/method
 static int jTcl_wtxClientDataGet_13 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 void ** param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr_Ptr].obj->name);
 }
  param_1 = *(void ***)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxClientDataGet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[13]);
  return TCL_ERROR;
 } // end method jWrap_wtxClientDataGet13

 // Interface jTcl to C++ for public wtxClientDataSet C/C++ function/method
 static int jTcl_wtxClientDataSet_14 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 void * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_1 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxClientDataSet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[14]);
  return TCL_ERROR;
 } // end method jWrap_wtxClientDataSet14

 // Interface jTcl to C++ for public wtxConsoleCreate C/C++ function/method
 static int jTcl_wtxConsoleCreate_15 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   INT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 const char * param_2;
 INT32 * param_3;
 INT32 * param_4;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 6) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_INT32_Ptr].obj->name);
 }
  param_3 = *(INT32 **)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_INT32_Ptr].obj->name);
 }
  param_4 = *(INT32 **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxConsoleCreate (param_0, param_1, param_2, param_3, param_4);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(INT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_INT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[15]);
  return TCL_ERROR;
 } // end method jWrap_wtxConsoleCreate15

 // Interface jTcl to C++ for public wtxConsoleKill C/C++ function/method
 static int jTcl_wtxConsoleKill_16 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 INT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_1 = *(INT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxConsoleKill (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[16]);
  return TCL_ERROR;
 } // end method jWrap_wtxConsoleKill16

 // Interface jTcl to C++ for public wtxContextCont C/C++ function/method
 static int jTcl_wtxContextCont_17 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextCont (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[17]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextCont17

 // Interface jTcl to C++ for public wtxContextCreate C/C++ function/method
 static int jTcl_wtxContextCreate_18 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_CONTEXT_ID_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_DESC * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->name);
 }
  param_1 = *(WTX_CONTEXT_DESC **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextCreate (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_CONTEXT_ID_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[18]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextCreate18

 // Interface jTcl to C++ for public wtxContextExitNotifyAdd C/C++ function/method
 static int jTcl_wtxContextExitNotifyAdd_19 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextExitNotifyAdd (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[19]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextExitNotifyAdd19

 // Interface jTcl to C++ for public wtxContextKill C/C++ function/method
 static int jTcl_wtxContextKill_20 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextKill (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[20]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextKill20

 // Interface jTcl to C++ for public wtxContextResume C/C++ function/method
 static int jTcl_wtxContextResume_21 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextResume (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[21]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextResume21

 // Interface jTcl to C++ for public wtxContextStep C/C++ function/method
 static int jTcl_wtxContextStep_22 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;
 TGT_ADDR_T param_3;
 TGT_ADDR_T param_4;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 6) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_3 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_4 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextStep (param_0, param_1, param_2, param_3, param_4);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[22]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextStep22

 // Interface jTcl to C++ for public wtxContextSuspend C/C++ function/method
 static int jTcl_wtxContextSuspend_23 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxContextSuspend (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[23]);
  return TCL_ERROR;
 } // end method jWrap_wtxContextSuspend23

 // Interface jTcl to C++ for public wtxErrClear C/C++ function/method
 static int jTcl_wtxErrClear_24 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrClear (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[24]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrClear24

 // Interface jTcl to C++ for public wtxErrGet C/C++ function/method
 static int jTcl_wtxErrGet_25 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_ERROR_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_ERROR_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_ERROR_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[25]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrGet25

 // Interface jTcl to C++ for public wtxErrSet C/C++ function/method
 static int jTcl_wtxErrSet_26 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrSet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[26]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrSet26

 // Interface jTcl to C++ for public wtxErrMsgGet C/C++ function/method
 static int jTcl_wtxErrMsgGet_27 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   const char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrMsgGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(const char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[27]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrMsgGet27

 // Interface jTcl to C++ for public wtxErrToMsg C/C++ function/method
 static int jTcl_wtxErrToMsg_28 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   const char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_ERROR_T param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_ERROR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_ERROR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_ERROR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_ERROR_T].obj->name);
 }
  param_1 = *(WTX_ERROR_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrToMsg (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(const char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[28]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrToMsg28

 // Interface jTcl to C++ for public wtxErrDispatch C/C++ function/method
 static int jTcl_wtxErrDispatch_29 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_ERROR_T param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_ERROR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_ERROR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_ERROR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_ERROR_T].obj->name);
 }
  param_1 = *(WTX_ERROR_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrDispatch (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[29]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrDispatch29

 // Interface jTcl to C++ for public wtxErrExceptionFunc C/C++ function/method
 static int jTcl_wtxErrExceptionFunc_30 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   BOOL32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 void * param_1;
 void * param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_1 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_2 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrExceptionFunc (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(BOOL32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_BOOL32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[30]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrExceptionFunc30

 // Interface jTcl to C++ for public wtxErrHandlerAdd C/C++ function/method
 static int jTcl_wtxErrHandlerAdd_31 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_HANDLER_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_HANDLER_FUNC param_1;
 void * param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_HANDLER_FUNC].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_HANDLER_FUNC].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_HANDLER_FUNC].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_HANDLER_FUNC].obj->name);
 }
  param_1 = *(WTX_HANDLER_FUNC*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_2 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrHandlerAdd (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_HANDLER_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_HANDLER_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[31]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrHandlerAdd31

 // Interface jTcl to C++ for public wtxErrHandlerRemove C/C++ function/method
 static int jTcl_wtxErrHandlerRemove_32 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_HANDLER_T param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_HANDLER_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_HANDLER_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_HANDLER_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_HANDLER_T].obj->name);
 }
  param_1 = *(WTX_HANDLER_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxErrHandlerRemove (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[32]);
  return TCL_ERROR;
 } // end method jWrap_wtxErrHandlerRemove32

 // Interface jTcl to C++ for public wtxEventAdd C/C++ function/method
 static int jTcl_wtxEventAdd_33 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 UINT32 param_2;
 const void * param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_3 = *(const void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxEventAdd (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[33]);
  return TCL_ERROR;
 } // end method jWrap_wtxEventAdd33

 // Interface jTcl to C++ for public wtxEventGet C/C++ function/method
 static int jTcl_wtxEventGet_34 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_EVENT_DESC*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxEventGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_EVENT_DESC**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_EVENT_DESC_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[34]);
  return TCL_ERROR;
 } // end method jWrap_wtxEventGet34

 // Interface jTcl to C++ for public wtxEventpointDelete C/C++ function/method
 static int jTcl_wtxEventpointDelete_35 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxEventpointDelete (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[35]);
  return TCL_ERROR;
 } // end method jWrap_wtxEventpointDelete35

 // Interface jTcl to C++ for public wtxEventpointList C/C++ function/method
 static int jTcl_wtxEventpointList_36 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_EVTPT_LIST*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxEventpointList (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_EVTPT_LIST**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_EVTPT_LIST_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[36]);
  return TCL_ERROR;
 } // end method jWrap_wtxEventpointList36

 // Interface jTcl to C++ for public wtxFileClose C/C++ function/method
 static int jTcl_wtxFileClose_37 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 INT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_1 = *(INT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxFileClose (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[37]);
  return TCL_ERROR;
 } // end method jWrap_wtxFileClose37

 // Interface jTcl to C++ for public wtxFileOpen C/C++ function/method
 static int jTcl_wtxFileOpen_38 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   INT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 WTX_OPEN_FLAG param_2;
 INT32 param_3;
 INT32 param_4;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 6) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_OPEN_FLAG].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_OPEN_FLAG].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_OPEN_FLAG].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_OPEN_FLAG].obj->name);
 }
  param_2 = *(WTX_OPEN_FLAG*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_3 = *(INT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_4 = *(INT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxFileOpen (param_0, param_1, param_2, param_3, param_4);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(INT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_INT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[38]);
  return TCL_ERROR;
 } // end method jWrap_wtxFileOpen38

 // Interface jTcl to C++ for public wtxFuncCall C/C++ function/method
 static int jTcl_wtxFuncCall_39 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_CONTEXT_ID_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_DESC * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->name);
 }
  param_1 = *(WTX_CONTEXT_DESC **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxFuncCall (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_CONTEXT_ID_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[39]);
  return TCL_ERROR;
 } // end method jWrap_wtxFuncCall39

 // Interface jTcl to C++ for public wtxDirectCall C/C++ function/method
 static int jTcl_wtxDirectCall_40 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 void * param_2;
 TGT_ARG_T param_3;
 TGT_ARG_T param_4;
 TGT_ARG_T param_5;
 TGT_ARG_T param_6;
 TGT_ARG_T param_7;
 TGT_ARG_T param_8;
 TGT_ARG_T param_9;
 TGT_ARG_T param_10;
 TGT_ARG_T param_11;
 TGT_ARG_T param_12;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 14) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_2 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_3 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_4 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_5 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[7]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[7]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[7]->bytes;
   tmpCgetObj.length  = objv[7]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[7];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,6,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_6 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[8]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[8]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[8]->bytes;
   tmpCgetObj.length  = objv[8]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[8];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,7,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_7 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[9]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[9]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[9]->bytes;
   tmpCgetObj.length  = objv[9]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[9];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,8,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_8 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[10]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[10]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[10]->bytes;
   tmpCgetObj.length  = objv[10]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[10];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,9,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_9 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[11]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[11]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[11]->bytes;
   tmpCgetObj.length  = objv[11]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[11];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,10,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_10 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[12]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[12]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[12]->bytes;
   tmpCgetObj.length  = objv[12]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[12];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,11,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_11 = *(TGT_ARG_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[13]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[13]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[13]->bytes;
   tmpCgetObj.length  = objv[13]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[13];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ARG_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ARG_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ARG_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,12,currentObj->typePtr->name,usedType[JTYPE_TGT_ARG_T].obj->name);
 }
  param_12 = *(TGT_ARG_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxDirectCall (param_0, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[40]);
  return TCL_ERROR;
 } // end method jWrap_wtxDirectCall40

 // Interface jTcl to C++ for public wtxGopherEval C/C++ function/method
 static int jTcl_wtxGopherEval_41 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_GOPHER_TAPE*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxGopherEval (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_GOPHER_TAPE**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_GOPHER_TAPE_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[41]);
  return TCL_ERROR;
 } // end method jWrap_wtxGopherEval41

 // Interface jTcl to C++ for public wtxMemInfoGet C/C++ function/method
 static int jTcl_wtxMemInfoGet_42 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_MEM_INFO*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemInfoGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_MEM_INFO**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_MEM_INFO_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[42]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemInfoGet42

 // Interface jTcl to C++ for public wtxMemAddToPool C/C++ function/method
 static int jTcl_wtxMemAddToPool_43 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 UINT32 param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemAddToPool (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[43]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemAddToPool43

 // Interface jTcl to C++ for public wtxMemAlign C/C++ function/method
 static int jTcl_wtxMemAlign_44 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   TGT_ADDR_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 UINT32 param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemAlign (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(TGT_ADDR_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[44]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemAlign44

 // Interface jTcl to C++ for public wtxMemAlloc C/C++ function/method
 static int jTcl_wtxMemAlloc_45 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   TGT_ADDR_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemAlloc (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(TGT_ADDR_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[45]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemAlloc45

 // Interface jTcl to C++ for public wtxMemChecksum C/C++ function/method
 static int jTcl_wtxMemChecksum_46 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 UINT32 param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemChecksum (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[46]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemChecksum46

 // Interface jTcl to C++ for public wtxMemFree C/C++ function/method
 static int jTcl_wtxMemFree_47 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemFree (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[47]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemFree47

 // Interface jTcl to C++ for public wtxMemMove C/C++ function/method
 static int jTcl_wtxMemMove_48 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 TGT_ADDR_T param_2;
 UINT32 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_2 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_3 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemMove (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[48]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemMove48

 // Interface jTcl to C++ for public wtxMemRead C/C++ function/method
 static int jTcl_wtxMemRead_49 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 void * param_2;
 UINT32 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_2 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_3 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemRead (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[49]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemRead49

 // Interface jTcl to C++ for public wtxMemRealloc C/C++ function/method
 static int jTcl_wtxMemRealloc_50 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   TGT_ADDR_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 UINT32 param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemRealloc (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(TGT_ADDR_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[50]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemRealloc50

 // Interface jTcl to C++ for public wtxMemSet C/C++ function/method
 static int jTcl_wtxMemSet_51 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 TGT_ADDR_T param_1;
 UINT32 param_2;
 UINT32 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_1 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_3 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemSet (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[51]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemSet51

 // Interface jTcl to C++ for public wtxMemScan C/C++ function/method
 static int jTcl_wtxMemScan_52 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 BOOL32 param_1;
 TGT_ADDR_T param_2;
 TGT_ADDR_T param_3;
 UINT32 param_4;
 void * param_5;
 TGT_ADDR_T * param_6;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 8) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_BOOL32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_BOOL32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_BOOL32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_BOOL32].obj->name);
 }
  param_1 = *(BOOL32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_2 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_3 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_4 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_5 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[7]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[7]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[7]->bytes;
   tmpCgetObj.length  = objv[7]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[7];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,6,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T_Ptr].obj->name);
 }
  param_6 = *(TGT_ADDR_T **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemScan (param_0, param_1, param_2, param_3, param_4, param_5, param_6);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[52]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemScan52

 // Interface jTcl to C++ for public wtxMemWrite C/C++ function/method
 static int jTcl_wtxMemWrite_53 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 void * param_1;
 TGT_ADDR_T param_2;
 UINT32 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_1 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_2 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_3 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxMemWrite (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[53]);
  return TCL_ERROR;
 } // end method jWrap_wtxMemWrite53

 // Interface jTcl to C++ for public wtxObjModuleFindName C/C++ function/method
 static int jTcl_wtxObjModuleFindName_54 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxObjModuleFindName (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[54]);
  return TCL_ERROR;
 } // end method jWrap_wtxObjModuleFindName54

 // Interface jTcl to C++ for public wtxObjModuleFindId C/C++ function/method
 static int jTcl_wtxObjModuleFindId_55 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxObjModuleFindId (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[55]);
  return TCL_ERROR;
 } // end method jWrap_wtxObjModuleFindId55

 // Interface jTcl to C++ for public wtxObjModuleInfoGet C/C++ function/method
 static int jTcl_wtxObjModuleInfoGet_56 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_MODULE_INFO*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxObjModuleInfoGet (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_MODULE_INFO**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_MODULE_INFO_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[56]);
  return TCL_ERROR;
 } // end method jWrap_wtxObjModuleInfoGet56

 // Interface jTcl to C++ for public wtxObjModuleList C/C++ function/method
 static int jTcl_wtxObjModuleList_57 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_MODULE_LIST*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxObjModuleList (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_MODULE_LIST**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_MODULE_LIST_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[57]);
  return TCL_ERROR;
 } // end method jWrap_wtxObjModuleList57

 // Interface jTcl to C++ for public wtxObjModuleLoad C/C++ function/method
 static int jTcl_wtxObjModuleLoad_58 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_LD_M_FILE_DESC*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_LD_M_FILE_DESC * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj->name);
 }
  param_1 = *(WTX_LD_M_FILE_DESC **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxObjModuleLoad (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_LD_M_FILE_DESC**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[58]);
  return TCL_ERROR;
 } // end method jWrap_wtxObjModuleLoad58

 // Interface jTcl to C++ for public wtxObjModuleUnload C/C++ function/method
 static int jTcl_wtxObjModuleUnload_59 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_1 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxObjModuleUnload (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[59]);
  return TCL_ERROR;
 } // end method jWrap_wtxObjModuleUnload59

 // Interface jTcl to C++ for public wtxRegisterForEvent C/C++ function/method
 static int jTcl_wtxRegisterForEvent_60 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxRegisterForEvent (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[60]);
  return TCL_ERROR;
 } // end method jWrap_wtxRegisterForEvent60

 // Interface jTcl to C++ for public wtxRegsGet C/C++ function/method
 static int jTcl_wtxRegsGet_61 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;
 WTX_REG_SET_TYPE param_3;
 UINT32 param_4;
 UINT32 param_5;
 void * param_6;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 8) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_REG_SET_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_REG_SET_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_REG_SET_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_WTX_REG_SET_TYPE].obj->name);
 }
  param_3 = *(WTX_REG_SET_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_4 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_5 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[7]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[7]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[7]->bytes;
   tmpCgetObj.length  = objv[7]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[7];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,6,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_6 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxRegsGet (param_0, param_1, param_2, param_3, param_4, param_5, param_6);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[61]);
  return TCL_ERROR;
 } // end method jWrap_wtxRegsGet61

 // Interface jTcl to C++ for public wtxRegsSet C/C++ function/method
 static int jTcl_wtxRegsSet_62 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 WTX_CONTEXT_TYPE param_1;
 WTX_CONTEXT_ID_T param_2;
 WTX_REG_SET_TYPE param_3;
 UINT32 param_4;
 UINT32 param_5;
 void * param_6;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 8) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_TYPE].obj->name);
 }
  param_1 = *(WTX_CONTEXT_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_2 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_WTX_REG_SET_TYPE].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_REG_SET_TYPE].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_REG_SET_TYPE].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_WTX_REG_SET_TYPE].obj->name);
 }
  param_3 = *(WTX_REG_SET_TYPE*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_4 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_5 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[7]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[7]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[7]->bytes;
   tmpCgetObj.length  = objv[7]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[7];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,6,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_6 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxRegsSet (param_0, param_1, param_2, param_3, param_4, param_5, param_6);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[62]);
  return TCL_ERROR;
 } // end method jWrap_wtxRegsSet62

 // Interface jTcl to C++ for public wtxResultFree C/C++ function/method
 static int jTcl_wtxResultFree_63 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 void * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_1 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxResultFree (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[63]);
  return TCL_ERROR;
 } // end method jWrap_wtxResultFree63

 // Interface jTcl to C++ for public wtxServiceAdd C/C++ function/method
 static int jTcl_wtxServiceAdd_64 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 UINT32 * param_1;
 UINT32 param_2;
 char * param_3;
 char * param_4;
 char * param_5;
 char * param_6;
 char * param_7;
 char * param_8;
 char * param_9;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 11) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_UINT32_Ptr].obj->name);
 }
  param_1 = *(UINT32 **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_3 = *(char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_4 = *(char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_5 = *(char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[7]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[7]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[7]->bytes;
   tmpCgetObj.length  = objv[7]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[7];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,6,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_6 = *(char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[8]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[8]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[8]->bytes;
   tmpCgetObj.length  = objv[8]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[8];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,7,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_7 = *(char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[9]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[9]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[9]->bytes;
   tmpCgetObj.length  = objv[9]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[9];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,8,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_8 = *(char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[10]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[10]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[10]->bytes;
   tmpCgetObj.length  = objv[10]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[10];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,9,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_9 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxServiceAdd (param_0, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[64]);
  return TCL_ERROR;
 } // end method jWrap_wtxServiceAdd64

 // Interface jTcl to C++ for public wtxStrToTgtAddr C/C++ function/method
 static int jTcl_wtxStrToTgtAddr_65 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   TGT_ADDR_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxStrToTgtAddr (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(TGT_ADDR_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[65]);
  return TCL_ERROR;
 } // end method jWrap_wtxStrToTgtAddr65

 // Interface jTcl to C++ for public wtxStrToInt32 C/C++ function/method
 static int jTcl_wtxStrToInt32_66 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   INT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxStrToInt32 (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(INT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_INT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[66]);
  return TCL_ERROR;
 } // end method jWrap_wtxStrToInt3266

 // Interface jTcl to C++ for public wtxStrToContextId C/C++ function/method
 static int jTcl_wtxStrToContextId_67 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_CONTEXT_ID_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxStrToContextId (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_CONTEXT_ID_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[67]);
  return TCL_ERROR;
 } // end method jWrap_wtxStrToContextId67

 // Interface jTcl to C++ for public wtxStrToContextType C/C++ function/method
 static int jTcl_wtxStrToContextType_68 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_CONTEXT_TYPE   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxStrToContextType (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_CONTEXT_TYPE*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_CONTEXT_TYPE].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[68]);
  return TCL_ERROR;
 } // end method jWrap_wtxStrToContextType68

 // Interface jTcl to C++ for public wtxStrToEventType C/C++ function/method
 static int jTcl_wtxStrToEventType_69 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_EVENT_TYPE   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxStrToEventType (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_EVENT_TYPE*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_EVENT_TYPE].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[69]);
  return TCL_ERROR;
 } // end method jWrap_wtxStrToEventType69

 // Interface jTcl to C++ for public wtxSymAdd C/C++ function/method
 static int jTcl_wtxSymAdd_70 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 TGT_ADDR_T param_2;
 UINT8 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_2 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT8].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT8].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT8].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT8].obj->name);
 }
  param_3 = *(UINT8*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxSymAdd (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[70]);
  return TCL_ERROR;
 } // end method jWrap_wtxSymAdd70

 // Interface jTcl to C++ for public wtxSymFind C/C++ function/method
 static int jTcl_wtxSymFind_71 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_SYMBOL*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 TGT_ADDR_T param_2;
 BOOL32 param_3;
 UINT8 param_4;
 UINT8 param_5;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 7) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_2 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_BOOL32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_BOOL32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_BOOL32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_BOOL32].obj->name);
 }
  param_3 = *(BOOL32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT8].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT8].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT8].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_UINT8].obj->name);
 }
  param_4 = *(UINT8*)&currentObj->internalRep;

 // Check for user application object
 if (objv[6]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[6]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[6]->bytes;
   tmpCgetObj.length  = objv[6]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[6];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT8].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT8].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT8].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,5,currentObj->typePtr->name,usedType[JTYPE_UINT8].obj->name);
 }
  param_5 = *(UINT8*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxSymFind (param_0, param_1, param_2, param_3, param_4, param_5);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_SYMBOL**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_SYMBOL_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[71]);
  return TCL_ERROR;
 } // end method jWrap_wtxSymFind71

 // Interface jTcl to C++ for public wtxSymListGet C/C++ function/method
 static int jTcl_wtxSymListGet_72 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_SYM_LIST*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 const char * param_2;
 TGT_ADDR_T param_3;
 BOOL32 param_4;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 6) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TGT_ADDR_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TGT_ADDR_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_TGT_ADDR_T].obj->name);
 }
  param_3 = *(TGT_ADDR_T*)&currentObj->internalRep;

 // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_BOOL32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_BOOL32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_BOOL32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_BOOL32].obj->name);
 }
  param_4 = *(BOOL32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxSymListGet (param_0, param_1, param_2, param_3, param_4);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_SYM_LIST**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_SYM_LIST_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[72]);
  return TCL_ERROR;
 } // end method jWrap_wtxSymListGet72

 // Interface jTcl to C++ for public wtxSymRemove C/C++ function/method
 static int jTcl_wtxSymRemove_73 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 UINT8 param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT8].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT8].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT8].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT8].obj->name);
 }
  param_2 = *(UINT8*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxSymRemove (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[73]);
  return TCL_ERROR;
 } // end method jWrap_wtxSymRemove73

 // Interface jTcl to C++ for public wtxSymTblInfoGet C/C++ function/method
 static int jTcl_wtxSymTblInfoGet_74 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_SYM_TBL_INFO*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxSymTblInfoGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_SYM_TBL_INFO**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_SYM_TBL_INFO_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[74]);
  return TCL_ERROR;
 } // end method jWrap_wtxSymTblInfoGet74

 // Interface jTcl to C++ for public wtxTargetRtTypeGet C/C++ function/method
 static int jTcl_wtxTargetRtTypeGet_75 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetRtTypeGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[75]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetRtTypeGet75

 // Interface jTcl to C++ for public wtxTargetRtVersionGet C/C++ function/method
 static int jTcl_wtxTargetRtVersionGet_76 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   const char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetRtVersionGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(const char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[76]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetRtVersionGet76

 // Interface jTcl to C++ for public wtxTargetCpuTypeGet C/C++ function/method
 static int jTcl_wtxTargetCpuTypeGet_77 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetCpuTypeGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[77]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetCpuTypeGet77

 // Interface jTcl to C++ for public wtxTargetHasFppGet C/C++ function/method
 static int jTcl_wtxTargetHasFppGet_78 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   BOOL32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetHasFppGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(BOOL32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_BOOL32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[78]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetHasFppGet78

 // Interface jTcl to C++ for public wtxTargetEndianGet C/C++ function/method
 static int jTcl_wtxTargetEndianGet_79 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_ENDIAN_T   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetEndianGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_ENDIAN_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_ENDIAN_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[79]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetEndianGet79

 // Interface jTcl to C++ for public wtxTargetBootlineGet C/C++ function/method
 static int jTcl_wtxTargetBootlineGet_80 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   const char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetBootlineGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(const char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[80]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetBootlineGet80

 // Interface jTcl to C++ for public wtxTargetBspNameGet C/C++ function/method
 static int jTcl_wtxTargetBspNameGet_81 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   const char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetBspNameGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(const char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[81]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetBspNameGet81

 // Interface jTcl to C++ for public wtxTargetReset C/C++ function/method
 static int jTcl_wtxTargetReset_82 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetReset (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[82]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetReset82

 // Interface jTcl to C++ for public wtxTargetAttach C/C++ function/method
 static int jTcl_wtxTargetAttach_83 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTargetAttach (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[83]);
  return TCL_ERROR;
 } // end method jWrap_wtxTargetAttach83

 // Interface jTcl to C++ for public wtxToolAttach C/C++ function/method
 static int jTcl_wtxToolAttach_84 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 const char * param_1;
 const char * param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(const char **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxToolAttach (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[84]);
  return TCL_ERROR;
 } // end method jWrap_wtxToolAttach84

 // Interface jTcl to C++ for public wtxToolNameGet C/C++ function/method
 static int jTcl_wtxToolNameGet_85 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxToolNameGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[85]);
  return TCL_ERROR;
 } // end method jWrap_wtxToolNameGet85

 // Interface jTcl to C++ for public wtxToolConnected C/C++ function/method
 static int jTcl_wtxToolConnected_86 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   BOOL32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxToolConnected (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(BOOL32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_BOOL32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[86]);
  return TCL_ERROR;
 } // end method jWrap_wtxToolConnected86

 // Interface jTcl to C++ for public wtxToolDetach C/C++ function/method
 static int jTcl_wtxToolDetach_87 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxToolDetach (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[87]);
  return TCL_ERROR;
 } // end method jWrap_wtxToolDetach87

 // Interface jTcl to C++ for public wtxTsInfoGet C/C++ function/method
 static int jTcl_wtxTsInfoGet_88 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_TS_INFO*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTsInfoGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_TS_INFO**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_TS_INFO_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[88]);
  return TCL_ERROR;
 } // end method jWrap_wtxTsInfoGet88

 // Interface jTcl to C++ for public wtxTsKill C/C++ function/method
 static int jTcl_wtxTsKill_89 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTsKill (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[89]);
  return TCL_ERROR;
 } // end method jWrap_wtxTsKill89

 // Interface jTcl to C++ for public wtxTsLock C/C++ function/method
 static int jTcl_wtxTsLock_90 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTsLock (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[90]);
  return TCL_ERROR;
 } // end method jWrap_wtxTsLock90

 // Interface jTcl to C++ for public wtxTsNameGet C/C++ function/method
 static int jTcl_wtxTsNameGet_91 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   const char*   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTsNameGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(const char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[91]);
  return TCL_ERROR;
 } // end method jWrap_wtxTsNameGet91

 // Interface jTcl to C++ for public wtxTsRestart C/C++ function/method
 static int jTcl_wtxTsRestart_92 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTsRestart (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[92]);
  return TCL_ERROR;
 } // end method jWrap_wtxTsRestart92

 // Interface jTcl to C++ for public wtxTsUnlock C/C++ function/method
 static int jTcl_wtxTsUnlock_93 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxTsUnlock (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[93]);
  return TCL_ERROR;
 } // end method jWrap_wtxTsUnlock93

 // Interface jTcl to C++ for public wtxVerify C/C++ function/method
 static int jTcl_wtxVerify_94 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   BOOL32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxVerify (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(BOOL32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_BOOL32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[94]);
  return TCL_ERROR;
 } // end method jWrap_wtxVerify94

 // Interface jTcl to C++ for public wtxVioChanGet C/C++ function/method
 static int jTcl_wtxVioChanGet_95 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   INT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxVioChanGet (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(INT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_INT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[95]);
  return TCL_ERROR;
 } // end method jWrap_wtxVioChanGet95

 // Interface jTcl to C++ for public wtxVioChanRelease C/C++ function/method
 static int jTcl_wtxVioChanRelease_96 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 INT32 param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_1 = *(INT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxVioChanRelease (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[96]);
  return TCL_ERROR;
 } // end method jWrap_wtxVioChanRelease96

 // Interface jTcl to C++ for public wtxVioCtl C/C++ function/method
 static int jTcl_wtxVioCtl_97 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 INT32 param_1;
 UINT32 param_2;
 UINT32 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_1 = *(INT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_2 = *(UINT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_3 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxVioCtl (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[97]);
  return TCL_ERROR;
 } // end method jWrap_wtxVioCtl97

 // Interface jTcl to C++ for public wtxVioFileList C/C++ function/method
 static int jTcl_wtxVioFileList_98 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_VIO_FILE_DESC**   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxVioFileList (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_VIO_FILE_DESC***)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_VIO_FILE_DESC_Ptr_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[98]);
  return TCL_ERROR;
 } // end method jWrap_wtxVioFileList98

 // Interface jTcl to C++ for public wtxVioWrite C/C++ function/method
 static int jTcl_wtxVioWrite_99 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 HWTX param_0;
 INT32 param_1;
 void * param_2;
 UINT32 param_3;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 5) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_HWTX].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_HWTX].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_HWTX].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_HWTX].obj->name);
 }
  param_0 = *(HWTX*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_INT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_INT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_INT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_INT32].obj->name);
 }
  param_1 = *(INT32*)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_2 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_UINT32].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_UINT32].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_UINT32].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_UINT32].obj->name);
 }
  param_3 = *(UINT32*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  wtxVioWrite (param_0, param_1, param_2, param_3);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[99]);
  return TCL_ERROR;
 } // end method jWrap_wtxVioWrite99


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Wtx_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="Wtx";
 module.help        ="Tornado VxWorks WTX interface with target server";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 100;
 module.hashTable   = NULL;
 module.version     = Wtx_CUSTOM_STAMP;
 module.structures  = structures;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef Wtx_CUSTOM_INIT
 Wtx_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_Wtx_enum,&Define_Wtx_type);

 /* --- Enumeration Section --- */

 jWrapEnumRegister (&module, &wtx_error_t_enum,&wtx_error_t_type);
 jWrapEnumRegister (&module, &wtx_event_type_enum,&wtx_event_type_type);
 jWrapEnumRegister (&module, &wtx_context_type_enum,&wtx_context_type_type);
 jWrapEnumRegister (&module, &wtx_action_type_enum,&wtx_action_type_type);
 jWrapEnumRegister (&module, &wtx_return_type_enum,&wtx_return_type_type);
 jWrapEnumRegister (&module, &wtx_reg_set_type_enum,&wtx_reg_set_type_type);
 jWrapEnumRegister (&module, &wtx_agent_mode_type_enum,&wtx_agent_mode_type_type);
 jWrapEnumRegister (&module, &wtx_open_flag_enum,&wtx_open_flag_type);
 jWrapEnumRegister (&module, &wtx_value_t_enum,&wtx_value_t_type);
 jWrapEnumRegister (&module, &wtx_endian_t_enum,&wtx_endian_t_type);
 
 /* *** Type Structs/Unions Section *** */
 {  // Compute wtx_core structure offset
  struct wtx_core dummy4offset;
  wtx_core_slotOffsets [0] = (char*)&dummy4offset.objId - (char*)&dummy4offset;
  wtx_core_slotOffsets [1] = (char*)&dummy4offset.errCode - (char*)&dummy4offset;
  wtx_core_slotOffsets [2] = (char*)&dummy4offset.protVersion - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_core_struct,&wtx_core_type,&wtx_core_ptr );
 };
 {  // Compute wtx_desc structure offset
  struct wtx_desc dummy4offset;
  wtx_desc_slotOffsets [0] = (char*)&dummy4offset.wpwrName - (char*)&dummy4offset;
  wtx_desc_slotOffsets [1] = (char*)&dummy4offset.wpwrType - (char*)&dummy4offset;
  wtx_desc_slotOffsets [2] = (char*)&dummy4offset.wpwrKey - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_desc_struct,&wtx_desc_type,&wtx_desc_ptr );
 };
 {  // Compute wtx_desc_q structure offset
  struct wtx_desc_q dummy4offset;
  wtx_desc_q_slotOffsets [0] = (char*)&dummy4offset.wpwrName - (char*)&dummy4offset;
  wtx_desc_q_slotOffsets [1] = (char*)&dummy4offset.wpwrType - (char*)&dummy4offset;
  wtx_desc_q_slotOffsets [2] = (char*)&dummy4offset.wpwrKey - (char*)&dummy4offset;
  wtx_desc_q_slotOffsets [3] = (char*)&dummy4offset.pNext - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_desc_q_struct,&wtx_desc_q_type,&wtx_desc_q_ptr );
 };
 {  // Compute wtx_value structure offset
  struct wtx_value dummy4offset;
  wtx_value_slotOffsets [0] = (char*)&dummy4offset.valueType - (char*)&dummy4offset;
  wtx_value_slotOffsets [1] = (char*)&dummy4offset.value_u - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_value_struct,&wtx_value_type,&wtx_value_ptr );
 };
 {  // Compute wtx_msg_result structure offset
  struct wtx_msg_result dummy4offset;
  wtx_msg_result_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_result_slotOffsets [1] = (char*)&dummy4offset.val - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_result_struct,&wtx_msg_result_type,&wtx_msg_result_ptr );
 };
 {  // Compute wtx_msg_param structure offset
  struct wtx_msg_param dummy4offset;
  wtx_msg_param_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_param_slotOffsets [1] = (char*)&dummy4offset.param - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_param_struct,&wtx_msg_param_type,&wtx_msg_param_ptr );
 };
 {  // Compute wtx_mem_region structure offset
  struct wtx_mem_region dummy4offset;
  wtx_mem_region_slotOffsets [0] = (char*)&dummy4offset.baseAddr - (char*)&dummy4offset;
  wtx_mem_region_slotOffsets [1] = (char*)&dummy4offset.size - (char*)&dummy4offset;
  wtx_mem_region_slotOffsets [2] = (char*)&dummy4offset.attribute - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_mem_region_struct,&wtx_mem_region_type,&wtx_mem_region_ptr );
 };
 {  // Compute wtx_rt_info structure offset
  struct wtx_rt_info dummy4offset;
  wtx_rt_info_slotOffsets [0] = (char*)&dummy4offset.rtType - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [1] = (char*)&dummy4offset.rtVersion - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [2] = (char*)&dummy4offset.cpuType - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [3] = (char*)&dummy4offset.hasFpp - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [4] = (char*)&dummy4offset.hasWriteProtect - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [5] = (char*)&dummy4offset.pageSize - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [6] = (char*)&dummy4offset.endian - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [7] = (char*)&dummy4offset.bspName - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [8] = (char*)&dummy4offset.bootline - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [9] = (char*)&dummy4offset.memBase - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [10] = (char*)&dummy4offset.memSize - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [11] = (char*)&dummy4offset.numRegions - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [12] = (char*)&dummy4offset.memRegion - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [13] = (char*)&dummy4offset.hostPoolBase - (char*)&dummy4offset;
  wtx_rt_info_slotOffsets [14] = (char*)&dummy4offset.hostPoolSize - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_rt_info_struct,&wtx_rt_info_type,&wtx_rt_info_ptr );
 };
 {  // Compute wtx_agent_info structure offset
  struct wtx_agent_info dummy4offset;
  wtx_agent_info_slotOffsets [0] = (char*)&dummy4offset.agentVersion - (char*)&dummy4offset;
  wtx_agent_info_slotOffsets [1] = (char*)&dummy4offset.mtu - (char*)&dummy4offset;
  wtx_agent_info_slotOffsets [2] = (char*)&dummy4offset.mode - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_agent_info_struct,&wtx_agent_info_type,&wtx_agent_info_ptr );
 };
 {  // Compute wtx_tgt_info structure offset
  struct wtx_tgt_info dummy4offset;
  wtx_tgt_info_slotOffsets [0] = (char*)&dummy4offset.agentInfo - (char*)&dummy4offset;
  wtx_tgt_info_slotOffsets [1] = (char*)&dummy4offset.rtInfo - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_tgt_info_struct,&wtx_tgt_info_type,&wtx_tgt_info_ptr );
 };
 {  // Compute wtx_tgt_link_desc structure offset
  struct wtx_tgt_link_desc dummy4offset;
  wtx_tgt_link_desc_slotOffsets [0] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_tgt_link_desc_slotOffsets [1] = (char*)&dummy4offset.type - (char*)&dummy4offset;
  wtx_tgt_link_desc_slotOffsets [2] = (char*)&dummy4offset.speed - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_tgt_link_desc_struct,&wtx_tgt_link_desc_type,&wtx_tgt_link_desc_ptr );
 };
 {  // Compute wtx_tool_desc structure offset
  struct wtx_tool_desc dummy4offset;
  wtx_tool_desc_slotOffsets [0] = (char*)&dummy4offset.id - (char*)&dummy4offset;
  wtx_tool_desc_slotOffsets [1] = (char*)&dummy4offset.toolName - (char*)&dummy4offset;
  wtx_tool_desc_slotOffsets [2] = (char*)&dummy4offset.toolArgv - (char*)&dummy4offset;
  wtx_tool_desc_slotOffsets [3] = (char*)&dummy4offset.toolVersion - (char*)&dummy4offset;
  wtx_tool_desc_slotOffsets [4] = (char*)&dummy4offset.userName - (char*)&dummy4offset;
  wtx_tool_desc_slotOffsets [5] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  wtx_tool_desc_slotOffsets [6] = (char*)&dummy4offset.next - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_tool_desc_struct,&wtx_tool_desc_type,&wtx_tool_desc_ptr );
 };
 {  // Compute wtx_msg_ts_info structure offset
  struct wtx_msg_ts_info dummy4offset;
  wtx_msg_ts_info_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [1] = (char*)&dummy4offset.tgtLinkDesc - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [2] = (char*)&dummy4offset.tgtInfo - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [3] = (char*)&dummy4offset.pWtxToolDesc - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [4] = (char*)&dummy4offset.version - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [5] = (char*)&dummy4offset.userName - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [6] = (char*)&dummy4offset.startTime - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [7] = (char*)&dummy4offset.accessTime - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [8] = (char*)&dummy4offset.lockMsg - (char*)&dummy4offset;
  wtx_msg_ts_info_slotOffsets [9] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_ts_info_struct,&wtx_msg_ts_info_type,&wtx_msg_ts_info_ptr );
 };
 {  // Compute wtx_msg_ts_lock structure offset
  struct wtx_msg_ts_lock dummy4offset;
  wtx_msg_ts_lock_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_ts_lock_slotOffsets [1] = (char*)&dummy4offset.lockType - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_ts_lock_struct,&wtx_msg_ts_lock_type,&wtx_msg_ts_lock_ptr );
 };
 {  // Compute wtx_msg_ts_unlock structure offset
  struct wtx_msg_ts_unlock dummy4offset;
  wtx_msg_ts_unlock_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_ts_unlock_slotOffsets [1] = (char*)&dummy4offset.force - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_ts_unlock_struct,&wtx_msg_ts_unlock_type,&wtx_msg_ts_unlock_ptr );
 };
 {  // Compute wtx_msg_tool_desc structure offset
  struct wtx_msg_tool_desc dummy4offset;
  wtx_msg_tool_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_tool_desc_slotOffsets [1] = (char*)&dummy4offset.wtxToolDesc - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_tool_desc_struct,&wtx_msg_tool_desc_type,&wtx_msg_tool_desc_ptr );
 };
 {  // Compute wtx_msg_tool_id structure offset
  struct wtx_msg_tool_id dummy4offset;
  wtx_msg_tool_id_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_tool_id_struct,&wtx_msg_tool_id_type,&wtx_msg_tool_id_ptr );
 };
 {  // Compute wtx_msg_kill_desc structure offset
  struct wtx_msg_kill_desc dummy4offset;
  wtx_msg_kill_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_kill_desc_slotOffsets [1] = (char*)&dummy4offset.request - (char*)&dummy4offset;
  wtx_msg_kill_desc_slotOffsets [2] = (char*)&dummy4offset.arg - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_kill_desc_struct,&wtx_msg_kill_desc_type,&wtx_msg_kill_desc_ptr );
 };
 {  // Compute wtx_symbol structure offset
  struct wtx_symbol dummy4offset;
  wtx_symbol_slotOffsets [0] = (char*)&dummy4offset.status - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [1] = (char*)&dummy4offset.symTblId - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [2] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [3] = (char*)&dummy4offset.exactName - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [4] = (char*)&dummy4offset.value - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [5] = (char*)&dummy4offset.type - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [6] = (char*)&dummy4offset.typeMask - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [7] = (char*)&dummy4offset.group - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [8] = (char*)&dummy4offset.moduleName - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [9] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  wtx_symbol_slotOffsets [10] = (char*)&dummy4offset.next - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_symbol_struct,&wtx_symbol_type,&wtx_symbol_ptr );
 };
 {  // Compute wtx_msg_symbol_desc structure offset
  struct wtx_msg_symbol_desc dummy4offset;
  wtx_msg_symbol_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_symbol_desc_slotOffsets [1] = (char*)&dummy4offset.symbol - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_symbol_desc_struct,&wtx_msg_symbol_desc_type,&wtx_msg_symbol_desc_ptr );
 };
 {  // Compute wtx_sym_list structure offset
  struct wtx_sym_list dummy4offset;
  wtx_sym_list_slotOffsets [0] = (char*)&dummy4offset.pSymbol - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_sym_list_struct,&wtx_sym_list_type,&wtx_sym_list_ptr );
 };
 {  // Compute wtx_msg_sym_list structure offset
  struct wtx_msg_sym_list dummy4offset;
  wtx_msg_sym_list_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_sym_list_slotOffsets [1] = (char*)&dummy4offset.symList - (char*)&dummy4offset;
  wtx_msg_sym_list_slotOffsets [2] = (char*)&dummy4offset.moreToCome - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_sym_list_struct,&wtx_msg_sym_list_type,&wtx_msg_sym_list_ptr );
 };
 {  // Compute wtx_msg_open_desc structure offset
  struct wtx_msg_open_desc dummy4offset;
  wtx_msg_open_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_open_desc_slotOffsets [1] = (char*)&dummy4offset.filename - (char*)&dummy4offset;
  wtx_msg_open_desc_slotOffsets [2] = (char*)&dummy4offset.flags - (char*)&dummy4offset;
  wtx_msg_open_desc_slotOffsets [3] = (char*)&dummy4offset.mode - (char*)&dummy4offset;
  wtx_msg_open_desc_slotOffsets [4] = (char*)&dummy4offset.channel - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_open_desc_struct,&wtx_msg_open_desc_type,&wtx_msg_open_desc_ptr );
 };
 {  // Compute wtx_msg_vio_ctl_desc structure offset
  struct wtx_msg_vio_ctl_desc dummy4offset;
  wtx_msg_vio_ctl_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_vio_ctl_desc_slotOffsets [1] = (char*)&dummy4offset.channel - (char*)&dummy4offset;
  wtx_msg_vio_ctl_desc_slotOffsets [2] = (char*)&dummy4offset.request - (char*)&dummy4offset;
  wtx_msg_vio_ctl_desc_slotOffsets [3] = (char*)&dummy4offset.arg - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_vio_ctl_desc_struct,&wtx_msg_vio_ctl_desc_type,&wtx_msg_vio_ctl_desc_ptr );
 };
 {  // Compute wtx_msg_vio_copy_desc structure offset
  struct wtx_msg_vio_copy_desc dummy4offset;
  wtx_msg_vio_copy_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_vio_copy_desc_slotOffsets [1] = (char*)&dummy4offset.channel - (char*)&dummy4offset;
  wtx_msg_vio_copy_desc_slotOffsets [2] = (char*)&dummy4offset.maxBytes - (char*)&dummy4offset;
  wtx_msg_vio_copy_desc_slotOffsets [3] = (char*)&dummy4offset.baseAddr - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_vio_copy_desc_struct,&wtx_msg_vio_copy_desc_type,&wtx_msg_vio_copy_desc_ptr );
 };
 {  // Compute wtx_vio_file_desc structure offset
  struct wtx_vio_file_desc dummy4offset;
  wtx_vio_file_desc_slotOffsets [0] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [1] = (char*)&dummy4offset.fd - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [2] = (char*)&dummy4offset.channel - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [3] = (char*)&dummy4offset.fp - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [4] = (char*)&dummy4offset.type - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [5] = (char*)&dummy4offset.mode - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [6] = (char*)&dummy4offset.status - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [7] = (char*)&dummy4offset.addlInfo - (char*)&dummy4offset;
  wtx_vio_file_desc_slotOffsets [8] = (char*)&dummy4offset.next - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_vio_file_desc_struct,&wtx_vio_file_desc_type,&wtx_vio_file_desc_ptr );
 };
 {  // Compute wtx_msg_vio_file_list structure offset
  struct wtx_msg_vio_file_list dummy4offset;
  wtx_msg_vio_file_list_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_vio_file_list_slotOffsets [1] = (char*)&dummy4offset.pVioFileList - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_vio_file_list_struct,&wtx_msg_vio_file_list_type,&wtx_msg_vio_file_list_ptr );
 };
 {  // Compute ld_m_section structure offset
  struct ld_m_section dummy4offset;
  ld_m_section_slotOffsets [0] = (char*)&dummy4offset.flags - (char*)&dummy4offset;
  ld_m_section_slotOffsets [1] = (char*)&dummy4offset.addr - (char*)&dummy4offset;
  ld_m_section_slotOffsets [2] = (char*)&dummy4offset.length - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&ld_m_section_struct,&ld_m_section_type,&ld_m_section_ptr );
 };
 {  // Compute wtx_msg_ld_m_file_desc structure offset
  struct wtx_msg_ld_m_file_desc dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [1] = (char*)&dummy4offset.filename - (char*)&dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [2] = (char*)&dummy4offset.loadFlag - (char*)&dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [3] = (char*)&dummy4offset.moduleId - (char*)&dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [4] = (char*)&dummy4offset.nSections - (char*)&dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [5] = (char*)&dummy4offset.section - (char*)&dummy4offset;
  wtx_msg_ld_m_file_desc_slotOffsets [6] = (char*)&dummy4offset.undefSymList - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_ld_m_file_desc_struct,&wtx_msg_ld_m_file_desc_type,&wtx_msg_ld_m_file_desc_ptr );
 };
 {  // Compute wtx_msg_module_list structure offset
  struct wtx_msg_module_list dummy4offset;
  wtx_msg_module_list_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_module_list_slotOffsets [1] = (char*)&dummy4offset.numObjMod - (char*)&dummy4offset;
  wtx_msg_module_list_slotOffsets [2] = (char*)&dummy4offset.modIdList - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_module_list_struct,&wtx_msg_module_list_type,&wtx_msg_module_list_ptr );
 };
 {  // Compute obj_segment structure offset
  struct obj_segment dummy4offset;
  obj_segment_slotOffsets [0] = (char*)&dummy4offset.flags - (char*)&dummy4offset;
  obj_segment_slotOffsets [1] = (char*)&dummy4offset.addr - (char*)&dummy4offset;
  obj_segment_slotOffsets [2] = (char*)&dummy4offset.length - (char*)&dummy4offset;
  obj_segment_slotOffsets [3] = (char*)&dummy4offset.reserved1 - (char*)&dummy4offset;
  obj_segment_slotOffsets [4] = (char*)&dummy4offset.reserved2 - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&obj_segment_struct,&obj_segment_type,&obj_segment_ptr );
 };
 {  // Compute wtx_msg_module_info structure offset
  struct wtx_msg_module_info dummy4offset;
  wtx_msg_module_info_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [1] = (char*)&dummy4offset.moduleId - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [2] = (char*)&dummy4offset.moduleName - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [3] = (char*)&dummy4offset.format - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [4] = (char*)&dummy4offset.group - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [5] = (char*)&dummy4offset.loadFlag - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [6] = (char*)&dummy4offset.nSegments - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [7] = (char*)&dummy4offset.segment - (char*)&dummy4offset;
  wtx_msg_module_info_slotOffsets [8] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_module_info_struct,&wtx_msg_module_info_type,&wtx_msg_module_info_ptr );
 };
 {  // Compute wtx_msg_mod_name_or_id structure offset
  struct wtx_msg_mod_name_or_id dummy4offset;
  wtx_msg_mod_name_or_id_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mod_name_or_id_slotOffsets [1] = (char*)&dummy4offset.moduleId - (char*)&dummy4offset;
  wtx_msg_mod_name_or_id_slotOffsets [2] = (char*)&dummy4offset.filename - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mod_name_or_id_struct,&wtx_msg_mod_name_or_id_type,&wtx_msg_mod_name_or_id_ptr );
 };
 {  // Compute wtx_sym_tbl_info structure offset
  struct wtx_sym_tbl_info dummy4offset;
  wtx_sym_tbl_info_slotOffsets [0] = (char*)&dummy4offset.symTblId - (char*)&dummy4offset;
  wtx_sym_tbl_info_slotOffsets [1] = (char*)&dummy4offset.symNum - (char*)&dummy4offset;
  wtx_sym_tbl_info_slotOffsets [2] = (char*)&dummy4offset.sameNameOk - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_sym_tbl_info_struct,&wtx_sym_tbl_info_type,&wtx_sym_tbl_info_ptr );
 };
 {  // Compute wtx_msg_sym_tbl_info structure offset
  struct wtx_msg_sym_tbl_info dummy4offset;
  wtx_msg_sym_tbl_info_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_sym_tbl_info_slotOffsets [1] = (char*)&dummy4offset.symTblId - (char*)&dummy4offset;
  wtx_msg_sym_tbl_info_slotOffsets [2] = (char*)&dummy4offset.symNum - (char*)&dummy4offset;
  wtx_msg_sym_tbl_info_slotOffsets [3] = (char*)&dummy4offset.sameNameOk - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_sym_tbl_info_struct,&wtx_msg_sym_tbl_info_type,&wtx_msg_sym_tbl_info_ptr );
 };
 {  // Compute wtx_msg_sym_match_desc structure offset
  struct wtx_msg_sym_match_desc dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [1] = (char*)&dummy4offset.symTblId - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [2] = (char*)&dummy4offset.matchString - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [3] = (char*)&dummy4offset.adrs - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [4] = (char*)&dummy4offset.stringToMatch - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [5] = (char*)&dummy4offset.byModuleName - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [6] = (char*)&dummy4offset.module - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [7] = (char*)&dummy4offset.listUnknownSym - (char*)&dummy4offset;
  wtx_msg_sym_match_desc_slotOffsets [8] = (char*)&dummy4offset.giveMeNext - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_sym_match_desc_struct,&wtx_msg_sym_match_desc_type,&wtx_msg_sym_match_desc_ptr );
 };
 {  // Compute wtx_event_desc structure offset
  struct wtx_event_desc dummy4offset;
  wtx_event_desc_slotOffsets [0] = (char*)&dummy4offset.event - (char*)&dummy4offset;
  wtx_event_desc_slotOffsets [1] = (char*)&dummy4offset.addlDataLen - (char*)&dummy4offset;
  wtx_event_desc_slotOffsets [2] = (char*)&dummy4offset.addlData - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_event_desc_struct,&wtx_event_desc_type,&wtx_event_desc_ptr );
 };
 {  // Compute wtx_msg_event_desc structure offset
  struct wtx_msg_event_desc dummy4offset;
  wtx_msg_event_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_event_desc_slotOffsets [1] = (char*)&dummy4offset.eventDesc - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_event_desc_struct,&wtx_msg_event_desc_type,&wtx_msg_event_desc_ptr );
 };
 {  // Compute wtx_msg_event_reg_desc structure offset
  struct wtx_msg_event_reg_desc dummy4offset;
  wtx_msg_event_reg_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_event_reg_desc_slotOffsets [1] = (char*)&dummy4offset.evtRegExp - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_event_reg_desc_struct,&wtx_msg_event_reg_desc_type,&wtx_msg_event_reg_desc_ptr );
 };
 {  // Compute wtx_wdb_service_desc structure offset
  struct wtx_wdb_service_desc dummy4offset;
  wtx_wdb_service_desc_slotOffsets [0] = (char*)&dummy4offset.rpcNum - (char*)&dummy4offset;
  wtx_wdb_service_desc_slotOffsets [1] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_wdb_service_desc_slotOffsets [2] = (char*)&dummy4offset.svcObjFile - (char*)&dummy4offset;
  wtx_wdb_service_desc_slotOffsets [3] = (char*)&dummy4offset.initRtnName - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_wdb_service_desc_struct,&wtx_wdb_service_desc_type,&wtx_wdb_service_desc_ptr );
 };
 {  // Compute wtx_wtx_service_desc structure offset
  struct wtx_wtx_service_desc dummy4offset;
  wtx_wtx_service_desc_slotOffsets [0] = (char*)&dummy4offset.svcObjFile - (char*)&dummy4offset;
  wtx_wtx_service_desc_slotOffsets [1] = (char*)&dummy4offset.svcProcName - (char*)&dummy4offset;
  wtx_wtx_service_desc_slotOffsets [2] = (char*)&dummy4offset.inProcName - (char*)&dummy4offset;
  wtx_wtx_service_desc_slotOffsets [3] = (char*)&dummy4offset.outProcName - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_wtx_service_desc_struct,&wtx_wtx_service_desc_type,&wtx_wtx_service_desc_ptr );
 };
 {  // Compute wtx_msg_service_desc structure offset
  struct wtx_msg_service_desc dummy4offset;
  wtx_msg_service_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_service_desc_slotOffsets [1] = (char*)&dummy4offset.pWtxServiceDesc - (char*)&dummy4offset;
  wtx_msg_service_desc_slotOffsets [2] = (char*)&dummy4offset.pWdbServiceDesc - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_service_desc_struct,&wtx_msg_service_desc_type,&wtx_msg_service_desc_ptr );
 };
 {  // Compute wtx_msg_service_list structure offset
  struct wtx_msg_service_list dummy4offset;
  wtx_msg_service_list_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_service_list_slotOffsets [1] = (char*)&dummy4offset.nServices - (char*)&dummy4offset;
  wtx_msg_service_list_slotOffsets [2] = (char*)&dummy4offset.serviceDesc - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_service_list_struct,&wtx_msg_service_list_type,&wtx_msg_service_list_ptr );
 };
 {  // Compute wtx_console_desc structure offset
  struct wtx_console_desc dummy4offset;
  wtx_console_desc_slotOffsets [0] = (char*)&dummy4offset.fdIn - (char*)&dummy4offset;
  wtx_console_desc_slotOffsets [1] = (char*)&dummy4offset.fdOut - (char*)&dummy4offset;
  wtx_console_desc_slotOffsets [2] = (char*)&dummy4offset.pid - (char*)&dummy4offset;
  wtx_console_desc_slotOffsets [3] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_console_desc_slotOffsets [4] = (char*)&dummy4offset.display - (char*)&dummy4offset;
  wtx_console_desc_slotOffsets [5] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_console_desc_struct,&wtx_console_desc_type,&wtx_console_desc_ptr );
 };
 {  // Compute wtx_msg_console_desc structure offset
  struct wtx_msg_console_desc dummy4offset;
  wtx_msg_console_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_console_desc_slotOffsets [1] = (char*)&dummy4offset.wtxConsDesc - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_console_desc_struct,&wtx_msg_console_desc_type,&wtx_msg_console_desc_ptr );
 };
 {  // Compute wtx_msg_mem_info structure offset
  struct wtx_msg_mem_info dummy4offset;
  wtx_msg_mem_info_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [1] = (char*)&dummy4offset.curBytesFree - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [2] = (char*)&dummy4offset.curBytesAllocated - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [3] = (char*)&dummy4offset.cumBytesAllocated - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [4] = (char*)&dummy4offset.curBlocksFree - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [5] = (char*)&dummy4offset.curBlocksAlloc - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [6] = (char*)&dummy4offset.cumBlocksAlloc - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [7] = (char*)&dummy4offset.avgFreeBlockSize - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [8] = (char*)&dummy4offset.avgAllocBlockSize - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [9] = (char*)&dummy4offset.cumAvgAllocBlockSize - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [10] = (char*)&dummy4offset.biggestBlockSize - (char*)&dummy4offset;
  wtx_msg_mem_info_slotOffsets [11] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_info_struct,&wtx_msg_mem_info_type,&wtx_msg_mem_info_ptr );
 };
 {  // Compute wtx_mem_xfer structure offset
  struct wtx_mem_xfer dummy4offset;
  wtx_mem_xfer_slotOffsets [0] = (char*)&dummy4offset.numBytes - (char*)&dummy4offset;
  wtx_mem_xfer_slotOffsets [1] = (char*)&dummy4offset.destination - (char*)&dummy4offset;
  wtx_mem_xfer_slotOffsets [2] = (char*)&dummy4offset.source - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_mem_xfer_struct,&wtx_mem_xfer_type,&wtx_mem_xfer_ptr );
 };
 {  // Compute wtx_msg_mem_xfer_desc structure offset
  struct wtx_msg_mem_xfer_desc dummy4offset;
  wtx_msg_mem_xfer_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_xfer_desc_slotOffsets [1] = (char*)&dummy4offset.memXfer - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_xfer_desc_struct,&wtx_msg_mem_xfer_desc_type,&wtx_msg_mem_xfer_desc_ptr );
 };
 {  // Compute wtx_event structure offset
  struct wtx_event dummy4offset;
  wtx_event_slotOffsets [0] = (char*)&dummy4offset.eventType - (char*)&dummy4offset;
  wtx_event_slotOffsets [1] = (char*)&dummy4offset.eventArg - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_event_struct,&wtx_event_type,&wtx_event_ptr );
 };
 {  // Compute wtx_context structure offset
  struct wtx_context dummy4offset;
  wtx_context_slotOffsets [0] = (char*)&dummy4offset.contextType - (char*)&dummy4offset;
  wtx_context_slotOffsets [1] = (char*)&dummy4offset.contextId - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_context_struct,&wtx_context_type,&wtx_context_ptr );
 };
 {  // Compute wtx_action structure offset
  struct wtx_action dummy4offset;
  wtx_action_slotOffsets [0] = (char*)&dummy4offset.actionType - (char*)&dummy4offset;
  wtx_action_slotOffsets [1] = (char*)&dummy4offset.actionArg - (char*)&dummy4offset;
  wtx_action_slotOffsets [2] = (char*)&dummy4offset.callRtn - (char*)&dummy4offset;
  wtx_action_slotOffsets [3] = (char*)&dummy4offset.callArg - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_action_struct,&wtx_action_type,&wtx_action_ptr );
 };
 {  // Compute wtx_msg_context structure offset
  struct wtx_msg_context dummy4offset;
  wtx_msg_context_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_context_slotOffsets [1] = (char*)&dummy4offset.contextType - (char*)&dummy4offset;
  wtx_msg_context_slotOffsets [2] = (char*)&dummy4offset.contextId - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_context_struct,&wtx_msg_context_type,&wtx_msg_context_ptr );
 };
 {  // Compute wtx_evtpt structure offset
  struct wtx_evtpt dummy4offset;
  wtx_evtpt_slotOffsets [0] = (char*)&dummy4offset.event - (char*)&dummy4offset;
  wtx_evtpt_slotOffsets [1] = (char*)&dummy4offset.context - (char*)&dummy4offset;
  wtx_evtpt_slotOffsets [2] = (char*)&dummy4offset.action - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_evtpt_struct,&wtx_evtpt_type,&wtx_evtpt_ptr );
 };
 {  // Compute wtx_msg_evtpt_desc structure offset
  struct wtx_msg_evtpt_desc dummy4offset;
  wtx_msg_evtpt_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_evtpt_desc_slotOffsets [1] = (char*)&dummy4offset.wtxEvtpt - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_evtpt_desc_struct,&wtx_msg_evtpt_desc_type,&wtx_msg_evtpt_desc_ptr );
 };
 {  // Compute wtx_msg_evtpt_list structure offset
  struct wtx_msg_evtpt_list dummy4offset;
  wtx_msg_evtpt_list_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_evtpt_list_slotOffsets [1] = (char*)&dummy4offset.nEvtpt - (char*)&dummy4offset;
  wtx_msg_evtpt_list_slotOffsets [2] = (char*)&dummy4offset.pEvtpt - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_evtpt_list_struct,&wtx_msg_evtpt_list_type,&wtx_msg_evtpt_list_ptr );
 };
 {  // Compute wtx_msg_reg_write structure offset
  struct wtx_msg_reg_write dummy4offset;
  wtx_msg_reg_write_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_reg_write_slotOffsets [1] = (char*)&dummy4offset.regSetType - (char*)&dummy4offset;
  wtx_msg_reg_write_slotOffsets [2] = (char*)&dummy4offset.context - (char*)&dummy4offset;
  wtx_msg_reg_write_slotOffsets [3] = (char*)&dummy4offset.memXfer - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_reg_write_struct,&wtx_msg_reg_write_type,&wtx_msg_reg_write_ptr );
 };
 {  // Compute WTX_MSG_REG_READ structure offset
  struct WTX_MSG_REG_READ dummy4offset;
  WTX_MSG_REG_READ_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  WTX_MSG_REG_READ_slotOffsets [1] = (char*)&dummy4offset.regSetType - (char*)&dummy4offset;
  WTX_MSG_REG_READ_slotOffsets [2] = (char*)&dummy4offset.context - (char*)&dummy4offset;
  WTX_MSG_REG_READ_slotOffsets [3] = (char*)&dummy4offset.memRegion - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&WTX_MSG_REG_READ_struct,&WTX_MSG_REG_READ_type,&WTX_MSG_REG_READ_ptr );
 };
 {  // Compute wtx_msg_mem_block_desc structure offset
  struct wtx_msg_mem_block_desc dummy4offset;
  wtx_msg_mem_block_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_block_desc_slotOffsets [1] = (char*)&dummy4offset.startAddr - (char*)&dummy4offset;
  wtx_msg_mem_block_desc_slotOffsets [2] = (char*)&dummy4offset.numBytes - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_block_desc_struct,&wtx_msg_mem_block_desc_type,&wtx_msg_mem_block_desc_ptr );
 };
 {  // Compute wtx_msg_mem_read_desc structure offset
  struct wtx_msg_mem_read_desc dummy4offset;
  wtx_msg_mem_read_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_read_desc_slotOffsets [1] = (char*)&dummy4offset.source - (char*)&dummy4offset;
  wtx_msg_mem_read_desc_slotOffsets [2] = (char*)&dummy4offset.destination - (char*)&dummy4offset;
  wtx_msg_mem_read_desc_slotOffsets [3] = (char*)&dummy4offset.numBytes - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_read_desc_struct,&wtx_msg_mem_read_desc_type,&wtx_msg_mem_read_desc_ptr );
 };
 {  // Compute wtx_msg_mem_copy_desc structure offset
  struct wtx_msg_mem_copy_desc dummy4offset;
  wtx_msg_mem_copy_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_copy_desc_slotOffsets [1] = (char*)&dummy4offset.source - (char*)&dummy4offset;
  wtx_msg_mem_copy_desc_slotOffsets [2] = (char*)&dummy4offset.destination - (char*)&dummy4offset;
  wtx_msg_mem_copy_desc_slotOffsets [3] = (char*)&dummy4offset.numBytes - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_copy_desc_struct,&wtx_msg_mem_copy_desc_type,&wtx_msg_mem_copy_desc_ptr );
 };
 {  // Compute wtx_msg_mem_scan_desc structure offset
  struct wtx_msg_mem_scan_desc dummy4offset;
  wtx_msg_mem_scan_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_scan_desc_slotOffsets [1] = (char*)&dummy4offset.match - (char*)&dummy4offset;
  wtx_msg_mem_scan_desc_slotOffsets [2] = (char*)&dummy4offset.startAddr - (char*)&dummy4offset;
  wtx_msg_mem_scan_desc_slotOffsets [3] = (char*)&dummy4offset.endAddr - (char*)&dummy4offset;
  wtx_msg_mem_scan_desc_slotOffsets [4] = (char*)&dummy4offset.numBytes - (char*)&dummy4offset;
  wtx_msg_mem_scan_desc_slotOffsets [5] = (char*)&dummy4offset.pattern - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_scan_desc_struct,&wtx_msg_mem_scan_desc_type,&wtx_msg_mem_scan_desc_ptr );
 };
 {  // Compute wtx_msg_mem_move_desc structure offset
  struct wtx_msg_mem_move_desc dummy4offset;
  wtx_msg_mem_move_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_move_desc_slotOffsets [1] = (char*)&dummy4offset.source - (char*)&dummy4offset;
  wtx_msg_mem_move_desc_slotOffsets [2] = (char*)&dummy4offset.destination - (char*)&dummy4offset;
  wtx_msg_mem_move_desc_slotOffsets [3] = (char*)&dummy4offset.numBytes - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_move_desc_struct,&wtx_msg_mem_move_desc_type,&wtx_msg_mem_move_desc_ptr );
 };
 {  // Compute wtx_msg_mem_set_desc structure offset
  struct wtx_msg_mem_set_desc dummy4offset;
  wtx_msg_mem_set_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_mem_set_desc_slotOffsets [1] = (char*)&dummy4offset.value - (char*)&dummy4offset;
  wtx_msg_mem_set_desc_slotOffsets [2] = (char*)&dummy4offset.width - (char*)&dummy4offset;
  wtx_msg_mem_set_desc_slotOffsets [3] = (char*)&dummy4offset.startAddr - (char*)&dummy4offset;
  wtx_msg_mem_set_desc_slotOffsets [4] = (char*)&dummy4offset.numItems - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_mem_set_desc_struct,&wtx_msg_mem_set_desc_type,&wtx_msg_mem_set_desc_ptr );
 };
 {  // Compute wtx_msg_context_desc structure offset
  struct wtx_msg_context_desc dummy4offset;
  wtx_msg_context_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [1] = (char*)&dummy4offset.contextType - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [2] = (char*)&dummy4offset.returnType - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [3] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [4] = (char*)&dummy4offset.priority - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [5] = (char*)&dummy4offset.options - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [6] = (char*)&dummy4offset.stackBase - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [7] = (char*)&dummy4offset.stackSize - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [8] = (char*)&dummy4offset.entry - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [9] = (char*)&dummy4offset.redirIn - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [10] = (char*)&dummy4offset.redirOut - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [11] = (char*)&dummy4offset.args - (char*)&dummy4offset;
  wtx_msg_context_desc_slotOffsets [12] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_context_desc_struct,&wtx_msg_context_desc_type,&wtx_msg_context_desc_ptr );
 };
 {  // Compute wtx_msg_context_step_desc structure offset
  struct wtx_msg_context_step_desc dummy4offset;
  wtx_msg_context_step_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_context_step_desc_slotOffsets [1] = (char*)&dummy4offset.context - (char*)&dummy4offset;
  wtx_msg_context_step_desc_slotOffsets [2] = (char*)&dummy4offset.startAddr - (char*)&dummy4offset;
  wtx_msg_context_step_desc_slotOffsets [3] = (char*)&dummy4offset.endAddr - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_context_step_desc_struct,&wtx_msg_context_step_desc_type,&wtx_msg_context_step_desc_ptr );
 };
 {  // Compute wtx_gopher_tape structure offset
  struct wtx_gopher_tape dummy4offset;
  wtx_gopher_tape_slotOffsets [0] = (char*)&dummy4offset.len - (char*)&dummy4offset;
  wtx_gopher_tape_slotOffsets [1] = (char*)&dummy4offset.data - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_gopher_tape_struct,&wtx_gopher_tape_type,&wtx_gopher_tape_ptr );
 };
 {  // Compute WTX_MSG_GOPHER_TAPE structure offset
  struct WTX_MSG_GOPHER_TAPE dummy4offset;
  WTX_MSG_GOPHER_TAPE_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  WTX_MSG_GOPHER_TAPE_slotOffsets [1] = (char*)&dummy4offset.tape - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&WTX_MSG_GOPHER_TAPE_struct,&WTX_MSG_GOPHER_TAPE_type,&WTX_MSG_GOPHER_TAPE_ptr );
 };
 {  // Compute wtx_msg_wtxregd_pattern structure offset
  struct wtx_msg_wtxregd_pattern dummy4offset;
  wtx_msg_wtxregd_pattern_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_wtxregd_pattern_slotOffsets [1] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_msg_wtxregd_pattern_slotOffsets [2] = (char*)&dummy4offset.type - (char*)&dummy4offset;
  wtx_msg_wtxregd_pattern_slotOffsets [3] = (char*)&dummy4offset.key - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_wtxregd_pattern_struct,&wtx_msg_wtxregd_pattern_type,&wtx_msg_wtxregd_pattern_ptr );
 };
 {  // Compute wtx_svr_desc structure offset
  struct wtx_svr_desc dummy4offset;
  wtx_svr_desc_slotOffsets [0] = (char*)&dummy4offset.wpwrName - (char*)&dummy4offset;
  wtx_svr_desc_slotOffsets [1] = (char*)&dummy4offset.wpwrType - (char*)&dummy4offset;
  wtx_svr_desc_slotOffsets [2] = (char*)&dummy4offset.wpwrKey - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_svr_desc_struct,&wtx_svr_desc_type,&wtx_svr_desc_ptr );
 };
 {  // Compute wtx_msg_svr_desc structure offset
  struct wtx_msg_svr_desc dummy4offset;
  wtx_msg_svr_desc_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_svr_desc_slotOffsets [1] = (char*)&dummy4offset.wtxSvrDesc - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_svr_desc_struct,&wtx_msg_svr_desc_type,&wtx_msg_svr_desc_ptr );
 };
 {  // Compute wtx_svr_desc_q structure offset
  struct wtx_svr_desc_q dummy4offset;
  wtx_svr_desc_q_slotOffsets [0] = (char*)&dummy4offset.wtxSvrDesc - (char*)&dummy4offset;
  wtx_svr_desc_q_slotOffsets [1] = (char*)&dummy4offset.pNext - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_svr_desc_q_struct,&wtx_svr_desc_q_type,&wtx_svr_desc_q_ptr );
 };
 {  // Compute wtx_msg_svr_desc_q structure offset
  struct wtx_msg_svr_desc_q dummy4offset;
  wtx_msg_svr_desc_q_slotOffsets [0] = (char*)&dummy4offset.wtxCore - (char*)&dummy4offset;
  wtx_msg_svr_desc_q_slotOffsets [1] = (char*)&dummy4offset.wtxSvrDescQ - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_msg_svr_desc_q_struct,&wtx_msg_svr_desc_q_type,&wtx_msg_svr_desc_q_ptr );
 };
 {  // Compute wtx_context_desc structure offset
  struct wtx_context_desc dummy4offset;
  wtx_context_desc_slotOffsets [0] = (char*)&dummy4offset.contextType - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [1] = (char*)&dummy4offset.returnType - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [2] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [3] = (char*)&dummy4offset.priority - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [4] = (char*)&dummy4offset.options - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [5] = (char*)&dummy4offset.stackBase - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [6] = (char*)&dummy4offset.stackSize - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [7] = (char*)&dummy4offset.entry - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [8] = (char*)&dummy4offset.redirIn - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [9] = (char*)&dummy4offset.redirOut - (char*)&dummy4offset;
  wtx_context_desc_slotOffsets [10] = (char*)&dummy4offset.args - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_context_desc_struct,&wtx_context_desc_type,&wtx_context_desc_ptr );
 };
 {  // Compute wtx_evtpt_list structure offset
  struct wtx_evtpt_list dummy4offset;
  wtx_evtpt_list_slotOffsets [0] = (char*)&dummy4offset.nEvtpt - (char*)&dummy4offset;
  wtx_evtpt_list_slotOffsets [1] = (char*)&dummy4offset.pEvtpt - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_evtpt_list_struct,&wtx_evtpt_list_type,&wtx_evtpt_list_ptr );
 };
 {  // Compute wtx_ld_m_file_desc structure offset
  struct wtx_ld_m_file_desc dummy4offset;
  wtx_ld_m_file_desc_slotOffsets [0] = (char*)&dummy4offset.filename - (char*)&dummy4offset;
  wtx_ld_m_file_desc_slotOffsets [1] = (char*)&dummy4offset.loadFlag - (char*)&dummy4offset;
  wtx_ld_m_file_desc_slotOffsets [2] = (char*)&dummy4offset.moduleId - (char*)&dummy4offset;
  wtx_ld_m_file_desc_slotOffsets [3] = (char*)&dummy4offset.nSections - (char*)&dummy4offset;
  wtx_ld_m_file_desc_slotOffsets [4] = (char*)&dummy4offset.section - (char*)&dummy4offset;
  wtx_ld_m_file_desc_slotOffsets [5] = (char*)&dummy4offset.undefSymList - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_ld_m_file_desc_struct,&wtx_ld_m_file_desc_type,&wtx_ld_m_file_desc_ptr );
 };
 {  // Compute wtx_mem_info structure offset
  struct wtx_mem_info dummy4offset;
  wtx_mem_info_slotOffsets [0] = (char*)&dummy4offset.curBytesFree - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [1] = (char*)&dummy4offset.curBytesAllocated - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [2] = (char*)&dummy4offset.cumBytesAllocated - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [3] = (char*)&dummy4offset.curBlocksFree - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [4] = (char*)&dummy4offset.curBlocksAlloc - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [5] = (char*)&dummy4offset.cumBlocksAlloc - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [6] = (char*)&dummy4offset.avgFreeBlockSize - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [7] = (char*)&dummy4offset.avgAllocBlockSize - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [8] = (char*)&dummy4offset.cumAvgAllocBlockSize - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [9] = (char*)&dummy4offset.biggestBlockSize - (char*)&dummy4offset;
  wtx_mem_info_slotOffsets [10] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_mem_info_struct,&wtx_mem_info_type,&wtx_mem_info_ptr );
 };
 {  // Compute wtx_module_info structure offset
  struct wtx_module_info dummy4offset;
  wtx_module_info_slotOffsets [0] = (char*)&dummy4offset.moduleId - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [1] = (char*)&dummy4offset.moduleName - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [2] = (char*)&dummy4offset.format - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [3] = (char*)&dummy4offset.group - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [4] = (char*)&dummy4offset.loadFlag - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [5] = (char*)&dummy4offset.nSegments - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [6] = (char*)&dummy4offset.segment - (char*)&dummy4offset;
  wtx_module_info_slotOffsets [7] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_module_info_struct,&wtx_module_info_type,&wtx_module_info_ptr );
 };
 {  // Compute wtx_module_list structure offset
  struct wtx_module_list dummy4offset;
  wtx_module_list_slotOffsets [0] = (char*)&dummy4offset.numObjMod - (char*)&dummy4offset;
  wtx_module_list_slotOffsets [1] = (char*)&dummy4offset.modIdList - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_module_list_struct,&wtx_module_list_type,&wtx_module_list_ptr );
 };
 {  // Compute wtx_ts_info structure offset
  struct wtx_ts_info dummy4offset;
  wtx_ts_info_slotOffsets [0] = (char*)&dummy4offset.tgtLinkDesc - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [1] = (char*)&dummy4offset.tgtInfo - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [2] = (char*)&dummy4offset.pWtxToolDesc - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [3] = (char*)&dummy4offset.version - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [4] = (char*)&dummy4offset.userName - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [5] = (char*)&dummy4offset.startTime - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [6] = (char*)&dummy4offset.accessTime - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [7] = (char*)&dummy4offset.lockMsg - (char*)&dummy4offset;
  wtx_ts_info_slotOffsets [8] = (char*)&dummy4offset.pReserved - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wtx_ts_info_struct,&wtx_ts_info_type,&wtx_ts_info_ptr );
 };

 {  // Compute Union_Wtx_0 Unions offset
  union Union_Wtx_0 dummy4offset;
  Union_Wtx_0_slotOffsets [0] = (char*)&dummy4offset.v_int8 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [1] = (char*)&dummy4offset.v_int16 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [2] = (char*)&dummy4offset.v_int32 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [3] = (char*)&dummy4offset.v_uint8 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [4] = (char*)&dummy4offset.v_uint16 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [5] = (char*)&dummy4offset.v_uint32 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [6] = (char*)&dummy4offset.v_double - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [7] = (char*)&dummy4offset.v_bool32 - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [8] = (char*)&dummy4offset.v_pchar - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [9] = (char*)&dummy4offset.v_pvoid - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [10] = (char*)&dummy4offset.v_tgt_addr - (char*)&dummy4offset;
  Union_Wtx_0_slotOffsets [11] = (char*)&dummy4offset.v_tgt_arg - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&Union_Wtx_0_union,&Union_Wtx_0_type,&Union_Wtx_0_ptr );
 };

 {  // Compute Union_Wtx_1 Unions offset
  union Union_Wtx_1 dummy4offset;
  Union_Wtx_1_slotOffsets [0] = (char*)&dummy4offset.moduleId - (char*)&dummy4offset;
  Union_Wtx_1_slotOffsets [1] = (char*)&dummy4offset.moduleName - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&Union_Wtx_1_union,&Union_Wtx_1_type,&Union_Wtx_1_ptr );
 };
 
 /* *** Type Alias Section *** */
 jWrapTypeAlias (&module,"long" ,"TGT_ADDR_T");
 jWrapTypeAlias (&module,"long" ,"TGT_ARG_T");
 jWrapTypeAlias (&module,"long" ,"TGT_INT_T");
 jWrapTypeAlias (&module,"int" ,"STATUS");
 jWrapTypeAlias (&module,"int" ,"BOOL");
 jWrapTypeAlias (&module,"char" ,"INT8");
 jWrapTypeAlias (&module,"char" ,"UINT8");
 jWrapTypeAlias (&module,"short" ,"INT16");
 jWrapTypeAlias (&module,"short" ,"UINT16");
 jWrapTypeAlias (&module,"int" ,"INT32");
 jWrapTypeAlias (&module,"int" ,"UINT32");
 jWrapTypeAlias (&module,"char" ,"UCHAR");
 jWrapTypeAlias (&module,"short" ,"USHORT");
 jWrapTypeAlias (&module,"int" ,"UINT");
 jWrapTypeAlias (&module,"long" ,"ULONG");
 jWrapTypeAlias (&module,"wtx_error_t" ,"WTX_ERROR_T");
 jWrapTypeAlias (&module,"long" ,"BOOL32");
 jWrapTypeAlias (&module,"long" ,"WTX_STATUS");
 jWrapTypeAlias (&module,"long" ,"WTX_REQUEST");
 jWrapTypeAlias (&module,"wtx_event_type" ,"WTX_EVENT_TYPE");
 jWrapTypeAlias (&module,"wtx_context_type" ,"WTX_CONTEXT_TYPE");
 jWrapTypeAlias (&module,"TGT_ADDR_T" ,"WTX_CONTEXT_ID_T");
 jWrapTypeAlias (&module,"wtx_action_type" ,"WTX_ACTION_TYPE");
 jWrapTypeAlias (&module,"wtx_return_type" ,"WTX_RETURN_TYPE");
 jWrapTypeAlias (&module,"wtx_reg_set_type" ,"WTX_REG_SET_TYPE");
 jWrapTypeAlias (&module,"wtx_agent_mode_type" ,"WTX_AGENT_MODE_TYPE");
 jWrapTypeAlias (&module,"wtx_open_flag" ,"WTX_OPEN_FLAG");
 jWrapTypeAlias (&module,"wtx_core" ,"WTX_CORE");
 jWrapTypeAlias (&module,"wtx_desc" ,"WTX_DESC");
 jWrapTypeAlias (&module,"wtx_desc_q" ,"WTX_DESC_Q");
 jWrapTypeAlias (&module,"wtx_value_t" ,"WTX_VALUE_T");
 jWrapTypeAlias (&module,"wtx_value" ,"WTX_VALUE");
 jWrapTypeAlias (&module,"wtx_msg_result" ,"WTX_MSG_RESULT");
 jWrapTypeAlias (&module,"wtx_msg_param" ,"WTX_MSG_PARAM");
 jWrapTypeAlias (&module,"wtx_mem_region" ,"WTX_MEM_REGION");
 jWrapTypeAlias (&module,"wtx_rt_info" ,"WTX_RT_INFO");
 jWrapTypeAlias (&module,"wtx_agent_info" ,"WTX_AGENT_INFO");
 jWrapTypeAlias (&module,"wtx_tgt_info" ,"WTX_TGT_INFO");
 jWrapTypeAlias (&module,"wtx_tgt_link_desc" ,"WTX_TGT_LINK_DESC");
 jWrapTypeAlias (&module,"wtx_tool_desc" ,"WTX_TOOL_DESC");
 jWrapTypeAlias (&module,"WTX_TOOL_DESC_Ptr" ,"TOOL_ID");
 jWrapTypeAlias (&module,"wtx_msg_ts_info" ,"WTX_MSG_TS_INFO");
 jWrapTypeAlias (&module,"wtx_msg_ts_lock" ,"WTX_MSG_TS_LOCK");
 jWrapTypeAlias (&module,"wtx_msg_ts_unlock" ,"WTX_MSG_TS_UNLOCK");
 jWrapTypeAlias (&module,"wtx_msg_tool_desc" ,"WTX_MSG_TOOL_DESC");
 jWrapTypeAlias (&module,"wtx_msg_tool_id" ,"WTX_MSG_TOOL_ID");
 jWrapTypeAlias (&module,"wtx_msg_kill_desc" ,"WTX_MSG_KILL_DESC");
 jWrapTypeAlias (&module,"wtx_symbol" ,"WTX_SYMBOL");
 jWrapTypeAlias (&module,"wtx_msg_symbol_desc" ,"WTX_MSG_SYMBOL_DESC");
 jWrapTypeAlias (&module,"wtx_sym_list" ,"WTX_SYM_LIST");
 jWrapTypeAlias (&module,"wtx_msg_sym_list" ,"WTX_MSG_SYM_LIST");
 jWrapTypeAlias (&module,"wtx_msg_open_desc" ,"WTX_MSG_OPEN_DESC");
 jWrapTypeAlias (&module,"wtx_msg_vio_ctl_desc" ,"WTX_MSG_VIO_CTL_DESC");
 jWrapTypeAlias (&module,"wtx_msg_vio_copy_desc" ,"WTX_MSG_VIO_COPY_DESC");
 jWrapTypeAlias (&module,"wtx_vio_file_desc" ,"WTX_VIO_FILE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_vio_file_list" ,"WTX_MSG_VIO_FILE_LIST");
 jWrapTypeAlias (&module,"ld_m_section" ,"LD_M_SECTION");
 jWrapTypeAlias (&module,"wtx_msg_ld_m_file_desc" ,"WTX_MSG_LD_M_FILE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_module_list" ,"WTX_MSG_MODULE_LIST");
 jWrapTypeAlias (&module,"obj_segment" ,"OBJ_SEGMENT");
 jWrapTypeAlias (&module,"wtx_msg_module_info" ,"WTX_MSG_MODULE_INFO");
 jWrapTypeAlias (&module,"wtx_msg_mod_name_or_id" ,"WTX_MSG_MOD_NAME_OR_ID");
 jWrapTypeAlias (&module,"wtx_sym_tbl_info" ,"WTX_SYM_TBL_INFO");
 jWrapTypeAlias (&module,"wtx_msg_sym_tbl_info" ,"WTX_MSG_SYM_TBL_INFO");
 jWrapTypeAlias (&module,"wtx_msg_sym_match_desc" ,"WTX_MSG_SYM_MATCH_DESC");
 jWrapTypeAlias (&module,"wtx_event_desc" ,"WTX_EVENT_DESC");
 jWrapTypeAlias (&module,"wtx_msg_event_desc" ,"WTX_MSG_EVENT_DESC");
 jWrapTypeAlias (&module,"wtx_msg_event_reg_desc" ,"WTX_MSG_EVENT_REG_DESC");
 jWrapTypeAlias (&module,"wtx_wdb_service_desc" ,"WTX_WDB_SERVICE_DESC");
 jWrapTypeAlias (&module,"wtx_wtx_service_desc" ,"WTX_WTX_SERVICE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_service_desc" ,"WTX_MSG_SERVICE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_service_list" ,"WTX_MSG_SERVICE_LIST");
 jWrapTypeAlias (&module,"wtx_console_desc" ,"WTX_CONSOLE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_console_desc" ,"WTX_MSG_CONSOLE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_mem_info" ,"WTX_MSG_MEM_INFO");
 jWrapTypeAlias (&module,"wtx_mem_xfer" ,"WTX_MEM_XFER");
 jWrapTypeAlias (&module,"wtx_msg_mem_xfer_desc" ,"WTX_MSG_MEM_XFER_DESC");
 jWrapTypeAlias (&module,"wtx_event" ,"WTX_EVENT");
 jWrapTypeAlias (&module,"wtx_context" ,"WTX_CONTEXT");
 jWrapTypeAlias (&module,"wtx_action" ,"WTX_ACTION");
 jWrapTypeAlias (&module,"wtx_msg_context" ,"WTX_MSG_CONTEXT");
 jWrapTypeAlias (&module,"wtx_evtpt" ,"WTX_EVTPT");
 jWrapTypeAlias (&module,"wtx_msg_evtpt_desc" ,"WTX_MSG_EVTPT_DESC");
 jWrapTypeAlias (&module,"wtx_msg_evtpt_list" ,"WTX_MSG_EVTPT_LIST");
 jWrapTypeAlias (&module,"wtx_msg_reg_write" ,"WTX_MSG_REG_WRITE");
 jWrapTypeAlias (&module,"wtx_msg_mem_block_desc" ,"WTX_MSG_MEM_BLOCK_DESC");
 jWrapTypeAlias (&module,"wtx_msg_mem_read_desc" ,"WTX_MSG_MEM_READ_DESC");
 jWrapTypeAlias (&module,"wtx_msg_mem_copy_desc" ,"WTX_MSG_MEM_COPY_DESC");
 jWrapTypeAlias (&module,"wtx_msg_mem_scan_desc" ,"WTX_MSG_MEM_SCAN_DESC");
 jWrapTypeAlias (&module,"wtx_msg_mem_move_desc" ,"WTX_MSG_MEM_MOVE_DESC");
 jWrapTypeAlias (&module,"wtx_msg_mem_set_desc" ,"WTX_MSG_MEM_SET_DESC");
 jWrapTypeAlias (&module,"wtx_msg_context_desc" ,"WTX_MSG_CONTEXT_DESC");
 jWrapTypeAlias (&module,"wtx_msg_context_step_desc" ,"WTX_MSG_CONTEXT_STEP_DESC");
 jWrapTypeAlias (&module,"wtx_gopher_tape" ,"WTX_GOPHER_TAPE");
 jWrapTypeAlias (&module,"wtx_msg_wtxregd_pattern" ,"WTX_MSG_WTXREGD_PATTERN");
 jWrapTypeAlias (&module,"wtx_svr_desc" ,"WTX_SVR_DESC");
 jWrapTypeAlias (&module,"wtx_msg_svr_desc" ,"WTX_MSG_SVR_DESC");
 jWrapTypeAlias (&module,"wtx_svr_desc_q" ,"WTX_SVR_DESC_Q");
 jWrapTypeAlias (&module,"wtx_msg_svr_desc_q" ,"WTX_MSG_SVR_DESC_Q");
 jWrapTypeAlias (&module,"wtx_endian_t" ,"WTX_ENDIAN_T");
 jWrapTypeAlias (&module,"HWTX_Ptr" ,"_wtx");
 jWrapTypeAlias (&module,"WTX_HANDLER_T_Ptr" ,"_wtx_handler_t");
 jWrapTypeAlias (&module,"wtx_context_desc" ,"WTX_CONTEXT_DESC");
 jWrapTypeAlias (&module,"wtx_evtpt_list" ,"WTX_EVTPT_LIST");
 jWrapTypeAlias (&module,"wtx_ld_m_file_desc" ,"WTX_LD_M_FILE_DESC");
 jWrapTypeAlias (&module,"wtx_mem_info" ,"WTX_MEM_INFO");
 jWrapTypeAlias (&module,"wtx_module_info" ,"WTX_MODULE_INFO");
 jWrapTypeAlias (&module,"wtx_module_list" ,"WTX_MODULE_LIST");
 jWrapTypeAlias (&module,"wtx_ts_info" ,"WTX_TS_INFO");

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_Wtx",sizeof(Define_Wtx));
 jWrapTypeCheck (&usedType [1],"wtx_core",sizeof(struct wtx_core));
 jWrapTypeCheck (&usedType [2],"UINT32",sizeof(UINT32));
 jWrapTypeCheck (&usedType [3],"WTX_ERROR_T",sizeof(WTX_ERROR_T));
 jWrapTypeCheck (&usedType [4],"wtx_desc",sizeof(struct wtx_desc));
 jWrapTypeCheck (&usedType [5],"char_Ptr",sizeof(char*));
 jWrapTypeCheck (&usedType [6],"wtx_desc_q",sizeof(struct wtx_desc_q));
 jWrapTypeCheck (&usedType [7],"wtx_desc_q_Ptr",sizeof(struct wtx_desc_q*));
 jWrapTypeCheck (&usedType [8],"wtx_value",sizeof(struct wtx_value));
 jWrapTypeCheck (&usedType [9],"WTX_VALUE_T",sizeof(WTX_VALUE_T));
 jWrapTypeCheck (&usedType [10],"Union_Wtx_0",sizeof(union Union_Wtx_0));
 jWrapTypeCheck (&usedType [11],"wtx_msg_result",sizeof(struct wtx_msg_result));
 jWrapTypeCheck (&usedType [12],"WTX_CORE",sizeof(WTX_CORE));
 jWrapTypeCheck (&usedType [13],"WTX_VALUE",sizeof(WTX_VALUE));
 jWrapTypeCheck (&usedType [14],"wtx_msg_param",sizeof(struct wtx_msg_param));
 jWrapTypeCheck (&usedType [15],"wtx_mem_region",sizeof(struct wtx_mem_region));
 jWrapTypeCheck (&usedType [16],"TGT_ADDR_T",sizeof(TGT_ADDR_T));
 jWrapTypeCheck (&usedType [17],"wtx_rt_info",sizeof(struct wtx_rt_info));
 jWrapTypeCheck (&usedType [18],"BOOL32",sizeof(BOOL32));
 jWrapTypeCheck (&usedType [19],"WTX_MEM_REGION_Ptr",sizeof(WTX_MEM_REGION*));
 jWrapTypeCheck (&usedType [20],"wtx_agent_info",sizeof(struct wtx_agent_info));
 jWrapTypeCheck (&usedType [21],"wtx_tgt_info",sizeof(struct wtx_tgt_info));
 jWrapTypeCheck (&usedType [22],"WTX_AGENT_INFO",sizeof(WTX_AGENT_INFO));
 jWrapTypeCheck (&usedType [23],"WTX_RT_INFO",sizeof(WTX_RT_INFO));
 jWrapTypeCheck (&usedType [24],"wtx_tgt_link_desc",sizeof(struct wtx_tgt_link_desc));
 jWrapTypeCheck (&usedType [25],"wtx_tool_desc",sizeof(struct wtx_tool_desc));
 jWrapTypeCheck (&usedType [26],"void_Ptr",sizeof(void*));
 jWrapTypeCheck (&usedType [27],"wtx_tool_desc_Ptr",sizeof(struct wtx_tool_desc*));
 jWrapTypeCheck (&usedType [28],"wtx_msg_ts_info",sizeof(struct wtx_msg_ts_info));
 jWrapTypeCheck (&usedType [29],"WTX_TGT_LINK_DESC",sizeof(WTX_TGT_LINK_DESC));
 jWrapTypeCheck (&usedType [30],"WTX_TGT_INFO",sizeof(WTX_TGT_INFO));
 jWrapTypeCheck (&usedType [31],"WTX_TOOL_DESC_Ptr",sizeof(WTX_TOOL_DESC*));
 jWrapTypeCheck (&usedType [32],"wtx_msg_ts_lock",sizeof(struct wtx_msg_ts_lock));
 jWrapTypeCheck (&usedType [33],"wtx_msg_ts_unlock",sizeof(struct wtx_msg_ts_unlock));
 jWrapTypeCheck (&usedType [34],"wtx_msg_tool_desc",sizeof(struct wtx_msg_tool_desc));
 jWrapTypeCheck (&usedType [35],"WTX_TOOL_DESC",sizeof(WTX_TOOL_DESC));
 jWrapTypeCheck (&usedType [36],"wtx_msg_tool_id",sizeof(struct wtx_msg_tool_id));
 jWrapTypeCheck (&usedType [37],"wtx_msg_kill_desc",sizeof(struct wtx_msg_kill_desc));
 jWrapTypeCheck (&usedType [38],"wtx_symbol",sizeof(struct wtx_symbol));
 jWrapTypeCheck (&usedType [39],"UINT8",sizeof(UINT8));
 jWrapTypeCheck (&usedType [40],"UINT16",sizeof(UINT16));
 jWrapTypeCheck (&usedType [41],"wtx_symbol_Ptr",sizeof(struct wtx_symbol*));
 jWrapTypeCheck (&usedType [42],"wtx_msg_symbol_desc",sizeof(struct wtx_msg_symbol_desc));
 jWrapTypeCheck (&usedType [43],"WTX_SYMBOL",sizeof(WTX_SYMBOL));
 jWrapTypeCheck (&usedType [44],"wtx_sym_list",sizeof(struct wtx_sym_list));
 jWrapTypeCheck (&usedType [45],"WTX_SYMBOL_Ptr",sizeof(WTX_SYMBOL*));
 jWrapTypeCheck (&usedType [46],"wtx_msg_sym_list",sizeof(struct wtx_msg_sym_list));
 jWrapTypeCheck (&usedType [47],"WTX_SYM_LIST",sizeof(WTX_SYM_LIST));
 jWrapTypeCheck (&usedType [48],"wtx_msg_open_desc",sizeof(struct wtx_msg_open_desc));
 jWrapTypeCheck (&usedType [49],"WTX_OPEN_FLAG",sizeof(WTX_OPEN_FLAG));
 jWrapTypeCheck (&usedType [50],"INT32",sizeof(INT32));
 jWrapTypeCheck (&usedType [51],"wtx_msg_vio_ctl_desc",sizeof(struct wtx_msg_vio_ctl_desc));
 jWrapTypeCheck (&usedType [52],"wtx_msg_vio_copy_desc",sizeof(struct wtx_msg_vio_copy_desc));
 jWrapTypeCheck (&usedType [53],"wtx_vio_file_desc",sizeof(struct wtx_vio_file_desc));
 jWrapTypeCheck (&usedType [54],"wtx_vio_file_desc_Ptr",sizeof(struct wtx_vio_file_desc*));
 jWrapTypeCheck (&usedType [55],"wtx_msg_vio_file_list",sizeof(struct wtx_msg_vio_file_list));
 jWrapTypeCheck (&usedType [56],"WTX_VIO_FILE_DESC_Ptr",sizeof(WTX_VIO_FILE_DESC*));
 jWrapTypeCheck (&usedType [57],"ld_m_section",sizeof(struct ld_m_section));
 jWrapTypeCheck (&usedType [58],"wtx_msg_ld_m_file_desc",sizeof(struct wtx_msg_ld_m_file_desc));
 jWrapTypeCheck (&usedType [59],"LD_M_SECTION_Ptr",sizeof(LD_M_SECTION*));
 jWrapTypeCheck (&usedType [60],"wtx_msg_module_list",sizeof(struct wtx_msg_module_list));
 jWrapTypeCheck (&usedType [61],"UINT32_Ptr",sizeof(UINT32*));
 jWrapTypeCheck (&usedType [62],"obj_segment",sizeof(struct obj_segment));
 jWrapTypeCheck (&usedType [63],"wtx_msg_module_info",sizeof(struct wtx_msg_module_info));
 jWrapTypeCheck (&usedType [64],"int",sizeof(int));
 jWrapTypeCheck (&usedType [65],"OBJ_SEGMENT_Ptr",sizeof(OBJ_SEGMENT*));
 jWrapTypeCheck (&usedType [66],"wtx_msg_mod_name_or_id",sizeof(struct wtx_msg_mod_name_or_id));
 jWrapTypeCheck (&usedType [67],"wtx_sym_tbl_info",sizeof(struct wtx_sym_tbl_info));
 jWrapTypeCheck (&usedType [68],"wtx_msg_sym_tbl_info",sizeof(struct wtx_msg_sym_tbl_info));
 jWrapTypeCheck (&usedType [69],"wtx_msg_sym_match_desc",sizeof(struct wtx_msg_sym_match_desc));
 jWrapTypeCheck (&usedType [70],"Union_Wtx_1",sizeof(union Union_Wtx_1));
 jWrapTypeCheck (&usedType [71],"wtx_event_desc",sizeof(struct wtx_event_desc));
 jWrapTypeCheck (&usedType [72],"wtx_msg_event_desc",sizeof(struct wtx_msg_event_desc));
 jWrapTypeCheck (&usedType [73],"WTX_EVENT_DESC",sizeof(WTX_EVENT_DESC));
 jWrapTypeCheck (&usedType [74],"wtx_msg_event_reg_desc",sizeof(struct wtx_msg_event_reg_desc));
 jWrapTypeCheck (&usedType [75],"wtx_wdb_service_desc",sizeof(struct wtx_wdb_service_desc));
 jWrapTypeCheck (&usedType [76],"wtx_wtx_service_desc",sizeof(struct wtx_wtx_service_desc));
 jWrapTypeCheck (&usedType [77],"wtx_msg_service_desc",sizeof(struct wtx_msg_service_desc));
 jWrapTypeCheck (&usedType [78],"WTX_WTX_SERVICE_DESC_Ptr",sizeof(WTX_WTX_SERVICE_DESC*));
 jWrapTypeCheck (&usedType [79],"WTX_WDB_SERVICE_DESC_Ptr",sizeof(WTX_WDB_SERVICE_DESC*));
 jWrapTypeCheck (&usedType [80],"wtx_msg_service_list",sizeof(struct wtx_msg_service_list));
 jWrapTypeCheck (&usedType [81],"wtx_console_desc",sizeof(struct wtx_console_desc));
 jWrapTypeCheck (&usedType [82],"wtx_msg_console_desc",sizeof(struct wtx_msg_console_desc));
 jWrapTypeCheck (&usedType [83],"WTX_CONSOLE_DESC",sizeof(WTX_CONSOLE_DESC));
 jWrapTypeCheck (&usedType [84],"wtx_msg_mem_info",sizeof(struct wtx_msg_mem_info));
 jWrapTypeCheck (&usedType [85],"wtx_mem_xfer",sizeof(struct wtx_mem_xfer));
 jWrapTypeCheck (&usedType [86],"wtx_msg_mem_xfer_desc",sizeof(struct wtx_msg_mem_xfer_desc));
 jWrapTypeCheck (&usedType [87],"WTX_MEM_XFER",sizeof(WTX_MEM_XFER));
 jWrapTypeCheck (&usedType [88],"wtx_event",sizeof(struct wtx_event));
 jWrapTypeCheck (&usedType [89],"WTX_EVENT_TYPE",sizeof(WTX_EVENT_TYPE));
 jWrapTypeCheck (&usedType [90],"TGT_ARG_T",sizeof(TGT_ARG_T));
 jWrapTypeCheck (&usedType [91],"wtx_context",sizeof(struct wtx_context));
 jWrapTypeCheck (&usedType [92],"WTX_CONTEXT_TYPE",sizeof(WTX_CONTEXT_TYPE));
 jWrapTypeCheck (&usedType [93],"WTX_CONTEXT_ID_T",sizeof(WTX_CONTEXT_ID_T));
 jWrapTypeCheck (&usedType [94],"wtx_action",sizeof(struct wtx_action));
 jWrapTypeCheck (&usedType [95],"WTX_ACTION_TYPE",sizeof(WTX_ACTION_TYPE));
 jWrapTypeCheck (&usedType [96],"wtx_msg_context",sizeof(struct wtx_msg_context));
 jWrapTypeCheck (&usedType [97],"wtx_evtpt",sizeof(struct wtx_evtpt));
 jWrapTypeCheck (&usedType [98],"WTX_EVENT",sizeof(WTX_EVENT));
 jWrapTypeCheck (&usedType [99],"WTX_CONTEXT",sizeof(WTX_CONTEXT));
 jWrapTypeCheck (&usedType [100],"WTX_ACTION",sizeof(WTX_ACTION));
 jWrapTypeCheck (&usedType [101],"wtx_msg_evtpt_desc",sizeof(struct wtx_msg_evtpt_desc));
 jWrapTypeCheck (&usedType [102],"WTX_EVTPT",sizeof(WTX_EVTPT));
 jWrapTypeCheck (&usedType [103],"wtx_msg_evtpt_list",sizeof(struct wtx_msg_evtpt_list));
 jWrapTypeCheck (&usedType [104],"WTX_EVTPT_Ptr",sizeof(WTX_EVTPT*));
 jWrapTypeCheck (&usedType [105],"wtx_msg_reg_write",sizeof(struct wtx_msg_reg_write));
 jWrapTypeCheck (&usedType [106],"WTX_REG_SET_TYPE",sizeof(WTX_REG_SET_TYPE));
 jWrapTypeCheck (&usedType [107],"WTX_MSG_REG_READ",sizeof(struct WTX_MSG_REG_READ));
 jWrapTypeCheck (&usedType [108],"WTX_MEM_REGION",sizeof(WTX_MEM_REGION));
 jWrapTypeCheck (&usedType [109],"wtx_msg_mem_block_desc",sizeof(struct wtx_msg_mem_block_desc));
 jWrapTypeCheck (&usedType [110],"wtx_msg_mem_read_desc",sizeof(struct wtx_msg_mem_read_desc));
 jWrapTypeCheck (&usedType [111],"wtx_msg_mem_copy_desc",sizeof(struct wtx_msg_mem_copy_desc));
 jWrapTypeCheck (&usedType [112],"wtx_msg_mem_scan_desc",sizeof(struct wtx_msg_mem_scan_desc));
 jWrapTypeCheck (&usedType [113],"wtx_msg_mem_move_desc",sizeof(struct wtx_msg_mem_move_desc));
 jWrapTypeCheck (&usedType [114],"wtx_msg_mem_set_desc",sizeof(struct wtx_msg_mem_set_desc));
 jWrapTypeCheck (&usedType [115],"wtx_msg_context_desc",sizeof(struct wtx_msg_context_desc));
 jWrapTypeCheck (&usedType [116],"WTX_RETURN_TYPE",sizeof(WTX_RETURN_TYPE));
 jWrapTypeCheck (&usedType [117],"wtx_msg_context_step_desc",sizeof(struct wtx_msg_context_step_desc));
 jWrapTypeCheck (&usedType [118],"wtx_gopher_tape",sizeof(struct wtx_gopher_tape));
 jWrapTypeCheck (&usedType [119],"WTX_MSG_GOPHER_TAPE",sizeof(struct WTX_MSG_GOPHER_TAPE));
 jWrapTypeCheck (&usedType [120],"WTX_GOPHER_TAPE",sizeof(WTX_GOPHER_TAPE));
 jWrapTypeCheck (&usedType [121],"wtx_msg_wtxregd_pattern",sizeof(struct wtx_msg_wtxregd_pattern));
 jWrapTypeCheck (&usedType [122],"wtx_svr_desc",sizeof(struct wtx_svr_desc));
 jWrapTypeCheck (&usedType [123],"wtx_msg_svr_desc",sizeof(struct wtx_msg_svr_desc));
 jWrapTypeCheck (&usedType [124],"WTX_SVR_DESC",sizeof(WTX_SVR_DESC));
 jWrapTypeCheck (&usedType [125],"wtx_svr_desc_q",sizeof(struct wtx_svr_desc_q));
 jWrapTypeCheck (&usedType [126],"wtx_svr_desc_q_Ptr",sizeof(struct wtx_svr_desc_q*));
 jWrapTypeCheck (&usedType [127],"wtx_msg_svr_desc_q",sizeof(struct wtx_msg_svr_desc_q));
 jWrapTypeCheck (&usedType [128],"WTX_SVR_DESC_Q",sizeof(WTX_SVR_DESC_Q));
 jWrapTypeCheck (&usedType [129],"wtx_context_desc",sizeof(struct wtx_context_desc));
 jWrapTypeCheck (&usedType [130],"wtx_evtpt_list",sizeof(struct wtx_evtpt_list));
 jWrapTypeCheck (&usedType [131],"wtx_ld_m_file_desc",sizeof(struct wtx_ld_m_file_desc));
 jWrapTypeCheck (&usedType [132],"wtx_mem_info",sizeof(struct wtx_mem_info));
 jWrapTypeCheck (&usedType [133],"wtx_module_info",sizeof(struct wtx_module_info));
 jWrapTypeCheck (&usedType [134],"wtx_module_list",sizeof(struct wtx_module_list));
 jWrapTypeCheck (&usedType [135],"wtx_ts_info",sizeof(struct wtx_ts_info));
 jWrapTypeCheck (&usedType [136],"INT8",sizeof(INT8));
 jWrapTypeCheck (&usedType [137],"INT16",sizeof(INT16));
 jWrapTypeCheck (&usedType [138],"double",sizeof(double));
 jWrapTypeCheck (&usedType [139],"wtx_error_t",sizeof(enum wtx_error_t));
 jWrapTypeCheck (&usedType [140],"wtx_event_type",sizeof(enum wtx_event_type));
 jWrapTypeCheck (&usedType [141],"wtx_context_type",sizeof(enum wtx_context_type));
 jWrapTypeCheck (&usedType [142],"wtx_action_type",sizeof(enum wtx_action_type));
 jWrapTypeCheck (&usedType [143],"wtx_return_type",sizeof(enum wtx_return_type));
 jWrapTypeCheck (&usedType [144],"wtx_reg_set_type",sizeof(enum wtx_reg_set_type));
 jWrapTypeCheck (&usedType [145],"wtx_agent_mode_type",sizeof(enum wtx_agent_mode_type));
 jWrapTypeCheck (&usedType [146],"wtx_open_flag",sizeof(enum wtx_open_flag));
 jWrapTypeCheck (&usedType [147],"wtx_value_t",sizeof(enum wtx_value_t));
 jWrapTypeCheck (&usedType [148],"wtx_endian_t",sizeof(enum wtx_endian_t));
 jWrapTypeCheck (&usedType [149],"STATUS",sizeof(STATUS));
 jWrapTypeCheck (&usedType [150],"HWTX",sizeof(HWTX));
 jWrapTypeCheck (&usedType [151],"FUNCPTR",sizeof(FUNCPTR));
 jWrapTypeCheck (&usedType [152],"WTX_DESC_Ptr",sizeof(WTX_DESC*));
 jWrapTypeCheck (&usedType [153],"WTX_DESC_Q_Ptr",sizeof(WTX_DESC_Q*));
 jWrapTypeCheck (&usedType [154],"HWTX_Ptr",sizeof(HWTX *));
 jWrapTypeCheck (&usedType [155],"WTX_AGENT_MODE_TYPE",sizeof(WTX_AGENT_MODE_TYPE));
 jWrapTypeCheck (&usedType [156],"void_Ptr_Ptr",sizeof(void **));
 jWrapTypeCheck (&usedType [157],"INT32_Ptr",sizeof(INT32 *));
 jWrapTypeCheck (&usedType [158],"WTX_CONTEXT_DESC_Ptr",sizeof(WTX_CONTEXT_DESC *));
 jWrapTypeCheck (&usedType [159],"WTX_HANDLER_T",sizeof(WTX_HANDLER_T));
 jWrapTypeCheck (&usedType [160],"WTX_HANDLER_FUNC",sizeof(WTX_HANDLER_FUNC));
 jWrapTypeCheck (&usedType [161],"WTX_EVENT_DESC_Ptr",sizeof(WTX_EVENT_DESC*));
 jWrapTypeCheck (&usedType [162],"WTX_EVTPT_LIST_Ptr",sizeof(WTX_EVTPT_LIST*));
 jWrapTypeCheck (&usedType [163],"WTX_GOPHER_TAPE_Ptr",sizeof(WTX_GOPHER_TAPE*));
 jWrapTypeCheck (&usedType [164],"WTX_MEM_INFO_Ptr",sizeof(WTX_MEM_INFO*));
 jWrapTypeCheck (&usedType [165],"TGT_ADDR_T_Ptr",sizeof(TGT_ADDR_T *));
 jWrapTypeCheck (&usedType [166],"WTX_MODULE_INFO_Ptr",sizeof(WTX_MODULE_INFO*));
 jWrapTypeCheck (&usedType [167],"WTX_MODULE_LIST_Ptr",sizeof(WTX_MODULE_LIST*));
 jWrapTypeCheck (&usedType [168],"WTX_LD_M_FILE_DESC_Ptr",sizeof(WTX_LD_M_FILE_DESC*));
 jWrapTypeCheck (&usedType [169],"WTX_SYM_LIST_Ptr",sizeof(WTX_SYM_LIST*));
 jWrapTypeCheck (&usedType [170],"WTX_SYM_TBL_INFO_Ptr",sizeof(WTX_SYM_TBL_INFO*));
 jWrapTypeCheck (&usedType [171],"WTX_ENDIAN_T",sizeof(WTX_ENDIAN_T));
 jWrapTypeCheck (&usedType [172],"WTX_TS_INFO_Ptr",sizeof(WTX_TS_INFO*));
 jWrapTypeCheck (&usedType [173],"WTX_VIO_FILE_DESC_Ptr_Ptr",sizeof(WTX_VIO_FILE_DESC**));

 /* --- Functions sub-section --- */

 // register wtxEach C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Each", jTcl_wtxEach_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxInfo C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Info", jTcl_wtxInfo_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxInfoQ C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.InfoQ", jTcl_wtxInfoQ_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxInitialize C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Initialize", jTcl_wtxInitialize_3  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxProbe C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Probe", jTcl_wtxProbe_4  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxRegister C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Register", jTcl_wtxRegister_5  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTerminate C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Terminate", jTcl_wtxTerminate_6  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTimeoutSet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TimeoutSet", jTcl_wtxTimeoutSet_7  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTimeoutGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TimeoutGet", jTcl_wtxTimeoutGet_8  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxUnregister C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Unregister", jTcl_wtxUnregister_9  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxAgentModeSet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.AgentModeSet", jTcl_wtxAgentModeSet_10  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxAgentModeGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.AgentModeGet", jTcl_wtxAgentModeGet_11  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxBreakpointAdd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.BreakpointAdd", jTcl_wtxBreakpointAdd_12  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxClientDataGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ClientDataGet", jTcl_wtxClientDataGet_13  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxClientDataSet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ClientDataSet", jTcl_wtxClientDataSet_14  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxConsoleCreate C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ConsoleCreate", jTcl_wtxConsoleCreate_15  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxConsoleKill C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ConsoleKill", jTcl_wtxConsoleKill_16  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextCont C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextCont", jTcl_wtxContextCont_17  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextCreate C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextCreate", jTcl_wtxContextCreate_18  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextExitNotifyAdd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextExitNotifyAdd", jTcl_wtxContextExitNotifyAdd_19  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextKill C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextKill", jTcl_wtxContextKill_20  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextResume C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextResume", jTcl_wtxContextResume_21  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextStep C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextStep", jTcl_wtxContextStep_22  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxContextSuspend C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ContextSuspend", jTcl_wtxContextSuspend_23  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrClear C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrClear", jTcl_wtxErrClear_24  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrGet", jTcl_wtxErrGet_25  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrSet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrSet", jTcl_wtxErrSet_26  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrMsgGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrMsgGet", jTcl_wtxErrMsgGet_27  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrToMsg C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrToMsg", jTcl_wtxErrToMsg_28  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrDispatch C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrDispatch", jTcl_wtxErrDispatch_29  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrExceptionFunc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrExceptionFunc", jTcl_wtxErrExceptionFunc_30  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrHandlerAdd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrHandlerAdd", jTcl_wtxErrHandlerAdd_31  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxErrHandlerRemove C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ErrHandlerRemove", jTcl_wtxErrHandlerRemove_32  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxEventAdd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.EventAdd", jTcl_wtxEventAdd_33  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxEventGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.EventGet", jTcl_wtxEventGet_34  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxEventpointDelete C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.EventpointDelete", jTcl_wtxEventpointDelete_35  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxEventpointList C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.EventpointList", jTcl_wtxEventpointList_36  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxFileClose C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.FileClose", jTcl_wtxFileClose_37  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxFileOpen C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.FileOpen", jTcl_wtxFileOpen_38  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxFuncCall C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.FuncCall", jTcl_wtxFuncCall_39  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxDirectCall C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.DirectCall", jTcl_wtxDirectCall_40  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxGopherEval C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.GopherEval", jTcl_wtxGopherEval_41  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemInfoGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemInfoGet", jTcl_wtxMemInfoGet_42  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemAddToPool C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemAddToPool", jTcl_wtxMemAddToPool_43  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemAlign C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemAlign", jTcl_wtxMemAlign_44  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemAlloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemAlloc", jTcl_wtxMemAlloc_45  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemChecksum C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemChecksum", jTcl_wtxMemChecksum_46  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemFree C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemFree", jTcl_wtxMemFree_47  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemMove C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemMove", jTcl_wtxMemMove_48  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemRead C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemRead", jTcl_wtxMemRead_49  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemRealloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemRealloc", jTcl_wtxMemRealloc_50  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemSet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemSet", jTcl_wtxMemSet_51  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemScan C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemScan", jTcl_wtxMemScan_52  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxMemWrite C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.MemWrite", jTcl_wtxMemWrite_53  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxObjModuleFindName C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ObjModuleFindName", jTcl_wtxObjModuleFindName_54  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxObjModuleFindId C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ObjModuleFindId", jTcl_wtxObjModuleFindId_55  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxObjModuleInfoGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ObjModuleInfoGet", jTcl_wtxObjModuleInfoGet_56  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxObjModuleList C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ObjModuleList", jTcl_wtxObjModuleList_57  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxObjModuleLoad C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ObjModuleLoad", jTcl_wtxObjModuleLoad_58  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxObjModuleUnload C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ObjModuleUnload", jTcl_wtxObjModuleUnload_59  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxRegisterForEvent C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.RegisterForEvent", jTcl_wtxRegisterForEvent_60  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxRegsGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.RegsGet", jTcl_wtxRegsGet_61  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxRegsSet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.RegsSet", jTcl_wtxRegsSet_62  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxResultFree C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ResultFree", jTcl_wtxResultFree_63  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxServiceAdd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ServiceAdd", jTcl_wtxServiceAdd_64  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxStrToTgtAddr C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.StrToTgtAddr", jTcl_wtxStrToTgtAddr_65  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxStrToInt32 C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.StrToInt32", jTcl_wtxStrToInt32_66  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxStrToContextId C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.StrToContextId", jTcl_wtxStrToContextId_67  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxStrToContextType C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.StrToContextType", jTcl_wtxStrToContextType_68  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxStrToEventType C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.StrToEventType", jTcl_wtxStrToEventType_69  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxSymAdd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.SymAdd", jTcl_wtxSymAdd_70  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxSymFind C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.SymFind", jTcl_wtxSymFind_71  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxSymListGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.SymListGet", jTcl_wtxSymListGet_72  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxSymRemove C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.SymRemove", jTcl_wtxSymRemove_73  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxSymTblInfoGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.SymTblInfoGet", jTcl_wtxSymTblInfoGet_74  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetRtTypeGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetRtTypeGet", jTcl_wtxTargetRtTypeGet_75  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetRtVersionGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetRtVersionGet", jTcl_wtxTargetRtVersionGet_76  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetCpuTypeGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetCpuTypeGet", jTcl_wtxTargetCpuTypeGet_77  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetHasFppGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetHasFppGet", jTcl_wtxTargetHasFppGet_78  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetEndianGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetEndianGet", jTcl_wtxTargetEndianGet_79  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetBootlineGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetBootlineGet", jTcl_wtxTargetBootlineGet_80  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetBspNameGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetBspNameGet", jTcl_wtxTargetBspNameGet_81  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetReset C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetReset", jTcl_wtxTargetReset_82  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTargetAttach C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TargetAttach", jTcl_wtxTargetAttach_83  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxToolAttach C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ToolAttach", jTcl_wtxToolAttach_84  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxToolNameGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ToolNameGet", jTcl_wtxToolNameGet_85  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxToolConnected C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ToolConnected", jTcl_wtxToolConnected_86  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxToolDetach C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.ToolDetach", jTcl_wtxToolDetach_87  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTsInfoGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TsInfoGet", jTcl_wtxTsInfoGet_88  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTsKill C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TsKill", jTcl_wtxTsKill_89  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTsLock C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TsLock", jTcl_wtxTsLock_90  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTsNameGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TsNameGet", jTcl_wtxTsNameGet_91  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTsRestart C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TsRestart", jTcl_wtxTsRestart_92  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxTsUnlock C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.TsUnlock", jTcl_wtxTsUnlock_93  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxVerify C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.Verify", jTcl_wtxVerify_94  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxVioChanGet C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.VioChanGet", jTcl_wtxVioChanGet_95  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxVioChanRelease C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.VioChanRelease", jTcl_wtxVioChanRelease_96  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxVioCtl C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.VioCtl", jTcl_wtxVioCtl_97  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxVioFileList C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.VioFileList", jTcl_wtxVioFileList_98  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register wtxVioWrite C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Wtx.VioWrite", jTcl_wtxVioWrite_99  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function Wtx_Init
#ifdef __cplusplus
}
#endif

// ------------------ end cmdWtxTornado_jWrap.c ----------------------
