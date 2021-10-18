//
//  NE451 Assignment3 Problem 1
//
//  2021-10-16
//  Kaylie Choi
//  20692499
//

#include <iostream>
#include <math.h>

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
//            cout << "setElectronDensity: " << iElectronDensity << endl;
        }
    
        void setHoleDensity( double aHoleDensity ) {
            iHoleDensity = aHoleDensity;
//            cout << "setHoleDensity: " << iHoleDensity << endl;
        }

        // one-element constructor that sets intrinsic carrier density
        Semiconductor( double aIntrinsicCarrierDensity ) {
            iIntrinsicCarrierDensity = aIntrinsicCarrierDensity;
        }
    
        void print() {
            
            // np = ni^2 -> n = ni^2/p ; p = ni^2/n
            if ( !iElectronDensity )
                iElectronDensity = (iIntrinsicCarrierDensity*iIntrinsicCarrierDensity) / iHoleDensity;
            else
                iHoleDensity = (iIntrinsicCarrierDensity*iIntrinsicCarrierDensity) / iElectronDensity;
            
            cout << "Electron Density (n): " << iElectronDensity << endl;
            cout << "Hole Density (p): " << iHoleDensity << endl;
            cout << "Intrinsic Carrier Density (ni): " << iIntrinsicCarrierDensity << endl;
        }
};


int main() {
    Semiconductor Silicon( 1.5e10 );
//    Silicon.setElectronDensity( 1.e10 );
    Silicon.setHoleDensity( 2.25e10 );

    Silicon.print( );
}
