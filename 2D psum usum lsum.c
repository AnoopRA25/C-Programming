#include<stdio.h>
void read(int a[100][100],int r,int c);
void display(int a[100][100],int r,int c);
void sum(int a[100][100],int r , int c);
int main()
{
    int a[100][100],r,c;
    printf("Enter the row and column size: \n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
    sum(a,r,c);
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
            printf("%d",a[i][j]);
        }
        printf("\n");
    }

}
void sum(int a[100][100],int r ,int c)
{
    int i,j,psum=0,usum=0,lsum=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
            {
                psum=psum+a[i][j];
            }
            if(i<j)
            {
                usum=usum+a[i][j];
            }
            if(i>j)
            {
                lsum=lsum+a[i][j];
            }
        }
    }
    printf("psum is : %d\n",psum);
    printf("usum is : %d\n",usum);
    printf("lsum is : %d\n",lsum);
}
