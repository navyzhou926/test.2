#include <stdio.h>
#include <time.h>

int print_date(const char *date)
{
    struct tm *t;

    t = getdate(date);
    //printf("[%s]: \n",date);
    if (t) 
    {
        printf("%d%d%d%d%d%d\n",t->tm_year, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min,t->tm_sec);
    }
    else
    {
        printf("error\n");
    }

    return 0;
}

int main(int argc, const char *argv[])
{
    print_date("10/1/87 4 PM");
    print_date("Friday");
    print_date("Friday September 19 1987, 10:30:30");
    print_date("24, 9, 1986 10:30");
    print_date("at monday the 1st of december in 1986");
    print_date("run job at 3 PM, december 2nd");
    
    return 0;
}
