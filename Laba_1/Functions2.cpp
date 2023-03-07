
#include <iostream>
#include <cstring>
#include <string>
#include "Functions2.h"
using namespace std;
string captureText2(){
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

void replaceNumber2(int counter) {
    FILE* fileRead = fopen("output.txt", "r");
    if (fileRead == NULL) {
        std::cout << "Error opening file for reading." << std::endl;
        return;
    }
    fseek(fileRead, 0, SEEK_END);
    long fileSize = ftell(fileRead);
    rewind(fileRead);

    char* text = new char[fileSize + 1];
    std::memset(text, 0, fileSize + 1);

    fread(text, sizeof(char), fileSize, fileRead);

    fclose(fileRead);

    int lastSpace = string(text).rfind(' ');
    int lastPositionSemicolon = string(text).rfind(';');
//    int lengthTheLastNumber = lastPositionSemicolon - lastSpace - 1;

    string newText = string(text).substr(0, lastSpace + 1) + std::to_string(counter) + std::string(text).substr(lastPositionSemicolon);
    delete[] text;

    FILE* fileWrite = fopen("output.txt", "w");
    if (fileWrite == NULL) {
        cout << "Error opening file for writing." << std::endl;
        return;
    }

    fwrite(newText.c_str(), sizeof(char), newText.size(), fileWrite);

    fclose(fileWrite);
}
void getOutputChangedFile2(const std::string& filename) {
    std::cout << "\nOutput after changing file:\n";

    FILE* file = fopen(filename.c_str(), "r");

    if (file == nullptr) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file) != nullptr) {
        std::cout << buffer;
    }

    fclose(file);
}

void getChangedOperators2(int count) {cout << "\nNumber of changed operators: " << count << "\n"; }



void getOutputFile2(string &stringLine, string basicString) {
    FILE *outputFile;
    char line[1000];

    outputFile = fopen("output.txt", "r");

    if (outputFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nOutput before changing file:\n");

    while (fgets(line, 1000, outputFile)) {
        printf("%s\n", line);
    }

    fclose(outputFile);
}


std::string& getInputFile2(const std::string& filename, std::string& stringLine) {
    std::cout << "Input file:\n";

    FILE* file = fopen(filename.c_str(), "r");

    if (file == nullptr) {
        std::cout << "Error opening file." << std::endl;
        return stringLine;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file) != nullptr) {
        std::cout << buffer;
        stringLine += buffer;
    }

    fclose(file);
    return stringLine;
}
void changeOperator2(FILE *inputFile, FILE *outputFile, string stringLine, int *count) {
    char c;
    int i = 0;
    while ((c = fgetc(inputFile)) != EOF) {
        if (c == '\n') {
            stringLine[i] = '\0';
            i = 0;

            // перевіряємо, чи містить рядок оператор присвоєння виду "змінна = змінна + число;"
            size_t pos = stringLine.find(" = ");

            if (pos != string::npos && stringLine.find('+') != string::npos) //npos the biggest value of size_t
            {
                // замінюємо оператор на "змінна += число;"
                int firstElementPos = 0;
                int firstSpace = stringLine.find(' ');
                int quantityOfLetters = firstSpace - firstElementPos;
                stringLine.replace(pos, quantityOfLetters + 6, " += ");
                (*count)++;
            }

            // записуємо рядок у вихідний файл
            fprintf(outputFile, "%s\n", stringLine.c_str());
        } else {
            stringLine[i++] = c;
        }
    }
}