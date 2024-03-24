#include<stdio.h>
void read(int *a,int n);
void display(int *a,int n);
void minmax(int *a,int n,int *min,int *max);

main()
{
    int n,a[30],min,max;
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    minmax(a,n,&min,&max);
    printf("The minimum element is %d\n",min);
    printf("The maximum element is %d",max);
}
void read(int *a,int n)
{
    int i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
}
void display(int *a,int n)
{
    int i;
    printf("the array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",*(a+i));
    }
}

void minmax(int *a,int n,int *min,int *max)
{
    int i;
    *min=*a;
    *max=*a;
    for(i=0;i<n;i++)
    {
        if(*(a+i)<*min)
            *min=*(a+i);
        if(*(a+i)>*max)
            *max=*(a+i);
    }
}

