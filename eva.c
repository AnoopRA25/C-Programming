#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void read(int a[1000],int N);
void display(int a[1000],int N);
void avg(int a[1000],int N,int age);
void count(int a[1000],int N,int age);

int main() {
    int a[1000],N,age;
    scanf("%d",&N);
    read(a,N);
    display(a,N);
    printf("Vaccinated Male babies average age:%d\n",age);
    avg(a,N,age);
     printf("Vaccinated Female babies average age:%d",age);
    avg(a,N,age);
    count(a,N,age);
}

void read(int a[1000],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%d ",& a[i]);
    }
}
void display(int a[1000],int N)
{
    int i;
    for (i=0;i<N;i++)
    {
        if(a[i]>=1&&a[i]<=5)
            printf("%d ",a[i]);
        else if(a[i]==0)
            printf("Invalid input");
    }
}

void avg(int a[1000],int N,int age)
{
    int i,j,sum=0,avg=0;
    for(i=0;i<N;i++)
    {
        for(j=1;j<N-1;j++)
            {
                if(j%2!=0)
                {
                    sum=sum+a[j];
                    avg=sum/j;
                 }
            }
            if(i%2==0)
            {
                sum=sum+a[i];
                avg=sum/i;
            }
    }
}

void count(int a[1000],int N,int age)
         {
            int i,j,countf=0,countm=0;
             for(i=0;i<N;i++)
             {
                 for(j=1;j<N-1;j++)
                 {
                     if(a[j]>age)
                         countm=countm+1;
                 }
                 if(a[i]>avg)
                     countf=countf+1;
             }


         }
