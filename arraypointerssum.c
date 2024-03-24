#include<stdio.h>

void read(int *a,int n);
void display(int *a,int n);
void sum(int *a,int n,int *s,float *avg);

int main()
{
    int n,a[30],s=0;
    float avg=0;
    printf("Enter the number :\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    sum(a,n,&s,&avg);
    printf("the sum is %d",s);
    printf("average =%0.2f",avg);
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

void sum(int *a,int n,int *s,float *avg)
{
    int i;
    for(i=0;i<n;i++)
    {
        *s=*s+*(a+i);
    }
    *avg=*s/n;
    printf("The sum is : %d \n",*s);
}
