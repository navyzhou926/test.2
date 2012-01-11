#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    FILE *fp1, *fp2;
    char str[256];
    char arr[5][256];
    int count;
    int n1, n2, n3;

    //strcpy(arr[0],"stuent1 90 80 85");
    fp1 = fopen("file1", "r");
    fp2 = fopen("file2", "w+");
    fprintf(fp2, "%s %d %d %d","stuendt1", 90, 80, 85);
    rewind(fp2); 
    fscanf(fp2, "%s%d%d%d",str, &n1, &n2, &n3);
    printf("%s %d %d %d\n",str, n1, n2, n3);
    //while (1)
    //{
    //if (feof(fp1)) 
    //{
    //break;
    //}
    //count = fread(str, 1, 20, fp1);
    //printf("%d\n",count);
    //fwrite(str, count, 1, fp2);
    //fflush(fp2);
    //}
    usleep(1000000);
    fprintf( stderr, "\nhello" );

    fclose(fp1);
    fclose(fp2);

    return 0;
}

