/*
 * Copyright(c) 1997-98 FRIDU a Free Software Company
 *
 * Projet       : Jos/jWrap
 * SubModule    : Test/jWrap
 * Implement    : DemoMikhail
 * Object   	: A very simple starting example from Mikhail Teterin
 * Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 *
 * Last:
 *  Author      : $Author: Fulup $ Date        :
 *  Date        : $Date: 1999/03/11 12:49:29 $
 *  Revision    : $Revision: 1.3.0.1 $
 *  Source      : $Source: /Master/jWrap/jTcl/zDemo/Mikhail++/funcDemoMikhail.h,v $
 *
 * Modification History
 * -------------------
 * 1.1 06may98, Fulup Written from Mikhail Teterin questions
 *
 */

// dont include unix include in jWrap parsing
#ifndef JWRAP_JTCL
#  include <stdio.h>
#  include <libRuntimeJwrap.h>
#  include <libDemoMikhail.i>
#endif

class one {
   int one_int;

   // all publics will be accessible from jTcl
   public:

   // signal is jTcl handling error
   virtual void signal (char* message);

   // your effective constructor
   one(int value);

   // your effective constructor
   one(int v1, double v2);

   // prodive an optional destructor
   ~one ();
};

