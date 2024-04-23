#include<stdio.h>
#include<stdlib.h>

typedef struct Players
{
    int exp;
    int runs;
    char name[30];
    struct Players *next;
} *player;

player getnode();
void display(player head);
player insert_rear(player head);
player search(player head);
player deleteplayer(player head);

int main()
{
    player head = NULL;
    int choice;
    for(;;)
    {
        printf("1.Insert Player\n2.Display\n3.Search and Display\n4.Delete\n5.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                head = insert_rear(head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                search(head);
                break;

            case 4:
                head = deleteplayer(head);
                break;

            case 5:
               exit(0);
        }
    }
}

player getnode()
{
    player new_player;
    new_player = (player)malloc(sizeof(struct Players));
    if (new_player == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    else
    {
        printf("Enter experience, runs, and name: ");
        scanf("%d %d %s", &new_player->exp, &new_player->runs, new_player->name);
        new_player->next = NULL;
    }
    return new_player;
}

void display(player head)
{
    player cur = head;
    if (cur == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("Details are:\n");
    while (cur != NULL)
    {
        printf("%d %d %s\n", cur->exp, cur->runs, cur->name);
        cur = cur->next;
    }
}

player insert_rear(player head)
{
    player new_player, cur;
    new_player = getnode();
    if (head == NULL)
    {
        head = new_player;
    }
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new_player;
    }
    return head;
}

player search(player head)
{
    player cur = head;
    printf("The player with more than 5 and less than 8 years experience are\n");
    while (cur != NULL)
    {
        if (cur->exp > 5 && cur->exp < 8)
        {
            printf("%d %d %s\n", cur->exp, cur->runs, cur->name);
        }
        cur = cur->next;
    }
}

player deleteplayer(player head)
{
    player prev = NULL, cur = head, temp;
    while (cur != NULL)
    {
        if (cur->exp < 5)
        {
            if (cur == head)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    printf("Deletion completed.\n");
    return head;
}
