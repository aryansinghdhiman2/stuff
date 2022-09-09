#include<stdio.h>

int main()
{
    int num;
    FILE* fptr;
    fptr=fopen("program.txt","w");

    if(fptr==NULL)
    {
        printf("Error\n");
        return 1;
    }

    printf("Enter Number: ");
    scanf("%d",&num);

    fprintf(fptr,"%d",num);
    fclose(fptr);
}