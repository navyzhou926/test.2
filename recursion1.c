#include <stdio.h>

int jc(int n)
{
    int ret = 0;

    if (n == 0) 
    {
        return 1;
    }
    else
    {
        ret = n*jc(n-1);
        return ret;
    }
}

int main(int argc, const char *argv[])
{
    int sum = 0;

    sum = jc(3);
    printf("%d\n",sum);
    
    return 0;
}
