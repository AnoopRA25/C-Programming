#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NEWSPAPERS 100

// Structure to represent a newspaper
struct Newspaper {
    char name[50];
    float price;
};

// Stack structure
struct Stack {
    struct Newspaper data[MAX_NEWSPAPERS];
    int top;
};

// Initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_NEWSPAPERS - 1;
}

// Push a newspaper onto the stack
void push(struct Stack* stack, struct Newspaper paper) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot add more newspapers.\n");
        return;
    }
    stack->data[++stack->top] = paper;
}

// Pop a newspaper from the stack
struct Newspaper pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: No newspapers to remove.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Display the newspapers in the stack
void display(struct Stack* stack) {

    for (int i = stack->top; i >= 0; i--) {
        printf("%s (Price: %.2f)\n", stack->data[i].name, stack->data[i].price);
    }
}
int count(struct Stack*stack)
{
    return stack->top+1;
}

// ...

int main() {
    struct Stack newspaperStack;
    initialize(&newspaperStack);

    int n;
    printf("Enter the number of newspapers read: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        struct Newspaper paper;
        printf("Enter details for newspaper %d:\n", i);
        printf("Name:\n ");
        scanf("%s", paper.name);
        printf("Price:\n ");
        scanf("%f", &paper.price);
        push(&newspaperStack, paper); // Only push once here
    }

    printf("Newspapers read by Gagan:\n");
    display(&newspaperStack);

    printf("Total newspapers read: %d\n", count(&newspaperStack)); // Use the count function

    // Calculate total expenditure
    float totalExpenditure = 0.0;
    while (!isEmpty(&newspaperStack)) {
        struct Newspaper paper = pop(&newspaperStack);
        totalExpenditure += paper.price;
    }
    printf("\nTotal expenditure: %.2f\n", totalExpenditure);

    return 0;
}
