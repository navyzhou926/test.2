#include <stdio.h>

int main(int argc, const char *argv[])
{
    //printf("%f\n",3.14);
    float a = 3.14;
    float b = 4.12;

    printf("%f\n",3.14 + 4.12);
    printf("sizeof 3.14 is %d\n",sizeof(a + b));
    printf("sizeof 3.14 is %d\n",sizeof(3.14f + 4.12f));
    //printf("3.14l + 4.12l = %ld\n",3.14l + 4.12l);
    printf("sizeof 3.14 is %d\n",sizeof(3.14l + 4.12l));
    printf("%x\n",-3 + 1u);
    printf("%e\n",3.14);
    printf("%i\n",011);
    //printf("%.4s\n","hello");
    return 0;
}

