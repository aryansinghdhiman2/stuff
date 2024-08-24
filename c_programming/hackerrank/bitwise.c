#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int i=1,j=2,m,and=0;
  int or=0,xor=0,count=0,count2=0,count3=0;
  for(;i<=n;i++)
  {
      for(;j<=n;j++)
      {
          m=(i&j);
          if(m<k)
          {
              if(count==0)
              {
                  and=m;
                  count++;
              }
              else if(count==1)
              {
                  if(m>and)
                  {
                  and=m;
                  }
              }
              
          }
          m=(i|j);
          if(m<k)
          {
               if(count2==0)
              {
                  or=m;
                  count2++;
              }
              else if(count2==1)
              {
                  if(m>or)
                  {
                  or=m;
                  }
              }
          }
          m=(i^j);
          if(m<k)
          {
               if(count3==0)
              {
                  xor=m;
                  count3++;
              }
              else if(count3==1)
              {
                  if(m>xor)
                  {
                  xor=m;
                  }
              }
          }
      }
      j=i+2;
  }
  printf("%d\n",and);
  printf("%d\n",or);
  printf("%d",xor);
  
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
