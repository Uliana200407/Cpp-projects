

#ifndef LABWORK4_VECTOR_H
#define LABWORK4_VECTOR_H


class Vector {
private:
    double length;
    double angle;

public:
    Vector();
    Vector(double len, double ang);

    double getLength() const ;

    double getAngle() const ;

    void setLength(double len);

    void setAngle(double ang) ;

    void rotate(double ang);

    Vector operator+(const Vector &v) const ;

    Vector operator/(double n) const ;

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

};

#endif //LABWORK4_VECTOR_H
