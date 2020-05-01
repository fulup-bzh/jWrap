#
#  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
#
# Object    :   show complex Structure and typedef mechanism
# Projet    :   Jos/jWrap
# Module    :   Test/jWrap
# Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/structure-c/scriptDemoStruct.jTcl,v $
#
# Modification History
# --------------------
# 01a,28feb98,Fulup,written
#



# Check jWrap DemoStruct jWrap demonstration module is loaded
if [catch {jWrap info DemoStruct} ERR] {
  puts "ERROR: This demonstration require ModuleStruct to loaded."
  puts "Restart stript with DemoStructSh Executable or load libDemoStruct.so in tclsh."
  puts "Example: load /home/fulup/Workspace/Fridu/Exe/linux86/lib/libDemoStruct.so"
  return -code error
}

jWrap debug 10

## ---------------------------------------------------------------------------
# WARNING: On Tcl garbage collector [IMPORTANT!!!]
# ================================================
# Interfacing complex structure including pointers impose you
# to cooperate with TCL garbage collector, and it is not obvious !!!
# Don't forget that when doing set A [myCmd "toto"] Tcl will delete
# "toto" string as soon it will have some time. This is not a problem
# if toto is only used in myCmd, but is myCmd produce a result that
# include toto, it can be very complex to debug. The result is usually
# a core dump in Tcl garbage collector, or puts, or anywhere else !
# If you are not sure of your application you can cheat Tcl garbage collector
# forcing a reference on your input parameters doing:
#   set PRM "toto"
#   myCmd $PRM
#   myNextCmd
#   unset PRM
## ----------------------------------------------------------------------------


## --------------------------------------------------------------------
# Non regression test coming from Wandel & Goltermann Irps project
## --------------------------------------------------------------------
jWrap new  str_sadr {}
jWrap new  str_sadr {{type USER_SPECIFIC} {digits "123452345"}}

jWrap new  str_CC_S_BIND_REQ [list \
  {app_q_id 35645} {ctx_max 2} {con_type 5} {mode 0} {data_service FALSE} \
  [list ref [jWrap cast int8u 233]] \
  [list user_to_user NULL]  \
]

## --------------------------------------------------------------------
# We don't have to force type because testIt is type and
# Will update WPR_ID internal REP automatically
## --------------------------------------------------------------------
set FILE [DemoStruct.fopen /etc/passwd r]
if [jWrap isnull $FILE] {
  puts "Warning: can't open /etc/passwd"
} else {
  puts "open /etc/passwd file handle is: $FILE"
}

## --------------------------------------------------------------------
# We don't have to force type because testIt is type and
# Will update WPR_ID internal REP automatically
## ---------------------------------------------------------------------
set WPR_ID "
  {toolName titi}
  {targetName toto}
  {within {
     {B  255}
     {C  4096}
    }
  }
  {jointure {
     {C A B C D ...}
   }
  }
  {vIoNum  1024}
  {array 1 2 3 -1 ...}
  {
    fichier $FILE
  }
"

## ----------------------------------------------------------------------
# Call First demo Func in order checking WPR_ID validity
## ----------------------------------------------------------------------
set RES_ID [DemoStruct.testIt $WPR_ID]


## ----------------------------------------------------------------------
# Check our cookie is still valid
## ----------------------------------------------------------------------
puts "\n\Check we can fclose file from cookie"
puts "-------------------------------------------------------------------"
set FILE [jWrap cget $RES_ID fichier]
if {![jWrap isnull $FILE]} {
  DemoStruct.fclose $FILE
  puts " done"
} else {
  puts "no /etc/passwd to close"
}

## -----------------------------------------------------------------------
# Check or external rep; WARNING: after foreach RES_ID
# change it WPR_ID internal rep for a TclObj_list rep
# this operation will also free application internal REP
# CONCLUSION: don't move to a TclList except if you know
#  what you are doing!!!
## ------------------------------------------------------------------------
puts "\n\$WPR_ID Type = [jWrap type $RES_ID] "
puts "---------------------------------------------------------------------"
foreach SLOT $RES_ID {
    puts [format "%-15s = %s" [lindex $SLOT 0] [lrange $SLOT 1 end]]
}
puts "---------------------------------------------------------------------"

## -------------------------------------------------------------------------
# Check Null pointer
## -------------------------------------------------------------------------
puts "\n\Check for Null pointer handling "
puts "---------------------------------------------------------------------"
set  RES_ID [DemoStruct.testIt [jWrap cast WPR_ID_Ptr 0]]
puts " RES_ID=$RES_ID"

## -------------------------------------------------------------------------
# Get only one slot from a structure, we first build a
# Complex type with testIt routine and then change only
# toolName, slot value.
# WARNING: In order values not to be deleted with TCL you should
#   set them in a value, and not pass them directly in parameters.
## --------------------------------------------------------------------------
set INPUT_LST {{toolName toto} {targetName titi}}
set RES_ID [DemoStruct.testIt $INPUT_LST]
puts "\nRES_ID = $RES_ID"

set  TOOL [jWrap cget $RES_ID  toolName]
puts "\nToolName Slot = $TOOL"

## --------------------------------------------------------------------------
# Create first linked list element,
# WARNING: linked list are complex because you have to cheat
#   Tcl garbage collector. A C/C++ list with no preparation will
#   surely run in bus error. Reading a C/C++ linked list
#   can be done with no troubles.
#   linked list from Tcl.
# Why it fail: because when doing "set JWRAP(DemoStruct.listHead) $ONE"
#   you create two object with one the internal representation
#   and in this case we cannot use cget structure because
#   JWRAP(DemoStruct.listHead) is a global C variable. As soon
#   you store a new value [ex: set JWRAP(DemoStruct.listHead) $TWO]
#   Tcl will free previous value making $ONE internal rep pointing
#   on a free buffer. The only solution in order to avoid this is to
#   manage malloc/free routine by your own.
# Why it can works in batch: because we don't go in idle loop making Tcl
#   1:not going in garbage routines [a miracle !!!]. This should be avoided
#     because it definitively doesn't work.
#   2:because next field is a cookie [a type unknow to jWrap] in this case
#     we dont free it. This is the good option, check C structure declaration
#     in C example and Tcl mandatory cast here after.
# Conclusion: Except if you are locked, it is a good ideas to provide some
#     C manual wrapper for handling linked list from Tcl.
## ----------------------------------------------------------------------------
parray JWRAP
set ONE   [list {name one} {ind 1}]
set JWRAP(DemoStruct.listHead) $ONE
DemoStruct.testLst

set TWO   [list {name two}   {ind 2} [list next [jWrap cast void_Ptr $ONE]]]
set JWRAP(DemoStruct.listHead) $TWO
DemoStruct.testLst

set THREE [list {name three} {ind 3} [list next [jWrap cast void_Ptr $TWO]]]
set JWRAP(DemoStruct.listHead) $THREE
DemoStruct.testLst

## ----------------------------------------------------------------------------
# Loop in Tcl on list, we used jWrap equal in order testing
# internal value without translating to an external format.
## ----------------------------------------------------------------------------
puts "\nDump linked list from Tcl "
puts "--------------------------------------------------"
for {set IND 0;set SLOT $JWRAP(DemoStruct.listHead)} \
    {![jWrap equal $SLOT 0]} \
    {set SLOT [jWrap cast linkedList [jWrap cget $SLOT next]]} {

  incr IND
  puts "ind=$IND name=[jWrap cget $SLOT name]"
}

puts "Normal end"
