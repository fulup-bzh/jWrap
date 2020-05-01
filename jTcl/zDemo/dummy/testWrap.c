/*
 * Copyright(c) 1997-98 FRIDU a Free Software Company
 *
 * Projet       : Jos/jWrap
 * SubModule    : Test
 * Implement    : DemoSimple
 * Object   	: Swig basic example.c adapted to jWrap
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
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

// Test
// tclsh
//  load /home/fulup/Workspace/Fridu/Exe/linux86/lib/libDemoSimple.so
//  DemoSimple.get_time

// exclude standard include from path
#ifndef JWRAP_JTCL
# include <easyc.h>
# include <time.h>
# include <string.h>
#endif



PUBLIC const char *get_time() {
    long            ltime;
    time(&ltime);
    // don't forget to return a valid malloced string
    const char*now = ctime(&ltime);
    char *dup= strdup(now);
    return dup;
}
