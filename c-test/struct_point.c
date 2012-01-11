#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct alloc
{
    int x[5];
    int y;
}a, *q = &a;

int main(int argc, const char *argv[])
{
    int i;
    char *p;
    //p = (char *)malloc(10);
    //if(p == NULL)
    ////exit(0);
    //return 1;
    //for (i = 0; i < 10; i++) 
    //{
    //*(p + i) = i + '0';
    //}
    //printf("%s\n",p);
    //free(p);

    q = (struct alloc *)malloc(sizeof(a));
    if (q == NULL) 
        return 1;
    for (i = 0; i < 5; i++) 
    {
        q->x[i] = i;
    }    

    q->y = 10;
    for (i = 0; i < 5; i++) 
    {
        printf("%d",q->x[i]);
    }
    printf("\n%d\n",q->y);

    return 0;
}

