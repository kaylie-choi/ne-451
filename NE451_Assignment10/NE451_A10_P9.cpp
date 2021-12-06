//  NE451 Assignment 10 Problem 9
//  2021-12-03
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"

using namespace std;

class Base {
  public:
    void virtual print() { cout << " Base Class " << endl; } 
};

class Derived : public Base {
  public:
  void print() { cout << " Derived Class " << endl; } 
};

int main() {
  Derived D1; 
  Base* B1 = &D1; 
  B1 -> print();
}