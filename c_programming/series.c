
#include <stdio.h>
#include <math.h>
int main()
{
    int x,i,j,fac=1,k;
    float result=0.0;
    printf("Please enter the value of x: ");
    scanf("%d",&x);
    printf("Please input the number of terms: ");
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        for(fac=1,k=1;k<=i;k++)
        {
            fac*=k;
        }
        result=(float)result+pow(x,i)/fac;
    }
    printf("Result is %f",result);

    return 0;
}
