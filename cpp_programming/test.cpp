/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

    int getNearest(int middle,vector<int>& cuts){
        vector<int> distance=cuts;
        for(int i=0;i<int(distance.size());i++){
            distance[i]=abs(distance[i]-middle);
        }
        auto mini=min_element(distance.begin(),distance.end());
        return mini-distance.begin();
    }
    int helper(vector<int>& cuts,int left,int right){
        if(cuts.size()==0){
            return 0;
        }
        else if(cuts.size()==1){
            return right-left;
        }
        else{
            int mid=int((right-left)/2+left);
            int near=getNearest(mid,cuts);
            int nextCut=cuts.at(near);
            // cuts.erase(distance.begin()+near);
            vector<int> cuts1(cuts.begin(),cuts.begin()+near);
            vector<int> cuts2(cuts.begin()+near+1,cuts.end());
            
            int cost1=helper(cuts1,left,nextCut);
            int cost2=helper(cuts2,nextCut,right);
            return cost1+cost2+(right-left);
        }
    }
    int anotherhelper(vector<int>& cuts,int left,int right){
        if(cuts.size()==0){
            return 0;
        }
        else if(cuts.size()==1){
            return right-left;
        }
        else{
            int mid=int((right-left)/2+left)+1;
            int near=getNearest(mid,cuts);
            int nextCut=cuts.at(near);
            // cuts.erase(distance.begin()+near);
            vector<int> cuts1(cuts.begin(),cuts.begin()+near);
            vector<int> cuts2(cuts.begin()+near+1,cuts.end());
            
            int cost1=anotherhelper(cuts1,left,nextCut);
            int cost2=anotherhelper(cuts2,nextCut,right);
            return cost1+cost2+(right-left);
        }
    }
    int minCost(int n,vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        return min(helper(cuts,0,n),anotherhelper(cuts,0,n));
    }
    
    int main(){
        // vector<int> v={3,1,4};
        
        // cout<<minCost(5,v);
        vector<int> v= {1,14,18,6,17,8,10,4,13,16,7};
        cout<<minCost(20,v);
    }