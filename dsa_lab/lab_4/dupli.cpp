#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cout<<"Enter Size of Array: ";
    int size;
    cin>>size;
    vector<int> arr;
    arr.reserve(size);
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++)
    {
        int input;
        cin>>input;
        arr.push_back(input);
    }
    sort(arr.begin(),arr.end());

    int prev_val=arr.at(0);
    vector<int> duplicate_arr;
    int prev_dupli=-1;
    for(auto itr=arr.begin()+1;itr!=arr.end();itr++)
    {
        if(*itr==prev_dupli)
        {
            //do nothing
        }
        else if(*itr==prev_val)
        {
            duplicate_arr.push_back(*itr);
            prev_dupli=*itr;
        }
        prev_val=*itr;
    }
    cout<<"Duplicated elements are: ";
    for(auto itr=duplicate_arr.begin();itr!=duplicate_arr.end();itr++)
    {
        cout<<*itr<<' ';
    }
}
