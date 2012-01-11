#include <stdio.h>

#define PRINT(x) printf(#x" = %d\n", x);
#define ID(n) i##n

void print(void)
{
    int ID(1) = 4, ID(2) = 5, ID(3) = 6;

    PRINT(ID(1));
    PRINT(ID(2));
    PRINT(ID(3));

    PRINT(i1);
    PRINT(i2);
    PRINT(i3);

    PRINT(2);
}

union test
{
    int a;
    char b[2];
}c = {0x1234};

int main(int argc, const char *argv[])
{

    print();

    printf("c.a = 0x%x\n",c.a);
    printf("&c.b[0] = %p \n",&c.b[0]);
    printf("&c.b[1] = %p \n",&c.b[1]);
    printf("c.b[0] = 0x%x\n",c.b[0]);
    printf("c.b[1] = 0x%x\n",c.b[1]);

    return 0;
}

