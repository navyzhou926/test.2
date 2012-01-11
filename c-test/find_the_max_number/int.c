#include <stdio.h>
#include <string.h>

int cmp(int *a, int *b)
{
    return  *a - *b;
}

void get_max(int *a, int len, int (*fun)(int *x, int *y))
{
    int i;
    int *p;
    int num = 0;

    p = a;
    for (i = 1; i < len; i++) 
    {
        if (fun(p, a + i) < 0) 
        {
            p = a + i;
            num = i;
        }
    }
    printf("The max number is: %d\n",a[num]);
    printf("The index of the array is: %d\n",num);
    printf("The address number is: 0x%p\n",p);
}

int main(int argc, char *argv[])
{
    int a[10] = {1,8,6,3,9,3,5,4,6};

    get_max(a, sizeof(a)/4, cmp);

    return 0;
}

