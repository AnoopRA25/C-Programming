#include<stdio.h>
void read(int a[100][100],int r,int c);
void display(int a[100][100],int r,int c);
void rowsum(int a[100][100],int r,int c);
int main()
{
    int a[100][100],r,c;
    printf("Enter the row and column size: \n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
    rowsum(a,r,c);
}
void read(int a[100][100],int r,int c)
{
    int i,j;
    printf("The elements are :\n");
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
void rowsum(int a[100][100],int r,int c)
{
    int sum=0;
    int i,j;
for(i=0;i<r;i++)
{
    sum=0;
    for(j=0;j<c;j++)
    {
        sum=sum+a[i][j];
    }
    printf("Sum is %d\n",sum);

}

}
