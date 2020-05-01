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
#      Source      : $Source: /Master/jWrap/tornado/shell/Build.mk,v $
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
  BIN_SRCS  = mainShellTornado.c
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})
  SRCS      = $(BIN_SRCS)

# define meta rules
# ------------------
  EXE    := TornadoSh

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = $(TORNADO_DEF)
  MK_INCLUDES = $(TORNADO_INCL)

# Effectively Build exe files [warning to lib order !!!]
# ------------------------------------------------------
${BINDIR}/TornadoSh${EXE_SFX}: $(BIN_OBJS) \
	$(LIBDIR)/libRuntimeVxWorks$(LIB_SFX) \
	$(LIBDIR)/libRuntimeTornado$(LIB_SFX) \
	$(LIBDIR)/libRuntimeWtx$(LIB_SFX) \
	$(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \
	$(LIBDIR)/libRuntimeReadline$(LIB_SFX) \

	${binRule}  ${JWRAP_LIB} ${TORNADO_LIB} $(TCL_LIB) $(READLINE_LIB) $(LIBFENCE) ${LDLIBS}

endif
