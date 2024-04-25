#include<vector>
#include<string>
#include<unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        visited.insert(deadends.begin(), deadends.end());

        queue<string> q;
        q.push("0000"s);
        visited.insert("0000"s);
        int spins = 0;
        while(!q.empty())
        {
            for(size_t s = q.size();s>0;s--)
            {
                string lock = q.front();
                if(lock==target)
                {
                    return spins;
                }
                for(size_t i=0;i<lock.size();i++)
                {
                    if(lock[i]=='9')
                    {
                        lock[i]='0';
                    }
                    else
                    {
                        lock[i]+=1;
                    }
                    if(!visited.contains(lock))
                    {
                        q.push(lock);
                        visited.insert(lock);
                    }

                    if(lock[i]=='0')
                    {
                        lock[i]='8';
                    }
                    else if(lock[i]=='1')
                    {
                        lock[i]='9';
                    }
                    else 
                    {
                        lock[i]-=2;
                    }
                    if(!visited.contains(lock))
                    {
                        q.push(lock);
                        visited.insert(lock);
                    }
                }
            }
            spins+=1;
        }

        return -1;
    }
};