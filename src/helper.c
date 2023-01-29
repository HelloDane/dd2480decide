#include <math.h>
#include "decide.h"
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void printPUM() {
    for(int i = 0; i <= 14; i++) {
      for(int j = 0; j <= 14; j++) {
        if(PUM[i][j]) printf("(%d,%d)=true ",i,j);
        else printf("(%d,%d)=false ",i,j);
      }
      printf("\n");
    }
}