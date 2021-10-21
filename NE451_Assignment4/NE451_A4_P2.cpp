//  NE451 Assignment 4 Problem 2
//  2021-10-21
//  Kaylie Choi - 20692499

#include <iostream>
#include "dislin.h"
#include <math.h> 

using namespace std;

// gas constant 0.0821 atm/mol*K
const double R = 0.082;

class Gas {
  public: 
  // VDW constants a and b
    double iA;
    double iB;
    Gas(double aA, double aB)
};


class VanDerWaalsCalculator {
  public: 
    Gas iGas;
    float iVolume[100];
    float iPressure[100];
    float iTemperature;
    float iNumberOfMoles;
    int iNumberOfPoints;

    VanDerWaalsCalculator (
      Gas aGas,
      double aMinimumVolume,
      double aMaximumVolume,
      double aTemperature, 
      double aNumberOfMoles,
      int aNumberOfPoints
    )

    // Use the Van der Waals formula to generate the pressure vector
    void generatePressure(){
      // P = (nRT/(V-nb)) - (an^2/v^2)


    }

    // Graph the pressure as a function of volume
    void draw()
};

main() {
  // a = 0.027 I^2*atm/mol^2
  // b = 0.0024 L/mol
  Gas Oxygen(0.027, 0.0024);

  float numberOfMoles = 1;
  float minimumVolume = 1;
  float maximumVolume = 10;
  int numberOfPoints = 100;
  float temperature = 300;

  VanDerWaalsCalculator VDW(Oxygen, minimumVolume, maximumVolume, temperature, numberOfMoles, numberOfPoints);
  VDW.generatePressure();
  VDW.draw();
}