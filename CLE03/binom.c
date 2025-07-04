#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) 
{
    if (argc < 3) 
    {
        printf("command usuage: %s %s %s", argv[0], "n", "k");
        return 1; //abnormal exit
    }

    long long n = atoll(argv[1]);
    long long k = atoll(argv[2]);
    long long answer = 1;

    if (n<0 || k < 0) {
        printf("parameters are not within valid range");
        return 1;
    }

    for (int i = 0; i < k; i++)
    {
        answer *= (n-i);
        answer /= (i+1);
    }

    printf("%lld choose %lld is %lld\n", n, k, answer);

    return 0;
}