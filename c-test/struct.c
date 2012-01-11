#include <stdio.h>
#include <string.h>

void print_xin(void)
{
    printf("%c ",'*');
}

void print_jin(void)
{
    printf("%c\n",'#');
}

struct stu_t 
{
    char name[30];
    int id;
    int chinese;
    void (*print_1)(void);
    void (*print_2)(void);
};

int main(int argc, const char *argv[])
{
    struct stu_t student[5]; 
    char i;
    for (i = 0; i < 5; i++) 
    {
        //student[i].name = "stu";
        //strcpy(student[i].name, "stu##i##");
        sprintf(student[i].name, "%s%d","student",i + 1);
        student[i].id = i + 1;
        student[i].chinese = 95 + i;
        student[i].print_1 = print_xin; 
        student[i].print_2 = print_jin; 
    }
    for (i = 0; i < 5; i++) 
    {
        student[i].print_1();
        printf("%s , %d , %d ",student[i].name, student[i].id, student[i].chinese);
        student[i].print_2();
    }
    return 0;
}

