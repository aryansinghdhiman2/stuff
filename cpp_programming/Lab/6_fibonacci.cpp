#include <iostream>

using namespace std;
//fibonacci
int main()
{
    int a=0,b=1,c,i;
    cout<<"Please enter the number upto which you want the Fibonacci Sequence to be printed out\n";
    cin>>i;
    cout<<a<<" "<<b<<" ";
    for(;;)
    {
        c=a+b;
        if(c>i)
        {
            break;
        }
        cout<<c<<" ";
        a=b;
        b=c;
    }

    return 0;
}