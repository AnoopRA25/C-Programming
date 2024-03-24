#include<stdio.h>
void read(int a[30],int n);
void display(int a[30],int n);
void sum(int a[30],int n);

main()
{
    int n,a[30];
    printf("Enter the number of subjects :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    sum(a,n);
}
void read(int a[30],int n)
{
    int i;
    printf("Enter the marks of subjects:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[30],int n)
{
    int i;
    printf("the marks are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
void sum(int a[30],int n)
{
    int i,sum=0;
    float avg;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("The sum is %d\n",sum);
    avg=sum/n;
    printf("The average is %f\n",avg);
}
