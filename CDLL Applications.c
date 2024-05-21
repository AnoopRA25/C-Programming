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
    struct music_list *prev;
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
void display_list_first(NODE head);
int main()
{
    int choice;
    NODE head = NULL;
    while(1)
    {
        printf("\nPress\n-1 for insert song at end\n-2 for insert song front\n-3 for display songs\n-4 for Delete song at end \n-5 for Delete song at front \n-6 Highest duration\n-7 for list by singer name\n-8 Delete by song name\n-9 Display first song after reaching last song\n-10 for exit\n");
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
            display_list_first(head);
            break;
        case 10:
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
    scanf("%s%d%s%d%s", newNode->song_name, &newNode->year, newNode->film_name, &newNode->duration, newNode->singer);
    newNode->prev = newNode;
    newNode->next = newNode;
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
    while(cur->next != head)
    {
        if(cur->duration > High_dur)
            High_dur = cur->duration;
        cur = cur->next;
    }
    printf("Highest duration: %d\n", High_dur);
    cur = head;
    do
    {
        if(cur->duration == High_dur)
            printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration, cur->singer);
        cur = cur->next;
    }
    while(cur != head);
}
NODE insert_end(NODE head)
{
    NODE newNode = getNode();
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    NODE last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
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
    do
    {
        printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration, cur->singer);
        cur = cur->next;
    }
    while(cur != head);
}
NODE insert_front(NODE head)
{
    NODE newNode = getNode();
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    NODE last = head->prev;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
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
    NODE last = head->prev;
    if(last == head)
    {
        printf("Deleted song: %s\n", head->song_name);
        free(head);
        return NULL;
    }
    last->prev->next = head;
    head->prev = last->prev;
    printf("Deleted song: %s\n", last->song_name);
    free(last);
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
    NODE cur = head;
    do
    {
        if(strcmp(cur->song_name, ssname) == 0)
        {
            if(cur == head)
                head = cur->next;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            printf("Deleted song: %s\n", cur->song_name);
            free(cur);
            return head;
        }
        cur = cur->next;
    }
    while(cur != head);
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
    NODE last = head->prev;
    if(last == head)
    {
        printf("Deleted song: %s\n", head->song_name);
        free(head);
        return NULL;
    }
    last->next = head->next;
    head->next->prev = last;
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
    do
    {
        if(strcmp(cur->singer, sname) == 0)
        {
            flag = 1;
            printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration, cur->singer);
        }
        cur = cur->next;
    }
    while(cur != head);
    if(flag == 0)
        printf("No songs found for the singer %s\n", sname);
}
void display_list_first(NODE head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Songs are\n");
    NODE cur = head;
    printf("song_name year film_name Duration singer_name\n");
    do
    {
        printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration, cur->singer);
        cur = cur->next;
    }
    while (cur != head);
    if (cur == head)
    {
        printf("\nReached the last song in the list. Playing the first song:\n");
        printf("%s\t%d\t%s\t%d\t%s\n", head->song_name, head->year, head->film_name, head->duration, head->singer);
    }
}
