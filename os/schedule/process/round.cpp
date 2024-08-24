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
    int previous_running_time=0;
};

pair<int,int> roundRobin(vector<Process>& processes,const int quantum){
    sort(processes.begin(),processes.end(),[](const Process& a,const Process& b){
        if(a.arrival>b.arrival){
            return true;
        }
        else if(a.burst>b.burst && a.arrival==b.arrival){
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
        p.waiting_time+=current_time-p.previous_running_time;

        int allottedTime = quantum;
        while(allottedTime){
            if(p.burst==0){
                processFinished=true;
                break;
            }
            p.burst--;
            current_time++;
            allottedTime--;
        };
        if(p.burst==0){
            processFinished=true;
        }
        p.previous_running_time=current_time;
        total_waiting_time+=p.waiting_time;
        if(processFinished){
            p.turnaround=current_time-p.arrival;
            total_turnaround_time+=p.turnaround;
            processes.push_back(p);
        }
        else{
            readyQueue.push(p);
        }
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
        int at,bt;
        cout<<"Enter details for process "<<i<<": \n";
        cout<<"Enter Arrival Time: ";
        cin>>at;
        cout<<"Enter Burst Time: ";
        cin>>bt;
        
        p.arrival=at;
        p.burst=bt;
        p.id=i;
        p.previous_running_time=p.arrival;
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
    cout<<"Total Turnaround Time"<<results.first<<endl;
}

int main(){
    auto pr=getProcesses();
    cout<<"Enter size of quantum: ";
    int quantum;
    cin>>quantum;
    auto results=roundRobin(pr,quantum);
    display(pr,results);
}