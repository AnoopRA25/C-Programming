#include<stdio.h>

int scheme(int L,int M, int T);

int main()
{
    int L,M,To,T;
    printf("Enter the number of months for RajDhan Scheme :\n");
    scanf("%d",&L);
    printf("Enter the number of months for RajEmployee Scheme :\n");
    scanf("%d",&M);
    printf("The total number of months benifitted by both schemes is %d months ",To);
    To=scheme(L,M,T);

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
