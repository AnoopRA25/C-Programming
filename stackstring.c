#include<stdio.h>
#define max 5

typedef struct stack
{
    char A[max];
    int top;

} st;

int isfull(st *s)
{
    if(s->top==max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(st *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(st *s, char data)
{
    if(isfull(s))
    {
        printf("stack overflow\n");
    }
    else
    {
        s->top++;
        s->A[s->top]=data;
    }
}
void pop(st *s)
{
    if(isempty(s))
    {
        printf("stack underflow\n");
    }
    else
    {
        s->top--;
    }
}
void display(st *s)
{
    int i;
    if(isempty(s))
    {
        printf("stack empty\n");
    }
    else
    {
        for(i=s->top; i>=0; i--)
        {
            printf("%c\n", s->A[i]);
        }
    }
}
int main()
{
    st s;
    s.top=-1;
    push(&s, 'A');
    display(&s);
    printf("\n");
    push(&s, 'B');
    display(&s);
    printf("\n");
    push(&s, 'C');
    display(&s);
    pop(&s);
    printf("\n");
    display(&s);
    pop(&s);
    printf("\n");
    display(&s);
    pop(&s);
    printf("\n");
    display(&s);
    return 0;
}
