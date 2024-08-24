#include <stdio.h>

int main()
{
    int a,b,fac=1,sum=0,i;
    printf("Enter a number:\n");
    scanf("%d",&a);
    int x=a;
    while(x>0)
    {
        b=x%10;
        for(i=b;i>0;i--)
            fac=fac*i;
        sum+=fac;
        fac=1;
        x/=10;
    }
    if(sum==a)
        printf("%d is a Strong number.",sum);
    else
        printf("%d is not a Strong number.",a);
    return 0;
}