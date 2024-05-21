#include <stdio.h>
#define max 5

typedef struct Stack
{
    char A[max];
    int top;
} st;

int isfull(st *s)
{
    if (s->top == max-1)
        return 1;
    else
        return 0;
}

isempty(st *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void push(st *s,int data)
{
    if(isfull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->A[s->top] = data;
    }
}
void pop(st *s)
{
    if(isempty(s))
    {
        printf("Stack underflow\n");
    }
    else
        s->top--;
}

void display(st *s)
{
    int i;
    if(isempty(s))
    {
        printf("Stack is empty\n");
    }
    else
        for(i=s->top; i>=0; i--)
        {
            printf("%d\n",s->A[i]);
        }
}

int main()
{
    st s;
    s.top=-1;
    int num;
    for(int i=0; i<max; i++)
    {
        printf("Enter the element to be pushed\n");
        scanf("%d",&num);
        push(&s,num);
    }
    printf("\n");
    display(&s);
    printf("\n");
    for(int i=0; i<max; i++)
    {
        pop(&s);
        display(&s);
        printf("\n");
    }
    printf("\n");
    display(&s);
    return 0;
}
