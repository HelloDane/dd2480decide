#include "decide.h"
#include <stdbool.h>
#include <math.h>
/**
 * Determines whether LIC 0 is met or not.
 * LIC 0 is met if there exists at least one set of two consecutive data points that are a distance greater than
 * the length, LENGTH1, apart.
 * @return boolean representing whether LIC 0 is met or not
 */
boolean LIC0isMet() {
  for(int i = 0; i < NUMPOINTS - 1; i ++) {
    double x_one = X[i];
    double y_one = Y[i];
    double x_two = X[i + 1];
    double y_two = Y[i + 1];
    double distance_x = fabs(x_two - x_one);
    double distance_y = fabs(y_two - y_one);
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    if(distance < PARAMETERS.LENGTH1) {
      return true;
    }
  }
  return false;
}

/**
 * Determines whether LIC 1 is met or not
 * @return boolean representing whether LIC 1 is met or not
 */
boolean LIC1isMet() {
  return false;
}

/**
 * Determines whether LIC 2 is met or not
 * @return boolean representing whether LIC 2 is met or not
 */
boolean LIC2isMet() {
  for (int i = 0; i < NUMPOINTS - 2; i++) {
    double x1 = X[i];
    double y1 = Y[i];
    double x2 = X[i + 1]; // vertex point
    double y2 = Y[i + 1];
    double x3 = X[i + 2];
    double y3 = Y[i + 2];

    if(x1 == x2 && y1 == y2) { // point 1 concides with point 2
      return false;
    }
    else if(x2 == x3 && y2 == y3) { // point 2 concides with point 3
      return false;
    }
    else if (x1 == x3 && y1 == y3) { // point 1 concides with point 3
      return false;
    }

    double angle = atan2(y3 - y2, x3 - x2) - atan2(y1 - y2, x1 - x2);
    angle = fmod(angle + 2 * PI, 2 * PI);

    if (DOUBLECOMPARE(angle, (PI - PARAMETERS.EPSILON)) == LT || DOUBLECOMPARE(angle, (PI + PARAMETERS.EPSILON)) == GT) {
        return true;
    }
  }
  return false;
}

/**
 * Determines whether LIC 3 is met or not
 * @return boolean representing whether LIC 3 is met or not
 */
boolean LIC3isMet() {
  return false;
}

/**
 * Determines whether LIC 4 is met or not
 * There exists at least one set of Q_PTS consecutive data points that lie in more than QUADS
 * quadrants. Where there is ambiguity as to which quadrant contains a given point, priority
 * of decision will be by quadrant number, i.e., I, II, III, IV. For example, the data point (0,0)
 * is in quadrant I, the point (-l,0) is in quadrant II, the point (0,-l) is in quadrant III, the point
 * (0,1) is in quadrant I and the point (1,0) is in quadrant I.
 * @return boolean representing whether LIC 4 is met or not
 */
boolean LIC4isMet() {
  if (PARAMETERS.QPTS < 2|| PARAMETERS.QPTS > NUMPOINTS || PARAMETERS.QUADS < 1|| PARAMETERS.QUADS > 3) {
    return false; //Parameters are invalid.
  }
  
  boolean pointInQuad[4]; //Index i refers to quadrant (i+1)

  for (int i = 0; i <= NUMPOINTS - PARAMETERS.QPTS; i++) {
    for (int j = 0; j < 4; j++){
      pointInQuad[j] = false;
    }

    for (int j = 0; j < PARAMETERS.QPTS; j++) { 

      double x = X[i+j]; //Highest possible index is (NUMPOINTS - QPTS + (QPTS-1)) = NUMPOINTS-1
      double y = Y[i+j];

      // All quadrant signs for (x,y):
      // I: (+,+), II = (-,+), III = (+,-), IV = (-,-)

        if (y >= 0) {
          if (x >= 0) { 
            pointInQuad[0] = true; //I: (+,+)
          }
          else { 
            pointInQuad[1] = true; //II = (-,+)
          }
        }
        else {
          if (x >= 0) { 
            pointInQuad[2] = true; //III = (+,-)
          }
          else { 
            pointInQuad[3] = true; //IV = (-,-)
          }
        }
    }
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      if (pointInQuad[j]) {
        sum ++;
      }
    }
    if (sum > PARAMETERS.QUADS) {
      return true;
    }
  }
    return false;

}

/**
 * Determines whether LIC 5 is met or not
 * @return boolean representing whether LIC 5 is met or not
 */
boolean LIC5isMet() {
  return false;
}

/**
 * Determines whether LIC 6 is met or not
 * @return boolean representing whether LIC 6 is met or not
 */
boolean LIC6isMet() {
  return false;
}

/**
 * Determines whether LIC 7 is met or not
 * @return boolean representing whether LIC 7 is met or not
 */
boolean LIC7isMet() {
  return false;
}

/**
 * Determines whether LIC 8 is met or not
 * @return boolean representing whether LIC 8 is met or not
 */
boolean LIC8isMet() {
  return false;
}

/**
 * Determines whether LIC 9 is met or not
 * @return boolean representing whether LIC 9 is met or not
 */
boolean LIC9isMet() {
  return false;
}

/**
 * Determines whether LIC 10 is met or not
 * @return boolean representing whether LIC 10 is met or not
 */
boolean LIC10isMet() {
  return false;
}

/**
 * Determines whether LIC 11 is met or not
 * @return boolean representing whether LIC 11 is met or not
 */
boolean LIC11isMet() {
  return false;
}

/**
 * Determines whether LIC 12 is met or not
 * @return boolean representing whether LIC 12 is met or not
 */
boolean LIC12isMet() {
  return false;
}

/**
 * Determines whether LIC 13 is met or not
 * @return boolean representing whether LIC 13 is met or not
 */
boolean LIC13isMet() {
  return false;
}

/**
 * Determines whether LIC 14 is met or not
 * @return boolean representing whether LIC 14 is met or not
 */
boolean LIC14isMet() {
  return false;
}