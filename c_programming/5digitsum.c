#include <stdio.h>

int main()
{
    int number,digit1,digit2,digit3,digit4,digit5;
    int a;
    printf("Please enter the number\n");
    scanf("%d", &number);
    
    a=number/10;
    digit1=number%10;
    number=a;
    
    a=number/10;
    digit2=number%10;
    number=a;
    
    a=number/10;
    digit3=number%10;
    number=a;
    
    a=number/10;
    digit4=number%10;
    number=a;
    
    a=number/10;
    digit5=number%10;
    
    printf("The new number is %d%d%d%d%d", digit1,digit2,digit3,digit4,digit5);
    return 0;
}