#include <iostream>

using namespace std;
//swapping
int main()
{
    cout<<"Enter two numbers\n";
    int a=0,b=0;
    
    cin>>a>>b;
    
    a=a+b;
    b=a-b;
    a=a-b;
    
    cout<<"The numbers after swapping are: "<<a<<" and "<<b;

    return 0;
}