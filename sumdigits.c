#include<stdio.h>

void sumdigits(int ,int *);
main()
{
    int num,s=0;
    printf("Enter the number :\n");
    scanf("%d",&num);
    sumdigits(num,&s);
    printf("The sum is : %d",s);
}

void sumdigits(int num,int *s)
{
    int d;
    while(num!=0)
    {
        d=num%10;
        *s=*s+d;
        num=num/10;
    }
}
