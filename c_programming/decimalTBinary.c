#include <stdio.h>
//decimal to binary
long long decimalToBinary(int);
int main()
{
    int n;
    long long int x;
    printf("Enter a decimal number:");
    scanf("%d",&n);
    x = decimalToBinary(n);
    printf("Binary Number is: %lld",x);
    return 0;
}
long long decimalToBinary(int n){
    long long binary = 0,i = 1,rem;
    while(n){
        rem = n%2;
        n = n/2;
        binary = binary + rem*i;
        i=i*10;
        
    }
    return(binary);
}