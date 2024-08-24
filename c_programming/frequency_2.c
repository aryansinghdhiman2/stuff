#include <stdio.h>

int main()
{
    int num;
    printf("Please enter the number\n");
    scanf("%d",&num);
    int i,j,temp=num,digitcounter=0;
    for(i=0;temp!=0;i++)
    {
        temp=temp/10;
        digitcounter++;
    }
    temp=num;
    int arr[digitcounter],freq;
    _Bool bool_var=1;
    for(i=0;i<digitcounter && temp!=0;i++)
    {
        arr[i]=temp%10;
        temp=temp/10;
    }
    for(i=0;i<digitcounter;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
            bool_var=0;
            break;
            }
            else
            bool_var=1;
        }
        if(bool_var)
        for(j=0,freq=0;j<digitcounter;j++)
        {
            if(arr[i]==arr[j])
            freq++;
        }
        if(bool_var)
        printf("The frequency of %d is %d\n",arr[i],freq);
    }

    return 0;
}
