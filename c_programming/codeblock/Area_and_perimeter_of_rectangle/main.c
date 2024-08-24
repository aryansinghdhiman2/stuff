#include <stdio.h>
#include <stdlib.h>

int main()
{
    double area,perimeter,width,height;

    printf("Enter width\n");
    scanf("%lf", &width);
    printf("Enter height\n");
    scanf("%lf", &height);

    area= width*height;
    perimeter= 2*(width+height);

    printf("Area is %lf\n", area);
    printf("Perimeter is %lf\n", perimeter);
    return 0;
}
