

#ifndef LABWORK5_TSYSTEML3INEAREQUATION_H
#define LABWORK5_TSYSTEML3INEAREQUATION_H

#include <cstdlib>
#include "TSystemLinearEquation.h"
#include <iostream>
using namespace std;

class TSystem3LinearEquation : public TSystemLinearEquation{
private:
    float d1{}, d2{}, a3{}, b3{}, c3{}, d3{}, det_z{}, z{};
public:
    TSystem3LinearEquation();
    void solve() override;
private:
    void generateCoefficients() override;
    static bool CheckSolution(float det);
};

#endif //LABWORK5_TSYSTEML3INEAREQUATION_H
