#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 0, b = 0;
    int temp;
    int *p = &a;

    printf("p = %p\n",p);
    #if 1
    temp = *p++;
    printf("%d\n",temp);
    #else
    temp = *(p++);
    printf("%d\n",temp);
    #endif
    printf("p = %p\n",p);


    p = &a;
    temp = *++p;
    printf("%d\n",temp);

    return 0;
}
