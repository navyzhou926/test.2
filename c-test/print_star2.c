#include <stdio.h>

void print_symbol(int length)
{
    int i;
    for (i = 0; i < length; i++) 
    {
        printf("* ");
    }
}

void print_matrix(void (*fun)(int length), int width)
{
    int i;
    for (i = 0; i < width; i++) 
    {
        fun(width);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    print_matrix(print_symbol, 5); 

    return 0;
}

