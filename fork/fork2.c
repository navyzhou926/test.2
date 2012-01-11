#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int num = 1;
    pid_t pid;

    pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(-1);
    }


    if (pid == 0) 
    {
        pid = fork();
        pid = fork();
        if (pid == 0) 
        {
            while (1)
            {
                usleep(500000);
                printf("child %d\n",getpid());
            }
        }
        else
        {
            while (1)
            {
                usleep(500000);
                printf("parent1%d\n",getpid());
            }
        }
    }

    if (pid > 0) 
    {
        while (1)
        {
            sleep(1);
            printf("parent %d\n",getpid());
        }
    }


    return 0;
}
