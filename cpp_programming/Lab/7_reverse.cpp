#include <iostream>
#include <cmath>
using namespace std;
//reverse
int main()
{
    cout<<"Enter the number to be reversed\n";
    int num;
    cin>>num;
    int temp=num;
    int rev{0};
    
    int len=0;
    for(int k=0;temp!=0;k++)
    {
        temp=temp/10;
        len++;
    }
    temp=num;
    for(int i=0;temp!=0;i++)
    {
        rev=rev+(temp%10)*pow(10,len-i-1);
        temp=temp/10;
    }
    
    cout<<rev;

    return 0;
}