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
 * Test cases for LIC10isMet function
 */
void testLIC10isMet() {
  /*
  testcase 1: Invalid input parameters but valid triangle area.
    NUMPOINTS = 4
    EPTS = 1
    FPTS = 0
    AREA1 = 0
    X[0] = 0;X[1] = 0;X[2] = -1;X[3] = 1;
    Y[0] = 0;Y[1] = -1;Y[2] = 0;Y[3] = 1;
  expected return: false
  */
  NUMPOINTS = 4;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 0;
  PARAMETERS.AREA1 = 0;
  X[0] = 0;X[1] = 0;X[2] = -1;X[3] = 1;
  Y[0] = 0;Y[1] = -1;Y[2] = 0;Y[3] = 1;
  if (LIC10isMet()) {
    LOGE("FAILURE, testcase 1. Expected: false.");
  }

  /*
  testcase 2: Valid triangle according to requirements.
    NUMPOINTS = 5
    EPTS = 1
    FPTS = 1
    AREA1 = 0.49
    X[0] = 0;X[1] = -1;X[2] = 0;X[3] = 1; X[4] = 1;
    Y[0] = 0;Y[1] = -1;Y[2] = 1;Y[3] = 1; Y[4] = 0;
    |(0 * (0 - 1) + -1 * (1 - 0) + 1 * (0-0))/2| = 0.5
  expected return: true
  */
  NUMPOINTS = 5;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 1;
  PARAMETERS.AREA1 = 0.49;
  X[0] = 0;X[1] = -1;X[2] = 0;X[3] = 1; X[4] = 1;
  Y[0] = 0;Y[1] = -1;Y[2] = 1;Y[3] = 1; Y[4] = 0;
  if (!LIC10isMet()) {
    LOGE("FAILURE, testcase 2. Expected: true.");
  }

  /*
  testcase 3: No valid triangle greater than area.
    NUMPOINTS = 5
    EPTS = 1
    FPTS = 1
    AREA1 = 0.5
    X[0] = 0;X[1] = -1;X[2] = 0;X[3] = 1; X[4] = 1;
    Y[0] = 0;Y[1] = -1;Y[2] = 1;Y[3] = 1; Y[4] = 0;
    |(0 * (0 - 1) + -1 * (1 - 0) + 1 * (0-0))/2| = 0.5
  expected return: false
  */
  NUMPOINTS = 5;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 1;
  PARAMETERS.AREA1 = 0.5;
  X[0] = 0;X[1] = -1;X[2] = 0;X[3] = 1; X[4] = 1;
  Y[0] = 0;Y[1] = -1;Y[2] = 1;Y[3] = 1; Y[4] = 0;
  if (LIC10isMet()) {
    LOGE("FAILURE, testcase 3. Expected: false.");
  }
  
  /*
  testcase 4: Points which can make a big enough triangle exist, but no such points are found with the specified separation.
    NUMPOINTS = 6
    EPTS = 1
    FPTS = 2
    AREA1 = 1
    X[0] = 0;X[1] = -10;X[2] = 0;X[3] = 1; X[4] = 10;  X[5] = 1;
    Y[0] = 0;Y[1] = -10;Y[2] = 1;Y[3] = 1; Y[4] = 0; Y[5] = 0;
    Using any of the points XY[2] or XY[4] is required to get a big enough area.
  expected return: false
  */
  NUMPOINTS = 6;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 2;
  PARAMETERS.AREA1 = 1;
  X[0] = 0;X[1] = -10;X[2] = 0;X[3] = 1; X[4] = 10;  X[5] = 1;
  Y[0] = 0;Y[1] = -10;Y[2] = 1;Y[3] = 1; Y[4] = 0; Y[5] = 0;
  if (LIC10isMet()) {
    LOGE("FAILURE, testcase 4. Expected: false.");
  }
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