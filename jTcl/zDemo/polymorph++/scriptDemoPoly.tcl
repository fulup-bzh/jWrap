#
#  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
#
# Object    :   show basic jTcl/C++ multiheritage mecanism
# Projet    :   Jos/jWrap
# Module    :   Test/jWrap
# Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/jTcl/zDemo/polymorph++/scriptDemoPoly.jTcl,v $
#
# Modification History
# --------------------
# 01a,28feb98,Fulup,written
#

# ------------------------------------------------------------------------------------------
# This small program shows how a jTcl can acces C++ polymorph methods
# WARNING: when overloading C++ polymorph method jTcl all C++ methods are
#          overloaded with one jTcl method !!!!
# ------------------------------------------------------------------------------------------

# Include jTcl wrapper file in demo mode
# -------------------------------------
if [catch {package require jTcl}] {
  puts "Can't find jTcl Package check TCLLIBPATH variable environemnt"
  return -code error
}

# Check jWrap DemoPoly jWrap demonstration module is loaded
if [catch {jWrap info DemoPoly} ERR] {
  puts "ERROR: This demonstration require ModulePoly to loaded."
  puts "Restart stript with DemoPolySh Executable or load libDemoPoly.so in tclsh."
  return -code error
}

# Import basic Object package
# ---------------------------
  jClassImport "lang.object.*"

## ----------------------------------------------------------------------------
# jTclJoint extends CxxA jTcl_Object
## ----------------------------------------------------------------------------
class jTclObj {
    extends CxxObj
    extends Object
} {
    # "Add a new method to our class"
    public AnOtherMethod {} {
      puts "Koukouk you are in jTclAB.AnOtherMethod method"
    }
} ;# "end jTclAB class"


# create a new object AB
# ----------------------
 set ID [new jTclObj]

# pass a C++ handle from jTcl to a C++method
# -------------------------------------------
# as we one 3 method with one param we have to force type and
# call method using lowlevel Tcl interface bypassing jTcl calling handler
 CxxObj.probe $ID [jWrap cast char_Ptr "This is a valid string"]
 CxxObj.probe $ID [jWrap cast int 4]

# As we only have one method with 2 params we don't have to force type
 $ID probe 4 "valid string"

puts "*** test MultiOk OK ***"

free $ID





