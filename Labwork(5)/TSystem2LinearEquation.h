

#ifndef LABWORK5_TSYSTEM2LINEAREQUATION_H
#define LABWORK5_TSYSTEM2LINEAREQUATION_H

#include <cstdlib>
#include "TSystemLinearEquation.h"
#include <iostream>
using namespace std;
class TSystem2LinearEquation : public TSystemLinearEquation{
public:
    TSystem2LinearEquation();
    void solve() override;
private:
    void generateCoefficients() override;
    bool CheckSolution(float det) const;
};

#endif //LABWORK5_TSYSTEM2LINEAREQUATION_H
