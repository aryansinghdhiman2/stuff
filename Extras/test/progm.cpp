#include <iostream>

using namespace std;

int main()
{
    int n, i, largest, smallest;

    cout<<"enter size of array"<<endl;
    cin>>n;

    int arr[n];

    cout<<"enter elements of array";

    for (i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    //Comparing the value of largest with every element of the array and if an element is bigger than largest assigning its value to largest
    largest= arr[0];
    for(i=0 ; i<n ; i++)
    {
        if (largest<arr[i])
        {
            largest=arr[i];
        }
    }

    //Comparing the value of smallest with every element of the array and if an element is smaller than smallest assigning its value to smallest
    smallest=arr[0];
    for(i=0 ; i<n ; i++)
    {
        if (smallest>arr[i])
        {
            smallest=arr[i];
        }
    }

    cout<<"largest number="<<largest<<endl;
    cout<<"smallest number="<<smallest<<endl;
    return 0;
}
