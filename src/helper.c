#include <math.h>
#include "decide.h"
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double radius(double x1, double y1, double x2, double y2, double x3, double y3) {
  double a=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
  double b=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)));
  double radius=sqrt((x1-a)*(x1-a)+(y1-b)*(y1-b));

  #ifdef DEBUG
  printf("points: (%f, %f) (%f, %f) (%f, %f)\n",x1, y1, x2, y2, x3, y3);
  // printf("center: (%f, %f)\n", cx, cy);
  printf("radius: %f\n", radius);
  #endif
  return radius;
}