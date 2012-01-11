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
        }
    }

    if (res == 0) 
    {
        while (1)
        {
            usleep(500000);
            execl("/home/navyzhou/test.2/hello", "hello", NULL);
            //execlp("./hello", "hello", NULL);
            //execv("/home/navyzhou/test.2/", NULL);
            execvp("./hello", NULL);
            //execle("/home/navyzhou/test.2/hello", "hello", NULL, "ls");
            printf("child\n");
            exit(-1);
        }
    }

    return 0;
}
