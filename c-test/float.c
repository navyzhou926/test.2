#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(char *p)
{
    //p = "hello world!";
    //p = (char *)malloc(4);
    *p = '1';
    printf("p = %p\n",p);
    //free(p);
}

int main(int argc, const char *argv[])
{
    float i = 5.01; 
    float j = 4.91; 
    //int a = 0x01020304;
    //char *c = (char *)&a;
    char *q = NULL;

    q = (char *)malloc(1);
    printf("q = %p\n",q);
    *q = '2';
    foo(q);
    printf("*q = %c\n",*q);
    free(q);

    printf("%d\n",(int)i);
    printf("%d\n",(int)j);

    return 0;
}

