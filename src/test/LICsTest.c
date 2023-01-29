#include "../decide.h"
#include <assert.h>

/**
 * Tests LIC0isMet using multiple different problem instances
 */
void testLIC0isMet() {
  // In the instance below, point 0 and 1 are sqrt(2) units apart
  NUMPOINTS = 3;
  X[0] = 1.0;
  Y[0] = 1.0;
  X[1] = 2.0;
  Y[1] = 2.0;
  X[2] = 10.0;
  Y[2] = 10.0;

  PARAMETERS.LENGTH1 = 2.0;
  boolean isMet = LIC0isMet(); // Should return true, since sqrt(2) is less than 2.0

  if(!isMet) {
    LOGE("LIC0isMet returned false when it should have been true");
  }


  PARAMETERS.LENGTH1 = 1.0;
  isMet = LIC0isMet(); // Should return false, since sqrt(2) is more than 1.0

  if(isMet) {
    LOGE("LIC0isMet returned true when it should have been false");
  }


  // Changing order of the points
  X[0] = 1.0;
  Y[0] = 1.0;
  X[1] = 10.0;
  Y[1] = 10.0;
  X[2] = 2.0;
  Y[2] = 2.0;

  PARAMETERS.LENGTH1 = 2.0;
  isMet = LIC0isMet(); // Should return false, since consecutive points are now far from each other

  if(isMet) {
    LOGE("LIC0isMet returned true when it should have been false");
  }

  // Changing order of the points, so that points 1 and 2 are now sqrt(2) units apart 
  X[0] = 10.0;
  Y[0] = 10.0;
  X[1] = 1.0;
  Y[1] = 1.0;
  X[2] = 2.0;
  Y[2] = 2.0;

  PARAMETERS.LENGTH1 = 2.0;
  isMet = LIC0isMet(); // Should return true, since sqrt(2) is less than 2

  if(!isMet) {
    LOGE("LIC0isMet returned false when it should have been true");
  }

  PARAMETERS.LENGTH1 = 1.0;
  isMet = LIC0isMet(); // Should return false, since sqrt(2) is more than 1

  if(isMet) {
    LOGE("LIC0isMet returned true when it should have been false");
  }

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
  /*
  testcase 1: angle < (PI - EPSILON)
    X = {1, 2, 3}
    Y = {1, 2, 1}
    EPSILON = 0.1
    result angle = 1.570796
  expected return: true
  */
  X[0] = 1;X[1] = 2;X[2] = 3;
  Y[0] = 1;Y[1] = 2;Y[2] = 1;
  PARAMETERS.EPSILON = 0.1;
  NUMPOINTS = 3;
  if(!LIC2isMet()) {
    LOGE("testLIC2isMet failed");
  }

  /*
  testcase 2: angle > (PI + EPSILON)
    X = {0, 1, 2}
    Y = {1, 0, 1}
    EPSILON = 0.1
    result angle = PI+PI/2
  expected return: true
  */
  X[0] = 0;X[1] = 1;X[2] = 2;
  Y[0] = 1;Y[1] = 0;Y[2] = 1;
  PARAMETERS.EPSILON = 0.1;
  NUMPOINTS = 3;
  if(!LIC2isMet()) {
    LOGE("testLIC2isMet failed");
  }
  /*
  testcase 3: angle between (PI - EPSILON) and (PI + EPSILON)
      X = {1, 2, 3}
      Y = {1, 2, 3}
      result angle = PI
  expected return: false
  */
  X[0] = 1;X[1] = 2;X[2] = 3;
  Y[0] = 1;Y[1] = 2;Y[2] = 3;
  PARAMETERS.EPSILON = 0.3;
  NUMPOINTS = 3;
  if(LIC2isMet()) {
    LOGE("testLIC2isMet failed");
  }

  /*
  testcase 4: either the first point or the last point (or both) coincides with the vertex
    X = {1, 1, 3}
    Y = {1, 1, 2}
  expected return: false
  */
  X[0] = 1;X[1] = 1;X[2] = 3;
  Y[0] = 1;Y[1] = 1;Y[2] = 2;
  PARAMETERS.EPSILON = 0.1;
  NUMPOINTS = 3;
  if(LIC2isMet()) {
    LOGE("testLIC2isMet failed");
  }

}

/**
 * TODO
 */
void testLIC3isMet() {
  
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
 * Tests the LIC7isMet function.
 */
void testLIC7isMet() {
  /*
  testcase 1: Invalid input.
  NUMPOINTS = 3
  KPTS = 0
  LENGTH1 = 0
  X[0] = 1.0;X[1] = 1.0;X[2] = 1.0;
  Y[0] = 1.0;Y[1] = 1.0;Y[2] = 1.0;
  Expected return: false
  */
  NUMPOINTS = 2;
  PARAMETERS.KPTS = 0;
  PARAMETERS.LENGTH1 = 0;
  X[0] = 1.0;X[1] = 1.0;X[2] = 1.0;
  Y[0] = 1.0;Y[1] = 1.0;Y[2] = 1.0;

  if(LIC7isMet()){
    LOGE("FAILURE: testLIC7isMet, testcase 1. Expected: false.");
  }

  /*
  testcase 2: Valid input and fullfills having point distance greater than the length, but invalid separation length.
  NUMPOINTS = 4
  KPTS = 2
  LENGTH1 = 1.5
  X[0] = 0.0;X[1] = 0.0;X[2] = 0.0;X[3] = 0.0;
  Y[0] = -1.0;Y[1] = 1.0;Y[2] = 1.0;Y[3] = 0.0;
  Distances (XY0,XY1), (XY0,XY2) are greater than LENGTH1, but not (XY0,XY3), which is 2 KPTS apart.
  Expected return: false
  */
  NUMPOINTS = 4;
  PARAMETERS.KPTS = 2;
  PARAMETERS.LENGTH1 = 1.5;
  X[0] = 0.0;X[1] = 0.0;X[2] = 0.0;X[3] = 0.0;
  Y[0] = -1.0;Y[1] = 1.0;Y[2] = 1.0;Y[3] = 0.0;

  if(LIC7isMet()){
    LOGE("FAILURE: testLIC7isMet, testcase 2. Expected: false.");
  }

  /*
  testcase 3: Valid input and fullfills having point distance greater than the length, valid separation length.
  NUMPOINTS = 4
  KPTS = 2
  LENGTH1 = 1.5
  X[0] = 0.0;X[1] = 0.0;X[2] = 0.0;X[3] = 0.0;
  Y[0] = -1.0;Y[1] = 0.0;Y[2] = 0.0;Y[3] = 1.0;
  Distances (0,1) and (0,2) are not greater than LENGTH1, but (0,3) is, which is 2 KPTS apart.
  Expected return: true
  */
  NUMPOINTS = 4;
  PARAMETERS.KPTS = 2;
  PARAMETERS.LENGTH1 = 1.5;
  X[0] = 0.0;X[1] = 0.0;X[2] = 0.0;X[3] = 0.0;
  Y[0] = -1.0;Y[1] = 0.0;Y[2] = 0.0;Y[3] = 1.0;

  if(!LIC7isMet()){
    LOGE("FAILURE: testLIC7isMet, testcase 3. Expected: true.");
  }
  
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