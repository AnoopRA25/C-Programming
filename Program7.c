//C Program to check the alphabet is vowel or consonant
/*
   Name     :Anoop R A
   Roll No. :1132
   Division :K
   Date     :26/10/2023
*/

#include<stdio.h>

int main()
{
    //local declaration
    char alphabet;
    //input alphabet
    printf("Enter the Alphabet:");
    scanf("%c",&alphabet);
    //check the alphabet
    if(alphabet=='a'|| alphabet=='e'|| alphabet=='i'|| alphabet=='o'|| alphabet=='u' || alphabet=='A'|| alphabet=='E'|| alphabet=='I'|| alphabet=='O'|| alphabet=='U')
    {
       printf("Alphabet is Vowel");
    }
    else
    {
        printf("Alphabet is Consonant");
    }
     return 0;
}
