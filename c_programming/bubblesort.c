#include <stdio.h>

int main()
{
    int i,l,temp=0;
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
    for(l=0;l<i-1;l++)
    {
        if(arr[l]>arr[l+1])
        {
        temp=arr[l];
        arr[l]=arr[l+1];
        arr[l+1]=temp;
        l=-1;
        }
    }
    for(l=0;l<i;l++)
    {
        printf("%d ",arr[l]);
    }

    return 0;
}
