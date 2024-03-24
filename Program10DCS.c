// program to compute total bill
/*
   Name    : Anoop R A
   Division: K
   Roll No : 1132
   Date    : 2/11/2023
*/

#include<stdio.h>
int main()

{
    float quantity_of_sweet,bill,total_bill;
    char type_of_sweet;
    printf("Enter the quantity of sweet and type :");
    scanf("%c%f",&type_of_sweet,&quantity_of_sweet);

    switch(type_of_sweet)
    {
        case 'B': bill=quantity_of_sweet*650;
                  total_bill=bill+0.03*bill;
                  break;

        case 'K': bill=quantity_of_sweet*500;
                  total_bill=bill+0.03*bill;
                  break;

        case 'D': bill=quantity_of_sweet*480;
                  total_bill=bill+0.03*bill;
                  break;

        case 'C': bill=quantity_of_sweet*600;
                  total_bill=bill+0.03*bill;
                  break;

        default : printf("Invalid type of sweet/namkeen\n");
    }
    printf("The total bill is %0.2f\n",total_bill);

    return 0;
}
