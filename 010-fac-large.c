#include <stdio.h>


int main()
{
    int length = 500000;
    unsigned long long n[length];
    unsigned long long fac[length];

    for(int i=0; i<length; ++i)
    {
        n[i]=50;
        fac[i]=1;
    }

    for (int x=0; x<length; ++x)
    {
        for (unsigned long long i=n[x]; i>=2; --i)
        {
            fac[x] *= i;
        }
        printf(".");
    }

    printf("\n");


    return 0;
}