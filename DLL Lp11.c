#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char doctorname[50];
    int joinig_year;
    char status;
    char specilization[50];
    char doctoravailabilty[50];
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *NODE;
NODE getnode()
{
    NODE newnode = (NODE)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory not created...");
        exit(0);
    }
    else
    {
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    printf("\nEnter the doctor details:\n");
    printf("Doctor name: ");
    scanf("%s", newnode->doctorname);
    printf("Joining year: ");
    scanf("%d", &newnode->joinig_year);
    printf("Status (A for Active, R for Resigned): ");
    scanf(" %c", &newnode->status);
    printf("Specialization: ");
    scanf("%s", newnode->specilization);
    printf("Availability: ");
    scanf("%s", newnode->doctoravailabilty);
    return newnode;
}
NODE insert_end(NODE head)
{
    NODE newnode = getnode();
    if (head == NULL)
        return newnode;
    else
    {
        NODE temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        return head;
    }
}
void display_forward(NODE head)
{
    if (head == NULL)
    {
        printf("\nLIST EMPTY....\n");
        return;
    }
    NODE cur = head;
    printf("\nDoctor Details (Forward Direction):\n");
    while (cur != NULL)
    {
        printf("Doctor name: %s\n", cur->doctorname);
        printf("Joining year: %d\n", cur->joinig_year);
        printf("Status: %c\n", cur->status);
        printf("Specialization: %s\n", cur->specilization);
        printf("Availability: %s\n", cur->doctoravailabilty);
        printf("\n");
        cur = cur->next;
    }
}
void display_backward(NODE head)
{
    if (head == NULL)
    {
        printf("\nLIST EMPTY....\n");
        return;
    }
    NODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    printf("\nDoctor Details (Backward Direction):\n");
    while (cur != NULL)
    {
        printf("Doctor name: %s\n", cur->doctorname);
        printf("Joining year: %d\n", cur->joinig_year);
        printf("Status: %c\n", cur->status);
        printf("Specialization: %s\n", cur->specilization);
        printf("Availability: %s\n", cur->doctoravailabilty);
        printf("\n");
        cur = cur->prev;
    }
}
void displaydocspecality(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    char spc[50];
    printf("Enter the specialization: ");
    scanf("%s", spc);
    NODE cur = head;
    int found = 0;
    printf("\nDoctor Details with Specialization \"%s\":\n", spc);
    while (cur != NULL)
    {
        if (strcmp(cur->specilization, spc) == 0)
        {
            printf("Doctor name: %s\n", cur->doctorname);
            printf("Joining year: %d\n", cur->joinig_year);
            printf("Status: %c\n", cur->status);
            printf("Specialization: %s\n", cur->specilization);
            printf("Availability: %s\n\n", cur->doctoravailabilty);
            found = 1;
        }
        cur = cur->next;
    }
    if (!found)
        printf("No doctors found with the specified specialization.\n");
}
void displaydocafter6(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    int found = 0;
    printf("\nDoctor Details available after 6pm:\n");
    while (cur != NULL)
    {
        if (strcmp(cur->doctoravailabilty, "6pm") == 0)
        {
            printf("Doctor name: %s\n", cur->doctorname);
            printf("Joining year: %d\n", cur->joinig_year);
            printf("Status: %c\n", cur->status);
            printf("Specialization: %s\n", cur->specilization);
            printf("Availability: %s\n\n", cur->doctoravailabilty);
            found = 1;
        }
        cur = cur->next;
    }
    if (!found)
        printf("No doctors available at 6pm.\n");
}
int displaydocbetween1995_2022(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    NODE cur = head;
    int cnt = 0;
    while (cur != NULL)
    {
        if (cur->joinig_year >= 1995 && cur->joinig_year <= 2022)
        {
            cnt++;
        }
        cur = cur->next;
    }
    if (cnt == 0)
        printf("No doctors found who joined between 1995 and 2022.\n");
    return cnt;
}
NODE delete_at_specific(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    char statusToDelete;
    printf("\nEnter the status to delete (A for Active, R for Resigned): ");
    scanf(" %c", &statusToDelete);
    NODE cur = head;
    NODE prev = NULL;
    int found = 0;
    while (cur != NULL)
    {
        if (cur->status == statusToDelete)
        {
            found = 1;
            if (prev == NULL)
            {
                head = cur->next;
                if (head != NULL)
                    head->prev = NULL;
                printf("Deleted: %s\n", cur->doctorname);
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                if (cur->next != NULL)
                    cur->next->prev = prev;
                printf("Deleted: %s\n", cur->doctorname);
                NODE nextNode = cur->next;
                free(cur);
                cur = nextNode;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    if (!found)
        printf("No doctors found with the specified status.\n");
    return head;
}
int main()
{
    NODE head = NULL;
    int choice, yearcnt;
    while (1)
    {
        printf("\n1. Enter Doctor's details\n2. Display Doctor's list in forward direction\n3. Display Doctor's list in backward direction\n4. Delete the doctor details if the doctor resigns\n5. Display Doctor's details of specific speciality\n6. Display the Doctor's list who are available at 6 pm\n7. Count of doctors who have joined the hospital between the year 1995-2022\n8. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
            display_forward(head);
            break;
        case 3:
            display_backward(head);
            break;
        case 4:
            head = delete_at_specific(head);
            break;
        case 5:
            displaydocspecality(head);
            break;
        case 6:
            displaydocafter6(head);
            break;
        case 7:
            yearcnt = displaydocbetween1995_2022(head);
            printf("The number of doctors who joined the hospital between 1995-2022 = %d\n", yearcnt);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
