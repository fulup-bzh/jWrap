#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# Module    :   Wtx VxWorks Tornado interface
# Auteur    :   Fulup Ar Foll (Fulup@fridu.bzh)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:31 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/wrs/wtx/Build.mk,v $
#
#Modification History
#--------------------
#02,20feb99,Fulup force ../Include [local wtx includes]
#01,20Apr98,Fulup written
#

ifdef TORNADO_BASE

# Compile WTX on LINUX only on Solaris use original WRS version
# -------------------------------------------------------------
ifeq (${ARCH_OS_TYPE},Unix)

# Define modules
# --------------
  LIB_SRCS  = regcomp.c   regerror.c  regfree.c   wtxexch.c   xdrwtx.c \
              regexec.c   wtx.c       wtxrpc.c
  LIB_OBJS  = $(LIB_SRCS:%.c=${OBJDIR}/%${OBJ_SFX})

  SRCS      = $(LIB_SRCS)

# define meta rules
# ------------------
  LIBS   := libLinuxWtx
  SHARED := libLinuxWtx

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = $(TORNADO_DEF)
  MK_INCLUDES = -I../Include $(TORNADO_INCL)
  override ARCH_OS_CCOPTIONS=-Wall

# don't try to build dependancies from WTS header files
# -----------------------------------------------------
  override CDEPEND = echo >/dev/null

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libLinuxWtx.i: $(LIB_SRCS:%.c=${DEPDIR}/%.i)
	${protoRule}

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libLinuxWtx${LIB_SFX}: ${LIB_OBJS}
	${libRule}

endif
endif
