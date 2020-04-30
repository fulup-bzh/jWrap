#       Copyright(c) 96-98 FRIDU a Free Software Company (Fulup Le Foll)
#
# Projet    :   jWrap
# Module    :   jTcl wrapping Demo
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/Mikhail++/Build.mk,v $
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
  WRAPPERS  = funcDemoMikhail_jWrap.cxx
  LIB_SRCXXS = $(WRAPPERS) funcDemoMikhail.cxx
  LIB_OBJS  = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCXXS = mainDemoMikhail.cxx 
  BIN_OBJS  = $(BIN_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS= $(BIN_SRCXXS) $(LIB_SRCXXS) 

# define meta rules
# ------------------
  LIBS   :=  libDemoMikhail
  SHARED :=  libDemoMikhail
  EXE    :=  DemoMikhailSh

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
${INCDIR}/libDemoMikhail.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i)
	${protoRule}
	@$(CP) $@ . 

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoMikhail${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# rule for jWrap generation from .c
# ---------------------------------
funcDemoMikhail_jWrap.cxx: funcDemoMikhail.h $(TOP_JWRAP)
	${jWrapRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoMikhailSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoMikhail$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \

	${binPlusRule} $(TCL_LIB) ${LDLIBS}

# test rule
# ---------
test:: ${BINDIR}/DemoMikhailSh${EXE_SFX}
	${BINDIR}/DemoMikhailSh${EXE_SFX} scriptDemoMikhail.jTcl
