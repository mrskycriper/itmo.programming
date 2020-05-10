#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main()
{
    int array[SIZE];
    int *p = array;

    for (int step = 0; step < SIZE; step++)
    {
        printf("array[%d]:\n", step);
        scanf("%d", &array[step]);
    }

    for (int step = 0; step < SIZE; step++)
    {
        printf("%d ", *(p + step));
    }
    printf("\n\n");


    float *darray = (float*) malloc (4 * sizeof(float));
    darray[0] = 56.4f;
    darray[1] = 36.5f;
    darray[2] = 7.7f;
    darray[3] = 44.3f;

    for (int step = 0; step < 4; step++)
    {
        printf("%.1f ", darray[step]);
    }
    free(darray);
    return 0;
}