#include <stdio.h>

enum months
{
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

struct cords
{
    int x_max;
    int x_min;
    int y_max;
    int y_min;
};

struct key_state
{
    unsigned int numlock:1;
    unsigned int capslock:1;
    unsigned int scrollock:1;
};

union union_type {
    int number;
    struct key_state;
};

int main()
{
    printf("%d\n", JUL);

    struct cords rectangle = {5, 0, 7, 0};
    int perimeter = 2 * (rectangle.x_max - rectangle.x_min) + 2 * (rectangle.y_max - rectangle.y_min);
    printf("%d\n", perimeter);

    union union_type c;
    printf("Number: \n");
    scanf("%o", &c.number);

    printf("Num: %d\nCaps: %d\nScrol: %d\n", c.numlock, c.scrollock, c.capslock);
    return 0;

}