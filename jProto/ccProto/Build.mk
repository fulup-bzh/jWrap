#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# SubModule :   jWrap Ansi C backend
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jProto/ccProto/Build.mk,v $
#
#Modification History
#--------------------
#01b,18apr98,Fulup moved to new tree
#01a,06feb98,Fulup written
#

# Do not install in production tree
# ---------------------------------
  NOT_INSTALL=1

# Define init modules
# ------------------------
  LIB_SRCXXS = BackendCcProto.cxx
  LIB_OBJS = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS    = ${LIB_SRCXXS}

# define meta rules
# ------------------
  LIBS    :=  libBackendCcProto

# define some extra option for TK
# --------------------------------
  MK_DEFINES  =
  MK_INCLUDES =

# set proto in libCt.h if any .i changed
# ----------------------------------------
${INCDIR}/libBackendCcProto.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libBackendCcProto${LIB_SFX}: ${LIB_OBJS}
	${libRule}

