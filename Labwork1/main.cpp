#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Functions2.h"
#include "Functions.h"

using namespace std;

int main(int argc, char * argv[])
{
    if(strcmp(argv[2], "FilePointer") == 0){
        FilePointerFunctions();

    }
    else if(strcmp(argv[2], "FileStream") == 0){
        FileStreamFunctions();

    }
    else{
        cout<<"Irregular expression"<< endl;
    }
}

