#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex {
    double real;
    double image;
} complex;

/* Function prototypes */
void read_comp(complex *X, const double *real, const double *image);
void print_comp(const complex *X);
complex add_comp(const complex *X, const complex *Y);
complex sub_comp(const complex *X, const complex *Y);
complex mult_comp_real(const complex *X, const double *real);
complex mult_comp_img(const complex *X, const double *image);
complex mult_comp_comp(const complex *X, const complex *Y);
double abs_comp(const complex *X);

#endif
