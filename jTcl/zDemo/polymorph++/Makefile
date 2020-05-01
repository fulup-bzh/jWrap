#
# Copyright(c) 1997-98 FRIDU a Free Software Company
#
# Projet       : Jos/jWrap
# SubModule    : Test
# Implement    : DemoSimple
# Object       : Minimal Makefile for runtime tree tesing
# Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last:
#  Author      : $Author: Fulup $ Date        :
#  Date        : $Date: 1999/03/11 12:49:30 $
#  Revision    : $Revision: 1.3.0.1 $
#  Source      : $Source: /Master/jWrap/jTcl/zDemo/polymorph++/Makefile,v $
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

# Compiler name
CXX        = g++
CXX_LIB    = -lstdc++
CXX_INCL   =

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
 HEADERS   = funcDemoPoly.h
 LIB_OBJS  = funcDemoPoly_jWrap.o funcDemoPoly.o
 BIN_OBJS  = mainDemoPoly.o

# Define C comilation options
CFLAGS =  -I. $(CXX_INCL) $(TCL_INCL) $(JWRAP_INCL)

help:
	@echo WARNING: this Makefile assume Fridu jWrap is in:
	@echo ----------------------------------------------------------
	@echo "  jWrap home   = $(JWRAP_HOME)"
	@echo "  tcl80 home   = $(TCL_HOME)"
	@echo "  C++ compiler = $(CXX)"
	@echo ----------------------------------------------------------
	@echo avaliable options:
	@echo
	@echo "  \"make static\"  Build a custom tclsh named DemoPolySh"
	@echo "  \"make shared\"  Build a shared library"
	@echo "  \"make clean\"   Clean up all tempry files"
	@echo ----------------------------------------------------------

# Default C++ compilation rule
%.o: %.cxx
	$(CXX) -c $(CFLAGS) $<

all: static shared

static: DemoPolySh
shared: libDemoPoly.so

funcDemoPoly_jWrap.cxx: $(HEADERS)
	$(JWRAP_BIN) --verbose --cc2jTcl $(HEADERS)

DemoPolySh: $(LIB_OBJS) $(BIN_OBJS)
	$(CXX) $(LIB_OBJS) $(BIN_OBJS) $(JWRAP_LIB) $(TCL_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo " 1) start your custom tclsh \"./DemoPolySh\""
	@echo " 2) check jWrap componant is activated \"jWrap info\""
	@echo " 3) source demo \"source scriptDemoPoly.jTcl\""
	@echo -------------------------------------------------------------------------

libDemoPoly.so: $(LIB_OBJS)
	$(LD) -shared $(LIB_OBJS) $(JWRAP_LIB) $(CXX_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo "in order testing: $@"
	@echo " 1) include current directory in search path \"export LD_LIBRARY_PATH=.\""
	@echo " 2) start a tclsh shell \"tclsh\" ot \"tclsh8.0\""
	@echo " 3) load your jWrap Demo component \"load libDemoPoly.so DemoPoly\""
	@echo " 4) check jWrap componant is activated \"jWrap info\""
	@echo " 5) source demo \"source scriptDemoPoly.jTcl\""
	@echo -------------------------------------------------------------------------

clean:
	rm -f DemoPolySh libDemoPoly.so $(LIB_OBJS) $(BIN_OBJS) core *~
