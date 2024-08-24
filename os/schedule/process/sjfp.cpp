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
    bool has_preempted = false;
};

bool compareLesser(const Process& a,const Process& b){
    if(a.burst<b.burst){
        return true;
    }
    else if(a.arrival<b.arrival && a.burst==b.burst){
        return true;
    }
    else{
        return false;
    }
}

bool shouldPreempt(queue<Process> readyQueue,const Process currentProcess,const int currentTime){
    if(!readyQueue.empty()){
        vector<Process> temp;
        while(!readyQueue.empty()){
            temp.push_back(readyQueue.front());
            readyQueue.pop();
        }
        sort(temp.begin(),temp.end(),compareLesser);
        for(auto it=temp.begin();it!=temp.end();it++){
            if(it->arrival<=currentTime
                and it->id!=currentProcess.id
                and not it->has_preempted
                and it->burst<currentProcess.burst){
                return true;
            }
        }
        return false;
    }
    else return false;
}

void reorderQueue(queue<Process>& readyQueue,const Process& currentProcess,const int currentTime){
    vector<Process> temp;
    while(!readyQueue.empty()){
        temp.push_back(readyQueue.front());
        readyQueue.pop();
    }
    sort(temp.begin(),temp.end(),compareLesser);
    vector<Process>::iterator mini;
    for(auto it=temp.begin();it!=temp.end();it++){
        if(it->arrival<=currentTime
            and it->id!=currentProcess.id
            and not it->has_preempted
            and it->burst<currentProcess.burst){
            mini=it;
            break;
        }
    }
    // auto mini=min_element(temp.begin(),temp.end(),compareLesser);
    Process preempter=*mini;
    preempter.has_preempted=true;
    temp.erase(mini);
    reverse(temp.begin(),temp.end());
    readyQueue.push(preempter);
    while(!temp.empty())
    {
        readyQueue.push(temp.back());
        temp.pop_back();
    }
    readyQueue.push(currentProcess);
}

void reorderQueue(queue<Process>& readyQueue,const int currentTime){
    if(not readyQueue.empty()){
        vector<Process> temp;
        while(not readyQueue.empty()){
            temp.push_back(readyQueue.front());
            readyQueue.pop();
        }
        sort(temp.begin(),temp.end(),compareLesser);
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
        bool preempted = false;
        Process p = readyQueue.front();
        readyQueue.pop();
        cout<<"Process "<<p.id<<" is running at "<<current_time<<"\n";
        p.waiting_time+=current_time-p.previous_running_time;
        while(p.burst){
            if(shouldPreempt(readyQueue,p,current_time)){
                preempted=true;
                break;
            }
            p.burst--;
            current_time++;
        }
        p.previous_running_time=current_time;
        total_waiting_time+=p.waiting_time;
        if(preempted){
            reorderQueue(readyQueue,p,current_time);
        }
        else{
            p.turnaround=current_time-p.arrival;
            total_turnaround_time+=p.turnaround;
            processes.push_back(p);
            reorderQueue(readyQueue,current_time);
        }
    }
    return pair<int,int>(total_turnaround_time,total_waiting_time);
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

int main(){
    auto pr=getProcesses();
    auto results=shortestJobFirst(pr);
    display(pr,results);

}