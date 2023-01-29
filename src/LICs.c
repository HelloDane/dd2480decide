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
 * LIC 3 is met if there exists there consecutive points which form a triangle with an area greater than PARAMETERS.AREA1 
 * @return boolean representing whether LIC 3 is met or not
 */
boolean LIC3isMet() {
  for(int i = 0; i < NUMPOINTS - 2; i ++) {
    double x_1 = X[i];
    double y_1 = Y[i];
    double x_2 = X[i + 1];
    double y_2 = Y[i + 1];
    double x_3 = X[i + 2];
    double y_3 = Y[i + 2];

    double area = 1.0/2 * fabs(x_1*(y_2 - y_3) + x_2*(y_3 - y_1) + x_3*(y_1 - y_2));
    
    if(area > PARAMETERS.AREA1) {
      return true;
    }
  }

  return false;
}

/**
 * Determines whether LIC 4 is met or not
 * @return boolean representing whether LIC 4 is met or not
 */
boolean LIC4isMet() {
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
 * LIC 6 is met if there exists PARAMETERS.NPTS consecutive points
 * so that for at least one of the points, the distance from that point
 * to the line between the first and last point is greater than PARAMETERS.DIST
 * Requires
 * PARAMETERS.NPTS
 * PARAMETERS.DIST
 * NUMPOINTS
 * where
 * 3 <= PARAMETERS.NPTS <= NUMPOINTS
 * 0 <= PARAMETERS.DIST
 * @return boolean representing whether LIC 6 is met or not
 */
boolean LIC6isMet() {

  if(NUMPOINTS < 3) {
    return false;
  }

  int npts = PARAMETERS.NPTS;
  if(npts > NUMPOINTS || npts < 3 || PARAMETERS.DIST < 0) {
    // This is invalid input
    return false;
  }

  // Example thought process for the loop
  // With npts = 3, and NUMPOINTS = 3, we want to loop once
  // Then this will loop from i = 0 to i < 1, which is once
  for(int i = 0; i < NUMPOINTS - npts + 1; i ++) {
    double firstx = X[i];
    double firsty = Y[i];

    // Motivation for subtraction of 1
    // if npts is 3 and NUMPOINTS is 3, then when first point is 0, then last point should be 2
    // 0 + 3 - 1 = 2
    double lastx = X[i + npts - 1];
    double lasty = Y[i + npts - 1];

    // Check all of the consecutive points, if they fulfill the criteria
    for(int j = i; j < i + npts; j ++) {

      if(firstx == lastx && firsty == lasty) {
        // First and last point lie at the same spot, measure distance to this point instead
        double distance = sqrt(pow(X[j] - firstx, 2) + pow(Y[j] - firsty, 2));
        if(distance > PARAMETERS.DIST) {
          return true;
        }
        continue;
      }
      
      // Formula defined on https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line under "Line defined by two points"
      double x1 = firstx;
      double y1 = firsty;
      double x2 = lastx;
      double y2 = lasty;
      double x0 = X[j];
      double y0 = Y[j];
     
      double distance = fabs((x2 - x1)*(y1 - y0) - (x1 - x0)*(y2 - y1))/sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
      
      if(distance > PARAMETERS.DIST) {
        return true;
      }
    }
  }
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
 * Requires
 * NUMPOINTS
 * PARAMETERS.CPTS
 * PARAMETERS.DPTS
 * PARAMETERS.EPSILON
 * @return boolean representing whether LIC 9 is met or not
 */
boolean LIC9isMet() {

  if(NUMPOINTS < 5) {
    return false;
  }

  if(PARAMETERS.CPTS < 1 || PARAMETERS.DPTS < 1 || PARAMETERS.CPTS + PARAMETERS.DPTS > NUMPOINTS - 3) {
    // Invalid input as per description
    return false;
  }

  int points_set_length = 1 + PARAMETERS.CPTS + 1 + PARAMETERS.DPTS + 1;

  // Loop over all possible sets
  for(int i = 0; i < NUMPOINTS - points_set_length + 1; i ++) {
    double x0 = X[i];
    double y0 = Y[i];

    int secondIndex = i + PARAMETERS.CPTS + 1;
    double x1 = X[secondIndex];
    double y1 = Y[secondIndex];

    int thirdIndex = secondIndex + PARAMETERS.DPTS + 1;
    double x2 = X[thirdIndex];
    double y2 = Y[thirdIndex];

    // If the first or last point, or both, coincides with the vertex (middle point), return false
    if(x0 == x1 && y0 == y1) {
      return false;
    }
    if(x2 == x1 && y2 == y1) {
      return false;
    }

    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // Distance between point 0 and 1
    double b = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // Distance between point 1 and 2
    double c = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2)); // Distance between point 0 and 2

    // law of cosine
    double angle = acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b));
    
    if(angle < PI - PARAMETERS.EPSILON || angle > PI + PARAMETERS.EPSILON) {
      return true;
    }
  }
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
 * There exists at least one set of three data points, separated by exactly A PTS and B PTS
 * consecutive intervening points, respectively, that cannot be contained within or on a circle of
 * radius RADIUS1. In addition, there exists at least one set of three data points (which can be
 * the same or different from the three data points just mentioned) separated by exactly A PTS
 * and B PTS consecutive intervening points, respectively, that can be contained in or on a
 * circle of radius RADIUS2. Both parts must be true for the LIC to be true. The condition is
 * not met when NUMPOINTS < 5.
 * @return boolean representing whether LIC 13 is met or not
 */
boolean LIC13isMet() {
  if (NUMPOINTS < 5 || PARAMETERS.APTS < 0 || PARAMETERS.BPTS < 0 ||
     (NUMPOINTS - PARAMETERS.APTS - PARAMETERS.BPTS - 3) < 0 || PARAMETERS.RADIUS2 < 0) {
    return false;
  }
  boolean cond1 = false;
  boolean cond2 = false;
  for (int i = 0; i < (NUMPOINTS - PARAMETERS.APTS - PARAMETERS.BPTS - 2); i++) {
    double x1 = X[i];
    double y1 = Y[i];
    double x2 = X[i + PARAMETERS.APTS + 1];
    double y2 = Y[i + PARAMETERS.APTS + 1];
    double x3 = X[i + PARAMETERS.APTS + 1 + PARAMETERS.BPTS + 1];
    double y3 = Y[i + PARAMETERS.APTS + 1 + PARAMETERS.BPTS + 1];
    // cond1: At least one of the distances between the pairs of data points must be greater than the diameter.
    if (distance(x1,y1,x2,y2) > PARAMETERS.RADIUS1*2 ||
        distance(x2,y2,x3,y3) > PARAMETERS.RADIUS1*2 ||
        distance(x3,y3,x1,y1) > PARAMETERS.RADIUS1*2) {
          cond1 = true;
    }
    // cond2: All of the distances between the pairs of data points must be less than or equal to the diameter.
    if (distance(x1,y1,x2,y2) <= PARAMETERS.RADIUS2*2 &&
        distance(x2,y2,x3,y3) <= PARAMETERS.RADIUS2*2 &&
        distance(x3,y3,x1,y1) <= PARAMETERS.RADIUS2*2) {
          cond2 = true;
    }
  }
  if (cond1 && cond2) {
    return true;
  }
  return false;
}

/**
 * Determines whether LIC 14 is met or not
 * @return boolean representing whether LIC 14 is met or not
 */

boolean LIC14isMet() {
  if(NUMPOINTS < 5) {
    return false;
  }
  if(PARAMETERS.AREA2 < 0) { //invalid input
    return false;
  }
  boolean flag1 = false;
  boolean flag2 = false;
  int e_pts = PARAMETERS.EPTS;
  int f_pts = PARAMETERS.FPTS;
  double a, b, c, p, area;
  double x1, y1, x2, y2, x3, y3;
 for (int i = 0; i < NUMPOINTS - (e_pts + f_pts + 2); i++) { // first point (X[i], Y[i])
  x1 = X[i];
  y1 = Y[i];
  for (int j = i + e_pts + 1; j < NUMPOINTS - (f_pts + 1); j++) { // second point (X[j], Y[j])
    x2 = X[j];
    y2 = Y[j];
    for (int k = j + f_pts + 1; k < NUMPOINTS; k++) { // third point (X[k], Y[k])
      x3 = X[k];
      y3 = Y[k];
      a = distance(x1, y1, x2, y2);
      b = distance(x2, y2, x3, y3);
      c = distance(x1, y1, x3, y3);
      p = (a + b + c) / 2.0;
      area = sqrt (p * (p - a) * (p - b) * (p - c));
      #ifdef DEBUG
      printf("(%f,%f)(%f,%f)(%f,%f)\n",x1,y1,x2,y2,x3,y3);
      printf("area = %f\n", area);
      #endif
      if(area > PARAMETERS.AREA1) {
        #ifdef DEBUG
        printf("flag1 true for area = %f\n", area);
        printf("AREA1 = %f\n", PARAMETERS.AREA1);
        #endif
        flag1 = true;
      }
      if(area < PARAMETERS.AREA2) {
        #ifdef DEBUG
        printf("flag2 true for area = %f\n",area);
        printf("AREA2 = %f\n", PARAMETERS.AREA2);
        #endif
        flag2 = true;
      }
    }
  }
 }
  if(flag1 && flag2) {
      return true;
  }
  return false;
}