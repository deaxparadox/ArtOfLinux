#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NTHREADS 3

void * worker (void *data)
{
    long datum = (long) data;

    printf("Worker thread #%ld says: hello, world.\n", datum);
    printf("#%ld: work done, exiting now\n", datum);

    pthread_exit(NULL);
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

    #if 1
        pthread_exit(NULL);
    #else
        exit(EXIT_SUCCESS);
    #endif

    return 0;
}