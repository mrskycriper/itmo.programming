#include <stdio.h>
#include <math.h>

int main()
{
    float m, n;
    printf("Введите значения m и n через пробел:\n");
    scanf("%f %f", &m, &n);
    float z1 = ((m - 1) * sqrt(m) - (n - 1) * sqrt(n)) / (sqrt(pow(m, 3) * n) + n * m + pow(m, 2) - m);
    float z2 = (sqrt(m) - sqrt(n)) / m;
    printf("Результаты:\nz1 =%f\nz2 =%f\n", z1, z2);
    return 0;
}