#include<stdio.h>

 void gcd(int m,int n);

 main()
 {
     int m,n;
     printf("Enter m & n:\n");
     scanf("%d%d",&m,&n);
     gcd(m,n);
 }
 void gcd(int m,int n)
 {
     int rem=0,gcd;
     do
     {
         rem=m%n;
         m=n;
         n=rem;
     }
     while (rem!=0);
          gcd=m;
     printf("%d",gcd);

 }

