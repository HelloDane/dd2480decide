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
 * Requires
 * NUMPOINTS
 * PARAMETERS.CPTS
 * PARAMETERS.DPTS
 * PARAMETERS.EPSILON
 * @return boolean representing whether LIC 9 is met or not
 */
boolean LIC9isMet() {

  if(NUMPOINTS < 5) {
    return false;
  }

  if(PARAMETERS.CPTS < 1 || PARAMETERS.DPTS < 1 || PARAMETERS.CPTS + PARAMETERS.DPTS > NUMPOINTS - 3) {
    // Invalid input as per description
    return false;
  }

  int points_set_length = 1 + PARAMETERS.CPTS + 1 + PARAMETERS.DPTS + 1;

  // Loop over all possible sets
  for(int i = 0; i < NUMPOINTS - points_set_length + 1; i ++) {
    double x0 = X[i];
    double y0 = Y[i];

    int secondIndex = i + PARAMETERS.CPTS + 1;
    double x1 = X[secondIndex];
    double y1 = Y[secondIndex];

    int thirdIndex = secondIndex + PARAMETERS.DPTS + 1;
    double x2 = X[thirdIndex];
    double y2 = Y[thirdIndex];

    // If the first or last point, or both, coincides with the vertex (middle point), return false
    if(x0 == x1 && y0 == y1) {
      return false;
    }
    if(x2 == x1 && y2 == y1) {
      return false;
    }

    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // Distance between point 0 and 1
    double b = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // Distance between point 1 and 2
    double c = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2)); // Distance between point 0 and 2

    // law of cosine
    double angle = acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b));
    
    if(angle < PI - PARAMETERS.EPSILON || angle > PI + PARAMETERS.EPSILON) {
      return true;
    }
  }
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