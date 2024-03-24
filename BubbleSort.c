
#include<stdio.h>
void read(int a[30],int n);
void sort(int a[30],int n);
void display(int a[30],int n);

main()
{
    int n,a[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    printf("The array elements are :\n");
    display(a,n);
    sort(a,n);
    printf("the elements after sorting are:\n");
    display(a,n);
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
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
void sort(int a[30], int n)
{
    int i,temp;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
