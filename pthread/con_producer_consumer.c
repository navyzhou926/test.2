#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct msg
{
    int num;
    struct msg *next;
};

struct msg *head;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_cond_t has_consume = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *p)
{
    struct msg *mp;
    while (1) 
    {
        mp = malloc(sizeof(struct msg));
        mp->num = rand() % 1000 + 1;
        printf("Produce %d\n",mp->num);
        pthread_mutex_lock(&lock);
        mp->next = head;
        head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);
        sleep(rand() % 3);
        //pthread_cond_wait(&has_consume, &lock1);
    }
}

void *consumer(void *p)
{
    struct msg *mp;

    while (1) 
    {
        pthread_mutex_lock(&lock);
        while (head == NULL) 
        {
            pthread_cond_wait(&has_product, &lock);
        }
        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&lock);
        printf("Consume %d\n",mp->num);
        free(mp);
        sleep(rand() % 3);
        //pthread_cond_signal(&has_consume);
    }
}

int main(int argc, const char *argv[])
{
    pthread_t pid, cid;

    srand(time(NULL));
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}

