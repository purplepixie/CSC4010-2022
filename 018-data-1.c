#include <stdio.h>
#include <omp.h>

int main()
{
    int i=10, j=10;
    // options include: private shared firstprivate
    #pragma omp parallel default(none) shared(i) firstprivate(j)
    {
        ++i;
        ++j;
        printf("i=%d,j=%d in thread %d\n",i,j,omp_get_thread_num());
    }

    printf("Finally i=%d,j=%d\n",i,j);
}