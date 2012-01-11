#include <stdio.h>
#include <signal.h>

volatile int a = 0;

void fun(int num)
{
    printf("akaedu\n");
    a = 1;
}

int main(int argc, const char *argv[])
{
    struct sigaction newsig;

    newsig.sa_handler = fun;
    newsig.sa_flags = 0;
    sigemptyset(&newsig.sa_mask);

    sigaction(SIGINT, &newsig, NULL);
    while (1) 
    {
        sleep(1);
        printf("%d\n",a);
        printf("hello\n");
    }

    return 0;
}

