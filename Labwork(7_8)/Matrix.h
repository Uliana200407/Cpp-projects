#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    int rows;
    int columns;

public:
    Matrix(int rows, int columns);
    int getRows() const ;
    int getColumns() const;
    int& operator()(int row, int col) ;
};

#endif // MATRIX_H
