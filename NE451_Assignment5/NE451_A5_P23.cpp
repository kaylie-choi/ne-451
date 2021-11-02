#include <iostream>
using namespace std;

ostream* hullo(ostream *aOut) {
  *(aOut) << "Hello" << endl;
  return aOut;
}

int main () {
  hullo(hullo(&cout));
}