#include<stdio.h>
#include<string.h>
void read_string(char name1[20],char name2[20]);
void display_string(char name1[20],char name2[20]);
void stringcopy(char name1[20],char name2[20]);

main()
{
    char name1[20],name2[20];
    printf("Enter the Name:\n");
    read_string(name1,name2);
    display_string(name1,name2);
    stringcopy(name1,name2);

}
void read_string(char name1[20],char name2[20])
{
    gets(name1);
    gets(name2);
}
void display_string(char name1[20],char name2[20])
{
    printf("%s %s \n",name1,name2);

}
void stringcopy(char name1[20],char name2[20])
{
    int i;
    for(i=0;name1[i]!='\0';i++)
    {
        name1[i]=name2[i];
    }
    name1[i]='\0';
    printf("After copying \n");
    printf("Name 1 is %s",name1);
}

