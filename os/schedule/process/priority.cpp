#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

class Process{
    public:
    int arrival=0;
    int burst=0;
    int id=0;
    int turnaround=0;
    int waiting_time=0;
    int priority;
};
void reorderQueue(queue<Process>& readyQueue,int current_time){
    if(not readyQueue.empty()){
        vector<Process> temp;
        while(not readyQueue.empty()){
            temp.push_back(readyQueue.front());
            readyQueue.pop();
        }
        sort(temp.begin(),temp.end(),[](const Process& a,const Process& b){
        if(a.priority<b.priority){
            return true;
        } 
        else if(a.priority==b.priority and a.burst<b.burst){
            return true;
        }
        else if(a.priority==b.priority and a.burst==b.burst and a.arrival<b.arrival){
            return true;
        }
        else return false;
        });
        for(auto it=temp.begin();it!=temp.end();it++){
            if(it->arrival<=current_time){
                readyQueue.push(*it);
                temp.erase(it);
                break;
            }
        }
        reverse(temp.begin(),temp.end());
        while(not temp.empty()){
            readyQueue.push(temp.back());
            temp.pop_back();
        }
    }
}
pair<int,int> priorityNonPreemptive(vector<Process>& processes){
    sort(processes.begin(),processes.end(),[](const Process& a,const Process& b){
        if(a.arrival>b.arrival){
            return true;
        }
        else if(a.priority>b.priority && a.arrival==b.arrival){
            return true;
        }
        else if(a.priority==b.priority && a.arrival==b.arrival && a.burst>b.burst){
            return true;
        }
        else{
            return false;
        }
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
        bool processFinished = false;
        Process p = readyQueue.front();
        readyQueue.pop();
        cout<<"Process "<<p.id<<" is running at "<<current_time<<"\n";
        p.waiting_time+=current_time-p.arrival;
        while(p.burst){
            current_time++;
            p.burst--;
        }
        total_waiting_time+=p.waiting_time;
        p.turnaround=current_time-p.arrival;
        total_turnaround_time+=p.turnaround;
        processes.push_back(p);
        reorderQueue(readyQueue,current_time);
    }
    return pair<int,int>(total_turnaround_time,total_waiting_time);
}

vector<Process> getProcesses(){
    vector<Process> processes;
    cout<<"Enter number of processes: ";
    int n;
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        Process p;
        int at,bt,pri;
        cout<<"Enter details for process "<<i<<": \n";
        cout<<"Enter Arrival Time: ";
        cin>>at;
        cout<<"Enter Burst Time: ";
        cin>>bt;
        cout<<"Enter priority: ";
        cin>>pri;
        p.arrival=at;
        p.burst=bt;
        p.id=i;
        p.priority=pri;
        processes.push_back(p);
    }
    return processes;
}

void display(vector<Process>& processes,pair<int,int> results){
    sort(processes.begin(),processes.end(),[](const Process& a,const Process& b){
        if(a.id<b.id){
            return true;
        }
        else return false;
    });
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

int main(){
    auto pr=getProcesses();
    auto results=priorityNonPreemptive(pr);
    display(pr,results);

}