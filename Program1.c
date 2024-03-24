//C program to compute the distance that
//can travel
/*  Name     : Anoop R A
    Division : K
    Roll No  : 1132
    Date     : 10/10/2023
*/
#include<stdio.h>

int main()
{
    //this is local declaration section
    int mileage;
    float worth_of_petrol,petrol_price,distance,fuel_filled_in_tank;
    //compile time initialization
    mileage=14;
    worth_of_petrol=1066.64;
    //Run time initialization using scanf()
    printf("Enter Petrol Price :");
    scanf("%f",&petrol_price);
    //compute fuel filled in tank
    fuel_filled_in_tank=worth_of_petrol/petrol_price;
    //compute distance
    distance=mileage*fuel_filled_in_tank;
    //display the distance
    printf("The Distance travelled by car %f :",distance);
    return 0;
}//end of main() section
