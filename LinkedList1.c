#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;

} *node;

node getnode();
node insert_rear(node head);
node insert_front(node head);
void display_list(node head);

void main()
{
    node head = NULL;
    int choice;
    for (;;)
    {
        printf("1.Insert Front\n2.Insert Rear\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = insert_front(head);
            break;

        case 2:
            head = insert_rear(head);
            break;

        case 3:
            display_list(head);
            break;

        default:
            exit(0);
        }
    }
}

node getnode()
{
    node new_node;
    new_node = (node)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        printf("Not Created\n");
        exit(0);
    }
    else
    {
        printf("Enter the data to be inserted\n");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
    }
    return new_node;
}

void display_list(node head)
{
    node cur;
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Elements are \n");
    cur = head;
    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

node insert_front(node head)
{
    node new_node;
    new_node=getnode();

    if (head ==NULL)
    {
        head =new_node;
        return head;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
    return head;
}

node insert_rear(node head)
{
    node new_node,cur;
    new_node=getnode();
    if (head==NULL)
    {
        head =new_node;
        return head;
    }
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=new_node;
    }
    return head;
}

