
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Functions.h"

Product ConvertStringToProduct(string line){
    int comaPosition = line.find(',');
    string name = line.substr(0, comaPosition - 0);
    int comaPosition2 = line.rfind(',');
    string productionDateString = line.substr(comaPosition + 1, comaPosition2 - comaPosition - 1);

    struct tm tm{};
    istringstream ss(productionDateString);
    ss >> get_time(&tm, "%d.%m.%y");

    time_t productionDate = mktime(&tm);


    int newLinePosition2 = line.rfind('\n');
    string expirationDateString = line.substr(comaPosition2 + 1, newLinePosition2 - comaPosition2);
    struct tm tm2{};
    istringstream ss2(expirationDateString);
    ss2 >> get_time(&tm2, "%d.%m.%y");
    time_t expirationDate = mktime(&tm2);

    struct Product product{name, productionDate, expirationDate};

    return product;
}

void RemoveExpiredProducts(time_t desirableDateUnix, const char *fileName){
    string line;
    ifstream File(fileName, ios::binary);
    ofstream FileTemp("temp.bin", ios::binary);
    while(getline(File,line)){
        Product product = ConvertStringToProduct(line);

        if(desirableDateUnix<=product.expirationDate){
            FileTemp << line << endl;
        }
    }

    File.close();
    FileTemp.close();
    remove(fileName);
    rename("temp.bin",fileName);
}

void RecordProducts(int linesCount , ofstream &File2, ofstream &File3, ofstream &File1, Product products[]) {
    for (int i = 0; i < linesCount; ++i) {
        RecordAll(File1, products, i);

        //432000 - 5 days in seconds
        if (products[i].expirationDate - products[i].productionDate < 432000) {
            string str = ConvertProductToString(products[i]);
            cout << "Product: " << str << " is perishable " << endl;
            RecordPerishable(File2, products, i);

            // Write the string to the file
        } else {
            string str = ConvertProductToString(products[i]);
            cout << "Product: " << str << " is nonperishable " << endl;
            RecordNonperishable(File3, products, i);
        }
    }
}

void RecordAll(ofstream &File1, Product products[], int i) {
    string str = ConvertProductToString(products[i]);
    int bufferSize = sizeof(str[0]) * str.size();
    File1.write((char *) &str[0], bufferSize);
}

string ConvertProductToString(Product product){
    struct tm *expiration_date;
    char buffer[80];
    expiration_date = localtime(&product.expirationDate);
    strftime(buffer, sizeof(buffer), "%d.%m.%Y", expiration_date);

    struct tm *production_date;
    char buffer2[80];
    production_date = localtime(&product.productionDate);
    strftime(buffer2, sizeof(buffer2), "%d.%m.%Y", production_date);
    string str = product.name + ',' + (buffer2) + ',' + (buffer) + '\n';

    return str;
}

void RecordNonperishable(ofstream &File3, Product products[], int i) {
    string productStr = ConvertProductToString(products[i]);

    int bufferSize = sizeof(productStr[0]) * productStr.size();
    File3.write((char *) &productStr[0], bufferSize);
}

void RecordPerishable(ofstream &File2, Product products[], int i) {
    string str = ConvertProductToString(products[i]);

    int bufferSize = sizeof(str[0]) * str.size();  // Define the buffer size for the string
    File2.write((char*)&str[0], bufferSize);
}

void GetProducts(string linesArray[], int linesCount, Product products[]) {
    for (int i = 0; i < linesCount; ++i) {
        Product product = ConvertStringToProduct(linesArray[i]);
        products[i] = product;
    }
}

void DivideLines(const string &text, int linesCount, string *linesArray) {
    int newLinePositionCounter = 0;
    for (int i = 0; i < linesCount; ++i) {
        int newLinePosition = text.find('\n', newLinePositionCounter+1);
        string NewText;

        if(i == 0){
             NewText = text.substr(newLinePositionCounter, newLinePosition-newLinePositionCounter);
        }
        else{
             NewText = text.substr(newLinePositionCounter+1, newLinePosition-newLinePositionCounter-1);
        }


        newLinePositionCounter = text.find('\n', newLinePositionCounter+1);
        linesArray[i] = NewText;
    }
}

string captureText(){
    cout << "Enter your text here (an example is - yogurt,21.03.2023,27.03.2023);\nPress Enter to go to the next line;\nPress '-' + Enter on the new line to end the writing;\n";
    string text;
    string line;
    // ascii код символу "-"
    int asciiCode = 45;
    // поки першиq символ строки не "-"
    while(int(line[0]) != asciiCode){
        getline(cin, line);
        text += line +'\n';
    }
    // відкидаємо 3 зайвих символи (2 зайвих \n і '-')
    text = text.substr(0, text.size()-2);

    cout << "Entered products: " << text << endl;

    return text;
}