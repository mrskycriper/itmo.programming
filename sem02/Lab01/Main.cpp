#include "Procedure.h"

/*
Variant 19:
* Tasks: 3, 6, 11, 14
*/

int main()
{
    int firstNumber = 10;
    int secondNumber = 25;
    int *firstNumberPointer = &firstNumber;
    int *secondNumberPointer = &secondNumber;
    swapToRemainderPointers(firstNumberPointer, secondNumberPointer);
    cout << *firstNumberPointer << " " << *secondNumberPointer << endl;
    firstNumber = 10;
    secondNumber = 25;
    int &firstNumberLink = firstNumber;
    int &secondNumberLink = secondNumber;
    swapToRemainderLinks(firstNumberLink, secondNumberLink);
    cout << firstNumberLink << " " << secondNumberLink << endl;
    cout << endl;

    double number = 16.556;
    double *numberPointer = &number;
    double &numberLink = number;
    RoundPointers(numberPointer);
    cout << *numberPointer << endl;
    number = 16.556;
    RoundLinks(numberLink);
    cout << numberLink << endl;
    cout << endl;

    circle CIRCLE;
    CIRCLE.radius = 10;
    int newRadius = 15;
    int *newRadiusPointer = &newRadius;
    int &newRadiusLink = newRadius;
    circle *circlePointer = &CIRCLE;
    circle &circleLink = CIRCLE;
    changeRadiusPointers(circlePointer, newRadiusPointer);
    cout << CIRCLE.radius << endl;
    CIRCLE.radius = 10;
    changeRadiusLinks(circleLink, newRadiusLink);
    cout << CIRCLE.radius << endl;
    cout << endl;

    int matrix[3][3];
    matrix[0][0] = 1;
    matrix[1][0] = 2;
    matrix[2][0] = 3;

    matrix[0][1] = 4;
    matrix[1][1] = 5;
    matrix[2][1] = 6;

    matrix[0][2] = 7;
    matrix[1][2] = 8;
    matrix[2][2] = 9;

    int (&matrixLink)[3][3] = matrix;
    matrixTransposePointers(matrix);
    cout << matrix[0][0] << " " << matrix[1][0] << " " << matrix[2][0] << endl;
    cout << matrix[0][1] << " " << matrix[1][1] << " " << matrix[2][1] << endl;
    cout << matrix[0][2] << " " << matrix[1][2] << " " << matrix[2][2] << endl;
    cout << endl;
    matrixTransposeLinks(matrixLink);
    cout << matrix[0][0] << " " << matrix[1][0] << " " << matrix[2][0] << endl;
    cout << matrix[0][1] << " " << matrix[1][1] << " " << matrix[2][1] << endl;
    cout << matrix[0][2] << " " << matrix[1][2] << " " << matrix[2][2] << endl;
    return 0;
}
