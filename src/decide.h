#ifndef DECIDE_H
#define DECIDE_H
#include <math.h>
#include <stdio.h>
////////////const ANT//////////
static const double PI = 3.1415926535;
////////////TYPEDECLARATIONS///////////
typedef enum {
  NOTUSED = 777,
  ORR,
  ANDD
} CONNECTORS;

//alwaysint herange[0..1]
typedef int boolean;
typedef enum {
  LT = 1111,
  EQ,
  GT
} COMPTYPE;
//inputstotheDECIDE()function
typedef struct {
  double LENGTH1;//LengthinLICs0,7,12
  double RADIUS1;//RadiusinLICs1,8,13
  double EPSILON;//DeviationfromPIinLICs2,9
  double AREA1;//AreainLICs3,10,14
  int QPTS;//No.ofconsecutivepoint sinLIC4
  int QUADS;//No.ofquadrantsinLIC4
  double DIST;//DistanceinLIC6
  int NPTS;//No.ofconsecutivepts.inLIC6
  int KPTS;//No.ofint .pts.inLICs7,12
  int APTS;//No.ofint .pts.inLICs8,13
  int BPTS;//No.ofint .pts.inLICs8,13
  int CPTS;//No.ofint .pts.inLIC9
  int DPTS;//No.ofint .pts.inLIC9
  int EPTS;//No.ofint .pts.inLICs10,14
  int FPTS;//No.ofint .pts.inLICs10,14
  int GPTS;//No.ofint .pts.inLIC11
  double LENGTH2;//MaximumlengthinLIC12
  double RADIUS2;//MaximumradiusinLIC13
  double AREA2;//MaximumareainLIC14
} PARAMETERS_T;

////////////globalvariabledeclarations////////////
extern PARAMETERS_T PARAMETERS;

//XCOORDINATE sofdatapoint s
extern double X[100];

//YCOORDINATE sofdatapoint s
extern double Y[100];

//Numberofdatapoint s
extern int NUMPOINTS;

//LogicalConnectorMatrix
extern CONNECTORS LCM[15][15];

//PreliminaryUnlockingMatrix
extern boolean PUM[15][15];

//ConditionsMetVECTOR 
extern boolean CMV[15];

//FinalUnlockingVECTOR 
extern boolean FUV[15];

//PreliminaryUnlockingVECTOR 
extern boolean PUV[15];

//Decision:LaunchorNoLaunch
extern boolean LAUNCH;

//comparesfloatingpoint numbers−−seeNonfunctionalRequirements
static inline
COMPTYPE DOUBLECOMPARE(double A, double B) {
  if(fabs(A - B) < 0.000001) return EQ;
  if(A < B) return LT;
  return GT;
}
//functionyoumustwrite
void DECIDE(void);

boolean LIC0isMet();
boolean LIC1isMet();
boolean LIC2isMet();
boolean LIC3isMet();
boolean LIC4isMet();
boolean LIC5isMet();
boolean LIC6isMet();
boolean LIC7isMet();
boolean LIC8isMet();
boolean LIC9isMet();
boolean LIC10isMet();
boolean LIC11isMet();
boolean LIC12isMet();
boolean LIC13isMet();
boolean LIC14isMet();
void testLICs();

void calculateCMV();
void calculatePUM();
void calculateFUV();
void decideLaunch();

void testAll();

//helper functions
double distance(double x1, double y1, double x2, double y2);
void printPUM();

#define LOGE(format, ...)  fprintf(stderr,"[ERROR] [%s:%d] " format "\n",__func__,__LINE__,##__VA_ARGS__)
static inline
void assert(boolean expression, char * value, char * expected) {
  if(!expression) {
    LOGE("Expected %s to equal %s", value, expected);
  }
}
#endif