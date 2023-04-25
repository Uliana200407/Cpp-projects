
#include "TSystemLinearEquation.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "TSystem2LinearEquation.h"

TSystem2LinearEquation::TSystem2LinearEquation(){
    generateCoefficients();
}

void TSystem2LinearEquation::solve() {
    cout<<"GENERATED COEFFICIENTS FOR T SYSTEM2LINEAR EQUATION"<<endl;
    cout << "a1: " << a1 << "; b1: " << b1 << "; c1: " << c1<<";"<<endl;
    cout << "a2: " << a2 << "; b2: " << b2 << "; c2: " << c2<<";"<<endl;
    // Find the determinant of the coefficient matrix
    det = a1*b2 - a2*b1;
    bool isSolutionAvailable = CheckSolution(det);

    if(!isSolutionAvailable)
    {
        cout << "The system has no unique solution." << endl;
    }
    else
    {
        // Find the determinants of the x and y matrices
        det_x = c1*b2 - c2*b1;
        det_y = a1*c2 - a2*c1;
        cout<<"Determinants are: "<<"det_x: "<<det_x<<", det_y: "<<det_y<<endl;

        // Calculate the values of x and y
        x = det_x/det;
        y = det_y/det;

        // Display the values of x and y
        cout << "The solution of the system is: x = " << x << ", y = " << y << endl;
        cout<<"-----------------------------------------------------"<<endl;

    }
}

void TSystem2LinearEquation::generateCoefficients() {
    a1 = rand() % 30 + 1;
    b1 = rand() % 30 + 1;
    c1 = rand() % 30 + 1;
    a2 = rand() % 30 + 1;
    b2 = rand() % 30 + 1;
    c2 = rand() % 30 + 1;
}

bool TSystem2LinearEquation::CheckSolution(float det) const {
    if(det == 0){
        return false;
    } else{
        return true;
    }
}



