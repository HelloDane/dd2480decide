#include "../decide.h"
#include <stdbool.h>
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



