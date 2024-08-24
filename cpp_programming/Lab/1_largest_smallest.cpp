#include <iostream>
#include <array>
using namespace std;
//largest,second largest,smallest
int main()
{
    array<int,3> arr;
    cout<<"Enter three numbers: ";
    
    for(int i=0;i<3;i++)
    {
        cin>>arr.at(i);
    }
    
    if(arr.at(0)>arr.at(1))
    {
        if(arr.at(0)>arr.at(2))
        {
            cout<<"Largest Number is : "<<arr.at(0)<<endl;
            if(arr.at(1)>arr.at(2))
            {
                cout<<"Second Largest Number is : "<<arr.at(1)<<endl;
                cout<<"Smallest Number is : "<<arr.at(2)<<endl;
            }
            else
            {
                cout<<"Second Largest Number is : "<<arr.at(2)<<endl;
                cout<<"Smallest Number is : "<<arr.at(1)<<endl;
            }
        }
        else
        {
            cout<<"Largest Number is : "<<arr.at(2)<<endl;
            cout<<"Second Largest Number is : "<<arr.at(0)<<endl;
            cout<<"Smallest Number is : "<<arr.at(1)<<endl;
        }
    }
    else
    {
        if(arr.at(1)>arr.at(2))
        {
            cout<<"Largest Number is : "<<arr.at(1)<<endl;
            if(arr.at(0)>arr.at(2))
            {
                cout<<"Second Largest Number is : "<<arr.at(0)<<endl;
                cout<<"Smallest Number is : "<<arr.at(2)<<endl;
            }
        }
        else
        {
            cout<<"Largest Number is : "<<arr.at(2)<<endl;
            cout<<"Second Largest Number is : "<<arr.at(1)<<endl;
            cout<<"Smallest Number is : "<<arr.at(0)<<endl;
        }
    }
    
    return 0;
}