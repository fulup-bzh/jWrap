/* $Header: /Master/jWrap/Include/libFrontendCc.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libFrontendCc.h C++/C frontend parser
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libFrontendCc.h,v $
 *
 * Modification History
 * --------------------
 * 01b,16apr98,Fulup adapted to new tree
 * 01a,06feb98,Fulup,written
 */

#ifndef _libFrontendCc_
#define _libFrontendCc_

#include "oalWrap.h"


// Import yacc proto
IMPORT   int   yycc_parse   (void);
IMPORT   FILE* yycc_in;

#include <libFrontendCc.i>
#endif	/* libFrontendCc */


