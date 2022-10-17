#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void exchange(int arr[],int size,int index_1,int index_2)
{
    int temp=arr[index_1];
    arr[index_1]=arr[index_2];
    arr[index_2]=temp;
}

int main()
{
    int size_of_arr=0;
    printf("%s","Enter size of array:");
    scanf("%d",&size_of_arr);
    int arr[size_of_arr];
    
    printf("%s","Enter Elements of the array\n");
    for(int i=0;i<size_of_arr;i++)
    {
        scanf("%d",&arr[i]);
    }

    srand((int)time(0));
    
    for(int i=0;i<size_of_arr;i++)
    {
        exchange(arr,size_of_arr,i,((rand())%size_of_arr));
    }

    for(int i=0;i<size_of_arr;i++)
        printf("%d ",arr[i]);

}
