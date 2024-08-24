#include <stdio.h>

int sum_of_digits(int);
int main()
{
    int num,result;
    printf("Please enter number\n");
    scanf("%d",&num);
    result=sum_of_digits(num);
    printf("The sum of digits are %d",result);

    return 0;
}
int sum_of_digits(int a)
{
    int sum=0,temp;
    for(;a!=0;)
    {
        temp=a%10;
        sum=sum+temp;
        a=a/10;
    }
    return sum;
} 
