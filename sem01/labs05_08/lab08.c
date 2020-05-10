#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100];
    char str1_copy[100];
    char str2[100];
    char str2_copy[100];
    int number;

    printf("First str:\n");
    scanf("%s", str1);
    printf("Second str:\n");
    scanf("%s", str2);
    printf("Number of symbols:\n");
    scanf("%d", &number);
    strncat(str1, str2, number);
    puts(str1);
    printf("\n");

    printf("Str:\n");
    scanf("%s", str1);
    printf("\n");
    strcpy(str1_copy, str1);
    puts(str1_copy);
    printf("\n");

    printf("Str:\n");
    scanf("%s", str2);
    printf("\n");
    strncpy(str2_copy, str2, number);
    str2_copy[number] = '\0';
    puts(str2_copy);
    printf("\n");

    printf("Str:\n");
    gets_s(str1, 100);
    gets_s(str1, 100);
    printf("Symbol for search:\n");
    int d_symbol = getchar();
    char *adr = strrchr(str1, d_symbol);
    printf("%d\n", adr - str1 + 1);

    printf("Str1:\n");
    scanf("%s", str1);
    printf("Str2:\n");
    scanf("%s", str2);
    printf("%d\n", strcspn(str1, str2));

    return 0;
}