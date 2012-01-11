#include <stdio.h>

int  add(int a, int b)
{
    return a + b;
}

int main(int argc, const char *argv[])
{
    int c;
    int (* fun1)(int , int);

    fun1 = add;
    printf("%p\n", fun1);

    c = (* fun1)(1 , 2);
    printf("%d\n", c);

    c = fun1(1 , 2);
    printf("%d\n", c);

    return 0;
}

