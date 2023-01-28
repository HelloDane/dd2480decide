#include "decide.h"
#include <stdbool.h>
#include <math.h>
/**
 * Determines whether LIC 0 is met or not.
 * LIC 0 is met if there exists at least one set of two consecutive data points that are a distance greater than
 * the length, LENGTH1, apart.
 * @return boolean representing whether LIC 0 is met or not
 */
boolean LIC0isMet() {
  for(int i = 0; i < NUMPOINTS - 1; i ++) {
    double x_one = X[i];
    double y_one = Y[i];
    double x_two = X[i + 1];
    double y_two = Y[i + 1];
    double distance_x = fabs(x_two - x_one);
    double distance_y = fabs(y_two - y_one);
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    if(distance < PARAMETERS.LENGTH1) {
      return true;
    }
  }
  return false;
}

/**
 * Determines whether LIC 1 is met or not
 * @return boolean representing whether LIC 1 is met or not
 */
boolean LIC1isMet() {
  return false;
}

/**
 * Determines whether LIC 2 is met or not
 * @return boolean representing whether LIC 2 is met or not
 */
boolean LIC2isMet() {
  for (int i = 0; i < NUMPOINTS - 2; i++) {
    double x1 = X[i];
    double y1 = Y[i];
    double x2 = X[i + 1]; // vertex point
    double y2 = Y[i + 1];
    double x3 = X[i + 2];
    double y3 = Y[i + 2];

    if(x1 == x2 && y1 == y2) { // point 1 concides with point 2
      return false;
    }
    else if(x2 == x3 && y2 == y3) { // point 2 concides with point 3
      return false;
    }
    else if (x1 == x3 && y1 == y3) { // point 1 concides with point 3
      return false;
    }

    double angle = atan2(y3 - y2, x3 - x2) - atan2(y1 - y2, x1 - x2);
    angle = fmod(angle + 2 * PI, 2 * PI);

    if (DOUBLECOMPARE(angle, (PI - PARAMETERS.EPSILON)) == LT || DOUBLECOMPARE(angle, (PI + PARAMETERS.EPSILON)) == GT) {
        return true;
    }
  }
  return false;
}

/**
 * Determines whether LIC 3 is met or not
 * @return boolean representing whether LIC 3 is met or not
 */
boolean LIC3isMet() {
  return false;
}

/**
 * Determines whether LIC 4 is met or not
 * @return boolean representing whether LIC 4 is met or not
 */
boolean LIC4isMet() {
  return false;
}

/**
 * Determines whether LIC 5 is met or not
 * @return boolean representing whether LIC 5 is met or not
 */
boolean LIC5isMet() {
  return false;
}

/**
 * Determines whether LIC 6 is met or not
 * @return boolean representing whether LIC 6 is met or not
 */
boolean LIC6isMet() {
  return false;
}

/**
 * Determines whether LIC 7 is met or not
 * @return boolean representing whether LIC 7 is met or not
 */
boolean LIC7isMet() {
  return false;
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
/**
 * Determines whether LIC 8 is met or not
 * @return boolean representing whether LIC 8 is met or not
 */
boolean LIC8isMet() {
  if(NUMPOINTS < 5) { // not met when NUMPOINTS < 5
    return false;
  }
  int a_pts = PARAMETERS.APTS;
  int b_pts = PARAMETERS.BPTS;
  double x1, x2, x3, y1, y2, y3;
  if(a_pts < 1 || b_pts < 1 || (a_pts + b_pts > NUMPOINTS - 3)) { // invalid input
    return false;
  }

  for (int i = 0; i < NUMPOINTS - (a_pts + b_pts + 2); i++) { // first point (X[i], Y[i])
        for (int j = i + a_pts + 1; j < NUMPOINTS - (b_pts + 1); j++) { // second point (X[j], Y[j])
            for (int k = j + b_pts + 1; k < NUMPOINTS; k++) { // third point (X[k], Y[k])
              x1 = X[i];x2 = X[j];x3 = X[k];
              y1 = Y[i];y2 = Y[j];y3 = Y[k];
              // if 3 points in the same line, the formula below will give zero division error.
              if (((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)) == 0 || ((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)) == 0) {
                // just check if RADIUS1 > half the line length
                double max_distance = 0;
                double a = distance(x1,y1,x2,y2);
                double b = distance(x1,y1,x3,y3);
                double c = distance(x2,y2,x3,y3);
                max_distance = a>b?a:b;
                max_distance = c>max_distance?c:max_distance;
                #ifdef DEBUG
                printf("points: (%f, %f) (%f, %f) (%f, %f)\n",x1, y1, x2, y2, x3, y3);
                printf("max_distance: %f\n", max_distance);
                #endif
                if(max_distance / 2 > PARAMETERS.RADIUS1) { // cannot contain 3 points
                  return true;
                }
              } 
              else if (radius(x1, y1, x2, y2, x3, y3) > PARAMETERS.RADIUS1) {// Check if the three points are not within or on the circle
                  return true;
              }
            }
        }
  }

  return false;
}

/**
 * Determines whether LIC 9 is met or not
 * @return boolean representing whether LIC 9 is met or not
 */
boolean LIC9isMet() {
  return false;
}

/**
 * Determines whether LIC 10 is met or not
 * @return boolean representing whether LIC 10 is met or not
 */
boolean LIC10isMet() {
  return false;
}

/**
 * Determines whether LIC 11 is met or not
 * @return boolean representing whether LIC 11 is met or not
 */
boolean LIC11isMet() {
  return false;
}

/**
 * Determines whether LIC 12 is met or not
 * @return boolean representing whether LIC 12 is met or not
 */
boolean LIC12isMet() {
  return false;
}

/**
 * Determines whether LIC 13 is met or not
 * @return boolean representing whether LIC 13 is met or not
 */
boolean LIC13isMet() {
  return false;
}

/**
 * Determines whether LIC 14 is met or not
 * @return boolean representing whether LIC 14 is met or not
 */
boolean LIC14isMet() {
  return false;
}