#include<stdio.h>
void read(int a[100][100],int b[100][100],int r,int c);
void display(int a[100][100],int r,int c);
void sum(int a[100][100],int b[100][100],int s[100][100],int r,int c);
int main()
{
    int a[100][100],r,c,s[100][100],b[100][100];
    printf("Enter the row and column size: \n");
    scanf("%d%d",&r,&c);
    read(a,b,r,c);
    display(a,r,c);
    sum(a,b,s,r,c);
}
void read(int a[100][100],int b[100][100],int r,int c)
{
    int i,j;
    printf("The element of 1 array are :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The element of 2 array are :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
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
void sum(int a[100][100],int b[100][100],int s[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            s[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }

}
