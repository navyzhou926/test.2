#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, const char *argv[])
{
    char buf[MAX];
    int i = 0;
    #if 0
    FILE *fp;
    if ((fp = fopen(argv[1], "a+")) == NULL) 
    {
        fprintf(stderr, "Error open file %s:%s\n", argv[1], strerror(errno));
        exit(1);
    }
    while(fgets(buf, MAX, fp))i++;
    #endif


    while (1) 
    {
        time_t tm = time(NULL);
        struct tm *t = localtime(&tm);
        fprintf(stdout, "%04d\t%04d-%02d-%02d\t%02d:%02d:%02d\n",i, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour,  t->tm_min, t->tm_sec);
        #if 0
        fprintf(fp, "%04d\t%04d-%02d-%02d\t%02d:%02d:%02d\n",i, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour,  t->tm_min, t->tm_sec);
        i++;
        //fflush(fp);
        #endif
        sleep(1);
    }
    //fclose(fp);

    return 0;
}
