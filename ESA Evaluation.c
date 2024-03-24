#include<stdio.h>

int scheme(int L,int M,int T);

int main()
{
    int L,M,T;
    printf("Enter the number of months for RajDhan Scheme :\n");
    scanf("%d",&L);
    printf("Enter the number of months for RajEmployee Scheme :\n");
    scanf("%d",&M);
    printf("The total number of months benifitted by both schemes is %d months.",T);
    scheme(L,M,T);
    return 0;

}

int scheme(int L,int M,int T)
{
    int Rd,Re,m;
    for(m=1;m<=12;m+L+1)
    {
        Rd++;
    }
    for(m=1;m<=12;m+M+1)
    {
        Re++;
    }
    T=Rd+Re-2;
    return T;

}
