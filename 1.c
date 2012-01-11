#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 1;
    int j = 2;
    int k;

    printf("i = %d\n",--i);
    printf("i = %d\n",--i);

    i = 1;
    j = 2;
    k = ++i+j++;
    printf("i = %d\n",i);
    printf("j = %d\n",j);
    printf("k = %d\n",k);
    //(a > b)?a:b;
    
    return 0;
}

