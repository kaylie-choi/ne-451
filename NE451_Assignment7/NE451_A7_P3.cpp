//  NE451 Assignment 7 Problem 3
//  2021-11-15
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"

using namespace std;

double func(double aD) {
  // return aD * sqrt(fabs(aD));
  return sin(aD);
}

double deriv (double aF(double), double aX) {
  double deltaX = 1.e-4;
  return (aF(aX + deltaX) - aF(aX - deltaX)) / (2. * deltaX);
}

int numIterations = 0;
// recursive newton's method
double newton(double aF(double), double a, double aEps) {
  // count number of iterations steps
  numIterations++;
  double del = - aF(a) / deriv(aF, a);
  a += del;
  if (fabs(del) < aEps)
    return a;
  else
    return newton(aF, a, aEps);
}

int main() {
  cout << "Root: " << newton(func, 0.1, 1.e-4) << endl;
  cout << "Number of Iteration Steps: " << numIterations << endl;
}