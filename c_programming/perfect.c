#include <stdio.h>

int main()
{
    int n,i,k,counter=0,sum=0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
            counter++;
    
    }
    int arr[counter];
    for(i=1,k=0;i<n;i++)
    {
        if(n%i==0)
            {
                arr[k]=i;
                k++;
            }
    }
    for(k=0;k<counter;k++)
    {
        sum=sum+arr[k];
    }
    if(sum==n)
        printf("%d is a perfect number\n",sum);
    else
        printf("%d is not a perfect number\n",n);
    return 0;
}
