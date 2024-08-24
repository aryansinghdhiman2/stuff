#include <stdio.h>
#include <stdlib.h>


float absoluteValue(float x);
float squareRoot(float t);

int main()
{
    printf("%f\n", squareRoot(-16));
    printf("%f\n", squareRoot(16));
    printf("%f\n", squareRoot(25));
    printf("%f\n", squareRoot(8));
    return 0;
}

float absoluteValue(float x)
{
    if(x<0){
        x=-x;
    }
    return x;
}

float squareRoot(float x)
{
    const float epsilon=0.00001;
    float guess=1.0;
    if(x<1){
        printf("Negative argument to square root:  ");
        return -1;
    }
     else
    {
        while  ( absoluteValue (guess * guess - x) >= epsilon )
           guess = ( x / guess + guess ) / 2.0;

        return guess;
    }

}
