/*
 * Copyright(c) 1997-98 FRIDU a Free Software Company
 * 
 * Projet       : Jos/jWrap
 * SubModule    : Test/jWrap
 * Implement    : DemoStruct
 * Object   	: Demonstrate Complex Structure handling
 * Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
 * 
 * Last: 
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:30 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/structure-c/funcDemoStruct.c,v $
 * 
 * Modification History
 * -------------------
 * 1.1  06may98, Fulup Written
 * 
 */

/** -----------------------------------------------------------------
 ** Place here after any wrapping you want to be included in Wrap
 ** interface but not in C code
 ** -----------------------------------------------------------------*/

#ifndef JWRAP_JTCL
#  include <easyc.h>
#  include <stdio.h>
#  include <tcl.h>
#  ifdef _WINDOWS_
#  include <memory.h>
#  endif
#  ifdef FRIDU
#    include <libDemoStruct.i>
#  endif

#else
  FILE * fopen  (char* name, char*opt);
  int    fclose (FILE*);
#endif

void *memcpy(void *dest, const void *src, size_t n);

// map a type on a new type
typedef unsigned long UINT32;

#define VA   2
#define TOTO 4
#define TATA 5
#define SNOOPY "snoopy"
#define TITI   "titi"


/** -----------------------------------------------------------------
 ** WPR_ID hold stdin/out vio redictio and tool to target ID
 ** is a super set of wtx id 
 ** -----------------------------------------------------------------*/

// Extract from Wandel IRPS bug
// ----------------------------
typedef unsigned short int16u;
typedef unsigned char  int8u;
typedef unsigned char  boolean;

typedef enum  {
   USER_SPECIFIC     = 0X08,
   RESERVE_1         = 0X09,
   SPECIAL_SADR      = 0X0A,
   RESERVE_2         = 0X0B,
   UNKNOWN_SADR_TYPE = 0XFF
} t_sadr_type;       

typedef struct str_sadr {
   t_sadr_type  type;
   char *digits;
} t_sadr;

typedef struct str_CC_S_BIND_REQ 
{
  int16u    app_q_id;	
  int8u	    ref;			
  int8u	    ctx_max;	
  int8u	    con_type;	
  int8u	    mode;
  int8u	    *user_to_user;
  boolean   data_service;
} CC_S_BIND_REQ;



// ------ First Fridu structure test --------------           
enum choix {A,B,C,D};

typedef struct wprId {		/*  Structure du tableau des commandes */
  /** target Internet name Mandatory */
  char           *targetName;
  /** tool name facultavice */
  char           *toolName;

  struct {
   int A;
   int B;
   int C; 
  } within;
  
  enum choix option;

  union {
   int    A[2];
   short  B[4];
   char   C[8];
   double D;
  } jointure;
   
  /** vio Target device name computed on target */
  UINT32          vIoNum;
  FILE *          fichier;
  UINT32          array [10];
} WPR_ID;

/** -------------------------------------------------------
 ** try to build a linked list, check WARNING in Tcl example
 ** -------------------------------------------------------*/
typedef struct linkedList {
  /** They is no limittation on application field */ 
   char   *name;
   int    ind;
   /** this as to be a TCL unknow type in order TCL not
    trying to handle it with garbade collection, replacing
    in this example void* with "struct linkedList" will 
    make this example fail when run in interractiv mode */
   void   *next;
} LINKED_LST;

// Keep track of list start
static LINKED_LST *listHead = NULL;

/**-------------------------------------------------------
 ** Print input structure and make a copy of input in a
 ** Result area, this last operation is mandatory because
 ** All Tcl Struct are freed with Tcl gargage collector
 **-------------------------------------------------------*/
PUBLIC WPR_ID * testIt (WPR_ID *wprId) {
 WPR_ID *result;

char line [255];

  if (wprId == NULL) {
     fprintf (stderr," WPR_ID *wprId == NULL\n");
     return NULL;
  }

  // try to read first line from file
  if (wprId->fichier != NULL) {
    fgets (line,sizeof (line),wprId->fichier);
  }

  fprintf (stderr,"testIt WPR_ID*wprId %p dump within C\n", (void*) wprId);
  fprintf (stderr,"--------------------------------------------------\n");
  fprintf (stderr,"toolName      = %s [%p]\n", wprId->toolName , (void*)wprId->toolName);
  fprintf (stderr,"targetName    = %s [%p]\n", wprId->targetName,(void*)wprId->targetName);
  fprintf (stderr,"within.A      = %d\n", wprId->within.A);
  fprintf (stderr,"within.B      = %d\n", wprId->within.B);
  fprintf (stderr,"within.C      = %d\n", wprId->within.C);
  fprintf (stderr,"jointure.A[0] = %d\n", wprId->jointure.A[0]);
  fprintf (stderr,"jointure.A[1] = %d\n", wprId->jointure.A[1]);
  fprintf (stderr,"jointure.C[0] = %c\n", wprId->jointure.C[0]);
  fprintf (stderr,"jointure.C[1] = %c\n", wprId->jointure.C[1]);
  fprintf (stderr,"jointure.C[2] = %c\n", wprId->jointure.C[2]);
  fprintf (stderr,"jointure.C[3] = %c\n", wprId->jointure.C[3]);
  fprintf (stderr,"jointure.D    = %f\n", wprId->jointure.D);
  fprintf (stderr,"vIoNum        = %ld\n",wprId->vIoNum);
  if (wprId->fichier != NULL) {
     fprintf (stderr,line);
  }

  result = (WPR_ID*)Tcl_Alloc (sizeof (WPR_ID));
  memcpy (result, wprId, sizeof (WPR_ID));

  fprintf (stderr,"returned wprId %p dump within C\n", (void*) result);
  fprintf (stderr,"\n--------------------------------------------------\n");
  
  return result;
}

/**-----------------------------------------------
 ** Dump all linked list
 **-----------------------------------------------*/
PUBLIC void testLst (void) {
 LINKED_LST *current;

  fprintf (stderr,"\nDump Linked List from C\n");
  fprintf (stderr,"--------------------------------------------------\n");

  if (listHead == NULL) {
    fprintf (stderr,"Linked List is empty\n");
  }

  for (current=listHead; current != NULL; current=(LINKED_LST*)current->next) {
    fprintf (stderr, "ind=%d name=%s\n",current->ind, current->name); 
    if ((LINKED_LST*)current->next == listHead) {
     fprintf (stderr, "list loop detected\n");
     break;
    }
  }
  fprintf (stderr,"--------------------------------------------------\n");
  
}
