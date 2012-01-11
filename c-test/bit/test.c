#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 2;
    int b = 5;
    int c = 0;
    int d = 0;

    a = a ^ b ^ b;
    printf("a = %d\n",a);

    c = a ^ b;
    printf("c = %d\n",c);
    d = c ^ b;
    printf("d = %d\n",d);

    a = 2;
    b = 5;
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    return 0;
}
