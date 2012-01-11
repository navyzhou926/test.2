#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MSG_TRY "try again\n"
#define N 10

int main(int argc, const char *argv[])
{
    char buf[N];
    int fd, n;

    fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
    if (fd < 0) 
    {
        perror("open /dev/tty");
        exit(1);
    }

tryagain:
    n = read(fd, buf, N);
    if (n < 0) 
    {
        if (errno == EAGAIN) 
        {
            sleep(1);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            goto tryagain;
        }
        perror("read /dev/tty");
        exit(1);
    }

    write(STDOUT_FILENO, buf, n);
    close(fd);

    return 0;
}

