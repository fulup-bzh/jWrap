/*
 * Copyright(c) 1997-98 FRIDU a Free Software Company
 * 
 * Projet       : Jos/jWrap
 * SubModule    : Test
 * Implement    : DemoSimple
 * Object   	: Swig basic example.c adapted to jWrap
 * Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
 * 
 * Last: 
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:30 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/simple-c/funcDemoSimple.c,v $
 * 
 * Modification History
 * -------------------
 * 1.1  06may98, Fulup Written
 * 
 */

// exclude standard include from path
#ifndef JWRAP_JTCL
# include <easyc.h>
# include <time.h>
# include <string.h>
# ifdef FRIDU
#   include <libDemoSimple.i>
# endif
#endif

EXPORT double MyDouble = 3.0;
EXPORT int    MyInt    = 9;
EXPORT long   MyLong   = 3;
EXPORT char   *MyString= "Hello World";
 

PUBLIC int fact(int n) {
  if (n <= 1) return 1;
  else return n*fact(n-1);
}

PUBLIC int mod(int n, int m) {
  return (n % m);
}

PUBLIC char *get_time() {
    long            ltime;
    time(&ltime);
    // don't forget to return a valid malloced string
    return strdup (ctime(&ltime));
}
