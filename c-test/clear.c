#include <stdio.h>

void set_to_zero(int *q)
{
    *q = 0;
}

int main(int argc, const char *argv[])
{
    int i = 1, j = 1; 
    int *p = &i;

    set_to_zero(p);
    printf("i = %d\n",i);

    set_to_zero(&j);
    printf("j = %d\n",j);

    return 0;
}

