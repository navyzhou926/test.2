#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu
{
    char name[256];
    int id;
    int chinese;
}a[2] = {{"stu1", 1, 95},{"stu2", 2, 98}}, b[2], *p, *q;

struct stu1
{
    char name1[20];
    int id1;
}a1 = {"hello", 1};

int main(int argc, const char *argv[])
{
    int i = 0;
    int ch = 0;
    FILE *fp1, *fp2;
    char str[256];
    int count;
    fp1 = fopen("file1", "r");
    fp2 = fopen("file2", "w+");

    ch = fwrite(a, 1, sizeof(a), fp2);
    rewind(fp2);
    fread(b, ch, 1, fp2);
    printf("%s %d %d\n",b->name, b->id, b->chinese);
    printf("%s %d %d\n",(b + 1)->name, (b + 1)->id, (b + 1)->chinese);
    //while (1)
    //{
    //if (feof(fp1)) 
    //{
    //break;
    //}
    //count = fread(str, 1, 20, fp1);
    //printf("%d\n",count);
    //fwrite(str, count, 1, fp2);
    ////fflush(fp2);
        //}
    fclose(fp1);
    fclose(fp2);

    return 0;
}
