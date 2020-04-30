/*
 *      Copyright(c) 1999 FRIDU a Free Software Company Philipppe Le Foll
 *
 * Projet       : jWrap
 * SubModule    : Readline
 * Oject        : Interface with GNU readline
 * Auteur       : Johannes Zellner & Fulup Le Foll
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/19 17:57:10 $
 *      Revision    : $Revision: 1.4 $
 *      Source      : $Source: /Master/jWrap/readline/src/tclReadline.c,v $
 *
 * Modificatin History
 * -------------------
 * 01d,19mar99,Fulup, added history command and ! history search
 * 01c,10mar99,Fulup, added common prefix completion
 * 01b,03mar99,Fulup, used same event mechanism as Johannes Zellner tclreadline
 * 01a,14mar96,Fulup, writen from realine example
 */

#ifndef SOLARIS
# define __FUNCTION_DEF
#endif

#include <tcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

#include "libRuntimeReadline.h"

typedef enum {
  LINE_COMPLETED,
  LINE_EOF,
  LINE_EMPTY,
  LINE_UNKNOW
} LineStatus;

EXPORT char *ReadlinePrompt1 = "--> ";
EXPORT char *ReadlinePrompt2 = "--? ";
EXPORT char *ReadlineName    = "TclSh ";


LOCAL Tcl_DString lineString;
LOCAL LineStatus lineStatus;
LOCAL Tcl_Interp *staticInterp;

/** --------------------------------------------------------------------
 * Attempt to complete on the contents of TEXT.  START and END show the
 * region of TEXT that contains the word to complete.  We can use the
 * entire line in case we want to do some simple parsing.  Return the
 * array of matches, or NULL if there aren't any.
 * --------------------------------------------------------------------*/
LOCAL char **
ReadlineCompletion (char *text, int start, int end)
{
  const char **matches;
  char **mlist;
  char **oneCmdMatches;
  char *name;
  char textStar[128];
  int  status;
  int  ind,jnd;
  int  nbCmd = 0;
  char *result;

  sprintf (textStar, "%s*", text);

  /*
   * ask TCL to return Var or List Variable 
   */
  Tcl_ResetResult (staticInterp);
  Tcl_AppendElement (staticInterp, text);
  status = Tcl_VarEval (staticInterp, "info ", "command ", textStar,NULL);

  if (status == TCL_OK)
    if (Tcl_GetStringResult(staticInterp)[0] != '\0') {
      /*
       * add a dummy trailing element for 0x0000 termination 
       */
      result = strdup (Tcl_GetStringResult(staticInterp));
      Tcl_ResetResult (staticInterp);
      Tcl_SplitList (staticInterp, result, &nbCmd, &matches);
      free (result);
    }

  /*
   * if no proc founded search for a variable 
   */
  if (nbCmd == 0) {

    Tcl_ResetResult (staticInterp);
    Tcl_AppendElement (staticInterp, text);
    status = Tcl_VarEval (staticInterp, "info ", "vars ", textStar,NULL);

    if (status == TCL_OK)
      if (Tcl_GetStringResult(staticInterp)[0] != '\0') {
	/*
	 * add a dummy trailing element for 0x0000 termination 
	 */
	result = strdup (Tcl_GetStringResult(staticInterp));
	Tcl_ResetResult (staticInterp);
	Tcl_SplitList (staticInterp, result, &nbCmd, &matches);
	free (result);
      }
  }
  /*
   * if no command or var founded leave readline search for a file 
   */
  if (nbCmd == 0) {
    return ((char **) NULL);
  }
  /*
   * if we only have one command maches array has a different shape 
   */
  if (nbCmd == 1) {
    oneCmdMatches = (char **) malloc (2 * (sizeof (char *)));

    oneCmdMatches[0] = strdup (matches[0]);
    oneCmdMatches[1] = NULL;

    /*
     * free previous maches array 
     */
    free (matches);
    return (oneCmdMatches);
  }
  /*
   * Readline impose to give matching list prefixed by original patern
   * we reallocate a bigger matching list to add patern
   */
  mlist = (char**) malloc ((nbCmd+2) * (sizeof (char*)));

  // take first element as common prefix and reduce it depending on others value
  mlist [0] = strdup (matches[0]);

  // loop on all avaliable commands
  for (ind = 0; matches[ind] != NULL; ind++) {

    // check partial completion
    for (jnd=0; mlist [0] [jnd] != '\0'; jnd++) {
      // if new element is smaller or differ with common prefix cut prefix
      if ((matches[ind] [jnd] == '\0') || (matches[ind] [jnd] !=  mlist[0] [jnd])) {
         mlist [0] [jnd] = '\0';
         break;
      }
    }

    // add slot in possible values
    mlist[ind+1] = strdup (matches[ind]);
  }
  // free original match and close mlist
  free (matches);
  mlist [ind+1] = NULL;
  return (mlist);
}


/** --------------------------------------------------------
 *  Call by TCL each time a new char if avaliable on stdin
 * ---------------------------------------------------------*/
LOCAL void 
ReadlineDataAvailableHandler (ClientData clientData, int mask) {

  // If a character is readable read it now inside readline buffer 
  if (mask & TCL_READABLE)
    rl_callback_read_char ();
}

/** ---------------------------------------------------
 *  Call by readline each time a line if completed
 * ----------------------------------------------------*/
LOCAL void 
ReadlineLineCompleteHandler (char *line) {
  int  status;
  int  offset;
  HIST_ENTRY *entry;
  char *result;

  // don't loop implicitely in readline EOL callback
  Tcl_DeleteFileHandler (0);
  rl_callback_handler_remove ();

  // If line is complete try to process it thru TCL 
  if (line && *line) {

    // check if we are facing an history command
    if (line [0]  != '!') {
      // add readed char to command line
      (void) Tcl_DStringAppend (&lineString, line, -1);
      (void) Tcl_DStringAppend (&lineString, "\n", -1);

      // change EOF line status to unlock ReadlineStart proc
      lineStatus = LINE_COMPLETED;

      // add line in readline history
      add_history (line);
    } else {
      // default if no history founded
      using_history ();
      result = get_history_event (line, &status, 0) ;
      if (result != NULL) {
          lineStatus = LINE_COMPLETED; 
          printf ("%s\n", result);
          (void) Tcl_DStringAppend (&lineString, result, -1);
          (void) Tcl_DStringAppend (&lineString, "\n", -1);
      } else {
         lineStatus = LINE_EMPTY;
         fprintf (stderr,"History failed to complete [%s]\n", line);
      }
    } // end if history
  } else if (line == NULL) {
    lineStatus = LINE_EOF;
  } else {
    lineStatus = LINE_EMPTY;
  }
}

/** ------------------------------------------------------
 *   History command
 * -------------------------------------------------------*/
PUBLIC void ReadlineHistory (void) {
  HIST_ENTRY **list;
  int        ind;

  list = history_list ();
  if (list)  {
    for (ind = 0; list[ind]; ind++) {
         printf ("%d: %s\r\n", ind+1, list[ind]->line);
    }
  }  
}

/** ------------------------------------------------------
 *   Effectivelly read keyboard in readline mode
 * -------------------------------------------------------*/
PUBLIC void  ReadlineStart (void)
{
  char *cmd=NULL; // gcc warning
  int status;

  // Allow conditiannal parsing of readline
  rl_readline_name = ReadlineName; 

  /*
   * Tell the completer that we want a crack first. 
   */
  rl_attempted_completion_function = (CPPFunction *) ReadlineCompletion;


  /*
   * Loop reading and executing lines until the user quits. 
   */

  for (;;)			// Loop forever on reading lines until EOF
   {
    // reset command line 
    Tcl_DStringInit (&lineString);

    // when starting line is uncompleted
    lineStatus = LINE_UNKNOW;

    // readline line handler is called when line is full 
    rl_callback_handler_install (ReadlinePrompt1, ReadlineLineCompleteHandler);


    for (;;) {

      // validate a TCL file handler on stdin 
      Tcl_CreateFileHandler (0, TCL_READABLE, ReadlineDataAvailableHandler, (ClientData) NULL);

      // wait for line to be completed before processing it           
      while (lineStatus == LINE_UNKNOW) Tcl_DoOneEvent (TCL_FILE_EVENTS);

 
      // check user did not EOF
      if ((lineStatus == LINE_EOF) || (lineStatus == LINE_EMPTY)) {
        printf ("\n");
	break;
      }

      // test command completion
      cmd = Tcl_DStringValue (&lineString);
      if (Tcl_CommandComplete (cmd)) break;

      // readline line handler is called when line is full 
      rl_callback_handler_install (ReadlinePrompt2, ReadlineLineCompleteHandler);
      lineStatus = LINE_UNKNOW;
    }

    // when user EOF leave readline 
    if (lineStatus == LINE_EOF) break;

    // if line is empty ignore
    if (lineStatus == LINE_EMPTY) continue;
  
    // excecute command
    status = Tcl_Eval (staticInterp, cmd);
    Tcl_DStringFree (&lineString);

    // display command line excecution result
    if (status != TCL_OK)
      fprintf (stderr, "%s\n", Tcl_GetStringResult(staticInterp));
    else
      printf ("%s\n", Tcl_GetStringResult(staticInterp));
  }

}


/** ------------------------------------------------------
 *   Only init readline when running in a full tty mode
 * -------------------------------------------------------*/
RESTRICTED int  ReadlineLibInit (Tcl_Interp * interp)
{
  char *line,
   *s;
  char *param[2];
  int status;
  int done = 0;
  int gotPartial = 0;
  Tcl_DString command;

  if (isatty (0) == 0) {
    Tcl_SetResult(interp, "WARNING: rlStart ignored [not a tty]\n",TCL_VOLATILE) ;
    return (TCL_OK);
  }
  /*
   * current version is mono interpreter 
   */
  staticInterp = interp;

  return TCL_OK;
}





