#include<stdio.h>
void read(int a[30],int n);
void display(int a[30],int n);
void count(int a[30],int n);

main()
{
    int n,a[30];
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    count(a,n);
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
void count(int a[30],int n)
{
    int i,even=0,odd=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            even=even+1;
        }
        else
        {
            odd=odd+1;
        }
    }
        printf("The number of even is %d and odd is %d \n",even,odd);

}

