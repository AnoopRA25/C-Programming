#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10

typedef struct Queue {
    int f,r;
    int age[MAX];
    char Name[MAX][10];
    char C[MAX];
} que;

int isfull(que *q) {
    if (q->r == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(que *q) {
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

void enqueue(que *q) {
    int age;
    char Name[10];
    char C;
    if(isfull(q)) {
        printf("Queue Overflow\n");
    } else {
        q->r++;
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter name: ");
        scanf("%s", Name);
        printf("Customer type (R-Regular,V-VIP)\n");
        scanf(" %c", &C);
        q->age[q->r] = age;
        strcpy(q->Name[q->r], Name);
        q->C[q->r] = C;
    }
}

void dequeue(que *q) {
    int x = 0;
    char y[10];
    if (isempty(q))
        printf("Queue Underflow\n");
    else {
        q->f++;
        x = q->age[q->f];
        strcpy(y, q->Name[q->f]);
    }
}

int countnumbers(que *q) {
    int i;
    int count=0,sum=0;
    for(i=q->f+1;i<=q->r;i++) {
        if(q->C[i]=='V'||q->C[i]=='v') {
            count++;
            sum=sum+100;
        }
    }
    printf("The number of VIP customers are %d\n",count);
    printf("Total Amount is %d\n",sum);
}

void display(que *q) {
    if(isempty(q)) {
        printf("Queue is Underflow\n");
    } else {
        for(int i=q->f+1;i<=q->r;i++) {
            if(q->C[i]=='R'||q->C[i]=='r') {
                printf("The details are \n");
                printf("%s %d ", q->Name[i], q->age[i]);
            }
        }
    }
}

int main()
{
    int choice;
    que q;
    q.f = q.r = -1;

    while (1) {
        printf("1.Enqueue\n2.Dequeue\n3.Display Details\n4.Count\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                countnumbers(&q);
                break;
            default:
                printf("Invalid choice\n");
                exit(0);
        }
    }
}
