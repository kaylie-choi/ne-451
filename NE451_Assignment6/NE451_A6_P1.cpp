//  NE451 Assignment 6 Problem 1
//  2021-11-06
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

class DerivativeCalculator {
  double (*iF)( double );  // setting point variable
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


double sixth ( double aX ) { 
  return pow( aX , 6 ); 
}


int main ( ) {
  double deltaX = 0.1; // delta x
  DerivativeCalculator DC1( deltaX, sixth ); 
  double xPow3[10], xPow4[10], y[10], error[10], logDeltaX[10]; // array definition
  
  for ( int loop = 0; loop < 10; loop++ ) {
    xPow3[loop] = pow(DC1.dx( ), 3); // deltaX raised to 3rd power
    xPow4[loop] = pow(DC1.dx( ), 4); //deltaX raised to 4th power
    y[loop] = DC1.deriv( 1.0 ); 
    error[loop] = log(abs(DC1.deriv( 1.0 ) - 6)); // verify 4th order accuracy
    logDeltaX[loop] = log(DC1.dx()); //log(deltaX) ; slope should be 4 near origin
    DC1.setDx( DC1.dx( ) / 1.3 ); 
  }

  // dislin plotting

  // graph #1 - derivative against xPow3
  metafl( “XWIN” ); // write to terminal
  disini(); // start plot
  name( "Third Power of Step Length", “x” ); // x label
  name( “Derivative”, “y” ); // y label
  labels( “EXP”, ”xy” ); // exponential format
  incmrk( 1 ); // marker every 1 point
  setscl( x, 10, “x” ); // auto scale axes
  setscl( y, 10, “y” );
  double minX, maxX, minY, maxY, stepX, stepY;
  graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY ); // draw axes 
  curve( xPow3, y, 10 );  // plot curve
  disfin(); // terminate plot


  // graph #2 - derivative against xPow4
  metafl( “XWIN” ); // write to terminal
  disini(); // start plot
  name( "Fourth Power of Step Length", “x” ); // x label
  name( “Derivative”, “y” ); // y label
  labels( “EXP”, ”xy” ); // exponential format
  incmrk( 1 ); // marker every 1 point
  setscl( x, 10, “x” ); // auto scale axes
  setscl( y, 10, “y” );
  double minX, maxX, minY, maxY, stepX, stepY;
  graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY ); // draw axes 
  curve( xPow4, y, 10 );  // plot curve
  disfin(); // terminate plot

  // graph #3 - x-logdelx; y-error
  metafl( “XWIN” ); // write to terminal
  disini(); // start plot
  name( "Log(delta X)", “x” ); // x label
  name( "Logarithm of Error |df/dx - 6|" , “y” ); // y label
  labels( LOG, ”xy” ); // exponential format
  incmrk( 1 ); // marker every 1 point
  setscl( x, 10, “x” ); // auto scale axes
  setscl( y, 10, “y” );
  double minX, maxX, minY, maxY, stepX, stepY;
  graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY ); // draw axes 
  curve( logDeltaX, error, 10 );  // plot curve
  disfin(); // terminate plot
}