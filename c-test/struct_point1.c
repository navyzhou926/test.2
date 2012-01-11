#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
    int id;
    int chinese;
    char name[256];
};

void swap(struct stu *a, struct stu *b)
{
    int temp;
    char *p;
    temp = a->id;
    a->id = b->id;
    b->id =temp;

    temp = a->chinese;
    a->chinese= b->chinese;
    b->chinese=temp;

    p = (char *)malloc(sizeof(256)); 
    strcpy(p, a->name); 
    strcpy(a->name, b->name);
    strcpy(b->name, p);
    free(p);
}

int main(int argc, const char *argv[])
{
    struct stu stu1 = {1, 95, "Zhang San"};
    struct stu stu2 = {2, 96, "Li Si"};
    printf("\n%d %d %s\n",stu1.id, stu1.chinese, stu1.name);
    printf("%d %d %s\n\n",stu2.id, stu2.chinese, stu2.name);

    swap(&stu1, &stu2);

    printf("%d %d %s\n",stu1.id, stu1.chinese, stu1.name);
    printf("%d %d %s\n\n",stu2.id, stu2.chinese, stu2.name);

    return 0;
}

