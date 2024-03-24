#include <stdio.h>
#include <string.h>

// Function to sort the characters in a string
void sort_string(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (str[j] > str[j+1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

// Function to check if two strings are anagrams or not
int check_anagram(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    sort_string(str1);
    sort_string(str2);

    return strcmp(str1, str2) == 0;
}

int main() {
    char str1[50], str2[50];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (check_anagram(str1, str2)) {
        printf("Simran is Happy\n");
    } else {
        printf("simran is sad .\n");
    }

    return 0;
}
