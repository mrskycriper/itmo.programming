#include <stdio.h>
#include "coords.h"

int main()
{
    struct coords triangle = {0.0, 0.0, 4.0, 0.0, 2.0, 2.0};
    double triangle_sqare = sqare(triangle);
    double triangle_perimeter = perimeter(triangle);
    printf("Sqare: %.2f\nPerimeter: %.2f\n", triangle_sqare, triangle_perimeter);
    return 0;
}