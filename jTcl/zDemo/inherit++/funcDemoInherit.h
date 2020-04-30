/*--------------------------------------------
 *  Help: small C++ example
 *  Implement: DemoInherit
 *--------------------------------------------*/

#ifndef __funDemoInherit__
#define __funDemoInherit__

// exclude standard include from wrapping
#ifndef JWRAP_JTCL
#  include <libRuntimeJwrap.h>
#endif

#ifdef __cplusplus
 extern "C" {
#endif
extern  char *Inherit_help;
#ifdef __cplusplus
}
#endif

class Point1
  {
    public:
    // Vars sub-section
    double x;
    static int count;

    // Methods sub-section
    double mag (void);
    virtual double mag1 (void);

  };   // end class Point1

class Point2
  // Class heritage hierarchie
  :public Point1
  {
    public:
    // Vars sub-section
    double y;

    // Methods sub-section
    double mag (void);
    double mag2 (void);

  };   // end class Point2

class Point3
  // Class heritage hierarchie
  :public Point2
  {
    public:
    // Vars sub-section
    double z;

    // Methods sub-section
    double mag (void);
    double mag3 (void);

  };   // end class Point3

#include <libDemoInherit.i>
#endif
