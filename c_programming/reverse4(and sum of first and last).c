#include <stdio.h>

int main()
{
    int number,digit1,digit2,digit3,digit4;
    int a,sumOfFirstAndLastDigits;
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
    
    sumOfFirstAndLastDigits=digit4+digit1;
    printf("The new number is %d%d%d%d", digit1,digit2,digit3,digit4);
    printf("\nSum of first and last digit is: %d",sumOfFirstAndLastDigits);
    return 0;
}