#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *my_memmove(void *dest, void *src, size_t n)
{
    int i = 0;

    for (i = 0; i < n; i++) 
    {
        if (((src + i) == NULL) || ((dest + i) == NULL)) 
        {
            break;
        }
        *((char *)dest + i) = *((char *)src + i);
    }
    *((char *)dest + i) = '\0';

    return dest;
}

int main(int argc, const char *argv[])
{
    char src_char[256] = "hello world My name is ZhouHaijun";
    char dest_char[256];
    int i = 0;
    int src_int[256] = {1, 2, 3, 4, 5}; 
    int dest_int[256] = {0}; 

    my_memmove(dest_char, src_char, 12);
    my_memmove(dest_int, src_int, 20);

    printf("\ndest_char is \"%s\"\n",dest_char);

    printf("\ndest_int is: ");
    for (i = 0; i < 5; i++) 
    {
        printf("%d  ", dest_int[i]);
    }
    printf("\n\n");

    return 0;
}

