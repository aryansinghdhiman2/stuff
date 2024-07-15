#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr,int i,int heapSize)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if(left < heapSize && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < heapSize && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,largest,heapSize);
    }
}

void buildHeap(vector<int>& arr)
{
    for(int i = int(arr.size())/2 - 1;i>=0;i--)
    {
        heapify(arr,i,arr.size());
    }
}

void heapsort(vector<int>& arr)
{
    buildHeap(arr);

    int heapSize = arr.size();

    for(int i = int(arr.size())-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapSize--;
        heapify(arr,0,heapSize);
    }
}

int main()
{
    vector<int> arr = {1,8,4,2,6,9,10};
    for(const int num : arr)
    {
        cout<<num<<' ';
    }
    cout<<'\n';

    heapsort(arr);

    for(const int num : arr)
    {
        cout<<num<<' ';
    }
    cout<<'\n';
}