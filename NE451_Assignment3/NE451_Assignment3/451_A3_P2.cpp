//  NE451 Assignment3 Problem 2
//  2021-10-16
//  Kaylie Choi - 20692499

#include <iostream>
using namespace std;

class Rectangle {
    // private double precision members iLength/iWidth
    private:
        double iLength, iWidth;
    
    public:
        // public member functions to get and set iLength/iWidth
        double getLength() { return iLength; }
        double getWidth() { return iWidth; }
    
        void setLength( double uLength ) {
            iLength = uLength;
        }
        void setWidth( double uWidth ) {
            iWidth = uWidth;
        }
        
        // 2 arg constructor setting length and width to user specified uLength/uWidth
        Rectangle( double uLength, double uWidth ) {
            iLength = uLength;
            iWidth = uWidth;
        }
    
        // void function to calculate area, printing it through cout
        void area() {
            cout << getLength() * getWidth() << endl;
        }
};

int main() {
    Rectangle R( 10, 20 );
    R.area();
}
