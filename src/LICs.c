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
 * True if there exists at least one set of three consecutive data points that cannot all be contained
 * within or on a circle of radius RADIUS1.
 * @return boolean representing whether LIC 1 is met or not
 */
boolean LIC1isMet() {
  if(NUMPOINTS < 3) {
    return false; // There must be at least 3 points.
  }
  for(int i = 0; i < NUMPOINTS - 2; i ++) {
    double x_1 = X[i];
    double y_1 = Y[i];
    double x_2 = X[i + 1];
    double y_2 = Y[i + 1];
    double x_3 = X[i + 1];
    double y_3 = Y[i + 1];
     // At least one of the distances between the pairs of data points must be greater than the diameter.
    if (distance(x_1,y_1,x_2,y_2) > PARAMETERS.RADIUS1*2 ||
        distance(x_2,y_2,x_3,y_3) > PARAMETERS.RADIUS1*2 ||
        distance(x_3,y_3,x_1,y_1) > PARAMETERS.RADIUS1*2) {
          return true;
    }
  }
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
  return false;
}