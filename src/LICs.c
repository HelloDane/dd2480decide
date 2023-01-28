#include "decide.h"
#include <stdbool.h>
#include <math.h>
/**
 * Determines whether LIC 0 is met or not
 * @return boolean representing whether LIC 0 is met or not
 */
boolean LIC0isMet() {
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
  return false;
}