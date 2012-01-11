#include <stdio.h>

enum week {MON = 0, TUE = 1, WEN, THU, FRI, SAT, SUN};

int main(int argc, const char *argv[])
{
    enum week day; 

    printf("sizeof enum is %d\n",sizeof(enum week));
    //printf("%s\n",day);
    day = WEN;
    printf("%d\n",day);

    return 0;
}

