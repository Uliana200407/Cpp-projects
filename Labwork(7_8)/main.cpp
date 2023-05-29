#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QInputDialog>
#include <QString>
#include <QPropertyAnimation>
#include <exception>

#include "Functions.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setStyleSheet("background: #FFF3E6; ");
    window.setGeometry(100, 100, 470, 804);

    QGridLayout layout;

    QLabel titleLabel("📙Matrix Multiplication Calculator📙");
    titleLabel.setStyleSheet("font-family: 'Nunito'; font-style: normal; font-weight: 600; font-size: 32px; line-height: 44px; display: flex; align-items: center; text-align: center; color: #000000; border: 2px solid #003570; text-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&titleLabel, 0, 0, 1, 3, Qt::AlignHCenter);  // Выравнивание заголовка по центру

    QLabel rangeLabel("Enter the range👉🏻:");
    rangeLabel.setStyleSheet("font-size: 32px; font-weight: 500; font-style: normal; font-family: 'Nunito';"
                             "line-height: 44px; display: flex; align-items: center; text-align: center; color: #000000;");
    layout.addWidget(&rangeLabel, 1, 0, 1, 1);

    QLineEdit startEdit;
    startEdit.setStyleSheet("font-size: 14px; padding: 3px; border: 1px solid #ccc; box-sizing: border-box;"
                            "position: absolute; width: 36px; height: 23px;"
                            "background: #FFFFFF; border: 1px solid #003570; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&startEdit, 1, 1, 1, 1);

    QLineEdit endEdit;
    endEdit.setStyleSheet("font-size: 14px; padding: 3px; border: 1px solid #ccc; box-sizing: border-box;"
                          "position: absolute; width: 36px; height: 23px;"
                          "background: #FFFFFF; border: 1px solid #003570; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&endEdit, 1, 2, 1, 1);

    QLabel label1("Enter dimensions of the first matrix🖍️:");
    label1.setStyleSheet("font-size: 20px; font-weight: 700; font-style: italic; color: #FF8700; text-decoration-line: underline;");
    layout.addWidget(&label1, 2, 0, 1, 3);

    QLabel rowsLabel1("Rows:");
    rowsLabel1.setStyleSheet("font-size: 25px; font-weight: 600; font-style: normal; font-family: 'Nunito';"
                             "line-height: 44px; display: flex; align-items: center; text-align: center; color: #000000;");
    layout.addWidget(&rowsLabel1, 3, 0);

    QLineEdit rowsEdit1;
    rowsEdit1.setStyleSheet("font-size: 14px; padding: 3px; border: 1px solid #ccc; box-sizing: border-box;"
                            "position: absolute; width: 36px; height: 23px;"
                            "background: #FFFFFF; border: 1px solid #003570; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&rowsEdit1, 3, 1);

    QLabel colsLabel1("Columns:");
    colsLabel1.setStyleSheet("font-size: 25px; font-weight: 600; font-style: normal; font-family: 'Nunito';"
                             "line-height: 44px; display: flex; align-items: center; text-align: center; color: #000000;");
    layout.addWidget(&colsLabel1, 4, 0);

    QLineEdit colsEdit1;
    colsEdit1.setStyleSheet("font-size: 14px; padding: 3px; border: 1px solid #ccc; box-sizing: border-box;"
                            "position: absolute; width: 36px; height: 23px;"
                            "background: #FFFFFF; border: 1px solid #003570; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&colsEdit1, 4, 1);

    QLabel label2("Enter dimensions of the second matrix here🖍️:");
    label2.setStyleSheet("font-size: 20px; font-weight: 700; font-style: italic; color: #FF8700; text-decoration-line: underline;");
    layout.addWidget(&label2, 5, 0, 1, 3);

    QLabel rowsLabel2("Rows:");
    rowsLabel2.setStyleSheet("font-size: 25px; font-weight: 600; font-style: normal; font-family: 'Nunito';"
                             "line-height: 44px; display: flex; align-items: center; text-align: center; color: #000000;");
    layout.addWidget(&rowsLabel2, 6, 0);

    QLineEdit rowsEdit2;
    rowsEdit2.setStyleSheet("font-size: 14px; padding: 3px; border: 1px solid #ccc; box-sizing: border-box;"
                            "position: absolute; width: 36px; height: 23px;"
                            "background: #FFFFFF; border: 1px solid #003570; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&rowsEdit2, 6, 1);

    QLabel colsLabel2("Columns:");
    colsLabel2.setStyleSheet("font-size: 25px; font-weight: 600; font-style: normal; font-family: 'Nunito';"
                             "line-height: 44px; display: flex; align-items: center; text-align: center; color: #000000;");
    layout.addWidget(&colsLabel2, 7, 0);

    QLineEdit colsEdit2;
    colsEdit2.setStyleSheet("font-size: 14px; padding: 3px; border: 1px solid #ccc; box-sizing: border-box;"
                            "position: absolute; width: 36px; height: 23px;"
                            "background: #FFFFFF; border: 1px solid #003570; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&colsEdit2, 7, 1);

    QPushButton calculateButton("Calculate");
    calculateButton.setStyleSheet("width: 187px; height: 32px; font-family: 'Nunito'; font-size: 26px; color: #FFFFFF; background-color: #FF8700; border: 3px solid #000000; border-radius: 30px; box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&calculateButton, 8, 0, 1, 3);

    QPushButton exitButton("Exit");
    exitButton.setStyleSheet("width: 187px; height: 32px; font-family: 'Nunito'; font-size: 26px; color: #FFFFFF; background-color: #003570; border: 3px solid #000000; border-radius: 30px; box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&exitButton, 9, 0, 1, 3);

    QPushButton cleanButton("Clean All");
    cleanButton.setStyleSheet("width: 187px; height: 32px; font-family: 'Nunito'; font-size: 26px; color: #FFFFFF; background-color: #FF8700; border: 3px solid #000000; border-radius: 30px; box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.25);");
    layout.addWidget(&cleanButton, 10, 0, 1, 3);

    QPlainTextEdit resultOutput;
    resultOutput.setStyleSheet("font-size: 14px; padding: 6px; border: 1px solid #ccc;");
    layout.addWidget(&resultOutput, 11, 0, 1, 3);

    QObject::connect(&calculateButton, &QPushButton::clicked, [&]() {
        calculateButtonClicked(startEdit, endEdit, rowsEdit1, colsEdit1, rowsEdit2, colsEdit2, resultOutput);
    });

    QObject::connect(&exitButton, &QPushButton::clicked, [&]() {
        QApplication::quit();
    });

    QObject::connect(&cleanButton, &QPushButton::clicked, [&]() {
        startEdit.clear();
        endEdit.clear();
        rowsEdit1.clear();
        colsEdit1.clear();
        rowsEdit2.clear();
        colsEdit2.clear();
        resultOutput.clear();
    });

    window.setLayout(&layout);
    window.show();

    return app.exec();
}
