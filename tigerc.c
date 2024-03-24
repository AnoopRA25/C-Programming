#include<stdio.h>
void Tiger_Population(int,float,int);
main()
{
   int x,z;
   float y;
   printf("enter estimated tiger population in 2003\n");
   scanf("%d",&x);
   printf("enter the rate of increase in tiger population since 2003\n");
   scanf("%f",&y);
   printf("enter number of year after 2003\n");
   scanf("%d",&z);
   Tiger_Population(x,y,z);
}

void Tiger_Population(int x,float y,int z)
{
    int i;
    printf("year-Tiger population\n");
    for(i=2003;i<2003+z;i++)
    {
         x=x+(x*y)/100;
         printf("%d-%d\n",i,x);
    }
}

