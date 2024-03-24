#include<stdio.h>

void prime(int n);

main()
{
    int n;
    printf("Enter the number n:\n");
    scanf("%d",&n);
    prime(n);
}
void prime(n)
{
    int i,count=0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
        if(count==2)
            printf("The number is prime\n");
        else
            printf("The number is not prime\n");

}
