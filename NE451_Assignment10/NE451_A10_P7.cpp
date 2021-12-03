//  NE451 Assignment 10 Problem 7
//  2021-12-03
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"

using namespace std;

static int b=3;

int myFun(int &i){ 
  static int b;
  b+=i;
  return(b);
}

int main() {
  int n = 2; 
  myFun(n);
  cout << myFun(n); 
}