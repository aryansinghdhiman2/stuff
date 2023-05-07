#include<iostream>
#include<vector>
#include<deque>
#include<utility>
#include<algorithm>
using namespace std;

class requestBuffer{
    deque<int> internalBuffer;
    size_t bufferSize;
    public:
    requestBuffer(size_t bs):bufferSize(bs){}
    bool push(int page){
        auto val=find(this->internalBuffer.begin(),this->internalBuffer.end(),page);
        if(val==this->internalBuffer.end()){
            if(this->internalBuffer.size()<this->bufferSize){
                this->internalBuffer.push_back(page);
            }
            else{
                this->internalBuffer.pop_front();
                this->internalBuffer.push_back(page);
            }
            return true;//Page Fault
        }
        return false;//No Page Fault
    }
    void display(){
        cout<<"Buffer: ";
        for(auto page:this->internalBuffer){
            cout<<page<<" ";
        }
        cout<<endl;
    }
};


int fifo(vector<int> requestQueue,size_t bufferSize){
    auto buffer = requestBuffer(bufferSize);
    int count=0;
    for(auto page:requestQueue){
        bool pageFault=buffer.push(page);
        buffer.display();
        if(pageFault) count++;
    }
    return count;
}

pair<size_t,vector<int>> getInput(){
    cout<<"Enter Number of Requests: ";
    size_t n;
    cin>>n;
    vector<int> requests;
    requests.reserve(n);
    cout<<"Enter Requests\n";
    for(size_t i=0;i<n;i++){
        int temp;
        cin>>temp;
        requests.push_back(temp);
    }
    bool correctInput=false;
    size_t bufferSize=0;
    while(not correctInput){
        cout<<"Enter Buffer Size: ";
        cin>>bufferSize;
        if(bufferSize<0){
            cout<<"Invalid Input\n";
        }
        else correctInput=true;
    }
    return make_pair(bufferSize,requests);
}

int main(){
    auto inputPair = getInput();
    size_t bufferSize=inputPair.first;
    vector<int> requests=inputPair.second;
    int count=fifo(requests,bufferSize);        
    cout<<"Number of Page Faults are: "<<count<<endl;
}