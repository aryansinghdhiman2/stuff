#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;


int get_max(const vector<int>& a)
{
    auto it = max_element(a.begin(),a.end());
    return *it;
}

int no_of_digits(int a)
{
    int count=0;
    while(a > 0)
    {
        a = a/10;
        count++;
    }
    return count;
}

void radix_sort(vector<int> &input)
{
    int max = get_max(input);
    int no_of_passes = no_of_digits(max);
    const size_t bins_size = 10;
    array<queue<int>,bins_size> bins;

    for(int j=0;j<no_of_passes;j++)
    {
        for(auto it = bins.begin();it!=bins.end();it++)
        {
            if(!(it->empty()))
            {
                while(!it->empty())
                {
                    it->pop();
                }
            }
        }

        for(auto it = input.begin();it!=input.end();it++)
        {
            int index = (*it)/(int(pow(10,j))) % 10;
            bins.at(index).push(*it);
        }

        auto bin_itr = bins.begin();
        auto input_itr = input.begin();

        while(bin_itr != bins.end())
        {
            if(!(bin_itr->empty()))
            {
                int element = bin_itr->front();
                bin_itr->pop();
                *input_itr = element;
                input_itr ++;
            }
            else
                bin_itr++;
        }
    }
    
}

void display(const vector<int> &input)
{
    auto print = [](const int& n) { std::cout << " " << n; };
    for_each(input.begin(),input.end(),print);
}

int main()
{
    vector<int> v={32,54,63,12,45,9,10};
    display(v);
    cout<<'\n';
    radix_sort(v);
    display(v);
    cout<<endl;
}