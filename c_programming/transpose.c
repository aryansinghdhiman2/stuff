#include <stdio.h>

int main() 
{
  int input[2][2], transpose[2][2],i,j;
  
  printf("Enter matrix elements:\n");
  for (i=0;i<2;i++)
    for (j=0;j<2;j++)
    {
        scanf("%d", &input[i][j]);
    }
    
  for (i=0;i<2;i++)
    for (j=0;j<2;j++)
    {
        transpose[j][i]=input[i][j];
    }
    
  printf("\nTranspose of the matrix:\n");
  for (i=0;i<2;i++)
  {
    for (j=0;j<2;j++) 
    {
        printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }
  return 0;
}