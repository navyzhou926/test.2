#include <stdio.h>
#include <string.h>

char *cmp(char *a, char *b)
{
    if (*a > *b)
    {
        return a;
    }
    return b;
}

void get_max(char *a, int len, char *(*fun)(char *x, char *y))
{
    char i;
    char *p;
    char num = 0;

    p = a;
    for (i = 1; i < len; i++) 
    {
        p = fun(p, a + i);
    }
    printf("The max number is: %c\n",*p);
    printf("The address number is: 0x%p\n",p);
}

int main(int argc, char *argv[])
{
    char a[10] ={"slkdwldk"};

    get_max(a, strlen(a), cmp);

    return 0;
}

