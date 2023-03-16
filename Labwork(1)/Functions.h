
using namespace std;

#ifndef LABA_1_FUNCTIONS_H
#define LABA_1_FUNCTIONS_H

string captureText();

void replaceNumber(int counter);

void getOutputChangedFile(fstream &outputFile, string &stringLine);

void getChangedOperators(int count);

void getOutputFile();
string &getInputFile(ifstream &inputFile,string &stringLine);

void changeOperator(ifstream &inputFile,fstream &outputFile,string &stringLine, int &count);
void FilePointerFunctions();
void FileStreamFunctions();
#endif //LABA_1_FUNCTIONS_H
