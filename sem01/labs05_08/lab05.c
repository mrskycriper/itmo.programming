#include <stdio.h>

int main()
{
    int len = 7;
    int array[] = {23, 5678, 2, 564, 365, 77, 443};
    for (int step = 0; step < len; step++)
        printf("a[%d] = %d\n", step, array[step]);

    int temp = 0;
    int matrix1[2][2];
    matrix1[0][0] = 1;
    matrix1[0][1] = 1;
    matrix1[1][0] = 0;
    matrix1[1][1] = 1;
    int matrix2[2][2];
    matrix2[0][0] = 2;
    matrix2[0][1] = 0;
    matrix2[1][0] = 3;
    matrix2[1][1] = 0;
    int matrix_result[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            matrix_result[i][j] = temp;
            temp = 0;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d] ", matrix_result[i][j]);
        }
        printf("\n");
    }
    return 0;
}