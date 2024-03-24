#include<stdio.h>
#include<string.h>
void read_string(char name[20]);
void display_string(char name[20]);

main()
{
    char name[20];
    printf("Enter the Name:\n");
    read_string(name);
    display_string(name);
}
void read_string(char name[20])
{
    gets(name);
}
void display_string(char name[20])
{
    printf("%s\n",name);
    printf("The length of the string =%d",strlen(name));
}
