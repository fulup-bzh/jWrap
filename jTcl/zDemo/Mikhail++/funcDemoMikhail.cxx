/*
 * Copyright(c) 1997-98 FRIDU a Free Software Company
 *
 * Projet       : Jos/jWrap
 * SubModule    : Test/jWrap
 * Implement    : DemoMikhail
 * Object   	: A very simple starting example from "Mikhail Teterin"
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 *
 * Last:
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:29 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/Mikhail++/funcDemoMikhail.cxx,v $
 *
 * Modification History
 * -------------------
 * 1.1 06may98, Fulup Written from Mikhail Teterin questions
 *
 */

#include "funcDemoMikhail.h"

// signal method is call by jTcl each time there is problem
void one::signal (char *message) {
           printf ("one:signal message=%s\n", message);
}

// your public effective constructor
one::one (int value) {
           printf ("  one::one int:Value=%d\n", value);
           one_int = value;
}
one::one (int v1, double v2) {
           printf ("  one::one int:V1=%d double:v2=%f\n", v1,v2);
}

// Destructor is not mandatory is present jTcl will call it
one::~one () {
           printf ("\n  one::~one application destructor called\n\n");
}
