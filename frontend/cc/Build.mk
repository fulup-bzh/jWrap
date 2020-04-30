#  $Header: /Master/jWrap/frontend/cc/Build.mk,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
#
#       Copyright(c) 96-97 FRIDU a Free Software Company (Fulup Le Foll)
#
# File      :   Build.mk
# Projet    :   Fridu Realtime Booster
# Module    :   Config/Ic
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/frontend/cc/Build.mk,v $
#      State       : $State: Exp $
#
#Modification History
#--------------------
#01b,18apr98,Fulup,moved to new tree
#01a,06feb98,Fulup,written from jIc
#


# Do not install in production tree
# ---------------------------------
  NOT_INSTALL=1

# Define modules
# ------------------------
  LIB_SRCXXS  = yaccFrontendCc.cxx lexFrontendCc.cxx
  LIB_OBJS  = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS= $(LIB_SRCXXS)

# define meta rules
# ------------------
  LIBS = libFrontendCc

# define some extra option for TK
# --------------------------------
  MK_DEFINES  =
  MK_INCLUDES =


# Use Makefile rules for lex & yacc
# ----------------------------------
yaccFrontendCc.cxx:	yaccFrontendCc.y
	@echo yaccing yaccFrontendCc.y
	$(YACC) -pyycc_ yaccFrontendCc.y
	sed -e "s/y.tab.h/yaccFrontendCc.h/" -e "s/y.tab.c/yaccFrontendCc.cxx/" <y.tab.c >yaccFrontendCc.cxx
	mv y.tab.h yaccFrontendCc.h
	@rm -f y.tab.c

lexFrontendCc.cxx:	lexFrontendCc.lex
	@echo lexing lexFrontendCc.lex
	flex -Pyycc_ lexFrontendCc.lex
	sed "s/lex.yycc_.c/lexFrontendCc.cxx/" <lex.yycc_.c >lexFrontendCc.cxx
	@rm -f lex.yycc_.c

# set Parser in libCt.h if any .i changed
# ----------------------------------------
${INCDIR}/libFrontendCc.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libFrontendCc${LIB_SFX}: ${LIB_OBJS}
	${libRule}
