//  NE451 Assignment 8 Problem 3
//  2021-11-20
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

int const numberOfSteps = 40000; // number of time steps

int main( ) {
  // define parameters
  double x[numberOfSteps], v[numberOfSteps], dt=0.03; 
  double a=1, b=0, c=0.3, F=10, t=0;
  
  // initial conditions
  x[0] = 1;
  v[0] = 6; 

  for ( int i = 1; i < numberOfSteps; i++ ) {
    // position
    x[i] = x[i - 1] + v[i - 1] * dt;

    // duffing oscillator velocity
    // x[i-1]
    v[i] = v[i - 1] - (a*pow(x[i-1], 3) + b*x[i-1] + c*v[i-1] + F*cos(t)) * dt; 

    // x[i]
    v[i] = v[i - 1] - (a*pow(x[i], 3) + b*x[i] + c*v[i] + F*cos(t)) * dt; 
    
    t += dt / 2 ;
  }

  float minX, maxX, minY, maxY, stepX, stepY; 
  metafl("XWIN"); // write to terminal
  disini( ); // start plot
  setscl(x, numberOfSteps, "X");
  setscl(v, numberOfSteps, "Y"); 
  dot();
  incmrk(-1); // plots markers at each point, supressing lines between
  marker(21); // marker type - filled circles
  hsymbl(25); // marker size
  graf(minX, maxX, minX, stepX, minY, maxY, minY, stepY); 
  curve(x, v, numberOfSteps);
  endgrf;
  disfin( ); // terminate plot
}