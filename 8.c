#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *ptr;

    printf("%p\n",ptr);
    if ((ptr = (char *)malloc(0)) == NULL) 
        puts("Got a null pointer");
    else
    {
        puts("Got a valid pointer");
        printf("%p\n",ptr);
    }
    printf("%d\n",sizeof(*ptr));
    *ptr = 'a';
    printf("%c\n",*ptr);

    return 0;
}

