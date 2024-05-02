#ifndef MYCALCULATOR_CALCULATOR_H
#define MYCALCULATOR_CALCULATOR_H

#include <QPushButton>
#include <QWidget>
#include <vector>
#include <string>
#include <QLabel>
#include <QGridLayout>
#include <QApplication>
#include <QLineEdit>
#include <QDesktopServices>
#include <QUrl>
class Calculator :public QWidget
{
private:
    double s = 0;
    double result = 0.0;
    QGridLayout *grid;
    QLineEdit *lineEdit;
    std::vector<QPushButton*> btnOfNumbers;
    std::vector<QString> symOfnumbers = {"0", "1", "2", "3","4", "5","6","7", "8", "9"};
    QString currentOperation;
public:
    Calculator();
    ~Calculator();

public slots:
    void backspace();
    void addition();
    void setOperation(QString operation);
    void equals();
    void funZero();
    void Quit();
    void Clear();
    void Numbers();
    void funcForLbl();
    void appendNumber();
    void Sum();

};


#endif
