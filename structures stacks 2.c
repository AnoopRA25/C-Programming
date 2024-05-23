#define MAX 30
#include<stdio.h>

typedef struct stack
{
   char data[MAX];
   int top;
}stk;

int full (stk*s)
{
    if(s->top==MAX-1)
        return 1;
    else{
        return 0;
    }
}


int empty(stk*s)  //or use in the function struct stack *s;
{
    if(s->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
 void push(stk*s,char x)
{
    if(full(s))
    {
        printf("Stack Overflow\n");
    }

    else{
    s->top++;
    s->data[s->top]=x;
    }

}

int pop(stk *s)
    {
        char temp;
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


   int top(stk *s)
    {
    return (s->data[s->top]);
    }

int precedence(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'|| x=='-')
        return 1;
    if(x=='*'||'/')
        return 2;
}
void infix_postfix(char infix[MAX],char postfix[MAX])
{
    stk s;
    s.top=-1;
    int i;
    int j=0;
    char x,token;
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalpha(token))
            postfix[j++]=token;
            else

                if(token=='(')
                    push(&s,token);

                else if(token==')')
                {
                    while((x=pop(&s))!='(')
                    {
                        postfix[j++]=x;
                    }
                }
                else{
                    while(precedence(token)<=precedence(top(&s))&&!empty(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;

                    }
                    push(&s,token);

                }

            }

    while(!empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
     postfix[j++]='\0';
}

main()
{
    char infix[20],postfix[20];
    printf("Enter the input expression\n");
    scanf("%s",infix);
    infix_postfix(infix,postfix);
    printf("Postfix expression:%s\n",postfix);
}
