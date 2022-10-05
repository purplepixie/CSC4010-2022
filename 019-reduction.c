#include <stdio.h>
#include <omp.h>

int main()
{
    int i;

    printf("** ATOMIC **\n");
    i=10;
    #pragma omp parallel for default(none) shared(i)
    for(int z=0; z<omp_get_num_threads(); ++z)
    {
        #pragma omp atomic
        i+=1;
        printf("i=%d in thread %d\n",i,omp_get_thread_num());
    }
    printf("After loop i=%d\n",i);

    printf("** REDUCTION **\n");
    i=10;
    #pragma omp parallel for default(none) reduction(+:i)
    for(int z=0; z<omp_get_num_threads(); ++z)
    {
        i+=1;
        printf("i=%d in thread %d\n",i,omp_get_thread_num());
    }
    printf("After loop i=%d\n",i);


    return 0;
}