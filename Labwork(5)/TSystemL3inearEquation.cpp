

#include "TSystem2LinearEquation.h"
#include "TSystemLinearEquation.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "TSystemL3inearEquation.h"

TSystem3LinearEquation::TSystem3LinearEquation(){
    generateCoefficients();
}

void TSystem3LinearEquation::solve(){
    cout<<"GENERATED COEFFICIENTS FOR T SYSTEM3LINEAR EQUATION"<<endl;
    cout << "a1: " << a1 << "; b1: " << b1 << "; c1: " << c1<< "; d1: " << d1<<";"<<endl;
    cout << "a2: " << a2 << "; b2: " << b2 << "; c2: " << c2<< "; d2: " << d2<<";"<<endl;
    cout << "a3: " << a3 << "; b3: " << b3 << "; c3: " << c3<< "; d3: " << d3<<";"<<endl;
    det = a1*b2*c3 + b1*c2*a3 + c1*a2*b3 - c1*b2*a3 - b1*a2*c3 - a1*c2*b3;
    bool isSolutionAvailable = CheckSolution(det);
    if(!isSolutionAvailable)
    {
        cout << "The system has no unique solution." << endl;
    }
    else
    {
        // Find the determinants of the x, y, and z matrices
        det_x = d1*b2*c3 + b1*c2*d3 + c1*d2*b3 - c1*b2*d3 - b1*d2*c3 - d1*c2*b3;
        det_y = a1*d2*c3 + d1*c2*a3 + c1*a2*d3 - c1*d2*a3 - d1*a2*c3 - a1*c2*d3;
        det_z = a1*b2*d3 + b1*d2*a3 + d1*a2*b3 - d1*b2*a3 - b1*a2*d3 - a1*d2*b3;
        cout<<"Determinants are: "<<"det_x: "<<det_x<<", det_y: "<<det_y<<", det_z: "<<det_z<<endl;

        // Calculate the values of x, y, and z
        x = det_x/det;
        y = det_y/det;
        z = det_z/det;

        // Display the values of x, y, and z
        cout << "The solution of the system is: x = " << x << ", y = " << y << ", z = " << z << endl;
    }
}

void TSystem3LinearEquation::generateCoefficients() {
    a1 = rand() % 30 + 1;
    b1 = rand() % 30 + 1;
    c1 = rand() % 30 + 1;
    d1 = rand() % 30 + 1;
    a2 = rand() % 30 + 1;
    b2 = rand() % 30 + 1;
    c2 = rand() % 30 + 1;
    d2 = rand() % 30 + 1;
    a3 = rand() % 30 + 1;
    b3 = rand() % 30 + 1;
    c3 = rand() % 30 + 1;
    d3 = rand() % 30 + 1;
}

bool TSystem3LinearEquation::CheckSolution(float det)  {
    if(det == 0){
        return false;
    } else{
        return true;
    }
}