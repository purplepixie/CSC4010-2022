#include <stdio.h>
#include <omp.h>

int main()
{
    int counter = 0;
    #pragma omp parallel
    {
        int tc = counter;
        printf("Hello from thread %d\n",omp_get_thread_num());
        tc++;
        counter = tc;
    }

    printf("The final counter is %d\n",counter);

    return 0;
}