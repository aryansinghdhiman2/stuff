#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size=2,counter=0,temp=0;
    int *arr;
    arr=(int*)calloc(2,sizeof(int));
    printf("Please enter numbers(99 to stop)\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&temp);
        if(temp==99)
            break;
        arr[i]=temp;
        counter++;
        if(counter==(size))
        {
            int *anotherarr;
            anotherarr=(int*)calloc(size+1,sizeof(int));
            for(int j=0;j<size;j++)
            {
                anotherarr[j]=arr[j];
            }
            arr=realloc(arr,sizeof(int)*(size+1));
            for(int j=0;j<size;j++)
            {
                arr[j]=anotherarr[j];   
            }
            size++;
            free(anotherarr);
        }
        
    }
    for(int i=0;i<size-1;i++)
        printf("%d ",arr[i]);

    return 0;
}
