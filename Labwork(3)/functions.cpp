#include <vector>
#include "Triangle.h"
#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int GetTriangleQuantity(){
    char ch,error;
    int quantityTriangles;

    do
    {
        error=0;
        printf("Enter quantity of triangles: "); //checking symbols
        scanf("%d%c",&quantityTriangles,&ch);
        if ((ch!='\n')||(quantityTriangles<=0))//checking buffering zone inputting (stdin) + substracrion check
        {
            error = 1;
            fflush(stdin);
            printf("Error inputting\n");
        }
        ch = 0;

    }
    while(error);

    return quantityTriangles;
}
Triangle* InputTriangle(int quantity) {
    //Triangle trianglesVector[quantity];
    Triangle *trianglesVector = new Triangle[quantity];

    char ch,error;
    for (int i = 0; i < quantity; ++i) {
        cout << "Enter triangle #" << i+1 << endl;
        float x1;
        symbolChecking(error, ch, x1, "Enter 1st point x: ");
        float y1;
        symbolChecking(error, ch, y1,"Enter 1st point y: ");
        float x2;
        symbolChecking(error, ch, x2,"Enter 2nd point x: ");
        float y2;
        symbolChecking(error, ch, y2,"Enter 2nd point y: ");
        float x3;
        symbolChecking(error, ch, x3,"Enter 3d point x: ");
        float y3;
        symbolChecking(error, ch, y3,"Enter 3d point y: ");

        Point point1(x1,y1);
        Point point2(x2,y2);
        Point point3(x3,y3);
        Triangle newTriangle(point1,point2,point3);
        trianglesVector[i] = newTriangle;
    }
    return trianglesVector;
}

void symbolChecking(char error, char &ch, float &x1, std::string text) {
    do
    {
        error=0;
        cout<< text;
        scanf("%f%c",&x1,&ch);
        if (ch!='\n')//checking buffering zone inputting (stdin) + substracrion check
        {
            error = 1;
            fflush(stdin);
            printf("Error inputting\n");
        }
        ch = 0;

    }
    while(error);
}

Triangle FindTheBiggestSquare(Triangle biggestSquare[], int arraySize){
    Triangle largestTriangle = biggestSquare[0];

    for (int i = 1; i < arraySize; ++i) {
        if(biggestSquare[i].getSquare() > largestTriangle.getSquare()){
            largestTriangle = biggestSquare[i];
        }
    }
    return largestTriangle;
}

void ShowTriangles(Triangle triangles[], int arraySize) {
    cout << "Array of triangles:" << endl;

    for (int i = 0; i < arraySize; ++i) {
        printf("\n----------------------------------------");
        printf("\n\t\tInfo about triangle %d\n", i+1);
        printf("Square of triangle is: %.2f\n", triangles[i].getSquare());

        printf("\t\t\tCoordinates:\n");
        printf("First point coordinates are: %.2f,%.2f\n", triangles[i].getPoint1().getX(), triangles[i].getPoint1().getY());
        printf("Second point coordinates: %.2f,%.2f\n", triangles[i].getPoint2().getX(), triangles[i].getPoint2().getY());
        printf("Third point coordinates: %.2f,%.2f", triangles[i].getPoint3().getX(), triangles[i].getPoint3().getY());
    }
    printf("\n----------------------------------------");
}