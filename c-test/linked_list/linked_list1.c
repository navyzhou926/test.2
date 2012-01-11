#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct stu {
    int id;
    int chinese;
    char name[256];
    struct stu *next;
};

struct stu * create(struct stu *pro, int id, int chinese, char *name)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->id = id;
    p->chinese = chinese;
    strcpy(p->name, name);
    p->next = NULL;
    
    pro->next = p;
    return p;
}

void traversal_link(struct stu *p)
{
    while (p != NULL) 
    {
        printf("%d %d %s\n",p->id, p->chinese, p->name);
        p = p->next;
    }
    printf("\n");
}
struct stu * delete_link_note(struct stu *p, int id)
{
    struct stu *q, *head;
    if (p->id == id) 
    {
        q = p;
        p = p->next;
        free(q);
        q = NULL;
        return p;
    }
    head = p;
    while (p->next != NULL) 
    {
        if (p->next->id == id) 
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
            q = NULL;
            return head;
        }
        p = p->next;
    }
    return head;
}

struct stu * delete_head_note(struct stu *p)
{
    struct stu *q;
    q = p;
    p = p->next;
    free(q);
    return p;
}
void delete_end_note(struct stu *p)
{
    while (p->next->next != NULL) 
    {
        p = p->next;
    }
    free(p->next->next);
    p->next = NULL;
}

struct stu * add_head_note(struct stu *head, int id, int chinese, char *name)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->id = id;
    p->chinese = chinese;
    strcpy(p->name, name);
    p->next = head;
    
    head = p;
    return head;
}

void add_end_note(struct stu *p, int id, int chinese, char *name)
{
    struct stu *q = (struct stu *)malloc(sizeof(struct stu));
    q->id = id;
    q->chinese = chinese;
    strcpy(q->name, name);
    q->next = NULL;

    while (p->next != NULL) 
    {
        p = p->next;
    }
    p->next = q;
}

struct stu * add_link_note(struct stu *p, int id, int id_n, int chinese, char *name)
{
    struct stu *q;
    struct stu *head;
    head = p;
    while (p != NULL) 
    {
        if (p->id == id) 
        {
            struct stu *q = (struct stu *)malloc(sizeof(struct stu));
            q->id = id_n;
            q->chinese = chinese;
            strcpy(q->name, name);

            q->next = p->next;
            p->next = q;
            return head;
        }
        p = p->next;
    }
    return head;
}
struct stu *free_one_link(struct stu *p)
{
    struct stu *q;

    if (p == NULL) 
    {
        return NULL;
    }
    q = p;
    p = p->next;
    free(q);

    return p;
}

void free_all_link(struct stu *(*fun)(struct stu *p), struct stu *head)
{
    while (head != NULL) 
    {
        head = fun(head);
    }
    return ;
}

int main(int argc, const char *argv[])
{

    int i;
    char name_t[256];
    struct stu *head, *p;
    head = (struct stu *)malloc(sizeof(struct stu));
    head->id = 1;
    head->chinese = 75;
    strcpy(head->name, "student_1");
    p = head;
    for (i = 2; i < 10; i++) 
    {
        sprintf(name_t, "%s%d","student_",i);
        p = create(p, i, 70 + i, name_t);
    }

    head = delete_link_note(head, 3);

    head = add_head_note(head, 10, 81, "student_11");

    add_end_note(head, 11, 82, "student_12");

    add_link_note(head, 9, 12, 83, "student_13");

    head = delete_head_note(head);

    delete_end_note(head);

    traversal_link(head);

    free_all_link(free_one_link, head);
    //traversal_link(head);
    return 0;
}

