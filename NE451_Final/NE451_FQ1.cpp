// Kaylie Choi
// NE 451 Final Exam
// 2021-12-16

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;


int main( ) {
	
	// initialize variables 
	double numberOfDimensions; 
	double thresholdDistance;
	
	double **numberOfPoints = new double* [];
  double **numberOfHistogramBins = new double* [100];
  

  // calculate number of pairs
	int totalNumberOfPairs = numberOfPoints * ( numberOfPoints - 1 ) / 2;
	
	// largest possible distance
	int Lmaximum = pow(numberOfDimensions, 0.5);
	
	
	
	
	
	// prompt for user input in console line
	cout << "Enter numberOfPoints, numberOfDimensions, and threshold distance" << endl;
	
  // random uniformly distributed points; 110
	cin >> numberOfPoints;
	// projection of a point along each of the coordinate axes, uniformly distributed random number between 0 and 1; 15
	cin >> numberOfDimensions;
  // 0.9
	cin >> thresholdDistance;
	
  // histogram values vs distance;
  // histogram of the number of pairs of points separated by distances within the 100 equal length intervals between 0 and Lmaximum
	qplot( ,thresholdDistance);


  // deallocate dynamically allocated arrays
  for ( int i = 0; i < n; i++ ) {
    delete [] numberOfPoints[i];
  }

  for ( int i = 0; i < 100; i++ ) {
    delete [] numberOfHistogramBins[i];
  }
  delete [] numberOfPoints;
  delete [] numberOfHistogramBins;
  
}

