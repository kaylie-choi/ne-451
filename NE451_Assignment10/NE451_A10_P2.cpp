//  NE451 Assignment 10 Problem 2
//  2021-12-03
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"

using namespace std;

class myClass { 
  public:
  int i;
  myClass& square() {i = i*i; return *this;}
};

int main() {
  myClass myClass1; 
  myClass1.i = 4;
  cout << myClass1.square().square().i; 
}