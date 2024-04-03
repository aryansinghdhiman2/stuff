#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for_each(nums.begin(),nums.end(),[](int& n){n = abs(n);});
    vector<int> result(nums.size(),0);

    int left = 0;
    int right = nums.size()-1;
    int i = right;

    int leftsqr = 0;
    int rightsqr = 0;
    while(left <= right)
    {
        leftsqr = int(pow(nums[left],2));
        rightsqr = int(pow(nums[right],2));

        if(leftsqr > rightsqr)
        {
            result[i] = leftsqr;
            ++left;
        }
        else
        {
            result[i] = rightsqr;
            --right;
        }
        --i;
    }
    return result;
}

int main()
{
    vector<int> v = {-4,-1,0,3,10};
    sortedSquares(v);
    std::cout<<"Hello World";

    return 0;
}