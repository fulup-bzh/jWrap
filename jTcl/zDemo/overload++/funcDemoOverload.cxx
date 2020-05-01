/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * Projet    :   Jos/jWrap
 * Module    :   Test/jWrap
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/overload++/funcDemoOverload.cxx,v $
 *
 * Modification History
 * --------------------
 * 01a,28feb98,Fulup,written
 */


#include <math.h>
#include <stdio.h>
#include <easyc.h>

#include "funcDemoOverload.h"

EXPORT char *Overload_help="Example on how jTcl can overload a C++ method";

// define a sttaic boolean for all c++ object
int CxxConvert::iscxx = TRUE;

// signal routine is a bas clone of jTcl signal method
void CxxConvert::signal (char* message) {
  fprintf (stderr, "ERROR: C++ signal ->%s<-\n\n", message);
} // end signal

// return current c++ object adresse as a cookie to jTcl
CxxConvert* CxxConvert::handle (void) {
  return this;
} // end handle

// translate an in to equivalent hexa reprenatation fail if int cannot fit in a short
char *CxxConvert::int2hexa (int number) {
  char *hexa =Tcl_Alloc (5);
  int status;

  // if int < 0 we refuse to convert it (stupid but simple to test)
  status = sprintf (hexa,"0x%x",number);
  if (number BAND 0xFFFF0000) goto invalidInteger;


  return hexa;

invalidInteger:
  char msg [255];
  sprintf (msg,"[too big]\ncan't translate number %d to short int hexa", number);
  signal   (msg);
  return NULL;
} // end int2hexa

// translate a string to int equilalent fail if string is invalid
int CxxConvert::hexa2int (char* chaine) {
  int status;
  int number;

  status = sscanf (chaine,"0x%x",&number);
  if (status == 0) goto invalidHexaString;

  return number;

invalidHexaString:
  char msg [255];
  sprintf (msg,"[invalid string]\n|%s| is not a valid hexa 0x... string", chaine);
  signal   (msg);
  return   -1;
} // end hexa2int

// Destructor
CxxConvert::~CxxConvert () {
 fprintf (stderr, "CxxConvert::~CxxConvert destructor called\n");
}


