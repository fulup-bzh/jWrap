#
#  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
#
# Projet    :   Jos/jWrap
# Module    :   jTcl C++ wrapper
# Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/overload++/scriptDemoOverload.jTcl,v $
#
# Modification History
# --------------------
# 01a,28feb98,Fulup,written
#


# Include jTcl wrapper file in demo mode
# -------------------------------------
if [catch {package require jTcl}] {
  puts "Can't find jTcl Package check TCLLIBPATH variable environemnt"
  return -code error
}

# Check jWrap DemoOverload jWrap demonstration module is loaded
if [catch {jWrap info DemoOverload} ERR] {
  puts "ERROR: This demonstration require ModuleOverload to loaded."
  puts "Restart stript with DemoOverloadSh Executable or load libDemoOverload.so in tclsh."
  return -code error
}

jClassImport "lang.object.*"

## ----------------------------------------------------------------------------
# jTclCovert extends CxxConvert and overload signal routine from CxxObject
## ----------------------------------------------------------------------------
class jTclConvert {extends CxxConvert} {

  ## --
  #  "signal is a C++ virtual method that is overloaded with a jTcl method"
  #  "@param MSG a string of character from C++"
  ## --
  public signal {MSG} {
    puts stderr "jTclConvert.signal: (overloaded C++ method) MSG=$MSG"
  }

} ;# "end jTclConvert"

puts "Wellcome to Overload demo: $JWRAP(Overload_help)"

set CONVERTER [new jTclConvert]

set VALID_NUM  1234
set VALID_HEXA 0xABCD

set INVALID_NUM  1234567899
set INVALID_HEXA "demat deoc'h"

# Try first valid number onlu use inheritancy mecanism
puts "num ->$VALID_NUM  == hexa [$CONVERTER int2hexa $VALID_NUM]"
puts "hexa->$VALID_HEXA == num  [$CONVERTER hexa2int $VALID_HEXA]"
puts "----------- End OK case ----------\n"

# Try invlaid number should use overload mecanism
puts "num ->$INVALID_NUM  == hexa [$CONVERTER int2hexa $INVALID_NUM]\n"
puts "hexa->$INVALID_HEXA == num  [$CONVERTER hexa2int $INVALID_HEXA]\n"

free $CONVERTER

puts "*** test Overload OK ***"







