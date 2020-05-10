#include <stdio.h>

int greatestCommonDivisor(int numberOne, int numberTwo)
{
    while(numberOne > 0 && numberTwo > 0)

        if(numberOne > numberTwo)
        {
            numberOne %= numberTwo;
        }
        else
        {
            numberTwo %= numberOne;
        }
    return numberOne + numberTwo;
}

int leastCommonMultiple(int numberOne, int numberTwo)
{
    return (numberOne * numberTwo) / greatestCommonDivisor(numberOne, numberTwo);
}

int digitSum(int number)
{
    int counter = number % 10;
    if (number != number % 10)
    counter += digitSum(number / 10);

    return counter;
}

int main()
{
    int numberOne, numberTwo;
    printf("Enter first number:\n");
    scanf("%d", &numberOne);
    printf("Enter second number:\n");
    scanf("%d", &numberTwo);
    printf("GCD: %d\n", greatestCommonDivisor(numberOne, numberTwo));
    printf("LCM: %d\n", leastCommonMultiple(numberOne, numberTwo));

    int number;
    printf("Enter number:\n");
    scanf("%d", &number);
    printf("Sum of digit: %d\n", digitSum(number));
    return 0;
}
