#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (*fp)(void);

int cmp(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int main(int argc, const char *argv[])
{
    int i;
    char *a[] = {"kslwolszd", "kskklale", "laklw", "ls", "ee", "zza"}; 
    //qsort(&argv[1], argc - 1, sizeof(argv[1]), cmp);
    qsort(&a, 6, sizeof(a[3]), cmp);
    for (i = 0; i < 6; i++) 
    {
        puts(a[i]);
    }


    //for (i = 1; i < argc; i++)
        //puts(argv[j]);
    return 0;
}
