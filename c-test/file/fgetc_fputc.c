#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp1, *fp2;
    char *str;
    int ch;

    //fp1 = fopen("file1", "r");
    //fp2 = fopen("file2", "w+");
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w+");
    while (1)
    {
        ch = fgetc(fp1);
        if (feof(fp1) == 1) 
        {
            break;
        }
        fputc(ch,fp2);   
    }

    //while ((ch = fgetc(fp1)) != EOF)
    //fputc(ch, fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}

