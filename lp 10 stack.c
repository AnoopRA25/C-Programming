#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
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
        exit(1);
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack arjunStack, bheemStack;
    initialize(&arjunStack);
    initialize(&bheemStack);

    printf("Enter number picked by Arjun: ");
    int num1;
    scanf("%d", &num1);
    push(&arjunStack, num1);

    printf("Enter number picked by Bheem: ");
    int num;
    scanf("%d", &num);
    push(&bheemStack, num);

    if (num1 > num) {
        printf("1\n");
        int popped = pop(&bheemStack);
        printf("Popped from Bheem's stack: %d\n", popped);
    } else if (num1 < num) {
        printf("2\n");
        int popped = pop(&arjunStack);
        printf("Popped from Arjun's stack: %d\n", popped);
    } else {
        printf("0\n");
        int poppedArjun = pop(&arjunStack);
        int poppedBheem = pop(&bheemStack);
        printf("Popped from Arjun's stack: %d\n", poppedArjun);
        printf("Popped from Bheem's stack: %d\n", poppedBheem);
    }

    printf("Remaining elements in Arjun's stack:\n");
    while (!isEmpty(&arjunStack)) {
        printf("%d ", pop(&arjunStack));
    }
    printf("\n");

    printf("Remaining elements in Bheem's stack:\n");
    while (!isEmpty(&bheemStack)) {
        printf("%d ", pop(&bheemStack));
    }
    printf("\n");

    return 0;
}
