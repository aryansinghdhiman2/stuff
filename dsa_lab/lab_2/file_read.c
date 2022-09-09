#include<stdio.h>

int main()
{
    int num;
    FILE* fptr;
    fptr=fopen("program.txt","r");

    if(fptr==NULL)
    {
        printf("Error\n");
        return 1;
    }

    fscanf(fptr,"%d",&num);
    printf("Value of num: %d",num);
    fclose(fptr);
}