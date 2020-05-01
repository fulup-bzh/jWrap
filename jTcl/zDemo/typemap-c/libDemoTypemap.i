/*--------------------------------- 
: Ansi prototypes generated automaticaly 
: file /home/fulup/Workspace/Fridu/Exe/linux86/include/libDemoTypemap.i 
: from funcDemoTypemap.i translateDemoTypemap.i funcDemoTypemap_jWrap.i 
: by fulup on fulup-desktop the 01-May-20[19h28] 
: ------------------------------------ */
#ifndef JWRAP_JTCL 
#ifdef __cplusplus 
extern "C" { 
#endif 
IMPORT char *vStamp_libDemoTypemap ;
#ifdef __cplusplus 
} 
#endif 
#endif 
#ifdef __cplusplus
 extern "C" {
#endif
extern  char *TypeMap_help ;
extern  typeMapAdrs *lastAdr ;
PUBLIC int checkOpt (SomeOptions option) ;
PUBLIC int addOneToInt (int number) ;
PUBLIC char* stringToUpper (char* chaine) ;
PUBLIC char** listToUpper (char ** list) ;
PUBLIC int evalTclInC (Tcl_Interp *interp, Tcl_Obj *objPtr) ;
PUBLIC void printAdr (typeMapAdrs *adr) ;
PUBLIC void checkVarg (JWRAP_varg *varg) ;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
 extern "C" {
#endif
PUBLIC void customInitType (Tcl_Interp *interp) ;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
 extern "C" {
#endif
RESTRICTED int Demotypemap_Init (Tcl_Interp *interp) ;
#ifdef __cplusplus
}
#endif


