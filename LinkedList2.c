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
node insert_position(node head, int pos);
node delete_front(node head);
node delete_rear(node head);
node delete_position(node head, int pos);
void display_list(node head);

void main()
{
    node head = NULL;
    int pos;
    int choice;
    for (;;)
    {
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front \n4.Delete Rear \n5. Display \n6.Exit\n");
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
            printf("Enter the position:\n");
            scanf("%d", &pos);
            head = insert_position(head);
            break;

        case 4:
            head = delete_front(head);
            break;

        case 5:
            head = delete_rear(head);
            break;

        case 6:
            printf("Enter the position:\n");
            scanf("%d", &pos);
            head = delete_position(head);
            break;

        case 7:search(head);
               break;

        case 8:c=count_node(head);
            printf("No of Nodes=%d\n",c);
            break;

        case 9:
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
    new_node = getnode();

    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
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
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    return head;
}

node delete_front(node head)
{
    node cur;
    if (head == NULL)
    {
        printf("List Empty\n");
        return head;
    }
    cur = head;
    head = head->next;
    printf("Deleted :%d\n", cur->data);
    free(cur);
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
    if (head->next == NULL)
    {
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }
    prev = NULL;
    cur = head;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted:%d\n", cur->data);
    free(cur);
    prev->next = NULL;
    return head;
}

node insert_position(node head, int pos)
{
    node new_node, prev, cur;
    int count;
    new_node = getnode();
    if (head == NULL && pos == 1)
    {
        return new_node;
    }
    if(head==NULL)
    {
        printf("Invalid Position\n");
        return head;
    }
    if(pos==1)
    {
        new_node->next=head;
        return new_node;
    }
    count=1;
    prev=NULL;
    cur=head;
    while(cur!=NULL&&count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=new_node;
        new_node->next=cur;
        return head;
    }
    else
    {
        printf("Invalid Position\n");
        return head;

    }
}

node delete_position(node head, int pos)
{
    node cur,prev;
    int count;
    if(head==NULL)
    {
        printf("List Empty\n");
        return NULL;
    }
    if(pos==1)
    {
        cur=head;
        head=head->next;
        free (cur);
        return head;
    }
    prev=NULL;
    cur=head;
    count=1;
    while(cur!=NULL&&count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(cur==NULL)
    {
        printf("Invalid Position\n");
        return head;
    }
    prev->next=cur->next;
    printf("%d Element is deleted\n",cur->data);
    free(cur);
    return head;
}

void search (node head)
{
    int key,flag=0;
    node cur;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    cur=head;
    while (cur!=NULL)
    {
        if(cur->data==key)
        {
            flag=1;
            break;
        }
        cur=cur->next;
    }
    if(flag==0)
    {
        printf("\n Element not found\n")
    }
    else
    {
        printf("\n%d is found \n",key);
    }
}

