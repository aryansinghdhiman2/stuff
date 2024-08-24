#include <stdio.h>

int main() {
    int a, b, c, sum=0;
    printf("Enter the number\n");
    scanf("%d", &a);
    
    for(b=0;a!=b;sum=sum+b)
    {
        b=a%10;
        c=a/10;
        a=c;
    }
    printf("Sum of the digits is %d", sum);

    return 0;
}