#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "vec.h"

/* Calculates the index of the next center
Parameters:
    data: Array containing all data points
    num_points: Integer of total number of data points
    dim: Integer of the dimension of each data point
    centers: Array of the indices of the current centers
    m: Integer of the current centers
Return:
    Index of the next center
*/ 
int calc_arg_max(double data[], int num_points, int dim, int centers[], int m)
{
    // Index of the farthest point
    int max = -1;
    // Maximum distance squared
    double max_ds = 0.0;

    // For loop that iterates through all data points (num_points)
    for (int i = 0; i < num_points; i++)
    {
        // Initializing the minimum distance the the maximum possible value
        double min_ds = DBL_MAX;

        // For loop that iterates through all of the current centers
        for (int j = 0; j < m; j++)
        {
            // Calculating the distance squared (ds) between the current
            // data point (i) and the j-th center
            double ds = vec_dist_sq(data+(i*dim), data+(centers[j]*dim), dim);

            // Updates the minimum distance squared (min_ds) if needed
            if (ds < min_ds)
            {
                min_ds = ds;
            }
        }

        // Updates the maximum distance squared (max_ds) and the index of
        // the farthest point
        if (min_ds > max_ds)
        {
            max_ds = min_ds;
            max = i;
        }
    }

    // Return the index of the next center
    return max;
}

/* Calculates the maximum distance squared from any point to its closest center
Parameters:
    data: Array containing all data points
    num_points: Integer of the total number of data points
    dim: Integer of the dimension of each data point
    centers: Array of all current centers' indices
    k: Integer of the total number of centers
Returns:
    Maximum distance squared from any point to its closest center
*/
double calc_cost_sq(double data[], int num_points, int dim, int centers[], int k)
{
    // Maximum distance squared
    double max_ds = 0.0;

    // For loop that iterates through all data points (num_points)
    for (int i = 0; i < num_points; i++)
    {
        // Minimum distance squared initialized to the maximum value possible
        double min_ds = DBL_MAX;

        // For loop that iterates through all the centers (k)
        for (int j = 0; j < k; j++)
        {

            // Calculating the distance squared between the current data point (i)
            // and the j-th center
            double ds = vec_dist_sq(data+(i*dim), data+(centers[j]*dim), dim);

            // Update the minimum distance squared if necessary
            if (ds < min_ds)
            {
                min_ds = ds;
            }
        }

        // Update the maximum distance squared
        if (min_ds > max_ds)
        {
            max_ds = min_ds;
        }
    }

    // Return the maximum distance squared
    return max_ds;
}

int main (int argc, char* argv[]) 
{

    // read k from the command line
    if (argc < 2) { 
        printf("command usage: %s %s\n", argv[0], "k");
        return 1;
    }
    int k = atoi(argv[1]);
    // printf("k = %d\n", k);

    // read num_points and dim
    int num_points, dim;
    if (scanf("%*c %d %d", &num_points, &dim) != 2) {
        printf ("error reading file info\n");
        return 1;
    }

    // printf ("num_points = %d, dim %d\n", num_points, dim);


    // allocate data
    double* data = (double*)malloc(sizeof(double)*num_points*dim);
    
    // read and store data
    for (int i=0; i<num_points; i++) {
        if (vec_read_stdin(data+i*dim, dim) != dim) {
            printf("error reading file\n");
            return 1;
        }
    }

    // Initialize the first center
    int centers[k];
    centers[0] = 0;

    // Calculate the remaining centers using the Farthest First Algorithm
    for (int m=1; m<k; m++)
    {
        centers[m] = calc_arg_max(data, num_points, dim, centers, m);
    }

    // Calculate the approximate optimal cost
    double cost_sq = calc_cost_sq(data, num_points, dim, centers, k);

    double cost = sqrt(cost_sq);

    printf("approximate optimal cost = %.4f \n", cost);

    printf("approximate optimal centers = ");
    for (int i = 0; i < k; i++) {
        printf("%d ", centers[i]);
    }
    printf("\n");


    // free data
    free(data);
}