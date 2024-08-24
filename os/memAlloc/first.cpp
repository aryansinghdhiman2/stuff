#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class block{
    int start;
    int end;
    int occupier;
    bool occupied;
    public:
    block(int s,int e):start(s),end(e){this->occupied=false;}
    block(int s,int e,int o):start(e),end(e),occupier(o){this->occupied=true;}
    pair<block,block> divide(int mid){
        block b1 = block(this->start,mid);
        block b2 = block(mid+1,this->end);
        return make_pair(b1,b2);
    }
    void addOccupier(int o){this->occupied=true;this->occupier=o;}
    void removeOccupier(){this->occupied=false;this->occupier=0;}
    int getSize(){return this->end-this->start;}
    int getStart(){return this->start;}
    int getEnd(){return this->end;}
    friend class memory;
};

class memory{
    vector<block> m;
    public:
    memory(int s,int e){m.push_back(block(s,e));}
    memory(vector<block> init){this->m=init;}
    void allocate(int id,int size){
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(not itr->occupied and size<=itr->getSize()){
                block temp=*itr;
                auto block_pair=temp.divide(temp.start+size);
                block_pair.first.addOccupier(id);
                itr=m.insert(itr,block_pair.first);
                itr++;
                itr=m.insert(itr,block_pair.second);
                itr++;
                m.erase(itr);
                return;
            }
        }
        cout<<"No free space"<<endl;
        throw string("No free space");
    }
    void display(){
        for(size_t i=0;i<m.size();i++){
            cout<<m.at(i).start<<endl;
            if(m.at(i).occupied){
                cout<<"Occupied\n";
            }
            else cout<<"Unoccupied\n";
            cout<<m.at(i).end<<endl;
        }
    }
};

int main(){
    // vector<block> v;
    // block b(0,50);
    // auto bPair=b.divide(10);
    // v.push_back(bPair.first);
    // auto secondPair=bPair.second.divide(15);
    // secondPair.first.addOccupier(1);
    // v.push_back(secondPair.first);
    // v.push_back(secondPair.second);
    // memory m(v);
    // m.display();
    // cout<<"****************************************\n";
    // m.allocate(2,12);
    // m.display();

    memory* my_memory=nullptr;
    cout<<"Enter size of memory: ";
    int mem_size=0;
    cin>>mem_size;

    cout<<"Enter 0 if memory is empty or 1 if memory is occupied: ";
    bool occupied=false;
    cin>>occupied;
    if(occupied){
        vector<block> tempVector;
        cout<<"Enter number of blocks occupied: ";
        int n;
        cin>>n;
        while(n>0){
            cout<<"Enter id of process occupying: ";
            int id;
            cin>>id;
            cout<<"Enter start location of process: ";
            int start_loc;
            cin>>start_loc;
            cout<<"Enter size of process: ";
            int process_size;
            cin>>process_size;
            tempVector.push_back(block(start_loc,start_loc+process_size,id));
        }
        if(tempVector.front().getStart()!=0){
            tempVector.insert(tempVector.begin(),block(0,tempVector.front().getEnd()-1));
        }
        if(tempVector.back().getEnd()!=mem_size){
            tempVector.insert(tempVector.end(),block(tempVector.back().getEnd()+1,mem_size));
        }
        my_memory=new memory(tempVector);
    }
    else{
        // block b(0,mem_size);
        // memory my_memory(0,mem_size);
        my_memory=new memory(0,mem_size);
    }
    cout<<"Enter id of process to be allocated: ";
    int alloc_id;
    cin>>alloc_id;
    cout<<"Enter size of process: ";
    int alloc_size;
    cin>>alloc_size;
    my_memory->allocate(alloc_id,alloc_size);
    my_memory->display();
}