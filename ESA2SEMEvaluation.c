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

node getnode()
{
    node new_node;
    new_node = (node)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        printf("Not Created\n");
        exit(0);
    }
    else
    {
        printf("Enter the details of the customer (ID Age): ");
        scanf("%d %d", &new_node->id, &new_node->age);
        new_node->next = NULL;
    }
    return new_node;
}

node insert_rear(node head)
{
    node new_node, cur;
    new_node = getnode();
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    return head;
}

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

        if (cur->id == key)
        {
            found = 1;
            prev->next = cur->next;

            printf("Details of the deleted customer: ID: %d Age: %d\n", cur->id, cur->age);
            free(cur);
            break;
        }
        prev = cur;
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

void display_details(node head)
{
    node cur = head;
    printf("Customer details:\n");
    while (cur != NULL)
    {
        printf("ID: %d Age: %d\n", cur->id, cur->age);
        cur = cur->next;
    }
}

int main()
{
    node head = NULL;
    int choice;
    int found;
    for (;;)
    {
        printf("\n1-Insert Rear\n2-Search and delete\n3-Display details\n4-Delete Rear\n5-Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert_rear(head);
            break;
        case 2:
            found = search_delete(head);
            if (found)
                printf("Customer found\n");
            else
                printf("Customer not found\n");
            break;
        case 3:
            display_details(head);
            break;
        case 4:
            head = delete_rear(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

