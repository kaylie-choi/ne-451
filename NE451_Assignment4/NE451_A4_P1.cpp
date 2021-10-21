//  NE451 Assignment 4 Problem 1
//  2021-10-21
//  Kaylie Choi - 20692499

#include <iostream>
using namespace std;

// a recursive fn that computes sqrt(2) for 1-10 terms 
// in the continued fraction
int main ( ) {
  // values n between 1 and 10
  int maxLoop = 10;

  for ( int n = 1; n < maxLoop; n++ ){
    double root = 0;

    // fraction expansion of (sqrt(2) - 1)
    for ( int loop = 0; loop < n; loop++ ){ 
      root = 1. / ( 2. + root );
    }

    // add 1 back in to get sqrt(2)
    cout << "n=" << n << ": " << 1. + root << endl; 
  }
}