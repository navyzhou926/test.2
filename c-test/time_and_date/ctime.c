#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    time_t t;

    time(&t);
    printf("Today's date and time: %s\n",ctime(&t));
    
    return 0;
}
