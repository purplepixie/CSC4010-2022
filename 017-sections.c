#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello from thread %d\n",omp_get_thread_num());

        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Thread %d in first section sleeping\n",omp_get_thread_num());
                nanosleep((const struct timespec[]){{2,0}},NULL);
                printf("Thread %d in first section waking up\n",omp_get_thread_num());
            }

            #pragma omp section
            {
                printf("Thread %d in the second section\n",omp_get_thread_num());
            }
        }
        
        printf("Goodbye from thread %d\n",omp_get_thread_num());
    }

    return 0;
}