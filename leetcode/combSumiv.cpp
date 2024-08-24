#include <vector>

using namespace std;

class Solution {
    inline int fac(const int num)
    {
        int result = 1;
        for(int i=2;i<=num;i++)
        {
            result = result * i;
        }
        return result;
    }
    bool allEqual(const vector<int>& v)
    {
        int num = v[0];
        for(size_t i=1;i<v.size();i++)
        {
            if(num != v[i]) return false;
        }
        return true;
    }
    int helper(vector<int> comb,const int remaining,const vector<int>& nums,const int cursor)
    {
        if(remaining==0)
        {
            if(allEqual(comb))
            {
                return 1;
            }
            else 
            {
                return fac(comb.size());
            }
        }
        if(remaining<0)
        {
            return 0;
        }

        int number_of_combinations=0;
        for(int i=cursor;i<nums.size();i++)
        {
            comb.push_back(nums[i]);
            number_of_combinations+=helper(comb,remaining-nums[i],nums,cursor);
            comb.pop_back();
        }
        return number_of_combinations;
    }
public:
    int combinationSum4(vector<int> nums, int target) {
        vector<int> comb;
        return helper(comb,target,nums,0);
    }
};

int main()
{
    Solution s;
    s.combinationSum4({1,2,3},4);
}