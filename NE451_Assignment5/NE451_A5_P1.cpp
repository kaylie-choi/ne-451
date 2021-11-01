//  NE451 Assignment 5 Problem 1
//  2021-11-01
//  Kaylie Choi - 20692499

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inputFile("matrices.txt");

int main() {

  // initialize memory allocation of matrices
  int **mA1, **mA2, **C;

  // mA1 -----
  // dynamically allocate array of pointers to arrays 
  mA1 = new int*[2];
  for ( int i = 0; i < 2; i++ ) {
    mA1[i] = new int[2];
  }
  // populate mA1 from input file
  for ( int i = 0; i < 2; i++ ) {
    for ( int j = 0; j < 2; j++  ) {
      inputFile >> mA1[i][j];
      cout << "mA1: " << mA1[i][j] << endl;
    }
  }

  // mA2 -----
  // dynamically allocate array of pointers to arrays 
  mA2 = new int*[2];
  for ( int i = 0; i < 2; i++ ) {
    mA2[i] = new int[2];
  }
  // populate mA2 from input file
  for ( int i = 0; i < 2; i++ ) {
    for ( int j = 0; j < 2; j++  ) {
      inputFile >> mA2[i][j];
      cout << "mA2: " << mA2[i][j] << endl;
    }
  }

  // set transpose of mA2
  int mA2t[2][2];
  for ( int i = 0; i < 2; i++ ) {
      for ( int j = 0; j < 2; j++ ) {
        mA2t[i][j] = mA2[j][i]; 
        cout << "mA2 transpose: " << mA2t[i][j] << endl;
      }
  }
  
  // C : third dynamically allocated matrix -----
  // dynamically allocate array of pointers to arrays 
  C = new int*[2];
  for ( int i = 0; i < 2; i++ ) {
    C[i] = new int[2];
  }

  // matrix multiplication -> mA1 * mA2t, storing result in C
  for ( int i = -1; ++i < 2; ) {
    for ( int j = -1; ++j < 2; ) {
      for ( int k = -1; ++k < 2; ) {
        C[i][j] += mA1[i][k] * mA2t[j][k];
      }
    } 
  }

  // resultant matrix 
  for ( int i = 0; i < 2; i++ ) {
    for ( int j = 0; j < 2; j++ ) {
      cout << "coordinates: [" << i+1 << "][" << j+1 << "] = " << C[i][j] << endl;
    }
  }

  // deallocate space reserved for dynamically allocated matrices 
  for (int i = 0; i < 2; i++) {
    delete [] mA1[i];
    delete [] mA2[i];
    delete [] C[i];
  }
  delete [] mA1;
  delete [] mA2;
  delete [] C;

}
