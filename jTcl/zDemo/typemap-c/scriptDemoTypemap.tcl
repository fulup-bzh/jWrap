#
#  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
#
# File      :   funcScript.tcl show basic jTcl/C++ type convertion mecanism
# Projet    :   jWrap
# Module    :   jTcl C++ wrapper
# Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/typemap-c/scriptDemoTypemap.jTcl,v $
#      State       : $State: Exp $
#
# Modification History
# --------------------
# 01b,06mar99,Fulup,added varg
# 01a,28feb98,Fulup,written
#

# Check jWrap DemoTypemap jWrap demonstration module is loaded
if [catch {jWrap info DemoTypemap} ERR] {
  puts "ERROR: This demonstration require ModuleTypemap to loaded."
  puts "Restart stript with DemoTypemapSh Executable or load libDemoTypemap.so in tclsh."
  return -code error
}
puts "Wellcome to typeMap: $JWRAP(TypeMap_help)"

# Check full comand arguement passing
# -----------------------------------
DemoTypemap.checkVarg {10 {--int 4} {--float 5.0} {--string toto}}
DemoTypemap.checkVarg [list 10 12 13]
DemoTypemap.checkVarg [list [list --int 4]]

# Check symbolic token with enum
# ------------------------------
DemoTypemap.checkOpt OPT_1
DemoTypemap.checkOpt OPT_2

if [catch {DemoTypemap.checkOpt OPT4} ERR] {
 puts "OK OPT4: $ERR"
}

# integer int/long
# -----------------
for {set ind 0} {$ind <60} {set ind [DemoTypemap.addOneToInt $ind]} {
  puts -nonewline "."
}
puts "OK"

# string char*
# -------------
puts [DemoTypemap.stringToUpper "OK: demat deoc'h"]

# array of string  char** (input && output)
# -----------------------------------------
puts [DemoTypemap.listToUpper [list "OK" "An" "Amzer" "a" "zo" "brav"]]

# give Tcl_Interp to a function (note: script interp value is ignore)
# -------------------------------------------------------------------
DemoTypemap.evalTclInC interp "puts \"OK: It Works this is evaluated within C\""

# send an application custom structure
# ------------------------------------
set  ADR  [list "Ar Foll" "Fulup" "22 rue Cariel" "56860" "Sene"]
DemoTypemap.printAdr $ADR
puts "OK static last ADR: $JWRAP(lastAdr)"

# check a cookie with an fopen
# ----------------------------
set FILE [DemoTypemap.fopen  "/etc/passxxx" "r"]
if {[jWrap isnull $FILE]} {
  puts stderr "OK /etc/passxxx does not exist"
} else {
  puts stderr "ERROR /etc/passxxx should not exist"
}

set FILE [DemoTypemap.fopen  "/etc/passwd" r]
if [jWrap isnull $FILE] {
  puts "ERROR /etc/passwd should exist"

} else {

  puts "Dumping /etc/passwd"
  set BUFFER [jWrap.Tcl_Alloc 255]
  puts "BUFFER Handle= $BUFFER"

  # Make sure LINE is never free
  set LINE ""

  while 1 {
    # read until end of line
    set LINE [DemoTypemap.fgets $BUFFER 255 $FILE]
    if [jWrap isnull $LINE] break
    puts -nonewline "$BUFFER: $LINE"
  }

  # clean up cookies
  puts "Closing /etc/passwd"
  jWrap.Tcl_Free  $BUFFER
  DemoTypemap.fclose $FILE

  # display cookie on screen
  puts "\nCOOKIES external representation FILE=$FILE BUFFER=$BUFFER"
}
puts ""
puts "--------------------------------------------"
puts " OK: jWrap DemoTypemap map test Normal end"
puts "--------------------------------------------"
