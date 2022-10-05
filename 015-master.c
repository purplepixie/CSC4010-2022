#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello\n");

        #pragma omp master
        printf("There\n");

        if (omp_get_thread_num()==0)
        printf("Also There\n");
        
        printf("Goodbye\n");
    }

    return 0;
}