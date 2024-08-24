#include <stdio.h>

int main()
{
    int a=0,b=1,c,i;
    printf("Please enter the number upto which you want the Fibonacci Sequence to be printed out\n");
    scanf("%d",&i);
    printf("%d %d ",a,b);
    for(;;)
    {
        c=a+b;
        if(c>i)
        {
            break;
        }
        printf("%d ",c);
        a=b;
        b=c;
    }
    return 0;
}
