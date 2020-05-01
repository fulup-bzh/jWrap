#
#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# Projet    :   jWrap
# Module    :   Wtx VxWorks Tornado interface
# Auteur    :   Fulup Ar Foll (Fulup@fridu.bzh)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:31 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/zDemo/msg/Build.mk,v $
#
#Modification History
#--------------------
#02,16feb99,Fulup addapted to new jWrap rule
#01,02jun98,Fulup written
#

# Only compile this directory if tornado is defined
# -------------------------------------------------
ifdef TORNADO_BASE

# Define modules
# --------------
  WRAPPERS   = cmdDemoMsg_wpr.c
  LIB_SRCS   = $(WRAPPERS)
  LIB_OBJS   = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCS  = mainDemoMsg.c
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS      = $(LIB_SRCS) $(BIN_SRCS)


# define meta rules
# ------------------
  LIBS   :=  libDemoMsg
  SHARED :=  libDemoMsg
  override SHLIBS := $(TORNADO_DLL) $(WTX_DLL) $(JWRAP_DLL) $(TORNADO_LIB) $(TCL_LIB) $(SHLIBS)
  EXE    :=  DemoMsgSh

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = $(TORNADO_DEF)
  MK_INCLUDES = $(TORNADO_INCL)
  override JWRAP_TARGET   := --cc2tornado
  override JWRAP_CPP_INCL = -I$(TORNADO_BASE)

# rule for jWrap generation from .c
# ---------------------------------
cmdDemoMsg_wpr.c: cmdDemoMsg.h $(TOP_JWRAP)
	${jWrapRule}

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libDemoMsg.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoMsg${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoMsgSh${EXE_SFX}: $(BIN_OBJS) \
		$(LIBDIR)/libDemoMsg$(LIB_SFX) \
		$(LIBDIR)/libRuntimeVxWorks$(LIB_SFX)\
		$(LIBDIR)/libRuntimeWtx$(LIB_SFX)\
		$(LIBDIR)/libRuntimeTornado$(LIB_SFX)\
		$(LIBDIR)/libRuntimeJwrap$(LIB_SFX)\

	${binRule} $(TCL_LIB) ${LDLIBS} ${TORNADO_LIB} ${LIBFENCE}

endif



