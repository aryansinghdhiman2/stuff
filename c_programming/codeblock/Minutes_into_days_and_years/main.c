#include <stdio.h>
#include <stdlib.h>

int main()
{
    double minutes;
    double years,days;

    printf("Enter the number of minutes\n");
    scanf("%lf", &minutes);

    days= ((minutes/60))/24;
    years= (int) days/365;
    days= (int) days%365;

    printf("Their are %lf years and %lf days in %lf minutes ", years, days,minutes);


    return 0;
}
