#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello from thread %d\n",omp_get_thread_num());

        #pragma omp single nowait // optional nowait
        {
            printf("Thread %d is sleeping for 2 seconds\n",omp_get_thread_num());
            nanosleep((const struct timespec[]){{2,0}},NULL);
            printf("Thread %d is awake!\n",omp_get_thread_num());
        }

        #pragma omp single nowait // optional nowait
        {
            printf("Thread %d is sleeping for 2 seconds\n",omp_get_thread_num());
            nanosleep((const struct timespec[]){{2,0}},NULL);
            printf("Thread %d is awake!\n",omp_get_thread_num());
        }
        
        printf("Goodbye from thread %d\n",omp_get_thread_num());
    }

    return 0;
}