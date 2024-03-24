#include<stdio.h>
void read(int a[30],int n);
void display(int a[30],int n);
void reverse(int a[30],int n);

main()
{
    int n,a[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    reverse(a,n);
    printf("The reverse is :\n");
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
    printf("the array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
void reverse(int a[30],int n)
{
    int i,k,temp;
    for(i=0,k=n-1;i<k;i++,k--)
    {
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }

}

