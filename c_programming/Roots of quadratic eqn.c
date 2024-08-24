#include <stdio.h>

int main() {
    float a, b, c, r1, r2;
    printf("Enter a,b,c\n");
    scanf("%f %f %f", &a, &b, &c);
    r1= (-b+sqrt(b*b-4*a*c))/(2*a);
    r2= (-b-sqrt(b*b-4*a*c))/(2*a);
    printf("r1 is %.2f\n", r1);
    printf("r2 is %.2f\n", r2 );
    return 0;
}