#!/bin/sh -f
#
# Start Tcl interpretor
# \
exec tclsh  "$0" ${1+"$@"} 
#
# Copyright(c) 1999 FRIDU a Free Software Company
# 
# Projet       : jWrap
# SubModule    : WTX VxWorks Tornado Interface
# Author       : Fulup Le Foll (Fulup@iu-vannes.fr)
# 
# Last: 
#  Author      : $Author: Fulup $ Date        :
#  Date        : $Date: 1999/03/19 17:59:07 $
#  Revision    : $Revision: 1.5 $
#  Source      : $Source: /Master/jWrap/tornado/shell/TornadoSh.tcl,v $
# 
# Modification History
# --------------------
# 01b, 19mar99,Fulup added an automode from fridu_home+history maping
# 01a, 05mar99,Fulup written

# if fridu_home is not set try to do it now
if {![info exist env(FRIDU_HOME)]} {
  set   DIR [file dirname $argv0]
  cd    $DIR/../..
  set   env(FRIDU_HOME) [pwd]

  if [info exist env(JTCL_DEBUG)] {
    puts "Warning: autolocate FRIDU_HOME to |$env(FRIDU_HOME)|"
  }
   # Add JTCL file in version reverse order
  if [catch {lsort -decreasing [glob $env(FRIDU_HOME)/*/bin/pkgIndex.tcl]} REP] {
       puts "ERROR: Can't find JTCL in default location set FRIDU_HOME or JTCL_PATH"
       puts "Directory : |$env(FRIDU_HOME)| is not a valid FRIDU_HOME"
       exit
  } else {
      # remove trailing Etc/Package.jTcl from JTCL_PATH
      foreach SLOT $REP {
         set dir  [file dirname $SLOT]
         uplevel #0 source $SLOT
      }
  }  
} 

# we use jTcl package management
if [catch {package require jTcl}] {
  puts "ERROR: did not find jTcl package pleaser set FRIDU_HOME"
  exit 1
}

# import DLL loading facilities
jClassImport jWrap.jTcl.getopt.*
jClassImport jWrap.jTcl.loader.*

# We need jWrap module to process arguments
jWrapComponantLoad  libRuntimeJwrap jWrap

# build arguement array
set SET_OPT(target)        [list 2 "AsToBeSet" "Target server name"]
set SET_OPT(registry)      [list 1 "none"      "Registry host"]
set SET_OPT(debug)         [list 1 "0"         "Debug level 0-9"]
set SET_OPT(tool)          [list 1 "TornadoSh" "Tool name on Target server"]
set SET_OPT(noshowroutine) [list 0 "0"         "Dont include WRS shell proc"]

# effectivelly check arguments
if [catch {jWrapCheckArgument SET_OPT GET_OPT $argv} RESULT] {
  puts $RESULT
  exit 1
} else {

  # check we dont have any remainding unprocessed argument
  if {$GET_OPT(argc) != 0} {
     puts "ERROR: unwanted arguments: |$GET_OPT(argv)|"
     exit 1
  }

  # Pass argument to application
  foreach {NAME VALUE} [array get GET_OPT *] {
    switch -- $NAME {
	debug    {jWrap debug $VALUE}
        target   {set TORNADO(target) $VALUE}
        tool     {set TORNADO(tool)   $VALUE}
        registry {jWrap.PutEnv "WIND_REGISTRY=$VALUE"}
    }
  }
} 

# If arguement are OK load all needed modules
 jWrapComponantLoad  libRuntimeReadline Readline
 jWrapComponantLoad  libRuntimeWtx      Wtx
 jWrapComponantLoad  libRuntimeVxWorks  VxWorks


# Connect onto target server
set TORNADO(id) [jWrap new TORNADO_id [list \
                [list targetName $TORNADO(target)] [list toolName $TORNADO(tool)]]]
if [catch {Tornado.Connect $TORNADO(id)} REPONSE] {
   puts "Cannot connect on registry=[jWrap.GetEnv WIND_REGISTRY] target=$TORNADO(target)\nERR=$REPONSE"
   exit 1
}

# make a direct acces to wtx id for WRS routines
set TORNADO(wtxId) [jWrap cget $TORNADO(id) wtxId]

# Bind our module, this function check all function on target
Tornado.ModuleBind $TORNADO(id) VxWorks BIND_LAZY

# Connect tornado Shell
if {!$GET_OPT(noshowroutine)} {
   # import basic thing in order to start WRS target show routines
   jClassImport jWrap.tornado.compat.*
   jClassImport jWrap.tornado.core.*
   jClassImport jWrap.tornado.show.*
   Shell.CoreInit
}

# Include basic Fridu use shell routine
  jClassImport jWrap.tornado.usr.*


# alias some usefull user command
  if {[info command unknown] != ""} {
    rename unknown tcl.unknown
  }
  if {[info command Show.I] != ""} {
    rename Show.I i
  }
  if {[info command history] != ""} {
    rename history tcl.history
    rename Readline.History history
  }
  rename Usr.Unknown unknown
  rename Usr.Ld ld
  rename Usr.Sp sp
  rename Usr.Reconnect reconnect

# In tk mode start a console in line mode enter readline
if [info exist tk_version] {
  jClassImport jWrap.readline.console.*
} else {
  # start readline
  Readline.Start
}






