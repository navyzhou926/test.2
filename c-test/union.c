#include <stdio.h>
#include <string.h>

union date
{
    int a;
    char b;
    char c[256];
}day;

int main(int argc, const char *argv[])
{
    char *p;
    int sum;
    day.a = 0x3721;

    p = &day.c[0];
    printf("%x, %x\n",*p, *(p+1));
    //day.b = 'd';
    strcpy(day.c, "abc");
    printf("%x,%c,%s\n",day.a, day.b, day.c);
    sum = 'a' + 'b'*256 + 'c'*256*256;
    printf("%x\n",sum);

    printf("%s\n",day.c);
    printf("%s\n",*&day.c);
    printf("%s\n",&day.c[0]);

    return 0;
}

