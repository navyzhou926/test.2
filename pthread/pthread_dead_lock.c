#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#define NLOOP 5000

int counter;
pthread_mutex_t counter_mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t counter_mutex2 = PTHREAD_MUTEX_INITIALIZER;

void *doit1(void *vptr)
{
    int i;

    for (i = 0; i < NLOOP; i++) 
    {
        pthread_mutex_lock(&counter_mutex1);
        printf("%x: %d\n",(unsigned int)pthread_self(), ++counter);
        printf("pthread 1 is dead lock\n");
        pthread_mutex_lock(&counter_mutex2);
        pthread_mutex_unlock(&counter_mutex1);
    }

    return NULL;
}

void *doit2(void *vptr)
{
    int i;

    for (i = 0; i < NLOOP; i++) 
    {
        pthread_mutex_lock(&counter_mutex2);
        printf("%x: %d\n",(unsigned int)pthread_self(), ++counter);
        printf("pthread 2 is dead lock\n");
        pthread_mutex_lock(&counter_mutex1);
        pthread_mutex_unlock(&counter_mutex2);
    }

    return NULL;
}

int main(int argc, const char *argv[])
{
    pid_t pid;

    pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(-1);
    }

    if (pid == 0) 
    {
        pthread_t tidA, tidB;

        pthread_create(&tidA,NULL, &doit1, NULL);
        pthread_create(&tidB,NULL, &doit2, NULL);

        pthread_join(tidA, NULL);
        pthread_join(tidB, NULL);
    }
    else
    {
        printf("parent 1\n");
        sleep(1);
        printf("parent 2\n");
        sleep(1);
        printf("parent 3\n");
        sleep(1);
        kill(pid, 9);
        printf("child process exit succeed\n");
        printf("parent process exit succeed\n");
    }

    return 0;
}

