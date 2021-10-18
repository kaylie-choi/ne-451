/*Demonstrates the DISLIN plotting program */
#include <iostream>
#include "dislin.h"

using namespace std; 

double f(double aX) {
	return aX * aX;
}

main( ){
	double x[11], y[11];
	double del = 0.1;
	for (int loop = 0; loop < 11; loop++){
		x[loop] = loop * del;
		y[loop] = f(x[loop]); 
	}
	
	metafl("TIFF");
	disini(); 

	name("X-axis","x");
	name("Y-axis","y");
	 
	qplsca(x, y, 11);
	disfin();
}
