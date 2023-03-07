//
// Created by mac on 02.03.2023.
//

#ifndef LABA_1_FUNCTIONS2_H
#define LABA_1_FUNCTIONS2_H
using namespace std;

string captureText2();
void replaceNumber2(int counter);
void getOutputChangedFile2(const std::string& filename);
void getChangedOperators2(int count);
void getOutputFile2(string &stringLine, string basicString);
std::string& getInputFile2(const std::string& filename, std::string& stringLine);
void changeOperator2(FILE *inputFile, FILE *outputFile, string stringLine, int *count);
#endif //LABA_1_FUNCTIONS2_H
