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

double deriv (double aF(double), double aX) {
  double deltaX = 1.e-4;
  return (aF(aX + deltaX) - aF(aX - deltaX)) / (2. * deltaX);
}

// recursive newton's method
double newton(double aF(double), double a, double aEps) {
  double del = - aF(a) / deriv(aF, a);
  a += del;
  if (fabs(del) < aEps)
    return a;
  else
    return newton(aF, a, aEps);
}

int main() {
  double deltaXx[9] = {0.1, 0.1/pow(10, 1/2), 0.01, 0.01/pow(10, 1/2), 0.001, 0.001/pow(10, 1/2), 0.0001, 0.0001/pow(10, 1/2), 0.00001 };
  double root[9];

  int i = 0;
  while(i < 9) {
    root[i] = newton(func, 0.1, deltaXx[i] ); //y
    i++;
  }
  
  cout << deltaXx[0] << endl;
  cout << root[0] << endl;
  cout << deltaXx[1] << endl;
  cout << root[1] << endl;
  cout << deltaXx[2] << endl;
  cout << root[2] << endl;
  cout << deltaXx[3] << endl;
  cout << root[3] << endl;

  // DISLIN plotting
  // metafl( "XWIN" );
  disini();
  name( "Logarithm of deltaX", "x" );
  name( "Logarithm of Error", "y" );
  labels( "EXP", "xy" );
  incmrk( 1 );
  setscl( deltaXx, 9, "x" );
  setscl( root, 9, "y" );
  double minX, maxX, minY, maxY, stepX, stepY;
  graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY );
  curve( deltaXx, root, 9 );
  disfin();
}
