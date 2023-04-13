#include <iostream>
#include "Functions.h"

Vector CreateVector(){
    double len, ang;
    char ch,error;

    symbolCheckingWithMinus(error, ch, len,"Enter the length: ");
    symbolChecking(error, ch, ang,"Enter the angle (in radians): ");
    Vector vector(len, ang);

    return vector;
}

void symbolChecking(char error, char &ch, double &x1, std::string text) {
    do
    {
        error=0;
        std::cout << text;
        scanf("%lf%c",&x1,&ch);
        if (ch!='\n')
        {
            error = 1;
            fflush(stdin);
            printf("Error inputting\n");
        }
        ch = 0;

    }
    while(error);
}

void symbolCheckingWithMinus(char error, char &ch, double &x1, std::string text) {
    do
    {
        error=0;
        std::cout << text;
        scanf("%lf%c",&x1,&ch);
        if (ch!='\n' || (x1<0))
        {
            error = 1;
            fflush(stdin);
            printf("Error inputting\n");
        }
        ch = 0;

    }
    while(error);
}
