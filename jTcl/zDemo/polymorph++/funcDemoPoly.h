/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * Projet    :   Jos/jTcl
 * SubModule :   Test/jWrap
 * Interface :   DemoPoly
 * Object    :   demonstrate basic jTcl/C++ multi-inheritance mecanism
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/polymorph++/funcDemoPoly.h,v $
 *
 * Modification History
 * --------------------
 * 01a,28feb98,Fulup,written
 */


// exclude standard C++ include from wrapping
#ifndef JWRAP_JTCL
#  include <libRuntimeJwrap.h>
#  include <libDemoPoly.i>
#endif

/*********************************************************************
 ** This class is a base boject for multi inheritage demo
 *********************************************************************/
class CxxObj  {
 public: 
  // define a method for checking C++ handle validity
  void probe (int     number) ;
  void probe (char*   chaine) ;
  void probe (int number, char*   chaine) ;
}; // end CxxObj

