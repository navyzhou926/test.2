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


    //if (res == getpid()) 
    if (res > 0) 
    {
        printf("parent id is %d\n",res);
        res1 = fork();
        if (res1 < 0) 
        {
            perror("fork");
            exit(-1);
        }

        if (res1 > 0) 
        {
            while (1)
            {
                sleep(1);
                printf("parent1 id is %d\n",res1);
                printf("parent\n");
            }
        }

        if (res1 == 0) 
        {
            while (1)
            {
                usleep(500000);
                printf("child1 id is %d\n",res1);
                printf("parent_child\n");
            }
        }
    }

    if (res == 0) 
    {
        while (1)
        {
            usleep(500000);
            printf("child id is %d\n",res);
            printf("child\n");
        }
    }

    return 0;
}
