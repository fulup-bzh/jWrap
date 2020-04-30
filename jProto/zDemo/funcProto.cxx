/* ********************************************************************
   | 
   |  Basic example show how to generate a proto from a C/C++ source
   |
   |  WARNING: This file does not compile it only test C/C++ frontend
   |
   ********************************************************************/

#assert interface (demoModule)

// if you need to process include use cpp
#warning "Ignore include           " 
#include <stdio.h>
#include "test.h"

// Cpp generate usufull info in oder finding bug in original file
#warning "process cpp info         " 
# 11 "interface.demo"

// Check comment can have embedded keywords
// #define are handle as soon they have a definition
/* sdfsdf
sdfsdf
sdf
*/


// Suport of many define mode some are ignored
#warning "process #define          " 
#define TOTO  
#define SNOOPY 1
#define TITI   "Ceci est un text"

#define MACRO  any type of macro
#define PARAM_MACRO(a,b)   ((a) > (b) ? (a) : (b))
#define NOT_USED_FN __attribute__ ((unused))
#define NULL ((void *)0)
#define __long_double_t  long double

// ignore any inline proc
#warning "Ignore  Inline/Templates "
inline int qRound( double d )
{
    return d > 0.0 ? int(d+0.5) : int(d-0.5);
}

// ignore template
template<class type> class QArrayT : public QGArray {
  protected:
   QArrayT( int, int ) : QGArray( 0, 0 ) {}
}

// an hugly anum
#warning "Check all Enum types     "
enum QtMsgType { QtDebugMsg, QtWarningMsg, QtFatalMsg };
enum { max_lzw_bits=12 };

// Enumeration With initialisation
enum SomeOptions_1 {
   OPT_11           = 1
  ,OPT_12           = 2
  ,OPT_13           = 3
  };

// Enumeration With one initialisation
enum SomeOptions_2 {
   OPT_21           = 1
  ,OPT_22
  ,OPT_23
  };

// Enumeration Without initialisation
enum SomeOptions_3 {
   OPT_31
  ,OPT_32
  ,OPT_33
  };

// Public variables will be prototype as extern references 
#warning "Check many extern var proto"
EXPORT int Int_b;
EXPORT  int Int_A=4;
char * toto;
char * Char_Ptr= "Ceci est une chaine";
FILE * Fichier = open ("/tmp/toto", "w");
char ** table [10];
char ** table [10 + 2];
int  A_int,B_int, * C_int_ptr;
const bool FALSE = 0;
extern const QColor color0;
extern struct _IO_FILE_plus _IO_stdin_, _IO_stdout_, _IO_stderr_;
extern FILE *stdin, *stdout, *stderr;
extern const char * sys_errlist[];
int toto,titi,*tata;

// Public functions will be prototype as extern references 
#warning "Check many extern functions"
extern long int ftell  (FILE* fp)  ;

PUBLIC void PublicPrefixedFunctionName (int toto) {
   fprintf (stderr,"toto=%d\n", toto);
}
char* PublicNonPrefixedFunction (char* toto) {
   fprintf (stderr,"toto=%s\n", toto);
}
PUBLIC void ComplexUnsignedType (unsigned int a) {
 fprintf (stderr, "ComplexTypedFunc a=%d\n", a);
}
PUBLIC void *ComplexEnumType (enum SomeOptions_3) {
 fprintf (stderr, "ComplexTypedFunc a=%d\n", a);
}
PUBLIC void * ComplexConstType (const int SomeOptions_3) {
 fprintf (stderr, "ComplexTypedFunc a=%d\n", a);
}
const char* VeryComplexStructFunc (struct SomeOptions_3) {
 fprintf (stderr, "ComplexTypedFunc a=%d\n", a);
}
extern void *  externProto  (void *  dest, const void *  src,
                            size_t __n)  ;
extern int stat (char *path, struct stat *statbuf);

#warning "Ignore some useless proto"
// operator are ignored
QDataStream &operator<<( QDataStream &, const QArrayT<char>  & );
QArrayS <QChain*> *cols;
// Local function should be ignored
LOCAL   LocalFunction  (void) {};
static  StaticFunction (void) {};
static  bool first = TRUE;
STATUS	wtxExchangeInstall (WTX_XID xid, 
			    STATUS (*xCreate) (WTX_XID, const char *),
			    STATUS (*xDelete) (WTX_XID), 
			    STATUS (*xExchange) (WTX_XID, WTX_REQUEST,
						void *, void *),
			    STATUS (*xFree) (WTX_XID, WTX_REQUEST, void *),
			    STATUS (*xControl) (WTX_XID, UINT32, void *));

#assert jWrap (ignore)
    friend QNPStream; 
#assert jWrap (process)


// an empty class
#warning "Check empty class"
class ClassName;

// CC parser support 3 type of C++ protection
class CxxObject {
  unsigned int a;
  int A = 4;
  enum Spec { Rgb, Hsv };
  enum Test {
   A,
   B,
   C
  } Data1,Data2;
  QFont::StyleHint    styleHint()     const;
  const char *mbr_name;

  public:

    //unsuported operator & struct are ignored
    #warning "Ignore some complex proto"
    operator const char *() const;
    friend inline bool operator==( const QPoint &, const QPoint & );
    friend inline QPoint operator*( double, const QPoint & );
    friend        QPoint operator/( const QPoint &, int );
    operator!=( const QColorGroup &g ) const
                           { return !(operator==(g)); }
    QPoint &operator*=( int c );
    bool operator==( const QRect &, const QRect & );
    bool operator!=( const QRect &, const QRect & );
    QDataStream &operator<<( QDataStream &, const QRect & );
    QDataStream &operator>>( QDataStream &, QRect & );
    QArrayT <QChain*> *cols;
    QArrayT<char>  buffer() const;
    friend class TopComponentCore;

#assert jWrap (ignore)
    friend QNPStream; 
#assert jWrap (process)

    // Some hugly syntaxe jWrap support
    #warning "Try to understand some hugly proto"
    uint size() const  { return shd->len; }
    virtual void detach() { duplicate(*this); }
    void   setSystemNamedColor( const char *name );
    unsigned int test_public (void* titi) {};

  // Some more clean proto
   #warning "Process all traditionnal Ansi Proto" 
  protected:
    void **test_protected (void* toto) {};

  private:
  void *test_private (int titi) {};
};


class CxxProto : public CxxObject  ( const QArrayM_QPointData  & a)
{
 // A is private even witout private tag
 int a;
 int toto,titi,*tata;

 public:
  // signal method is call by jTcl each time there is problem
  void  signal (char *message) {
           printf ("one:signal message=%s\n", message);
  }

 // your public effective constructor
 CxxProto (int value) {
           printf ("  one::one int:Value=%d\n", value);
           one_int = value;
 }
 CxxProto (int v1, double v2) {
           printf ("  one::one int:V1=%d double:v2=%f\n", v1,v2);
 }
 QGManager::Direction dir;

 void	killPStack();
 protected:
# 283 "qpainter.h"
  Display    *dpy; 

}; // end class CxxProto
