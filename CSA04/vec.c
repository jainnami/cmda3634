#include <stdio.h>

// v = 0
void vec_zero (double v[], int dim) {
    for (int i=0;i<dim;i++) {
        v[i] = 0;
    }
}

// read a vector from stdin
// returns the number of elements read in
int vec_read_stdin (double v[], int dim) {
    for (int i=0;i<dim;i++) {
        if (scanf("%lf",&(v[i])) != 1) { // could also use v+i
            return i;
        }
    }
    return dim;
}

// w = u + v
void vec_add (double u[], double v[], double w[], int dim) {
    for (int i=0;i<dim;i++) {
        w[i] = u[i] + v[i];
    }
}

// w = cv
void vec_scalar_mult (double v[], double c, double w[], int dim) {
    for (int i=0;i<dim;i++) {
        w[i] = c*v[i];
    }
}

// print a vector using the given format specifier
void vec_print (double v[], char* format, int dim) {
    for (int i=0;i<dim;i++) {
        printf (format,v[i]);
    }
    printf ("\n");
}

// calculate the norm squared of a vector
double vec_norm_sq (double v[], int dim) {
    double norm_sq = 0;
    for (int i=0;i<dim;i++) {
        norm_sq += v[i]*v[i];
    }
    return norm_sq;
}

// calculate the distance squared between two vectors
double vec_dist_sq (double u[], double v[], int dim) {
    double dist_sq = 0;
    for (int i=0;i<dim;i++) {
        dist_sq += (u[i]-v[i])*(u[i]-v[i]);
    }
    return dist_sq;
}
