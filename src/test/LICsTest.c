#include "../decide.h"
#include <assert.h>

/**
 * TODO
 */
void testLIC0isMet() {
  
}

/**
 * TODO
 */
void testLIC1isMet() {
  
}

/**
 * TODO
 */
void testLIC2isMet() {
  
}

/**
 * TODO
 */
void testLIC3isMet() {

  // In the problem instance below, points 1, 2 and 3 form a triangle with area 2 * 2 / 2 = 2 units
  // The fourth point lies between them, causing a smaller area when combined with any pair of other points
  NUMPOINTS = 4;
  X[0] = 1;
  Y[0] = 1;
  X[1] = 2;
  Y[1] = 3;
  X[2] = 3;
  Y[2] = 1;
  X[3] = 2;
  Y[3] = 1.8;

  PARAMETERS.AREA1 = 1.95;
  boolean isMet = LIC3isMet(); // Should be true since 2 > 1.95
  if(!isMet) {
    LOGE("LIC3isMet returned false when it should have returned true");
  }

  PARAMETERS.AREA1 = 3.2;
  isMet = LIC3isMet(); // Should be false since 2 < 3.2
  if(isMet) {
    LOGE("LIC3isMet returned true when it should have returned false");
  }

  // reorder points so it is not the 3 first ones that form the triangle (swapped 0 and 3)
  X[0] = 2;
  Y[0] = 1.8;
  X[1] = 2;
  Y[1] = 3;
  X[2] = 3;
  Y[2] = 1;
  X[3] = 1;
  Y[3] = 1;

  PARAMETERS.AREA1 = 1.95;
  isMet = LIC3isMet(); // Should be true since 2 > 1.95
  if(!isMet) {
    LOGE("LIC3isMet returned false when it should have returned true");
  }

  PARAMETERS.AREA1 = 3.2;
  isMet = LIC3isMet(); // Should be false since 2 < 3.2
  if(isMet) {
    LOGE("LIC3isMet returned true when it should have returned false");
  }
}

/**
 * TODO
 */
void testLIC4isMet() {
  
}

/**
 * TODO
 */
void testLIC5isMet() {
  
}

/**
 * TODO
 */
void testLIC6isMet() {
  
}

/**
 * TODO
 */
void testLIC7isMet() {
  
}

/**
 * TODO
 */
void testLIC8isMet() {
  
}

/**
 * TODO
 */
void testLIC9isMet() {
  
}

/**
 * TODO
 */
void testLIC10isMet() {
  
}

/**
 * TODO
 */
void testLIC11isMet() {
  
}

/**
 * TODO
 */
void testLIC12isMet() {
  
}

/**
 * TODO
 */
void testLIC13isMet() {
  
}

/**
 * TODO
 */
void testLIC14isMet() {
  
}

/**
 * Calls all testing functions for the LICisMet-functions
 */
void testLICs() {
  testLIC0isMet();
  testLIC1isMet();
  testLIC2isMet();
  testLIC3isMet();
  testLIC4isMet();
  testLIC5isMet();
  testLIC6isMet();
  testLIC7isMet();
  testLIC8isMet();
  testLIC9isMet();
  testLIC10isMet();
  testLIC11isMet();
  testLIC12isMet();
  testLIC13isMet();
  testLIC14isMet();
}