
#include "Functions.h"

int main() {
    time_t desirableDateUnix = time(0);

    int choice;
    cout << "Enter 1, if you want to use appending, otherwise enter any number here: ";
    cin >> choice;

    ofstream File1;
    ofstream File2;
    ofstream File3;

    if (choice == 1) {
        File1.open("productList.bin", ios::app | ios::binary);
        File2.open("perishableProducts.bin", ios::app | ios::binary);
        File3.open("nonperishableProducts.bin", ios::app | ios::binary);
    }
    else {
        File1.open("productList.bin", ios::binary);
        File2.open("perishableProducts.bin", ios::binary);
        File3.open("nonperishableProducts.bin", ios::binary);
    }


    string text = captureText();
    int linesCount = count(text.begin(), text.end(), '\n');
    string linesArray[linesCount];
    DivideLines(text, linesCount, linesArray);

    Product products[linesCount];
    GetProducts( linesArray,  linesCount,  products);

    RecordProducts( linesCount , File2,File3, File1, products);

    File1.close();
    File2.close();
    File3.close();

    RemoveExpiredProducts(desirableDateUnix, "productList.bin");
    RemoveExpiredProducts(desirableDateUnix, "perishableProducts.bin");
    RemoveExpiredProducts(desirableDateUnix, "nonperishableProducts.bin");
}


