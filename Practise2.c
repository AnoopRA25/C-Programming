#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int id;
    int age;
    struct NODE *next;
} *node;

node getnode();
node insert_rear(node head);
int search_delete(node head);
void display_details(node head);
node delete_rear(node head);

// Rest of the functions remain unchanged...

int search_delete(node head)
{
    node cur, prev;
    int key;
    int found = 0;
    printf("Enter the ID of the customer to delete: ");
    scanf("%d", &key);
    cur = head;
    while (cur != NULL)
    {
        prev = cur;
        if (cur->id == key)
        {
            found = 1;
            prev->next = cur->next;
            printf("Details of the deleted customer: ID: %d Age: %d\n", cur->id, cur->age);
            free(cur);
            break;
        }
        cur = cur->next;
    }
    return found;
}

node delete_rear(node head)
{
    int N, i;
    node prev, cur;
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    prev = NULL;
    cur = head;
    printf("Enter the number of customers to be removed from the rear: ");
    scanf("%d", &N);
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    for (i = 0; i < N; i++)
    {
        printf("Deleted: %d\n", cur->id);
        free(cur);
        prev->next = NULL;
    }
    return head;
}




// Rest of the main function remains unchangednode
delete_rear(node head)
{
    int N,i;
    node prev,cur;
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }


    prev=NULL;
    cur=head;
    printf("Enter the number of customer to be removed from rear");
    scanf("%d",&N);
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    for(i<=N)
    {
        printf("Deleted: %d\n",cur->id);
        free(cur);
        prev->next=NULL;
        i++;
    }
    return head;
}
