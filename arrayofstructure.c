#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char name[10];
    int  roll_no;
    float sgpa;
}stud;

void read(stud s[10], int n);
void display(stud s[10], int n);
void highest_sgpa(stud s[10], int n);
void searchByName(stud s[10], int n, char searchName[10]);
void searchByRollNo(stud s[10], int n, int rollNo);
void sortByRollno(stud s[10], int n);

int main()
{
    stud s[10];
    int n;
    float high;
    int searchRollNo;
    char searchName[10];

    printf("Enter Number of Students\n");
    scanf("%d", &n);

    read(s, n);
    display(s, n);

    sortByRollNo(s, n);
    printf("\nSorted by Roll Number:\n");
    display(s,n);

    highest_sgpa(s, n);

    printf("\nEnter the name to search: ");
    scanf("%s", searchName);
    searchByName(s, n, searchName);

    printf("\nEnter the roll number to search: ");
    scanf("%d", &searchRollNo);
    searchByRollNo(s, n, searchRollNo);



}

void read(stud s[10], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Enter %d Student Details\n", i + 1);
        printf("Enter Student Name\tRollno\tSGPA\n");
        scanf("%s%d%f", s[i].name, &s[i].roll_no, &s[i].sgpa);
    }
}

void display(stud s[10], int n)
 {
    int i;
    printf("\nName\tRollno\tSGPA\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll_no, s[i].sgpa);
    }
}

void sortByRollNo(stud s[10], int n)
{
    int i,j;
    for(i = 0; i < n - 1; i++)
        {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].roll_no > s[j + 1].roll_no)
            {
                stud temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void highest_sgpa(stud s[10],int n)
{
    float highest=s[0].sgpa;
    int i;
    int index;
    for(i=0;i<n;i++)
    {
        if(s[i].sgpa>highest)
        {
            highest=s[i].sgpa;
            index=i;
        }
    }
    printf("\nThe Student with Highest SGPA\n");
    printf("\nName\tRollno\tSGPA\n");
    printf("%s\t%d\t%.2f\t",s[index].name,s[index].roll_no,s[index].sgpa);

}
void searchByName(stud s[10], int n, char searchName[10])
{
    int found = 0;
    int i;
    printf("\nSearch Results for '%s':\n", searchName);
    printf("Name\tRollno\tSGPA\n");
    for (i = 0; i < n; i++)
        {
        if (strcmp(s[i].name, searchName) == 0)
        {
            printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll_no, s[i].sgpa);
            found = 1;
        }
    }
    if (found == 0)
     {
        printf("No student found with name '%s'.\n", searchName);
    }
}

void searchByRollNo(stud s[10], int n, int rollNo)
 {
    int found = 0;
    int i;
    printf("\nSearch Results for Roll Number '%d':\n", rollNo);
    printf("Name\tRollno\tSGPA\n");
    for (i = 0; i < n; i++)
    {
        if (s[i].roll_no == rollNo)
        {
            printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll_no, s[i].sgpa);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("No student found with roll number '%d'.\n", rollNo);
    }
}
