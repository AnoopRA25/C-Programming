#include<stdio.h>

int divisible(int n);

void main()
{
    int n,div;
    printf("Enter the number :\n");
    scanf("%d",&n);
    if(n%3==0&&n%9==0)
    {
        printf("The number is divisible by 3 and 9\n");
    }
    else
    {
        printf("Not divisible \n ");
    }
    div=divisible(n);
}

int divisible(int n)

{
    int i,sum=0;
    while(n!=0)
    {
        i=n%10;

        n=n/10;
        sum=sum+i;
    }
        if (sum%3==0&&sum%9==0)
        {
            printf("the sum is divisible by 3\n");
        }

        else
        {
            printf("Not divisible by sum\n");
        }

    return 0;
}
