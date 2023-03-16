
#ifndef LABWORK_2__FUNCTIONS_H
#define LABWORK_2__FUNCTIONS_H

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Structure.h"
using namespace std;

Product ConvertStringToProduct(string line);

void RemoveExpiredProducts(time_t desirableDateUnix, const char *fileName);

void RecordProducts(int linesCount , ofstream &File2, ofstream &File3, ofstream &File1, Product products[]);
void RecordAll(ofstream &File1, Product products[], int i);
string ConvertProductToString(Product product);
void RecordNonperishable(ofstream &File3, Product products[], int i);

void RecordPerishable(ofstream &File2, Product products[], int i);

void GetProducts(string linesArray[], int linesCount, Product products[]);
void DivideLines(const string &text, int linesCount, string *linesArray);
string captureText();

#endif //LABWORK_2__FUNCTIONS_H
