
#include <stdio.h>

int main() {
    int a, b, sum, difference, product;
    float quotient;
    
    printf("Enter first number\n");
    scanf("%d", &a);
    printf("Enter second number\n");
    scanf("%d", &b);
    
    sum= a+b;
    difference= a-b;
    product= a*b;
    quotient= (float) a/b;
    printf("Sum is %d\n", sum);
    printf("Difference is %d\n", difference);
    printf("Product is %d\n", product);
    printf("Quotient is %.2f\n", quotient);
    return 0;
}