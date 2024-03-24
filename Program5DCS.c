//C Program to compare the weight of two students
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
    float w1,w2;
    //input weight1
    printf("Enter the weight of Student 1: ");
    scanf("%f",&w1);
    //input weight2
    printf("Enter the weight of Student 2:");
    scanf("%f",&w2);
    //compare weight1 and weight2
    if(w1>w2)
    {
        //true block
        printf("Student1 has more weight%f\n",w1);
    }
    else
    {
        //false block
        printf("Student2 has more weight%f\n",w2);
    }
    return 0;
}
