#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp1, *fp2;
    char str[256];
    int ch;

    fp1 = fopen("file1", "r");
    fp2 = fopen("file2", "w+");

    while (1)
    {
        fgets(str, 16, fp1);
        if (feof(fp1)) 
        {
            break;
        }
        printf("%s",str);    
        fputs(str, fp2);
    }

    //if (strlen(fgets(str, 30, stdin)) > 0) 
    //{
    //fputs(str, fp2);
    //fputs("\n", fp2);
    //}
    fclose(fp1);
    fclose(fp2);
    return 0;
}

