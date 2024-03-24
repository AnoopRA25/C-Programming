//C Program to compute net amount a customer has to pay
/*
   Name    : Anoop R A
   Roll No : 1132
   Division: K
   Date    : 31/10/2023
*/

#include<stdio.h>
int main()
{
    //local declaration
    char type_of_item;
    float purchase_amt,net_amt,discount_amt;
    //input
    printf("Enter Purchase amount and Type of item :");
    scanf("%c%f",&type_of_item,&puchase_amt);
    //check for type of item and purchase amount
    if(type_of_item=='T')
    {
        if(purchase_amt>=1&&purchase_amt<=500)
        {
            net_amt=purchase_amt;
        }
        else if(purchase_amt>=501&&purchase_amt<=1000)
        {
            discount_amt=0+(purchase_amt-500)*0.05;
            net_amt=purchase_amt-discount_amt;
        }
        else if(purchase_amt>=1001)
        {
            discount_amt=0+500*0.05+(purchase_amt-1000)*0.07;
            net_amt=purchase_amt-discount_amt;
        }
        else
        {
            printf("Invalid purchase amount");
        }
    }
}
