#include "complex.h"
#include <stdio.h>

void read_comp(complex *X, double *real,double *image)
{
    X->real = *real;
    X->image = *image;
}

void print_comp(complex *X)
{
    printf("%lf + (%lf)i",X->real,X->image);
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

}

complex mult_comp_real(complex *X,double *real)
{

}

complex mult_comp_img(complex *X,double *image)
{

}

complex mult_comp_comp(complex *X,complex *Y)
{

}

complex abs_comp(complex *X)
{

}