#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct no_hole
{
    int len;
    char *str;
}a, *p;

int main(int argc, const char *argv[])
{
    int i;
    char *pp;
    a.len = 10;

    //a.str = "abcd";
    a.str = (char *)malloc(sizeof(0));
    printf("%d\n",sizeof(*(a.str)));
    strcpy(a.str, "aaaabbbb");
    //printf("%d\n",sizeof(a));
    printf("%d\n",a.len);
    printf("%s\n",a.str);

    return 0;
}
