#include<stdio.h>
void read(int a[30],int n);
void linear(int a[30],int n,int key);
void display(int a[30],int n);

main()
{
    int n,a[30],key;
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    printf("The array elements are :\n");
    display(a,n);
    printf("Enter the key to find :\n");
    scanf("%d",&key);
    linear(a,n,key);

}
void read(int a[30],int n)
{
    int i;
    printf("Enter the A value:\n");
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
void linear(int a[30],int n,int key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("The key is found at position %d\n",i);
            flag++;
        }
    }
        if(flag==0)
        {
            printf("The Key is not found\n");
        }
}

