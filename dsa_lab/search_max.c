#include<stdio.h>

int search(int arr[],int n)
{
    int i;
    int max=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("Inside function max= %d\n",max);
    return max;
}