#
#  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
#
# Projet    :   Jos/jWrap
# Module    :   Test/Tornado
# Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:31 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/zDemo/msg/Makefile,v $
#
# Modification History
# --------------------
# 01a,28feb98,Fulup,written

## ---------------------------------------------------------------
#              basic Makefile for jWrap Demo
#
# This Makefile is only operation in binary distribution in
# source tree user should use Fridu Common tools.
# ---------------------------------------------------------------

# Host Compiler name
CC        = gcc
CC_LIB    =
CC_INCL   =


# Adapt jWrap location to your site
JWRAP_HOME = $(HOME)/local
JWRAP_BIN  = $(JWRAP_HOME)/bin/jWrap
JWRAP_LIB  = -L$(JWRAP_HOME)/lib -lRuntimeJwrap
JWRAP_INCL = -I$(JWRAP_HOME)/include -I$(JWRAP_HOME)/include/Unix

# Tcl 8.x location
TCL_HOME   =  /usr/local
TCL_LIB    = -L$(TCL_HOME)/lib -ltcl8.6 -lm -ldl
TCL_INCL   = -I$(TCL_HOME)/include

# Tornado location
TORNADO_HOME   =  $(WIND_BASE)
TORNADO_HOST   =  sun4-solaris2
TORNADO_LIB    = -lRuntimeTornado -L$(TORNADO_HOME)/host/$(TORNADO_HOST)/lib -lwpwr -lthread
TORNADO_INCL   = -I/usr/include -I$(TORNADO_HOME)/host/include
TORNADO_DEF    = -DHOST=$(TORNADO_HOST) -DEASYC_PROTO_ONLY

# Definition of the C++ library to wrap. This are read-only files
 HEADERS   = cmdDemoMsg.h
 LIB_OBJS  = cmdDemoMsg_wpr.o
 BIN_OBJS  = mainDemoMsg.o

# Define C comilation options warning tcl should be before tornado
CFLAGS =  $(TCL_INCL) $(TORNADO_INCL) $(TORNADO_DEF) $(JWRAP_INCL)

help:
	@echo WARNING: this Makefile assume Fridu jWrap is in:
	@echo ----------------------------------------------------------
	@echo "  jWrap home      = $(JWRAP_HOME)"
	@echo "  tcl80 home      = $(TCL_HOME)"
	@echo "  tornado home    = $(TORNADO_HOME) host = $(TORNADO_HOST)"
	@echo "  C host compiler = $(CC)"
	@echo ----------------------------------------------------------
	@echo avaliable options:
	@echo
	@echo "  \"make static\"  Build a custom tclsh embedding example"
	@echo "  \"make shared\"  Not implement for Tornado example"
	@echo "  \"make clean\"   Clean up all tempry files"
	@echo ----------------------------------------------------------

all: static shared

static: DemoMsgSh
shared: libDemoMsg.so

cmdDemoMsg_wpr.c: $(HEADERS)
	$(JWRAP_BIN) --verbose --cc2wpr $(HEADERS)

DemoMsgSh: $(LIB_OBJS) $(BIN_OBJS)
	$(CC) $(LIB_OBJS) $(BIN_OBJS) $(TORNADO_LIB) $(JWRAP_LIB) $(TCL_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo " 1) start your custom tclsh \"./DemoMsgSh\""
	@echo " 2) check jWrap componant is activated \"jWrap info\""
	@echo " 3) source demo \"source scriptDemoMsg.jTcl\""
	@echo -------------------------------------------------------------------------

clean:
	rm -f DemoMsgSh libDemoMsg.so $(LIB_OBJS) $(BIN_OBJS) core *~
