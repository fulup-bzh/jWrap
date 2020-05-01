#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   Wtx VxWorks Tornado interface
# Auteur    :   Fulup Ar Foll (Fulup@fridu.bzh)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/vxWorks/Build.mk,v $
#
#Modification History
#--------------------
#01a,15feb99,Fulup written
#

# Only compile this directory if tornado is defined
# -------------------------------------------------
ifdef TORNADO_BASE

# Define modules
# --------------
  WRAPPERS   = cmdVxWorksTornado_wpr.c
  SOURCES    =
  LIB_SRCS   = $(SOURCES) $(WRAPPERS)
  LIB_OBJS   = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS      = $(LIB_SRCS)

# define meta rules
# ------------------
  LIBS   :=  libRuntimeVxWorks
  JDOC   :=  libRuntimeVxWorks
  SHARED :=  libRuntimeVxWorks
  override SHLIBS := $(TORNADO_DLL) $(WTX_DLL) $(JWRAP_DLL) $(TORNADO_LIB) $(TCL_LIB) $(SHLIBS)
  EXE    :=

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = $(TORNADO_DEF) $(VXWORKS_DEF)
  MK_INCLUDES = $(TORNADO_INCL)
  override JWRAP_TARGET   := --cc2tornado
  override JWRAP_CPP_INCL = -I$(TORNADO_BASE)

# rule for jWrap generation from .c
# ---------------------------------
cmdVxWorksTornado_wpr.c: headerVxWorksTornado.h $(TOP_JWRAP)
	${jWrapRule}

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libRuntimeVxWorks.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libRuntimeVxWorks${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Produce doc with javadoc for this lib
# -------------------------------------
${JDOCDIR}/libRuntimeVxWorks.html: ${SOURCES}
	${jDocRule}

endif



