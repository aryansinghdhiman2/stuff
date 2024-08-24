#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Size of int is %zd\n", sizeof(int));
    printf("Size of char is %zd\n", sizeof(char));
    printf("Size of long is %zd\n", sizeof(long));
    printf("Size of long long is %zd\n", sizeof(long long));
    printf("Size of double is %zd\n", sizeof(double));
    printf("Size of long double is %zd\n", sizeof(long double));
    printf("Size of float is %zd\n", sizeof(float));
    printf("Size of short is %zd\n", sizeof(short));
    return 0;
}
