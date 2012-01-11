#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NLOOP 5000

int counter;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *doit(void *vptr)
{
    int i;

    for (i = 0; i < NLOOP; i++) 
    {
        pthread_mutex_lock(&counter_mutex);
        printf("%x: %d\n",(unsigned int)pthread_self(), ++counter);
        pthread_mutex_unlock(&counter_mutex);
    }

    return NULL;
}

int main(int argc, const char *argv[])
{
    pthread_t tidA, tidB;

    pthread_create(&tidA,NULL, &doit, NULL);
    pthread_create(&tidB,NULL, &doit, NULL);

    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    return 0;
}

