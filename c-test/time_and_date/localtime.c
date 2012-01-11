#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    time_t timer;
    struct tm *tblock;

    timer = time(NULL);
    tblock = localtime(&timer);
    printf("Local time is: %s\n",asctime(tblock));
    
    return 0;
}
