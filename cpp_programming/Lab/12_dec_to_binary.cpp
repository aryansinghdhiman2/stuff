#include <iostream>

using namespace std;

long int dec_to_bin(int num);

int main()
{
    int num;
    cout<<"Enter Decimal Number which you want converted to binary: ";
    cin>>num;
    cout<<"Binary form is : "<<dec_to_bin(num);
    return 0;
}

long int dec_to_bin(int num)
{
    if(num==0)
        return 0;
    else if(num==1)
        return 1;
    else
        return (num%2)+10*dec_to_bin(num/2);//finds remainder and then adds 10 times remainder of half of input
}
