#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINE 80

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

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
        //close(fd[0]);
        sleep(1);
        write(fd[1], "hello world\n", 12);
        printf("write success\n");
    }
    else
    {
        //close(fd[1]);
        write(fd[1], "Jack\n", 5);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
        printf("read success\n");

        wait();
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
        //wait(NULL);
    }

    return 0;
}
