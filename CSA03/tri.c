#include <stdio.h>
#define MAX_POINTS 1000

typedef struct vec2_s {
    double x, y;
} vec2;

// Calculate the determinant of a 3x3 matrix and then checks whether the point is in the circumcircle
int inCircumcircle(vec2 points[], int i, int j, int k, int num_points)
{
    // Possible triangle vertices
    vec2 A = points[i];
    vec2 B = points[j];
    vec2 C = points[k];

    // Check if vertices are in counter-clockwise order by calculating the determinant
    double clockwise_determinant = A.x*(B.y-C.y) - A.y*(B.x-C.x) + (B.x*C.y - B.y*C.x);

    // If vertices are not in counter-clockwise order,
    // then swap B and C to make them in counter-clockwise order
    if (clockwise_determinant <= 0)
    {
        B = points[k];
        C = points[j];
    }

    // Loop through all other points to check if they are inside the circumcircle of triangle ABC
    for (int p=0; p < num_points; p++)
    {
        if ((p != i) && (p != j) && (p !=k))
        {
            // Assign the pth point to vertex D
            vec2 D = points[p];

            // Calculate coefficients for the determinant
            double a = (A.x-D.x);
            double b = (A.y-D.y);
            double c = (A.x-D.x)*(A.x-D.x) + (A.y-D.y)*(A.y-D.y);
            double d = (B.x-D.x);
            double e = (B.y-D.y);
            double f = (B.x-D.x)*(B.x-D.x) + (B.y-D.y)*(B.y-D.y);
            double g = (C.x-D.x);
            double h = (C.y-D.y);
            double l = (C.x-D.x)*(C.x-D.x) + (C.y-D.y)*(C.y-D.y);
            
            // Calculate the determinant of the 3x3 matrix
            double determinant =  a*(e*l - f*h) - b*(d*l - g*f) + c*(d*h - e*g);

            // If determinant is greater than 0, point D is inside the circumcircle of triangle ABC
            if (determinant > 0)
            {
                return 1;
            }
        }
    }
    // Point is not inside the circumcircle
    return 0;
}



int main()
{
    vec2 points[MAX_POINTS];
    vec2 next;
    int num_points = 0;

    while(scanf("%le %le", &(next.x), &(next.y)) == 2)
    {
        if (num_points < MAX_POINTS)
        {
            points[num_points] = next;
            num_points += 1;
        }

        else {
            printf("too many points!\n");
            return 1;
        }
    }

    // Loop through all possible combinations of three points to form triangles
    for (int i=0; i < num_points-2; i++)
    {
        for (int j = i+1; j < num_points-1; j++)
        {
            for (int k = j+1; k < num_points; k++)
            {
                // Check if the current indices forms a valid triangle
                if (inCircumcircle(points, i, j, k, num_points) == 0)
                {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
}