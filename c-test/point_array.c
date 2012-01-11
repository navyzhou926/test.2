#include <stdio.h>

int main(int argc, const char *argv[])
{
    int *p[4];
    int a[5] = {0xabcdef56, 2, 3, 4};
    int a1[5] = {1234}; // {0x04d2, 0, 0, 0, 0};
    char b[5] = {"5678"};

    p[0] = a;
    p[1] = &b;

    printf("%d\n",*(a + 1));
    printf("%d\n",a[1]);

    printf("%d\n",*(p[0] + 1));
    printf("%d\n",(p[0])[1]);
    printf("%d\n",*(*p + 1));

    printf("%x\n",*((char *)p[0] + 1));
    printf("%x\n",((char *)p[0])[1]);
    printf("%x\n",*((char *)*p + 1));

    printf("%c\n",((char *)p[1])[1]);
    printf("%c\n",*((char *)p[1] + 1));
    printf("%c\n",*((char *)*(p + 1) + 1));


    p[0] = a1;
    p[1] = &b;

    printf("\n%d\n",*(a1 + 1));
    printf("%d\n",a1[1]);

    printf("%d\n",*(p[0] + 1));
    printf("%d\n",(p[0])[1]);
    printf("%d\n",*(*p + 1));

    printf("%x\n",*((char *)p[0] + 1));
    printf("%x\n",((char *)p[0])[1]);
    printf("%x\n",*((char *)*p + 1));

    printf("%c\n",((char *)p[1])[1]);
    printf("%c\n",*((char *)p[1] + 1));
    printf("%c\n",*((char *)*(p + 1) + 1));

    return 0;
}

