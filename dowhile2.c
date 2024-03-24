#include<stdio.h>
void rev(int n);

main()
{
     int N;
     printf("Enter the N no\n");
     scanf("%d",&N);
     rev(N);
}
void rev(int N)
{
    int i,d,rev=0;
    do
    {
        d=N%10;
        rev=rev*10+d;
        N=N/10;
    }
    while(N!=0);
    printf("Reverse Number is :%d",rev);
}
