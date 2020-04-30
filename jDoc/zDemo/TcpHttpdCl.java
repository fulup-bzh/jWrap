
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: -
 *   Date: Thu May 14 22:34:29 1998

 *   jWrap --javadoc TcpHttpdCl.java

 *   Except if you really know what you are doing you should
 *   not edit this file by hand.
 *
 *   In order rebuilding it use jWrap
 + ------------------------------------------------------------ */
package jWrap.httpd;

/** ----------------------------------------------------------------------------
*  A new object of class TcpHttpdCl is created for each new incomming client 
*//

public class TcpHttpdCl 
 extends TcpChannel 
  {
  // Methods sub-section

/**  callback when a fcopy is done 
  *//
 public  String fcopyDone (String FD, String LEN) {};

/**  et line from browser until empty line 
  *//
 public  String read () {};

/**  End of page method 
  *//
 public  String write (String PAGE) {};

/**  Constructor called at each Browser accept 
  *//
 public  String TcpHttpdCl (String HTTPD_ID, String HOST, String SOCK, String PORT) {};

  // Methods sub-section

  // Methods sub-section
};
