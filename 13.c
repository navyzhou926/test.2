#include <stdio.h>

#define YEAR (365*24*60*60)
#define xname(n) x##n

fun1(void)
{
    printf("%d\n",YEAR);
}

fun2(void)
{
    xname(8);
}

int main(int argc, const char *argv[])
{
    unsigned int a = 6;
    int b = -20;
    int ret;

    ret = fun1();
    printf("ret1 = %d\n",ret);
    ret = fun2();
    printf("ret2 = %d\n",ret);

    (a + b > 6) ? puts(">6"):puts("<=6");

    printf("a + b = %d\n",a+b);

    return 0;
}
