#include <stdio.h>

int main()
{
    int a,b,temp;
    
    printf("Please enter A\n");
    scanf("%d", &a);
    printf("Please enter B\n");
    scanf("%d", &b);
    
    temp=b;
    b=a;
    a=temp;
    
    printf("The value of A is %d\n", a);
    printf("The value of B is %d\n", b);
    return 0;
}