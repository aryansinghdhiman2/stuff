#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    // n-1 passes
    for(int k = 0;k<n-1;k++)
    {
        for(int i=0;i<n-1-k;i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
        }
    }
}

void print(const vector<int>& arr)
{
    for(const int num : arr)
    {
        cout<<num<<' ';
    }
    cout<<'\n'; 
}

int main()
{
    vector<int> arr = {4,5,3,7,6,1,3,1,5};
    print(arr);
    bubbleSort(arr);
    print(arr);
}