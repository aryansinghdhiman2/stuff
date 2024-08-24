#include <iostream>

using namespace std;

int rec_fac(const int num);

int main()
{
    cout << "Enter Number for which you want Factorial: ";

    int num;
    cin>>num;

    cout<<"Factorial of "<<num<<" is: "<<rec_fac(num);
    return 0;
}

int rec_fac(const int num)
{
    if(num==1)
        return num;
    else
        return num*rec_fac(num-1);//multiplies num by integers less than it till it reaches 1
}
