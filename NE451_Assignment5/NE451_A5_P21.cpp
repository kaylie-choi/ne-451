#include <iostream>
using namespace std;

int *myFunction (int *aI, int *aJ) {
  *aI = *aI * (*aJ);
  return aI;
}

int main () {
  // gives error
  // int *aI;
  // int *aJ;
  // *aI = 2;
  // *aJ = 3;

  // fixed
  int I = 2;
  int J = 3;
  int *aI = &I;
  int *aJ = &J;

  cout << (*myFunction (aI, aJ)) << endl;

}