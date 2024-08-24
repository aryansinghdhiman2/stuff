#include <stdio.h>

int main()
{
    int a,num,digit1,digit2,digit3,digit4,digit5,sum,i;
    printf("Please enter the number you want checked\n");
    scanf("%d",&num);
    i=num;
	
	a=num/10;
    digit5=num%10;
    num=a;
	
	a=num/10;
    digit4=num%10;
    num=a;
	
    a=num/10;
    digit3=num%10;
    num=a;
    
    a=num/10;
    digit2=num%10;
    num=a;
    
    a=num/10;
    digit1=num%10;
    num=a;
    num=i;
    
    sum=digit5*(10000)+digit4*(1000)+digit3*(100)+digit2*(10)+digit1;
    if(sum==num)
    printf("%d is a Palindrome number\n",num);
    else
    printf("%d is not a Palindrome number\n",num);
    
    return 0;
}
