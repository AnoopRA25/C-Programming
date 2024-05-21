#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int taskid,priority,cpuusage,memoryusage;
    char name[100];
    struct node *next,*previous;
}*task;




task getnode()
{

    task newnode;
    newnode = (task)malloc(sizeof(struct node));
    if(newnode == NULL)
    {

        printf("Memory allocation failed\n");
    }
    else
    {

        printf("Enter the taskid,name,priority,cpuusage,memoryusage\n");
        scanf("%d %s %d %d %d",&newnode->taskid,newnode->name,&newnode->priority,&newnode->cpuusage,&newnode->memoryusage);

        newnode->next=newnode->previous = NULL;
    }
    return newnode;

}






task Insertfront(task head)
{
    task newnode;

    newnode = getnode();

    if(head == NULL)
    {

        return newnode;
    }

    else
    {

        newnode->next = head;
        head ->previous = newnode;
        head = newnode;
    }
    return head;

}

void displayforward(task head)
{

    task cur;
    cur = head;
    printf("pass\n");
    if(head == NULL)
    {

        printf("List is empty\n");

    }

    else
    {
        while(cur!=NULL)
        {
            printf("Task id = %d \t name = %s\t priority=%d \t cpuusage=%d \t memoryusage= %d \n",cur->taskid,cur->name,cur->priority,cur->cpuusage,cur->memoryusage);
            cur = cur->next;

        }

    }


}

void displaybackward(task head)
{

    task cur;
    cur = head;
    printf("pass\n");
    if(head == NULL)
    {

        printf("List is empty\n");

    }

    else
    {
        while(cur->next!=NULL)
        {


            cur = cur->next;

        }

        while(cur!=NULL)
        {

            printf("Task id = %d \t name = %s\t priority=%d \t cpuusage=%d \t memoryusage= %d \n",cur->taskid,cur->name,cur->priority,cur->cpuusage,cur->memoryusage);
            cur=cur->previous;
        }

    }


}

int counttask(task head)
{

    int count=0;
    task cur;

    if(head == NULL)
    {

        printf("List is empty\n");

    }

    else
    {
        cur = head;
        while(cur!=NULL)
        {
            count++;
            cur = cur->next;

        }

    }
    return count;
}


task delete_high_memoryusage_task(task head)
{

    task i,max,t1,t2;

    if(head == NULL)
    {

        printf("List is empty\n");
    }

    else if(head->next == NULL)
    {

        printf("Single task is present\n");
    }

    else
    {
        max=head;
        for(i=head;i!=NULL;i=i->next)
        {

            if(i->taskid>max->taskid)
            {
                max= i;
            }
        }

        t1=max->previous;
        t2=max->next;


        if(t1==NULL)
        {
            head=head ->next;
        }
        else
        {
            t1->next=t2;
        }
        if(t2!=NULL)
        {
            t2->previous = t1;
        }
        printf("The deleted task is\n");
        printf("Task id = %d \t name = %s\t priority=%d \t cpuusage=%d \t memoryusage= %d \n",max->taskid,max->name,max->priority,max->cpuusage,max->memoryusage);
        free(max);



    }
    return(head);


}

task Inserttaskbefore(task head)
{
    task newnode,cur,t1,t2;
    newnode = getnode();
    int searchtask;


    printf("Enter the task\n");
    scanf("%d",&searchtask);


    if(head == NULL)
    {
        printf("List is empty\n");

    }

    else
    {
        for(cur=head;cur!=NULL&&cur->taskid!=searchtask;cur=cur->next);

        if(cur == NULL)
        {
            printf("No node found\n");

        }

        else
        {
            t1=cur->previous;
            newnode->previous =t1;
            newnode->next = cur;

            if(t1==NULL)
            {

                head = newnode;
            }
            else
            {

                t1->next=newnode;

            }
            cur->previous = newnode;

        }
    }

    return(head);





}
















int main()
{
    int count=0;
    task head;
    head = NULL;

    int choice;
    do
    {
        printf("1.Insert front\n2.count task\n3.insert before task \n4.Delete high memory usaage task \n5.display forward \n6.display backward \n7.exit\n");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:  head = Insertfront(head);
                break;
            case 2:count = counttask(head);
                    printf("No of nodes is = %d\n",count);
                break;
            case 3:head= Inserttaskbefore(head);
                break;
            case 4:head = delete_high_memoryusage_task(head);
                break;
            case 5:displayforward(head);
                break;
            case 6:displaybackward(head);
                break;
            case 7:exit(0);
                break;


        }
    }while(1);

    return 0;
}
