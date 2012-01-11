#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char *username;

    username = getlogin();
    printf("login username: %s\n",username);

    return 0;
}
