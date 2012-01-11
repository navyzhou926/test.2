#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct stu {
    char ch;
    struct stu *next;
};

struct stu * create(struct stu *pro, char ch)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->ch= ch;
    p->next = NULL;
    
    pro->next = p;
    return p;
}

void traversal_link(struct stu *p)
{
    while (p != NULL) 
    {
        printf("%c",p->ch);
        p = p->next;
    }
    printf("\n");
}
/*
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
}*/

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

struct stu * inverse(struct stu *head)
{
    struct stu *p, *q, *t;
    q = head;
    t = q->next;
    p = t;
    while (t->next != NULL) 
    {
        t = t->next;
        p->next = q;
        q = p;
        p = t;
    }
    p->next = q;
    head->next = NULL;
    return p;
}

int main(int argc, const char *argv[])
{

    int i;
    char a[] = "hello world!";
    struct stu *head, *p;

    head = (struct stu *)malloc(sizeof(struct stu));
    head->ch = a[0];
    p = head;
    for (i = 1; i < strlen(a); i++) 
    {
        p = create(p, a[i]);
    }
    traversal_link(head);

    head = inverse(head);
    traversal_link(head);

    free_all_link(free_one_link, head);
    return 0;
}
