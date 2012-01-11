#include <stdio.h>
#include <signal.h>

void printsigset(const sigset_t *set)
{
    int i;
    for (i = 1; i < 32; i++) 
    {
        if (sigismember(set, i) == 1) 
        {
            printf("%-3d",1);
        }
        else
        {
            printf("%-3d",0);
        }
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    sigset_t s, p;

    sigemptyset(&s);
    sigaddset(&s, SIGINT);
    sigprocmask(SIG_BLOCK, &s, NULL);
    while (1) 
    {
        sigpending(&p);
        printsigset(&p);
        sleep(1);
    }

    return 0;
}

