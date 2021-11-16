//  NE451 Assignment 7 Problem 1
//  2021-11-14
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

class IntegralCalculator {
  // private: is implicit
  double iLeftLim, iRightLim, iResult, iDx;
  int iNumIntervals;
  double (*iF) (double); // setting point variable for f(x)

  public:
    // constructor
    IntegralCalculator( double (*aF) (double) ) : iF(aF) {}

    int numIntervals() { return iNumIntervals; }
    void setNumIntervals( int aNumIntervals ) {
      iNumIntervals = aNumIntervals;
    }
    double dx() { return iDx; }
    double result() { return iResult; }

    void setParams() {
      iLeftLim = 0; // set lower limit
      iRightLim = 1; // set upper limit
      iNumIntervals = 10; // set number of intervals
    }

    // simpson's rule
    void integrate() {
      iDx = (iRightLim - iLeftLim) / iNumIntervals; // step length

      double x = 0;
      double sum = 0;
      for (int i = 0; i < iNumIntervals; i++) {
        // sum += iF(x + iDx / 2);
        sum += (iF(x) + 4*iF(x + iDx / 2) + iF(x + iDx)) / 6.;
        x += iDx;
      }
      iResult = sum * iDx;
    }

    void print() {
      cout << "Left limit: " << iLeftLim << endl;
      cout << "Right limit: " << iRightLim << endl;
      cout << "Number of intervals: " << iNumIntervals << endl;
      cout << "Integration interval: " << iDx << endl;
      cout << "Integral: " << iResult << endl;
    }
};

// f(x) = x^5
double fifth( double aX ) {
  return pow( aX, 5 );
}

int main() {
  IntegralCalculator IC1( fifth );
  IC1.setParams();
  IC1.integrate();
  IC1.print();

  double x[10], logX[10], error[10];
  for ( int loop = 0; loop < 10; loop++ ) {
    x[loop] = IC1.dx();
    logX[loop] = log( IC1.dx() );
    IC1.integrate();

    error[loop] = log(fabs(IC1.result() - 1.0 / 6.0)); // given integral of fn is x/6
    IC1.setNumIntervals(IC1.numIntervals() * 1.3); // multiply deltaX by 1.3 for each iteration
  }
  
  cout << "slope: " << (error[5] - error[4])/(logX[5] - logX[4]) << endl;
  
  // DISLIN plotting 
  // graphically determine order of error
  metafl( "TIFF" ); // save as TIFF graphic
  disini(); // start plot
  name( "Logarithm of Step Length", "x" ); // x label
  name( "Logarithm of Error", "y" ); // y label
  qplsca(logX, error, 10); // quick scatter plot
  disfin(); // terminate plot
}
