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
    vector<int> duplicate_arr,count_arr;
    int prev_dupli=arr.at(0);
    int count=1;
    bool check;
    for(auto itr=arr.begin()+1;itr!=arr.end();itr++)
    {
        if(*itr==prev_dupli && itr!=(arr.begin()+1))
        {
            count++;
        }
        else if(*itr==prev_val)
        {
            duplicate_arr.push_back(*itr);
            prev_dupli=*itr;
            if(itr!=(arr.begin()+1)){
                count_arr.push_back(count+1);
                count=1;
            }
        }
        prev_val=*itr;
        if(itr==(arr.end()-1))
        {
            count_arr.push_back(count+1);
        }
    }
    cout<<"Duplicated elements are: \n";
    for(auto itr=duplicate_arr.begin(),count_itr=count_arr.begin();itr!=duplicate_arr.end();itr++,count_itr++)
    {
        cout<<*itr<<' '<<*count_itr<<'\n';
    }
}
