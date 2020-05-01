/* --------------------------------------------------------------------------------
 * Copyright(c) 1997-98 FRIDU a Free Software Company
 *
 * Object   	: interface prototype for VxWorks/Tornado basic demo
 * Projet       : Jos/jWrap
 * SubModule    : Test/tornado
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 *
 * Last:
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:31 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/tornado/zDemo/msg/cmdDemoMsg.h,v $
 *
 * Modification History
 * -------------------
 * 1.1  2jun98, Fulup Writen
 * --------------------------------------------------------------------- */

/* =====================================================================
 * Interface    : DemoMsg
 * Help         : Tornado/VxWorks Message Queue demo
 * =====================================================================*/

/** -----------------------------------------------------------------------
 *  interface to VxWorks message queue library
 *
 *  following prototype definition is mainlelly an extract from VxWorks includes
 *  file. Theorically we could wrap all VxWorks proto file directelly from
 *  WindRiver include files. Nevertheless the result would be so big that
 *  it would probabelly be impossible to handle it
 * ------------------------------------------------------------------------*/

// Map sysboot line public string (Not implement in current version)
IMPORT char* sysBootLine;

// Map VxWorks message queue ID to a jWrap Cookie
typedef void *MSG_Q_ID;
typedef void *PART_ID;

// define some default (only in order testing define facility)
#define MSG_DEFAULT_LENGHT 2
#define forever -1


typedef union type32 {
 int  intValue;
  // char *string;
 void *pointer;
} TYPE32;

// try some complex structure
typedef struct MsgLists {
   int  A[4];
   char *name;
   void *next;
  union BB {
    short shortValue [2];
    void  *buffer;
  } jointure;
} MSG_lists;

// define target char in order beeing able to send string on target
typedef char target_char;

// Change MSG option to an enumeration for simplifying script
typedef enum MsgOptions {
  MSG_Q_FIFO     = 0,
  MSG_Q_PRIORITY = 1
} MSG_options;

typedef enum MsgPriorities {

  MSG_PRI_NORMAL = 0,
  MSG_PRI_URGENT = 1
} MSG_priorities;

typedef enum MsgStatus {
  MSG_STS_OK     =  0,
  MSG_STS_ERROR  = -1,

  MSG_STS_UNKNOW = -2
} MSG_status;


/* Declare all prototype we want to be interfaced
 * note malloc/free are declared for jWrap but not included
 * in C for not interering with host stdlib.h proto
 */
#ifdef JWRAP_JTCL
  void*       malloc      (int size);
  void        free        (void*);
#endif

// Message queue mapping
MSG_Q_ID    msgQCreate  (int maxMsg, int maxMsgLenght, MSG_options option);
MSG_status  msgQDelete  (MSG_Q_ID msgQId);
int         msgQNumMsgs (MSG_Q_ID msgId);
int         msgQReceive (MSG_Q_ID msgId, void *buffer, int maxNBytes
            , int timeout);
MSG_status  msgQSend    (MSG_Q_ID msgId, char *buffer, int maxNBytes
            , int timeout, MSG_priorities priority);

// Memory partition mapping
PART_ID memPartCreate (void* poolBlock, int poolSize);
void   *memPartAlloc  (PART_ID partId,  int size);
void    memPartFree   (PART_ID partId,  void* pBlock);

// in Fridu environment we include ansi proto and lib timestamp
#ifdef FRIDU
#include <libDemoMsg.i>
#endif
