#include<stdio.h>

int main()
{
    int *ptr;
    double *dptr;
    char *cptr;
    float *fptr;
    printf("Size of the integer pointer =%d bytes \n",sizeof(ptr));
    printf("Size of the float pointer =%d bytes \n",sizeof(fptr));
    printf("Size of the char pointer =%d bytes \n",sizeof(cptr));
    printf("Size of the double pointer =%d bytes \n",sizeof(dptr));
    return 0;
}
