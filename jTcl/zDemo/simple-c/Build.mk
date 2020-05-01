#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# Projet    :   jWrap
# Module    :   Test/jWrap/jTcl module
# Auteur    :   Fulup Ar Foll (Fulup@fridu.bzh)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/simple-c/Build.mk,v $
#
#Modification History
#--------------------
#011,20feb98,Fulup written from jIc
#

# We do not install binaries
# --------------------------
  NOT_INSTALL=1

# Define modules
# ------------------------
  WRAPPERS = funcDemoSimple_jWrap.c
  LIB_SRCS =  $(WRAPPERS)
  LIB_OBJS  = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCS = mainDemoSimple.c
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS= $(BIN_SRCS) $(LIB_SRCS)

# define meta rules
# ------------------
  EXE    :=  DemoSimpleSh
  LIBS   :=  libDemoSimple
  SHARED :=  libDemoSimple

ifeq (${ARCH_OS_NAME},Linux)
  override SHLIBS := $(JWRAP_DLL)
endif
ifeq (${ARCH_OS_NAME},WinDos)
  override SHLIBS := $(JWRAP_DLL) $(TCL_LIB) $(SHLIBS)
endif

# Map malloc on Tcl_Alloc
# --------------------------------
  MK_DEFINES  = -DJWRAP_MALLOC
  MK_INCLUDES =

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libDemoSimple.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# rule for jWrap generation from .c
# ---------------------------------
funcDemoSimple_jWrap.c: funcDemoSimple.c $(TOP_JWRAP)
	${jWrapRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoSimple${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoSimpleSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoSimple$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \

	${binRule} $(TCL_LIB) ${LDLIBS} $(LIBFENCE)


# test rule
# ---------
test:: ${BINDIR}/DemoSimpleSh${EXE_SFX}
	${BINDIR}/DemoSimpleSh${EXE_SFX} scriptDemoSimple.tcl
