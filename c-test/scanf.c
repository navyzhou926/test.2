#include <stdio.h>
#include <stdlib.h>

void print_hello_to_me(int n)
{
    printf("Say hello to Navy\n");
}

int main(int argc, const char *argv[])
{
    char a[5];
    //a = (char *)malloc(5);
    scanf("%6s",a);
    printf("%s\n",a);
    scanf("%s",a);
    printf("%s\n",a);
    //free(a);
    return 0;
}
