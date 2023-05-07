#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int sstf(vector<int> diskQueue,int seekHeadPos){
    int totalDistance=0;
    auto closestToHead=[seekHeadPos](int a,int b){
        if(abs(seekHeadPos-a)<abs(seekHeadPos-b)){
            return true;
        }
        else return false;
    };
    while(not diskQueue.empty()){
        auto request = min_element(diskQueue.begin(),diskQueue.end(),closestToHead);
        totalDistance+=abs((*request)-seekHeadPos);
        seekHeadPos=*request;
        diskQueue.erase(request);
    } 
    return totalDistance;
}

pair<vector<int>,int> getInput(){
    cout<<"Enter Last Cylinder Number: ";
    int lastCylinderNumber;
    cin>>lastCylinderNumber;

    cout<<"Enter Number of disk requests: ";
    int n;
    cin>>n;
    vector<int> diskQueue;
    while(n>0){
        int temp;
        cout<<"Enter Request: ";
        cin>>temp;
        if(temp<0 or temp>lastCylinderNumber){
            cout<<"Invalid, enter again\n";
            continue;
        }
        diskQueue.push_back(temp);
        n--;
    }
    bool correctInput = false;
    int seekHeadPos=0;
    while(not correctInput){
        cout<<"Enter Head Starting Position: ";
        cin>>seekHeadPos;
        if(seekHeadPos<0 or seekHeadPos>lastCylinderNumber) continue;
        else correctInput=true;
    }
    return pair(diskQueue,seekHeadPos);
}

int main(){
    auto dq=getInput();
    cout<<"Total Distance Travelled: "<<sstf(dq.first,dq.second);
}