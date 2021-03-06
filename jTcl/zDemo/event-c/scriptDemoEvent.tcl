 # --------------------------------------------------------------------------------
 # Copyright(c) 1997-98 FRIDU a Free Software Company
 #
 # Projet       : Test
 # SubModule    : Tct event
 # Object       : Demos Tcl8 event registration
 # Author       : Fulup Ar Foll (Fulup@iu-vannes.fr)
 #
 # Last:
 #  Author      : $Author: Fulup $ Date        :
 #  Date        : $Date: 1999/03/11 12:49:30 $
 #  Revision    : $Revision: 1.3.0.1 $
 #  Source      : $Source: /Master/jWrap/jTcl/zDemo/event-c/scriptDemoEvent.jTcl,v $
 #
 # Modification History
 # -------------------
 # 1.1  02sep98, Fulup Written
 # --------------------------------------------------------------------------


 ## --------------------------------------------------------------------------
 #    In order running this example:
 #      1: Startit with " DemoEventSh scriptDemoEvent.jTcl HostName Port"
 #
 #    This demos connect on localhost echo server, using a private event
 #    handler. A timer send two lines of data onto echo server each 3 seconds
 #    As server echo datas, socket become readable and Tcl getData callback
 #    is called in order reading socket.
 #
 #    WARNING: This example only shows how interfacing a private event into
 #    Tcl already provide a socket mecanism that should be used for any
 #    network application.
 #
 #    - start a local echo server on tcp 1234  (accept ports 1024-4096)
 #      mkfifo /tmp/fifo && cat /tmp/fifo  | nc -k -l 1234 -v | cat  > /tmp/fifo
 #    - start your jWrap test
 #      DemoEventSh scriptDemoEvent.jTcl localhost 1234
 ## --------------------------------------------------------------------------

# Check jWrap DemoEvent jWrap demonstration module is loaded
if [catch {jWrap info DemoEvent} ERR] {
  puts "ERROR: This demonstration require ModuleEvent to loaded."
  puts "Restart stript with DemoEventSh Executable or load libDemoEvent.so in tclsh."
  return -code error
}

proc getData {PORT} {
  # this routine is call each time socket is readable
  puts "----------------------------------"
  puts "Socket $PORT is readable"
  set RES [DemoEvent.get $PORT]
  puts "----------------------------------"
  puts $RES
  puts "waiting new data on socket"
}

proc sendData {PORT} {
 global COUNT

  # initialize counter on first run
  if {![info exist COUNT]} {set COUNT 0}
  incr COUNT

  # send some data onto server
  DemoEvent.put $PORT "$COUNT: premier ligne\n"
  DemoEvent.put $PORT "$COUNT: deuxieme ligne\n"

  # restart timer
  after 3000 "sendData $PORT"
}

proc startIt {{HOST localhost} {PORT 1234}} {
 global FOREVER

  # connect on localhost echo server
  set ID [DemoEvent.start . $HOST $PORT "getData $PORT"]

  # Start sending data on serveur socket
  sendData $PORT

  puts "-------------------------------------"
  puts "Tcl waiting for event"
  puts "-------------------------------------\n"
  vwait FOREVER
}

# --------- main -------------
eval startIt $argv
