#       Copyright(c) 97-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   Test jTcl module
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/typemap-c/Build.mk,v $
#      State       : $State: Exp $
#
#Modification History
#--------------------
#011,20feb98,Fulup written from jIc
#

# We do not install binaries
# --------------------------
  NOT_INSTALL=1

# Map malloc on Tcl_Alloc
# --------------------------------
  MK_DEFINES  = -DJWRAP_MALLOC
  MK_INCLUDES =
# Define modules
# ------------------------
  WRAPPERS = funcDemoTypemap_jWrap.c
  LIB_SRCS = funcDemoTypemap.c translateDemoTypemap.c $(WRAPPERS)
  LIB_OBJS  = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCS = mainDemoTypemap.c
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS= $(BIN_SRCS) $(LIB_SRCS)

# define meta rules
# ------------------
  LIBS   :=  libDemoTypemap
  SHARED :=  libDemoTypemap
  EXE    :=  DemoTypemapSh

ifeq (${ARCH_OS_NAME},Linux)
  override SHLIBS := $(JWRAP_DLL)
endif
ifeq (${ARCH_OS_NAME},WinDos)
  override SHLIBS := $(JWRAP_DLL) $(TCL_LIB) $(SHLIBS)
endif

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libDemoTypemap.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}
	@cp ${INCDIR}/libDemoTypemap.i .

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoTypemap${LIB_SFX}: ${LIB_OBJS}
	${libRule}
	@$(CP) $@ .

# rule for jWrap generation from .c
# ---------------------------------
funcDemoTypemap_jWrap.c: funcDemoTypemap.h $(TOP_JWRAP)
	${jWrapRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoTypemapSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoTypemap$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX)
	${binRule} $(TCL_LIB) ${LDLIBS}


# test rule
# ---------
test:: ${BINDIR}/DemoTypemapSh${EXE_SFX}
	${BINDIR}/DemoTypemapSh${EXE_SFX} scriptDemoTypemap.tcl
