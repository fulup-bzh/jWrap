#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# Projet    :   jWrap
# Module    :   Test/jWrap jTcl module
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/event-c/Build.mk,v $
#
#Modification History
#--------------------
#01,01sep98,Fulup written
#

# We do not install binaries
# --------------------------
  NOT_INSTALL=1
  MK_DEFINES  = -DJWRAP_MALLOC

# Define modules
# ------------------------
  WRAPPERS = libDemoEvent_jWrap.c
  LIB_SRCS = funcDemoEvent.c $(WRAPPERS)
  LIB_OBJS  = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCS = mainDemoEvent.c
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS= $(BIN_SRCS) $(LIB_SRCS)

# define meta rules
# ------------------
  EXE    :=  DemoEventSh
  LIBS   :=  libDemoEvent
  SHARED :=  libDemoEvent

ifeq (${ARCH_OS_NAME},Linux)
  override SHLIBS := $(JWRAP_DLL)
endif
ifeq (${ARCH_OS_NAME},WinDos)
  override SHLIBS := $(JWRAP_DLL) $(TCL_LIB) $(SHLIBS)
endif

# define some extra option for TK
# --------------------------------
  MK_DEFINES  =
  MK_INCLUDES =

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libDemoEvent.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}
	$(CP) ${INCDIR}/libDemoEvent.i .

# rule for jWrap generation from .c
# ---------------------------------
libDemoEvent_jWrap.c: libDemoEvent.h $(TOP_JWRAP)
	${jWrapRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoEvent${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoEventSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoEvent$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX)  \

	${binRule} $(TCL_LIB) ${LDLIBS} $(LIBFENCE)


# test rule
# ---------
test:: ${BINDIR}/DemoEventSh${EXE_SFX}
	${BINDIR}/DemoEventSh${EXE_SFX} scriptDemoEvent.jTcl
