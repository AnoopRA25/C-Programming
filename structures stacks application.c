#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int value);
int pop(Stack *s);
int isEmpty(Stack *s);
int peek(Stack *s);
void display(Stack *s);
int isPrime(int num);

void pickUntilPrimeOrEmpty(Stack *stack1, Stack *stack2) {
    srand(time(NULL));

    while (!isEmpty(stack1) || !isEmpty(stack2)) {
        int stackChoice = rand() % 2;
        int value;

        if (stackChoice == 0 && !isEmpty(stack1)) {
            value = pop(stack1);
        } else if (!isEmpty(stack2)) {
            value = pop(stack2);
        } else {
            break;
        }

        printf("Popped value: %d\n", value);

        if (isPrime(value)) {
            printf("Prime number found: %d\n", value);
            return;
        }
    }
    printf("Both stacks are empty or no prime number found.\n");
}

int main() {
    Stack stack1, stack2;
    stack1.top = -1;
    stack2.top = -1;

    int size;

    printf("Enter the size of the stacks: ");
    scanf("%d", &size);

    printf("Enter elements for stack 1:\n");
    for (int i = 0; i < size; i++) {
        int element;
        scanf("%d", &element);
        push(&stack1, element);
    }

    printf("Enter elements for stack 2:\n");
    for (int i = 0; i < size; i++) {
        int element;
        scanf("%d", &element);
        push(&stack2, element);
    }

    printf("Stack 1: ");
    display(&stack1);
    printf("\n");

    printf("Stack 2: ");
    display(&stack2);
    printf("\n");

    pickUntilPrimeOrEmpty(&stack1, &stack2);

    return 0;
}
void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int isEmpty(Stack *s) {
    return (s->top == -1) ? 1 : 0;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
}

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
