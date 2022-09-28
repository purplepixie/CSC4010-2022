#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        for (int i=0; i<20; ++i)
        {
            if ((i % omp_get_num_threads()) == omp_get_thread_num())
                printf("i=%d in thread %d\n",i,omp_get_thread_num());
        }
    }

    return 0;
}