#include <stdio.h>

int main(int argc, const char *argv[])
{
    unsigned int i;

//  Program will exit after 1 second
    alarm(1);

    for (i = 0; 1; i++) 
    {
        printf("I = %d\n",i);
    }
    
    return 0;
}
