#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void child(int num)
{
    wait(NULL);
    printf("child1 process exit successfully\n");
}

int main(int argc, const char *argv[])
{
    pid_t pid;
    struct sigaction newsig;

    pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(-1);
    }

    if (pid == 0) 
    {
        usleep(500000);
        printf("child\n");
        //sleep(5);
        printf("child\n");
        exit(1);
    }
    else
    {
        pid = fork();
        if (pid < 0) 
        {
            perror("fork");
            exit(-1);
        }

        if (pid == 0) 
        {
            usleep(500000);
            printf("child1\n");
            sleep(5);
            printf("child1\n");
            exit(1);
        }
        else
        {
            newsig.sa_handler = child;
            newsig.sa_flags = 0;
            sigemptyset(&newsig.sa_mask);

            sigaction(SIGCHLD, &newsig, NULL);
            while (1) 
            {
                sleep(1);
                printf("parent\n");
            }
        }
    }

    return 0;
}
