#include <stdio.h>

int main()
{
    int i,l,k,j,temp=0,sum=0;
    printf("Enter the number of elements in the arrays\n");
    scanf("%d",&i);
    int arr[i];
    int arr_2[i];
    int finalArray[i];
    printf("Please enter the numbers for 1st Array\n");
    for(l=0;l<i;l++)
    {
        printf("%d> ",l+1);
        scanf("%d",&temp);
        arr[l]=temp;
    }
    printf("\nPlease enter the numbers for 2nd Array\n");
    for(l=0;l<i;l++)
    {
        printf("%d> ",l+1);
        scanf("%d",&temp);
        arr_2[l]=temp;
    }
    
    for(l=0,j=0;l<i;l++)
    {
        for(k=0;k<i;k++)
        {
            if(arr_2[k]==arr[l])
            {
                finalArray[j]=arr_2[k];
                j++;
            }
        }
    }
    temp=j;
    for(j=0;j<temp;j++)
    {
        printf("%d ",finalArray[j]);
    }
}
