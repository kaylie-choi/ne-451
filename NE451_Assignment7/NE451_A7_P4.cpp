//  NE451 Assignment 7 Problem 4
//  2021-11-15
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

// f(x) = x^3
double func( double aD ) { 
  return pow( aD , 3 ); 
}

double deriv (double aF(double), double aX, double deltaX) {
  return (aF(aX + deltaX) - aF(aX - deltaX)) / (2. * deltaX);
}

// recursive newton's method
double newton(double aF(double), double a, double aEps, double deltaX) {
  double del = - aF(a) / deriv(aF, a, deltaX);
  a += del;
  if (fabs(del) < aEps)
    return a;
  else
    return newton(aF, a, aEps, deltaX);
}

int main() {
	double aEps = 0.001;
	double a = 0.1;
	double deltaX = 0.1;
  
  double logX[10], root[10];
  for ( int loop = 0; loop < 10; loop++ ) {
    logX[loop] = log(deltaX);
    root[loop] = newton(func, a, aEps, deltaX);
    
    deltaX = deltaX / sqrt(10);
  }

  // DISLIN plotting
  metafl( "TIFF" );
  disini();
  name( "Logarithm of deltaX", "x" );
  name( "Root Value", "y" );
  labels( "LOG", "x" );
  incmrk( 1 );
  setscl( logX, 10, "x" );
  setscl( root, 10, "y" );
  double minX, maxX, minY, maxY, stepX, stepY;
  graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY );
  curve( logX, root, 10 );
  disfin();
}
