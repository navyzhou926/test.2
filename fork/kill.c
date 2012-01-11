#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#define MAXLINE 80

int main(int argc, const char *argv[])
{
    pid_t pid, pid1;
    int n = 0;
    char line[MAXLINE];
    int parent_id;

    parent_id = getpid();

    pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(-1);
    }


    if (pid == 0) 
    {
            sleep(2);
            //kill(getpid()-1, 9);
            //kill(getppid(), 9);
            kill(parent_id, 9);
            //kill(0, 9);
            //kill(pid, 9);
            printf("child exit\n");
            printf("parent ");
            exit(0);
    }
    else
    {
        {
            printf("parent id is %d\n",getpid());
            printf("grandparent id is %d\n",getppid());
        }
        while (1);
    }

    return 0;
}

