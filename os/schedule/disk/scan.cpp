#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int diskPartition(vector<int>& diskQueue,int& seekHeadPos){
    int i=0;
    while(i<diskQueue.size()){
        if(diskQueue.at(i)>seekHeadPos){
            break;
        }
        i++;
    }
    return i;
}

int scan(vector<int>& diskQueue,int seekHeadPos,int lastCylinder){
    int totalDistance=0;
    int prevPos=0;
    sort(diskQueue.begin(),diskQueue.end());
    int i=diskPartition(diskQueue,seekHeadPos);
    if(i>diskQueue.size()-i-1){
        prevPos=seekHeadPos-1;
    }
    else{
        prevPos=seekHeadPos+1;;
    }

    i = 2;
    prevPos=52;

    while(not diskQueue.empty()){
        if(seekHeadPos>prevPos){
            int j=i;
            auto request = diskQueue.begin()+i;
            int diskQueueSize = int(diskQueue.size());
            while(j!=diskQueueSize and request!=diskQueue.end()){
                totalDistance+=abs((*request)-seekHeadPos);
                prevPos=seekHeadPos;
                seekHeadPos=*request;
                request=diskQueue.erase(request);
                j++;
            }
            totalDistance+=abs(seekHeadPos-lastCylinder);
            seekHeadPos=lastCylinder;
            prevPos=lastCylinder+1;
        }
        else{
            int j=0;
            auto request = diskQueue.end()-1;
            while(j!=i){
                totalDistance+=abs((*request)-seekHeadPos);
                prevPos=seekHeadPos;
                seekHeadPos=*request;
                request=diskQueue.erase(request);
                request--;
                j++;
            }
            totalDistance+=abs(seekHeadPos-lastCylinder);
            seekHeadPos=0;
            prevPos=-1;
        }
    }
    return totalDistance;
}

pair<vector<int>,int> getInput(int& lastCylinderNumber){
    cout<<"Enter Last Cylinder Number: ";
    // int lastCylinderNumber;
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
    return pair<vector<int>,int>(diskQueue,seekHeadPos);
}

int main(){
    int lastCylinderNumber=0;
    pair<vector<int>,int> dq=getInput(lastCylinderNumber);
    vector<int> diskQueue=vector<int>(dq.first);
    int seekHeadPos = dq.second;
    // vector<int> diskQueue = {98, 183, 37, 122, 14, 124, 65, 67};
    // int seekHeadPos = 53;
    // int lastCylinderNumber = 199;
    auto a = scan(diskQueue,seekHeadPos,lastCylinderNumber);
    cout<<"Total Distance is: "<<a;
}