#include <iostream>
#include "test.h"

int main()
{
    int i,j,k;
    std::cout<<"Enter 3 numbers: ";
    std::cin>>i>>j>>k;
    int sum = add(i,j,k);
    std::cout<<"Sum of numbers is: "<<sum;
    int mult = MULTIPLY(i,j,k);
    std::cout<<"Multiplication of numbers is : "<<mult;
}