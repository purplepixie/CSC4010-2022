#include <stdio.h>
#include <stdlib.h>

int isPrime(unsigned long x)
{
    unsigned long max = x/2;
    if (x<=2) return 1;
    if ((x%2)==0) return 0;
    for (unsigned long i=3; i<=max; i+=2)
    {
        //printf("%d M %d = %d\n",x,i,(x%i));
        if ((x%i) == 0) return 0;
    }
    return 1;
}

int main(int ac, char** av)
{
    unsigned long start = 100000000;
    unsigned long end = 100005000;

    if (ac>1) start=atol(av[1]);
    if (ac>2) end=atol(av[2]);

    unsigned long diff = end-start;
    printf("From %lu to %lu = %lu numbers\n",start,end,diff);

    for (unsigned long x = start; x <= end; ++x)
    {
        if (isPrime(x)==1) printf(".");
    }
    printf("\n");
    return 0;
}