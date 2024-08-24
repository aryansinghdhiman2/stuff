#include <stdio.h>
#include "test.h"

int main()
{
    int arr[3];
    printf("Enter 3 numbers: ");
    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

    printf("Inputted Characters are :");
    for(int i=0;i<3;i++)
    {
        printf("%d\t",arr[i]);
    }

    int sum = add(arr[0],arr[1],arr[2]);
    printf("\nSum of Numbers is: %d\n",sum);
    int mult = MULTIPLY(arr[0],arr[1],arr[2]);
    printf("Multiplication of numbers is: %d",mult);
}