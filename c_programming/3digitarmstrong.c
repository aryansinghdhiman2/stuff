#include <stdio.h>

int main()
{
    int num,i,sum=0;
    int a,digit1,digit2,digit3;
    printf("Please enter the number you want checked\n");
    scanf("%d",&num);
    i=num;
	
    a=num/10;
    digit1=num%10;
    num=a;
    
    a=num/10;
    digit2=num%10;
    num=a;
    
    a=num/10;
    digit3=num%10;
	
    num=i;
    sum=(digit1*digit1*digit1)+(digit2*digit2*digit2)+(digit3*digit3*digit3);
    if(sum==num)
    printf("%d is an Armstrong Number\n",sum);
    else
    printf("%d is not an Armstrong Number\n",num);
    return 0;
}
