#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int isPrime(unsigned long x)
{
    unsigned long max = x/2;
    if (x<=2) return 1;
    if ((x%2)==0) return 0;
    for (unsigned long i=3; i<=max; i+=2)
    {
        //printf("%d M %d = %d\n",x,i,(x%i));
        if ((x%i) == 0) return 0;
    }
    return 1;
}

struct range
{
    unsigned long start;
    unsigned long end;
};

void *PrimeThread(void *args)
{
    unsigned long tstart=((struct range*)args)->start;
    unsigned long tend=((struct range*)args)->end;
    //printf("Thread from %lu to %lu\n",tstart,tend);
    for(unsigned long x=((struct range*)args)->start ; x<=((struct range*)args)->end ; ++x)
    {
        if (isPrime(x)==1) printf(".");
    }
    return NULL;
}

int main(int ac, char** av)
{
    unsigned long start = 100000000;
    unsigned long end = 100005000;

    int num_threads = 10;

    if (ac>1) start=atol(av[1]);
    if (ac>2) end=atol(av[2]);
    if (ac>3) num_threads=atoi(av[3]);

    unsigned long diff = end-start;
    printf("From %lu to %lu = %lu numbers\n",start,end,diff);

    printf("Using %d threads.\n",num_threads);

    unsigned long thread_range = diff / num_threads;

    printf("Thread range is %lu per thread.",thread_range);

    unsigned long tstart = start;
    unsigned long tend = start + thread_range;

    pthread_t thread[num_threads];

    for(int t=0; t<num_threads; ++t)
    {
        struct range *range_args = (struct range *)malloc(sizeof(struct range));
        range_args->start=tstart;
        range_args->end=tend;
        //printf("Starting thread ID %d from %lu to %lu\n",t,tstart,tend);
        pthread_create(&thread[t], NULL, PrimeThread, (void *)range_args);

        tstart = tend+1;
        tend = tstart + thread_range;
        if (tend>end) tend=end;
    }

    for (int t=0; t<num_threads; ++t)
    {
        //printf("Joining thread %d\n",t);
        pthread_join(thread[t], NULL);
    }

    printf("\n");
    return 0;
}