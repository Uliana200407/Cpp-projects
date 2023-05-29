#include "Matrix.h"

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {
    if (rows <= 0 || columns <= 0) {
        throw invalid_argument("Invalid matrix dimensions");
    }

    data.resize(rows, vector<int>(columns, 0));
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

int& Matrix::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        throw out_of_range("Matrix indices out of range");
    }

    return data[row][col];
}
