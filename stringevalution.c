#include<stdio.h>
#include<string.h>
#include<math.h>
int sizecheck(char *str);
void Display(int s);
int main ()
{
    char str[100];
    puts("Enter the name of the album ");
    gets(str);
    int s;
    s=sizecheck(str);
    Display(s);
    return 0 ;
}
int sizecheck(char *str)
{
    int size =0;
    int k = 0;
    while(str[k]!='\0')
    {
        size++;
        k++;
    }
    printf("The number of characters in album is %d\n",size);
    return size ;
}
void Display(int s)
{
    int p =s*s;
    printf("The square is %d\n",p);
    if(p%2==0)
        printf("The album is square");
    else
       printf("The album is not square");
}

