#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr)
{
    for(size_t i=1;i<arr.size();i++)
    {
        int current_idx = i;
        while(current_idx > 0 && arr[current_idx - 1] > arr[current_idx])
        {
            swap(arr[current_idx],arr[current_idx-1]);
            current_idx--;
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
    insertionSort(arr);
    print(arr);
}