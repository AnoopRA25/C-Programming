
#include<stdio.h>
struct player
{
    char name[20];
    int hundreds;
    float average;
};
void display(char name[10],int hundreds,float average);


void main()
{
    struct player p1;
    printf("Enter the name,hundreds,average:\n");
    scanf("%s\t%d\t%f",&p1.name,&p1.hundreds,&p1.average);
    display(p1.name,p1.hundreds,p1.average);
}

void display(char name[10],int hundreds,float average)
{
   printf("The Stats are \n%s\n%d\n%0.4f ",name,hundreds,average);

}


