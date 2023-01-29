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
    /*
  testcase 1: Numpoints < 3 and points are within RADIUS1
  Three points are needed to be able to return true.
  Expected return: false
  */
  NUMPOINTS = 2;
  PARAMETERS.RADIUS1 = 5;
  X[0] = 1.0;
  Y[0] = 1.0;
  X[1] = 2.0;
  Y[1] = 2.0;
  if(LIC1isMet()){
    LOGE("FAILURE: testLIC1isMet, testcase 1. Expected: false.");
  }

  /*
  testcase 2: Numpoints >= 3 and points are within a RADIUS1 circle
  Points (1,1), (2,2), (4,4) can fit in a circle with radius 2.15.
  Longest distance is between (1,1) and (4,4) (~= 4.242 < 2.15*2 = 4.3)
  Expected return: false
  */
  NUMPOINTS = 3;
  PARAMETERS.RADIUS1 = 2.15;
  X[0] = 1.0;
  Y[0] = 1.0;
  X[1] = 1.0;
  Y[1] = 2.0;
  X[2] = 4.0;
  Y[2] = 4.0;

  if(LIC1isMet()){
    LOGE("FAILURE: testLIC1isMet, testcase 2. Expected: false.");
  }

    /*
  testcase 3: Numpoints >= 3 and points are within a RADIUS1 circle
  Points (1,1), (5,4), (2,2) cannot fit in a circle with radius 2.15.
  Longest distance is between (1,1) and (5,4) (~= 4.89 > 2.15*2 = 4.3)
  Expected return: true
  */
  NUMPOINTS = 3;
  PARAMETERS.RADIUS1 = 2.15;
  X[0] = 1.0;
  Y[0] = 1.0;
  X[1] = 5.0;
  Y[1] = 4.0;
  X[2] = 2.0;
  Y[2] = 2.0;

  if(!LIC1isMet()){
    LOGE("FAILURE: testLIC1isMet, testcase 3. Expected: true.");
  }

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
 * Tests the LIC6isMet-function.
 */
void testLIC6isMet() {
  // The distance from point 1 is sqrt(2) units from the line between points 0 and 2.
  NUMPOINTS = 3;
  PARAMETERS.NPTS = 3;
  X[0] = 1;
  Y[0] = 3;
  X[1] = 3;
  Y[1] = 3;
  X[2] = 3;
  Y[2] = 1;

  PARAMETERS.DIST = 2;
  boolean isMet = LIC6isMet(); // Should be false
  if(isMet) {
    LOGE("LIC6isMet returned true when it should have returned false");
  }

  PARAMETERS.DIST = 1;
  isMet = LIC6isMet(); // Should be true
  if(!isMet) {
    LOGE("LIC6isMet returned false when it should have returned true");
  }
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
 * Tests the LIC9isMet-function
 */
void testLIC9isMet() {
  // In the situation below, the saught after angle is 90 degrees = PI/2 radians
  PARAMETERS.CPTS = 2;
  PARAMETERS.DPTS = 3;
  NUMPOINTS = 8;
  X[0] = 1;
  Y[0] = 1;
  X[3] = 2;
  Y[3] = 1;
  X[7] = 2;
  Y[7] = 2;

  PARAMETERS.EPSILON = PI/3; // Should return true since PI/2 < PI - PI/3
  boolean isMet = LIC9isMet();
  if(!isMet) {
    LOGE("LIC9isMet returned false when it should have returned true");
  }

  PARAMETERS.EPSILON = -(PI/2 + PI/6); // Should return true since PI/2 > PI + (-(PI/2 + PI/6))
  isMet = LIC9isMet();
  if(!isMet) {
    LOGE("LIC9isMet returned false when it should have returned true");
  }

  PARAMETERS.EPSILON = PI/2 + PI/6; // Should return false since PI/2 > PI - (PI/2 + PI/6) and PI/2 < PI + (PI/2 + PI/6)
  isMet = LIC9isMet();
  if(isMet) {
    LOGE("LIC9isMet returned true when it should have returned false");
  }
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
 * Tests for LIC13 function
 */
void testLIC13isMet() {
  /*
  testcase 1: Invalid input, (NUMPOINTS - PARAMETERS.APTS - PARAMETERS.BPTS - 3) < 0
    NUMPOINTS = 5;
    PARAMETERS.RADIUS1 = 5;
    PARAMETERS.RADIUS2 = 3;
    PARAMETERS.APTS = 1;
    PARAMETERS.BPTS = 2;
    X[0] = 1.0;X[1] = 2.0;X[2] = 3.0;X[3] = 4.0;X[4] = 5.0;
    Y[0] = 1.0;Y[1] = 2.0;Y[2] = 3.0;Y[3] = 4.0;Y[4] = 5.0;
  Expected return: false
  */
  NUMPOINTS = 5;
  PARAMETERS.RADIUS1 = 5;
  PARAMETERS.RADIUS2 = 3;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 2;
  X[0] = 1.0;X[1] = 2.0;X[2] = 3.0;X[3] = 4.0;X[4] = 5.0;
  Y[0] = 1.0;Y[1] = 2.0;Y[2] = 3.0;Y[3] = 4.0;Y[4] = 5.0;
  if(LIC13isMet()){
    LOGE("FAILURE: testcase 1. Expected: false.");
  }

  /*
  testcase 2: Valid input parameters and points are outside a RADIUS1 circle and inside a RADIUS2 circle
    NUMPOINTS = 5;
    PARAMETERS.RADIUS1 = 2.1;
    PARAMETERS.RADIUS2 = 2.15;
    PARAMETERS.APTS = 1;
    PARAMETERS.BPTS = 1;
    X[0] = 1.0;X[1] = 2.0;X[2] = 2;X[3] = 1;X[4] = 4;
    Y[0] = 1.0;Y[1] = 2.0;Y[2] = 2;Y[3] = 1;Y[4] = 4;
    Coordinates (1,1), (2,2), (4,4) can fit in a circle with radius 2.15, but not 2.1.
    Longest distance is between (1,1) and (4,4) (~= 4.242 < 2.15*2 = 4.3)
  Expected return: true
  */
  NUMPOINTS = 5;
  PARAMETERS.RADIUS1 = 2.1;
  PARAMETERS.RADIUS2 = 2.15;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 1;
  X[0] = 1.0;X[1] = 2.0;X[2] = 2;X[3] = 1;X[4] = 4;
  Y[0] = 1.0;Y[1] = 2.0;Y[2] = 2;Y[3] = 1;Y[4] = 4;

  if(!LIC13isMet()){
    LOGE("FAILURE: testcase 2. Expected: true.");
  }

  /*
  testcase 3: Valid input parameters. RADIUS1 requirement fullfilled, but not RADIUS2.
    NUMPOINTS = 5;
    PARAMETERS.RADIUS1 = 2.1;
    PARAMETERS.RADIUS2 = 2.1;
    PARAMETERS.APTS = 1;
    PARAMETERS.BPTS = 1;
    X[0] = 1.0;X[1] = 2.0;X[2] = 2;X[3] = 1;X[4] = 4;
    Y[0] = 1.0;Y[1] = 2.0;Y[2] = 2;Y[3] = 1;Y[4] = 4;
    Coordinates (1,1), (2,2), (4,4) can fit in a circle with radius 2.15, but not 2.1.
    Longest distance is between (1,1) and (4,4) (~= 4.242 < 2.15*2 = 4.3)
  Expected return: false
  */
  NUMPOINTS = 5;
  PARAMETERS.RADIUS1 = 2.1;
  PARAMETERS.RADIUS2 = 2.1;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 1;
  X[0] = 1.0;X[1] = 2.0;X[2] = 2;X[3] = 1;X[4] = 4;
  Y[0] = 1.0;Y[1] = 2.0;Y[2] = 2;Y[3] = 1;Y[4] = 4;

  if(LIC13isMet()){
    LOGE("FAILURE: testcase 3. Expected: false.");
  }

  /*
  testcase 4: Valid input parameters. RADIUS2 requirement fullfilled, but not RADIUS1.
    NUMPOINTS = 5;
    PARAMETERS.RADIUS1 = 2.15;
    PARAMETERS.RADIUS2 = 2.15;
    PARAMETERS.APTS = 1;
    PARAMETERS.BPTS = 1;
    X[0] = 1.0;X[1] = 2.0;X[2] = 2;X[3] = 1;X[4] = 4;
    Y[0] = 1.0;Y[1] = 2.0;Y[2] = 2;Y[3] = 1;Y[4] = 4;
    Coordinates (1,1), (2,2), (4,4) can fit in a circle with radius 2.15, but not 2.1.
    Longest distance is between (1,1) and (4,4) (~= 4.242 < 2.15*2 = 4.3)
  Expected return: false
  */
  NUMPOINTS = 5;
  PARAMETERS.RADIUS1 = 2.15;
  PARAMETERS.RADIUS2 = 2.15;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 1;
  X[0] = 1.0;X[1] = 2.0;X[2] = 2;X[3] = 1;X[4] = 4;
  Y[0] = 1.0;Y[1] = 2.0;Y[2] = 2;Y[3] = 1;Y[4] = 4;

  if(LIC13isMet()){
    LOGE("FAILURE: testcase 4. Expected: false.");
  }

}

/**
 * TODO
 */
void testLIC14isMet() {
  /*
  testcase 1: area smaller than AREA1
      X = {1, 1, 3, 1, 3}
      Y = {1, 1, 2, 1, -5}
      
  expected return: false
  */
  X[0] = 1;X[1] = 1;X[2] = 3;X[3] = 1;X[4] = 3;
  Y[0] = 1;Y[1] = 1;Y[2] = 2;Y[3] = 1;Y[4] = -5;
  PARAMETERS.AREA1 = 7.44;
  PARAMETERS.AREA2 = 10.3;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 1;
  NUMPOINTS = 5;
  if(LIC14isMet()) {
    LOGE("testLIC14isMet failed");
  }
  /*
  testcase 2: area greater than AREA2
      X = {1, 1, 3, 1, 8}
      Y = {1, 1, 2, 1, -5}
      
  expected return: false
  */
  X[0] = 1;X[1] = 1;X[2] = 3;X[3] = 1;X[4] = 8;
  Y[0] = 1;Y[1] = 1;Y[2] = 2;Y[3] = 1;Y[4] = -5;
  PARAMETERS.AREA1 = 6.44;
  PARAMETERS.AREA2 = 9.1;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 1;
  NUMPOINTS = 5;
  if(LIC14isMet()) {
    LOGE("testLIC14isMet failed");
  }
  /*
  testcase 3: area between AREA1 and AREA2
      X = {1, 1, 3, 1, 8}
      Y = {1, 1, 2, 1, -5}
      
  expected return: true
  */
  X[0] = 1;X[1] = 1;X[2] = 3;X[3] = 1;X[4] = 3;
  Y[0] = 1;Y[1] = 1;Y[2] = 2;Y[3] = 1;Y[4] = -5;
  PARAMETERS.AREA1 = 6.44;
  PARAMETERS.AREA2 = 9.1;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 1;
  NUMPOINTS = 5;
  if(!LIC14isMet()) {
    LOGE("testLIC14isMet failed");
  }
  /*
  testcase 4: NUMPOINT < 5
    NUMPOINT = 2
  expected return: false
  */
  X[0] = 1;X[1] = 1;
  Y[0] = 1;Y[1] = 1;
  PARAMETERS.AREA1 = 6.44;
  PARAMETERS.AREA2 = 9.1;
  PARAMETERS.EPTS = 1;
  PARAMETERS.FPTS = 1;
  NUMPOINTS = 2;
  if(LIC14isMet()) {
    LOGE("testLIC14isMet failed");
  }
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