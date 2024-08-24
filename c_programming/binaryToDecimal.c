#include <stdio.h>
#include <math.h>
//binary to decimal
int binaryToDecimal(long long);
int main()
{
    long long b;
    int d;
    printf("Enter a binary number:");
    scanf("%lld",&b);
    d=binaryToDecimal(b);
    printf("Decimal Number is: %d",d);
    return 0;
}
int binaryToDecimal(long long bin){
    int dec=0,r,x=0;
    while (bin)
        {
            r = bin%10;
            bin = bin/10;
            dec = dec+r*pow(2,x);
            x++;
        }
    return(dec);
}