#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *next;
    struct NODE *prev;
} *node;
node getnode();
node insert_front(node head);
node insert_rear(node head);
void display_forward(node head);
void display_backward(node head);
node delete_front(node head);
node delete_rear(node head);
int count_nodes(node head);
void search(node head);
node insert_position(node head);
node delete_position(node head);
main()
{
    node head = NULL;
    int choice, pos, c;
    for (;;)
    {
        printf("1-Insert Front\n2-Insert Rear\n3-Display_Foward\n4-Display_Backward\n5-Delete_front\n6-Delete_rear\n7-Count_Nodes\n8-Search\n9-Insert_Position\n10-Delete_Position\n11-Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert_front(head);
            break;
        case 2:
            head = insert_rear(head);
            break;
        case 3:
            display_forward(head);
            break;
        case 4:
            display_backward(head);
            break;
        case 5:
            head = delete_front(head);
            break;
        case 6:
            head = delete_rear(head);
            break;
        case 7:
            c = count_nodes(head);
            printf("count=%d\n", c);
            break;
        case 8:
            search(head);
            break;
        case 9:
            head = insert_position(head);
            break;
        case 10:
            head = delete_position(head);
            break;
        default:
            exit(0);
        }
    }
}
node getnode()
{
    node new_node;
    new_node = (node)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    else
    {
        printf("Enter data to be Inserted\n");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}
node insert_front(node head)
{
    node new_node;
    new_node = getnode();
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        head->prev = NULL;
    }
    return head;
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
        new_node->prev = cur;
        new_node->next = NULL;
    }
    return head;
}
void display_forward(node head)
{
    node cur;
    if (head == NULL)
    {
        printf("DLL is empty\n");
    }
    else
    {
        cur = head;
        while (cur != NULL)
        {
            printf("%d\n", cur->data);
            cur = cur->next;
        }
    }
}
void display_backward(node head)
{
    node cur;
    if (head == NULL)
    {
        printf("DLL is empty\n");
    }
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        while (cur != NULL)
        {
            printf("%d\n", cur->data);
            cur = cur->prev;
        }
    }
}
node delete_front(node head)
{
    node cur;
    if (head == NULL)
    {
        printf("DLL is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("Data Deletetd is\n");
        printf("%d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        printf("Data Deleted is\n");
        printf("%d\n", head->data);
        cur = head;
        head = head->next;
        free(cur);
        head->prev = NULL;
    }
    return head;
}
node delete_rear(node head)
{
    node cur, cur1;
    if (head == NULL)
    {
        printf("DLL is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("Data Deletetd is\n");
        printf("%d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        printf("Data Deletetd is\n");
        printf("%d\n", cur->data);
        cur1 = cur->prev;
        free(cur);
        cur1->next = NULL;
    }
    return head;
}
int count_nodes(node head)
{
    node cur;
    int count = 0;
    if (head == NULL)
        return (count);
    else
    {
        cur = head;
        while (cur != NULL)
        {
            count++;
            cur = cur->next;
        }
        if (cur == NULL)
            return count;
    }
}
void search(node head)
{
    node cur;
    int data;
    printf("Enter Data to be search\n");
    scanf("%d", &data);
    if (head == NULL)
        printf("DLL is empty.....cant search\n");
    else
    {
        cur = head;
        while (cur != NULL)
        {
            if (cur->data == data)
            {
                printf("Data found\n");
                printf("%d\n", cur->data);
                break;
            }
            cur = cur->next;
        }
        if (cur == NULL)
            printf("Data not found\n");
    }
}
node insert_position(node head)
{
    int pos, count;
    node new_node, cur;
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count_nodes(head) + 1)
        printf("Invalid position\n");
    else if (pos == 1)
        head = insert_front(head);
    else if (pos == count_nodes(head) + 1)
        head = insert_rear(head);
    else
    {
        new_node = getnode();
        cur = head;
        count = 1;
        while (count != pos - 1)
        {
            cur = cur->next;
            count++;
        }
        new_node->next = cur->next;
        cur->next->prev = new_node;
        cur->next = new_node;
        new_node->prev = cur;
    }
    return head;
}
node delete_position(node head)
{
    int pos, count;
    node cur, cur1;
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count_nodes(head))
        printf("Invalid position\n");
    else if (pos == 1)
        head = delete_front(head);
    else if (pos == count_nodes(head))
        head = delete_rear(head);
    else
    {
        cur = head;
        count = 1;
        while (count != pos - 1)
        {
            cur = cur->next;
            count++;
        }
        cur1 = cur->next;
        printf("Data deleted is\n");
        printf("%d\n", cur1->data);
        cur->next = cur1->next;
        cur1->next->prev = cur;
        free(cur1);
    }
    return head;
}