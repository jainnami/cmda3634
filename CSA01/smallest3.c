#include <stdio.h>
#include <limits.h>

int main () {
    int smallest1 = INT_MAX, smallest2 = INT_MAX, smallest3 = INT_MAX;
    int next;
    while (scanf("%d",&next) == 1) {
        if (next < smallest1) {
            smallest3 = smallest2;
            smallest2 = smallest1;
            smallest1 = next;
        }

        else if (next < smallest2) {
            smallest3 = smallest2;
            smallest2 = next;
        }

        else if (next < smallest3) {
            smallest3 = next;
        }
    }
    printf ("The smallest number is %d\n",smallest1);
    if (smallest2 != INT_MAX) {
    printf ("The second smallest number is %d\n",smallest2);
    }
    if (smallest3 != INT_MAX) {
    printf ("The third smallest number is %d\n",smallest3);
    }
}