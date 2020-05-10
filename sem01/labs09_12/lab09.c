#include <stdio.h>
#define length 100

int check(int number)
{
    for(int i = 2 ; i < number; i++)
        if(number % i == 0)
            return 0;
    return 1;
}

int main()
{
    char string[length];
    int numbersCount = 0;
    int upLettersCount = 0;
    int downLettersCount = 0;
    printf("String:\n");
    gets_s(string, length);
    for (int i = 0; i < length; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            numbersCount++;
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            downLettersCount++;
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            upLettersCount++;
        }
    }
    printf("Numbers: %d\nUpper letters: %d\nLower letters: %d\n", numbersCount, upLettersCount, downLettersCount);

    int number;
    printf("Enter number:\n");
    scanf("%d", &number);
    for (int i = 2; i <= number; i++)
    {
        if (check(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}