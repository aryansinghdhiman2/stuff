#include <iostream>
#include <array>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int l=0;l<n-1;l++)//bubble sort
    {
        if(arr[l]>arr[l+1])
        {
        int temp=arr[l];
        arr[l]=arr[l+1];
        arr[l+1]=temp;
        l=-1;
        }
    }

    cout<<"\nLargest number is: "<<arr[n-1]<<" ,Smallest Number is: "<<arr[0]<<endl;
    return 0;
}
