#include <stdio.h>
#include <time.h>

void delay(int x)
{
    int y, z;
    for (y = x; y > 0; y--)
        for (z = 100000; z > 0; z--);
}

int main(int argc, const char *argv[])
{
    double start, end;
    int i;
    //delay(1);
    //sleep(1);
    //printf("%u\n",clock());
    //delay(1);
    //sleep(1);

    //printf("%f\n",(float)clock());
    //while (1) 
    //{
    //printf("%f\n", (float)clock());
    //delay(10000);
    //}
    printf("%d\n",sizeof(long int));
    start = clock();
    //delay(100);
    int z;
    for (i = 0; i < 300; i++) 
    {
        z = 10000;
        while(z--);
    }
    end = clock();
    printf("%le\n",end-start);

    return 0;
}

