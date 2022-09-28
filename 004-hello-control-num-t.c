#include <stdio.h>
#include <omp.h>

int main()
{
    printf("Maximum threads: %d\n",omp_get_max_threads());
    printf("Number of processors: %d\n",omp_get_num_procs());

    omp_set_num_threads(2);

    printf("Maximum threads: %d\n",omp_get_max_threads());
    printf("Number of processors: %d\n",omp_get_num_procs());

    #pragma omp parallel
    {
        printf("Hello from thread %d of %d\n",
            omp_get_thread_num(),
            omp_get_num_threads());
    }

    printf("Goodbye World\n");

    return 0;
}