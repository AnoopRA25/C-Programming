#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct music_list
{
    char song_name[25];
    int year;
    char film_name[25];
    int duration;
    char singer[25];
    struct music_list *next;
} *NODE;
NODE getNode();
NODE insert_front(NODE head);
NODE insert_end(NODE head);
void display_list(NODE head);
NODE delete_end(NODE head);
NODE delete_front(NODE head);
void list_by_singer_Name(NODE head);
void highest_duration(NODE head);
NODE delete_song_by_name(NODE head);
int main()
{
    int choice;
    NODE head = NULL;
    while(1)
    {
        printf("\nPress\n 1 for insert song at end\n 2 for insert song front\n 3 for display songs\n 4 forDelete song at end \n5 for Delete song at front \n6 Highest duration\n 7 for list by singer name\n8Delete by song name\n9 for exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
            head = insert_front(head);
            break;
        case 3:
            display_list(head);
            break;
        case 4:
            head = delete_end(head);
            break;
        case 5:
            head = delete_front(head);
            break;
        case 6:
            highest_duration(head);
            break;
        case 7:
            list_by_singer_Name(head);
            break;
        case 8:
            head = delete_song_by_name(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
NODE getNode()
{
    NODE newNode = (NODE)malloc(sizeof(struct music_list));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter song_name year film_name and duration singer name\n");
    scanf("%s%d%s%d%s", newNode->song_name, &newNode->year, newNode->film_name,
          &newNode->duration, newNode->singer);
    newNode->next = NULL;
    return newNode;
}
void highest_duration(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    int High_dur = cur->duration;
    while(cur != NULL)
    {
        if(cur->duration > High_dur)
            High_dur = cur->duration;
        cur = cur->next;
    }
    printf("Highest duration: %d\n", High_dur);
    cur = head;
    while(cur != NULL)
    {
        if(cur->duration == High_dur)
            printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration,
                   cur->singer);
        cur = cur->next;
    }
}
NODE insert_end(NODE head)
{
    NODE newNode = getNode();
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    NODE cur = head;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = newNode;
    return head;
}
void display_list(NODE head)
{
    if(head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Songs are\n");
    NODE cur = head;
    printf("song_name year film_name Duration singer_name\n");
    while(cur != NULL)
    {
        printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration,
               cur->singer);
        cur = cur->next;
    }
}
NODE insert_front(NODE head)
{
    NODE newNode = getNode();
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}
NODE delete_end(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next == NULL)
    {
        printf("Deleted song: %s\n", head->song_name);
        free(head);
        return NULL;
    }
    NODE prev = NULL, cur = head;
    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted song: %s\n", cur->song_name);
    free(cur);
    prev->next = NULL;
    return head;
}
NODE delete_song_by_name(NODE head)
{
    char ssname[20];
    printf("Enter the song name\n");
    scanf("%s", ssname);
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE cur = head, prev = NULL;
    while(cur != NULL)
    {
        if(strcmp(cur->song_name, ssname) == 0)
        {
            if(prev == NULL)
                head = cur->next;
            else
                prev->next = cur->next;
            printf("Deleted song: %s\n", cur->song_name);
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Song not found\n");
    return head;
}
NODE delete_front(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE temp = head;
    head = head->next;
    printf("Deleted song: %s\n", temp->song_name);
    free(temp);
    return head;
}
void list_by_singer_Name(NODE head)
{
    char sname[20];
    printf("Enter the singer name\n");
    scanf("%s", sname);
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    int flag = 0;
    while(cur != NULL)
    {
        if(strcmp(cur->singer, sname) == 0)
        {
            flag = 1;
            printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration,
                   cur->singer);
        }
        cur = cur->next;
    }
    if(flag == 0)
        printf("No songs found for the singer %s\n", sname);
}
