#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr,int start,int middle,int end)
{
    int p = start;
    int q = middle + 1;

    vector<int> dummy(end - start + 1);

    for(int k = 0;k<dummy.size();k++)
    {
        if(p > middle)
        {
            dummy[k] = arr[q];
            q++;
        }
        else if(q > end)
        {
            dummy[k] = arr[p];
            p++;
        }
        else if(arr[p] < arr[q])
        {
            dummy[k] = arr[p];
            p++;
        }
        else
        {
            dummy[k] = arr[q];
            q++;
        }
    }

    for(int i = start,k = 0;i<=end;i++,k++)
    {
        arr[i]=dummy[k];
    }
}

void mergeSort(vector<int>& arr,const int start,const int end)
{
    if(start < end)
    {
        const int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
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
    mergeSort(arr,0,arr.size()-1);
    print(arr);
}