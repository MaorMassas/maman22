#include "complex.h"
#include <stdio.h>
#include <math.h>

void read_comp(complex *X, const double *real, const double *image) {
    X->real = *real;
    X->image = *image;
}

void print_comp(const complex *X) {
    printf("%.2f + (%.2f)i\n", X->real, X->image);
}

complex add_comp(const complex *X, const complex *Y) {
    complex result;
    result.real = X->real + Y->real;
    result.image = X->image + Y->image;
    return result;
}

complex sub_comp(const complex *X, const complex *Y) {
    complex result;
    result.real = X->real - Y->real;
    result.image = X->image - Y->image;
    return result;
}

complex mult_comp_real(const complex *X, const double *real) {
    complex result;
    result.real = X->real * (*real);
    result.image = X->image * (*real);
    return result;
}

complex mult_comp_img(const complex *X, const double *image) {
    complex result;
    result.real = -X->image * (*image);
    result.image = X->real * (*image);
    return result;
}

complex mult_comp_comp(const complex *X, const complex *Y) {
    complex result;
    result.real = (X->real * Y->real) - (X->image * Y->image);
    result.image = (X->real * Y->image) + (X->image * Y->real);
    return result;
}

double abs_comp(const complex *X) {
    return sqrt((X->real * X->real) + (X->image * X->image));
}
