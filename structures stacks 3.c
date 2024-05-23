#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

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

     int cal(char op,int x,int y)
    {
        switch(op)
        {
            case'+':return(x+y);
            case'-':return(x-y);
            case'*':return(x*y);
            case'/':return(x/y);

        }
    }

    int evaluate_postfix(char postfix[15])
    {
        stack s;
        int op1,op2,res;
        int i;
        s.top=-1;
        for(i=0;i<strlen(postfix);i++)
        {
            if(isdigit(postfix[i]))
            {
                push(&s,postfix[i]-'0');
            }
            else{
                op2=pop(&s);
                op1=pop(&s);
                res=cal(postfix[i],op1,op2);
                push(&s,res);
            }
        }
            res=pop(&s);
            return res;

    }



  int   main()
    {
        char postfix[15];
        int res;
        printf("Enter the postfix expression:\n");
        scanf("%s",postfix);
        res=evaluate_postfix(postfix);
        printf("Value of postfix expression is:%d\n",res);
        return 0;
    }
