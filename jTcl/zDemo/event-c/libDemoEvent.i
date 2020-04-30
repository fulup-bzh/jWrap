/*--------------------------------- 
: Ansi prototypes generated automaticaly 
: file /home/fulup/Workspace/Fridu/Exe/linux86/include/libDemoEvent.i 
: from funcDemoEvent.i libDemoEvent_jWrap.i 
: by fulup on fulup-desktop the 28-Apr-20[11h59] 
: ------------------------------------ */
#ifndef JWRAP_JTCL 
#ifdef __cplusplus 
extern "C" { 
#endif 
IMPORT char *vStamp_libDemoEvent ;
#ifdef __cplusplus 
} 
#endif 
#endif 
#ifdef __cplusplus
 extern "C" {
#endif
PUBLIC void initModule (Tcl_Interp *interp) ;
PUBLIC int start (Tcl_Interp *interp, Tcl_Obj *host, int port, Tcl_Obj *callback) ;
PUBLIC void stop (int port) ;
PUBLIC void put (int port, Tcl_Obj *msg) ;
PUBLIC Tcl_Obj* get (int port) ;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
 extern "C" {
#endif
RESTRICTED int Demoevent_Init (Tcl_Interp *interp) ;
#ifdef __cplusplus
}
#endif


