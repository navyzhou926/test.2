#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int a[10];
    int *p = a;

    srand((unsigned int)time(0));

    for (; p < a + 5; p++)
    {
        //sleep(1);
        //srand(i++);
        *p = rand()%50;
    }
    //srand((unsigned)time(0) + 1);
    //srand(2);
    for (; p < a + 10; p++)
    {
        *p = rand()%50;
    }
    for (p = a; p < a + 10; p++)
    {
        printf("a[%d] = %d\n", p-a, *p);
    }
    return 0;
}

