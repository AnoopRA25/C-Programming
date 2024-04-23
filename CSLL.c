#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}*node;

node getnode();
node insert_front(node head);
node insert_rear(node head);
node delete_front(node head);
node delete_rear(node head);
void display(node head);
void search(node head);
int count_nodes(node head);

main()
{
    node head=NULL;
    int choice,pos;
    for(;;)
{
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front \n4.Delete Rear \n5.search \n6.Count\n7.Display\n8.Exit");
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
            head = delete_front(head);
            break;

        case 4:
            head = delete_rear(head);
            break;

        case 5:search(head);
               break;

        case 6:count_nodes(head);
               break;

        case 7: display(head);
              break;

        default : exit(0);

        }
}
}

node getnode()
{
    node new_node;
    new_node = (node)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Not Created\n");
        exit(0);
    }
        printf("Enter the data to be inserted\n");
        scanf("%d", &new_node->data);
        new_node->next = new_node;
    return new_node;
}

node insert_front(node head)
{
    node new_node,cur;
    new_node=getnode();
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    cur=head;
    while (cur->next!=head)
    {
        cur=cur->next;
    }
    new_node->next;
    head=new_node;
    cur->next=new_node;
    return head;
}

node insert_rear(node head)
{
    node new_node, cur;
    new_node = getnode();
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    cur = head;
    while (cur->next != head)
        {
            cur = cur->next;
        }
        new_node->next=cur->next;
        cur->next = new_node;
    return head;
}

node delete_front(node head)
{
    node temp,cur=head;
    if (head == NULL)
    {
        printf("List Empty\n");
        return head;
    }
    if(head->next==head)
    {
        printf("Deleted item =%d\n",head->data);
        free(head);
        return NULL;
    }
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    temp=head;
    head = temp->next;
    cur->next=head;
    printf("Deleted :%d\n", temp->data);
    free(temp);
    return head;
}

node delete_rear(node head)
{
    node prev, cur;
    if (head == NULL)
    {
        printf("List Empty\n");
        return head;
    }
    if (head->next == head)
    {
        printf("Deleted %d\n", head->data);
        free(head);
        head=NULL;
        return NULL;
    }
    prev = NULL;
    cur = head;
    while (cur->next != head)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next=head;
    printf("Deleted:%d\n", cur->data);
    free(cur);
    return head;
}


