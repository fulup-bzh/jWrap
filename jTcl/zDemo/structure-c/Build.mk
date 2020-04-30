#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Le Foll)
#
# Projet    :   jWrap
# Module    :   Test/jWrap/jTcl module
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/structure-c/Build.mk,v $
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
  WRAPPERS = funcDemoStruct_jWrap.c
  LIB_SRCS =  $(WRAPPERS)
  LIB_OBJS  = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCS = mainDemoStruct.c 
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS= $(BIN_SRCS) $(LIB_SRCS) 

# define meta rules
# ------------------
  EXE    :=  DemoStructSh
  LIBS   :=  libDemoStruct
  SHARED :=  libDemoStruct

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
${INCDIR}/libDemoStruct.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}
	@$(CP) $@ .

# rule for jWrap generation from .c
# ---------------------------------
funcDemoStruct_jWrap.c: funcDemoStruct.c $(TOP_JWRAP)
	${jWrapRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libDemoStruct${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Effectively Build exe files
# ---------------------------
${BINDIR}/DemoStructSh${EXE_SFX}: $(BIN_OBJS) \
			   $(LIBDIR)/libDemoStruct$(LIB_SFX) \
			   $(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \

	${binRule} $(TCL_LIB) ${LDLIBS} $(LIBFENCE)


# test rule
# ---------
test:: ${BINDIR}/DemoStructSh${EXE_SFX}
	${BINDIR}/DemoStructSh${EXE_SFX} scriptDemoStruct.jTcl
