#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Le Foll)
#
# Projet    :   jWrap
# Module    :   Test/jTcl module
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/overload++/Build.mk,v $
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
  WRAPPERS  = funcDemoOverload_jWrap.cxx
  LIB_SRCXXS = $(WRAPPERS) funcDemoOverload.cxx
  LIB_OBJS  = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCXXS = mainDemoOverload.cxx 
  BIN_OBJS  = $(BIN_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS= $(BIN_SRCXXS) $(LIB_SRCXXS) 

# define meta rules
# ------------------
  LIBS   :=  libDemoOverload
  SHARED :=  libDemoOverload
  EXE    :=  DemoOverloadSh

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

# set proto if any .i changed make a local copy for non Fridu makefile
# --------------------------------------------------------------------
${INCDIR}/libDemoOverload.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}
	@cp $@ . 

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoOverload${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# rule for jWrap generation from .c
# ---------------------------------
funcDemoOverload_jWrap.cxx: funcDemoOverload.h $(TOP_JWRAP)
	${jWrapRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoOverloadSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoOverload$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \

	${binPlusRule} $(TCL_LIB) ${LDLIBS}

# test rule
# ---------
test:: ${BINDIR}/DemoOverloadSh${EXE_SFX}
	${BINDIR}/DemoOverloadSh${EXE_SFX} scriptDemoOverload.jTcl
