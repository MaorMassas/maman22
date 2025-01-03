#include <stdio.h>


typedef struct complex{
    double real;
    double image;
}complex;

complex *A,*B,*C,*D,*E,F;

void read_comp(complex *X,const double *real,const double *image);
void print_comp(complex *X);
void add_comp(complex *X,complex *Y);
complex sub_comp(complex *X,complex *Y);
complex mult_comp_real(complex *X,const double *real);
complex mult_comp_img(complex *X,const double *image);
complex mult_comp_comp(complex *X,complex *Y);
complex abs_comp(complex *X);