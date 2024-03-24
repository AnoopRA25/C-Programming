#include<stdio.h>

int main()
{
    int num=100;
    int *ptr;
    ptr=&num;
    printf("Address in integer pointer =%x\n",ptr);
    printf("Address of num variable is =%x\n",&num);
    printf("Value of num =%d\n",num);
    printf("Value of num via ptr is =%d\n",*ptr);
    return 0;
}
