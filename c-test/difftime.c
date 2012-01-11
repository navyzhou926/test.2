#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    time_t  first, second;

    first = time(NULL);
    sleep(2);
    second = time(NULL);

    printf("The difference is: %f seconds\n", difftime(second, first));
    
    return 0;
}
