#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int getNext(const vector<int>& work,const vector<vector<int>>& need,const vector<bool>& finish)
{
    int i=0;
    while(i<finish.size())
    {
        if(finish[i]==false and need[i]<=work)
        {
            return i;
        }
    }
    return -1;
}

bool bankerSafe(const vector<int>& available,const vector<vector<int>>& allocation,const vector<vector<int>>& need)
{
    auto work=available;
    vector<bool> finish;
    finish.reserve(allocation.size());
    for(int i=0;i<finish.size();i++)
    {
        finish.at(i)=false;
    }
    while(true){
        int index = getNext(work,need,finish);
        if(index==-1)
        {
            for(int i=0;i<finish.size();i++)
            {
                if(finish.at(i)==false)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for(int i=0;i<work.size();i++)
            {
                work[i]=work[i]+allocation[index][i];
            }
            finish[index]=true;
        }
    }
}

bool bankerRequest(vector<int> available,vector<vector<int>> allocation,vector<vector<int>> need,const vector<int>& request,int requestee){
    if(request>need[requestee]){
        return false;
    }
    if(request>available){
        return false;
    }
    for(int i=0;i<available.size();i++){
        available[i]=available[i]-request[i];
        allocation[requestee][i]=allocation[requestee][i]+request[i];
        need[requestee][i]=need[requestee][i]-request[i];
    }
    return bankerSafe(available,allocation,need);
}

vector<vector<int>> getInput(vector<int>& available,vector<vector<int>>& max,vector<vector<int>>& allocation){
    cout<<"Enter number of resources: ";
    int m;
    cin>>m;
    vector<int> total;
    cout<<"Enter Total Vector: ";
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        total.push_back(temp);
    }
    available=total;
    cout<<"Enter number of processes: ";
    int n;
    cin>>n;
    // max.reserve(n);
    for(int i=0;i<n;i++){
        cout<<"Enter Max Vector for "<<i<<" : ";
        max.push_back({});
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            max.at(i).push_back(temp);
        }
    }
    // allocation.reserve(n);
    for(int i=0;i<n;i++){
        cout<<"Enter Allocation Vector for "<<i<<" : ";
        allocation.push_back({});
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            if(temp>max.at(i).at(j)){
                cout<<"\nInvalid\n";
                j--;
                continue;
            }
            allocation.at(i).push_back(temp);
        }
    }
    for(int j=0;j<m;j++){
        int summation=0;
        for(int i=0;i<n;i++){
            summation+=allocation.at(i).at(j);
        }
        available.at(j)=total.at(j)-summation;
        if(available.at(j)<0){
            cout<<"Invalid Total\n";
            exit(1);
        }
    }
    vector<vector<int>> need;
    // need.reserve(n);
    for(int i=0;i<n;i++){
        need.push_back({});
        for(int j=0;j<m;j++){
            need.at(i).push_back(max.at(i).at(j)-allocation.at(i).at(j));
        }
    }
    return need;
}

pair<vector<int>,int> getRequest(int numberOfProcesses,int numberOfResources){
    bool correctInput=false;
    int requestee=0;
    vector<int> requested;
    while(not correctInput){
        cout<<"Enter Requestee: ";
        cin>>requestee;
        if(requestee<0 or requestee>numberOfProcesses){
            cout<<"Invalid\n";
            continue;
        }
        else{
            cout<<"Enter Request Vector: ";
            for(int i=0;i<numberOfResources;i++){
                int temp;
                cin>>temp;
                requested.push_back(temp);
            }
            correctInput=true;
        }
    }
    return pair<vector<int>,int>(requested,requestee);
}

int main(){
    vector<int> available;
    vector<vector<int>> max;
    vector<vector<int>> allocation;
    auto need = getInput(available,max,allocation);
    if(bankerSafe(available,allocation,need)==true){
        cout<<"System initially in safe state\n";
    }
    else{
        cout<<"System initially in unsafe state\n";
    }
    auto requestData=getRequest(max.size(),available.size());
    if(bankerRequest(available,allocation,need,requestData.first,requestData.second)){
        cout<<"Request can be granted\n";
    }
    else{
        cout<<"Request cannot be granted\n";
    }
    // vector<int> available={1,5,2,0};
    // vector<vector<int>> max={
    //                         {0,0,1,2},
    //                         {1,7,5,0},
    //                         {2,3,5,6},
    //                         {0,6,5,2},
    //                         {0,6,5,6}};
    // vector<vector<int>> allocation={
    //                         {0,0,1,2},
    //                         {1,0,0,0},
    //                         {1,3,5,4},
    //                         {0,6,3,2},
    //                         {0,0,1,4}};
    // vector<vector<int>> need={
    //                         {0,0,0,0},
    //                         {0,7,5,0},
    //                         {1,0,0,2},
    //                         {0,0,2,0},
    //                         {0,6,1,2}};
    // cout<<bankerSafe(available,max,allocation,need);
    // vector<int> available={9,3,6};
    // vector<vector<int>> max={
    //                         {3,2,2},
    //                         {6,1,3},
    //                         {3,1,4},
    //                         {4,2,2}};
    // vector<vector<int>> allocation={
    //                         {1,0,0},
    //                         {6,1,2},
    //                         {2,1,1},
    //                         {0,0,2}};
    // vector<vector<int>> need={
    //                         {2,2,2},
    //                         {0,0,1},
    //                         {1,0,3},
    //                         {4,2,0}};
    // cout<<bankerSafe(available,allocation,need);
}