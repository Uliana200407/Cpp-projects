#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QPlainTextEdit>
#include <QLineEdit>
#include "Matrix.h"

Matrix matrixMultiply(Matrix matrix1, Matrix matrix2, int start, int end, QPlainTextEdit& resultOutput);
void validateRange(int start, int end);
void readMatrixElements(Matrix& matrix, QPlainTextEdit& resultOutput, int rows, int cols, const QString& title);
void calculateButtonClicked(QLineEdit& startEdit, QLineEdit& endEdit, QLineEdit& rowsEdit1, QLineEdit& colsEdit1, QLineEdit& rowsEdit2, QLineEdit& colsEdit2, QPlainTextEdit& resultOutput);

#endif // FUNCTIONS_H
