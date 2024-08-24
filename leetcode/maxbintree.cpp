#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//   map<int, TreeNode*> q;
//   for (int num : nums) {
//     auto it = q.insert({ num, new TreeNode(num) }).first;
//     if (it != q.begin()) {
//       it->second->left = next(it, -1)->second;
//       q.erase(q.begin(), it);
//     }
//     if (next(it, 1) != q.end()) 
//         next(it, 1)->second->right = it->second;
//   }
//   return q.rbegin()->second;
// }

// TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//     vector<TreeNode*> s { new TreeNode(nums[0]) };
//     for (int i = 1; i < nums.size(); ++i) {
//         TreeNode* cur = new TreeNode(nums[i]);
//         auto it = upper_bound(s.rbegin(), s.rend(), cur,
//             [](const TreeNode* a, const TreeNode* b) { return a->val < b->val; });
//         if (it != s.rend()) 
//             (*it)->right = cur;
//         if (it != s.rbegin()) 
//             cur->left = *next(it, -1);
//         auto dist = distance(it,s.rend());
//         s.resize(dist);
//         s.push_back(cur);
//     }
//     return s.front();
// }

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    vector<TreeNode*> v(1,new TreeNode(nums.at(0)));
    for(size_t i=1; i<nums.size();i++)
    {
        TreeNode* cur = new TreeNode(nums[i]);
        auto itr = upper_bound(v.rbegin(),v.rend(),cur,
            [](const TreeNode* a,const TreeNode* b){ return a->val < b->val;});
        if(itr!=v.rend())
        {
            (*itr)->right = cur;
        }
        if(itr!=v.rbegin())
        {
            cur->left = (*next(itr,-1));
        }

        v.resize(distance(itr,v.rend()));
        v.push_back(cur);
    }

    return *(v.begin());
}

int main()
{
    vector<int> n = {3,2,1,6,0,5};
    auto t = constructMaximumBinaryTree(n);

    return 0;
}