

#include <iostream>
#include "dislin.h"

using namespace std;


class Ball {
    public:
      double massBall1, massBall2;
      double positions[2];
      double velocities[2];
      Ball(double aX, double aY, double aVx, double aVy) {
          positions[0] = aX;
          positions[1] = aY;
          velocities[0] = aVx;
          velocities[1] = aVy;
      }
};

class TwoBallSystem {
    public:
      Ball Ball1;
      Ball Ball2;
      double forceConstant;
      double dampingConstant;
      double xBall1[1000];
      double yBall2[1000];
      double numberOfSteps; 
      double timeInterval;
    
    // constructor, initialize force / damping constants
    // assigns memory to Ball object array  & 2 internal 100 element arrays
    TwoBallSystem(double ) {};

    // euler-cromer method to evolve 2 ball system
    // and number of time steps in time duration
    // store x & y positions of ball 1
    void propogate( double numberOfSteps) {


    };

    // assign value of 2 args of type Ball to 2 elements of Ball object array
    void setBall() {

    };


    void plotTrajectory() {
      // qplot(x, y);
    }
};

int main() {

  TwoBallSystem TBS();
  double forceConstant = 0.2;
  double dampingConstant = 0.2;
  double numberOfSteps = 1000; 
  double timeInterval = 0.0025;



};