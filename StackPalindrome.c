#include <stdio.h>
#define max 5

typedef struct Stack
{
    int A[max];
    int top;
} st;

int isfull(st *s)
{
    if (s->top == max-1)
        return 1;
    else
        return 0;
}

int isempty(st *s)
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

int pop(st *s)
{
    if(isempty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        int data = s->A[s->top];
        s->top--;
        return data;
    }

}

int main()
{
    st s;
    s.top=-1;
    int n,m,rem=0,rev=0,fact=1;
    printf("Enter the number\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid input\n");
    }
    m=n;
    while(n!=0)
    {
        rem=n%10;
        push(&s,rem);
        n=n/10;
    }
    while(s.top!=-1)
    {
        rev=rev+fact*pop(&s);
        fact=fact*10;
    }
    if(m==rev)
    {
        printf("Number is palindrome\n");
    }
    else
    {
        printf("NOt palindrome\n");
    }
}
