#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class person{
    public:
    int time;
    person(int t){
        this->time=t;
    }
    bool operator<(person a){
    //Reversed so as to sort list in descending order
        if(this->time<a.time){
            return false;
        }
        else return true;
    }
};

int bridgeAndTorch(vector<person> persons){
    sort(persons.begin(),persons.end());
    person runner=persons.back();
    persons.pop_back();
    int passedTime=0;
    while(not persons.empty()){
        if(persons.size()==1){
            passedTime+=persons.back().time;
            persons.pop_back();
        }
        else{
            passedTime+=persons.back().time+runner.time;
            persons.pop_back();
        }
    }
    return passedTime;
}

int main(){
    // vector<person> v = {person(1),person(2),person(5),person(10)};
    vector<person> v = {person(10),person(20),person(30)};
    cout<<bridgeAndTorch(v);
}