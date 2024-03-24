#include<stdio.h>
void read(int a[100][100],int r,int c);
void display(int a[100][100],int r,int c);
int main()
{
    int a[100][100],r,c;
    printf("Enter the row and column size: \n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
}
void read(int a[100][100],int r,int c)
{
    int i,j;
    printf("The element are :\n");
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
