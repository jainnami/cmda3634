#ifndef VEC_H
#define VEC_H

// v = 0
void vec_zero (double v[], int dim);

// read a vector from stdin
// returns the number of elements read in
int vec_read_stdin (double v[], int dim);

// w = u + v
void vec_add (double u[], double v[], double w[], int dim);

// w = cv
void vec_scalar_mult (double v[], double c, double w[], int dim);

// print a vector using the given format specifier
void vec_print (double v[], char* format, int dim);

// calculate the norm squared of a vector
double vec_norm_sq (double v[], int dim);

// calculate the distance squared between two vectors
double vec_dist_sq (double u[], double v[], int dim);

#endif
