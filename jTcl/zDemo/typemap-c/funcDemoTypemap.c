/*
 *  Copyright(c) 1997-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * Projet    :   jWrap
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/typemap-c/funcDemoTypemap.c,v $
 *
 * Modification History
 * --------------------
 * 01b,06mar99,Fulup,added varg example
 * 01a,06feb98,Fulup,written
 */

/* Simple example from SWIG documentation */
/* File : example.c adapted to jWrap      */

#include <easyc.h>
#include <tcl.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "libRuntimeJwrap.h"
#include "funcDemoTypemap.h"


EXPORT char        *TypeMap_help = "Demonstrate how convert basic C type to Tcl";
EXPORT typeMapAdrs *lastAdr = NULL;

// This routine demonstrate how translate a string token to an int
PUBLIC int checkOpt (SomeOptions option) {

  switch ((int) option) {
  case OPT_1:
  case OPT_2:
  case OPT_3:
   fprintf (stderr,"Option:%d valid\n", (int) option);
   break;
   
  default: fprintf (stderr, "Imposible opt=%d\n", option);
  }

  return (int) option;
}


// return input parameter + one
PUBLIC int addOneToInt (int number) {
 
  return (number+1);
} 


// return upperstring to Tcl
PUBLIC char* stringToUpper (char* chaine) {
 static char result [255];
 int ind;
 
 for (ind=0; chaine [ind] != '\0'; ind ++) {
   result [ind] = toupper (chaine [ind]);
 }
 result [ind] = '\0';

 return result; // WARNING: Tcl will do a private copy at first puts only

toBig:
 return "Input string ig bigger than 255 character";
}

// translate a list to uppercase
PUBLIC char** listToUpper (char ** list) {
 int  ind;
 int status;
 char **res;

 // count list length in order returning it
 for (ind=0; list[ind] != NULL; ind++);
 res = (char**) Tcl_Alloc (sizeof(char**) * (ind+1));
 
 for (ind=0; list[ind] != NULL; ind++) {
   if (ind > 9) goto tooBig;
   res [ind] = strdup (stringToUpper (list [ind]));
 }
 res [ind] = NULL; // close the list

 return res;

tooBig:
 jWrapPanic (NULL,"listToUpper list as %s...%s more than 10 elements",list[0], list[ind]);
 return NULL; // for gcc warning
}

// eval a Tcl expression with given interp
PUBLIC int evalTclInC (Tcl_Interp *interp, Tcl_Obj *objPtr) {
 int     status;
 Tcl_Obj result;

 status = Tcl_GlobalEvalObj (interp, objPtr);
 
 return status;    
}

// retreive a custom C structure
PUBLIC void printAdr (typeMapAdrs *adr) {
  lastAdr = adr;  // save adress in a static

 fprintf (stderr,"--------- Printed from C  -----------------\n");
 fprintf (stderr,"Last  name=%s\n", adr->lastName);
 fprintf (stderr,"First name=%s\n", adr->firstName);
 fprintf (stderr,"Street    =%s\n", adr->adress);
 fprintf (stderr,"Zip       =%d\n", adr->zip);
 fprintf (stderr,"Town      =%s\n", adr->town);
 fprintf (stderr,"---------------  OK  -----------------------\n");
}

// check we get a full cmd type
PUBLIC void checkVarg (JWRAP_varg *varg) {
 int  ind;
 char *typeName;

  printf ("argc = %d\n", varg->argc);
  

  for (ind =0 ; ind <varg->argc; ind++) {
    if (varg->argv[ind]->typePtr != NULL) {
        typeName= varg->argv[ind]->typePtr->name;
    } else {
        typeName="String";
    }
    printf ("argv[%d] byte=%s internal=%p type=%s\n"
      , ind, varg->argv[ind]->bytes, varg->argv[ind]->internalRep.twoPtrValue.ptr1
      , typeName);
  }

} 


