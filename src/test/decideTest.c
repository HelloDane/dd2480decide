#include "../decide.h"

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
 * 
 */
void calculateFUVTest() {

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



