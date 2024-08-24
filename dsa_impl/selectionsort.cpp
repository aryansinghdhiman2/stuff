#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr)
{
    size_t min_index = 0;
    for(size_t i=0;i<arr.size();i++)
    {
        min_index = i;
        for(size_t j = i + 1;j<arr.size();j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
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
    selectionSort(arr);
    print(arr);
}