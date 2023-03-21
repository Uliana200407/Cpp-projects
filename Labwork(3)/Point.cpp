#include "Point.h"

#include <utility>

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const {
    return x;
}

void Point::setX(float x) {
    Point::x = x;
}

float Point::getY() const {
    return y;
}

void Point::setY(float y) {
    Point::y = y;
}
