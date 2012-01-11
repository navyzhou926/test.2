#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define N 4096 

unsigned char *src = NULL, *dest = NULL;
int pthread_count;
int rate = 0, rate1 = 0;
struct stat buf;
pthread_mutex_t rate_mutex = PTHREAD_MUTEX_INITIALIZER;

void *mycp_pthread(void *arg)
{
    int i, a = 0, b = 0;
    int count = *(int *)arg;

    a = ((int)buf.st_size/pthread_count)*count;
    b = a + (int)buf.st_size/pthread_count;

    for (i = a; i < b; i++) 
    {
        memcpy(dest + i, src + i, 1);
        pthread_mutex_lock(&rate_mutex);
        //pthread_mutex_trylock(&rate_mutex);
        rate++;
        pthread_mutex_unlock(&rate_mutex);
    }

    return (void *)1;
}

void *mycp_rate(void *arg)
{
    int i;

    for (i = ((int)buf.st_size/pthread_count)*(*(int *)arg); i < (int)buf.st_size; i++) 
    {
        memcpy(dest + i, src + i, 1);
        pthread_mutex_lock(&rate_mutex);
        rate++;
        if (rate < (int)buf.st_size)
        {
            if ((rate*100/(int)buf.st_size) > rate1) 
            {
                printf("rate = %d\n",rate);
                printf("buf.st_size = %d\n",(int)buf.st_size);
                rate1 = rate*100/(int)buf.st_size;
                printf("%d%%\n",rate1);
            }
        }
        if (rate == (int)buf.st_size) 
        //else
        {
            printf("100%%\n");
            printf("rate = %d\n",rate);
            printf("buf.st_size = %d\n",(int)buf.st_size);
            pthread_mutex_unlock(&rate_mutex);
            return (void *)1;
        }
        pthread_mutex_unlock(&rate_mutex);
    }

    return (void *)1;
}

int main(int argc, const char *argv[])
{
    int fd1, fd2;
    int i = 0, k = 0;
    void *tret = NULL;
    int error;

    pthread_count = atoi(argv[3]);
    pthread_t tid[pthread_count + 1];

    system("clear");

    if (argc != 4) 
    {
        printf("input wrong !\n");
        printf("format is:%s srcfile destfile pthread_number\n",argv[0]);
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) 
    {
        perror("open");
        exit(1);
    }

    fd2 = open(argv[2], O_RDWR | O_CREAT, 00776);
    if (fd2 < 0) 
    {
        perror("open");
        exit(1);
    }

    stat(argv[1], &buf);
    src = mmap(NULL, (int)buf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    if (src == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }
    lseek(fd2, buf.st_size-1, SEEK_SET);
    write(fd2, "0", 1);
    dest = mmap(NULL, (int)buf.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
    if (dest == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }

    for (k = 0; k < pthread_count-1; k++) 
    {
        //if (k == pthread_count-1) 
        //{
            //error = pthread_create(&tid[k], NULL, mycp_rate, &k);
        //}
        //else
        //{
            error = pthread_create(&tid[k], NULL, mycp_pthread, &k);
        //}
        if (error != 0) 
        {
            fprintf(stderr, "can't create thread:%s",strerror(error));
            exit(1);
        }
    }

    for (i = ((int)buf.st_size/pthread_count)*k; i < (int)buf.st_size; i++) 
    {
        memcpy(dest + i, src + i, 1);
        pthread_mutex_lock(&rate_mutex);
        rate++;
        if (rate < (int)buf.st_size)
        {
            if ((rate*100/(int)buf.st_size) > rate1) 
            {
                //printf("rate = %d\n",rate);
                rate1 = rate*100/(int)buf.st_size;
                //printf("\b\b%d%%",rate1);
                printf("%d%%\n",rate1);
            }
        }
        pthread_mutex_unlock(&rate_mutex);
    }
    while (rate != (int)buf.st_size)
    {
        if ((rate*100/(int)buf.st_size) > rate1) 
        {
            //printf("rate = %d\n",rate);
            rate1 = rate*100/(int)buf.st_size;
            //printf("\b\b%d%%",rate1);
            printf("%d%%\n",rate1);
        }
    }
    //printf("\b\b100%%\n");
    printf("100%%\n");
    printf("rate = %d\n",rate);
    printf("buf.st_size = %d\n",(int)buf.st_size);

    for (i = 0; i < pthread_count-1; i++) 
    {
        error = pthread_join(tid[i], &tret);
        //error = pthread_detach(tid[i]);
        if (error != 0) 
        {
            fprintf(stderr, "can't pthread_join thread:%s",strerror(error));
            exit(1);
        }
        //printf("thread %d exit code %d\n",i + 1, (int)tret);
    }

    munmap(src, (int)buf.st_size);
    munmap(dest, (int)buf.st_size);
    close(fd1);
    close(fd2);
    printf("File copy finished\n\n");

    return 0;
}

