//  NE451 Assignment 10 Problem 8
//  2021-12-03
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"

using namespace std;

class MyClass {
  public:
  static int iP;
  MyClass(int aX) {iX = aX; iP++;} 
  int iX;
};

int MyClass::iP = 3;

int main() {
  MyClass::iP = 0; 
  MyClass M1(2); 
  MyClass M2(M1); 
  cout << M1.iP << endl; 
}