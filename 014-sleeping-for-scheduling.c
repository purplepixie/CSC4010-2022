#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    #pragma omp parallel
    {
        int sleep = rand()%5;
        printf("Hello from thread %d I am sleeping for %d seconds\n",
            omp_get_thread_num(), sleep);
        nanosleep((const struct timespec[]){{sleep,0}},NULL);

        printf("Thread %d has finished sleeping\n",omp_get_thread_num());

        #pragma omp for schedule(guided) // different modes i.e. static/dynamic/guided
        for(int i=0; i<20; ++i)
        {
            printf("i=%d in thread %d\n",i,omp_get_thread_num());
        }
    }   

    printf("All threads finished - parallel region over\n");

    #pragma omp parallel
    {
        printf(".");
    } 
    printf(" FINISH\n");

    return 0;
}