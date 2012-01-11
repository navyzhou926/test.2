#include <stdio.h>
#include <string.h>

typedef void(* fp)(char *);

void say_hello(char *str)
{
    printf("hello %s\n",str);
}

int main(int argc, const char *argv[])
{
    char buf[1024]; char str[256] = "Navy";
    char st[1024] = "  hello    world             navy   zhou   ";
    char p1[256], p2[256], p3[256], p4[256];

    sprintf(buf, "hello %s", str);
    printf("%s\n",buf);

    sscanf(st, "%s %s %s %s",p1, p2, p3, p4);
    printf("%s\n",p1);
    printf("%s\n",p2);
    printf("%s\n",p3);
    printf("%s\n",p4);

    //void(* fp)(char *) = say_hello;
    fp fun = say_hello;
    fun("Navy");
    
    return 0;
}

