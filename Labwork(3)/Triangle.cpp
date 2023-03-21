//
// Created by mac on 04.02.2023.
//
// Розробити клас трикутник на площині,
// який заданий   координатами вершин.Створити масив об*єктів даного класу.
// Визначити трикутник з найбільшою площею.
#include "Triangle.h"

Triangle::Triangle(const Point &point1, const Point &point2, const Point &point3) : point1(point1), point2(point2),
                                                                                    point3(point3) {}

Triangle::Triangle(): point1(0,0),point2(0,0), point3(0,0){

}

const Point &Triangle::getPoint1() const {
    return point1;
}

const Point &Triangle::getPoint2() const {
    return point2;
}

const Point &Triangle::getPoint3() const {
    return point3;
}
