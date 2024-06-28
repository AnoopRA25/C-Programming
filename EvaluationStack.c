#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20
typedef struct stack
{
    char A[MAX];
    int top;
} st;
int isfull(st *s)
{
    if(s->top == MAX-1)
        return 1;
    return 0;
}
int isempty(st *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}
void push(st *s, char data)
{
    if(isfull(s))
// No need to print "STACK OVERFLOW" for this use case
        return;
    else
    {
        ++s->top;
        s->A[s->top] = data;
    }
}
char pop(st *s)
{
    if (isempty(s))
    {
// Return a special character to indicate underflow
        return '\0';
    }
    else
    {
        return s->A[s->top--];
    }
}
int isBalanced(st *s, char str[20])
{
    char x;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == '{' || str[i]=='(' || str[i] == '[')
            push(s,str[i]);
        else
        {
            if(str[i] == '}' || str[i]==')'|| str[i] == ']')
            {
                if (x == '\0')
                    return 0;
                x = pop(s);
                switch(str[i])
                {
                case '}' :
                    if(x == '{')
                        continue;
                    else
                        return 0;
                case ')' :
                    if(x == '(')
                        continue;
                    else
                        return 0;
                case ']' :
                    if(x == '[')
                        continue;
                    else
                        return 0;
                }
            }
        }
    }
    if(!isempty(s))
        return 0;
    return 1;
}
int main()
{
    st s;
    s.top = -1;
    int result;
    char str[20];
    scanf("%s", str);
    {
        result = isBalanced(&s, str);
    }
    if (result == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
