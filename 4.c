#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{ //char *p;
    char *p = "hello world";
    char a[] = "hello world";
    char *q = a;
    //p = (char *)malloc(12);
    //p = "hello world";
    //*p = 'a';
    //*(p + 1) = 'E';
    *(q + 1) = 'E';
    //strcpy(p, "world hello");
    printf("%s\n",p);
    //free(p);
    printf("%s\n",a);
    printf("%d,%d,%d,%d\n",sizeof(p), sizeof(*q), sizeof(a), strlen(p));

    //int *p1 = {1,2,3,4,5};
    int *p1;
    int b[] = {1,2,3,4,5};
    int *q1 = b;
    printf("%d,%d,%d\n",sizeof(*p1), sizeof(*q1), sizeof(b));

    return 0;
}
