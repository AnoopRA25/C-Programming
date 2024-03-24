#include<stdio.h>

int calc_gcd(int *ap,int *bp)
{
    int i,gcd;
    for(i=1;i<=*ap&&i<=*bp;i++)
    {
        if(*ap%i==0&&*bp%i==0)
            gcd=i;
    }
    return gcd;
}

int calc_lcm(int *ap,int *bp,int *gcdp)
{
    int  lcm;
    lcm=(*ap**bp)/ *gcdp;
    return lcm;
}
int main()
{
    int a,b,gcd,lcm;
    int *ap=&a,*bp=&b,*gcdp=&gcd,*lcmp=&lcm;
    printf("Enter 2 integer number \n");
    scanf("%d%d",&a,&b);
    *gcdp=calc_gcd(ap,bp);
    printf("\nGCD is %d\n",*gcdp);
    *lcmp=calc_lcm(ap,bp,gcdp);
    printf("\nLCM is %d\n",*lcmp);
    return 0;
}
