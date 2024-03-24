#include<stdio.h>

int main()
{
    int i,j,N;
    printf("Enter a number:\n");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=0;j<=N;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}
