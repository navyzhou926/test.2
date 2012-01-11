#include <stdio.h>
#include <string.h>

int *cmp(int *a, int *b)
{
    if (*a > *b)
    {
        return a;
    }
    return b;
}

void get_max(int *a, int len, int *(*fun)(int *x, int *y))
{
    int i;
    int *p;
    int num = 0;

    p = a;
    for (i = 1; i < len; i++) 
    {
        p = cmp(p, a + i);
    }
    printf("The max number is: %d\n",*p);
    printf("The address number is: 0x%p\n",p);
}

int main(int argc, char *argv[])
{
    int a[10] = {1,8,6,3,2,3,5,4,6};
    get_max(a, 9, cmp);

    return 0;
}

