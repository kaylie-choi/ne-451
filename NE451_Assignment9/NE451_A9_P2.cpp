//  NE451 Assignment 9 Problem 2
//  2021-11-29
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
// #include "dislin.h"

using namespace std;


int main( ) {
  double gridInterval = 3.1415; // grid from [0, pi]
  int numTimeSteps = 10000; // time steps
  int numGridPts = 10000; // computational grid points

  double *temperature = new double[ numGridPts ];
  double *temperatureEnd = new double[ numGridPts ];
  double *gridPts = new double[ numGridPts ];
  
  double delX = gridInterval / ( numGridPts - 1 ); // deltaX, equal spacing
  double delT = 0.01; // deltaT
  double diffCoef = 0.02; // diffusion coefficient D
  double coefficient = diffCoef * delT / ( pow(delX, 2 ));
  
  for( int x = 0; x < numGridPts; x++ ) {
    gridPts[x] = x * delX;
    // initial temperature distribution on [0, pi] given by 10sin(x)
    temperature[x] = 10 * sin( gridPts[x] ); 
  }
  
  for ( int outerLoop = 0; outerLoop < numTimeSteps; outerLoop++ ) {
    for ( int loop = 0; loop < numGridPts; loop++ ) {
      temperatureEnd[loop] = temperature[loop];
    } 
    for ( int loop = 0; loop < numGridPts; loop++ ) {
      if ( loop == 0 ) {
        temperature[loop] = coefficient * ( temperatureEnd[numGridPts - 1] - 2 * temperatureEnd[loop] + temperatureEnd[loop + 1] ) + temperature[loop];
      }
      else if ( loop == ( numGridPts - 1 ) ) {
        temperature[loop] = coefficient * ( temperatureEnd[loop - 1] - 2 * temperatureEnd[loop] + temperature[0]) + temperature[loop];
      } 
      else {
        temperature[loop] = coefficient * ( temperatureEnd[loop - 1] - 2 * temperatureEnd[loop] + temperatureEnd[loop + 1] ) + temperature[loop];
      }
    } 
  } 

  // cout << "first half of temperature distribution, x -> f(x)" << endl;
  // cout << "--------------------------------------------------" << endl;
  for( int loop = 5000; loop < 5005; loop++ ) {
    cout << gridPts[loop] << " -> " << temperature[loop] << endl;

  } 
  // qplot( gridPts, temperature, numGridPts ); // quick plot; grid points from 0 -> pi as a function of temperature
}