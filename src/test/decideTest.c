#include "../decide.h"
#include <stdbool.h>
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
  /*Testcase1: the testcase in assignment document */
  CMV[0] = false;
  CMV[1] = true;
  CMV[2] = true;
  CMV[3] = true;
  CMV[4] = false;
  // ... CMV 5 to 13 unspecified
  CMV[14] = false;
  LCM[0][0]=ANDD;LCM[0][1]=ANDD;LCM[0][2]=ORR;LCM[0][3]=ANDD;LCM[0][4]=NOTUSED;LCM[0][14]=NOTUSED;
  LCM[1][0]=ANDD;LCM[1][1]=ANDD;LCM[1][2]=ORR;LCM[1][3]=ORR;LCM[1][4]=NOTUSED;LCM[1][14]=NOTUSED;
  LCM[2][0]=ORR;LCM[2][1]=ORR;LCM[2][2]=ANDD;LCM[2][3]=ANDD;LCM[2][4]=NOTUSED;LCM[2][14]=NOTUSED;
  LCM[3][0]=ANDD;LCM[3][1]=ORR;LCM[3][2]=ANDD;LCM[3][3]=ANDD;LCM[3][4]=NOTUSED;LCM[3][14]=NOTUSED;
  LCM[4][0]=NOTUSED;LCM[4][1]=NOTUSED;LCM[4][2]=NOTUSED;LCM[4][3]=NOTUSED;LCM[4][4]=NOTUSED;LCM[4][14]=NOTUSED;
  //...
  LCM[14][0]=NOTUSED;LCM[14][1]=NOTUSED;LCM[14][2]=NOTUSED;LCM[14][3]=NOTUSED;LCM[14][4]=NOTUSED;LCM[14][14]=NOTUSED;
  
  calculatePUM();
  
  if(PUM[0][1]==false&&PUM[0][2]==true&&PUM[0][3]==false&&PUM[0][4]==true&&PUM[0][14]==true
    &&PUM[1][0]==false&&PUM[1][2]==true&&PUM[1][3]==true&&PUM[1][4]==true&&PUM[1][14]==true
    &&PUM[2][0]==true&&PUM[2][1]==true&&PUM[2][3]==true&&PUM[2][4]==true&&PUM[2][14]==true
    &&PUM[3][0]==false&&PUM[3][1]==true&&PUM[3][2]==true&&PUM[3][4]==true&&PUM[3][14]==true
    &&PUM[4][0]==true&&PUM[4][1]==true&&PUM[4][2]==true&&PUM[4][3]==true&&PUM[4][14]==true
    &&PUM[14][0]==true&&PUM[14][1]==true&&PUM[14][2]==true&&PUM[14][3]==true&&PUM[14][4]==true&&PUM[14][14]==true)
  {
    //correct
      //printf("PUMTestcase1 result correct\n");
  }
  else {
    LOGE("PUMTestcase1 failed");
  }

  //printPUM();

}

/**
 * Tests the calculateFUV-function
 * 
 * 
 */
void calculateFUVTest() {
  /*
  testcase 1: All elements in PUM false. All elements in PUV true.
  If all PUV elements are true, none of the FUV elements will be set to true.
  If all PUM elements are false, none of the FUV elements will be set to true.
  Expected result: All FUV elements will be false.
  */
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      PUM[i][j] = false;
    }
    PUV[i] = true;
  }
  calculateFUV();
  for(int i = 0; i < 15; i++){
    if(FUV[i]){
      LOGE("FAILURE: testcase 1. All FUV elements should be false.");
      break;
    }
  }

  /*
  testcase 2: All elements in PUM true. All elements in PUV true.
  If all PUV elements are true, none of the FUV elements will be set to true.
  If all PUM elements are true, all of the FUV elements will be set to true.
  Expected result: All FUV elements will be true.
  */
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      PUM[i][j] = true;
    }
    PUV[i] = true;
  }
  calculateFUV();
  for(int i = 0; i < 15; i++){
    if(!FUV[i]){
      LOGE("FAILURE: testcase 2. All FUV elements should be true.");
      break;
    }
  }

  /*
  testcase 3: All elements in PUM true. All elements in PUV true.
  If all PUV elements are true, none of the FUV elements will be set to true.
  If all PUM elements are true, all of the FUV elements will be set to true.
  Expected result: All FUV elements will be true.
  */
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      PUM[i][j] = true;
    }
    PUV[i] = true;
  }
  calculateFUV();
  for(int i = 0; i < 15; i++){
    if(!FUV[i]){
      LOGE("FAILURE: testcase 3. All FUV elements should be true.");
      break;
    }
  }

  /*
  testcase 4: All elements in PUM false. All elements in PUV false.
  If all PUV elements are false, all of the FUV elements will be set to true.
  If all PUM elements are false, none of the FUV elements will be set to true.
  Expected result: All FUV elements will be true.
  */
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      PUM[i][j] = false;
    }
    PUV[i] = false;
  }
  calculateFUV();
  for(int i = 0; i < 15; i++){
    if(!FUV[i]){
      LOGE("FAILURE: testcase 4. All FUV elements should be true.");
      break;
    }
  }

}

/**
 * Tests the decideLaunch-function
 * First test is to make sure LAUNCH is set to true if all values of FUV are set to true.
 * Second test makes sure any one FUV index set to false results in LAUNCH being set to false.
 * Third test randomly sets a random number of indexes of FUV to false (could set 0 of them), and makes sure LAUNCH is set accordingly.
 */
void decideLaunchTest() {
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



