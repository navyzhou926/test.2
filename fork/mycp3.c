#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>

#define N 4096 

int main(int argc, const char *argv[])
{
    int fd1, fd2, fd3;
    int i = 0, j = 0;
    char str[4];
    int sum;
    struct stat buf;
    unsigned char *src = NULL, *dest = NULL;
    unsigned int *rate = NULL; 
    //void *src = NULL, *dest = NULL;
    int count = atoi(argv[3]);
    pid_t pid, pid1;

    system("clear");

    if (argc != 4) 
    {
        printf("input wrong !\n");
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

    fd3 = open("file3", O_RDWR | O_CREAT, 00776);
    if (fd3 < 0) 
    {
        perror("open");
        exit(1);
    }

    stat(argv[1], &buf);
    src = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    if (src == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }
    lseek(fd2, buf.st_size-1, SEEK_SET);
    write(fd2, "0", 1);
    dest = mmap(NULL, buf.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
    if (dest == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }

    write(fd3, "0", 1);
    rate = mmap(NULL, sizeof(int)*2, PROT_WRITE | PROT_READ, MAP_SHARED, fd3, 0);
    if (rate == MAP_FAILED) 
    {
        perror("map");
        exit(1);
    }
    *rate = 0;
    *(rate + 1) = 0;

    pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(-1);
    }

    if (pid == 0) 
    {
        pid1 = fork();
        if (pid1 < 0) 
        {
            perror("fork");
            exit(-1);
        }

        if (pid1 == 0) 
        {
            //while (1)
            for (i = 0; i < buf.st_size/count; i++) 
            {
                memcpy(dest + i, src + i, 1);
                *rate += 1 ;
                j++;
                if (j == 400000) 
                {
                    j = 0;
                    if (*rate <= buf.st_size)
                    {
                        if (((*rate)*100/buf.st_size) > *(rate + 1)) 
                        {
                            *(rate + 1) = (*rate)*100/buf.st_size;
                            //printf("%ld%%\n",(*rate)*100/buf.st_size);
                            printf("%d%%\n",*(rate + 1));
                        }
                    }
                }
            }
            exit(1);
        }
        else 
        {
            //while (1)
            for (i = buf.st_size/count; i <= buf.st_size; i++) 
            {
                memcpy(dest + i, src + i, 1);
                *rate += 1 ;
                j++;
                if (j == 400000) 
                {
                    j = 0;
                    if (*rate <= buf.st_size)
                    {
                        if (((*rate)*100/buf.st_size) > *(rate + 1)) 
                        {
                            *(rate + 1) = (*rate)*100/buf.st_size;
                            printf("%d%%\n",*(rate + 1));
                        }
                    }
                }
            }
            wait();
            exit(1);
        }

    }
    else
    {
        //while (1)
        {
            wait();
            printf("100%%\n");
            //waitpid(pid, NULL, 0);
            //printf("parent\n");
            munmap(src, buf.st_size);
            munmap(dest, buf.st_size);
            close(fd1);
            close(fd2);
            close(fd3);
            system("rm file3");
            printf("File copy finished\n\n");
        }
    }

    return 0;
}

