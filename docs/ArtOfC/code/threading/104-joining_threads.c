#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define NTHREADS 30

void * worker (void *data)
{
    long datum = (long) data;
    int slptm = (int) datum;

    printf("Worker #%ld: will sleep for %ds now ...\n", datum, slptm);
    sleep(slptm);
    printf(" worker #%ld: work (eyeroll) done, exiting now\n", datum);


    /*
    Terminate with success: status value 0
    The join will pick this up.
    */
    pthread_exit((void *)0);
}


int main(void) 
{
    long i;
    int ret, stat=0;
    pthread_t tid[NTHREADS];
    pthread_attr_t attr;

    // Init the thread attribute structure to defaults
    pthread_attr_init(&attr);

    // create all threads as joinable
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


    // Thread creation loop
    for (i=0; i<NTHREADS; i++)
    {
        ret = pthread_create(&tid[i], NULL, worker, (void *)i);

        if (ret)
            printf("pthread_create() failed! [%d]\n", ret);
    }
    pthread_attr_destroy(&attr);


    // Thread join loop
    for (i=0; i<NTHREADS; i++)
    {
        printf("main: joining (waiting) upon thread #%ld ...\n", i);
        ret = pthread_join(tid[i], (void **)&stat);
        if (ret)
            printf("pthread_join() failed! [%d]\n", ret);
        else
            printf("Thread #%ld successfully join; it terminated with"
                    "status=%d\n", i, stat);
    }
    printf("\nmain: now dying... <Dramatic!> Farewell!\n");
    pthread_exit(NULL);
    return 0;
}