#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# Projet    :   jWrap
# Module    :   Test/jWrap
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/inherit++/Build.mk,v $
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
  WRAPPERS  = funcDemoInherit_jWrap.cxx
  LIB_SRCXXS = $(WRAPPERS) funcDemoInherit.cxx
  LIB_OBJS  = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCXXS = mainDemoInherit.cxx
  BIN_OBJS  = $(BIN_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS= $(BIN_SRCXXS) $(LIB_SRCXXS)

# define meta rules
# ------------------
  EXE    :=  DemoInheritSh
  LIBS   :=  libDemoInherit
  SHARED :=  libDemoInherit

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
${INCDIR}/libDemoInherit.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}
	@cp $@ .

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoInherit${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# rule for jWrap generation from .c
# ---------------------------------
funcDemoInherit_jWrap.cxx: funcDemoInherit.h $(TOP_JWRAP)
	${jWrapRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoInheritSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoInherit$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \

	${binPlusRule} $(TCL_LIB) ${LDLIBS}

# test rule
# ---------
test:: ${BINDIR}/DemoInheritSh${EXE_SFX}
	${BINDIR}/DemoInheritSh${EXE_SFX} scriptDemoInherit.jTcl
