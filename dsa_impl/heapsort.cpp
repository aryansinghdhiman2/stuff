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

inline int parent(int i)
{
    if((i % 2)==0)
    {
        return (i / 2) - 1;
    }
    else return (i / 2);
}

void push(vector<int>& arr,int val)
{
    arr.push_back(val);
    int i = arr.size() - 1;
    while(parent(i)>=0 && arr[parent(i)] < arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i = parent(i);
    }
}

void pop(vector<int>& arr)
{
    swap(arr.front(),arr.back());
    arr.pop_back();
    heapify(arr,0,arr.size());
}

inline int top(const vector<int>& arr)
{
    return arr.front();
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
    vector<int> arr = {5,2,3,1};
    print(arr);

    heapsort(arr);

    print(arr);

    buildHeap(arr);
    print(arr);

    push(arr,25);
    print(arr);

    cout<<top(arr)<<'\n';

    pop(arr);
    print(arr);

    vector<int> another;
    for(const int num : arr)
    {
        push(another,num);
    }
    print(another);

}