#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (int argc, char* argv[]) {
    if (argc < 2) {
        printf ("command usage: %s %s\n",argv[0],"center");
    }
    int center = atoi(argv[1]);
    int closest1, closest2, closest3;
    int smallest_distance1 = INT_MAX, smallest_distance2 = INT_MAX, smallest_distance3 = INT_MAX;
    int next;
    while (scanf("%d",&next) == 1) {
        int distance = abs(next-center);
        if (distance < smallest_distance1) {
            closest3 = closest2;
            closest2 = closest1;
            closest1 = next;

            smallest_distance3 = smallest_distance2;
            smallest_distance2 = smallest_distance1;
            smallest_distance1 = distance;
        }
        
        else if (distance < smallest_distance2) {
            closest3 = closest2;
            closest2 = next;
            
            smallest_distance3 = smallest_distance2;
            smallest_distance2 = distance;
        }

        else if (distance < smallest_distance3) {
            closest3 = next;
            
            smallest_distance3 = distance;
        }
    }
    printf("The number closest to %d is %d\n", center, closest1);
    printf("The number second closest to %d is %d\n", center, closest2);
    printf("The number third closest to %d is %d\n", center, closest3);

    return 0;
}