#include <stdio.h>

//#pragma pack(4)
//#pragma pack(push, 4)
//#pragma pack(pop)
struct h_t 
{
    int c;
    short m;
    char b;
    short n;
    char o;
    int l;
    char g[5];
    char r;
    //double e;
    //short a;
    //int h[5];
}x,*p = &x;

int main(int argc, const char *argv[])
{
    int a = 5;
    int *q = &a;

    printf("%d,%d,%d\n",sizeof(x), sizeof(*p), sizeof(*q));

    #pragma message "Hello world"

    char *p;   // 4
    char *q1[20];   // 80
    char *m[20][20];  // 1600
    int (*n)[10];   // 4
    struct MyStruct
    { 
        char dda; 
        double dda1; 
        int type;
    }k; 
    printf("%d %d %d %d %d\n",sizeof(p),sizeof(q1),sizeof(m),sizeof(n),sizeof(k));
    printf("%d\n",sizeof(*n));

    return 0;
}

