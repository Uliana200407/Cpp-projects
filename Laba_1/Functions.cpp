
#include <string>
#include <fstream>
#include <iostream>
#include "Functions.h"
#include "Functions2.h"

using namespace std;

string captureText(){
cout << "Enter your text here :\nPress Enter to go to the next line\nPress '-' + Enter on the new line to end writing\n";
    string text;
    string line;
    // ascii код символу "-"
    int asciiCode = 45;
    // поки першиq символ строки не "-"
    while(int(line[0]) != asciiCode){
        getline(cin, line);
        text += line +'\n';
    }
    // відкидаємо 3 зайвих символи (2 зайвих \n і ^D)
    text = text.substr(0, text.size()-3);

    return text;
}

void replaceNumber(int counter){
    fstream fileRead("output.txt");
    string text;
    string line;

    while (getline(fileRead, line))
    {
        text += line + '\n';
    }
    fileRead.close();

    text = text.substr(0, text.size() - 1);
    int lastSpace = text.rfind(' ') ;
    int lastPositionSemicolon = text.rfind(';');
    int lengthTheLastNumber = lastPositionSemicolon - lastSpace - 1;

    text.replace(lastSpace + 1, lengthTheLastNumber, to_string(counter));

    ofstream fileWrite("output.txt");
    fileWrite << text;
    fileWrite.close();
}

void getOutputChangedFile(fstream &outputFile,string &stringLine) {
    cout << "\nOutput after changing file:\n";
    outputFile.open("output.txt");
    while (getline(outputFile, stringLine))
    {
        cout << stringLine << "\n";
    }
    outputFile.close();

}

void getChangedOperators(int count) {cout << "\nNumber of changed operators: " << count << "\n"; }



void getOutputFile() {
    ifstream inputFile("output.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    cout << "\nOutput before changing file:\n";

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
}

string &getInputFile(ifstream &inputFile, string &stringLine) {
    cout << "Input file:\n";
    inputFile.open("input.txt");
    while (getline(inputFile, stringLine))
    {
        cout << stringLine << "\n";
    }
    inputFile.close();
    return stringLine;
}

void changeOperator(ifstream &inputFile, fstream &outputFile,string &stringLine, int &count) {
    while (getline(inputFile, stringLine))
    {
        // перевіряємо, чи містить рядок оператор присвоєння виду "змінна = змінна + число;"
        size_t pos = stringLine.find(" = ");

        if (pos != string::npos && stringLine.find('+') != string::npos) //npos the biggest value of size_t
        {
            // замінюємо оператор на "змінна += число;"

            int firstElementPos = 0;
            int firstSpace = stringLine.find(' ');
            int quantityOfLetters = firstSpace - firstElementPos;
            stringLine.replace(pos, quantityOfLetters + 6, " += ");
            count++;

        }

        // записуємо рядок у вихідний файл
        outputFile << stringLine << "\n";

    }
}
void FileStreamFunctions() {
    string user_input = captureText();
    ofstream inputFileToWrite("input.txt");
    inputFileToWrite << user_input;
    inputFileToWrite.close();

    ifstream inputFile("input.txt");// for reading
    fstream outputFile("output.txt");//for writing

    string stringLine;
    int count = 0;

    changeOperator(inputFile, outputFile, stringLine, count);//кінець

    inputFile.close();
    outputFile.close();

    stringLine = getInputFile(inputFile, stringLine);

    getOutputFile();
    getChangedOperators(count);

    replaceNumber(count);

    getOutputChangedFile(outputFile, stringLine);
}

void FilePointerFunctions() {
    string user_input = captureText2();
    FILE* inputFileToWrite = fopen("input.txt", "w");

    fprintf(inputFileToWrite, "%s\n", user_input.c_str());

    fclose(inputFileToWrite);

    FILE* inputFile = fopen("input.txt", "r");

    FILE* outputFile = fopen("output.txt", "w");

    string stringLine;
    int count = 0;

    changeOperator2(inputFile, outputFile ,user_input, &count);

    fclose(inputFile);
    fclose(outputFile);

    getInputFile2("input.txt", stringLine);
    getOutputFile2((string &) "output.txt", stringLine);
    getChangedOperators2( count);
    replaceNumber2( count);
    getOutputChangedFile2( "output.txt");
}
