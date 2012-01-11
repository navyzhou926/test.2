#include <stdio.h>

int sum(int a[], int n)
{
    if (n > 0) 
        return (a[--n] + sum(a, n));
    else 
        return 0;
}

int main(int argc, const char *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};

    printf("sum is %d\n",sum(a, 8));

    return 0;
}

