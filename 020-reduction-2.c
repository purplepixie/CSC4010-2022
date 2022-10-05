#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int j=500;

    srand(time(NULL));

    #pragma omp parallel for default(none) reduction(max:i,j)
    for(int z=0; z<omp_get_num_threads(); ++z)
    {
        i=rand()%100;
        j=rand()%100;
        printf("i=%d,j=%d in t=%d\n",i,j,omp_get_thread_num());
    }

    printf("Finally i=%d, j=%d\n",i,j);

    return 0;
}