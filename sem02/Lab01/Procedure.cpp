#include "Procedure.h"

void swapToRemainderPointers(int *first, int *second)
{
    if (*first > *second)
    {
        *first = *first % *second;
    }
    else if (*second > *first)
    {
        *second = *second % *first;
    }
}

void swapToRemainderLinks(int& first, int& second)
{
    if (first > second)
    {
        first = first % second;
    }
    else if (second > first)
    {
        second = second % first;
    }
}

void RoundPointers(double *number)
{
    *number = round(*number);
}

void RoundLinks(double& number)
{
    number = round(number);
}

void changeRadiusPointers(circle *CIRCLE, const int *newRadius)
{
    CIRCLE->radius = *newRadius;
}

void changeRadiusLinks(circle& CIRCLE, int& newRadius)
{
    CIRCLE.radius = newRadius;
}

void matrixTransposePointers(int MATRIX[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            swap(MATRIX[i][j], MATRIX[j][i]);
        }
    }
}

void matrixTransposeLinks(int (&MATRIX)[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            swap(MATRIX[i][j], MATRIX[j][i]);
        }
    }
}
