#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct note
{
    int id;
    struct note *next;
};

struct note * make_note(int id, struct note *n)
{
    struct note *p = (struct note *)malloc(sizeof(struct note));
    p->id= id;
    
    p->next = n;
    return p;
}

void traversal_loop_link(struct note *head, int n)
{
    struct note *p;
    int i = 0;
    while (1) 
    {
        p = p->next;
        printf("%d\n",p->id);
        i++;
        if (i == n) 
        {
            break;
        }
    }
}

int josephus_survive(int len, int space)
{
    int i;
    int count = 0;
    struct note *head = NULL, *p = NULL, *q = NULL;

    head = p = make_note(1, NULL);
    p->next = p;
    for (i = 2; i < len + 1; i++) 
    {
        p = p->next = make_note(i, p->next);
    }

    p = head;
    while (1) 
    {
        if (p == p->next) 
        {
            break;
        }
        count = space-1;
        while (--count) 
        {
            p = p->next;
        }
        q = p->next;
        p->next = p->next->next;
        printf("%d\t is out\n",q->id);
        free(q); q = NULL;
        p = p->next;
    }

    return p->id;
}
     
int main(int argc, const char *argv[])
{
    //traversal_loop_link(head, 9);
    printf("\n我是周海军，我是幸存者！\n\n");
    printf("The surviver's ID is %d\n\n",josephus_survive(10, 3));

    return 0;
}

