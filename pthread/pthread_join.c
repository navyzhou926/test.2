#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thr_fn1(void *arg)
{
    printf("thread 1 returning\n");
    return (void *)1;
}

void *thr_fn2(void *arg)
{
    printf("thread 1 exiting\n");
    pthread_exit((void *)2);
}

void *thr_fn3(void *arg)
{
    while (1) 
    {
        printf("thread 3 writing\n");
        sleep(1);
    }
}

int main(int argc, const char *argv[])
{
    pthread_t tid;
    void *tret = NULL;
    int error;

    error = pthread_create(&tid, NULL, thr_fn1, NULL);
    if (error != 0) 
    {
        fprintf(stderr, "can't create thread:%s",strerror(error));
        exit(1);
    }
    //error = pthread_join(tid, &tret);
    error = pthread_detach(tid);
    if (error != 0) 
    {
        fprintf(stderr, "can't pthread_join thread:%s",strerror(error));
        exit(1);
    }
    printf("thread 1 exit code %d\n",(int)tret);

    error = pthread_create(&tid, NULL, thr_fn2, NULL);
    if (error != 0) 
    {
        fprintf(stderr, "can't create thread:%s",strerror(error));
        exit(1);
    }
    //error = pthread_join(tid, &tret);
    error = pthread_detach(tid);
    if (error != 0) 
    {
        fprintf(stderr, "can't pthread_join thread:%s",strerror(error));
        exit(1);
    }
    printf("thread 2 exit code %d\n",(int)tret);

    error = pthread_create(&tid, NULL, thr_fn3, NULL);
    if (error != 0) 
    {
        fprintf(stderr, "can't create thread:%s",strerror(error));
        exit(1);
    }
    sleep(3);
    pthread_cancel(tid);
    //error = pthread_join(tid, &tret);
    //error = pthread_detach(tid);
    if (error != 0) 
    {
        fprintf(stderr, "can't pthread_join thread:%s",strerror(error));
        exit(1);
    }
    printf("thread 3 exit code %d\n",(int)tret);

    return 0;
}

