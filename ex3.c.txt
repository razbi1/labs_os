#include <stdio.h>
#include <stdlib.h>

struct  node
{
  int value;
  struct node * next;
};

struct node*    new_list(int n)
{
    struct node*    tmp;

    tmp = (struct node*) malloc(sizeof (struct node));
    tmp->value = n;
    tmp->next = NULL;
    return (tmp);
}

void            print_list(struct node* head)
{
  while(head != NULL)
  {
    printf("%d\n", head->value);
    head = head->next;
  }
}

void            insert_node(struct node* head, struct node * new_node, int index)
{
    int     i;

    if (index < 2)
        printf("Err.\n");
    else if(index == 2)
    {
        new_node->next = head->next;
        head->next = new_node;
    }
    else
    {
        for(i = 2;i < index;i++)
        {
            if (head->next != NULL)
                head = head->next;
            else
            {
                head->next = new_node;
                break;
            }
        }
        new_node->next = head->next;
        head->next = new_node;
    }
}

void            delete_node(struct node* head, int index)
{
    int     i;

    if(index == 0)
        printf("Err.\n");
    else
    {
        for(i = 1; (i < index-1) && (head->next != NULL); i++)
            head = head->next;
        if(head->next != NULL)
            head->next = head->next->next;
    }
}

int             main()
{
    struct node*    head;
    struct node*    n1;
    struct node*    n2;
    struct node*    n3;
    
    head = new_list(1);
    n1 = new_list(2);
    n2 = new_list(3);
    n3 = new_list(4);

    head->next = n1;
    print_list(head);
    printf("\n");

    insert_node(head, n3, 3);
    insert_node(head, n2, 3);
    print_list(head);
    printf("\n");

    delete_node(head, 3);
    print_list(head);
    printf("\n");

    return (0);
}