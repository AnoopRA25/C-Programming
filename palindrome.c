#include<stdio.h>

void palindrome(int n);

main()
{
    int n;
    printf("Enter the number :\n");
    scanf("%d",&n);
    palindrome(n);
}
void palindrome(int n)
{
    int d,temp,N,rev=0;
    temp=N;
    while (N != 0) {
        d=N % 10;
        rev = rev * 10 + d;
        N /= 10;
    }


    if (temp == rev)
        printf("Number is a palindrome.");
    else
        printf("Number is not a palindrome.");



}
