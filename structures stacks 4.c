#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct Queue
{
  int value[MAX];
  int f;
  int r;
}que;

int full(que*q)
{
    if(q->r==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int empty(que *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void Enqueue(que*q,int ele)
{
    if(full(q))
    {
        printf("Overflow\n");
    }
    else{
        q->r++;
        q->value[q->r]=ele;
    }
}
int deque(que*q)
{
    int x;
    if(empty(q))
    {
        printf("Queue is empty\n");
    }
    else{
        q->f++;
        x=q->value[q->f];
    }
    return x;
}

void display_candy(que*q,int n)
{
    int sum=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        temp=deque(q);
        sum=sum+temp;
    }
    if(sum>=25 && sum<=34)
        {
            printf("Mango\n");
        }
    else if(sum>=35 && sum<=49)
        {
            printf("Strawberry\n");
        }
    else if(sum>=50 && sum<=70)
        {
        printf("Pista \n");

        }
    else{
            printf("NO CANDY AVAILABLE\n");
        }
    }


int main()
{
    int n,i,ele;
    que q;
    q.r=q.f=-1;
    printf("Enter the no. of coin :\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value of coin :\n");
        scanf("%d",&ele);
        Enqueue(&q,ele);
    }
    display_candy(&q,n);

}
