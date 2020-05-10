#include "ComplexNumber.h"

complexNumber::complexNumber(const double& realNumber, const double& imaginaryNumber)
{
    realPart = realNumber;
    imaginaryPart = imaginaryNumber;
}

void complexNumber::complexNumberPrint(const complexNumber& complex)
{
    cout << "Результат: " << complex.realPart;
    if (complex.imaginaryPart > 0.0)
    {
        cout << "+" << complex.imaginaryPart << "i" << endl;
    }
    else if (complex.imaginaryPart < 0.0)
    {
        cout << "-" << complex.imaginaryPart << "i" << endl;
    }
    else if (complex.imaginaryPart == 0.0)
    {
        cout << endl;
    }
}

complexNumber complexNumber::complexNumber_x_realNumber(const complexNumber& complex, const double& real)
{
    complexNumber result(complex.realPart, complex.imaginaryPart);
    result.realPart *= real;
    result.imaginaryPart *= real;
    return result;
}

complexNumber complexNumber::complexNumbersSummary(const complexNumber& firstNumber, const complexNumber& secondNumber)
{
    complexNumber result(firstNumber.realPart + secondNumber.realPart, firstNumber.imaginaryPart + secondNumber.imaginaryPart);
    return result;
}

complexNumber complexNumber::complexNumbersMultiplication(const complexNumber& firstNumber, const complexNumber& secondNumber)
{
    complexNumber result(0.0, 0.0);
    result.realPart = (firstNumber.realPart * secondNumber.realPart) - (firstNumber.imaginaryPart + secondNumber.imaginaryPart);
    result.imaginaryPart = (firstNumber.realPart * secondNumber.imaginaryPart) + (secondNumber.realPart * firstNumber.imaginaryPart);
    return result;
}

double complexNumber::complexNumberLength(const complexNumber& number)
{
    double result;
    result = sqrt(pow(number.realPart, 2) + pow(number.imaginaryPart, 2));
    return result;
}
