#pragma once

#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class complexNumber
{
public:
    complexNumber(const double& realNumber, const double& imaginaryNumber);

    static void complexNumberPrint(const complexNumber& complex);

    static complexNumber complexNumber_x_realNumber(const complexNumber& complex, const double& real);

    static complexNumber complexNumbersSummary(const complexNumber& firstNumber, const complexNumber& secondNumber);

    static complexNumber complexNumbersMultiplication(const complexNumber& firstNumber, const complexNumber& secondNumber);

    static double complexNumberLength(const complexNumber& number);
private:
    double realPart;
    double imaginaryPart;
};

