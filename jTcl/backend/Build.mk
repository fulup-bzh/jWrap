#  $Header: /Master/jWrap/jTcl/backend/Build.mk,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
#
#       Copyright(c) 96-97 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   Rubicon
# SubModule :   wrap
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/backend/Build.mk,v $
#      State       : $State: Exp $
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
  LIB_SRCXXS = typeBackendCc2jTcl.cxx    enumBackendCc2jTcl.cxx    \
               functionBackendCc2jTcl.cxx miscBackendCc2jTcl.cxx \
               programBackendCc2jTcl.cxx  classBackendCc2jTcl.cxx  \
               varBackendCc2jTcl.cxx
  LIB_OBJS = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS    = ${LIB_SRCXXS}

# define meta rules
# ------------------
  LIBS    :=  libBackendCc2jTcl

# define some extra option for TK
# --------------------------------
  MK_DEFINES  =
  MK_INCLUDES =

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libBackendCc2jTcl.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libBackendCc2jTcl${LIB_SFX}: ${LIB_OBJS}
	${libRule}

