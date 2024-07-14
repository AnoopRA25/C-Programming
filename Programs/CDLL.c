#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
    {
        int data;
        struct NODE *next;
        struct NODE *prev;
    }node;

node getnode();
node insert_front(node head);
node insert_rear(node head);
void display_forward(node head);
void display_backward(node head);

main()
{
    node head=NULL;
    int choice;
    for(;;)
    {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Display forward\n4.Display backward\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head=insert_front(head);
                break;
            case 2:
                head=insert_rear(head);
                break;
            case 3:
                display_forward(head);
                break;
            case 4:
                display_backward(head);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}

node getnode()
{
    node new_node;
    new_node=(node)malloc(sizeof(struct NODE));
    if(new_node==NULL)
    {
        printf("\nOut of memory\n");
        exit(0);
    }
    return new_node;

}

node insert_front(node head)
{
    node new_node;
    new_node=getnode();
    if(head==NULL)
    {
        new_node->next=NULL;
        new_node->prev=NULL;
        head=new_node;
    }
    else
    {
        new_node->next=head;
        new_node->prev=NULL;
        head->prev=new_node;
        head=new_node;
    }
    return head;
}

node insert_rear(node head)
{
    node new_node,temp;
    new_node=getnode();
    if(head==NULL)
    {
        new_node->next=NULL;
        new_node->prev=NULL;
        head=new_node;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=NULL;
    }
    return head;
}

void display_forward(node head)
{
    node temp;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void display_backward(node head)
{
    node temp;
    if(head==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
}

