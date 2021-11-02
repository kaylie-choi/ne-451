#include <iostream>
using namespace std;

void blah(int *aI, int *aJ) {
  *aJ = 20;
  aI = aJ;
}

int main () {
  int j = 10;
  int k = 15;
  blah(&j, &k);

  cout << j << '\t' << k << endl;
}