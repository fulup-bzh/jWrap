# ---------------------------------------------------------------
#              basic Makefile for jWrap demo
#
# This Makefile is only operation in binary distribution in
# source tree user should use Fridu Common tools.
# ---------------------------------------------------------------

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
 HEADERS   = funcDemoInherit.h
 LIB_OBJS  = funcDemoInherit_jWrap.o funcDemoInherit.o
 BIN_OBJS  = mainDemoInherit.o

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
	@echo "  \"make static\"  Build a custom tclsh named DemoInheritSh"
	@echo "  \"make shared\"  Build a shared library"
	@echo "  \"make clean\"   Clean up all tempry files"
	@echo ----------------------------------------------------------

# Default C++ compilation rule
%.o: %.cxx
	$(CXX) -c $(CFLAGS) $<

all: static shared

static: DemoInheritSh
shared: libDemoInherit.so

funcDemoInherit_jWrap.cxx: $(HEADERS)
	$(JWRAP_BIN) --verbose --cc2jTcl $(HEADERS)

DemoInheritSh: $(LIB_OBJS) $(BIN_OBJS)
	$(CXX) $(LIB_OBJS) $(BIN_OBJS) $(JWRAP_LIB) $(TCL_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo " 1) start your custom tclsh \"./DemoInheritSh\""
	@echo " 2) check jWrap componant is activated \"jWrap info\""
	@echo " 3) source demo \"source scriptDemoInherit.jTcl\""
	@echo -------------------------------------------------------------------------

libDemoInherit.so: $(LIB_OBJS)
	$(LD) -shared $(LIB_OBJS) $(JWRAP_LIB) $(CXX_LIB) -o $@
	@echo -------------------------------------------------------------------------
	@echo "in order testing: $@"
	@echo " 1) include current directory in search path \"export LD_LIBRARY_PATH=.\""
	@echo " 2) start a tclsh shell \"tclsh\" ot \"tclsh8.0\""
	@echo " 3) load your jWrap Demo component \"load libDemoInherit.so DemoInherit\""
	@echo " 4) check jWrap componant is activated \"jWrap info\""
	@echo " 5) source demo \"source scriptDemoInherit.jTcl\""
	@echo -------------------------------------------------------------------------

clean:
	rm -f DemoInheritSh libDemoInherit.so $(LIB_OBJS) $(BIN_OBJS) core *~
