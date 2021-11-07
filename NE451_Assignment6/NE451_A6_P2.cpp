//  NE451 Assignment 6 Problem 2
//  2021-11-06
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

class DerivativeCalculator {
  double (*iF)( double );  // setting point variable for f(x)
  double iDx; // x
  public:
    void setDx( double aDx ) { iDx = aDx; } 
    double dx( ) { 
      return iDx; 
    }
  
  // finite-difference approximation
  double deriv( double aX ) {
    return ( (*iF)(aX - 2*iDx) - 8*(*iF)(aX - iDx) + 8*(*iF)(aX + iDx) - (*iF)(aX + 2*iDx) ) / ( 12*iDx );
  }

  // constructor
  DerivativeCalculator ( double aDx, double aF( double ) ) : iDx( aDx ) { iF = aF; }
};


// f(x) = x^4
double fourth ( double aX ) { 
  return pow( aX , 4 ); 
}


int main ( ) {
  double deltaX = 0.1;
  DerivativeCalculator DC1( deltaX, fourth ); 
  double xPow3[10], xPow4[10], y[10], error[10], logDeltaX[10]; // array definition
  
  for ( int loop = 0; loop < 10; loop++ ) {
    xPow3[loop] = pow(DC1.dx( ), 3); // deltaX raised to 3rd power
    xPow4[loop] = pow(DC1.dx( ), 4); //deltaX raised to 4th power
    y[loop] = DC1.deriv( 1.0 ); 
    error[loop] = log(fabs(DC1.deriv( 1.0 ) - 4)); // verify 4th order accuracy
    logDeltaX[loop] = log(DC1.dx( )); //log(deltaX) ; slope should be 4 near origin
    DC1.setDx( DC1.dx( ) / 1.3 ); 
  }

	
  // DISLIN plotting
  // graph #1 - derivative against xPow3
  metafl( "TIFF" ); // save as TIFF graphic
  disini(); // start plot
  name( "Third Power of Step Length", "x" ); // x label
  name( "Derivative", "y" ); // y label
  labels( "EXP", "xy" ); // exponential format
  incmrk( 1 ); // marker every 1 point
  setscl( xPow3, 10, "x" ); // auto scale axes
  setscl( y, 10, "y" );
  double minX, maxX, minY, maxY, stepX, stepY;
  graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY ); // draw axes 
  curve( xPow3, y, 10 );  // plot curve
  disfin(); // terminate plot


  // graph #2 - derivative against xPow4
  metafl( "TIFF" );
  disini();
  name( "Fourth Power of Step Length", "x" );
  name( "Derivative", "y" );
  labels( "EXP", "xy" );
  incmrk( 1 );
  setscl( xPow4, 10, "x" );
  setscl( y, 10, "y" );
  double minX2, maxX2, minY2, maxY2, stepX2, stepY2;
  graf( minX2, maxX2, minX2, stepX2, minY2, maxY2, minY2, stepY2 ); 
  curve( xPow4, y, 10 );
  disfin();

  // graph #3 - x-logdelx; y-error
  metafl( "TIFF" );
  disini();
  name( "Logarithm of deltaX", "x" );
  name( "Logarithm of Error", "y" );
  labels( "EXP", "xy" );
  incmrk( 1 );
  setscl( logDeltaX, 10, "x" );
  setscl( error, 10, "y" );
  double minX3, maxX3, minY3, maxY3, stepX3, stepY3;
  graf( minX3, maxX3, minX3, stepX3, minY3, maxY3, minY3, stepY3 );
  curve( logDeltaX, error, 10 );
  disfin();
}
