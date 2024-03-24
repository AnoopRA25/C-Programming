#include<stdio.h>
void read(int a[30],int n);
void cal(int a[30],int b[30],int c[30],int n);
void display(int a[30],int n);

main()
{
    int n,a[30],b[30],c[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    printf("Enter the A value :\n");
    read(a,n);
    printf("Enter the B value :\n");
    read(b,n);
    cal(a,b,c,n);
    printf("The calculation is :\n");
    display(c,n);
}
void read(int a[30],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void cal(int a[30],int b[30],int c[30],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        c[i]=2*a[i]+b[i];
    }
}
void display(int a[30],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

