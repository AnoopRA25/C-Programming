#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 40
typedef struct stack
{
    int exp[max];
    int top;
} st;
void push(st *s, int n);
int pop(st *s);
int isempty(st *s);
int isfull(st *s);
int isempty(st *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}
int isfull(st *s)
{
    if(s->top==max-1)
        return 1;
    return 0;
}
int main()
{
    st s;
    s.top = -1;
    int i,a, b, result, pEval;
    char exp[20];
    char ch;
    printf("\nEnter a postfix expression: ");
    scanf("%s",exp);
    for(i=0; exp[i]!='\0'; i++)
    {
        ch=exp[i];
        if (isdigit(ch))
        {
            push(&s, ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            b = pop(&s);
            a = pop(&s);
            switch (ch)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    printf("Division by zero error\n");
                    return 1;
                }
                result = a / b;
                break;
            }
            push(&s, result);
        }
    }
    pEval = pop(&s);
    if (!isempty(&s))
    {
        printf("Invalid expression: Too many operands\n");
        return 1;
    }
    printf("\nThe postfix evaluation is: %d\n", pEval);
    return 0;
}
void push(st *s, int n)
{
    if (isfull(s))
    {
        printf("Stack is full!\n");
    }
    s->top++;
    s->exp[s->top] = n;
}
int pop(st *s)
{
    if (isempty(s))
    {
        printf("Stack is empty!\n");
        return 0;
    }
    int n = s->exp[s->top];
    s->top--;
    return n;
}
