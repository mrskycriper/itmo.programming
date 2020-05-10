#include <stdio.h>

int main()
{
    int number1, number2;
    printf("Введите первое число:\n");
    scanf("%d", &number1);
    printf("Задание 2 | %x\n", number1);
    printf("Задание 3 | %o %o\n", number1, number1<<4);
    printf("Задание 4 | %o %o\n", number1, ~number1);
    printf("Введите второе число:\n");
    scanf("%x", &number2);
    printf("Задание 5 | %x\n", number1 & number2);
    return 0;
}