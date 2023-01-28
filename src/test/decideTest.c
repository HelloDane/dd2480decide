#include "../decide.h"
#include <time.h>
#include <stdlib.h>

/**
 * Tests the DECIDE-function with input paramaters that should result in a launch
 * 
 */
void decideTestPositive() {
  
}

/**
 * Tests the DECIDE-function with input paramaters that should result in not launching
 * 
 */
void decideTestNegative() {

}

/**
 * Tests the DECIDE-function with invalid input parameters
 * 
 */
void decideTestInvalid() {

}

/**
 * Tests the calculateCMV-function
 * 
 */
void calculateCMVTest() {
  
}

/**
 * Tests the calculatePUM-function
 * 
 */
void calculatePUMTest() {

}

/**
 * Tests the calculateFUV-function
 * First test is to make sure LAUNCH is set to true if all values of FUV are set to true.
 * Second test makes sure any one FUV index set to false results in LAUNCH being set to false.
 * Third test randomly sets a random number of indexes of FUV to false (could set 0 of them), and makes sure LAUNCH is set accordingly.
 */
void calculateFUVTest() {
  for(int i = 0; i < 15; i ++) {
    FUV[i] = 1;
  }

  decideLaunch();

  if(!LAUNCH) {
    LOGE("LAUNCH was set to false by decideLaunch() when it should have been set to true");
  }

  // Test each individual FUV index, and make sure setting it to false while the rest are true results in not launching
  for(int i = 0; i < 15; i ++) {
    FUV[i] = 0;
    decideLaunch();
    if(LAUNCH) {
      LOGE("LAUNCH was set to true by decideLaunch() when it should have been set to false");
    }
    FUV[i] = 1;
  }

  // Randomly set some FUV indexes to false
  srand(time(NULL));
  for(int i = 0; i < 100; i ++) {
    // Make sure all are set to true before the test
    for(int i = 0; i < 15; i ++) {
      FUV[i] = 1;
    }

    double chanceToSetToFalse = rand() % 101; // Random int from 0 to 100 (inclusive, represents percentage). 
    boolean hasSetAtLeastOneToFalse = 0;

    for(int i = 0; i < 15; i ++) {
      boolean setFalse = (rand() % 101) < chanceToSetToFalse;
      if(setFalse) {
        FUV[i] = 0;
        hasSetAtLeastOneToFalse = 1;
      }
    }

    decideLaunch();

    if(hasSetAtLeastOneToFalse && LAUNCH) {
      LOGE("LAUNCH was set to true by decideLaunch() when it should have been set to false");
    }

    if(!hasSetAtLeastOneToFalse && !LAUNCH) {
      LOGE("LAUNCH was set to false by decideLaunch() when it should have been set to true");
    }
  }
}

/**
 * Tests the decideLaunch-function
 * 
 */
void decideLaunchTest() {

}

/**
 * Tests the DECIDE function with different inputs.
 * One test is with input that should cause a launch.
 * One test is with input that should not cause a launch.
 * One test is with invalid input.
 * 
 */
void decideTest() {
  decideTestPositive();
  decideTestNegative();
  decideTestInvalid();
}

/**
 * Runs all tests
 * 
 */
void testAll() {
  decideTest();
  calculateCMVTest();
  calculatePUMTest();
  calculateFUVTest();
  decideLaunchTest();
  testLICs();
}



