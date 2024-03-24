//C Program to compute total package amount of customers
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
    char type_of_yatra, type_of_package;
    //input yatra and package
    printf("Enter the Yatra And Package :");
    scanf("%c%c",&type_of_yatra,&type_of_package);
    //check the package and yatra
    if(type_of_yatra=='K')
    {
        //true block for c1
        if(type_of_package=='P')
        {
            printf("Total package amount is%0.2f\n",2*10000.0);
        }
        else if(type_of_package=='C')
        {
            printf("Total package amount is%0.2f\n",2*8000.0);
        }
        else if(type_of_package=='B')
        {
            printf("Total package amount is%0.2f\n",2*5000.0);
        }
        else
        {
            printf("Invalid type of package\n");
        }
    }
    else if(type_of_yatra=='M')
    {
        if(type_of_package=='P')
        {
            printf("Total package amount is %0.2f\n",2*20000.0);
        }
        else if(type_of_package=='C')
        {
            printf("Total package amount is %0.2f\n",2*15000.0);
        }
        else if(type_of_package=='B')
        {
            printf("Total package amount is %0.2f\n",2*10000.0);
        }
        else
        {
            printf("Invalid type of package\n");
        }
    }else if(type_of_yatra=='V')
    {
        if(type_of_package=='P')
        {
            printf("Total package amount is %0.2f\n",2*20000.0);
        }
        else if(type_of_package=='C')
        {
            printf("Total package amount is %0.2f\n",2*15000.0);
        }
        else if(type_of_package=='B')
        {
            printf("Total package amount is %0.2f\n",2*10000.0);
        }
        else
        {
            printf("Invalid type of package\n");
        }
    }
    else if(type_of_yatra=='G')
    {
        if(type_of_package=='P')
        {
            printf("Total package amount is %0.2f\n",2*25000.0);
        }
        else if(type_of_package=='C')
        {
            printf("Total package amount is %0.2f\n",2*15000.0);
        }
        else if(type_of_package=='B')
        {
            printf("Total package amount is %0.2f\n",2*7000.0);
        }
        else
        {
            printf("Invalid type of package \n");
        }
    }
    else
    {
        printf("Invalid type of yatra");
    }
    return 0;
}
