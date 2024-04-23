#include<stdio.h>
#include<stdlib.h>

typedef struct Players
{
    int exp;
    int runs;
    char name[30];
    struct Players *next;
}*player;

player getnode();
void display(player head);
player insert_rear(player head);
player search(player head);
player deleteplayer(player head);

int main()
{
    player head;
    int choice;
    for(;;)
    {
        printf("1.Insert Player\n 2.Display\n3.Search Delete\n4.Delete\n5.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:head=insert_rear(head);
            break;

            case 2:display(head);
            break;

            case 3:head=search(head);
            break;

            case 4:head=deleteplayer(head);
            break;

            default:exit(0);
        }
    }
}

player getnode()
{
    player new_player;
    new_player = (player)malloc(sizeof(struct Players));
    if (new_player == NULL)
    {
        printf("Not Created\n");
        exit(0);
    }
    else
    {
        printf("Enter experience, runs, and name: ");
        scanf("%d%d%s",&new_player->exp,&new_player->runs ,new_player->name);
        new_player->next =NULL;
    }
    return new_player;
}

void display(player head)
{
    player cur;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("Details are \n");
    cur = head;
    while (cur != NULL)
    {
        printf("%d %d %s",cur->exp,cur->runs,cur->name);
        cur=cur->next;
    }
    printf("\n");
}

player insert_rear(player head)
{
    player new_player,cur;
    new_player=getnode();
    if(head==NULL)
    {
        head=new_player;
        return new_player;
    }
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=new_player;
    }
    return head;
}

player search(player head)
{
    player cur;
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        if(cur->exp<5&&cur->exp>8)
        {
            printf("%d %d %s",cur->exp,cur->runs,cur->name);
        }
    }
}

player deleteplayer(player head)
{
    player prev,cur;
    prev=NULL;
    cur=head;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
        if(cur->exp<5)
        {
           printf("%d %d %s",cur->exp,cur->runs,cur->name);
           free(cur);
           prev->next=cur->next;
        }
    }
    printf("Deleted \n");
}
