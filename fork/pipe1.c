#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int fd[2];
    pid_t pid;
    char line[MAXLINE];
    int read_res;

    if (pipe(fd) < 0) 
    {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork()) < 0) 
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0) 
    {
        close(fd[1]);
        read_res = read(fd[0], 0, 1);
        if (read_res == 0) 
        {
            printf("Parent is closed\n");
        }
        while (1) 
        {
            printf("Child is run\n");
            sleep(1);
        }
    }
    else
    {
        sleep(3);
        exit(0);
    }

    return 0;
}

