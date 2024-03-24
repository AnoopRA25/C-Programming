#include<stdio.h>

void read(int a[30],int n);
void display(int a[30],int n);
void sum(int a[30],int n);

int main()
{
    int n,a[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    sum(a,n);
}
void read(int a[30],int n)
{
    int i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[30],int n)
{
    int i;
    printf("the array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void sum(int a[30],int n)
{
    int i,s=0;
    for(i=0;i<n;i++)
    {
        s=s+a[i];
    }
    printf("THe sum is : %d \n",s);
}
