//well ordered
#include <stdio.h>
int main()
{
    int num,temp,i;
    printf("Please enter the number\n");
    scanf("%d",&num);
    temp=num;
    int arr[3];
    for(i=0;i<3;i++)
    {
        arr[i]=temp%10;
        temp=temp/10;
    }
    if(arr[0]>arr[1] && arr[1]>arr[2])
    {
        printf("%d is well ordered\n",num);
    }
    else
    {
        printf("%d is not well ordered\n",num);
    }

    return 0;
}
