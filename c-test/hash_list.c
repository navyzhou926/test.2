#include <stdio.h>
#include <stdlib.h>
#define N 11
#define H(x) ((x) % N)
typedef struct node *link;

struct node{
    int item;
    link next;
};

link hash[N];

link make_node(unsigned char item)
{
    link p = malloc(sizeof *p);
    p->item = item;
    p->next = NULL;
    return p;
}

void free_node(link p)
{
    free(p);
}

link search(unsigned char key)
{
    link p, head = hash[H(key)];
    for (p = head; p; p = p->next) 
    {
        if (p->item == key) 
        {
            return p;
        }
    }
    return NULL;
}

void insert(link p)
{ link *phead = &hash[H(p->item)];
    p->next = *phead;
    *phead = p;
}

void delete(link p)
{
    link *pnext = &hash[H(p->item)];
    for (; *pnext; pnext = &(*pnext)->next) 
    {
        if (*pnext == p) 
        {
            *pnext = p->next;
            return;
        }
    }
}

void traverse(void (*visit)(link))
{
    int i;
    link p, head;
    for (i = 0; i < N; i++) 
    {
        head = hash[i];
        for (p = head; p; p = p->next) 
        {
            visit(p);
        }
    }
}

void print_item(link p)
{
    printf("%d\n",p->item);
}

int main(int argc, const char *argv[])
{
    link p;
    insert(make_node(57));
    insert(make_node(38));
    insert(make_node(29));
    insert(make_node(7));
    insert(make_node(98));
    insert(make_node(12));
    traverse(print_item);
    puts("");
    if (p = search(38)) 
    {
        delete(p);
        free_node(p);
    }
    if (p = search(7)) 
    {
        delete(p);
        free_node(p);
    }
    traverse(print_item);

    return 0;
}
