// Kaylie Choi
// NE 451 Final Exam
// 2021-12-16

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

// global variable
double RAND_MAX;

int main( ) {
	
	// initialize variables 
	double numberOfPoints[];
	double numberOfDimensions; 
	double thresholdDistance;
	double **numberOfhistogramBins = new double* [100];
	int totalNumberOfPairs = numberOfPoints*(numberOfPoints - 1)/2;
	
	// largest possible distance
	int Lmaximum = pow(numberOfDimensions, 0.5);
	
	
	
	
	
	// user input in console line
	cout << "Enter numberOfPoints, numberOfDimensions, and threshold distance" << endl;
	// random uniformly distributed points
	cin >> numberOfPoints;
	// projection of a point along each of the coordinate axes;
	// uniformly distributed random number between 0 and 1
	cin >> numberOfDimensions;
	cin >> thresholdDistance;
	
	qplot( ,thresholdDistance);
}

