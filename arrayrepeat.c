#include<stdio.h>
void read(int a[30],int n);
void display(int a[30],int n);
void repeat(int a[30],int n);

main()
{
    int n,a[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    repeat(a,n);
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
void repeat(int a[30],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                printf("the repeating number is %d\n",a[i]);
            }
        }
    }
}
