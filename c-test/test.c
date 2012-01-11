#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    char b,c;
    char aa[10]={"abc"};
    int a[5]={1,2,3,4,5};
    int *p=0;
    i=1;
    p=a;
    //p=&i;
    //aa[3]=2;
    //aa[4]=3;
    //aa[5]=0;
    printf("%d\n",a[1]);
    //*p=2;
    printf("%d\n",*(a+1));
    
    printf("%p\n",a);
    printf("%p\n",a+1);
    
    printf("%p\n",p);
    printf("%p\n",p+1);
    //for (i = 0; i < 10; i++) 
    //{
    //putchar(getchar());
    //}
    //printf("%s\n",aa);
    //a=getchar();
    //getchar();
    //b=getchar();
    //getchar();
    //c=getchar();
    //getchar();
    //printf("%c,%c,%c\n",a,b,c);
    putchar('\n');

    return 0;
}

