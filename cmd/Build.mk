#  $Header: /Master/jWrap/cmd/Build.mk,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
#
#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   Parser main binary
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/cmd/Build.mk,v $
#      State       : $State: Exp $
#
#Modification History
#--------------------
#011,06feb98,Fulup written from jIc
#

# Define modules
# ------------------------
  GET_SRCXX  =  mainWrap.cc oalWrap.cc
  GET_OBJS  = $(GET_SRCXX:%.cc=${OBJDIR}/%${OBJ_SFX})

  SRCXX= $(GET_SRCXX)

# define meta rules
# ------------------
  EXE    :=  jWrap

# define some extra option for TK
# --------------------------------
ifdef TORNADO_BASE
  MK_DEFINES  = -DTORNADO_BASE=$(TORNADO_BASE)
  BACKEND_TORNADO=$(LIBDIR)/libBackendCc2Tornado$(LIB_SFX)
endif
  MK_INCLUDES =

# oalWrap.cxx refuse to compile with -O2 option !!!
  override DEBUGCCFLAGS=

# We need oalWrap.i for frontend and backend lib
# ----------------------------------------------
proto::    ${DEPDIR}/oalWrap.i

# Effectively Build exe files
# ---------------------------
${BINDIR}/jWrap${EXE_SFX}: $(GET_OBJS) \
			   $(LIBDIR)/libFrontendCc$(LIB_SFX) \
			   $(LIBDIR)/libFrontendTcl$(LIB_SFX) \
			   $(LIBDIR)/libBackendJavadoc$(LIB_SFX) \
			   $(LIBDIR)/libBackendCcHat$(LIB_SFX) \
			   $(BACKEND_TORNADO) \
			   $(LIBDIR)/libBackendCc2jTcl$(LIB_SFX) \
			   $(LIBDIR)/libBackendCcProto$(LIB_SFX) \

	${binPlusRule} ${LIBPOSIX} ${LDLIBS}

