#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello World\n");
    }

    printf("Goodbye World\n");

    return 0;
}