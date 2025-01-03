#include "complex.h"
#include <stdio.h>
#include <math.h>

void read_comp(complex *X, const double *real,const double *image)
{
    X->real = *real;
    X->image = *image;
}

void print_comp(complex *X)
{
    printf("%.2f + (%.2f)i",X->real,X->image);
}

void add_comp(complex *X,complex *Y)
{
    complex tmp;
    tmp.real = X->real + Y->real;
    tmp.image = X->image + Y->image;

    print_comp(&tmp);
}

complex sub_comp(complex *X,complex *Y)
{
    complex tmp;
    tmp.real = X->real - Y->real;
    tmp.image = X->image - Y->image;

    print_comp(&tmp);
}

complex mult_comp_real(complex *X,const double *real)
{
    complex tmp;
    tmp.real = X->real * *real;
    tmp.image = X->image;

    print_comp(&tmp);
}

complex mult_comp_img(complex *X,const double *image)
{
    complex tmp;
    tmp.image = X->image * *image;
    tmp.real = X->real;

    print_comp(&tmp);
}

complex mult_comp_comp(complex *X,complex *Y)
{
    complex tmp;
    tmp.real = X->real * Y->real;
    tmp.image = X->image * Y->image;

    print_comp(&tmp);
}

complex abs_comp(complex *X)
{
    double result;
    result = sqrt(pow(X->image,2) + pow(X->real,2));

    printf("The result of abs is: %.2f\n", result);
}