#ifndef LABA3_TRIANGLE_H
#define LABA3_TRIANGLE_H


#include "Point.h"

class Triangle {
private:
    Point point1;
    Point point2;
    Point point3;

public:
    Triangle(const Point &point1, const Point &point2, const Point &point3);
    Triangle();

    const Point &getPoint1() const;

    const Point &getPoint2() const;

    const Point &getPoint3() const;

    float getSquare() const {
        return 0.5*abs((point1.getX()*point2.getY()+point2.getX() * point3.getY() + point3.getX()*point1.getY())-(point1.getY()*point2.getX()+point2.getY()*point3.getX()+point3.getY()*point1.getX()));
    }
};


#endif //LABA3_TRIANGLE_H
