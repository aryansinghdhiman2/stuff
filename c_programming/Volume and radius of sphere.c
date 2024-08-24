#include <stdio.h>

int main() {
    float radius, volume, area;
    const float pi=3.14;
    
    printf("Enter Radius\n");
    scanf("%f", &radius);
    
    volume= 4*pi*radius*radius*radius/3;
    area= 4*pi*radius*radius;
    
    printf("Area is %.2f\n", area);
    printf("Volume is %.2f\n", volume);
    return 0;
}