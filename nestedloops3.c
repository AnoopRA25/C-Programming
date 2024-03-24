#include<stdio.h>

int main()
{
    int i,j,N;
    printf("Enter a number:\n");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i==j)
               printf("$ ");
             else
                printf("* ");
        }
        printf("\n");
    }
}


