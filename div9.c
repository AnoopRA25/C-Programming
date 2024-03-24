#include <stdio.h>

int isDivisibleByNine(int num) {
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return (sum % 9 == 0);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(isDivisibleByNine(num)) {
        printf("%d is divisible by 9.\n", num);
    } else {
        printf("%d is not divisible by 9.\n", num);
    }

    return 0;
}
