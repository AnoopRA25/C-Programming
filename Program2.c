//C program to calculate time required
//to cut the grass
/* Name     : Anoop R A
   Division : K
   Roll no  : 1132
   Date     : 12/10/2023
*/
#include<stdio.h>

int main()
{
    //local declaration section
    float length,width,radius;
    float area_of_rectangle,area_of_circle,area_of_lawn;
    float time;
    //runtime initilazation
    printf("Enter the length and width: ");
    scanf("%f%f",&length,&width);
    printf("Enter radius of hut:");
    scanf("%f",&radius);
    //compute area of rectangle
    area_of_rectangle=length*width;
    //compute area of circle
    area_of_circle=3.142*radius*radius;
    //calculate area of lawn
    area_of_lawn=area_of_rectangle-area_of_circle;
    //calculate time
    time=area_of_lawn/2;
    //display time
    printf("The time required to cut the grass is: %f seconds\n ",time);
    if(time<60)
    {
        //true block
        printf("Aarush can go to picnic\n");
    }
    else
    {
        //false block
        printf("Aarush cannot go to picnic\n");
    }
    return 0;
}//end of main() section
