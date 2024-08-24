#include <stdio.h>

int main()
{
    float x,y,A,B;
    printf("Please enter the value of x and y\n");
    scanf("%f%f",&x,&y);
    A=(x+y)/(x-y);
    B=(x+y)*(x-y);
    printf("The value of A is %.2f and B is %.2f",A,B);
    return 0;
}