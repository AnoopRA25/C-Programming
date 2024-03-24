//C Program to compare the weight of three students
/*
   Name     : Anoop R A
   Roll No. :1132
   Division :K
   Date     :26/10/2023
*/

#include<stdio.h>

int main()
{
    // local declaration
    float w1,w2,w3;
    //input weight1
    printf("Enter the weight of Student 1: ");
    scanf("%f",&w1);
    //input weight2
    printf("Enter the weight of Student 2:");
    scanf("%f",&w2);
    //input weight3
    printf("Enter the weight of Student 3:");
    scanf("%f",&w3);
    // compare w1,w2 and w3
    if(w1>w2)
    {
        if(w1>w3)
        {
            printf("Student1 has more weight\n");
        }
        else
        {
            printf("Student3 has more weight\n");
        }
    }
    else
    {
        if(w2>w3)
        {
            printf("Student2 has more weight\n");
        }
        else
        {
            printf("Student3 has more weight\n");
        }
    }
    return 0;
}
