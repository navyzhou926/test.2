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

void alarm(void)
{
    printf("Unkown character !\n");
    printf("Please input right character:\n");
}

int main(int argc, char *argv[])
{
    int a, b;
    char num;
    fun count;

    while (1) 
    {
        scanf("%c", &num);
        getchar();
        if (num == '#') 
        {
            break;
        }
        switch (num)
        {
            case '+':
                scanf("%d %d", &a, &b);
                count = plus;
                printf("%d %c %d = %d\n", a, num, b, count(a, b));
                getchar();
                break;
            case '-':
                scanf("%d %d", &a, &b);
                count = minus;
                printf("%d %c %d = %d\n", a, num, b, count(a, b));
                getchar();
                break;
            case '*':
                scanf("%d %d", &a, &b);
                count = multiply;
                printf("%d %c %d = %d\n", a, num, b, count(a, b));
                getchar();
                break;
            case '/':
                scanf("%d %d", &a, &b);
                count = divide;
                printf("%d %c %d = %d\n", a, num, b, count(a, b));
                getchar();
                break;
            case '%':
                scanf("%d %d", &a, &b);
                count = mod;
                printf("%d %c %d = %d\n", a, num, b, count(a, b));
                getchar();
                break;
            default :
                alarm();
                break;
        }
    }
    return 0;
}

