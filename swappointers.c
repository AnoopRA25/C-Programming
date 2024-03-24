#include<stdio.h>

void swapnumbers(int *aptr,int *bptr);

int main()
{
    int a,b;
    printf("Enter the 2 numbers: ");
    scanf("%d%d",&a,&b);
    printf("Numbers before swapping = %d %d\n ",a,b);
    swapnumbers(&a,&b);
    printf("The numbers after swapping = %d %d \n",a,b);
    return 0;
}

void swapnumbers(int *aptr,int *bptr)
{
    int temp;
    int *tptr=&temp;
    *tptr=*aptr;
    *aptr=*bptr;
    *bptr=*tptr;
}
