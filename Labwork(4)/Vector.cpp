
#include <iostream>
#include "cmath"
#include "Vector.h"


Vector::Vector() {
    length = 0;
    angle = 0;


}
Vector::Vector(double len, double ang) {
    length = len;
    angle = ang;
}

double Vector::getLength() const {
    return length;
}

double Vector::getAngle() const {
    return angle;
}

void Vector::setLength(double len) {
    length = len;
}

void Vector::setAngle(double ang) {
    angle = ang;
}

void Vector::rotate(double ang) {
    angle += ang;
}

Vector Vector:: operator+(const Vector &v) const {
    double x = length * cos(angle) + v.length * cos(v.angle);
    double y = length * sin(angle) + v.length * sin(v.angle);
    double len = sqrt(x*x + y*y);
    double ang = atan2(y, x);
    return Vector(len, ang);
}

Vector Vector:: operator/(double n) const {
    return Vector(length / n, angle);
}


std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "Vector: (" << v.getLength() << ", " << v.getAngle() << ")";
    return os;
}

