#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot add more elements.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: No elements to remove.\n");
        return -1; // Return a sentinel value
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack numbersStack;
    initialize(&numbersStack);

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        push(&numbersStack, num);
    }

    while (!isEmpty(&numbersStack)) {
        int currentNum = pop(&numbersStack);
        int nextNum;

        if (!isEmpty(&numbersStack)) {
            nextNum = pop(&numbersStack);
            if (currentNum == nextNum) {
                // Crush both numbers
                printf("Crushed: %d %d\n", currentNum, nextNum);
            } else {
                // Keep the next number
                push(&numbersStack, nextNum);
            }
        } else {
            // Only one number left
            printf("Remaining: %d\n", currentNum);
        }
    }

    return 0;
}

