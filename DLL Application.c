#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char song_name[100];
    int released_year;
    char singer_name[100];
    int duration;
    char film_name[100];
    struct Song *next;
    struct Song *prev;
} Song;

void add_song(Song **start_ref, Song *new_song);
void display_songs(Song *start);
void display_songs_by_singer(Song *start, char *singer_name);
void delete_song_by_name(Song **start_ref, char *song_name);
Song find_highest_duration_song(Song *start);
void display_songs_by_year(Song *start, int released_year);
Song *search_song_by_name(Song *start, char *song_name);

int main() {
    Song *start = NULL;

    int choice;
    char singer_name[100], song_name[100];
    int released_year;

    while (1) {
        printf("\n1. Add song\n2. Display all songs\n3. Display songs by singer\n4. Delete song by name\n5. Find highest duration song\n6. Display songs by year\n7. Search song by name\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&start, create_song());
                break;
            case 2:
                display_songs(start);
                break;
            case 3:
                printf("Enter singer name: ");
                scanf("%s", singer_name);
                display_songs_by_singer(start, singer_name);
                break;
            case 4:
                printf("Enter song name: ");
                scanf("%s", song_name);
                delete_song_by_name(&start, song_name);
                break;
            case 5:
                find_highest_duration_song(start);
                break;
            case 6:
                printf("Enter released year: ");
                scanf("%d", &released_year);
                display_songs_by_year(start, released_year);
                break;
            case 7:
                printf("Enter song name: ");
                scanf("%s", song_name);
                search_song_by_name(start, song_name);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

Song create_song() {
    Song new_song = (Song ) malloc(sizeof(Song));

    printf("Enter song name: ");
    scanf("%s", new_song->song_name);

    printf("Enter released year: ");
    scanf("%d", &(new_song->released_year));

    printf("Enter singer name: ");
    scanf("%s", new_song->singer_name);

    printf("Enter duration: ");
    scanf("%d", &(new_song->duration));

    printf("Enter film name: ");
    scanf("%s", new_song->film_name);

    new_song->next = NULL;
    new_song->prev = NULL;

    return new_song;
}

void add_song(Song **start_ref, Song *new_song) {
    if (*start_ref == NULL) {
        *start_ref = new_song;
    } else {
        Song *last = *start_ref;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_song;
        new_song->prev = last;
    }
}

void display_songs(Song *start) {
    Song *temp = start;

    while (temp != NULL) {
        printf("\nSong name: %s\nReleased year: %d\nSinger name: %s\nDuration: %d\nFilm name: %s\n", temp->song_name, temp->released_year, temp->singer_name, temp->duration, temp->film_name);
        temp = temp->next;
    }
}

void display_songs_by_singer(Song *start, char *singer_name) {
    Song *temp = start;

    while (temp != NULL) {
        if (strcmp(temp->singer_name, singer_name) == 0) {
            printf("\nSong name: %s\nReleased year: %d\nSinger name: %s\nDuration: %d\nFilm name: %s\n", temp->song_name, temp->released_year, temp->singer_name, temp->duration, temp->film_name);
        }
        temp = temp->next;
    }
}

void delete_song_by_name(Song **start_ref, char *song_name) {
    Song *temp = *start_ref, *prev;

    while (temp != NULL) {
        if (strcmp(temp->song_name, song_name) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *start_ref = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    }

    printf("Song not found!\n");
}

Song *find_highest_duration_song(Song *start) {
    Song *temp = start;
    int max_duration = 0;

    while (temp != NULL) {
        if (temp->duration > max_duration) {
            max_duration = temp->duration;
        }
        temp = temp->next;
    }

    temp = start;
    while (temp != NULL) {
        if (temp->duration == max_duration) {
            printf("\nSong name: %s\nReleased year: %d\nSinger name: %s\nDuration: %d\nFilm name: %s\n", temp->song_name, temp->released_year, temp->singer_name, temp->duration, temp->film_name);
        }
        temp = temp->next;
    }

    return start;
}

void display_songs_by_year(Song *start, int released_year) {
    Song *temp = start;

    while (temp != NULL) {
        if (temp->released_year == released_year) {
            printf("\nSong name: %s\nReleased year: %d\nSinger name: %s\nDuration: %d\nFilm name: %s\n", temp->song_name, temp->released_year, temp->singer_name, temp->duration, temp->film_name);
        }
        temp = temp->next;
    }
}

Song *search_song_by_name(Song *start, char *song_name) {
    Song *temp = start;

    while (temp != NULL) {
        if (strcmp(temp->song_name, song_name) == 0) {
            printf("\nSong name: %s\nReleased year: %d\nSinger name: %s\nDuration: %d\nFilm name: %s\n", temp->song_name, temp->released_year, temp->singer_name, temp->duration, temp->film_name);
            return temp;
        }
        temp = temp->next;
    }

    printf("Song not found!\n");
    return NULL;
}
