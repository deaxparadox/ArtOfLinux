#include<stdio.h>
#include<pthread.h>

#define NTHREADS 3

void * worker (void *data)
{
    long datum = (long) data;

    printf("Worker thread #%ld says: hello, world.\n", datum);
    printf("#%ld: work done, exiting now\n", datum);
}


int main(void) 
{
    long i;
    int ret;
    pthread_t tid;

    for (i=0; i<NTHREADS; i++)
    {
        ret = pthread_create(&tid, NULL, worker, (void *)i);

        if (ret)
            printf("pthread_create() failed! [%d]\n", ret);
    }

    return 0;
}