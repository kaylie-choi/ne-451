// Gravitational field magnitude of Earth
// Illustrates simple 3-dimensional plotting routines

#include <iostream> 
#include "dislin.h"
#include <math.h> 

using namespace std; 

const double KM = 1000;
const double GRAVITATIONALCONSTANT = 6.67e-11; 
const double EARTHMASS = 5.97e24;
const double EARTHRADIUS = 6380 * KM;
const int MATSIZE = 20;

double gravitationalField(double aX, double aY) {
  const double radius = sqrt(aX * aX + aY * aY);
  if (radius < EARTHRADIUS)
    return GRAVITATIONALCONSTANT * EARTHMASS * radius / (EARTHRADIUS*EARTHRADIUS*EARTHRADIUS);
  else if (radius >= EARTHRADIUS)
    return GRAVITATIONALCONSTANT * EARTHMASS / (aX * aX + aY * aY);
}

main ( ) {
  double position[MATSIZE]; // x and y coordinate positions
  double field[MATSIZE][MATSIZE]; // gravitational field
  float offset = MATSIZE / 2 - 0.5; // determines starting point of the grid

  for (int loop = 0; loop < MATSIZE; loop++) {
    position[loop] = 0.1 * EARTHRADIUS * (loop - offset);
  } 

  float x, y;

  for (int outerLoop = 0; outerLoop < MATSIZE; outerLoop++) {
    x = position[outerLoop];
    for (int innerLoop = 0; innerLoop < MATSIZE; innerLoop++) {
      y = position[innerLoop];
      field[outerLoop][innerLoop] = gravitationalField(x, y);
    } 
  } 

  metafl("XWIN");
  disini( );
  int iPlot = 2; // 1 -> surface plot; 2 -> color plot; 3 -> contour plot
  
  if (iPlot == 1) // surface plot
    qplsur((double*) field, MATSIZE, MATSIZE); 
  else if (iPlot == 2) // color plot
    qplclr((double*) field, MATSIZE, MATSIZE); 
  else { // contour plot
    int numberOfContours = 30;
    qplcon((double*) field, MATSIZE, MATSIZE, numberOfContours); 
  }
}