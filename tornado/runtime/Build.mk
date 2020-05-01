#
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
#      Source      : $Source: /Master/jWrap/tornado/runtime/Build.mk,v $
#
#Modification History
#--------------------
#012,06mar99,Fulup added directRuntimeTornado
#011,20Apr98,Fulup written
#

# Only compile this directory if tornado is defined
# -------------------------------------------------
ifdef TORNADO_BASE

# Define modules
# --------------
  WRAPPERS   = cmdRuntimeTornado_jWrap.c
  SOURCES    = typeRuntimeTornado.c stringRuntimeWpr.c  miscRuntimeTornado.c \
               attachRuntimeTornado.c execRuntimeTornado.c moduleRuntimeTornado.c \
               targetRuntimeTornado.c varRuntimeTornado.c directRuntimeTornado.c

  LIB_SRCS   = $(SOURCES) $(WRAPPERS)
  LIB_OBJS   = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS       = $(LIB_SRCS)

# define meta rules
# ------------------
  LIBS   :=  libRuntimeTornado
  JDOC   :=  libRuntimeTornado
  SHARED :=  libRuntimeTornado
  SHARED :=  libRuntimeTornado

ifeq (${ARCH_OS_NAME},Linux)
  override SHLIBS := $(WTX_DLL) $(JWRAP_DLL) $(TORNADO_LIB)
endif
ifeq (${ARCH_OS_NAME},WinDos)
  override SHLIBS := $(WTX_DLL) $(JWRAP_DLL) $(TORNADO_LIB) $(TCL_LIB) $(SHLIBS)
endif

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = $(TORNADO_DEF)
  MK_INCLUDES = $(TORNADO_INCL)

# rule for jWrap generation from .c
# ---------------------------------
cmdRuntimeTornado_jWrap.c: headerTornado.h ../../Include/libRuntimeTornado.h $(TOP_JWRAP)
	${jWrapRule}

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libRuntimeTornado.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libRuntimeTornado${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Produce doc with javadoc for this lib
# -------------------------------------
${JDOCDIR}/libRuntimeTornado.html: ${SOURCES}
	${jDocRule}

endif
