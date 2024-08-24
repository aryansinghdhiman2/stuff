#include <iostream>

using namespace std;
//find prime till n
int main()
{
    int n{0};
    cout<<"Enter upper limit: ";
    cin>>n;
    cout<<"2 ";
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
                break;
            else if(j==i-1)
                cout<<i<<" ";
        }
    }

    return 0;
}