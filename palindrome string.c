#include <stdio.h>
#include <string.h>

int check_palindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
        {
        if (str[i] != str[length - i - 1])
        {
            return 1; // String is not a palindrome
        }
    }
    return 0; // String is a palindrome
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);

    if (check_palindrome(str) == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
