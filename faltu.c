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
int popuntilprime(Stack* s);
int main() {
    Stack stack1;
    stack1.top = -1;

    int size;

    printf("Enter the size of the stacks: ");
    scanf("%d", &size);

    printf("Enter elements for stack 1:\n");
    for (int i = 0; i < size; i++) {
        int element;
        scanf("%d", &element);
        push(&stack1, element);
    }
  printf("Stack 1: ");
    display(&stack1);
    printf("\n");
        pickUntilPrimeOrEmpty(&stack1);

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
int popuntilprime(Stack* s)
{
    int num;
    while(s->top>=0)
    {
        num=s[s->top];
    while(isPrime(num)==0)
    {
        pop(&s);
    }
    s->top=s->top-1;
    }
}
