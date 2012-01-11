#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *string1 = "1234567890";
    char *string2 = "AB1234DC8";
    int length;

    length = strspn(string1, string2);
    printf("Character where strings differ is at position %d\n",length);
    
    return 0;
}
