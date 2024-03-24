#include<stdio.h>

void sumdigits(int ,int *);
void countn(int , int *);
int main()
{
    int num,s=0,count=0;
    printf("Enter the number :\n");
    scanf("%d",&num);
    sumdigits(num,&s);
    countn(num,&count);
    printf("The sum is : %d \n",s);
    printf("The count is %d",count);
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
void countn(int num,int *count)
{

      while(num!=0)
      {
          num=num/10;
          (*count)++;
      }
}

