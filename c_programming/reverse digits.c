#include <stdio.h>

int main()
{
    int a,b,c;
    
    printf("Enter your number\n");
    scanf("%d", &a);
    
    for(b=0;a!=b,a!=0;)
    {
        b=a%10;
        c=a/10;
        a=c;
        printf("%d",b);
    }
  

    return 0;
}
