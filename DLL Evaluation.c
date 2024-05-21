#include<stdio.h>
#include<stdlib.h>

typedef struct OS
{
    int task_Id;
    char name[30];
    int priority;
    int memory_usage;
    char CPU[30];
    struct OS *next;
    struct OS *prev;
}*node;

node getnode();
node insert_front(node head);
void display_front(node head);
void display_back(node head);
int count_nodes(node head);
node search_and_delete(node head);
node insert_before(node head);

main()
{
    node head=NULL;
    int choice;
   while(1)
    {
       printf("1.InsertFront\n2.DisplayFront\n3.DisplayBack\n4.CountNodes\n5.SearchAndDelete\n6.InsertBefore\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:head=insert_front(head);
                break;

           case 2:display_front(head);
                  break;

           case 3:display_back(head);
                  break;

           case 4:count_nodes(head);
                  break;

           case 5:head=search_and_delete(head);
                  break;

           case 6:head=insert_before(head);
                  break;

            default:exit(0);
       }
    }
}

node getnode()
{
    node new_node;
    new_node=(node)malloc(sizeof(struct OS));
    if(new_node==NULL)
    {
        printf("Not Created\n");
    }
    else
    {
        printf("Enter the details\n");
        scanf("%d %s %d %d %s",&new_node->task_Id,new_node->name,&new_node->priority,&new_node->memory_usage,new_node->CPU);
        new_node->next=NULL;
        new_node->prev=NULL;
    }
    return new_node;
}

node insert_front(node head)
{
   node new_node;
   new_node=getnode();
   if(head==NULL)
   {
       head=new_node;
       return head;
   }
   else
   {
      new_node->next=head;
      head->prev=new_node;
      head=new_node;
      head->prev=NULL;
   }
   return head;
}

void display_front(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    else
  {
    cur=head;
    while(cur!=NULL)
    {
       printf("The details are %d %s %d %d %s\n",cur->task_Id,cur->name,cur->priority,cur->memory_usage,cur->CPU);
       cur=cur->next;
    }
  }

}

void display_back(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
       cur=head;
       while(cur->next!=NULL)
       {
           cur=cur->next;
       }
       while(cur!=NULL)
       {
           printf("The details are %d %s %d %d %s\n",cur->task_Id,cur->name,cur->priority,cur->memory_usage,cur->CPU);
           cur=cur->prev;
       }
    }
}

int count_nodes(node head)
{
    node cur;
    int count=0;
    if(head==NULL)
        return(count);
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->next;
        }
        if(cur==NULL)
            return count;
    }
}

node search_and_delete(node head)
{
    node cur,cur1;
    int max;
    max=head->memory_usage;
    cur=head;
    while(cur!=head)
    {
        if(cur->memory_usage>max)
        {
            cur1=cur->prev;
            cur1->next=cur->next;
            cur->next->prev=cur1;
            printf("The task with highest memory usage is deleted\n");
            free(cur);
            cur=cur->next;
        }
        cur=cur->next;
    }
}

node insert_before(node head)
{
    node cur,new_node;
    int key,found=0;
    printf("Enter the task to be found\n");
    scanf("%d",&key);
    cur=head;
    while(cur!=NULL)
    {
        if(cur->task_Id==key)
        {
            found=1;
            new_node=getnode();
            new_node->next=cur;
            cur->next->prev=new_node;
            new_node->prev=cur->prev;
            cur->prev=new_node;
            cur=cur->next;
        }
        cur=cur->next;
    }
    if(found==1)
    {
        printf("The task is found\n ");
    }
    else if(found==0)
    {
        printf("The task is not found\n");
    }
    if(head->task_Id==key)
    {
        head->prev=new_node;
        new_node->next=head;
        new_node->prev=NULL;
    }
    return head;


}





