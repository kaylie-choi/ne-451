//  NE451 Assignment 8 Problem 4
//  2021-11-20
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
// #include "dislin.h"

using namespace std;

// define function to integrate
// for a unit circle: 1 = x^2 + y^2 for radius = 1
// --> y = sqrt(1 - x^2)
double unitCircle( double aX ) {
  return sqrt( 1 - (pow(aX, 2)) );
}

// monte-carlo integration for area of unit circle
double monteCarloIntegral( double aA, double aB, double aNumEvaluationPoints) {
  // define y-limits
  double y1 = unitCircle( aA ); // lower limit
  double y2 = unitCircle( aB ); // upper limit 

  // define reference region area 
  double referenceRegionArea = abs( aB - aA ) * ( y2 - y1 ); 

  // initialize 
  int numPointsBelowCurve = 0;

  for ( int i = 0; i < aNumEvaluationPoints; i++ ) {
    double xPosition = rand() / double(RAND_MAX) * ( aB - aA ) + aA;
    double yPosition = rand() / double(RAND_MAX) * ( y2 - y1 ) + y1;

    // increment numPointsBelowCurve by one for each random point
    // that lies below unitCircle function
    if ( unitCircle( xPosition ) < yPosition ){
      numPointsBelowCurve ++ ;
    }
  }
  // integral is ratio of number of points below the curve to total sample points,
  // multiplied by the reference region area,
  // added to the difference of the x-limits, multiplied by the lower y-limit
  double integral =  ( numPointsBelowCurve / aNumEvaluationPoints )
                    * referenceRegionArea + ( aB - aA ) * y1; 
  
  cout << "area of unit circle : " << integral  << endl;
  
  return integral;

}

int main() {
  double a = 0; // lower x-limit of unit square
  double b = 1; // upper x-limit of unit square
  double logEvalPts[10], logError[10]; // array definition

  // initialize
  int numPoints = 0 ;
  int numEvaluations = 1000;

  // looping through 10 times to use 2000, 4000, 8000, ... (2^10)*100 steps
  for ( int j = 0; j < 10; j++ ) {
    numEvaluations *= 2; 
    double MCI = monteCarloIntegral( a, b, numEvaluations);

    logEvalPts[numPoints] = log10(numEvaluations);
    logError[numPoints] = log10(fabs(MCI * 4 - M_PI));
  }

  // qplsca ( resX, resY, numPoints );

}
