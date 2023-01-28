#include "decide.h"
#include <stdbool.h>

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
  return false;
}

/**
 * Determines whether LIC 3 is met or not
 * LIC 3 is met if there exists there consecutive points which form a triangle with an area greater than PARAMETERS.AREA1 
 * @return boolean representing whether LIC 3 is met or not
 */
boolean LIC3isMet() {
  for(int i = 0; i < NUMPOINTS - 2; i ++) {
    double x_1 = X[i];
    double y_1 = Y[i];
    double x_2 = X[i + 1];
    double y_2 = Y[i + 1];
    double x_3 = X[i + 2];
    double y_3 = Y[i + 2];

    double area = 1.0/2 * fabs(x_1*(y_2 - y_3) + x_2*(y_3 - y_1) + x_3*(y_1 - y_2));
    
    if(area > PARAMETERS.AREA1) {
      return true;
    }
  }

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