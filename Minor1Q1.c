// C program to calculate the amount
#include<stdio.h>

float total_amount(float MRP,float disc,float total);

int main()

{
    int N;
    float total,disc,MRP;

    printf("Enter the number of Boxes:%d\n");
    scanf("%d",&N);


    total=N*total_amount(MRP,disc,total);

    printf("The total amount to pay:%f",total);
}
float total_amount(float MRP,float disc,float total)
{
    float MRP,disc;
    printf("Enter the MRP:%f\n");
    scanf("%f",&MRP);


    if(MRP>=100&&MRP<=200)
    {
        disc=MRP;
        total=total-disc;
    }
    else if(MRP>=201&&MRP<=500)
    {
        disc=MRP*0.15;
        total=total-disc;
    }
    else if(MRP>=501&&MRP<=800)
    {
        disc=MRP*0.25;
        total=total-disc;
    }
    else if(MRP>800)
    {
        disc=MRP*0.30;
        total=total-disc;
    }
    else
    {
        printf("Invalid boxes.\n");
    }
    return total;
}
