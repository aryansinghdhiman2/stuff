#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int fcfs(queue<int> diskQueue,int seekHeadPos){
    int totalDistance = 0;
    while(not diskQueue.empty()){
        totalDistance+=abs((diskQueue.front())-seekHeadPos);
        seekHeadPos=diskQueue.front();
        diskQueue.pop();
    }
    return totalDistance;
}

pair<queue<int>,int> getInput(){
    cout<<"Enter Last Cylinder Number: ";
    int lastCylinderNumber;
    cin>>lastCylinderNumber;

    cout<<"Enter Number of disk requests: ";
    int n;
    cin>>n;
    queue<int> diskQueue;
    while(n>0){
        int temp;
        cout<<"Enter Request: ";
        cin>>temp;
        if(temp<0 or temp>lastCylinderNumber){
            cout<<"Invalid, enter again\n";
            continue;
        }
        diskQueue.push(temp);
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
    cout<<"Total Distance Travelled: "<<fcfs(dq.first,dq.second)<<endl;
}