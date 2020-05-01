#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   Wtx VxWorks Tornado interface
# Auteur    :   Fulup Ar Foll (Fulup@fridu.bzh)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:31 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/wtx/Build.mk,v $
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
  WRAPPERS   = cmdWtxTornado_jWrap.c
  SOURCES    =
  LIB_SRCS   = $(SOURCES) $(WRAPPERS)
  LIB_OBJS   = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS      = $(LIB_SRCS)

# define meta rules
# ------------------
  LIBS   :=  libRuntimeWtx
  JDOC   :=  libRuntimeWtx
  SHARED :=  libRuntimeWtx
  override SHLIBS := $(JWRAP_DLL) $(TORNADO_LIB) $(TCL_LIB) $(SHLIBS)
  EXE    :=

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = $(TORNADO_DEF)
  MK_INCLUDES = $(TORNADO_INCL)

# Alglomarate all jTixes .h in one big interface file ignore CPP errors
# ---------------------------------------------------------------------
ifdef REBUILD_DEF
proto:: cmdWtxTornado.def

cmdWtxTornado.def: headerWtxTornado.h
	@echo aglomerating Tornado header in $@
	$(CC_CMD) -I. -DJWRAP_JTCL -DJWRAP -DARCH_OS_NAME=$(ARCH_OS_TYPE) \
	-E $(TORNADO_DEF) \
	-dD -nostdinc -C $< >$@ 2>$(NULL_DEV) || exit 0
endif

# rule for jWrap generation from .c
# ---------------------------------
cmdWtxTornado_jWrap.c: cmdWtxTornado.def  headerWtxTornado.h $(TOP_JWRAP)
	@echo jWrapping Cc2jTcl from $<
	$(JWRAP) --verbose --cc2jTcl --include=./headerWtxTornado.h $<

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libRuntimeWtx.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libRuntimeWtx${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Produce doc with javadoc for this lib
# -------------------------------------
${JDOCDIR}/libRuntimeWtx.html: ${SOURCES}
	${jDocRule}

endif


