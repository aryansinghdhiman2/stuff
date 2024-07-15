#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    bool helper(const size_t curr,const vector<int>& nums)
    {
        static unordered_map<size_t,bool> mp;
        
        if(curr == (nums.size()-1))
        {
            return true;
        }

        if(curr >= nums.size())
        {
            return false;
        }

        if(mp.count(curr)!=0)
        {
            return mp[curr];
        }

        bool canReach = false;
        for(int i=nums[curr];i>=1;i--)
        {
            canReach |= helper(curr+i,nums);
        }

        mp[curr]=canReach;
        return canReach;
    }
public:
    bool canJump(vector<int> nums) {
        bool val =  helper(0,nums);
        return val;
    }
};

int main()
{
    cout<<Solution().canJump({3,2,1,0,4});
}