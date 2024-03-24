#include<stdio.h>
#include<stdlib.h>

struct student
{
    char sname[20];
    int roll_no;
    float sgpa;
};

struct student read(struct student x);
void display(struct student x);

int main()
{
    struct student s1;
    struct student s2;
    struct student s3;
    s1=read(s1);
    display(s1);
    s2=read(s2);
    display(s2);
    s3=read(s3);
    display(s3);
}

struct student read(struct student x)
{
    printf("\nEnter the Name:\nEnter the Roll_No\nEnter the SGPA:\n");
    scanf("%s%d%f",x.sname,&x.roll_no,&x.sgpa);

    return x;
}

void display(struct student x)
{
    printf("\nName:%s\nRoll No:%d\nSGPA:%0.2f",x.sname,x.roll_no,x.sgpa);

}
