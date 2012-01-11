#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


pid_t create_child(void)
{
    pid_t pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0) 
    {
        printf("in child %d\n",getpid());
        return 0;
    }

    return pid;
}

int main(int argc, const char *argv[])
{
    pid_t pid1, pid2;
    int st1, st2;

    pid1 = create_child();
    pid2 = create_child();

    waitpid(pid1, &st1, 0);
    waitpid(pid2, &st2, 0);
    printf("in parent,pid = %d\n",getpid());
    printf("in parent,child 1 exited with %d\n",st1);
    printf("in parent,child 2 exited with %d\n\n",st2);

    return 0;
}
