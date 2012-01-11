#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[10][8];
    int b[10][8];
    int *p;
    int (*q)[];

    p = b[0];
    q = a;

    return 0;
}
