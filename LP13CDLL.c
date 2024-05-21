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
NODE insert_end(NODE head);
NODE delete_song(NODE head, char song_name[]);
void display_playlist(NODE head);
void play_repeat_mode(NODE head);
int main()
{
    int choice;
    NODE head = NULL;
    while(1)
    {
        printf("\nAdvik's Playlist Management System\n");
        printf("1. Add a song to the playlist\n");
        printf("2. Delete a song from the playlist\n");
        printf("3. Display playlist\n");
        printf("4. Play playlist in repeat mode\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
        {
            char song_name[25];
            printf("Enter the song name to delete: ");
            scanf("%s", song_name);
            head = delete_song(head, song_name);
        }
        break;
        case 3:
            display_playlist(head);
            break;
        case 4:
            play_repeat_mode(head);
            break;
        case 5:
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
    printf("Enter song_name, year, film_name, duration, and singer: ");
    scanf("%s%d%s%d%s", newNode->song_name, &newNode->year, newNode->film_name, &newNode->duration, newNode->singer);
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}
NODE insert_end(NODE head)
{
    NODE newNode = getNode();
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        NODE last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    return head;
}
void display_playlist(NODE head)
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }
    printf("Advik's Playlist:\n");
    NODE cur = head;
    do
    {
        printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration, cur->singer);
        cur = cur->next;
    }
    while(cur != head);
}
NODE delete_song(NODE head, char song_name[])
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return NULL;
    }
    NODE cur = head;
    while(cur != NULL)
    {
        if(strcmp(cur->song_name, song_name) == 0)
        {
            if(cur->next == cur)
            {
                free(cur);
                return NULL;
            }
            if(cur == head)
                head = cur->next;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            printf("Deleted song: %s\n", cur->song_name);
            free(cur);
            return head;
        }
        cur = cur->next;
        if(cur == head)
            break;
    }
    printf("Song '%s' not found in the playlist\n", song_name);
    return head;
}
void play_repeat_mode(NODE head)
{
    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }
    printf("Playing playlist in repeat mode:\n");
    NODE cur = head;
    do
    {
        printf("%s\t%d\t%s\t%d\t%s\n", cur->song_name, cur->year, cur->film_name, cur->duration, cur->singer);
        cur = cur->next;
    }
    while(cur != head);
}
