#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct Queue
{
    int f,r;
    int age[max];
} que;
int isfull(que *q)
{
    if((q->r+1)%max == q->f)
        return 1;
    return 0;
}
int isempty(que *q)
{
    if(q->r == -1 && q->f == -1)
        return 1;
    return 0;
}
void enqueue(que *q, int ele)
{
    if(isfull(q))
        printf("Queue overflow\n");
    else
    {
        if(q->r == -1 && q->f == -1)
        {
            q->r = q->f = 0;
            q->age[q->r] = ele;
        }
        else
        {
            q->r = (q->r + 1) % max;
            q->age[q->r] = ele;
        }
    }
}
void dequeue(que *q)
{
    int x;
    if(isempty(q))
    {
        printf("Queue empty\n");
    }
    else
    {
        x = q->age[q->f];
        printf("Age deleted is %d\n", x);
        if(q->r == q->f)
        {
            q->r = q->f = -1;
        }
        else
        {
            q->f = (q->f + 1) % max;
        }
    }
}
void display(que q)
{
    if (isempty(&q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        int i = q.f;
        while(i != q.r)
        {
            printf("%d\t", q.age[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", q.age[q.r]); // Print the last element
    }
}
int main()
{
    que q;
    q.r = -1;
    q.f = -1;
    int ch, age;
    while(1)
    {
        printf("Enter your choice\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the age to be inserted in queue\n");
            scanf("%d", &age);
            enqueue(&q, age);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
