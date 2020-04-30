#
#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Le Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   Readline interface
# Auteur    :   Fulup Le Foll (Fulup@fridu.bzh)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 13:06:43 $
#      Revision    : $Revision: 1.4 $
#      Source      : $Source: /Master/jWrap/readline/src/Build.mk,v $
#
#Modification History
#--------------------
#011,02mar99 written
#

# don't try to compile in WinBug 
# ----------------------------------
ifndef READLINE_LIB
exe:
	$(CECHO) READLINE_LIB not defined in $(ARCH_OS).mk ignore module
else
# Define modules
# --------------
  WRAPPERS   = cmdRuntimeReadline_jWrap.c
  SOURCES    = tclReadline.c

  LIB_SRCS   = $(SOURCES) $(WRAPPERS)
  LIB_OBJS   = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  BIN_SRCS  = mainShellReadline.c
  BIN_OBJS  = $(BIN_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})        

  SRCS       = $(SOURCES)

# define meta rules
# ------------------
  LIBS   :=  libRuntimeReadline
  JDOC   :=  libRuntimeReadline
  SHARED :=  libRuntimeReadline
  EXE    :=  ReadlineSh

  override SHLIBS :=  $(JWRAP_DLL) $(READLINE_DLL)

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = 
  MK_INCLUDES = $(READLINE_INCL)

# rule for jWrap generation from .c
# ---------------------------------
cmdRuntimeReadline_jWrap.c: headerReadline.h ../../Include/libRuntimeReadline.h $(TOP_JWRAP)
	${jWrapRule}           

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libRuntimeReadline.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}           

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libRuntimeReadline${LIB_SFX}: ${LIB_OBJS}
	${libRule}

# Produce doc with javadoc for this lib
# -------------------------------------
${JDOCDIR}/libRuntimeReadline.html: ${SOURCES}
	${jDocRule}

# Effectively Build exe files [warning to lib order !!!]
# ------------------------------------------------------
${BINDIR}/ReadlineSh${EXE_SFX}: $(BIN_OBJS) \
        $(LIBDIR)/libRuntimeReadline$(LIB_SFX) \
        $(LIBDIR)/libRuntimeJwrap$(LIB_SFX) \

	${binRule}  ${JWRAP_LIB} $(TCL_LIB) -lreadline -lncurses $(LIBFENCE) ${LDLIBS}

# On solaris neither Readline neither termcap are shipped in DLL mode !!!
ifeq ($(ARCH_OS_NAME),Solaris)
install::
	@echo force installsharable readline termcap in $(RUNTIME_SHLDIR)
	$(CP) $(PMASTER)/shadow/lib/libtermcap.so       $(RUNTIME_SHLDIR)
	$(CP) $(PMASTER)/shadow/lib/libreadline.so      $(RUNTIME_SHLDIR)
endif
endif
