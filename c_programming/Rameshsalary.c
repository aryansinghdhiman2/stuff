#include <stdio.h>

int main()
{
    float salary,dearness,houseRent,grossSalary;
    
    printf("Enter Ramesh's salary\n");
    scanf("%f", &salary);
    
    dearness= (40)*salary/100;
    houseRent= (20)*salary/100;
    
    grossSalary = dearness + houseRent + salary;
    printf("Ramesh's salary is %.2f\n", grossSalary);
    return 0;
}