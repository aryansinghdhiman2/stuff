#include <stdio.h>
//multiple ops on array
int main()
{
    int arr[5];
    printf("Please enter 5 numbers\n");
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    int l,checker,temp;
    for(;;)
    {
        for(l=0,checker=0;l<3;l++)
        {
            if(arr[l]>arr[l+1])
            {
            temp=arr[l];
            arr[l]=arr[l+1];
            arr[l+1]=temp;
            }
            else
            checker++;
        }
        if(checker==3)
            break;
    }
    printf("The largest value is %d\nThe smallest value is %d\n",arr[4],arr[0]);
    int sum=0;
    for(i=0;i<5;i++)
    {
        sum=sum+arr[i];
    }
    printf("The sum of the numbers is %d\n",sum);
    float mean=(float)sum/5;
    printf("The mean of the numbers is %f\n",mean);
    for(i=4;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
 
