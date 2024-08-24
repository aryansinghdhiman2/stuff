#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr,const int start,const int end)
{
    int pivot = arr[start];
    int i = start + 1;

    for(int j=start+1;j<=end;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }

    swap(arr[i-1],arr[start]);
    return i-1;
}

void quickSort(vector<int>& arr,const int start,const int end)
{
    if(start < end)
    {
        const int pivot = partition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
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
    quickSort(arr,0,arr.size()-1);
    print(arr);
}