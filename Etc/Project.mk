#	Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   project.mk, project global definition
# Projet    : 	rtWeb
# SubModule :   Makefile configuration
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/19 08:09:27 $
#      Revision    : $Revision: 1.4 $
#      Source      : $Source: /Master/jWrap/Etc/Project.mk,v $
#
# Modification History
# --------------------
# 01e,15feb99,Fulup extract jWrap from JOS project
# 01d,31mar98,Fulup moved all specifics in arch.mk
# 01c,01Jun97,Fulup added Java & moved Runtime dir in default file
# 01b,28feb97,Fulup released jTcl
# 01a,20sep97,Fulup written
#
# Project Definition can be overrided by $(ARCH).mk
#
# Warning: This file deepely use GNU Make syntaxe, dont use your time trying
# -------  to run it with an ordinary make, you realy have to use gnu Make
# -------  When assigning Variable dont forget := is not equal to =
# -------  if you not sure that := will fit = is slower but works in any case

# Where to install production
# ---------------------------
  ifndef FRIDU_HOME
    FRIDU_HOME  := $(HOME)/pMaster/$(ARCH_OS)
  endif

  # WARNING: no space after those variables
  PRJ_VERSION   := jWrap-1.30
  INSTALL_DIR   := $(FRIDU_HOME)/$(PRJ_VERSION)

  CCDEBUG = 1

  JWRAP_CPP_INCL   = -I$(TOP)/$(PROJECT)/Include
  JWRAP_DLL        = $(L_FLG)RuntimeJwrap$(DLL_SFX)
  WTX_DLL          = $(L_FLG)RuntimeWtx$(DLL_SFX)
  TORNADO_DLL      = $(L_FLG)RuntimeTornado$(DLL_SFX)
  VXWORKS_DLL      = $(L_FLG)RuntimeVxWorks$(DLL_SFX)

  # Do not use     := for project variables
  PRJ_LIBRARIES    =  $(DL_LIB)
  LIBINCL          =  $(TOP)/$(PROJECT)/Include
  PRJ_INCLUDES     =  $(TCL_INCL)
  PRJ_CCOPTIONS    =  -Wno-write-strings -Wno-deprecated-declarations -Wno-int-to-pointer-cast \
                      -Wno-incompatible-pointer-types  \
                      -Wno-maybe-uninitialized -Wno-discarded-qualifiers -Wno-clobbered -Wno-pointer-to-int-cast
  PRJ_CCPLUSOPTIONS=  -fpermissive -Wno-write-strings -Wno-deprecated-declarations -Wno-int-to-pointer-cast

# For demo purpose Java class are kept in dev tree
# ------------------------------------------------
  override CLASSDIR := ../Class

# Global debug/optimization flag
# ------------------------------
# set all flasg for a full debug or oprtimized mode
# -------------------------------------------------
ifeq ($(CCDEBUG),1)
    DEBUGCCFLAGS=$(ARCH_OS_CCDEBUG)
    DEBUGSHFLAGS=$(ARCH_OS_SHDEBUG)
    DEBUGLDFLAGS=$(ARCH_OS_LDDEBUG)
else
    DEBUGCCFLAGS=$(ARCH_OS_CCO2)
    DEBUGSHFLAGS=$(ARCH_OS_SHO2)
    DEBUGLDFLAGS=$(ARCH_OS_LDO2)
    override LIBFENCE =
endif










