#include <stdio.h>
#include <stdlib.h>

int main()
{
    float const pi=3.14159;
    float area,perimeter,width,height,radius;

    printf("Enter width of rectangle\n");
    scanf("%f", &width);
    printf("Enter height of rectangle\n");
    scanf("%f", &height);
    printf("Enter radius of circle\n");
    scanf("%f",&radius);

    area= width*height;
    perimeter= 2*(width+height);

    printf("Area of rectangle is %.2f\n", area);
    printf("Perimeter of rectangle is %.2f\n\n", perimeter);
    
    area=pi*radius*radius;
    perimeter=2*pi*radius;
    
    printf("Area of circle is %.2f\n", area);
    printf("Perimeter of circle is %.2f\n", perimeter);
    return 0;
}
