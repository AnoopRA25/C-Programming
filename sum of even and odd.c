#include<stdio.h>

void even(int s,int e);
void odd(int s,int e);
main()
{
    int s,e;
    printf("Enter the starting and ending range\n");
    scanf("%d %d",&s,&e);
    even(s,e);
    odd(s,e);
}

void even(int s,int e)
{
    int i,evensum=0;
    for(i=s;i<=e;i++)
    {
        if(i%2==0)
            evensum=evensum+i;
    }
    printf("Evensum=%d\n",evensum);
}

void odd(int s, int e)
{
    int i,oddsum=0;
    for(i=s;i<=e;i++)
    {
        if(i%2!=0)
            oddsum=oddsum+i;
    }
    printf("Oddsum=%d",oddsum);

}
