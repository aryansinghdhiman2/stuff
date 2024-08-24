#include <stdio.h>

int main()
{
    int arr[10]={0};
    int i;
    printf("Enter 10 elements\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int j;
    _Bool checker_array[10]={0};
    _Bool second_checker[10]={0};
    for(i=0;i<10;i++)
    {
        for(j=i;j<10;j++)
        {
            if(arr[i]==arr[j] && second_checker[j]==0)
            {
                checker_array[i]=1;
                if(i!=j)
                {
                    second_checker[j]=1;
                }
            }
        }
    }
    int size_of_new=0;
    for(i=0;i<10;i++)
    {
        size_of_new=size_of_new+checker_array[i];
    }
    int anotherarr[size_of_new];
    int k;
    for(i=0,k=0;i<10;i++)
    {
        if(checker_array[i])
        {
            anotherarr[k]=arr[i];
            k++;
        }
    }
    for(k=0;k<size_of_new;k++)
        printf("%d ",anotherarr[k]);

    return 0;
}
 
