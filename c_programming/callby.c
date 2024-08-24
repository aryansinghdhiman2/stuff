#include <stdio.h>

void swap_reference(int*,int*);
void swap_value(int,int);

int main()
{
    int x,y;
    printf("Please enter two numbers\n");
    scanf("%d%d",&x,&y);
    swap_value(x,y);
    printf("Values of the numbers after swapping by call by value are %d and %d\n",x,y);
    swap_reference(&x,&y);
    printf("Values of the numbers after swapping by call by reference are %d and %d",x,y);

    return 0;
}
void swap_value(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void swap_reference(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
 
