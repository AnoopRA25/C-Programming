#include <stdio.h>
#include <string.h>

int count_characters(char* name) {
    int count = 0;
    for (int i = 0; i < strlen(name); i++) {
        count++;
    }
    return count;
}

int calculate_points(int count) {
    return count * count;
}

int check_winner(int points) {
    if (points % 2 == 0) {
        return 1; // Player is winner
    } else {
        return 2; // Computer is winner
    }
}

int main() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    int count = count_characters(name);
    int points = calculate_points(count);
    int winner = check_winner(points);

    printf("The count of characters in your name is: %d\n", count);
    printf("The calculated points are: %d\n", points);

    if (winner == 1) {
        printf("The winner is: Player\n");
    } else {
        printf("The winner is: Computer\n");
    }

    return 0;
}
