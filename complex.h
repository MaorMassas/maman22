#include <stdio.h>


typedef struct complex{
    double real;
    double image;
}complex;

complex *A,*B,*C,*D,*E,F;

read_mat(double real,double image);
print_comp(complex X);
add_comp(complex X,complex Y);
sub_comp(complex X,complex Y);
mult_comp_real(complex X,double real);
mult_comp_img(complex X,double image);
mult_comp_comp(complex X,complex Y);
abs_comp(complex X);