#include<stdio.h>
struct student
{
    char name[20];
    int roll_no;
    float cgpa;
};


void main()
{
    struct student s1;
    printf("Enter the name, roll number,cgpa:\n");
    scanf("%s\t%d\t%f\t",&s1.name,&s1.roll_no,&s1.cgpa);
    printf("The information is %s\t%d\t%0.4f ",s1.name,s1.roll_no,s1.cgpa);

}

