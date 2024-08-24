#include <stdio.h>

int main()
{
    int a,b,c,product;
    
    printf("Enter your number\n");
    scanf("%d", &a);
	
    for(b=a,product=a;b!=1;a--)
    {
        b=a-1;
        product=product*b;
    }
  printf("%d", product);

    return 0;
}
