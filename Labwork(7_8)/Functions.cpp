#include "Functions.h"

#include <QInputDialog>

Matrix matrixMultiply(Matrix matrix1, Matrix matrix2, int start, int end, QPlainTextEdit& resultOutput) {
    int rows1 = matrix1.getRows();
    int cols1 = matrix1.getColumns();
    int rows2 = matrix2.getRows();
    int cols2 = matrix2.getColumns();

    Matrix result(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                int sum = matrix1(i, k) * matrix2(k, j);

                if (sum > end || sum < start) {
                    resultOutput.appendHtml("<font color='blue'></font> Calculating element at position (" + QString::number(i) + "</font color='blue>', " + QString::number(j) + "): </font>" + QString::number(result(i, j)) + " + " + QString::number(sum) + " = " + QString::number(result(i, j) + sum));
                } else {
                    resultOutput.appendPlainText("Calculating element at position (" + QString::number(i) + ", " + QString::number(j) + "): " + QString::number(result(i, j)) + " + " + QString::number(sum) + " = " + QString::number(result(i, j) + sum));
                }

                result(i, j) += sum;
            }
        }
    }

    return result;
}

void validateRange(int start, int end) {
    if (start > end) {
        throw std::invalid_argument("Start can't be greater than end");
    }
}

void readMatrixElements(Matrix& matrix, QPlainTextEdit& resultOutput, int rows, int cols, const QString& title) {
    resultOutput.appendPlainText(title);
    resultOutput.moveCursor(QTextCursor::End);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            QString input;
            bool validInput = false;

            while (!validInput) {
                input = QInputDialog::getText(nullptr, "Enter Element",
                                              "Element at position (" +
                                                  QString::number(i) + ", " +
                                                  QString::number(j) + "):");

                // Перевірка на валідність числа
                bool ok;
                input.toInt(&ok);

                if (!ok) {
                    resultOutput.appendHtml("<font color='red'>Invalid input! Please enter a valid number.</font>");
                } else {
                    validInput = true;
                }
            }

            resultOutput.appendPlainText("Element at position (" +
                                         QString::number(i) + ", " +
                                         QString::number(j) + "): " +
                                         input);
            matrix(i, j) = input.toInt();
        }
    }
}


void calculateButtonClicked(QLineEdit& startEdit, QLineEdit& endEdit, QLineEdit& rowsEdit1, QLineEdit& colsEdit1, QLineEdit& rowsEdit2, QLineEdit& colsEdit2, QPlainTextEdit& resultOutput) {
    try {
        int start = startEdit.text().toInt();
        int end = endEdit.text().toInt();

        validateRange(start, end);

        int rows1 = rowsEdit1.text().toInt();
        int cols1 = colsEdit1.text().toInt();
        int rows2 = rowsEdit2.text().toInt();
        int cols2 = colsEdit2.text().toInt();

        if (cols1 != rows2) {
            throw std::invalid_argument("Cannot multiply matrices with incompatible dimensions");
        }

        Matrix matrix1(rows1, cols1);
        Matrix matrix2(rows2, cols2);

        resultOutput.clear();

        readMatrixElements(matrix1, resultOutput, rows1, cols1, "Enter elements of the first matrix:");

        readMatrixElements(matrix2, resultOutput, rows2, cols2, "Enter elements of the second matrix:");

        resultOutput.appendPlainText("\nMultiply matrices:");
        Matrix result = matrixMultiply(matrix1, matrix2, start, end, resultOutput);

        resultOutput.appendPlainText("\nMatrix product:");
        for (int i = 0; i < result.getRows(); i++) {
            QString row;
            for (int j = 0; j < result.getColumns(); j++) {
                row += QString::number(result(i, j)) + " ";
            }
            resultOutput.appendPlainText(row);
        }
    } catch (const std::exception& e) {
        resultOutput.appendHtml("<font color='red'>❌ An error occurred: </font> <font color='#003570'>" + QString(e.what()) + "</font>") ;
    }
}
