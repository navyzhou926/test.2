#include <stdio.h>
#include <string.h>

//char *cmp_char(char *a, char *b)
//{
//if (*a > *b)
//{
//return a;
//}
//return b;
//}
//int *cmp_int(int *a, int *b)
//{
//if (*a > *b)
//{
//return a;
//}
//return b;
//}

void *cmp_char(void *a, void *b)
{
    if (*(char *)a > *(char *)b)
    {
        return a;
    }
    return b;
}

void *cmp_int(void *a, void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return a;
    }
    return b;
}

void get_max(void *a, int len, int size, void *(*fun)(void *x, void *y))
{
    int i;
    void *p;
    int num = 0;

    if (size == 1 ) 
    {
        p = (char *)a;
        for (i = 1; i < len; i++) 
        {
            p = fun(p, a + i);
        }
        printf("The max number is: %c\n",*(char *)p);
    }
    if (size == 4) 
    {
        p = (int *)a;
        for (i = 1; i < len; i++) 
        {
            p = fun(p, a + 4*i);
        }
        printf("The max number is: %d\n",*(int *)p);
    }
    printf("The address is: %p\n",p);
}

int main(int argc, char *argv[])
{
    int a[10] = {1,8,6,3,2,3,5,4,6};
    char b[10] = {"dwolzpcda"};

    get_max(a, sizeof(a)/4, 4, cmp_int);
    get_max(b, strlen(b), 1, cmp_char);

    return 0;
}

