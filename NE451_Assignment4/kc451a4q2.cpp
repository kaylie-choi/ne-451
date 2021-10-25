//  NE451 Assignment 4 Problem 2
//  2021-10-24
//  Kaylie Choi - 20692499

#include <iostream>
#include "dislin.h"

using namespace std;

// gas constant 0.0821 atm/mol*K
const double R = 0.082;

class Gas {
  public: 
  // VDW constants a and b
    double iA;
    double iB;
    Gas (double aA, double aB ) : iA ( aA ), iB ( aB ) {};
};


class VanDerWaalsCalculator {
  public: 
    Gas iGas; // initialize iGas in initialization list, not body of VanDerWallsCalculator constructor
    double iVolume[100];
    double iPressure[100];
    double iTemperature;
    double iNumberOfMoles;
    int iNumberOfPoints;

  VanDerWaalsCalculator ( 
  	Gas aGas, 
	double aMinimumVolume,
	double aMaximumVolume, 
	double aTemperature, 
	double aNumberOfMoles, 
	int aNumberOfPoints ) : iGas( aGas ) {
    	iTemperature = aTemperature;
    	iNumberOfMoles = aNumberOfMoles;
	    iNumberOfPoints = aNumberOfPoints; 

    	double delta = ( aMaximumVolume - aMinimumVolume ) / aNumberOfPoints;

      	for ( int loop = 0; loop < iNumberOfPoints; loop++) {
        	if ( loop == 0 ) {
          		iVolume[loop] = aMinimumVolume;
        	}
        	else {
            	iVolume[loop] = iVolume[loop - 1] + delta;
        	}
    	}
  };

  // Use the Van der Waals formula to generate the pressure vector
  void generatePressure( ) {
    for ( int loop = 0; loop < iNumberOfPoints; loop++ ) {
      	// P = (nRT/(V-nb)) - (an^2/v^2)
     	 iPressure[loop] = (( iNumberOfMoles * R * iTemperature ) 
                        	- (( iGas.iA * iNumberOfMoles * iNumberOfMoles ) / ( iVolume[loop] * iVolume[loop] )) 
                        	* ( iVolume[loop] - ( iGas.iB * iNumberOfMoles )))
                        	/ ( iVolume[loop] - ( iGas.iB * iNumberOfMoles ));
    } 
  }

  // Graph the pressure as a function of volume
  void draw( ) {
    metafl("TIFF");
    disini(); 

    name("Volume (L)", "x");
    name("Pressure (atm)", "y");
    
    qplsca(iVolume, iPressure, iNumberOfPoints);
    disfin();
  }
};

main() {
  // a = 0.027 I^2*atm/mol^2
  // b = 0.0024 L/mol
  Gas Oxygen(0.027, 0.0024);

  double minimumVolume = 1;
  double maximumVolume = 10;
  double temperature = 300;
  double numberOfMoles = 1;
  int numberOfPoints = 100;

  VanDerWaalsCalculator VDW(Oxygen, minimumVolume, maximumVolume, temperature, numberOfMoles, numberOfPoints);
  VDW.generatePressure();
  VDW.draw();
}

