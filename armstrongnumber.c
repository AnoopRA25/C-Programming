#include<stdio.h>
void armstrong(int n);
int cube(int d);
int main ()
{
    int n;
    printf("Enter the N value:\n");
    scanf("%d",&n);
    armstrong(n);
}

void armstrong(int n)
{
    int temp,d,c,sum=0;
    temp=n;
    while (n!=0)
    {
        d=n%10;
        c=cube(d);
        n=n/10;
        sum=sum+c;
    }
    printf("The sum of the number is =%d\n",sum);
    if (temp==sum)
        printf("%d is armstrong number\n",temp);
    else
        printf("%d is not armstrong number\n",temp);

}

int cube(int d)
{
    int cube;
    cube=d*d*d;

    return cube;
}

