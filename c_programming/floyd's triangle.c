#include <stdio.h>

void main()
{
    int j,k,num=1;
    for(k=1;k<=4;k++)
    {
        for(j=1;j<=k;j++,num++)
        {
        printf("%d\t",num);
        }
        printf("\n");
    }
}    