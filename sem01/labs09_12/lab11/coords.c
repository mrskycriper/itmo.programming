//
// Created by serge on 16.11.2019.
//
#include "coords.h"
#include <math.h>

double sqare(struct coords triangle)
{
    return 0.5 * fabs((triangle.x_B - triangle.x_A) * (triangle.y_C - triangle.y_A) - (triangle.x_C - triangle.x_A) * (triangle.y_B - triangle.y_A));
}

double perimeter(struct coords triangle)
{
    return sqrt(pow(triangle.x_A - triangle.x_C, 2) + pow(triangle.y_A - triangle.y_B, 2)) + sqrt(pow(triangle.x_A - triangle.x_B, 2) + pow(triangle.y_A - triangle.y_C, 2)) + sqrt(pow(triangle.x_B - triangle.x_C, 2) + pow(triangle.y_B - triangle.y_C, 2));
}