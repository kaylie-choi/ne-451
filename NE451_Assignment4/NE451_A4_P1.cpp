//  NE451 Assignment 4 Problem 1
//  2021-10-23
//  Kaylie Choi - 20692499

#include <iostream>
using namespace std;

// a recursive fn that computes sqrt(2) for 1-10 terms 
// in the continued fraction

double continuedFraction ( int n ) {
  
  const int maxIter = 10;

  // for values n between 1 and 10
    if ( n <= maxIter && n > 1 ) {
        return ( 1 / ( 2 + continuedFraction( n - 1 ) ) );
    }
    else {
        return 1. / 2.;
    }
}

int main () {

  int n;
  cout << "number of fractional terms, n: ";
  cin >> n;
  double approximation = continuedFraction(n);

  // add 1 back in to get sqrt(2)
  cout << "n = " << n << "  approximation = " << 1. + approximation << endl;

}
