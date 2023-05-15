#include<iostream>
#include<vector>
#include<deque>
#include<utility>
#include<algorithm>
using namespace std;

class requestBuffer{
    deque<int> internalBuffer;
    size_t bufferSize;
    int getLateUsed(const vector<int>& requestQueue,const int& currentIndex){
        vector<int> dist={INT_MAX,INT_MAX,INT_MAX};
        for(size_t i=0;i<this->bufferSize;i++){
            for(size_t j=currentIndex-1;j>=0;j--){
                if(requestQueue.at(j)==this->internalBuffer.at(i)){
                    dist.at(i)=abs(int(j-currentIndex));
                    break;
                }
            }
        }
        auto usedLater = min_element(dist.begin(),dist.end());
        return usedLater-dist.begin();
    }
    public:
    requestBuffer(size_t bs):bufferSize(bs){}
    bool push(const int& page,const vector<int>& requestQueue,const int& currentIndex){
        auto val=find(this->internalBuffer.begin(),this->internalBuffer.end(),page);
        if(val==this->internalBuffer.end()){
            if(this->internalBuffer.size()<this->bufferSize){
                this->internalBuffer.push_back(page);
            }
            else{
                auto usedLater=this->getLateUsed(requestQueue,currentIndex);
                this->internalBuffer.erase(this->internalBuffer.begin()+usedLater);
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


int mru(const vector<int>& requestQueue,const size_t& bufferSize){
    auto buffer = requestBuffer(bufferSize);
    int count=0;
    for(size_t i=0;i<requestQueue.size();i++){
        bool pageFault=buffer.push(requestQueue.at(i),requestQueue,i);
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
    // size_t bufferSize = 3;
    // vector<int> requests = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int count=mru(requests,bufferSize);        
    cout<<"Number of Page Faults are: "<<count<<endl;
}