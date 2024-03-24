#include<stdio.h>
void read(int a[30],int n);
void display(int a[30],int n);
void minmax(int a[30],int n);

main()
{
    int n,a[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    minmax(a,n);
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

void minmax(int a[30],int n)
{
    int i,min ,max;
    min=max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            a[i]=max;
    }
    printf("%d %d",min,max);
}
