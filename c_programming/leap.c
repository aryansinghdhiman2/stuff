#include <stdio.h>

void leap_year_checker(int);
int main()
{
    int year;
    printf("Enter year you want checked\n");
    scanf("%d",&year);
    leap_year_checker(year);

    return 0;
}
void leap_year_checker(int a)
{
    if(((a%4==0)&&(a%100!=0))||(a%400==0))
        printf("%d is a leap year\n",a);
    else
        printf("%d is not a leap year\n",a);
    
}
 
