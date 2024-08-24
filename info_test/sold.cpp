#include <iostream>
#include <cmath>

using namespace std;

int reduce(const int n)
{
    int soldiers = n;
    int steps = 0;
    while(soldiers > 1)
    {
        if( soldiers % 3 == 0)
        {
            soldiers = soldiers / 3;
        }
        else if(soldiers % 2 == 0)
        {
            soldiers = trunc(soldiers / 2);
        }
        else
        {
            soldiers--;
        }
        steps++;
        cout<<soldiers<<endl;
    }
    return steps;
}

int main()
{
    int n;
    cin>>n;
    cout<<reduce(n);
}