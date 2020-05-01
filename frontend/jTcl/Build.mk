#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   jTcl frontend
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/frontend/jTcl/Build.mk,v $
#      State       : $State: Exp $
#
#Modification History
#--------------------
#01b,16apr98,Fulup moved to new name
#01a,06feb98,Fulup written from jIc
#

# Do not install in production tree
# ---------------------------------
  NOT_INSTALL=1

# Define modules
# ------------------------
  LIB_SRCXXS = yaccFrontendTcl.cxx lexFrontendTcl.cxx
  LIB_OBJS  = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS= $(LIB_SRCXXS)

# define meta rules
# ------------------
  LIBS :=  libFrontendTcl

# define some extra option for TK
# --------------------------------
  MK_DEFINES  =
  MK_INCLUDES =

# Use Makefile rules for lex & yacc
# ----------------------------------
yaccFrontendTcl.cxx:	yaccFrontendTcl.y
	@echo yaccing yaccFrontendTcl.y
	$(YACC) -pyytcl_ yaccFrontendTcl.y
	sed -e "s/y.tab.h/yaccFrontendTcl.h/" -e "s/y.tab.c/yaccFrontendTcl.cxx/" <y.tab.c >yaccFrontendTcl.cxx
	mv y.tab.h yaccFrontendTcl.h
	@rm -f y.tab.c

lexFrontendTcl.cxx:	lexFrontendTcl.lex
	@echo lexing lexFrontendTcl.lex
	flex -Pyytcl_ lexFrontendTcl.lex
	sed "s/lex.yytcl_.c/lexFrontendTcl.cxx/" <lex.yytcl_.c >lexFrontendTcl.cxx
	@rm -f lex.yytcl_.c

# set Parser in libCt.h if any .i changed
# ----------------------------------------
${INCDIR}/libFrontendTcl.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libFrontendTcl${LIB_SFX}: ${LIB_OBJS}
	${libRule}
