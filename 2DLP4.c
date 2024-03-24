#include<stdio.h>
void read(int a[100][100],int r,int c);
void display(int a[100][100],int r,int c);
void minmax(int a[100][100],int r,int c);
void avg(int a[100][100],int r, int c);
int main()
{
    int a[100][100],r,c;
    printf("Enter the sellers and days : \n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
    avg(a,r,c);
    minmax(a,r,c);

}
void read(int a[100][100],int r,int c)
{
    int i,j;
    printf("The price :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

}
void display(int a[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
void avg(int a[100][100],int r ,int c)
{
    int i,j,sum=0;
    float avg;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            sum=sum+a[i][j];
        }
        avg=sum/c;
        printf("The avg price is :%f\n",avg);
    }
}
void minmax(int a[100][100],int r,int c)
{  int i,j;
    int max;
        for(i=0;i<r;i++)
    {
        max=a[i][0];
        for(j=0;j<c;j++)
        {
    if(a[i][j]>max)
    {
        max=a[i][j];
    }
        }

    printf("The maximum value is %d \n ",max);
    }

}
