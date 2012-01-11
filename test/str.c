#include <stdio.h>
#include <string.h>
#include <hello.h>

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    //for (i = 0; i < strlen(src); i++) 
    for (i = 0; dest[i] = src[i]; i++)
    {
        dest[i] = src[i];
    }
    //dest[i+1] = 0;
    
    return  dest;
}

char *my_strcpy1(char *dest, const char *src)
{
    char *p = dest;

    if (src == NULL) 
        return NULL;

    while ((*dest++ = *src++) != '\0');

    return p;

}

char *my_strcpy2(char *dest, const char *src)
{
    int i = 0;

    if (src == NULL) 
        return NULL;

    while (*(dest + i) = *(src + i) != '\0') 
    {
        i++;
    }

    return dest;
}

int main(int argc, const char *argv[])
{
    char str[256] = {0};

    if(argc < 2)
    {
        printf("usage:%s <argument>\n", argv[0]);
        return 0;
    }

    //printf("%s.\n", my_strcpy2(str, argv[1]));
    printf("%s.\n", my_strcpy2(str, "hello"));
    //printf("%s.\n", my_strcpy1(str, '\0'));
    //printf("%s.\n", my_strcpy1(dest, NULL));

    print_hello(3);

    return 0;
}
