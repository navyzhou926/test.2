#include <stdio.h>

typedef int (* fun)(int, int);

int plus(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return a/b;
}

int mod(int a, int b)
{
    return a%b;
}

struct calculator
{
    char op;
    int (*handle)(int, int);
}arr[]= { {'+', plus}, {'-', minus}, {'*', multiply}, {'/', divide}, {'%', mod} };

int main(int argc, char *argv[])
{
    int i, a, b, ret;
    char num;
    fun count;
    while (1) 
    {
        scanf("%c", &num);
        if (num == '#') 
        {
            break;
        }
        scanf("%d %d", &a, &b);
        for (i = 0; i < 5; i++) 
        {
            if (arr[i].op == num)
            {
                ret = arr[i].handle(a, b);
                printf("%d %c %d = %d\n", a, num, b, ret);
                break;
            }
        }
        getchar();
    }

    return 0;
}

