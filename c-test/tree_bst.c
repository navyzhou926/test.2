#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

typedef struct node *link;

struct node
{
    int item;
    link l,r;
};

link NODE(int item)
{
    link t = malloc(sizeof *t);
    t->item = item;
    t->l = NULL;
    t->r = NULL;
    return t;
}

int  search(link t, int key)
{
    if (t == NULL) 
    {
        return 0;
    }
    if (key < t->item) 
    {
        return search(t->l, key);
    }
    if (key > t->item) 
    {
        return search(t->r, key);
    }
    return 1;
}

void pre_ord(link t)
{
    if (!t) 
    {
        return;
    }  
    printf("%3d\n",t->item);
    pre_ord(t->l);
    pre_ord(t->r);
}

void in_ord(link t)
{
    if (!t) 
    {
        return;
    }
    in_ord(t->l);
    printf("%3d\n",t->item);
    in_ord(t->r);
}

void post_ord(link t)
{
    if (!t) 
    {
        return;
    }
    post_ord(t->l);
    post_ord(t->r);
    printf("%3d\n",t->item);
}

link insert_node(link t, int item)
{
    if (!t) 
    {
        return NODE(item);
    }
    if ((item < t->item)) 
    {
        insert_node(t->l, item);
    }
    else if(item > t->item) 
    {
        insert_node(t->r, item);
    }
    return t;
}

void pprint(link t)
{
    if (t) 
    {
        printf("(");
        printf("%d\n",t->item);
        pprint(t->l);
        pprint(t->r);
        printf(")");
    }
    else
    {
        printf("()");
    }
}

int count(link t)
{
    if (!t) 
    {
        return 0;
    }
    return 1 + count(t->l) + count(t->r);
}

int depth(link t)
{
    if (!t) 
    {
        return 0;
    }
    int dl = depth(t->l);
    int dr = depth(t->r);
    int d = dl > dr ? dl : dr;
    return d + 1;
}

link create_tree(char *P, char *l, int n)
{
    if (n == 0) 
    {
        return NULL;
    }
    int k;
    for (k = 0; P[0] != l[k]; k++) {;} 
    link t =NODE(P[0]-'0');
    t->l = create_tree(P + 1, l, k);
    t->r = create_tree(P + k + 1, l + k + 1,n-k-1);
    return t;
}

int main(int argc, const char *argv[])
{
    int i;
    srand(time(NULL));
    link root = NULL;
    //for (i = 0; i < N; i++) 
    //{
    //root = insert_node(root, rand()%100);
    //}
    root = create_tree("4213657", "1234567", 7);
    pre_ord(root); printf("\n");
    in_ord(root); printf("\n");
    post_ord(root); printf("\n");
    printf("\\tree\n"); pprint(root); printf("\n");
    printf("count = %d\n",count(root));
    printf("depth = %d\n",dept(root));
    return 0;
}
