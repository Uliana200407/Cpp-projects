#ifndef LABA3_POINT_H
#define LABA3_POINT_H
#include <string>

class Point {
private:
public:
    Point(float x, float y);

private:
    float x;
    float y;
public:
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

};


#endif //LABA3_POINT_H
