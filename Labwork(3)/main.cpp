#include "functions.h"
using namespace std;


int main() {
    int quantity = GetTriangleQuantity();
    Triangle *trianglesVector = InputTriangle(quantity);
    ShowTriangles(trianglesVector,  quantity);
    Triangle theBiggestSquare = FindTheBiggestSquare(trianglesVector,quantity);
    printf("\n\nThe biggest square of triangle is: %.2f\n", theBiggestSquare.getSquare());
    printf("\t\t\tCoordinates:\n");
    printf("First point coordinates are: %.2f,%.2f\n", theBiggestSquare.getPoint1().getX(), theBiggestSquare.getPoint1().getY());
    printf("Second point coordinates: %.2f,%.2f\n", theBiggestSquare.getPoint2().getX(), theBiggestSquare.getPoint2().getY());
    printf("Third point coordinates: %.2f,%.2f", theBiggestSquare.getPoint3().getX(), theBiggestSquare.getPoint3().getY());
}
