#
# Copyright(c) 1997-98 FRIDU a Free Software Company
#
# Projet       : Jos/jWrap
# SubModule    : Test
# Implement    : DemoSimple
# Object       : Minimal Makefile for runtime tree tesing
# Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last:
#  Author      : $Author: Fulup $ Date        :
#  Date        : $Date: 1999/03/11 12:49:30 $
#  Revision    : $Revision: 1.3.0.1 $
#  Source      : $Source: /Master/jWrap/jTcl/zDemo/simple-c/Makefile,v $
#
# Modification History
# -------------------
# 01a,14jul98, Fulup Written
#
## ---------------------------------------------------------------
#              basic Makefile for jWrap demo
#
#  This Makefile is only operation in binary distribution in
#  source tree user should use Fridu Common Makefile skeleton.
## ---------------------------------------------------------------

# Define C compiler
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

# Definition of the C++ library to wrap. This are read-only files
 HEADERS   = funcDemoSimple.c
 LIB_OBJS  = funcDemoSimple_jWrap.o
 BIN_OBJS  = mainDemoSimple.o

# Define C comilation options
CFLAGS =  $(TCL_INCL) $(JWRAP_INCL)

help:
	@echo WARNING: this Makefile assume Fridu jWrap is in:
	@echo ----------------------------------------------------------
	@echo "  jWrap home = $(JWRAP_HOME)"
	@echo "  tcl80 home = $(TCL_HOME)"
	@echo "  C compiler = $(CC)"
	@echo ----------------------------------------------------------
	@echo avaliable options:
	@echo
	@echo "  \"make static\"  Build a custom tclsh named DemoSimpleSh"
	@echo "  \"make shared\"  Build a shared library"
	@echo "  \"make clean\"   Clean up all tempry files"
	@echo ----------------------------------------------------------

# Default C compilation rule
%.o: %.c
	$(CC) -c $(CFLAGS) $<

all: static shared

static: DemoSimpleSh
shared: libDemoSimple.so

funcDemoSimple_jWrap.c: $(HEADERS)
	$(JWRAP_BIN) --verbose --cc2jTcl $(HEADERS)

DemoSimpleSh: $(LIB_OBJS) $(BIN_OBJS)
	$(CC) $(LIB_OBJS) $(BIN_OBJS) $(JWRAP_LIB) $(TCL_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo " 1) start your custom tclsh \"./DemoSimpleSh\""
	@echo " 2) check jWrap componant is activated \"jWrap info\""
	@echo " 3) source demo \"source scriptDemoSimple.jTcl\""
	@echo -------------------------------------------------------------------------

libDemoSimple.so: $(LIB_OBJS)
	$(LD) -shared $(LIB_OBJS) $(JWRAP_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo "in order testing: $@"
	@echo " 1) include current directory in search path \"export LD_LIBRARY_PATH=.\""
	@echo " 2) start a tclsh shell \"tclsh\" ot \"tclsh8.0\""
	@echo " 3) load your jWrap Demo component \"load libDemoSimple.so DemoSimple\""
	@echo " 4) check jWrap componant is activated \"jWrap info\""
	@echo " 5) source demo \"source scriptDemoSimple.jTcl\""
	@echo -------------------------------------------------------------------------

clean:
	rm -f DemoSimpleSh libDemoSimple.so $(LIB_OBJS) $(BIN_OBJS) core *~
