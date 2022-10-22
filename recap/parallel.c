#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    #pragma omp parallel
    {
        int delay = rand()%5;
        #pragma omp for schedule(dynamic)
        for (int i=0; i<20; ++i)
        {
            printf("Hello from thread %d where i=%d sleeping for %d\n",omp_get_thread_num(),i,delay);
            nanosleep((const struct timespec[]){{delay,0}},NULL);
            printf("Hello again from thread %d where i=%d\n",omp_get_thread_num(),i);
        }
    }
    
}