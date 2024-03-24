#include<stdio.h>
void strong(int n);
int fact(int d);
int main ()
{
    int n;
    printf("Enter the N value:\n");
    scanf("%d",&n);
    strong(n);
}

void strong(int n)
{
    int temp,d,f,sum=0;
    temp=n;
    while (n!=0)
    {
        d=n%10;
        f=fact(d);
        n=n/10;
        sum=sum+f;
    }
    printf("The sum of the number is =%d\n",sum);
    if (temp==sum)
        printf("%d is strong number\n",temp);
    else
        printf("%d is not strong number\n",temp);

}

int fact(int d)
{
    int i,mul=1;
    for(i=1;i<=d;i++)
    {
        mul=mul*i;
    }
    return mul;
}

