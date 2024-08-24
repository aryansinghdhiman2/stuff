#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int diskPartition(vector<int>& diskQueue,int& seekHeadPos){
    int i=0;
    while(i<int(diskQueue.size())){
        if(diskQueue.at(i)>seekHeadPos){
            break;
        }
        i++;
    }
    return i;
}

int cscan(vector<int>& diskQueue,int seekHeadPos,int lastCylinder){
    int totalDistance=0;
    int prevPos=0;
    sort(diskQueue.begin(),diskQueue.end());
    int i=diskPartition(diskQueue,seekHeadPos);
    if(i>int(diskQueue.size())-i-1){
        prevPos=seekHeadPos-1;
    }
    else{
        prevPos=seekHeadPos+1;;
    }
    i = 2;
    prevPos=54;

    bool hasChangedDirection = false;
    while(not diskQueue.empty()){
        if(seekHeadPos>prevPos){
            int j;
            if(not hasChangedDirection){
                j=i;
            }
            else j=0;
            auto request = diskQueue.begin()+j;
            int diskQueueSize = int(diskQueue.size());
            while(j!=diskQueueSize and request!=diskQueue.end()){
                totalDistance+=abs((*request)-seekHeadPos);
                prevPos=seekHeadPos;
                seekHeadPos=*request;
                request=diskQueue.erase(request);
                j++;
            }
            totalDistance+=abs(seekHeadPos-lastCylinder);
            if(not hasChangedDirection){
                hasChangedDirection=true;
                totalDistance+=abs(lastCylinder-0);
                seekHeadPos=0;
                prevPos=-1;
            }
        }
        else{
            int j;
            if(not hasChangedDirection){
                j=i-1;
            }
            else j=diskQueue.size()-i+1;
            auto request = diskQueue.begin()+j;
            while(j>=0){
                totalDistance+=abs((*request)-seekHeadPos);
                prevPos=seekHeadPos;
                seekHeadPos=*request;
                request=diskQueue.erase(request);
                request--;
                j--;
            }
            totalDistance+=abs(seekHeadPos-0);
            if(not hasChangedDirection){
                hasChangedDirection=true;
                totalDistance+=abs(lastCylinder-0);
                seekHeadPos=lastCylinder;
                prevPos = lastCylinder+1;
            }
        }
    }
    return totalDistance;
}

pair<vector<int>,int> getInput(int& lastCylinderNumber){
    cout<<"Enter Last Cylinder Number: ";
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
    auto a = cscan(diskQueue,seekHeadPos,lastCylinderNumber);
    cout<<"Total Distance is: "<<a;
}