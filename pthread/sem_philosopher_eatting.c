#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 256

int num;
pthread_t tid[MAX];
pthread_mutex_t count_mutex[MAX];

void *philosopher(void *arg)
{
    int i = *(int *)arg;
    int left_i, right_i;
    if (i == 0) 
        left_i = num-1; 
    else 
        left_i = i-1;
    right_i = i; 
    //while ((pthread_mutex_trylock(&count_mutex[left_i]) != 0))
    //{
        //sleep(rand()%10);
    //}
    while (1) 
    {
        sleep(rand()%5);
        //usleep(3);
        pthread_mutex_lock(&count_mutex[left_i]);
        printf("Philosopher%d fetches chopstick %d\n",i + 1, left_i + 1);
        pthread_mutex_lock(&count_mutex[right_i]);
        printf("Philosopher%d fetches chopstick %d\n",i + 1, right_i + 1);
        sleep(rand()%5);
        //usleep(3);
        pthread_mutex_unlock(&count_mutex[left_i]);
        pthread_mutex_unlock(&count_mutex[right_i]);
        printf("Philosopher%d releases chopsticks %d %d\n",i + 1, left_i + 1, right_i + 1);
    }

    return NULL;
}


int main(int argc, const char *argv[])
{
    int i;

    if (argc != 2) 
    {
        printf("Input format is %s number\n",argv[0]);
        exit(1);
    }
    num = atoi(argv[1]);

    for (i = 0; i < num; i++) 
    {
        pthread_mutex_init(&count_mutex[i], NULL);
    }

    for (i = 0; i < num; i++) 
    {
        pthread_create(&tid[i], NULL, philosopher, &i);
    }
    while (1) 
    {
        ;
    }

/*
    sem_init(&blank_number, 0, NUM);
    sem_init(&product_number, 0, 0);
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    sem_destroy(&blank_number);
    sem_destroy(&product_number);
    */

    return 0;
}
