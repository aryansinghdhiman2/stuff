#include <stdio.h>
int main() {
    int a, b, c;
    printf("Enter the first number\n");
    scanf("%d", &a);
    printf("Enter the second number\n");
    scanf("%d", &b);
    printf("Enter the third number\n");
    scanf("%d", &c);
    if(a>c && a>b)
    {
     printf("First number is largest\n");   
    }
    else if(b>c && b>a)
    {
     printf("Second number is largest\n");   
    }
    else if(c>a && c>b)
    {
     printf("Third number is largest\n");   
    }
    return 0;
}
