#include <stdio.h>
#define max 5;

typedef struct Stack
{
    int A[max];
    int top;
} st;

int isfull(st *s)
{
    if (s->top == max - 1)
        return 1;
    else
        return 0;
}

intempty(st *s)
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
           for(i=s->top;i>=0;i--) 
           {
            printf("%d\n",s->A[i]);
           }
}

int main()
{
    st s;
    s.top=-1;
    push(&s,100);
    display(&s);
    printf("\n");
    push(&s,200);
    display(&s);
    printf("\n");
    push(&s,300);
    display(&s);
    pop(&s);
    printf("\n");
    display(&s);
    return 0;
}