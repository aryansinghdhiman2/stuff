#include <iostream>
//sum of first and last digit
using namespace std;

int main()
{
    cout<<"Enter Number\n";
    
    int number{0};
    
    cin>>number;
    int temp{0},sum{0};
    
    sum=number%10;
    
    for(;;)
    {
        temp=number%10;
        number=number/10;
        if(!number)
        {
            break;
        }
    }
    sum=temp+sum;
    cout<<"Sum of first and last digit is: ";
    cout<<sum<<endl;

    return 0;
}