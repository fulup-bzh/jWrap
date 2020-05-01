/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * Projet    :   Jos/jWrap
 * Module    :   Test/jWrap
 * Interface :   DemoOverload
 * Object    :   Demonstrate how overloading a C++ function from jTcl
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/overload++/funcDemoOverload.h,v $
 *
 * Modification History
 * --------------------
 * 01a,28feb98,Fulup,written
 */

// exclude standard C++ include from wrapping
#ifndef JWRAP_JTCL
# include <math.h>
# include <stdio.h>
# include <easyc.h>

# include <libRuntimeJwrap.h>
# include <libDemoOverload.i>
#endif

IMPORT char* Overload_help;

/*********************************************************************
 ** Define a small Hexa/base10 mecanism in it seld it as not interest
 ** but it show how the exception routine can be overloaded
 *********************************************************************/
class CxxConvert  {
 public:
   static  int      iscxx;
   CxxConvert* handle(void);
   virtual void signal (char* message);

   char* int2hexa (int   number);
   int   hexa2int (char* chaine);
   virtual ~CxxConvert (void);
}; // end CxxTranslate

