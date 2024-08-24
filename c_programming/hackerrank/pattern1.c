#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
      // Complete the code to print the pattern.
      _Bool newLine=0;
      int numberOfRows=(2*n-1);
      int i,j,count,temp=1,t;
      for(i=0;i<numberOfRows;i++)
      {
          newLine=0;
          for(j=n,count=0,temp=1;count<numberOfRows && i<n;count++)
          {
              if(count==n)
              {
                  temp=-temp;
              }
              if(count<i)
              {
                  printf("%d ",j);
                  j=j-temp;
              }
              else if(count>=(numberOfRows-i))
              {
                  j=j-temp;
                  printf("%d ",j);
              }
              else {
              printf("%d ",j);
              }
              newLine=1;
              
          }
          for(j=n,temp=1;count<numberOfRows && i>=n;count++)
          {
              t=numberOfRows-i-1;
              newLine=0;
              if(count==n)
              {
                  temp=-temp;
              }
              if(count<t)
              {
                  printf("%d ",j);
                  j=j-temp;
              }
              else if(count>=(numberOfRows-t))
              {
                  j=j-temp;
                  printf("%d ",j);
              }
              else {
              printf("%d ",j);
              }
           newLine=1;   
          }
          if(newLine)
          {
            printf("\n");
          }
      }
      
    return 0;
}
