#include <stdio.h>

int main()
{
    int number1, number2, result;
    printf("Введите первое целое число:\n");
    scanf("%d", &number1);
    result = (number1 >= 33) & (number1 <= 88);
    printf("Резульат (Если число попадает в диапазон 33-88 то 1, иначе 0): %d\n", result);
    printf("Введите втрое целое число:\n");
    scanf("%d", &number2);
    printf("%d\n", (number2 >> 20) & 1);
    return 0;
}