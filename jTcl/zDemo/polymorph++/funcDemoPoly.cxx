/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * Object    :   demonstrate basic jTcl/C++ multiinheritance mecanism
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/zDemo/polymorph++/funcDemoPoly.cxx,v $
 *
 * Modification History
 * --------------------
 * 01a,28feb98,Fulup,written
 */

#include <stdio.h>
#include "funcDemoPoly.h"

void CxxObj::probe (int number) {
 fprintf (stderr, "CxxObj::probe: number=%d\n", number);   
}

void CxxObj::probe (char *chaine) {
 fprintf (stderr, "CxxObj::probe: chaine=%s\n", chaine);   
}

void CxxObj::probe (int number, char *chaine) {
 fprintf (stderr, "CxxObj::probe: number=%d, chaine=%s\n", number,chaine);   
}
