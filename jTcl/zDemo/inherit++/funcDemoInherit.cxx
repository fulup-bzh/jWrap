/*--------------------------------------------
 * Example taken from Swig Inherit directory
 *--------------------------------------------*/

#include <math.h>
#include <stdio.h>

#include "funcDemoInherit.h"

EXPORT char *Inherit_help="This a a basic C++ example from swig toolkit";


double Point1::mag(void) {
     return x;
}

int Point1::count = 0;

double Point1::mag1(void) {
   printf ("test count:%d\n",Point1::count);
     return x;
}

double Point2::mag(void) {
    return sqrt(x*x + y*y);
}
double Point2::mag2(void) {
    return sqrt(x*x + y*y);
}

double Point3::mag(void) {
    return sqrt(x*x + y*y + z*z);
}
double Point3::mag3(void) {
    return sqrt(x*x + y*y + z*z);
}





