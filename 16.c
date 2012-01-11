#include <stdio.h>

int main(int argc, const char *argv[])
{
    printf("%4.3s\n","hello");
    printf("%3.4s\n","hello");
    printf("%3s\n","hello");

    printf("%hhd\n",255);
    printf("%hd\n",255);
    printf("%lld\n",(long long)255);

    double v = 0;
    //while (scanf("%lf", &v) == 1) 
    if (scanf("%lf", &v) == 1) 
    {
        printf("%.2f\n",v);
    }

    char buf[1024];
    char monthname[20];
    int day = 0, year = 0;
    while (fgets(buf, sizeof(buf), stdin) > 0) 
    {
        if (sscanf(buf, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n",buf);
        else
            printf("invalid %s\n",buf);
    }

    
    return 0;
}
