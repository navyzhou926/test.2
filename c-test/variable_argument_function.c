#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#define CHOICE 3

#if CHOICE == 1
void myprintf(char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    printf("%s\n",va_arg(ap, char *));
    printf("%s\n",va_arg(ap, char *));
    //printf("%s\n",va_arg(ap, char *));
    va_end(ap);
}
#elif CHOICE == 2
void myprintf(int format, ...)
{
    va_list ap;
    int i, sum = 0;

    va_start(ap, format);
    for (i = 0; i < format; i++) 
    {
        sum += va_arg(ap, int);
    }
    va_end(ap);
    printf("sum = %d\n", sum);
}
#elif CHOICE == 3
void myprintf(char * format, ...)
{
    va_list ap;
    int i = 0;
    va_start(ap, format);
    while (*(format + i) != '\0')
    {
        if (*(format + i) == '%') 
        {
            i++;
            if (*(format + i) != '\0') 
            {
                if (*(format + i) == 's') 
                {
                    printf("%s",va_arg(ap, char *));
                }
                if (*(format + i) == 'c') 
                {
                    printf("%c",(char)va_arg(ap, int));
                }
                if (*(format + i) == 'd') 
                {
                    printf("%d",va_arg(ap, int));
                }
                if (*(format + i) == 'f') 
                {
                    printf("%f",(float)va_arg(ap, double));
                }
                if (*(format + i) == 'u') 
                {
                    printf("%u",(unsigned int)va_arg(ap, int));
                }
                i++;
                continue;
            }
        }
        else
        {
            printf("%c",*(format + i));
        }
        i++;
    }
    printf("\n");
    va_end(ap);
}
#else 
void myprintf(char *format, ...)
{
    //int *p = (int *)&format;
    
    //char **p = &format;
    //p = p + 1;
    //printf("%s\n", *p++);
    //printf("%s\n", *p++);
    //printf("%s\n", *p);

    char *p = (char *)&format;
    printf("%s\n",(char *)(*(int*)(p + 4)));
    printf("%s\n",(char *)(*(int*)(p + 8)));
    printf("%s\n",(char *)(*(int*)(p + 12)));
}
#endif

int main(int argc, const char *argv[])
{
    //myprintf("", "hello world!", "how are you");
    //myprintf("", "how", "are", "you");
    //myprintf(5, 1, 2, 3, 4, 5);
    myprintf("%s  %d  %c","hello", 10, 'a');

    return 0;
}

