#include<stdio.h>
#include<string.h>
#include<math.h>

int  check(char s1[100]);
void square(int count);

int main()
{
    char s1[100];
    int i,count=0;
    printf("Enter the name of music album name:\n");
    gets(s1);
    puts(s1);
    i=check(s1);
    square(i);
    return 0;
}
int check(char s1[100])
{
    int i,c,sqr;
    int count=0;
    for(i=0;s1[i]!='\0';i++)
    {
        count++;
    }
    printf("The count is %d\n",count);
    return count;
}
void square(int count)
{
    int sqr;
    sqr=count*count;
    printf("The square is %d\n",sqr);
    if(sqr%2==0)
    {
        printf("The music album name is square\n");
    }
    else
    {
        printf("The music album name is not square\n");
    }
}


