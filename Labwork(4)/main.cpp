#include <iostream>
#include <cmath>
#include "Functions.h"
using namespace std;



int main() {
    Vector v1, v2, v3;

    cout<<"\t\t\t\tINITIAL DATA:"<< endl;
    cout << "Vector 1 is initialized with empty constructor." << std::endl;
    cout << "Enter vector 2:" << endl;
    v2 = CreateVector();
    cout << "Enter vector 3:" << endl;
    v3 = CreateVector();
    cout<<"------------------------------------------------"<<endl;
    cout<<"\t\t\t\tENTERED VECTORS: \n" <<v1<<"\n"<<v2<<"\n"<<v3<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"\t\t\t\tINTERIM RESULTS:"<< endl;
    v3.rotate(M_PI / 4);
    cout << "Vector 3 after rotation: " << v3<< endl;
    v2 = v2 / 2;
    cout<<"Vector 2 after dividing : "<< v2<< endl;
    v1 = v2 + v3;
    cout<<"Vector 1 after summing the first and the second one : "<< v1<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"\t\t\t\tFINAL RESULTS:" << endl;
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    cout << "Vector 3: " << v3 << endl;
    return 0;
}
