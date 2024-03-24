#include<stdio.h>

void read_array(int *ap, int *np)
{
    int i;
    for(i=0;i<*np;i++)
    {
        scanf("%d",ap);
        ap++;
    }
}

void display_array(int *ap, int *np)
{
    int i;
    for(i=0;i<*np;i++)
    {
        printf("%d",*ap);
        ap++;
    }
}
 int sum_array(int *ap, int *np)
 {
     int i,sum=0;
     for(i=0;i<*np;i++)
     {
         sum=sum+*ap;
         ap++;
     }
     return sum;
 }

 int main ()
 {
     int a[100],n,sum=0;
     int *sumptr=&sum;
     printf("Enter n value:");
     scanf("%d",&n);
     printf("Enter the array elements \n");
     read_array(a,&n);
     printf("Array elements are \n");
     display_array(a,&n);
     *sumptr=sum_array(a,&n);
     printf("Sum of the array elements is %d \n",*sumptr);
     return 0;
 }

