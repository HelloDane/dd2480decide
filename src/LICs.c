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
 * LIC 6 is met if there exists PARAMETERS.NPTS consecutive points
 * so that for at least one of the points, the distance from that point
 * to the line between the first and last point is greater than PARAMETERS.DIST
 * Requires
 * PARAMETERS.NPTS
 * PARAMETERS.DIST
 * NUMPOINTS
 * where
 * 3 <= PARAMETERS.NPTS <= NUMPOINTS
 * 0 <= PARAMETERS.DIST
 * @return boolean representing whether LIC 6 is met or not
 */
boolean LIC6isMet() {

  if(NUMPOINTS < 3) {
    return false;
  }

  int npts = PARAMETERS.NPTS;
  if(npts > NUMPOINTS || npts < 3 || PARAMETERS.DIST < 0) {
    // This is invalid input
    return false;
  }

  // Example thought process for the loop
  // With npts = 3, and NUMPOINTS = 3, we want to loop once
  // Then this will loop from i = 0 to i < 1, which is once
  for(int i = 0; i < NUMPOINTS - npts + 1; i ++) {
    double firstx = X[i];
    double firsty = Y[i];

    // Motivation for subtraction of 1
    // if npts is 3 and NUMPOINTS is 3, then when first point is 0, then last point should be 2
    // 0 + 3 - 1 = 2
    double lastx = X[i + npts - 1];
    double lasty = Y[i + npts - 1];

    // Check all of the consecutive points, if they fulfill the criteria
    for(int j = i; j < i + npts; j ++) {

      if(firstx == lastx && firsty == lasty) {
        // First and last point lie at the same spot, measure distance to this point instead
        double distance = sqrt(pow(X[j] - firstx, 2) + pow(Y[j] - firsty, 2));
        if(distance > PARAMETERS.DIST) {
          return true;
        }
        continue;
      }
      
      // Formula defined on https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line under "Line defined by two points"
      double x1 = firstx;
      double y1 = firsty;
      double x2 = lastx;
      double y2 = lasty;
      double x0 = X[j];
      double y0 = Y[j];
     
      double distance = fabs((x2 - x1)*(y1 - y0) - (x1 - x0)*(y2 - y1))/sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
      
      if(distance > PARAMETERS.DIST) {
        return true;
      }
    }
  }
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
  return false;
}