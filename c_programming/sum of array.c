#include <stdio.h>

int main()
{
    int i,l,temp=0,sum=0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&i);
    int arr[i];
    printf("Please enter the numbers\n");
    for(l=0;l<i;l++)
    {
        printf("%d> ",l+1);
        scanf("%d",&temp);
        arr[l]=temp;
    }
    for(l=0;l<i;l++)
    {
        sum=sum+arr[l];
    }
    printf("The sum is %d",sum);
}
