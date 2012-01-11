#include <stdio.h>
#include <ctype.h>

union data
{
    unsigned long a;
    char b[4];
}u = {0xabcdef98};

int main(int argc, const char *argv[])
{
    int i = 0;
    int d = 3, g = 3;
    char a[] = "This is my";
    char e[30];
    int b[] = {1,2,3,4,5,6,7,8,9};
    //printf("%6.7s\n",a);
    printf("%d,%d,%d,%d,%d\n",sizeof(short),sizeof(int), sizeof(long int), sizeof(float), sizeof(double));
    printf("%x %x %x %x\n",u.b[0], u.b[1], u.b[2], u.b[3]);
    printf("%p,%p\n",a + 1,&a + 1);
    printf("%p,%p\n",b + 1, &b + 1);
    //printf(#g" = %d\n",g);
    //gets(e);
    //scanf("%3s",e);
    //puts(e);
    //printf("%d,%d\n",getchar(), getchar());

    //printf("%c\n",tolower(h));
    //printf("%c\n",toupper(h));
    //printf("%d\n",isalpha('/'));
    printf("%d,%d,\n",i++, i++);
    printf("%d\n",i);
    return 0;
}

