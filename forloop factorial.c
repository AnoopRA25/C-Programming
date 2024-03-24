#include<stdio.h>
void fact(int N);

main()
{
    int N;
    printf("Enter the value of N\n");
    scanf("%d",&N);
    fact(N);
}

void fact(int N)
{
    int i,res=1;
    for(i=1;i<=N;i++)
    {
        res=res*i;
    }
    printf("Fact=%d",res);
}
