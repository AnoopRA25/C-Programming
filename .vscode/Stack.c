#include<stdio.h>
#include<stdlib.h>
#define max 5

int push(int stack[max],int top);
int pop(int stack[max],int top);
void display(int stack[max],int top);

main()
{
    int stack[max];
    int top,ch,value;
    top=-1;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
    
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:top=push(stack,top);
               break;
        case 2:top=pop(stack,top);
               break;
        case 3:display(stack,top);
               break;
        case 4:exit(0);
               break;
        case 5:if(isempty(stack,top))
                   printf("Stack empty\n");
                else
                   printf("Stack is not empty\n");
                break;
        case 6:if(isfull(stack,top))
                  printf("Stack is full\n");
                else
                  printf("Stack is not full\n");
                break;
        case 7: value=stack_top(stack,top);
                  printf("Top element of the stack is =%d\n",value);
        default:printf("Invalid Position\n");
    }
    } 
}

int push(int stack[max],int top)
{
    int ele;
    if(top==max-1)
        printf("Stack is full\n");
    else
    {
        printf("Enter element to push\n" );
        scanf("%d",&ele);
        top++;
        stack[top]=ele;
    }
    return top;
}

int pop(int stack[max],int top)
{
    if(top==-1)
       printf("Stack is Empty\n");
    else
    {
        printf("Poped element=%d\n",stack[top]);
        top--;
    }
    return top;
}

void display(int stack[max],int top)
{
    int i;
    if(top==-1)
     printf("Stack is empty\n");
    else
    {
        printf("The elemets of the stack are\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

