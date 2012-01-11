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
            printf("child\n");
        }
    }
    else
    {
        //while (1)
        {
            sleep(1);
            printf("parent\n");
            waitpid(pid, NULL, 0);
            printf("child process killed\n");
        }
    }


    return 0;
}

