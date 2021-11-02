#include <iostream>
using namespace std;

int main () {
  // gives error
  // const int j[4] = {1, 2, 3, 4};
  // int *k = &j;

  // fixed
  int j[4] = {1, 2, 3, 4};
  int *k = j;

  k[2] = 10;
  cout << j[2] << endl;
}