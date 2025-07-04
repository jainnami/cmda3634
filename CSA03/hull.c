#include <stdio.h>
#define MAX_POINTS 1000

typedef struct vec2_s {
    double x, y;
} vec2;

// Function to calculate the coefficients of the line equation 
// given two points
void lineEquation(vec2 p1, vec2 p2, double *a, double *b, double *c) {
    *a = p2.y - p1.y;
    *b = p1.x - p2.x;
    *c = p1.x * p2.y - p2.x * p1.y;
}

// Function to calculate whether two points are on the 
// same side of the line
double sameSide(double a, double b, double c, vec2 p)
{
    // Calculates the result of the equation ax + by - c 
    double result = a*p.x + b*p.y - c;
    if (result > 0)
    {
        // return 1 if points are on the same side
        return 1;
    }

    else
    {
        // return -1 if the points are not on the same side side of the line.
        return -1;
    }
}

int main() {
    // Array to store input points
    vec2 data[MAX_POINTS];

    // Points read from hull60.txt file
    int num_points = 0;

    // Temporary variable to store the next point from hull60.txt file
    vec2 next;

    // Checks to make sure maximum amount of points (1000) is not reached
    while(scanf("%lf %lf", &(next.x), &(next.y)) == 2)
    {
        if (num_points < MAX_POINTS)
        {
            data[num_points] = next;
            num_points += 1;
        }

        else {
            printf("too many points!\n");
            return 1;
        }
    }

    // Coefficients of the line equation
    double a, b, c;
    for (int i=0; i < num_points; i++)
    {
        for (int j = i+1; j < num_points; j++)
        {
            // calculates the equation for the edge
            lineEquation(data[i], data[j], &a, &b, &c);

            // counters for each side of the line
            int counter_pos = 0;
            int counter_neg = 0;
            // Used to check if the edge is valid
            int validity = 0;
            for (int p=0; p < num_points && validity == 0; p++)
            {
                // Exclude the points that are forming the edge to avoid reiteration
                if (p != i && p != j)
                {
                    // Checks which side of the line the point is on
                    double side = sameSide(a, b, c, data[p]);
                    // Point is on the negative side of the line
                    if (side < 0)
                    {
                        counter_neg++;
                        // If there is a point on the positive side and the negative side
                        // then invalidate the edge
                        if (counter_pos > 0)
                        {
                        validity = 1;
                        }
                    }

                    // Check for the positive side.
                    // If there is also a point on the negative side, then invalidate the edge    
                    else {
                        counter_pos++;
                        if (counter_neg > 0)
                        {
                        validity = 1;
                        }
                    }
                }
            }

            // If either side does not have points, then it is an edge
            // Print the indices of points that form a valid edge
            if (counter_pos == 0  || counter_neg == 0)
            {
                printf("%d %d\n", i, j);
            }
        }
    }
}