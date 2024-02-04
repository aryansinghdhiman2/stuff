#include <stdio.h>
#include "test.h"

int main()
{
    int i,j,k;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d",&i,&j,&k);
    int sum = add(i,j,k);
    printf("Sum of Numbers is: %d\n",sum);
    int mult = MULTIPLY(i,j,k);
    printf("Multiplication of numbers is: %d",mult);
}