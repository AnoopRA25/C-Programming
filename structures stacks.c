#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct stack
{
    int data[MAX];
    int top;
}stack;

int full (stack*s)
{
    if(s->top==MAX-1)
        return 1;
    else{
        return 0;
    }
}

int empty(stack*s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
 void push(stack*s,int num)
{
    if(full(s))
    {
        printf("Stack Overflow\n");
    }

    else{
    s->top++;
    s->data[s->top]=num;
    }

}

int pop(stack *s)
    {
        int temp;
        if(empty(s))
        {
            printf("Stack Underflow\n");
        }
        else{
           temp= s->data[s->top];
           s->top--;
           return temp;
        }
    }
void Display(stack*s)
    {
        int i;
        if(empty(s))
        {
            printf("Stack Underflow\n");
        }
        for(i=0;i<=s->top;i++)
        {
            printf("%d\t\n",s->data[i]);
        }
    }

int main()
{
    stack s;
    int choice,num,x;
    s.top=-1;
    while(1)
    {
        printf("1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be pushed\n");
                    scanf("%d",&num);
                    push(&s,num);
                    break;
            case 2: x=pop(&s);
                    printf("popped element =%d\n",x);
                    break;
            case 3: Display(&s);
                    break;
            default: printf("Invalid choice\n");
                     exit(0);
        }
    }
    return 0;
}

