#include <stdio.h>

int main(int argc, const char *argv[])
{
    int handle;

    handle = fileno(stdin);
    if (isatty(handle)) 
    {
        printf("Handle %d is a device type\n",handle);
    }
    else
    {
        printf("Handle %d isn't a device type\n",handle);
    }
    
    return 0;
}

