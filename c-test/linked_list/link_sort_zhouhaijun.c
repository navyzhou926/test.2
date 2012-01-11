#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>
#include <unistd.h>

#define LINK_SORT 2
#define ESC 27

struct stu 
{
    int chinese;
    int english;
    int math;
    int ave;
    int id;
    char name[256];
    struct stu *next;
};

struct stu * create_head(struct stu *head, char *name, int id, int chinese, int english, int math)
{
    head = (struct stu *)malloc(sizeof(struct stu));
    head->chinese = chinese;
    head->english = english;
    head->math = math;
    head->ave = (chinese + english + math)/3;
    head->id = id;
    strcpy(head->name, name);
    return head;
}

struct stu * create(struct stu *pro, char *name, int id, int chinese, int english, int math)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->chinese = chinese;
    p->english = english;
    p->math = math;
    p->ave = (p->chinese + p->english + p->math)/3;
    p->id = id;
    strcpy(p->name, name);
    p->next = NULL;
    
    pro->next = p;
    return p;
}

void traversal_link(struct stu *p)
{
    printf("\nid  student_name   chinese   english    math   ave\n");
    while (p != NULL) 
    {
        printf("%d    %s\t     %d\t       %d\t %d\t%d\n",p->id, p->name, p->chinese, p->english, p->math, p->ave);
        p = p->next;
    }
    printf("\n");
}

struct stu * delete_note_by_id(struct stu *p, int id)
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

struct stu * delete_note_by_name(struct stu *p, char *name)
{
    struct stu *q, *head;
    if (strcmp(p->name, name) == 0) 
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
        if (strcmp(p->next->name, name) == 0) 
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

struct stu * add_head_note(struct stu *head, char *name, int id, int chinese, int english, int math)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->chinese = chinese;
    p->english = english;
    p->math = math;
    p->ave = (chinese + english + math)/3;
    p->id = id;
    strcpy(p->name, name);
    p->next = head;
    head = p;
    return head;
}

struct stu * add_end_note(struct stu *end, char *name, int id, int chinese, int english, int math)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->chinese = chinese;
    p->english = english;
    p->math = math;
    p->ave = (p->chinese + p->english + p->math)/3;
    p->id = id;
    strcpy(p->name, name);

    end->next = p;
    p->next = NULL;
    return p;
}

struct stu * add_link_note(struct stu *p, char *name, int id, int chinese, int english, int math)
{
    struct stu *q = (struct stu *)malloc(sizeof(struct stu));
    q->chinese = chinese;
    q->english = english;
    q->math = math;
    q->id = id;
    q->ave = (chinese + english + math)/3;
    strcpy(q->name,name);

    q->next = p->next;
    p->next = q;
    return p;
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

#if LINK_LIST_SORT == 1
struct stu * link_list_sort(struct stu *p)
{
    struct stu *head = NULL, *end, *head1;
    struct stu *q, *q1;
    head1 = p;
    head = create_head(head, p->name, p->id, p->chinese, p->english, p->math);
    q = end = head;
    p = p->next;
    while (p != NULL) 
    {
        if (p->ave > head->ave) 
        {
            head = add_head_note(head, p->name, p->id, p->chinese, p->english, p->math);      
        }
        if (p->ave < end->ave)
        {
            end = add_end_note(end, p->name, p->id, p->chinese, p->english, p->math);      
            continue;
        }
        if ((p->ave <= head->ave) && (p->ave >= end->ave))
        {
            q = head;
            while (q->next != NULL)
            {
                if ((p->ave <= q->ave) && (p->ave >= q->next->ave)) 
                {
                    add_link_note(q, p->name, p->id, p->chinese, p->english, p->math);
                    break;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
    free_all_link(free_one_link, head1);
    delete_end_note(head);
}

#else 
struct stu * sort_insert(struct stu *head, struct stu *n)
{
	struct stu *p = head, *pre;
	if(n->ave > p->ave)
    {
		n->next = p;
		return n;
	}
	pre = p; p = p->next;
	while(p != NULL)
    {
		if(n->ave > p->ave) break;
		pre = p; p = p->next;
	}
	if(p)
    {
		n->next = p;
		pre->next = n;
	}
	else
    {
		n->next = NULL;
		pre->next = n;
	}
	return head;	  
}

struct stu * link_list_sort(struct stu *head)
{
	struct stu *p,*tmp, *new = head;
	p = head->next; 
	new->next = NULL;
	while(p)
    {
		tmp = p->next;
		new = sort_insert(new, p);
		p = tmp;
	}
	return new;
}
#endif

void write_to_file(struct stu *head)
{
    struct stu *p = head;
    FILE *fp1;
    fp1 = fopen("students_infomation", "w+");
    while (p != NULL) 
    {
        fprintf(fp1, "%s %d %d %d %d %d\n",p->name, p->id, p->chinese, p->english, p->math, p->ave);
        p = p->next;
    }
    fclose(fp1);
}

void show_meun(void)
{
    printf("\n*******************************\n");
    printf("Please select the option:\n");
    printf("1. Display all student's record\n");
    printf("2. Sort by average\n");
    printf("3. Add a new record\n");
    printf("4. Delete a record\n");
    printf("5. Exit system\n");
    printf("*******************************\n");
    printf("***Press ESC to back to meun***\n");
    printf("Please input your choice: ");
}

int main(int argc, const char *argv[])
{
    FILE *fp1;
    char choice = 0, ch = 0;
    int i, id_t;
    char name_t[256];
    struct stu *head = NULL, *p;

    fp1 = fopen("students_infomation", "w+");
    head = create_head(head, "student_1", 1, 75, 87, 98);
    fprintf(fp1, "%s %d %d %d %d %d\n","stuendt_1", 1, 75, 87, 98, head->ave);
    p = head;
    for (i = 2; i < 10; i++) 
    {
        sprintf(name_t, "%s%d","student_",i);
        p = create(p, name_t, i, 70 + i, 80-i, 90 + i);
        fprintf(fp1, "%s %d %d %d %d %d\n",name_t, i, 70 + i, 80-i, 90 + i, p->ave);
    }
    fclose(fp1);

    show_meun();
    while (1) 
    {
        printf("\n");
        scanf("%c",&choice);
        getchar();
        switch (choice)
        {
            case '1':
            {
                traversal_link(head);
     again3 :   printf("\n***Press ESC to back to meun***\n");
                scanf("%c",&ch); getchar();
                if (ch == ESC) 
                {
                    system("clear");
                    show_meun();
                    break;
                }
                else
                {
                    goto again3;
                }
                choice = 0;
                break;
            }
            case '2':
            {
                head = link_list_sort(head);
                write_to_file(head);
                system("clear");
                printf("\nAll students' infomation has been sorted by average scores\n");
                usleep(1500000);
                show_meun();
                break;
            }
            case '3':
            {
      again :   p = (struct stu *)malloc(sizeof(struct stu));
                printf("Please input student's infomation:");
                printf("\nname: "); scanf("%s",p->name);
                printf("\nid: "); scanf("%d",&p->id);
                printf("\nchinese: ");scanf("%d",&p->chinese);
                printf("\nenglish: ");scanf("%d",&p->english);
                printf("\nmath: ");scanf("%d",&p->math);
                p->ave = (p->chinese + p->english + p->math)/3;
                getchar();
     again1 :   printf("\n\n***Press ESC to back to meun***\n");
                printf("Are you sure to add this new infomation?(Y/n)\n");

                scanf("%c",&ch); getchar();
                if ((ch == 'Y') || (ch == 'y')) 
                {
                    choice = 0;
                    system("clear");
                    head = sort_insert(head, p);
                    write_to_file(head);
                    printf("You have added infomation successfully\n");
                    usleep(1500000);
         again2 :   printf("\n\n***Press ESC to back to meun***\n");
                    printf("Do you want to add new infomation again ?(Y/n)\n");
                    scanf("%c",&ch); getchar();
                    if ((ch == 'Y') || (ch == 'y')) 
                    {
                        goto again;
                    }
                    else if ((ch == 'N') || (ch == 'n') || (ch == ESC)) 
                    {
                        choice = 0;
                        system("clear");
                        show_meun();
                        break;
                    }
                    else
                    {
                        goto again2;
                    }
                }
                else if ((ch == 'N') || (ch == 'n')) 
                {
                    system("clear");
                    printf("You didn't add any infomation\n");
                    goto again;
                }
                else if (ch == ESC) 
                {
                    system("clear");
                    show_meun();
                    choice = 0;
                    break;
                }
                else
                {
                    goto again1;
                }
                break;
            }
            case '4':
            {
                system("clear");
     again4 :   printf("\n***Press ESC to back to meun***\n");
                printf("Please select a  type to delete\n");
                printf("1. by ID\n2. by NAME\n\n");
                scanf("%c",&ch); getchar();
                if (ch == '1') 
                {
                    printf("\nPlease input ID to delete:\n");
                    scanf("%d",&id_t); getchar();
                    head = delete_note_by_id(head, id_t);
                    write_to_file(head);
                    system("clear");
                    printf("\nSucceed to delete ID: %d\n",id_t);
                    usleep(1500000);
                    show_meun();
                    break;
                }
                else if (ch == '2') 
                {
                    printf("\nPlease input NAME to delete:\n");
                    scanf("%s",name_t); 
                    head = delete_note_by_name(head, name_t);
                    getchar();
                    write_to_file(head);
                    system("clear");
                    printf("\nSucceed to delete NAME: %s\n",name_t);
                    usleep(1500000);
                    show_meun();
                    break;
                }
                else if (ch == ESC)
                {
                    system("clear");
                    show_meun();
                    choice = 0;
                    break;
                }
                else
                {
                    goto again4;
                }
            }
            case '5':
            {
                return 0;
            }
            case ESC:
            {
                system("clear");
                show_meun();
            }
        }
    }
    return 0;
}           

