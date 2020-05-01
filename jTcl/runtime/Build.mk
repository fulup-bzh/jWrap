#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# SubModule :   jTcl runtime
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/runtime/Build.mk,v $
#
#Modification History
#--------------------
#01b,21feb98,Fulup adapted to new tree
#01a,06feb98,Fulup written
##

# Define init modules
# ------------------------
  WRAPPERS = cmdRuntimeJwrap_jWrap.c
  SOURCES  = typeRuntimeJwrap.c miscRuntimeJwrap.c \
             varRuntimeJwrap.c \
             cookieRuntimeJwrap.c enumRuntimeJwrap.c \
	     stringRuntimeJwrap.c interpRuntimeJwrap.c
  LIB_SRCS = $(SOURCES) $(WRAPPERS)
  LIB_OBJS = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS     = ${LIB_SRCS}

# define meta rules
# ------------------
  LIBS   :=  libRuntimeJwrap
  JDOC   :=  libRuntimeJwrap
  SHARED :=  libRuntimeJwrap

ifeq (${ARCH_OS_NAME},WinDos)
  override SHLIBS := $(TCL_LIB) $(SHLIBS)
endif

# define some extra option for TK
# --------------------------------
  MK_DEFINES  =
  MK_INCLUDES =

# rule for jWrap generation from .c
# ---------------------------------
cmdRuntimeJwrap_jWrap.c: cmdRuntimeJwrap.c
	${jWrapRule}

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libRuntimeJwrap.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# Produce doc with javadoc for this lib
# -------------------------------------
${JDOCDIR}/libRuntimeJwrap.html: ${SOURCES}
	${jDocRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libRuntimeJwrap${LIB_SFX}: ${LIB_OBJS}
	${libRule}
