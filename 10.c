#include <stdio.h>
#include <unistd.h>

#define LEN 14

char msg[14] = "Hello,world\n";

int main(int argc, const char *argv[])
{
    write(1, msg, LEN);
    _exit(0);
    //return 0;
}

