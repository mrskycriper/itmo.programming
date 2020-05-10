#include <stdio.h>

int main()
{
    int number;
    char symbol;
    printf("Введите целое число и символ через пробел:\n");
    scanf("%d %c", &number, &symbol);
    printf("Целое число: %d\nСимвол: %c\n", number, symbol);
    return 0;
}