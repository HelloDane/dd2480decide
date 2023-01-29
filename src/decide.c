#include "decide.h"
#include <stdio.h>
#include <stdbool.h>

PARAMETERS_T PARAMETERS;
int NUMPOINTS = 100;
double X[100];
double Y[100];
boolean FUV[15];
boolean PUV[15];
boolean CMV[15];
boolean PUM[15][15];
CONNECTORS LCM[15][15];
boolean LAUNCH;

/**
 * Calculates the entire global CMV array
 * 
 */
void calculateCMV() {
  CMV[0] = LIC0isMet();
  CMV[1] = LIC1isMet();
  CMV[2] = LIC2isMet();
  CMV[3] = LIC3isMet();
  CMV[4] = LIC4isMet();
  CMV[5] = LIC5isMet();
  CMV[6] = LIC6isMet();
  CMV[7] = LIC7isMet();
  CMV[8] = LIC8isMet();
  CMV[9] = LIC9isMet();
  CMV[10] = LIC10isMet();
  CMV[11] = LIC11isMet();
  CMV[12] = LIC12isMet();
  CMV[13] = LIC13isMet();
  CMV[14] = LIC14isMet();
}

/**
 * Calculate and fill the global PUM array
 * 
 */
void calculatePUM() {
  for(int i = 0; i <= 14; i++) {
    for(int j = 0; j <= 14; j++) {
      if(LCM[i][j] == NOTUSED) { //If LCM[i,j] is NOTUSED, then PUM[i,j] should be set to true.
        PUM[i][j] = true;
      }
      else if(LCM[i][j] == ANDD) {//If LCM[i,j] is ANDD, PUM[i,j] should be set to true only if (CMV[i] AND CMV[j]) is true.
        if(CMV[i] == true && CMV[j] == true) {
          PUM[i][j] = true;
        }
        else {
          PUM[i][j] = false;
        }
      }
      else if (LCM[i][j] == ORR) { // If LCM[i,j] is ORR, PUM[i,j] should be set to true if (CMV[i] OR CMV[j]) is true.
        if(CMV[i] == true || CMV[j] == true) {
          PUM[i][j] = true;
        }
        else {
          PUM[i][j] = false;
        }
      }
      // (Note that the LCM is symmetric, i.e. LCM[i,j]=LCM[j,i] for all i and j.)
    }
  }
  //printPUM();
}

/**
 * Calculate and fill the global FUV array
 * 
 */
void calculateFUV() {

}

/**
 * Calculate and set the global LAUNCH boolean based on the global FUV array.
 * If all values of the FUV array are true, then set LAUNCH to true. Otherwise set LAUNCH to false.
 * 
 */
void decideLaunch() {
  for(int i = 0; i < 15; i ++) {
    if(!FUV[i]) {
      LAUNCH = 0;
      return;
    }
  }
  LAUNCH = 1;
}

/**
 * Prints the launch decision to stdout.
 * If LAUNCH is true, then "YES" is printed, otherwise "NO" is printed.
 */
void printDecision() {
  if(LAUNCH) {
    printf("YES\n");
  }
  else {
    printf("NO\n");
  }
}

/**
 * Determins whether to launch or not, depending on the program input
 * 
 */
void DECIDE() {
  calculateCMV();
  calculatePUM();
  calculateFUV();
  decideLaunch();
  printDecision();
}












