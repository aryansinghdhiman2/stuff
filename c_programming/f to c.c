#include <stdio.h>

int main()
{
    float fahrenheit,celsius;
    
    printf("Please enter the temperature in fahrenheit\n");
    scanf("%f", &fahrenheit);
    
    celsius=(fahrenheit-32)*5/9;
    
    printf("The temperature in Celsius is %f", celsius);
    return 0;
}