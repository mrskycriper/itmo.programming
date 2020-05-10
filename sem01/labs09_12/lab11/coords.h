//
// Created by serge on 16.11.2019.
//

#ifndef HW11_COORDS_H
#define HW11_COORDS_H


 struct coords
{
    double x_A;
    double y_A;
    double x_B;
    double y_B;
    double x_C;
    double y_C;
};

double sqare(struct coords triangle);

double perimeter(struct coords triangle);

#endif HW11_COORDS_H
