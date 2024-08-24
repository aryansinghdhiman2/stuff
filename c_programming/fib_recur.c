#include <stdio.h>
int factorialOfNum(int);
int main()
{
    int fac;
    printf("Enter number you want factorial of :");
    scanf("%d",&fac);
    printf("Factorial of the inputted number is: %d",factorialOfNum(fac));

    return 0;
}
int factorialOfNum(int a)
{
    if(a>1)
    {
        return a*factorialOfNum(a-1);
    }
    else
    return 1;
}
