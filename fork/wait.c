#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int num = 1;
    int res, res1;

    res = fork();
    if (res < 0) 
    {
        perror("fork");
        exit(-1);
    }


    if (res > 0) 
    {
        while (1)
        {
            sleep(1);
            printf("parent\n");
            wait(); // recycle child process or wait until child process terminated
            printf("child process killed\n");
        }
    }

    if (res == 0) 
    {
        while (1)
        {
            usleep(500000);
            printf("child\n");
        }
    }

    return 0;
}
