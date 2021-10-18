//  NE451 Assignment3 Problem 1
//  2021-10-16
//  Kaylie Choi - 20692499

#include <iostream>
using namespace std;

class Semiconductor {
    // private: is implicit
    double iElectronDensity, iHoleDensity, iIntrinsicCarrierDensity;

    public:
        double electronDensity() { return iElectronDensity; } //n
        double holeDensity() { return iHoleDensity; } //p
        double intrinsicCarrierDensity() { return iIntrinsicCarrierDensity; } //ni; read-only

        void setElectronDensity( double aElectronDensity ) {
            iElectronDensity = aElectronDensity;
            // p = ni^2/n
            iHoleDensity = (iIntrinsicCarrierDensity*iIntrinsicCarrierDensity) / iElectronDensity;
        }
    
        void setHoleDensity( double aHoleDensity ) {
            iHoleDensity = aHoleDensity;
            // n = ni^2/p
            iElectronDensity = (iIntrinsicCarrierDensity*iIntrinsicCarrierDensity) / iHoleDensity;
        }

        // one-element constructor that sets intrinsic carrier density
        Semiconductor( double aIntrinsicCarrierDensity ) {
            iIntrinsicCarrierDensity = aIntrinsicCarrierDensity;
        }
    
        void print() {
            cout << "Electron Density (n): " << iElectronDensity << endl;
            cout << "Hole Density (p): " << iHoleDensity << endl;
            cout << "Intrinsic Carrier Density (ni): " << iIntrinsicCarrierDensity << endl;
        }
};


int main() {
    Semiconductor Silicon( 1.5e10 );
    Silicon.setElectronDensity( 1.e10 );
//    Silicon.setHoleDensity( 2.25e10 );

    Silicon.print( );
}
