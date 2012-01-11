#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    long result;
    long x = -12345678L;

    result = labs(x);
    printf("Number: %ld abs value: %ld\n",x, result);
    
    return 0;
}
