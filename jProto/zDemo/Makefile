#  $Header: /Master/jWrap/jProto/zDemo/Makefile,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
#
#       Copyright(c) 96-97 FRIDU a Free Software Company (Fulup Ar Foll)
#
# File      :   Build.mk produce ansi proto from C/C++ source file
# Projet    :   Rubicon jWrap
# Module    :   Test
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:29 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jProto/zDemo/Makefile,v $
#      State       : $State: Exp $
#
#Modification History
#--------------------
#011,20feb98,Fulup written from jIc
#

# Where to find jWrap
# -------------------
  override PATH:=$(TOP)/Fridu/Exe/$(ARCH_OS)/bin:$(PATH)

all: funcType.i funcLibProto.i

funcProto.i: funcProto.cxx
	@echo Genrating Ansi proto from funcProto.cxx
	jWrap --cproto funcProto.cxx

funcType.i: funcType.h
	@echo generating proto from funcType.h
	jWrap --cproto funcType.h


