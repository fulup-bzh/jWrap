/* $Header: /Master/jWrap/Include/libFrontendTcl.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libFrontendTcl.h jTcl frontend parser
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libFrontendTcl.h,v $
 *
 * Modification History
 * --------------------
 * 01b,1_apr98,Fulup moved to new tree
 * 01a,06feb98,Fulup,written
 */

#ifndef _libFrontendTcl_
#define _libFrontendTcl_

#include <easyc.h>
#include <stdio.h>

#include "oalWrap.h"


IMPORT   int   yytcl_parse   (void);
IMPORT   FILE* yytcl_in;


#include <libFrontendTcl.i>
#endif	/* libFrontendTcl */


