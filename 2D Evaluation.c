#include<stdio.h>
void read(int a[100][100],int N);
void display(int a[100][100],int N);
void avggoals(int a[100][100],int N);
int main()
{
    int a[100][100],N;
    scanf("%d",&N);
    read(a,N);
    avggoals(a,N);
    display(a,N);
}
void read(int a[100][100],int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

}
void display(int a[100][100],int N)
{
   int i,j,avg,max,temp;
   max=a[0][0];
   for(i=0;i<N;i++)
   {
    for(j=0;j<5;j++)
    {
        if(max<avg)
        {
            max=avg;
            avg=temp;
            temp=max;
        }
    }
   }
}
void avggoals(int a[100][100],int N)
{
    int i,j,avg,sum;
    for(i=0;i<N;i++)
    {
      sum=0;
      for(j=0;j<5;j++)
      {
        sum=sum+a[i][j];
      }
      avg=sum/5;
      printf("Player %d : %d average score\n",i+1,avg);
    }
}
