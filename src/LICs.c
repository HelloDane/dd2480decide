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

/**
 * Determines whether LIC 8 is met or not
 * @return boolean representing whether LIC 8 is met or not
 */
boolean LIC8isMet() {
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
  if(NUMPOINTS < 5) {
    return false;
  }
  if(PARAMETERS.AREA2 < 0) { //invalid input
    return false;
  }
  boolean flag1 = false;
  boolean flag2 = false;
  int e_pts = PARAMETERS.EPTS;
  int f_pts = PARAMETERS.FPTS;
  double a, b, c, p, area;
  double x1, y1, x2, y2, x3, y3;
 for (int i = 0; i < NUMPOINTS - (e_pts + f_pts + 2); i++) { // first point (X[i], Y[i])
  x1 = X[i];
  y1 = Y[i];
  for (int j = i + e_pts + 1; j < NUMPOINTS - (f_pts + 1); j++) { // second point (X[j], Y[j])
    x2 = X[j];
    y2 = Y[j];
    for (int k = j + f_pts + 1; k < NUMPOINTS; k++) { // third point (X[k], Y[k])
      x3 = X[k];
      y3 = Y[k];
      a = distance(x1, y1, x2, y2);
      b = distance(x2, y2, x3, y3);
      c = distance(x1, y1, x3, y3);
      p = (a + b + c) / 2.0;
      area = sqrt (p * (p - a) * (p - b) * (p - c));
      #ifdef DEBUG
      printf("(%f,%f)(%f,%f)(%f,%f)\n",x1,y1,x2,y2,x3,y3);
      printf("area = %f\n", area);
      #endif
      if(area > PARAMETERS.AREA1) {
        #ifdef DEBUG
        printf("flag1 true for area = %f\n", area);
        printf("AREA1 = %f\n", PARAMETERS.AREA1);
        #endif
        flag1 = true;
      }
      if(area < PARAMETERS.AREA2) {
        #ifdef DEBUG
        printf("flag2 true for area = %f\n",area);
        printf("AREA2 = %f\n", PARAMETERS.AREA2);
        #endif
        flag2 = true;
      }
    }
  }
 }
  if(flag1 && flag2) {
      return true;
  }
  return false;
}