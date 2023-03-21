#include "Triangle.h"

#ifndef LABA3_FUNCTIONS_H
#define LABA3_FUNCTIONS_H
#endif //LABA3_FUNCTIONS_H

int GetTriangleQuantity();
Triangle* InputTriangle(int quantity)  ;
Triangle FindTheBiggestSquare(Triangle biggestSquare[], int arraySize);
void symbolChecking(char error, char &ch, float &x1, std::string text) ;
void ShowTriangles(Triangle triangles[], int arraySize);