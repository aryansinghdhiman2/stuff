#include <stdio.h>

int main()
{
    int matrix[3][3]={0};
    int i,j,x;
    printf("Enter number of rows and columns:" );
    scanf("%d",&x);
    printf("Enter matrix\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    _Bool isIdentity=0;
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(matrix[i][j]==1 && i==j)
                isIdentity=1;
            else if(matrix[i][j]==0 && i!=j)
                isIdentity=1;
            else 
            {
                isIdentity=0;
                break;
            }
        }
        if(!isIdentity)
            break;
    }
    if(isIdentity)
        printf("Inputted matrix  is Identity\n");
    else
        printf("Inputted matrix  is not Identity\n");

    return 0;
}
