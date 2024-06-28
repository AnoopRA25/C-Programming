#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100

typedef struct Stack
{
    int A[max];
    int top;
} stack;

int isfull(stack *s)
{
    if (s->top == max-1)
        return 1;
    else
        return 0;
}

int isempty(stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void push(stack *s,int data)
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
void pop(stack *s)
{
    if(isempty(s))
    {
        printf("Stack underflow\n");
    }
    else
        s->top--;
}

int balancedparentheses(char exp)
{
    stack ps;
    ps.top=-1;
    char inp;
    int i;

    for(i=0;(inp=exp[i])!='\0';i++)
    {
        if(inp==isdigit(&ps)&& inp==isalphabet(&ps))
        {
            push(&ps,inp);
        }
        if(inp=='/'||inp=='*'||inp=='+'||inp=='-')
        {
            push(&ps,inp);
        }
        if(inp=='('&&ps.top!=')')
        {
            printf("NO\n");
        }
        else if(inp=='('&&ps.top==')')
        {
            printf("YES\n");
        }
        if(inp=='{'&&ps.top!='}')
        {
            printf("NO\n");
        }
        else if(inp=='{'&&ps.top=='}')
        {
            printf("YES\n");
        }
        if(inp=='['&&ps.top!=']')
        {
            printf("NO\n");
        }
        else if(inp=='['&&ps.top==']')
        {
            printf("YES\n");
        }
    }
}

int main()
{
    stack s;
    s.top=-1;
    char exp[10];
    scanf("%s",exp);
    balancedparentheses(exp);

}

