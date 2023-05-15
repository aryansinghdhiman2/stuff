#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class process{
    public:
    int id;
    int arrival;
    int burst;
    int priority;
};

pair<int,int> lrtf(vector<process> processes){
    auto comparor = [](const process& a,const process& b){
        if(a.burst<b.burst) return true;
        if(a.burst==b.burst and a.priority<b.priority) return true;
        if(a.burst==b.burst and a.priority==b.priority and a.arrival<b.arrival) return true;
        return false;
    };
    sort(processes.begin(),processes.end(),comparor);
    int current_time=0;
    int total_wait_time=0,total_turnaround_time=0;
    while(!processes.empty()){
        auto request=processes.begin();
        for(auto itr=processes.begin();itr!=processes.end();itr++){
            if(itr->arrival <= request->arrival
            and itr->arrival <= current_time){
                request=itr;
                break;
            }
        }
        cout<<"Process "<<request->id<<" is running at "<<current_time<<endl;
        total_wait_time+=abs(request->arrival-current_time);
        current_time+=request->burst;
        total_turnaround_time+=abs(request->arrival-current_time);
        processes.erase(request);
    }
    return pair<int,int>(total_turnaround_time,total_wait_time);
}

int main(){
    cout<<"Enter number of processes: ";
    int n;
    cin>>n;
    vector<process> processes;
    for(int i=0;i<n;i++){
        cout<<"Enter info about process "<<i<<endl;
        cout<<"Enter arrival time: ";
        int a;
        cin>>a;
        cout<<"Enter burst time: ";
        int b;
        cin>>b;
        cout<<"Enter priority: ";
        int p;
        cin>>p;

        process prc;
        prc.id=i;\
        prc.arrival=a;
        prc.burst=b;
        prc.priority=p;
        processes.push_back(prc);
    }
    auto result = lrtf(processes);
    cout<<"Total Waiting Time: "<<result.second<<endl;
    cout<<"Total Turnaround Time: "<<result.first<<endl;
}