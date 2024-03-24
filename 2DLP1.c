#include<stdio.h>
void read(int a[100][100],int r,int c);
void display(int a[100][100],int r,int c);
void avgstud(int a[100][100],int r,int c);
void avgeva(int a[100][100],int r,int c);
int main()
{
    int a[100][100],r,c;
    printf("Enter the no. of students and evaluations : \n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
    avgstud(a,r,c);
    avgeva(a,r,c);
}
void read(int a[100][100],int r,int c)
{
    int i,j;
    printf("The no. of students and evaluation are:\n");
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
void avgstud(int a[100][100],int r,int c)
{
    int i,j,sum;
    float avgstud;
    for(i=0;i<r;i++)
  {
    sum=0;
    for(j=0;j<c;j++)
    {
        sum=sum+a[i][j];

    }
    printf("The total marks of student is: %d \n",sum);
     avgstud=sum/c;
      printf("The Avgs is %f\n",avgstud);
  }
}

void avgeva(int a[100][100],int r,int c)
{
    int i,j,sume;
    float avgeva;
    for(j=0;j<c;j++)
  {
    sume=0;
    for(i=0;i<r;i++)
    {
        sume=sume+a[i][j];

    }
    printf("The total marks of evaluation is: %d \n",sume);
     avgeva=sume/r;
      printf("The Avge is %f\n",avgeva);
  }
}
