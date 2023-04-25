
#ifndef LABWORK5_TSYSTEMLINEAREQUATION_H
#define LABWORK5_TSYSTEMLINEAREQUATION_H

class TSystemLinearEquation{
protected:
    virtual void generateCoefficients() = 0;
    virtual void solve ()  = 0;

    float a1;
    float a2;
    float b1;
    float b2;
    float c1;
    float c2;
    float det;
    float det_x;
    float det_y;
    float x;
    float y;
};

#endif //LABWORK5_TSYSTEMLINEAREQUATION_H
