
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: -
 *   Date: Thu May 14 22:34:29 1998

 *   jWrap --javadoc TcpHttpd.java

 *   Except if you really know what you are doing you should
 *   not edit this file by hand.
 *
 *   In order rebuilding it use jWrap
 + ------------------------------------------------------------ */
package jWrap.httpd;

/** --------------------------------------------------
*  Standard httpd class handle text,html & gif files 
*  Use Tcp Server as super class 
*//

public class TcpHttpd 
 extends TcpServer 
  {
  // Vars sub-section

/**  Class for each new incomming client 
 *//
 public  static String clientsClass;

/**  Default localy managed mime type 
 *//
 public  static String mimes;

/**  Default error  messages 
 *//
 public  static String errors;

/**  Default error formating   
 *//
 public  static String errFmt;

/**  Default Index file Name 
 *//
 public  static String index;

  // Methods sub-section

/**  Generate a date string in HTTP format [from SUN example] 
  *//
 public  String date (String SECONDS) {};

/**  html error procedure 
  *//
 public  String error (String CODE, String URL, String MSG) {};

/**  Build a Valid Httpd answer from buffer 
  *//
 public  String header (String CLIENT_ID, String MIME, String FILE) {};

/**  Build full path name and open URL 
  *//
 public  String openUrl (String URL) {};

/**  get file type from extention & retreive URL 
  *//
 public  String mime (String EXT, String CLIENT_ID) {};

/**  Process httpd request  
  *//
 public  String process (String CLIENT_ID) {};

/**  Accept method if call by accept even on wellkow socket 
  *   Https overload it in order cancelling all auth control 
  *//
 public  String accept (String SOCK, String CLIENT_HOST, String PORT) {};

/**  Httpd constructor Add $ROOT_DIR in Tcl Autopath 
  *   check $ROOT_DIR is a valid directoty and call 
  *   it super class in order starting Tcp socket server 
  *//
 public  String TcpHttpd (String PORT, String ROOT_DIR) {};

  // Vars sub-section

  // Methods sub-section

  // Vars sub-section

  // Methods sub-section
}