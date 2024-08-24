#include <stdio.h>
#include <stdlib.h>
int psquare(int *pointer);
int main()
{
    int num;
    printf("Enter number to be squared\n");
    scanf("%d",&num);
    psquare(&num);
    printf("The square is : %d", num);
    return 0;
}
int psquare(int *pointer)
{
    *pointer*=(*pointer);
    return *pointer;
}
