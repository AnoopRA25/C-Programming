#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct Queue
{
    int f;
    int r;
    char data[MAX];
} que;
int isfull(que *q)
{
    if (q->r == MAX - 1)
        return 1;
    else
        return 0;
}
int isempty(que *q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}
void enqueue(que *q, int num)
{
    if (isfull(q))
        printf("Queue Overflow\n");
    else
    {
        q->r++;
        q->data[q->r] = num;
    }
}
int dequeue(que *q)
{
    int x = 0;
    if (isempty(q))
        printf("Queue Underflow\n");
    else
    {
        q->f++;
        x = q->data[q->f];
    }
    return x;
}

int tollway()
{
    que q;
    int count=0;
    int amount=0;
    int i;
    for(i=q.f; i<q.r; i++)
    {
        if(q.data[i]=='l'&&q.data[i]=='L')
        {
            count++;
        }

        if(q.data[i]=='h'&&q.data[i]=='H')
        {
            amount=amount+100;
        }
    }
    printf("The number of LMV vehicles are %d",count);
    printf("The amount from HMV vehicles are %d",amount);


}
int main()
{
    int ch;
    char data;
    que q;
    q.f = q.r = -1;
    while (1)
    {
        printf("Queue OPerations\n1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an integer number to be inserted in queue\n");
            scanf("%c", q.data);
            enqueue(&q, data);
            break;
        case 2:
            data = dequeue(&q);
            if (q.data == 0)
                printf("Queue Underflow\n");
            else
                printf("Dequeued %c\n", data);
            break;
        case 3:
            display(&q);
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
        }
    }
}
void display(que *q)
{
    int i;
    if (isempty(q))
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements are\n");
        for (i = q->f + 1; i <= q->r; i++)
            printf("%c\t", q->data[i]);
    }
}
