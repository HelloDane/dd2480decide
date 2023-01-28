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
  /*
  testcase 1: one distance greater than DIST
    X = {1, 2.5, 3, 3}
    Y = {1, 1, 3, 1}
    NUMPOINTS = 4
    NPTS = 4
    DIST = 0.8
  expected return: true
  */
  X[0] = 1; X[1] = 2.5; X[2] = 3; X[3] = 3;
  Y[0] = 1; Y[1] = 1; Y[2] = 3; Y[3] = 1;
  NUMPOINTS = 4;
  PARAMETERS.NPTS = 4;
  PARAMETERS.DIST = 0.8;
  if(!LIC5isMet()) {
    LOGE("testLIC5isMet failed");
  }
  /*
  testcase 2: all distance smaller than DIST
    X = {1, 2, 2.5, 5}
    Y = {1, 2, 1, 1}
    NUMPOINTS = 4
    NPTS = 4
    DIST = 3
  expected return: false
  */
  X[0] = 1; X[1] = 2; X[2] = 2.5; X[3] = 5;
  Y[0] = 1; Y[1] = 2; Y[2] = 1; Y[3] = 1;
  NUMPOINTS = 4;
  PARAMETERS.NPTS = 4;
  PARAMETERS.DIST = 3;
  if(LIC5isMet()) {
    LOGE("testLIC5isMet failed");
  }
  /*
  testcase 3: a case that first and last point are identical
    X = {0, 2, 0, 2}
    Y = {0, 0, 0, 0}
    NUMPOINTS = 4
    N_PTS = 3
    DIST = 1.5
  expected return: true
  */
  X[0] = 0; X[1] = 2; X[2] = 0; X[3] = 2;
  Y[0] = 0; Y[1] = 0; Y[2] = 0; Y[3] = 0;
  NUMPOINTS = 4;
  PARAMETERS.NPTS = 3;
  PARAMETERS.DIST = 1.5;
  if(!LIC5isMet()) {
    LOGE("testLIC5isMet failed");
  }
  /*
  testcase 4: NUMPOINTS < 3
    X = {0, 2, 0, 2}
    Y = {0, 0, 0, 0}
    NUMPOINTS = 2
    N_PTS = 3
    DIST = 1.5
  expected return: false
  */
  X[0] = 0; X[1] = 2; X[2] = 0; X[3] = 2;
  Y[0] = 0; Y[1] = 0; Y[2] = 0; Y[3] = 0;
  NUMPOINTS = 2;
  PARAMETERS.NPTS = 3;
  PARAMETERS.DIST = 1.5;
  if(LIC5isMet()) {
    LOGE("testLIC5isMet failed");
  }
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