#include "../decide.h"
#include <assert.h>

/**
 * Tests LIC0isMet using multiple different problem instances
 */
void testLIC0isMet() {
  // In the instance below, points 0 and 1 are 4 units apart,
  // points 1 and 2 are 5 units apart and
  NUMPOINTS = 3;
  X[0] = 1.0;
  Y[0] = 1.0;
  X[1] = 5.0;
  Y[1] = 1.0;
  X[2] = 10.0;
  Y[2] = 2.0;

  PARAMETERS.LENGTH1 = 4.0;
  boolean isMet = LIC0isMet(); // Should return true, 5 is greater than 4

  if(!isMet) {
    LOGE("LIC0isMet returned false when it should have been true");
  }


  PARAMETERS.LENGTH1 = 6.0;
  isMet = LIC0isMet(); // Should return false, since 5 is less than 6

  if(isMet) {
    LOGE("LIC0isMet returned true when it should have been false");
  }


  // Swap points 1 and 2 so that distances between consecutive points remain the same but point order is different
  // Makes sure order does not matter
  X[0] = 10.0;
  Y[0] = 2.0;
  X[1] = 5.0;
  Y[1] = 1.0;
  X[2] = 1.0;
  Y[2] = 1.0;

  PARAMETERS.LENGTH1 = 4.0;
  isMet = LIC0isMet(); // Should return true sice 5 > 4

  if(!isMet) {
    LOGE("LIC0isMet returned false when it should have been true");
  }


  PARAMETERS.LENGTH1 = 6.0;
  isMet = LIC0isMet(); // Should return false, since 5 < 6

  if(isMet) {
    LOGE("LIC0isMet returned true when it should have been false");
  }

  // Make sure invalid length input returns false
  PARAMETERS.LENGTH1 = -1.0;
  isMet = LIC0isMet(); // Should return false, since LENGTH1 needs to be >= 0

  if(isMet) {
    LOGE("LIC0isMet returned true when it should have been false");
  }

}

/**
 * Tests LIC1isMet using multiple different problem instances
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
 * Tests LIC2isMet using multiple different problem instances
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
 * Tests LIC3isMet using multiple different problem instances
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
 * Tests LIC4isMet using multiple different problem instances
 */
void testLIC4isMet() {
  /*
  testcase 1: PARAMETERS.QPTS > NUMPOINTS
    Parameters are invalid.
  expected return: false
  */
  NUMPOINTS = 3;
  PARAMETERS.QPTS = 4;
  PARAMETERS.QUADS = 1;
  X[0] = 0;X[1] = 0;X[2] = -1;
  Y[0] = 0;Y[1] = -1;Y[2] = 0;
  if (LIC4isMet()) {
    LOGE("FAILURE, testcase 1. Expected: false.");
  }

  /*
  testcase 2: Consecutive datapoints lie in more than QUADS quadrants.
    QUADS = 3. Four datapoints, one in each quadrant.
      X[0] = 1;X[1] = 1;X[2] = -1; X[3] = -1;
      Y[0] = 1;Y[1] = -1;Y[2] = 1; Y[3] = -1;
  expected return: true
  */
  NUMPOINTS = 4;
  PARAMETERS.QPTS = 4;
  PARAMETERS.QUADS = 3;
  X[0] = 1;X[1] = 1;X[2] = -1; X[3] = -1;
  Y[0] = 1;Y[1] = -1;Y[2] = 1; Y[3] = -1;
  if (!LIC4isMet()) {
    LOGE("FAILURE, testcase 2. Expected: true.");
  }

  /*
  testcase 3: Datapoints lie in more than QUADS quadrants, but not in a consecutive set.
    QUADS = 3. QPTS = 4. Eight datapoints, no valid consecutive set of size QPTS.
      X[0] = 1; X[5] = 1;X[6] = -1; X[7] = -1;
      Y[0] = 1; Y[5] = -1;Y[6] = 1; Y[7] = -1;

      X[1] = 1;X[2] = 1; X[3] = 1; X[4] = 1;
      Y[1] = -1;Y[2] = -1; Y[3] = -1; Y[4] = -1;
  expected return: false
  */
  NUMPOINTS = 8;
  PARAMETERS.QPTS = 4;
  PARAMETERS.QUADS = 3;
  X[0] = 1; X[5] = 1;X[6] = -1; X[7] = -1;
  Y[0] = 1; Y[5] = -1;Y[6] = 1; Y[7] = -1;

  X[1] = 1;X[2] = 1; X[3] = 1; X[4] = 1;
  Y[1] = -1;Y[2] = -1; Y[3] = -1; Y[4] = -1;


  if (LIC4isMet()) {
    LOGE("FAILURE, testcase 3. Expected: false.");
  }

    /*
  testcase 4: Data point quadrants are prioritized correctly.
    QUADS = 2. QPTS = 3. Three datapoints, one of which is on origo.
      X[0] = 0; X[1] = 1;X[2] = -1;
      Y[0] = 0; Y[1] = -1;Y[2] = 1;
    expected return: true
    */
  NUMPOINTS = 3;
  PARAMETERS.QPTS = 3;
  PARAMETERS.QUADS = 2;
  X[0] = 0; X[1] = 1;X[2] = -1;
  Y[0] = 0; Y[1] = -1;Y[2] = 1;


  if (!LIC4isMet()) {
    LOGE("FAILURE, testcase 4. Expected: true.");
  }
}

/**
 * Tests LIC5isMet using multiple different problem instances
 */
void testLIC5isMet() {
  /*
  testcase 1: X[i+1] - X[i] < 0
    X = {1, 0}
    Y = {1, 1}
    NUMPOINTS = 2
  expected return: true
  */
  X[0] = 1; X[1] = 0;
  Y[0] = 1; Y[1] = 1;
  NUMPOINTS = 2;

  if(!LIC5isMet()) {
    LOGE("FAILURE, testcase 1. Expected: true.");
  }
  /*
  testcase 2: X[i+1] - X[i] > 0
    X = {0, 1}
    Y = {1, 1}
    NUMPOINTS = 2
  expected return: false
  */
  X[0] = 0; X[1] = 1;
  Y[0] = 1; Y[1] = 1;
  NUMPOINTS = 2;
  if(LIC5isMet()) {
    LOGE("FAILURE, testcase 2. Expected: false.");
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
 * Tests LIC8isMet using multiple different problem instances
 */
void testLIC8isMet() {
  /*
  testcase 1: can be contained within or on a circle of radius RADIUS1
    X = {1, 0, 2, 0, 3}
    Y = {1, 0, 2, 0, 1}
  expected return: false
  */
  X[0]=1;X[1]=0;X[2]=2;X[3]=0;X[4]=3;
  Y[0]=1;Y[1]=0;Y[2]=2;Y[3]=0;Y[4]=1;
  PARAMETERS.RADIUS1 = 1;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 1;
  NUMPOINTS = 5;
  if(LIC8isMet()) {
    LOGE("testLIC8isMet failed");
  }
  /*
  testcase 2: can not be contained
    X = {0, 0, 2, 0, 0, -3}
    Y = {0, 0, 2, 0, 0, -1}
  expected return: true
  */
  X[0]=0;X[1]=0;X[2]=-2;X[3]=0;X[4]=0;X[5]=-2;
  Y[0]=0;Y[1]=0;Y[2]=0;Y[3]=0;Y[4]=0;Y[5]=-1;
  PARAMETERS.RADIUS1 = 1;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 2;
  NUMPOINTS = 6;
  if(!LIC8isMet()) {
    LOGE("testLIC8isMet failed");
  }
  /*
  testcase 3: three points on a line
    X = {1, 0, -3, 0, 0, 3}
    Y = {1, 0, -3, 0, 0, 3}
  expected return: false
  */
  X[0]=1;X[1]=0;X[2]=-3;X[3]=0;X[4]=0;X[5]=3;
  Y[0]=1;Y[1]=0;Y[2]=-3;Y[3]=0;Y[4]=0;Y[5]=3;
  PARAMETERS.RADIUS1 = 9;
  PARAMETERS.APTS = 1;
  PARAMETERS.BPTS = 2;
  NUMPOINTS = 6;
  if(LIC8isMet()) {
    LOGE("testLIC8isMet failed");
  }

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
 * Tests LIC11isMet using multiple different problem instances
 */
void testLIC11isMet() {
  /*
  testcase 1:
    X = {1, 1, 3}
    Y = {1, 1, 2}
  expected return: true
  */
  X[0] = 1;X[1] = 1;X[2] = 3;
  Y[0] = 1;Y[1] = 1;Y[2] = 2;
  PARAMETERS.GPTS = 1;
  NUMPOINTS = 3;
  if(!LIC11isMet()) {
    LOGE("testLIC11isMet failed");
  }
  /*
  testcase 2:
    X = {3, 1, 1}
    Y = {-1, 11, 2}
  expected return: false
  */
  X[0] = 3.222;X[1] = 1;X[2] = 1;X[3] = -2; X[4] = -4.8;
  Y[0] = -1;Y[1] = 11;Y[2] = 2;Y[3] = -5;Y[4] = 3;
  PARAMETERS.GPTS = 1;
  NUMPOINTS = 5;
  if(LIC11isMet()) {
    LOGE("testLIC11isMet failed");
  }
  /*
  testcase 3: NUMPOINTS < 3
    X = {3, 1, 1}
    Y = {-1, 11, 2}
  expected return: false
  */
  X[0] = 3.222;X[1] = 1;X[2] = 1;X[3] = -2; X[4] = -4.8;
  Y[0] = -1;Y[1] = 11;Y[2] = 2;Y[3] = -5;Y[4] = 3;
  PARAMETERS.GPTS = 1;
  NUMPOINTS = 1;
  if(LIC11isMet()) {
    LOGE("testLIC11isMet failed");
  }

}

/**
 * TODO
 */
void testLIC12isMet() {

  // Lets have 8 points.
  // Points 0-3 fulfills first critera while points 4-7 fulfills second critera
  // This means points 1 and 2 need to be further than PARAMETERS.LENGTH1 apart
  // and points 5 and 6 need to be closer than PARAMETERS.LENGTH2 apart
  // Lets space out all other points so that only points 5 and 6 can fulfill the second critera
  // to make sure that fulfillment is not caused by some other points
  // All points are placed 4 units apart, except for 5 and 6, which are placed 2 units apart
  PARAMETERS.KPTS = 2;
  NUMPOINTS = 8;
  X[0] = 0;
  Y[0] = 0;

  X[1] = 4;
  Y[1] = 0;

  X[2] = 8;
  Y[2] = 0;

  X[3] = 12;
  Y[3] = 0;

  X[4] = 16;
  Y[4] = 0;

  X[5] = 20;
  Y[5] = 0;

  X[6] = 22;
  Y[6] = 0;

  X[7] = 26;
  Y[7] = 0;

  PARAMETERS.LENGTH1 = 3;
  PARAMETERS.LENGTH2 = 3;
  // LIC12 should now be met since 2 and 3 are 4 units apart which is > 3
  // and 5 and 6 are 2 units apart which is < 3, no other points are less than 3 apart
  boolean isMet = LIC12isMet();
  if(!isMet) {
    LOGE("LIC12isMet returned false when it should have returned true");
  }

  PARAMETERS.LENGTH1 = 3;
  PARAMETERS.LENGTH2 = 1.8;
  // LIC12 should now NOT be met since 2 and 3 are 4 units apart which is > 3
  // BUT 5 and 6 are 2 units apart which is not < 1.8
  isMet = LIC12isMet();
  if(isMet) {
    LOGE("LIC12isMet returned true when it should have returned false");
  }

  PARAMETERS.LENGTH1 = 5;
  PARAMETERS.LENGTH2 = 3;
  // LIC12 should now NOT be met since 2 and 3 are 4 units apart which is not > 5 (no 2 consecutive points are 5 units apart)
  isMet = LIC12isMet();
  if(isMet) {
    LOGE("LIC12isMet returned true when it should have returned false");
  }
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
 * Tests LIC14isMet using multiple different problem instances
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
