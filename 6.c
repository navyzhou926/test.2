#include <stdio.h>
#include <string.h>
#include <time.h>

int j = 3;

#define DOUBLE(x) (x+x) ; j = 5*DOUBLE(2);
//#define DOUBLE(x) x+x 
//j = 5*DOUBLE(2);
//char p[] = "hello world ";
char p[20];

char * get_memory(void)
{
    strcpy(p,"hello world ");
    return p;
}

void test(void)
{
    char *str = NULL;
    str = get_memory();
    puts(str);
}

void function_name(char aa[100])
{
    printf("%d\n",sizeof(aa));
}

int main(int argc, const char *argv[])
{
    int i = 0;
    int a[10];
    int *p = a;

    printf("j = %d\n",j);

    //srand((unsigned)time(0));
    srand((unsigned int)time((void *)0));
    //srand(2);
    #if 0
    for (i = 0; i < 10; i++) 
    {
        a[i] = rand()%50;
    }
    #else
    for (; p < a + 10; p++)
    {
        //sleep(1);
        //srand(i++);
        *p = rand()%50;
    }
    #endif
    for (p = a; p < a + 10; p++)
    {
        printf("a[%d] = %d\n", p-a, *p);
    }

    return 0;
}

