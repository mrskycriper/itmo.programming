#pragma  once

#include <cmath>
#include <utility>
#include <iostream>
using namespace std;

typedef struct
{
    int xCentre;
    int yCentre;
    int radius;
}circle;

void swapToRemainderPointers(int *first, int *second);
void swapToRemainderLinks(int& first, int& second);

void RoundPointers(double *number);
void RoundLinks(double& number);

void changeRadiusPointers(circle *CIRCLE, const int *newRadius);
void changeRadiusLinks(circle& CIRCLE, int& newRadius);

void matrixTransposePointers(int MATRIX[3][3]);
void matrixTransposeLinks(int (&MATRIX)[3][3]);
