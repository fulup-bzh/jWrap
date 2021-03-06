#
# Copyright(c) 1997-98 FRIDU a Free Software Company
#
# Projet       : Jos/jWrap
# SubModule    : Test
# Implement    : DemoSimple
# Object       : Swig basic example adapted to jWrap
# Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last:
#  Author      : $Author: Fulup $ Date        :
#  Date        : $Date: 1999/03/11 12:49:30 $
#  Revision    : $Revision: 1.3.0.1 $
#  Source      : $Source: /Master/jWrap/jTcl/zDemo/simple-c/scriptDemoSimple.jTcl,v $
#
# Modification History
# -------------------
# 01a,06may98, Fulup Written
#


# Check jWrap DemoSimple jWrap demonstration module is loaded
if [catch {jWrap info DemoSimple} ERR] {
  puts "ERROR: This demonstration require ModuleSimple to loaded."
  puts "Restart stript after loading libDemoSimple.so manually in tclsh."
  puts "example: load /home/fulup/Workspace/Fridu/Exe/linux86/lib/libDemoSimple.so"
  return -code error
}

puts [DemoSimple.get_time]
set tcl_precision 17
puts "My Double = $JWRAP(MyDouble)"
for {set i 0} {$i < 14} {incr i 1} {
    set n [DemoSimple.fact $i];
    puts "$i factorial is $n"
}

for {set i 1} {$i < 250} {incr i 1} {
    for {set j 1} {$j < 250} {incr j 1} {
	set n [DemoSimple.mod $i $j]
	set JWRAP(MyDouble) [expr {$JWRAP(MyDouble) + $n}]
    }
}

puts "MyDouble = $JWRAP(MyDouble)"
puts "---------------------------"
puts [DemoSimple.get_time]
puts "*** test DemoSimple OK ***"
