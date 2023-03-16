
#include <iostream>
#include <cstring>
#include <string>
#include "Functions2.h"
using namespace std;
char* captureText2(){
    std::cout << "Enter your text here :\nPress Enter to go to the next line\nPress '-' + Enter on the new line to end writing\n";
    char* text = new char[1000];
    char* line = new char[1000];
    int text_len = 0;
    int line_len = 0;
    // ascii код символу "-"
    int asciiCode = 45;
    // поки перший символ строки не "-"
    while((line_len == 0) || (line[0] != asciiCode)){
        std::cin.getline(line, 1000);
        int i = 0;
        while(line[i] != '\0'){
            text[text_len] = line[i];
            text_len++;
            i++;
        }
        text[text_len] = '\n';
        text_len++;
        line_len = i;
    }
    // відкидаємо 3 зайвих символи (2 зайвих \n і ^D)
    text[text_len-3] = '\0';

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

    int lastSpace = -1;
    int lastPositionSemicolon = -1;

    for (int i = fileSize - 1; i >= 0; i--) {
        if (text[i] == ' ' && lastSpace == -1) {
            lastSpace = i;
        } else if (text[i] == ';' && lastPositionSemicolon == -1) {
            lastPositionSemicolon = i;
        }
        if (lastSpace != -1 && lastPositionSemicolon != -1) {
            break;
        }
    }

    int lengthTheLastNumber = lastPositionSemicolon - lastSpace - 1;

    char* newNumber = new char[10];
    int newNumberSize = sprintf(newNumber, "%d", counter);

    char* newText = new char[fileSize - lengthTheLastNumber + newNumberSize + 1];
    std::memset(newText, 0, fileSize - lengthTheLastNumber + newNumberSize + 1);

    std::memcpy(newText, text, lastSpace + 1);
    std::memcpy(newText + lastSpace + 1, newNumber, newNumberSize);
    std::memcpy(newText + lastSpace + newNumberSize + 1, text + lastPositionSemicolon, fileSize - lastPositionSemicolon);

    delete[] text;
    delete[] newNumber;

    FILE* fileWrite = fopen("output.txt", "w");
    if (fileWrite == NULL) {
        cout << "Error opening file for writing." << std::endl;
        return;
    }

    fwrite(newText, sizeof(char), fileSize - lengthTheLastNumber + newNumberSize, fileWrite);

    fclose(fileWrite);
    delete[] newText;
}

void getOutputChangedFile2(const char* filename) {
    std::cout << "\nOutput after changing file:\n";

    FILE* file = fopen(filename, "r");

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



void getOutputFile2(char* stringLine) {
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



char* getInputFile2(const char* filename) {
    std::cout << "Input file:\n";
    FILE* file = fopen(filename, "r");

    if (file == nullptr) {
        std::cout << "Error opening file." << std::endl;
        return nullptr;
    }

    char* stringLine = new char[1];
    stringLine[0] = '\0';

    char buffer[1024];
    while (fgets(buffer, 1024, file) != nullptr) {
        std::cout << buffer;
        char* newString = new char[strlen(stringLine) + strlen(buffer) + 1];
        std::strcpy(newString, stringLine);
        std::strcat(newString, buffer);
        delete[] stringLine;
        stringLine = newString;
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
