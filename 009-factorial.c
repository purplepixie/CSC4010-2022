#include <stdio.h>


int main()
{
    unsigned long long n = 50;
    unsigned long long fac = 1;

    for (unsigned long long i=n; i>=2; --i)
    {
        fac = fac * i;
    }

    printf("%llu!=%llu\n",n,fac);

    return 0;
}