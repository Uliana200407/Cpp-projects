
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "TSystemLinearEquation.h"
#include "TSystem2LinearEquation.h"
#include "TSystemL3inearEquation.h"

int main(){
    srand(time(0));

    TSystem2LinearEquation solver2;
    solver2.solve();
    TSystem3LinearEquation solver3;
    solver3.solve();

}