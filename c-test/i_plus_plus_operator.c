#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 5;
    int i = 0;

    //printf("%d,%d\n",i++, i++);
    printf("a++*a++-a++ = %d, a = %d\n",a++*a++-a++, a);
    printf("a = %d\n",a);

    a = 5;
    printf("a++-a++ = %d, ++a*a++ = %d\n",a++-a++, ++a*a++);
    printf("a = %d\n",a);

    a = 5;
    printf("a+++a++ = %d, a++*a++ = %d\n",a+++a++, a++*a++);
    printf("a = %d\n",a);

    a = 5;
    printf("++a = %d, a++-a++ = %d\n",++a, a++-a++);
    printf("a = %d\n",a);

    a = 5;
    printf("++a = %d, a = %d\n",++a, a);
    printf("a = %d\n",a);
    //printf("%d,%d\n",a++, a);

    return 0;
}
