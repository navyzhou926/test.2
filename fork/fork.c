#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
        while (1)
        {
            usleep(500000);
            printf("%d\n",getpid());
            printf("parent'parent pid is %d\n",getppid());
            printf("child\n");
        }
    }
    else
    {
        while (1)
        {
            sleep(1);
            printf("parent1 pid is %d\n",getpid());
            printf("parent2 pid is %d\n",getppid());
            printf("parent pid is %d\n",pid);
        }
    }

    return 0;
}

