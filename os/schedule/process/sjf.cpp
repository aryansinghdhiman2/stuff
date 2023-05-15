#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

class Process{
    public:
    int arrival;
    int burst;
    int id;
    int turnaround;
    int waiting_time;
    bool operator<(const Process& other){
        if(this->burst<other.burst){
            return true;
        }
        else if(this->arrival<other.arrival and this->burst==other.burst){
            return true;
        }
        else return false;
    }
};

void reorderQueue(queue<Process>& readyQueue,const int currentTime){
    if(not readyQueue.empty()){
        vector<Process> temp;
        while(not readyQueue.empty()){
            temp.push_back(readyQueue.front());
            readyQueue.pop();
        }
        sort(temp.begin(),temp.end());
        vector<Process>::iterator mini;
        for(auto it=temp.begin();it!=temp.end();it++){
            if(it->arrival<=currentTime){
                mini=it;
                break;
            }
        }
        auto shortest = *mini;
        temp.erase(mini);
        readyQueue.push(shortest);
        for(auto process:temp){
            readyQueue.push(process);
        }
    }
}

pair<int,int> shortestJobFirst(vector<Process>& processes){
    sort(processes.begin(),processes.end(),[](const Process& a,const Process& b){
        if(a.arrival>b.arrival){
            return true;
        }
        else return false;
    });
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    queue<Process> readyQueue;

    while (!processes.empty())
    {
        readyQueue.push(processes.back());
        processes.pop_back();
    }
    int current_time=0;
    while(!readyQueue.empty()){
        Process p = readyQueue.front();
        readyQueue.pop();
        cout<<"Process "<<p.id<<" is running\n";
        p.waiting_time=current_time-p.arrival;

        current_time+=p.burst;

        p.turnaround=current_time-p.arrival;
        total_turnaround_time+=p.turnaround;
        total_waiting_time+=p.waiting_time;
        processes.push_back(p);
        reorderQueue(readyQueue,current_time);
    }
    return pair<int,int>(total_turnaround_time,total_waiting_time);
}

void display(const vector<Process>& processes,pair<int,int> results){
    
    for(auto it=processes.begin();it!=processes.end();it++){
        cout<<"***************************************\n";
        cout<<"Process "<<it->id<<":\n";
        cout<<"Turnaround Time: "<<it->turnaround<<endl;
        cout<<"Waiting Time: "<<it->waiting_time<<endl;
    }
    cout<<"***************************************\n";
    cout<<"Total Waiting Time: "<<results.second<<endl;
    cout<<"Total Turnaround Time: "<<results.first<<endl;
}

vector<Process> getProcesses(){
    vector<Process> processes;
    cout<<"Enter number of processes: ";
    int n;
    cin>>n;
    cout<<endl;
    // cout<<"Enter 1 to use priority as tie-breaker, 0 for arrival time: ";
    // int choice;
    // cin>>choice;
    for(int i=0;i<n;i++){
        Process p;
        int at,bt;
        cout<<"Enter details for process "<<i<<": \n";
        cout<<"Enter Arrival Time: ";
        cin>>at;
        cout<<"Enter Burst Time: ";
        cin>>bt;
        
        p.arrival=at;
        p.burst=bt;
        p.id=i;

        processes.push_back(p);
    }
    return processes;
}

int main(){
    auto pr=getProcesses();
    auto results=shortestJobFirst(pr);
    display(pr,results);
}